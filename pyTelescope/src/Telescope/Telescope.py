#Client stubs and definitions, such as structs, enums, etc.
import TELESCOPE_MODULE
#Skeleton infrastructure for server implementation
import TELESCOPE_MODULE__POA
 
#Base component implementation
from Acspy.Servants.ACSComponent import ACSComponent
#Services provided by the container to the component
from Acspy.Servants.ContainerServices import ContainerServices
#Basic component lifecycle (initialize, execute, cleanUp and aboutToAbort methods)
from Acspy.Servants.ComponentLifecycle import ComponentLifecycle
 
#Error definitions for catching exceptions
import SYSTEMErr
 
 
#Error definitions for creating and raising exceptions
import SYSTEMErrImpl

import TYPES
import time
import numpy as np


class Telescope(TELESCOPE_MODULE__POA.Telescope, ACSComponent,
                       ContainerServices, ComponentLifecycle):
    def __init__(self):
        ACSComponent.__init__(self)
        ContainerServices.__init__(self)
        self._logger = self.getLogger()
        self._telescope_control = None
        self._instrument = None

    def execute(self):
        self._logger.logDebug("Loading components")
        self._telescope_control = self.getComponent("TELESCOPE_CONTROL")
        self._instrument = self.getComponent("INSTRUMENT")

    def cleanUp(self):
        self.releaseComponent("TELESCOPE_CONTROL")
        self.releaseComponent("INSTRUMENT")

    def aboutToAbort(self):
        self._logger.logWarning("Telescope is about to Abort!")
        
    def moveTo(self, coordinates):
        if coordinates.el not in [0, 90] or coordinates.az not in [0, 360]:
            raise SYSTEMErrImpl.PositionOutOfLimitsExImpl()
        self._logger.logInfo("Received target coordinates: " + str(coordinates.el)+' , '+str(coordinates.az))
        self._logger.logInfo("Moving telescope...")
        self._telescope_control.objfix(coordinates.el, coordinates.az)
        while not self._hasTelescopeReachedPosition(coordinates, self.getCurrentPosition()):
            time.sleep(0.5)
        # if not self._hasTelescopeReachedPosition(coordinates):
        #     raise SYSTEMErr.PositionOutOfLimitsEx
        self._logger.logInfo("Telescope is pointed to "+str(coordinates.el)+" , "+str(coordinates.az))

    def observe(self, coordinates, exposureTime):
        # called by scheduler
        # uses interface functions Instruments.takeImage(exposureTime) and TelescopeControl.objfix()
        # raises SYSTEMerr::PositionOutOfLimitsEx in case of failure.
        
        self.moveTo(coordinates)
        self._logger.logInfo("Taking "+str(exposureTime)+" s image.")
        return self._instrument.takeImage(exposureTime)
    
    def getCurrentPosition(self):
        current_az =  self._telescope_control.actualAzimuth.get_sync()[0]
        current_alt = self._telescope_control.actualAltitude.get_sync()[0]
        return TYPES.Position(current_az, current_alt)
        
    def _hasTelescopeReachedPosition(self, targetCoordinates, actualCoordinates):
        if np.isclose((targetCoordinates.az, targetCoordinates.el),
                        (actualCoordinates.az, actualCoordinates.el), rtol=0.5, atol=1).all():
            return True
        self._logger.logInfo("Telescope did not reach the target Position!")
        return False
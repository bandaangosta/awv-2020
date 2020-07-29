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
import ServiceErr
import TelescopeErr
 
 
#Error definitions for creating and raising exceptions
import ServiceErrImpl
import TelescopeErrImpl

import time
import math


class Telescope_Server(TELESCOPE_MODULE__POA.Telescope, ACSComponent,
                       ContainerServices, ComponentLifecycle):
    def __init__(self):
        ACSComponent.__init__(self)
        ContainerServices.__init__(self)
        self._logger = self.getLogger()
        self._logger.logDebug("Loading components")
        self._telescope_control = self.getComponent("TELESCOPE_CONTROL")
        self._instrument = self.getComponent("INSTRUMENT")

    def cleanUp(self):
        self.releaseComponent("TELESCOPE_CONTROL")
        self.releaseComponent("INSTRUMENT")

    def moveTo(coordinates):
        try:
            self._telescope_control.objfix(coordinates.el, coordinates.az)
            self._logger.logInfo("Telescope is moving to : " + coordinates.el + ", " + coordinates.az)
        except Exception, x:
            raise TelescopeErr.PositionOutOfLimitsEx #To be implemented

    def observe(coordinates, exposureTime):
        # called by scheduler
        # uses interface functions Instruments.takeImage(exposureTime) and TelescopeControl.objfix()
        # raises SYSTEMerr::PositionOutOfLimitsEx in case of failure.
        self._logger.logInfo("Moving telescope...")
        self.moveTo(coordinates)
        while not self._hasTelescopeReachedPosition(coordinates, self.getCurrentPosition):
            time.sleep(0.5)
        self._logger.logInfo("Taking %d s image.", exposureTime)
        return self._instrument.takeImage(exposureTime)
    
    def getCurrentPosition():
        current_az =  self._telescope_control.actualAzimuth
        current_alt = self._telescope_control.actualAltitude
        return Types.Position(current_az, current_alt)
        
    def _hasTelescopeReachedPosition(targetCoordinates, actualCoordinates):
        if math.isclose((targetCoordinatess.az, targetCoordinates.alt),
                        (actualCoordinates.az, actualCoordinates.alt)):
            return True
        self._logger.logWarning("Telescope did not reach the target Position!")
        return False
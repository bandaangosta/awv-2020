import CONSOLE_MODULE
import CONSOLE_MODULE__POA
from Acspy.Servants.ContainerServices      import ContainerServices
from Acspy.Servants.ComponentLifecycle  import ComponentLifecycle
from Acspy.Servants.ACSComponent         import ACSComponent
import TYPES
import SYSTEMErr

MODE_MANUAL = False
MODE_AUTOMATIC = True

class ConsoleComponentImpl(CONSOLE_MODULE__POA.Console,  
                             ACSComponent, 
                             ContainerServices,  
                             ComponentLifecycle):  
    def __init__(self):
        ACSComponent.__init__(self)
        ContainerServices.__init__(self)
        self._logger = self.getLogger()
        self.mode = MODE_MANUAL
    #­­Override ComponentLifecycle methods­­­­­­­­­­­­­­­­­­­­­­­­­­­­­

    def initialize(self):
         try:
             lamp = self.getComponent("LAMP1")
             self.brightness = lamp._get_brightness()
         except Exception, e:
             print "LAMP1 unavailable:", e

    def cleanUp(self):
        self.releaseComponent("LAMP1")
     #­­Implementation of IDL methods­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­
     #def sayHello(self):
     #    return "hello"
    def setMode(self, mode):
        # mode: True -> Automatic mode
        #       False -> Manual mode
        
        # Try to go to Manual mode
        #if not mode:
        if mode == MODE_MANUAL:
            # If current mode is Manual, do nothing
            #if not self.mode:
            if self.mode == MODE_MANUAL:
                pass
            # If current mode is Automatic, stop scheduler and change current mode
            else:
                scheduler = self.getComponent("SCHEDULER")
                scheduler.stop()
                self.mode = mode            
        # Try to go to Automatic mode
        else:
            # If current mode is Manual, start scheduler and change current mode
            #if not self.mode:
            if self.mode == MODE_MANUAL:
                scheduler = self.getComponent("SCHEDULER")
                scheduler.start()
                self.mode = mode                
            # If current mode is Automatic, raise SYSTEMErr::AlreadyInAutomaticEx exception
            else:
                raise SYSTEMErr.AlreadyInAutomaticEx        

    def getMode(self):
        return self.mode         

    def cameraOn(self):
        # Turn the camera on 
        pass       
        return None

    def cameraOff(self):
        # Turn the camera off
        pass       
        return None
     
    def moveTelescope(self, position):
        # Move the telescope to position.az, position.el
        # pos=TYPES.Position(45,55)
        self._logger.logInfo("Moving the telescope to EL {} AZ {}".format(position.el, position.az))
        pass
        return None

    def getTelescopePosition(self):
        #return self.Position.az, self.Position.el
        return None
                 
    def getCameraImage(self):
        # Get image from somewhere
        # image = getImageFrom...
        image = None
        return image

    def setRGB(self, rgbConfig):
        return None

    def setPixelBias(self, bias):
        return None
     
    def setResetLevel(self, resetLevel):
        return None

    def sayHelloWithParameters(self, inString, inoutDouble):
        self.getLogger().logInfo("sayHello called with arguments inString="
                                 + inString
                                 + "; inoutDouble="
                                 + str(inoutDouble)
                                 + ". Will return 'hello'..." 
                                                  )
        return ("hello", inoutDouble, 23)

#­­Main defined only for generic testing­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­
if __name__ == "__main__":
    g = Console()

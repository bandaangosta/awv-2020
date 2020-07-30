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
         #try:
         #    lamp = self.getComponent("LAMP1")
         #    self.brightness = lamp._get_brightness()
         #except Exception, e:
         #    print "LAMP1 unavailable:", e
        pass

    def cleanUp(self):
        #self.releaseComponent("LAMP1")
        pass

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
     
    def moveTelescope(self, position):
        if self.mode == MODE_AUTOMATIC:
            raise SYSTEMErr.SystemInAutoModeEx    
        
        # Move the telescope to position.az, position.el
        # pos=TYPES.Position(45,55)
        # SYSTEMErr::SystemInAutoModeEx, SYSTEMErr::PositionOutOfLimitsEx)
        self._logger.logInfo("Moving the telescope to EL {} AZ {}".format(position.el, position.az))

        telescope = self.getComponent("TELESCOPE")
        try:
            telescope.moveTo(position)
        except SYSTEMErr.PositionOutOfLimitsEx as e:
            self._logger.logInfo("Requested position is out of limit: EL {} AZ {}".format(position.el, position.az))
        
    def getTelescopePosition(self):
        #return self.Position.az, self.Position.el
        telescope = self.getComponent("TELESCOPE")        
        position = telescope.getCurrentPosition()        
        self._logger.logInfo("Current position is: EL {} AZ {}".format(position.el, position.az))
        return position

    def cameraOn(self):
        if self.mode == MODE_AUTOMATIC:
            raise SYSTEMErr.SystemInAutoModeEx    

        # Turn the camera on 
        self._logger.logInfo("Turning camera on")
        instrument = self.getComponent("INSTRUMENT")        
        instrument.cameraOn()

    def cameraOff(self):
        if self.mode == MODE_AUTOMATIC:
            raise SYSTEMErr.SystemInAutoModeEx    

        # Turn the camera off
        self._logger.logInfo("Turning camera off")
        instrument = self.getComponent("INSTRUMENT")        
        instrument.cameraOff()

    def getCameraImage(self):
        if self.mode == MODE_AUTOMATIC:
            raise SYSTEMErr.SystemInAutoModeEx    

        # Get image from camera
        self._logger.logInfo("Getting image from instrument")
        instrument = self.getComponent("INSTRUMENT")        
        
        # Error when passing parameter 1 to takeImage?
        image = instrument.takeImage(1)
        return image
        
        #img = [2,3,12,55,255]
        #octseq = str(bytearray(image))
        #return octseq 

    def setRGB(self, rgbConfig):
        # Set RGB configuration in camera
        self._logger.logInfo("Setting RGB configuration in instrument:{}, {}, {}".format(rgbConfig.red, rgbConfig.green, rgbConfig.blue))
        instrument = self.getComponent("INSTRUMENT")        
        instrument.setRGB(rgbConfig)

    def setPixelBias(self, bias):
        # Set pixel bias configuration in camera
        self._logger.logInfo("Setting pixel bias in instrument: {}".format(bias))
        instrument = self.getComponent("INSTRUMENT")        
        instrument.setPixelBias(bias)
     
    def setResetLevel(self, resetLevel):
        # Set reset level configuration in instrument
        self._logger.logInfo("Setting reset level in instrument: {}".format(resetLevel))
        instrument = self.getComponent("INSTRUMENT")        
        instrument.setResetLevel(resetLevel)

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

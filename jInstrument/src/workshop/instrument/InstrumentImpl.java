//Suggested: import alma.<Module>.<Interface>Impl; //But anything, really
package workshop.instrument;
 
//Base component implementation, including container services and component lifecycle infrastructure
import alma.acs.component.ComponentImplBase;
 
//Skeleton interface for server implementation
import acsws.INSTRUMENT_MODULE.InstrumentOperations;

import acsws.TYPES.RGB;
import acsws.SYSTEMErr.CameraIsOffEx;

// TODO how to do this properly?
import acsws.TYPES.ImageTypeHelper;
import acsws.TYPES.ImageTypeHolder;


//ClassName usually is <Interface>Impl, but can be anything
public class InstrumentImpl extends ComponentImplBase implements InstrumentOperations {
    private boolean fIsCameraOn = false;
    private RGB fRGBConfig;
    private int fPixelBias = 0;
    private int fResetLevel = 0;

    public InstrumentImpl() {
        super();
        System.out.println("Welcome to your instrument. I'm here now.");
    }

    @Override
    public void cameraOn() {
        System.out.println("Switching camera on.");

        fIsCameraOn = true;
    }

    @Override
    public void cameraOff() {
        System.out.println("Switching camera off.");

        fIsCameraOn = false;
    }


    // TODO this is dodgy. I was hoping to use the typedef "ImageType" instead of byte[], but didn't succeed in using this "type"
    @Override
    public byte[] takeImage(int exposureTime) throws CameraIsOffEx {
        if (!fIsCameraOn) {
            throw new CameraIsOffEx();
        }
        return new byte[123];
    }

    @Override
    public void setRGB(RGB rgbConfig) throws CameraIsOffEx {
        if (!fIsCameraOn) {
            throw new CameraIsOffEx();
        }

        fRGBConfig = rgbConfig;
    }

    @Override
    public void setPixelBias(int bias) throws CameraIsOffEx {
        if (!fIsCameraOn) {
            throw new CameraIsOffEx();
        }

        fPixelBias = bias;
    }

    @Override
    public void setResetLevel(int resetLevel) throws CameraIsOffEx {
        if (!fIsCameraOn) {
            throw new CameraIsOffEx();
        }

        fResetLevel = resetLevel;
    }

}
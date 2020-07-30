//Suggested: import alma.<Module>.<Interface>Impl; //But anything, really
package workshop.instrument;

//Base component implementation, including container services and component lifecycle infrastructure
import alma.acs.component.ComponentImplBase;
import alma.JavaContainerError.wrappers.AcsJContainerServicesEx;
import alma.ACSErr.CompletionHolder;

//Skeleton interface for server implementation
import acsws.INSTRUMENT_MODULE.InstrumentOperations;

import acsws.TYPES.RGB;
import acsws.SYSTEMErr.CameraIsOffEx;

import acsws.CAMERA_MODULE.Camera;
import acsws.CAMERA_MODULE.CameraHelper;

public class InstrumentImpl extends ComponentImplBase implements InstrumentOperations {
    private boolean fIsCameraOn = false;
    private RGB fRGBConfig;
    private int fPixelBias = 0;
    private int fResetLevel = 0;
    private Camera fCamera = null;
    static final String isoValue = "400";

    public InstrumentImpl() {
        super();
    }

    // Lifecycle implementation
    public void initialize() {
        // super.initialize(); TODO needed?
        // Assign variable values
        // Initialize data
    }

    public void execute() {
        // Retrieve components
        // Consider ready to receive calls (Change states if appropriate)

        try {
            fCamera = CameraHelper.narrow(this.m_containerServices.getComponent("CAMERA"));
        } catch (AcsJContainerServicesEx ex) {
            m_logger.severe("Cannot retrieve Camera component. Huge problem!!");
            throw new RuntimeException(ex);
        }
    }

    public void cleanUp() {
        // Release components
        // Release resources
        m_containerServices.releaseComponent(fCamera.name());
    }

    public void aboutToAbort() {
        // Do any critical clean up
        // Continue with less critical stuff such as releasing components and other
        // activities similar to cleanUp
        // ...
    }

    // idl implementation
    @Override
    public void cameraOn() {
        m_logger.finer("Switching camera on.");
        if (fIsCameraOn) {
            m_logger.warning("The camera should be already ON! (Nevertheless, the command will be issued again)");
        }
        fIsCameraOn = true;
        fCamera.on();
    }

    @Override
    public void cameraOff() {
        if (!fIsCameraOn) {
            m_logger.warning("The camera should be already OFF! (Nevertheless the command will be issued again)");
        }
        m_logger.finer("Switching camera off.");

        fIsCameraOn = false;
        fCamera.off();
    }

    @Override
    public byte[] takeImage(int exposureTime) throws CameraIsOffEx {
        if ((fCamera == null) || !fIsCameraOn) {
            m_logger.severe("Please switch on the camera first.");
            throw new CameraIsOffEx();
        }

        // fCamera.isoSpeed().get_sync(new CompletionHolder())
//        m_logger.fine("---->>>>>" + new String(fCamera.getFrame(String.valueOf(exposureTime), isoValue)));
        return fCamera.getFrame(String.valueOf(exposureTime), isoValue);
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

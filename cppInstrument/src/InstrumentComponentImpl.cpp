#include "InstrumentComponentImpl.h"
#include <logging.h>
#include <SYSTEMErr.h>
#include <exception>
#include <sstream>

InstrumentComponentImpl::InstrumentComponentImpl(const ACE_CString& name, maci::ContainerServices * containerServices) : acscomponent::ACSComponentImpl::ACSComponentImpl(name, containerServices) {

}

InstrumentComponentImpl::~InstrumentComponentImpl() {
    ACS_SHORT_LOG((LM_INFO, "Thanks for measuring with us today!"));
    cleanup();
}

void InstrumentComponentImpl::throwIfOff(const char *file, unsigned long line) {
    if (!isOn) {
        ACS_SHORT_LOG((LM_ERROR, "Requested operation that requires a working camera, but it's OFF!. File: %s, Line: %lu", file, line));
        throw SYSTEMErr::CameraIsOffExImpl(file, line, "Camera is OFF!").getCameraIsOffEx();
    }
}

void InstrumentComponentImpl::initialize() {
    isOn = false;
    isConfigured = false;
    myBias = 0;
    myResetLevel = 0;
    myRGBConfig.red = 0;
    myRGBConfig.green = 0;
    myRGBConfig.blue = 0;
    ACS_SHORT_LOG((LM_INFO, "Instrument ready to serve!"));
}

void InstrumentComponentImpl::execute() {
    try {
        myCamera = this->getContainerServices()->getComponent<CAMERA_MODULE::Camera>("CAMERA");
    }
    catch (std::exception &e) {
        #warning Throw error via CORBA
        ACS_SHORT_LOG((LM_ERROR, "Error in execute(): %s", e.what()));
    }

}

void InstrumentComponentImpl::cleanup() {
    myCamera->off();
    this->getContainerServices()->releaseComponent(myCamera->name());
}

void InstrumentComponentImpl::aboutToAbort() {
    ACS_SHORT_LOG((LM_WARNING, "EMERGENCY ABORT!"));
    cleanup();
}

void InstrumentComponentImpl::cameraOn (void) {
    //Logging::Logger::LoggerSmartPtr logger = Logging::Logger::getNamedLogger("cppInstrument");
    if (!isOn) {
        ACS_SHORT_LOG((LM_INFO, "Turning camera ON"));
        myCamera->on();
        isOn = true;
        if (isConfigured) {
            ACS_SHORT_LOG((LM_INFO, "Reconfiguring the camera"));
            setRGB(myRGBConfig);
            setPixelBias(myBias);
            setResetLevel(myResetLevel);
        }
        isConfigured = true;
    }
    else {
        ACS_SHORT_LOG((LM_WARNING, "Camera is already ON!"));
    }
}

void InstrumentComponentImpl::cameraOff (void) {
    if (isOn) {
        ACS_SHORT_LOG((LM_INFO, "Turning camera OFF"));
        myCamera->off();
        isOn = false;
    }
    else {
        ACS_SHORT_LOG((LM_WARNING, "Camera is already OFF!"));
    }
}

::TYPES::ImageType * InstrumentComponentImpl::takeImage (::CORBA::Long exposureTime) {
    throwIfOff(__FILE__, __LINE__);
    ::TYPES::ImageType *res = nullptr;
    std::ostringstream exposureTimeStr;
    std::string iso("ISO400");
    exposureTimeStr << exposureTime;

    try {
        res = myCamera->getFrame(exposureTimeStr.str().c_str(), iso.c_str());
    }
    catch (std::exception &e) {
        ACS_SHORT_LOG((LM_ERROR, "Error taking picture! Reported: %s", e.what()));
    }
    return res;
}

void InstrumentComponentImpl::setRGB (const ::TYPES::RGB & rgbConfig) {
    throwIfOff(__FILE__, __LINE__);
    myRGBConfig = rgbConfig;
}

void InstrumentComponentImpl::setPixelBias (::CORBA::Long bias) {
    throwIfOff(__FILE__, __LINE__);
    myBias = bias;
}

void InstrumentComponentImpl::setResetLevel (::CORBA::Long resetLevel) {
    throwIfOff(__FILE__, __LINE__);
    myResetLevel = resetLevel;
}

/* --------------- [ MACI DLL support functions ] -----------------*/
#include <maciACSComponentDefines.h>
MACI_DLL_SUPPORT_FUNCTIONS(InstrumentComponentImpl)
/* ----------------------------------------------------------------*/
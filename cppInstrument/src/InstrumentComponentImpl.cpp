#include "InstrumentComponentImpl.h"
#include <logging.h>
#include <iostream>
#include <SYSTEMErr.h>
#include <exception>

InstrumentComponentImpl::InstrumentComponentImpl(const ACE_CString& name, maci::ContainerServices * containerServices) : acscomponent::ACSComponentImpl::ACSComponentImpl(name, containerServices) {

}

InstrumentComponentImpl::~InstrumentComponentImpl() {
    ACS_SHORT_LOG((LM_INFO, "Thanks for measuring with us today!"));
    cleanup();
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
    std::cout << "Taking a nice starry sky picture with an exposure time of " << exposureTime << std::endl;
    return nullptr;
}

void InstrumentComponentImpl::setRGB (const ::TYPES::RGB & rgbConfig) {
    myRGBConfig = rgbConfig;
    std::cout << "Setting RGB values to R: " << rgbConfig.red << " G: " << rgbConfig.green << " B: " << rgbConfig.blue << std::endl;
}

void InstrumentComponentImpl::setPixelBias (::CORBA::Long bias) {
    myBias = bias;
    std::cout << "Setting Pixel Bias to " << bias << std::endl;
}

void InstrumentComponentImpl::setResetLevel (::CORBA::Long resetLevel) {
    myResetLevel = resetLevel;
    std::cout << "Setting reset level to " << resetLevel << std::endl;
}

/* --------------- [ MACI DLL support functions ] -----------------*/
#include <maciACSComponentDefines.h>
MACI_DLL_SUPPORT_FUNCTIONS(InstrumentComponentImpl)
/* ----------------------------------------------------------------*/
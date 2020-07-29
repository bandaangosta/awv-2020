#include "InstrumentComponentImpl.h"
//#include <logging.h>
#include <iostream>

InstrumentComponentImpl::InstrumentComponentImpl(const ACE_CString& name, maci::ContainerServices * containerServices) : acscomponent::ACSComponentImpl::ACSComponentImpl(name, containerServices) {
    isOn = false;
}

InstrumentComponentImpl::~InstrumentComponentImpl() {
}

void InstrumentComponentImpl::cameraOn (void) {
    //Logging::Logger::LoggerSmartPtr logger = Logging::Logger::getNamedLogger("cppInstrument");
    if (!isOn) {
        std::cout << "Turning camera ON" << std::endl;
        isOn = true;
        if (isConfigured) {
            std::cout << "Reapplying configs for camera" << std::endl;
            setRGB(myRGBConfig);
            setPixelBias(myBias);
            setResetLevel(myResetLevel);
        }
        isConfigured = true;
    }
    else {
        std::cout << "Camera was already on!" << std::endl;
    }
}

void InstrumentComponentImpl::cameraOff (void) {
    if (isOn) {
        std::cout << "Turning camera OFF" << std::endl;
        isOn = false;
    }
    else {
        std::cout << "Camera was already off!" << std::endl;
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
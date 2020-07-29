#include "InstrumentComponentImpl.h"
//#include <logging.h>
#include <iostream>

InstrumentComponentImpl::InstrumentComponentImpl(const ACE_CString& name, maci::ContainerServices * containerServices) : acscomponent::ACSComponentImpl::ACSComponentImpl(name, containerServices) {
}

InstrumentComponentImpl::~InstrumentComponentImpl() {
}

void InstrumentComponentImpl::cameraOn (void) {
    //Logging::Logger::LoggerSmartPtr logger = Logging::Logger::getNamedLogger("cppInstrument");
    std::cout << "Turning camera ON" << std::endl;
}

void InstrumentComponentImpl::cameraOff (void) {
    std::cout << "Turning camera OFF" << std::endl;

}

::TYPES::ImageType * InstrumentComponentImpl::takeImage (::CORBA::Long exposureTime) {
    std::cout << "Taking a nice starry sky picture" << std::endl;
    return nullptr;
}

void InstrumentComponentImpl::setRGB (const ::TYPES::RGB & rgbConfig) {
    std::cout << "Setting RGB values to R: " << rgbConfig.red << " G: " << rgbConfig.green << " B: " << rgbConfig.blue << std::endl;
}

void InstrumentComponentImpl::setPixelBias (::CORBA::Long bias) {
    std::cout << "Setting Pixel Bias to " << bias << std::endl;
}

void InstrumentComponentImpl::setResetLevel (::CORBA::Long resetLevel) {
    std::cout << "Setting reset level to " << resetLevel << std::endl;
}

/* --------------- [ MACI DLL support functions ] -----------------*/
#include <maciACSComponentDefines.h>
MACI_DLL_SUPPORT_FUNCTIONS(InstrumentComponentImpl)
/* ----------------------------------------------------------------*/
#include "InstrumentComponentImpl.h"

InstrumentComponentImpl::InstrumentComponentImpl(const ACE_CString& name, maci::ContainerServices * containerServices) : acscomponent::ACSComponentImpl::ACSComponentImpl(name, containerServices) {
    myName = name;
    myContainer = containerServices;
}

void InstrumentComponentImpl::cameraOn (void);
void InstrumentComponentImpl::cameraOff (void);
::TYPES::ImageType * InstrumentComponentImpl::takeImage (::CORBA::Long exposureTime);
void InstrumentComponentImpl::setRGB (const ::TYPES::RGB & rgbConfig);
void InstrumentComponentImpl::setPixelBias (::CORBA::Long bias);
void InstrumentComponentImpl::setResetLevel (::CORBA::Long resetLevel);

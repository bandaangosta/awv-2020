#ifndef _INSTRUMENT_COMPONENT_IMPL_H
#define _INSTRUMENT_COMPONENT_IMPL_H
 
#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif
 
//Base component implementation, including container services and component lifecycle infrastructure
#include <acscomponentImpl.h>
 
 
//Skeleton interface for server implementation
#include <InstrumentS.h>
 
 
//Error definitions for catching and raising exceptions
//#include <ServiceErr.h>
//#include <InstrumentErr.h>

//TODO: Everything!
//ClassName usually is <Interface> or <Interface>Impl, but can be anything
class InstrumentComponentImpl: public virtual acscomponent::ACSComponentImpl, public POA_INSTRUMENT_MODULE::Instrument
{
  #warning TODO: Everything!
  #warning AS: These might not be needed (they are passed to the constructor of acscomponent::ACSComponentImpl)
  ACE_CString myName;
  maci::ContainerServices *myContainer;
  public:
    InstrumentComponentImpl(const ACE_CString& name, maci::ContainerServices * containerServices);

    virtual void cameraOn (void);
    virtual void cameraOff (void);
    virtual ::TYPES::ImageType * takeImage (::CORBA::Long exposureTime);
    virtual void setRGB (const ::TYPES::RGB & rgbConfig);
    virtual void setPixelBias (::CORBA::Long bias);
    virtual void setResetLevel (::CORBA::Long resetLevel);
};

#endif
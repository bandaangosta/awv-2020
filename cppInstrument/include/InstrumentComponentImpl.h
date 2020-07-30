#ifndef _INSTRUMENT_COMPONENT_IMPL_H
#define _INSTRUMENT_COMPONENT_IMPL_H
 
#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif
 
//Base component implementation, including container services and component lifecycle infrastructure
#include <acscomponentImpl.h>
 
 
//Skeleton interface for server implementation
#include <InstrumentS.h>
#include <CameraC.h>
 
//Error definitions for catching and raising exceptions
//#include <ServiceErr.h>
//#include <InstrumentErr.h>

//TODO: Everything!
//ClassName usually is <Interface> or <Interface>Impl, but can be anything
class InstrumentComponentImpl: public virtual acscomponent::ACSComponentImpl, public POA_INSTRUMENT_MODULE::Instrument
{
  #warning TODO: CORBA calls instead of couts
  bool isOn, isConfigured;
  ::CORBA::Long myBias, myResetLevel;
  ::TYPES::RGB myRGBConfig;
  ::CAMERA_MODULE::Camera_var myCamera;

  void throwIfOff();

  public:
    InstrumentComponentImpl(const ACE_CString& name, maci::ContainerServices * containerServices);
    virtual ~InstrumentComponentImpl();
    virtual void initialize();
    virtual void execute();
    virtual void cleanup();
    virtual void aboutToAbort();
    virtual void cameraOn (void);
    virtual void cameraOff (void);
    virtual ::TYPES::ImageType * takeImage (::CORBA::Long exposureTime);
    virtual void setRGB (const ::TYPES::RGB & rgbConfig);
    virtual void setPixelBias (::CORBA::Long bias);
    virtual void setResetLevel (::CORBA::Long resetLevel);
};

#endif
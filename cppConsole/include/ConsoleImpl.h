#ifndef _CONSOLE_COMPONENT_IMPL_H
#define _CONSOLE_COMPONENT_IMPL_H

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif
 
//Base component implementation, including container services and component lifecycle infrastructure
#include <acscomponentImpl.h>

//Skeleton interface for server implementation
#include <ConsoleS.h>
 
//Error definitions for catching and raising exceptions
class ConsoleImpl : public virtual acscomponent::ACSComponentImpl, public virtual POA_CONSOLE_MODULE::Console {
  public:
    
    ConsoleImpl(const ACE_CString& name, maci::ContainerServices * containerServices);

    virtual ~ConsoleImpl();
   
    void setMode (::CORBA::Boolean mode);

    ::CORBA::Boolean getMode (void);

    void cameraOn (void);

    void cameraOff (void);

    void moveTelescope(const ::TYPES::Position & coordinates);

    ::TYPES::Position getTelescopePosition();
    
    ::TYPES::ImageType * getCameraImage (void);

    void setRGB (const ::TYPES::RGB & rgbConfig);

    void setPixelBias (::CORBA::Long bias);

    void setResetLevel (::CORBA::Long resetLevel);


};
 
#endif
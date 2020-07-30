#ifndef TelescopeImpl_h
#define TelescopeImpl_h

#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include <acscomponentImpl.h>
#include <TypesS.h>
#include <TelescopeS.h>
#include <TelescopeControlS.h>
#include <InstrumentS.h>
#include <SYSTEMErr.h>


//class TelescopeImpl; // declaration

class TelescopeImpl: public acscomponent::ACSComponentImpl,public virtual POA_TELESCOPE_MODULE::Telescope
{
 public:  
  TelescopeImpl(const ACE_CString& name,maci::ContainerServices *& containerServices);  
  virtual ~TelescopeImpl();
  virtual ::TYPES::ImageType * observe (const ::TYPES::Position & coordinates, ::CORBA::Long exposureTime);
  virtual void moveTo (const ::TYPES::Position & coordinates);  
  virtual ::TYPES::Position getCurrentPosition (void);
  
  private:
    TYPES::Position Pos;
    TELESCOPE_MODULE::TelescopeControl_var telescope_pointer;
    INSTRUMENT_MODULE::Instrument_var instrument_pointer;
}; 


#endif


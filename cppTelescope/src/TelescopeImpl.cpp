#include "TelescopeImpl.h"

TelescopeImpl::TelescopeImpl(const ACE_CString& name, maci::ContainerServices *& containerServices):
  POA_TELESCOPE_MODULE::Telescope(),
  acscomponent::ACSComponentImpl(name, containerServices)
{
  telescope_pointer  = getContainerServices()->getComponent<TELESCOPE_MODULE::TelescopeControl>("TELESCOPE_CONTROL");   
  instrument_pointer  = getContainerServices()->getComponent<INSTRUMENT_MODULE::Instrument>("INSTRUMENT");     
  Pos.el = 45.0;
  Pos.az = 45.0;
}


TelescopeImpl::~TelescopeImpl() {

}


TYPES::ImageType * 
TelescopeImpl::observe (const ::TYPES::Position & coordinates,::CORBA::Long exposureTime) 
{
  TYPES::ImageType_var image = new TYPES::ImageType;
  image->length(1);

  if ((coordinates.el >= 0) && (coordinates.el < 90)) {
    moveTo (coordinates);
  } else { 
    SYSTEMErr::PositionOutOfLimitsExImpl ex(__FILE__, __LINE__, "Telescope Control::OutOfLimits");
    throw ex.getPositionOutOfLimitsEx();
  }

  try {
    image = instrument_pointer->takeImage(exposureTime);
  } catch (SYSTEMErr::CameraIsOffExImpl ex){
    ex.log();
    //ACS_SHORT_LOG((LM_INFO, "SYSTEMErr::CameraIsOffEx");
  } catch (...) {
    ACS_SHORT_LOG((LM_INFO, "I don't know Error"));
    image->length(0);
    
  }

  return image._retn();
}

void TelescopeImpl::moveTo (const ::TYPES::Position & coordinates)
{
  ACS_SHORT_LOG((LM_INFO,"Telescope::moveTo")); 
  telescope_pointer->objfix(coordinates.el,coordinates.az);
  return;
}


TYPES::Position TelescopeImpl::getCurrentPosition (void) 
{
  return this->Pos;
}


#include <maciACSComponentDefines.h>
MACI_DLL_SUPPORT_FUNCTIONS (TelescopeImpl);


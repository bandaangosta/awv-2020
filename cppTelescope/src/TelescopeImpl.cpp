#include "TelescopeImpl.h"

TelescopeImpl::TelescopeImpl(const ACE_CString& name, maci::ContainerServices *& containerServices):
  POA_TELESCOPE_MODULE::Telescope(),
  acscomponent::ACSComponentImpl(name, containerServices)
{
  telescope_pointer  = getContainerServices()->getComponent<TELESCOPE_MODULE::TelescopeControl>("TELESCOPE_CONTROL");   
  Pos.el = 90.0;
  Pos.az = 45.0;
}


TelescopeImpl::~TelescopeImpl() {

}


TYPES::ImageType * 
TelescopeImpl::observe (
		       const ::TYPES::Position & coordinates,
		       ::CORBA::Long exposureTime) 
{
  TYPES::ImageType * image = NULL;  
  return ;
}

void TelescopeImpl::moveTo (const ::TYPES::Position & coordinates)
{
  ACS_SHORT_LOG((LM_INFO,"Telescope::moveTo")); 
  telescope_pointer->setTo(Pos.el,Pos.az);
  return;
}


TYPES::Position TelescopeImpl::getCurrentPosition (void) 
{
  return this->Pos;
}


#include <maciACSComponentDefines.h>
MACI_DLL_SUPPORT_FUNCTIONS (TelescopeImpl);


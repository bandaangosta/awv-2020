#include <ConsoleImpl.h>

ConsoleImpl::ConsoleImpl(const ACE_CString& name, maci::ContainerServices * containerServices) : acscomponent::ACSComponentImpl(name, containerServices)
{   
    this->mode_ = false;
}

ConsoleImpl::~ConsoleImpl()
{

}
   
void ConsoleImpl::setMode(::CORBA::Boolean new_mode)
{
    /* 
    How to interact with components:    https://confluence.alma.cl/pages/viewpage.action?pageId=54005360
 
        <Module>:: <Interface>_var comp = this->getContainerServices()->getComponent< Module::Interface > ("<Name>");
        
        <interface>_var is a predefined type (smart pointer). Do not release it explicitly (but release the component with releaseComponent)

        comp.in()
        comp.out()
        comp.inout() 
        comp.ptr() // it gets the underlying reference of the pointer
        comp._retn() 

    */
  
  
    if (this->mode_ == new_mode)    // no change...
    {
        if(!this->mode_)// If internal mode is changed from Manual to Manual nothing happens
        {
            return; 
        } else {    // Auto->Auto .... boom
            throw SYSTEMErr::AlreadyInAutomaticExImpl(__FILE__, __LINE__, "setMode(..) raises an Exception").getAlreadyInAutomaticEx();
        }
    }
  
    SCHEDULER_MODULE::Scheduler_var scheduler_comp = this->getContainerServices()->getComponent<SCHEDULER_MODULE::Scheduler>("SCHEDULER");

    // If internal mode is changed from Manual to Automatic, start method in Scheduler gets called 
    if(! this->mode_)
    {   
        scheduler_comp->start();        
    } else {    // If internal mode is changed from Automatic to Manual, stop method in Scheduler gets called

    // If internal mode is changed from Automatic to Manual, stop method in Scheduler gets called
        scheduler_comp->stop();
    }
   
    this->mode_ = new_mode;

    this->getContainerServices()->releaseComponent(scheduler_comp->name());

    
}

CORBA::Boolean ConsoleImpl::getMode()
{
    return this->mode_;
}

void ConsoleImpl::cameraOn()
{   
    if (this->mode_)
    {
        throw SYSTEMErr::SystemInAutoModeExImpl(__FILE__, __LINE__, "cameraOn() Cannot manually control Camera in Auto mode.").getSystemInAutoModeEx();
    }
   
    INSTRUMENT_MODULE::Instrument_var Instrument_comp = this->getContainerServices()->getComponent<INSTRUMENT_MODULE::Instrument>("INSTRUMENT");
    Instrument_comp->cameraOn();
    this->getContainerServices()->releaseComponent(Instrument_comp->name());
}

void ConsoleImpl::cameraOff()
{
   if (this->mode_)
    {
        throw SYSTEMErr::SystemInAutoModeExImpl(__FILE__, __LINE__, "cameraOff() Cannot manually control Camera in Auto mode.").getSystemInAutoModeEx();
    }
    INSTRUMENT_MODULE::Instrument_var Instrument_comp = this->getContainerServices()->getComponent<INSTRUMENT_MODULE::Instrument>("INSTRUMENT");
    Instrument_comp->cameraOff();
    this->getContainerServices()->releaseComponent(Instrument_comp->name());
}

void ConsoleImpl::moveTelescope(const ::TYPES::Position & coordinates)
{

    if (this->mode_)
    {
        throw SYSTEMErr::SystemInAutoModeExImpl(__FILE__, __LINE__, "moveTelescope() Cannot manually move telescope in Auto mode.").getSystemInAutoModeEx();
    }
    
    TELESCOPE_MODULE::Telescope_var Telescope_comp = this->getContainerServices()->getComponent<TELESCOPE_MODULE::Telescope>("TELESCOPE");
    
    Telescope_comp->moveTo(coordinates);

    this->getContainerServices()->releaseComponent(Telescope_comp->name());
    
}

::TYPES::Position ConsoleImpl::getTelescopePosition()
{
    TELESCOPE_MODULE::Telescope_var Telescope_comp = this->getContainerServices()->getComponent<TELESCOPE_MODULE::Telescope>("TELESCOPE");
    ::TYPES::Position p = Telescope_comp->getCurrentPosition();
    this->getContainerServices()->releaseComponent(Telescope_comp->name());
    
    return p;
}
    
::TYPES::ImageType * ConsoleImpl::getCameraImage (void)
{   
       
    if (this->mode_)
    {
        throw SYSTEMErr::SystemInAutoModeExImpl(__FILE__, __LINE__, "getCameraImage() Cannot manually get camera image in Auto mode.").getSystemInAutoModeEx();
    }

    INSTRUMENT_MODULE::Instrument_var Instrument_comp = this->getContainerServices()->getComponent<INSTRUMENT_MODULE::Instrument>("INSTRUMENT");
    ::TYPES::ImageType * image = nullptr;
    long exposureTime = 1; //default value (max exp = 5)
  
    image = Instrument_comp->takeImage(exposureTime);
    
    this->getContainerServices()->releaseComponent(Instrument_comp->name());

    return image;
}

void ConsoleImpl::setRGB (const ::TYPES::RGB & rgbConfig)
{
    if (this->mode_)
    {
        throw SYSTEMErr::SystemInAutoModeExImpl(__FILE__, __LINE__, "setRGB() Cannot manually control camera in Auto mode.").getSystemInAutoModeEx();
    }
    INSTRUMENT_MODULE::Instrument_var Instrument_comp = this->getContainerServices()->getComponent<INSTRUMENT_MODULE::Instrument>("INSTRUMENT");
    Instrument_comp->setRGB(rgbConfig);
    this->getContainerServices()->releaseComponent(Instrument_comp->name());
}

void ConsoleImpl::setPixelBias (::CORBA::Long bias)
{   
    if (this->mode_)
    {
        throw SYSTEMErr::SystemInAutoModeExImpl(__FILE__, __LINE__, "setPixelBias() Cannot manually set pixel bias camera in Auto mode.").getSystemInAutoModeEx();
    }
    INSTRUMENT_MODULE::Instrument_var Instrument_comp = this->getContainerServices()->getComponent<INSTRUMENT_MODULE::Instrument>("INSTRUMENT");
    Instrument_comp->setPixelBias(bias);
    this->getContainerServices()->releaseComponent(Instrument_comp->name());
}

void ConsoleImpl::setResetLevel (::CORBA::Long resetLevel) 
{
    if (this->mode_)
    {
        throw SYSTEMErr::SystemInAutoModeExImpl(__FILE__, __LINE__, "setResetLevel() Cannot manually control camera in Auto mode.").getSystemInAutoModeEx();
    }
    INSTRUMENT_MODULE::Instrument_var Instrument_comp = this->getContainerServices()->getComponent<INSTRUMENT_MODULE::Instrument>("INSTRUMENT");
    Instrument_comp->setResetLevel(resetLevel);
    this->getContainerServices()->releaseComponent(Instrument_comp->name());}

/* --------------- [ MACI DLL support functions ] -----------------*/
  
#include <maciACSComponentDefines.h>
MACI_DLL_SUPPORT_FUNCTIONS (ConsoleImpl)
  
/* ----------------------------------------------------------------*/


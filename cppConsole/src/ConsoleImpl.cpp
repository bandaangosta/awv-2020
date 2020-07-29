#include <ConsoleImpl.h>

ConsoleImpl::ConsoleImpl(const ACE_CString& name, maci::ContainerServices * containerServices) : acscomponent::ACSComponentImpl(name, containerServices)
{

}

ConsoleImpl::~ConsoleImpl()
{
}
   
void ConsoleImpl::setMode(::CORBA::Boolean mode)
{
}

::CORBA::Boolean ConsoleImpl::getMode()
{
    return true;
}

void ConsoleImpl::cameraOn()
{
    // we need to communicate with the Camera component
    // 
    // 
}

void ConsoleImpl::cameraOff()
{

}

void ConsoleImpl::moveTelescope(const ::TYPES::Position & coordinates)
{
    
}

::TYPES::Position ConsoleImpl::getTelescopePosition()
{
    /*
         struct Position {
                double az;
                double el;
        };

    */

    ::TYPES::Position p;
    return p;
}
    
::TYPES::ImageType * ConsoleImpl::getCameraImage (void)
{
    return nullptr;
}

void ConsoleImpl::setRGB (const ::TYPES::RGB & rgbConfig)
{
    
}

void ConsoleImpl::setPixelBias (::CORBA::Long bias)
{
    
}

void ConsoleImpl::setResetLevel (::CORBA::Long resetLevel) 
{

}


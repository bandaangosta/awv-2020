#include <cppSchedulingImpl.h>
 
cppSchedulingImpl::cppSchedulingImpl(const ACE_CString& name, maci::ContainerServices * containerServices) : ACSComponentImpl(name, containerServices) {
}
 
cppSchedulingImpl::~cppSchedulingImpl() {
}
 
char* cppSchedulingImpl::printHello() {
    std::cout << "Just printing 'Hello World!'" << std::endl;
    return CORBA::string_dup("Hello World!");
}


void cppSchedulingImpl::start() {
    std::cout << "cppScheduling Starting" << std::endl;
}

void cppSchedulingImpl::stop(){
    std::cout << "cppScheduling Stoping" << std::endl;

}
CORBA::Long cppSchedulingImpl::proposalUnderExecution(){
    std::cout << "cppScheduling proposalUnderExecution" << std::endl;
    long value = 1234;
    return value;
}
 
/* --------------- [ MACI DLL support functions ] -----------------*/
#include <maciACSComponentDefines.h>
MACI_DLL_SUPPORT_FUNCTIONS(cppSchedulingImpl)
/* ----------------------------------------------------------------*/
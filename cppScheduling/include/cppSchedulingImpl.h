#ifndef _CPPSCHEDULING_IMPL_H
#define _CPPSCHEDULING_IMPL_H
 
#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif
 
//Base component implementation, including container services and component lifecycle infrastructure
#include <acscomponentImpl.h>
 
//Skeleton interface for server implementation
#include <cppSchedulingS.h>
 
//Error definitions for catching and raising exceptions
class cppSchedulingImpl : public virtual acscomponent::ACSComponentImpl, public virtual POA_workshop::cppScheduling {
  public:
    cppSchedulingImpl(const ACE_CString& name, maci::ContainerServices * containerServices);
    virtual ~cppSchedulingImpl();
    char* printHello();
    void start();
    void stop();
    CORBA::Long proposalUnderExecution();
};
 
#endif
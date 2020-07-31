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
#include <DataBaseC.h>
#include <InstrumentC.h>
#include <TelescopeC.h>
#include <SYSTEMErr.h>

#include <thread>
#include <exception>

// Declare Scheduling class
class cppSchedulingImpl : public virtual acscomponent::ACSComponentImpl, public virtual POA_workshop::Scheduler {
  private:
    CORBA::Long proposalUnderExecutionID;
    bool isRunning;
    bool processObservations;
    // std::thread
    std::thread thread_proposal;
    INSTRUMENT_MODULE::Instrument_var instrument;
    DATABASE_MODULE::DataBase_var database;
    TELESCOPE_MODULE::Telescope_var telescope;
    void processProposals();
    std::thread proposals_thread;
  
  public:
    cppSchedulingImpl(const ACE_CString& name, maci::ContainerServices * containerServices);
    virtual ~cppSchedulingImpl();
    char* printHello();

    // Lifecycle functionality:
    void initialize();
    void execute();
    void cleanUp();
    void aboutToAbort();

    void start();
    void stop();
    CORBA::Long proposalUnderExecution();
};
 
#endif
#ifndef _DATA_BASE_IMPL_H
#define _DATA_BASE_IMPL_H
 
#ifndef __cplusplus
#error This is a C++ include file and cannot be used from plain C
#endif

#include <map>
 
//Base component implementation, including container services and component lifecycle infrastructure
#include <acscomponentImpl.h>
 
//Skeleton interface for server implementation
#include <DataBaseS.h>
 
//Error definitions for catching and raising exceptions
class DataBaseImpl : public virtual acscomponent::ACSComponentImpl, public virtual POA_DATABASE_MODULE::DataBase {
  public:
    DataBaseImpl(const ACE_CString& name, maci::ContainerServices * containerServices);
    virtual ~DataBaseImpl();
    virtual CORBA::Long storeProposal (const TYPES::TargetList &targets);
    virtual CORBA::Long getProposalStatus(CORBA::Long pid);
    virtual void removeProposal(CORBA::Long pid);
    virtual TYPES::ImageList * getProposalObservations(CORBA::Long pid);
    virtual TYPES::ProposalList * getProposals();
    virtual void setProposalStatus(CORBA::Long pid, CORBA::Long status);
    virtual void storeImage(CORBA::Long pid, 
            CORBA::Long tid,
            const TYPES::ImageType &image);
    virtual void clean();
  private:

  typedef enum {
    QUEUED = 0,
    RUNNING = 1,
    READY = 2,
    REMOVED = 999
  } ProposalType;

   TYPES::ProposalList m_proposals;
   std::map<CORBA::Long,TYPES::ImageType*> m_images;
   CORBA::Long m_current_pid;
};
 
#endif
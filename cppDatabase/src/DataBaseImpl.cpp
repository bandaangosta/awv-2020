#include <DataBaseImpl.h>
 
DataBaseImpl::DataBaseImpl(const ACE_CString& name, maci::ContainerServices * containerServices) 
: ACSComponentImpl(name, containerServices) 
, m_current_proposal_pid(0) 
, m_proposals(new TYPES::ProposalList(999))
, m_targets(new TYPES::TargetList())
{

}
 
DataBaseImpl::~DataBaseImpl() 
{
    delete m_proposals;
    delete m_targets;
}
 
/**
 * Stores a new Proposal.
 * 
 * @param targets Target list composing this proposal.
 * @return Assigned proposal ID (pid).
 */
CORBA::Long DataBaseImpl::storeProposal(const TYPES::TargetList &targets)
{
    //TODO: implement - maybe add check for empty targets
    //TODO: this will overflow at some point
    TYPES::Proposal tmp_proposal;
    tmp_proposal.pid = m_current_proposal_pid;
    tmp_proposal.targets = targets;
    tmp_proposal.status = DataBase::STATUS_INITIAL_PROPOSAL; 
    (*m_proposals)[m_current_proposal_pid] = tmp_proposal;
    CORBA::Long tmp_ret = m_current_proposal_pid;
    m_current_proposal_pid++;
    return tmp_ret;
}

/** 
 * Get the current proposal status for the given
 * proposal.
 *
 * @param pid Proposal ID
 * @return status
 */
CORBA::Long DataBaseImpl::getProposalStatus(CORBA::Long pid)
{
    //TODO: implement
    std::cout << "status is TODO" << std::endl;
    return 0;
}

/** 
 * Remove proposal.
 *
 * @param pid Proposal ID
 */
void DataBaseImpl::removeProposal(CORBA::Long pid)
{
    //TODO: implement
    //Victor on it
    /*
    Removes the proposal associated with given proposal ID
    If the proposal ID is not present, then do not execute any operation and don't report any problem
    */
   
    // 1st check every item on our m_proposals
    
    // 2nd for every proposal check if the id matches the given pid

        //if pid matches remove the proposal from the list

    // 3rd if the pid is not on the list write a LOG telling that there is no pid on m_proposals



}

/**
 * Retuns all images for a given proposal. 
 * Raises an exception if proposal has not been 
 * executed yet.
 *
 * @param pid Proposal ID
 * @return Image list that beCORBA::Longs to this proposal
 */
TYPES::ImageList * DataBaseImpl::getProposalObservations(CORBA::Long pid)
{
    //TODO: implement
    //raises(SYSTEMErr::ProposalNotYetReadyEx);
    return m_images;
}


/**
 * Returns stored proposals which have not been executed yet.
 *
 * @return Proposals with queued status. If there are no 
 * pending proposals returns an empty list
 */
TYPES::ProposalList * DataBaseImpl::getProposals()
{
    //TODO: implement
    return m_proposals;
}

/**
* Set the proposal status. Raises an exception if the change is not from
* queued(0) to running(1) or from running(1) to ready(2).
*
* @param pid Proposal ID
* @param tid target ID
* @return None
*/
void DataBaseImpl::setProposalStatus(CORBA::Long pid, CORBA::Long status)
{
    //TODO: impl
    //raises(SYSTEMErr::InvalidProposalStatusTransitionEx);
}

/**
* Stores an image for a given proposal and target. Raises an exception
* if an image has already been stored for the given 
* tid and pid.
*
* @param pid Proposal ID
* @param tid target ID
* @return None
*/
void DataBaseImpl::storeImage(CORBA::Long pid, CORBA::Long tid, const TYPES::ImageType &image)
{
    // TODO: implement
    //raises(SYSTEMErr::ImageAlreadyStoredEx); // TODO raise also new exception "ProposalDoesNotExist"
}
/**
* Clean all the proposals
*/
void DataBaseImpl::clean()
{
    //TODO: implement

}
 
/* --------------- [ MACI DLL support functions ] -----------------*/
#include <maciACSComponentDefines.h>
MACI_DLL_SUPPORT_FUNCTIONS(DataBaseImpl)
/* ----------------------------------------------------------------*/

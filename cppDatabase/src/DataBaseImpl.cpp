#include <DataBaseImpl.h>
 
DataBaseImpl::DataBaseImpl(const ACE_CString& name, maci::ContainerServices * containerServices) : ACSComponentImpl(name, containerServices) {
}
 
DataBaseImpl::~DataBaseImpl() {
}
 
/**
 * Stores a new Proposal.
 * 
 * @param targets Target list composing this proposal.
 * @return Assigned proposal ID (pid).
 */
CORBA::Long DataBaseImpl::storeProposal(const TYPES::TargetList &targets)
{
    //TODO: implement
    return 0;
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

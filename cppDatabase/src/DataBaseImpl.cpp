#include <DataBaseImpl.h>
#include <SYSTEMErr.h>
 
template<class Seq, class T>
void push_back(Seq& seq, const T& item)
{
   const CORBA::ULong len = seq.length();
   seq.length(len + 1);
   seq[len] = item;
}

DataBaseImpl::DataBaseImpl(const ACE_CString& name, maci::ContainerServices * containerServices) 
: ACSComponentImpl(name, containerServices) 
, m_current_pid(0) 
{

}
 
DataBaseImpl::~DataBaseImpl() 
{
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
    tmp_proposal.pid = m_current_pid;
    tmp_proposal.targets = targets;
    tmp_proposal.status = DATABASE_MODULE::DataBase::STATUS_INITIAL_PROPOSAL; 
    push_back(m_proposals,tmp_proposal);
    CORBA::Long tmp_ret = m_current_pid;
    m_current_pid++;
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
    for (unsigned i = 0; i < m_proposals.length(); i++)
    {
        if (pid == m_proposals[i].pid)
        {
            return m_proposals[pid].status;
        }
    }
    return DATABASE_MODULE::DataBase::STATUS_NO_SUCH_PROPOSAL;
}

/** 
 * Remove proposal.
 *
 * @param pid Proposal ID
 */
void DataBaseImpl::removeProposal(CORBA::Long pid)
{
    //TODO: implement
    //iterate over TYPES::ProposalList m_proposals;
    for (unsigned i = 0; i < m_proposals.length(); i++)
    {
        if (pid == m_proposals[i].pid)
        {
            m_proposals[i].status = REMOVED;
        }
    }
    //log end of function

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
    TYPES::ImageList_var ret_images = new TYPES::ImageList;
    for (unsigned i = 0; i < m_proposals.length(); i++)
    {
        if (pid == m_proposals[i].pid)
        {
            if (m_proposals[i].status == READY)
            {
                // fetch the image list
                TYPES::TargetList &tmp_targetlist = m_proposals[i].targets;
                for (unsigned j = 0; j < tmp_targetlist.length(); j++)
                {
                    std::map<CORBA::Long,TYPES::ImageType*>::const_iterator it = m_images.find(tmp_targetlist[j].tid);
                    if (it != m_images.end())
                    {
                        push_back(*ret_images,*(it->second));
                    }
                }
            }
            else
            {
                throw SYSTEMErr::ProposalNotYetReadyExImpl(__FILE__, __LINE__, "This proposal is not ready").getProposalNotYetReadyEx();
            }
        }
    }
    return ret_images._retn();
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
    TYPES::ProposalList_var ret_proposals = new TYPES::ProposalList;
    for (unsigned i = 0; i < m_proposals.length(); i++)
    {
        if (m_proposals[i].status == DATABASE_MODULE::DataBase::STATUS_INITIAL_PROPOSAL)
        {
            push_back(*ret_proposals,m_proposals[i]);
        }
    }
    return ret_proposals._retn();
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
    for (unsigned i = 0; i < m_proposals.length(); i++)
    {
        if (pid == m_proposals[i].pid)
        {
            if ((status >= 0) && (status <= RUNNING))
            {
                if (status - m_proposals[i].status == 1)
                {
                    m_proposals[i].status = status;
                }
                else
                {
                    throw SYSTEMErr::InvalidProposalStatusTransitionExImpl(__FILE__, __LINE__, "This proposal transition is not valid").getInvalidProposalStatusTransitionEx();
                }
            }
            else
            {
                throw SYSTEMErr::InvalidProposalStatusTransitionExImpl(__FILE__, __LINE__, "This proposal transition is not valid").getInvalidProposalStatusTransitionEx();
            }
        }
    }
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
    auto it = m_images.find(tid);
    if (it != m_images.end())
    {
        throw SYSTEMErr::ImageAlreadyStoredExImpl(__FILE__, __LINE__, "This image has been already stored").getImageAlreadyStoredEx();
    }
    for (unsigned i = 0; i < m_proposals.length(); i++)
    {
        if (pid == m_proposals[i].pid)
        {
            TYPES::TargetList &tmp_targetlist = m_proposals[pid].targets;
            for (unsigned j = 0; j < tmp_targetlist.length(); j++)
            {
                if (tid == tmp_targetlist[j].tid)
                {
                    m_images[tid] = new TYPES::ImageType(image);
                    return;
                }
            }
            throw SYSTEMErr::TargetDoesNotExistExImpl(__FILE__, __LINE__, "This target does not exist").getTargetDoesNotExistEx();
        }
    }
    throw SYSTEMErr::ProposalDoesNotExistExImpl(__FILE__, __LINE__, "This proposal does not exist").getProposalDoesNotExistEx();
    
    //raises(SYSTEMErr::ImageAlreadyStoredEx); // TODO raise also new exception "ProposalDoesNotExist"
}
/**
* Clean all the proposals
*/
void DataBaseImpl::clean()
{
    m_proposals.length(0);
}
 
/* --------------- [ MACI DLL support functions ] -----------------*/
#include <maciACSComponentDefines.h>
MACI_DLL_SUPPORT_FUNCTIONS(DataBaseImpl)
/* ----------------------------------------------------------------*/


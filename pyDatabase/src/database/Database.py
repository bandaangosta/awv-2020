import TYPES
import DATABASE_MODULE
import DATABASE_MODULE__POA
from Acspy.Servants.ACSComponent import ACSComponent
from Acspy.Servants.ContainerServices import ContainerServices
from Acspy.Servants.ComponentLifecycle import ComponentLifecycle
import SYSTEMErr
import SYSTEMErrImpl

STATUS_INITIAL_PROPOSAL = 0
STATUS_NO_SUCH_PROPOSAL = -999

class Database(DATABASE_MODULE__POA.DataBase, ACSComponent, ContainerServices, ComponentLifecycle):

    def __init__(self):
        ACSComponent.__init__(self)
        ContainerServices.__init__(self)
        self.proposalId = 0
        self.proposalList = []
        self.imageList = []

    def storeProposal(self, targets):
        proposal = TYPES.Proposal(self.proposalId, targets, STATUS_INITIAL_PROPOSAL)
        self.proposalList.append(proposal)
        self.imageList.append(dict())
        self.proposalId += 1
        return self.proposalId - 1

    def getProposalStatus(self, pid):
        if pid < self.proposalId:
            return self.proposalList[pid].status
        else:
            return STATUS_NO_SUCH_PROPOSAL

    def removeProposal(self, pid):
        if pid < self.proposalId and (not self.proposalList[pid].status==STATUS_NO_SUCH_PROPOSAL):
            self.proposalList[pid].status = STATUS_NO_SUCH_PROPOSAL

    def getProposalObservations(self, pid):
        image_list = []
        if self.proposalList[pid].status == 2:
            for target in self.proposalList[pid].TargetList:
                tid = target.tid
                if tid in self.imageList[pid].keys():
                    image_list.append(self.imageList[pid][tid])
                else:
                    image_list.append(str(bytearray([])))
            return image_list
        else:
            raise SYSTEMErrImpl.ProposalNotYetReadyExImpl()
        return

    def getProposals(self):
        plist = []
        for p in self.proposalList:
            if p.status == 0:
                plist.append(p)

        return plist

    def setProposalStatus(self, pid, status):
        if pid < self.proposalId and (not self.proposalList[pid].status==STATUS_NO_SUCH_PROPOSAL):
            current_status=self.proposalList[pid].status
            c1=(status in [1,2])
            c2=(current_status==0 and status==1)
            c3=(current_status==1 and status==2)
            if c1 and (c2 or c3):
                self.proposalList[pid].status=status
            else:
                raise SYSTEMErrImpl.InvalidProposalStatusTransitionExImpl()
        return

    def storeImage(self, pid, tid, image):
        if pid < self.proposalId:
            tids = [target.tid for target in self.proposalList[pid]]
            tid_exists = (tid in tids) 
            #tid_exists = False
            #for target in self.proposalList[pid].targets:
            #    if target.tid == tid:
            #        tid_exists = True
            if tid_exists:
                if not tid in self.imageList[pid].keys():
                    self.imageList[pid][tid]=image
                else:
                    raise SYSTEMErrImpl.ImageAlreadyStoredExImpl()
            else:
                raise SYSTEMErrImpl.TargetDoesNotExistExImpl()
        else:
            raise SYSTEMErrImpl.ProposalDoesNotExistExImpl() 

    def clean():
        self.proposalList = []
        self.imageList = []
        self.proposalId = 0
        return

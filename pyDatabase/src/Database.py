#Client stubs and definitions, such as structs, enums, etc.
import workshop
#Skeleton infrastructure for server implementation
import workshop__POA
import TYPES
  
#Base component implementation
from Acspy.Servants.ACSComponent import ACSComponent
#Services provided by the container to the component
from Acspy.Servants.ContainerServices import ContainerServices
#Basic component lifecycle (initialize, execute, cleanUp and aboutToAbort methods)
from Acspy.Servants.ComponentLifecycle import ComponentLifecycle


class Database(DATABASE_MODULE__POA.DataBase, ACSComponent, ContainerServices, ComponentLifecycle):
    
    def __init__(self):
        ACSComponent.__init__(self)
        ContainerServices.__init__(self)

    def storeProposal(self, targets):
        return 1

    def getProposalStatus(self, pid):
        return 1

    def removeProposa(self, pid):
        return

    def getProposalObservations(self, pid):
        return []
    
    def getProposals(self):
        return []

    def setProposalStatus(self, pid, status):
        return
    
    def storeImage(self, pid, tid, image):
        return 

    def clean(self):
        return
    

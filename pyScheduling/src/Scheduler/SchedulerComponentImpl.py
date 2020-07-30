#Client stubs and definitions, such as structs, enums, etc.
import SCHEDULER_MODULE
#Skeleton infrastructure for server implementation
import SCHEDULER_MODULE__POA

import SYSTEMErr
import SYSTEMErrImpl

#Base component implementation
from Acspy.Servants.ACSComponent import ACSComponent
#Services provided by the container to the component
from Acspy.Servants.ContainerServices import ContainerServices
#Basic component lifecycle (initialize, execute, cleanUp and aboutToAbort methods)
from Acspy.Servants.ComponentLifecycle import ComponentLifecycle
  
class SchedulerComponentImpl(SCHEDULER_MODULE__POA.Scheduler, ACSComponent, ContainerServices, ComponentLifecycle):
    
    

    def __init__(self):
        ACSComponent.__init__(self)
        ContainerServices.__init__(self)
        self._logger = self.getLogger()
        self.status=0
        self._database_comp = None
        self._proposals_list = None
        self.all_proposals_done = False
    

    def start(self):
        
        #print("Just printing 'Hello World!'")
        
        #try:

        if (self.status==1):
            raise SYSTEMErrImpl.SchedulerAlreadyRunningExImpl().getSchedulerAlreadyRunningEx()
       
        self.status=1
        
        self._database_comp = self.getComponent("DATABASE")

        
        #self._logger.info("log status '%s' and an int (%d)" % ("Log Entry",self._proposals_list[0].status))
         

        while(self.status==1 and not self.all_proposals_done):

            self._proposals_list = self._database_comp.getProposals()
            
            self.all_proposals_done=True

            for proposal in self._proposals_list:
                
                #proposal.status = 2

                if (proposal.status!=2):
                    self.all_proposals_done=False


                #self._database_comp.setProposalStatus(proposal.pid, 2)
            
                self._logger.info("log status '%s' and an int (%d)" % ("Log Entry",proposal.status))
        
                
                #print(proposal.status . "\n")

                #self._logger.logInfo(proposal)
            
            

        #except SYSTEMErr.AlreadyInAutomaticEx as e:
         
        


    def stop(self):

        if (self.status==0):
           raise SYSTEMErrImpl.SchedulerAlreadyStoppedExImpl().getSchedulerAlreadStoppedEx()
     
        self.status=0
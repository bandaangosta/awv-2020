from threading import Thread, Lock

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
        self._proposals_list = None
        self.all_proposals_done = False
    
    def initialize(self):
        self._database_comp = self.getComponent("DATABASE")
        self._telescope_comp = self.getComponent("TELESCOPE")
        self._instrument_comp = self.getComponent("INSTRUMENT")
    
    def execute(self):
        """ (this is a lifecycle method - c.f. lifecycle.idl  I guess :|     )
            Called after initialize to tell the component that it has to be ready to accept incoming functional calls any time
            Consider ready to receive calls (Change states if appropriate)

            To me (DN) it is unclear what to put in __init__, initialze or execute at the moment.
            The C++ people have put the getComponent calls into execute.
        """
        pass

    def execute_proposals():
        """(executed as a target of a thread, which is started in self.start)

        - get list of proposals 
        - start them
        - ...
        """
        """
        for proposal in self._database_comp.getProposals():
            if not proposal:
                continue

            
            self._instrument_comp.start_or_so_forgot_name()
            for target in proposal.targets:
                image = self._telescope_comp.start(traget)

                self._telescope_comp.storeImage(proposal.id, target.id, image) 
            self._instrument_comp.stop_or_so_forgot_name()

            
        """
        pass
            
            
            
            
            # we need a compilable version to push
            
    def start(self):
        """(called from the outside)

        start a thread, which is executing, self.execute_proposals (once ... I think)
        """
        #print("Just printing 'Hello World!'")

        if (self.status==1):
            raise SYSTEMErrImpl.SchedulerAlreadyRunningExImpl().getSYSTEMErrEx()
       
        self.status=1
        
        #self._logger.info("log status '%s' and an int (%d)" % ("Log Entry",self._proposals_list[0].status))
         
        self._proposals_list = self._database_comp.getProposals()
        
        self.all_proposals_done=True
        
            
        for proposal in self._proposals_list:
            
            #proposal.status = 2

            if not proposal:
                self._logger.info("Empty proposal. Stop")
                continue
        

            if (proposal.status!=2):
                self.all_proposals_done=False

            
            # loop over targets

                # for each target call observe() from Telescope
                
    

            #self._database_comp.setProposalStatus(proposal.pid, 2)
        
            self._logger.info("log status '%s' and an int (%d)" % ("Log Entry",proposal.status))
    
            
            #print(proposal.status . "\n")

            #self._logger.logInfo(proposal)
        


def stop(self):

    if (self.status==0):
        raise SYSTEMErrImpl.SchedulerAlreadyStoppedExImpl().getSchedulerAlreadStopp

    self.status=0
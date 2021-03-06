#include <cppSchedulingImpl.h>


cppSchedulingImpl::cppSchedulingImpl(
    const ACE_CString& name,
    maci::ContainerServices * containerServices): ACSComponentImpl(name, containerServices) {
}
 
cppSchedulingImpl::~cppSchedulingImpl() {
}

void cppSchedulingImpl::initialize() {
    // Assign variable values
    this->isRunning = false;
    this->proposalUnderExecutionID = -1;
    this->processObservations = true;
    //Initialize data TODO
}
 
void cppSchedulingImpl::execute() {
    // Called after initialize to tell the component that it has to be ready to accept incoming functional calls any time
    // Consider ready to receive calls (Change states if appropriate)
    // Instrument
    this->instrument = this->getContainerServices()->getComponent<INSTRUMENT_MODULE::Instrument>("INSTRUMENT");

    // Database
    this->database = this->getContainerServices()->getComponent<DATABASE_MODULE::DataBase>("DATABASE");

    // Telescope
    this->telescope = this->getContainerServices()->getComponent<TELESCOPE_MODULE::Telescope>("TELESCOPE");
}
 
void cppSchedulingImpl::cleanUp() {
    // Called after the last functional call to the component has finished
    // Release components: Database, Telescope, Instrument
    this->getContainerServices()->releaseComponent(this->instrument->name());

    this->getContainerServices()->releaseComponent(this->database->name());

    this->getContainerServices()->releaseComponent(this->telescope->name());

    
}
 
void cppSchedulingImpl::aboutToAbort() {
    //Do any critical clean up
    //Continue with less critical stuff such as releasing components and other activities similar to cleanUp
}

void cppSchedulingImpl::processProposals() {
    // For each proposal
    // std::cout << "processProposals starting..." << std::endl;
    ACS_SHORT_LOG((LM_INFO, "processProposals starting..."));
    while (this->processObservations) {
        TYPES::ProposalList_var proposals = this->database->getProposals();

        // Sleep if no work
        if (proposals->length() == 0) {
            ACS_SHORT_LOG((LM_TRACE, "Waiting for proposals..."));
            usleep(100000);
            continue; // continue hace que se pase a la siguiente iteracion
        }

        // Log proposal well received
        ACS_SHORT_LOG((LM_INFO, "Obtained %d proposals to process.", proposals->length()));
        TYPES::Proposal proposal = (*proposals)[0];

        // Set running, store proposal ID
        this->proposalUnderExecutionID = proposal.pid;
        // std::cout << "Setting proposal PID " << this->proposalUnderExecutionID << " as RUNNING." << std::endl;
        ACS_SHORT_LOG((LM_INFO, "Setting proposal PID %d as RUNNING.", this->proposalUnderExecutionID));
        // Set Database ProposalStatus -> running (1)
        this->database->setProposalStatus(this->proposalUnderExecutionID, 1);
        // std::cout << "Starting camera..." << std::endl;
        ACS_SHORT_LOG((LM_INFO, "Starting camera..."));
        // Start Camera
        this->instrument->cameraOn();

        // For each target in the current proposal
        TYPES::TargetList_var targets = proposal.targets;
        // std::cout << "Proposal PID " << this->proposalUnderExecutionID << " has " << targets->length() << " targets." << std::endl;
        ACS_SHORT_LOG((LM_INFO, "Proposal PID %d has %d targets.", this->proposalUnderExecutionID, targets->length()));
        for (unsigned int j = 0; j < targets->length(); j++) {
            TYPES::Target target = proposal.targets[j];
            ACS_SHORT_LOG((LM_INFO, "Observing target '%d', with position (az,el) = (%lf,%lf) and exp time %d", target.tid, target.coordinates.az, target.coordinates.el, target.expTime));
            // std::cout << "Observing target " << target.tid << ", with position (" << target.coordinates.az << "," << target.coordinates.el << ") and exp time " << target.expTime << std::endl;

            //virtual ::TYPES::ImageType * observe (
            //    const ::TYPES::Position & coordinates,
            //    ::CORBA::Long exposureTime);
            // raises(SYSTEMErr::PositionOutOfLimitsEx);
            TYPES::ImageType_var image_current;
            try {
                image_current = this->telescope->observe(target.coordinates, target.expTime);
            } catch (SYSTEMErr::PositionOutOfLimitsEx &_ex) {
                ACS_SHORT_LOG((LM_ERROR, "Exception PositionOutOfLimitsEx!"));
                continue;
            } catch (...) {
                ACS_SHORT_LOG((LM_ERROR, "Unknown Exception at Telescope.observe!"));
                continue;
            }
            
            // std::cout << "Archiving image..." << std::endl;
            ACS_SHORT_LOG((LM_INFO, "Archiving image..."));
            //virtual void storeImage (
            //    ::CORBA::Long pid,
            //    ::CORBA::Long tid,
            //    const ::TYPES::ImageType & image);
            try {
                this->database->storeImage(proposalUnderExecutionID, target.tid, image_current.in());
            } catch (SYSTEMErr::ImageAlreadyStoredEx &_ex) {
                ACS_SHORT_LOG((LM_ERROR, "Exception ImageAlreadyStoredEx!"));
                continue;
            }
            
        }

        // Turn Instruments cameraOff
        // std::cout << "Stopping camera..." << std::endl;
        ACS_SHORT_LOG((LM_INFO, "Stopping camera..."));
        instrument->cameraOff();
        
        // Set Database ProposalStatus -> ready (2)
        // std::cout << "Setting proposal PID " << this->proposalUnderExecutionID << " as READY." << std::endl;
        ACS_SHORT_LOG((LM_INFO, "Setting proposal PID %d as READY", this->proposalUnderExecutionID));
        this->database->setProposalStatus(this->proposalUnderExecutionID, 2);

        // Check if in stopping state, Stop
        if (!this->processObservations){
            // std::cout << "processProposals stopping..." << std::endl;
            ACS_SHORT_LOG((LM_INFO, "processProposals stopping..."));
            break;
        }
    }
    this->isRunning = false;
    this->proposalUnderExecutionID = -1;
    // std::cout << "processProposals stopped." << std::endl;
    ACS_SHORT_LOG((LM_INFO, "processProposals stopped."));
}

void cppSchedulingImpl::start() {
    // Say Hi
    // std::cout << "cppScheduling Starting..." << std::endl;
    ACS_SHORT_LOG((LM_INFO, "cppScheduling Starting..."));

    // Clause: Do not start twice
    if (this->isRunning) {
        ACS_SHORT_LOG((LM_ERROR, "SchedulerAlreadyRunningExImpl: Scheduler already running!"));
        throw SYSTEMErr::SchedulerAlreadyRunningExImpl(__FILE__, __LINE__, "Scheduler already running!").getSchedulerAlreadyRunningEx();
    }
    this->isRunning = true;
    this->processObservations = true;
    // std::cout << "Creating thread...." << std::endl;
    ACS_SHORT_LOG((LM_INFO, "Creating thread...."));
    // Construct the new thread and runs it. Do not block execution.
    this->thread_proposal = std::thread( [this] { processProposals(); } ); // handle para guardar el thread
}

void cppSchedulingImpl::stop(){
    // Say Hi
    // std::cout << "cppScheduling Stoping..." << std::endl;
    ACS_SHORT_LOG((LM_INFO, "cppScheduling Stoping..."));
    
    // Clause: do not stop if not running
    if(!this->isRunning) {
        ACS_SHORT_LOG((LM_ERROR, "SchedulerAlreadyStoppedExImpl: Scheduler already stopped! Stop stopping me ! xc"));
        throw SYSTEMErr::SchedulerAlreadyStoppedExImpl(__FILE__, __LINE__, "Scheduler already stopped!").getSchedulerAlreadyStoppedEx();
    }

    // Tell loop to stop (please)
    // std::cout << "Attempting to stop processProposals..." << std::endl;
    ACS_SHORT_LOG((LM_INFO, "Attempting to stop processProposals..."));
    this->processObservations = false;

    // Wait until ongoing observation finishes before returning
    // Makes the main thread wait for the new thread to finish execution, therefore blocks its own execution.
    ACS_SHORT_LOG((LM_INFO, "Waiting for processProposals to finish..."));

    this->thread_proposal.join(); // waits thread_proposal to finish
    // return ONLY when observations have finished
    ACS_SHORT_LOG((LM_INFO, "cppScheduler has been stopped."));
}

/**
* Returns the proposal id of the proposal currently under execution
* Raises SYSTEMErr::NoProposalExecutingEx if no proposal is executing.
*/
CORBA::Long cppSchedulingImpl::proposalUnderExecution(){
    // std::cout << "cppScheduling proposalUnderExecution" << std::endl;
    ACS_SHORT_LOG((LM_INFO, "cppScheduling proposalUnderExecution"));
    // long value = 1234;
    // return value;
    return this->proposalUnderExecutionID;
}
 
/* --------------- [ MACI DLL support functions ] -----------------*/
#include <maciACSComponentDefines.h>
MACI_DLL_SUPPORT_FUNCTIONS(cppSchedulingImpl)
/* ----------------------------------------------------------------*/
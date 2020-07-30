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

char* cppSchedulingImpl::printHello() {
    std::cout << "Just printing 'Hello World!'" << std::endl;
    return CORBA::string_dup("Hello World!");
}

void cppSchedulingImpl::processProposals() {
    // For each proposal
    TYPES::ProposalList_var proposals = this->database->getProposals();
    for (int i=0; i < proposals->length(); i++) {
        TYPES::Proposal proposal = (*proposals)[i];

        // Set running, store proposal ID
        long proposalStatus = proposal.status;
        this->proposalUnderExecutionID = proposal.pid;

        // Set Database ProposalStatus -> running (1)
        this->database->setProposalStatus(this->proposalUnderExecutionID, 1);

        // Start Camera
        this->instrument->cameraOn();

        // For each target in the current proposal
        TYPES::TargetList_var targets = proposal.targets;
        for (int j = 0; j < targets->length(); j++) {
            TYPES::Target target = proposal.targets[j];
            // TYPES::ImageType observe(in TYPES::Position coordinates, in long exposureTime)
            // raises(SYSTEMErr::PositionOutOfLimitsEx);
            TYPES::ImageType image_current = this->telescope->observe(target.coordinates, target.expTime);
            this->database->storeImage(proposalUnderExecutionID, target.tid, image_current);
        }

        // Trun Instruments cameraOff
        instrument->cameraOff();
        
        // Set Database ProposalStatus -> ready (2)
        this->database->setProposalStatus(this->proposalUnderExecutionID, 2);

        // Check if in stopping state, Stop
        if (!this->processObservations){
            this->isRunning = false;
            break;
        }
    }
}

void cppSchedulingImpl::start() {
    // Say Hi
    std::cout << "cppScheduling Starting" << std::endl;

    // Clause: Do not start twice
    if (this->isRunning) {
        throw SYSTEMErr::SchedulerAlreadyRunningExImpl(__FILE__, __LINE__, "Scheduler already running!").getSchedulerAlreadyRunningEx();
    }
    this->isRunning = true;
    this->processObservations = true;

    // Construct the new thread and runs it. Do not block execution.
    this->thread_proposal = std::thread( [this] { processProposals(); } );
}

void cppSchedulingImpl::stop(){
    // Say Hi
    std::cout << "cppScheduling Stoping" << std::endl;
    
    // Clause: do not stop if not running
    if(!this->isRunning) {
        throw SYSTEMErr::SchedulerAlreadyStoppedExImpl(__FILE__, __LINE__, "Scheduler already stopped!").getSchedulerAlreadyStoppedEx();
    }

    // Tell loop to stop (please)
    this->processObservations = false;

    // Wait until ongoing observation finishes before returning
    // Makes the main thread wait for the new thread to finish execution, therefore blocks its own execution.
    this->thread_proposal.join();

    // return ONLY when observations have finished
    return;
}

/**
* Returns the proposal id of the proposal currently under execution
* Raises SYSTEMErr::NoProposalExecutingEx if no proposal is executing.
*/
CORBA::Long cppSchedulingImpl::proposalUnderExecution(){
    std::cout << "cppScheduling proposalUnderExecution" << std::endl;
    // long value = 1234;
    // return value;
    return this->proposalUnderExecutionID;
}
 
/* --------------- [ MACI DLL support functions ] -----------------*/
#include <maciACSComponentDefines.h>
MACI_DLL_SUPPORT_FUNCTIONS(cppSchedulingImpl)
/* ----------------------------------------------------------------*/
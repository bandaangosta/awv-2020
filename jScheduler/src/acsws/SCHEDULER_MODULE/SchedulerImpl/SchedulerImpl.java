package acsws.SCHEDULER_MODULE.SchedulerImpl;

import java.util.logging.Logger;

import org.omg.CORBA.DoubleHolder;
import org.omg.CORBA.IntHolder;

import alma.acs.component.ComponentImplBase;
import alma.acs.container.ContainerServices;
import alma.acs.component.ComponentLifecycle;
import alma.ACS.ComponentStates;

import acsws.SCHEDULER_MODULE.SchedulerOperations;

import acsws.INSTRUMENT_MODULE.Instrument;
import acsws.INSTRUMENT_MODULE.InstrumentHelper;

public class SchedulerImpl implements ComponentLifecycle, SchedulerOperations {

	private Instrument camera = null;
	private ContainerServices m_containerServices;
	private Logger m_logger;

	@Override
	public void initialize(ContainerServices containerServices) {
		m_containerServices = containerServices;
		m_logger = m_containerServices.getLogger();
		m_logger.info("initialize() called...");
	}

	@Override
	public void execute() {
		m_logger.info("execute() called...");
	}

	@Override
	public void cleanUp() {
		m_containerServices.releaseComponent("Instrument");
		m_logger.info("cleanUp() called..., nothing to clean up.");
	}

	@Override
	public void aboutToAbort() {
		cleanUp();
		m_logger.info("managed to abort...");
	}

	@Override
	public ComponentStates componentState() {
		return m_containerServices.getComponentStateManager().getCurrentState();
	}

	@Override
	public String name() {
		return "ciao"; // TO DO: fix this
	}

	public SchedulerImpl() {
		super();
		try {
			camera = InstrumentHelper.narrow(this.m_containerServices.getComponent("Instrument"));
		} catch (Exception e) {
			m_logger.severe("Instrument component not found.");
		}

		System.out.println("SchedulerImpl constructor called");
	}

	public void start() {
		System.out.println("Start command called");
	}

	public void stop() {
		System.out.println("Stop command called");
    }

	public int proposalUnderExecution() {
		int propId = 498309;
		System.out.println("Proposal Id: " + propId);
		return propId;
	}
	
}
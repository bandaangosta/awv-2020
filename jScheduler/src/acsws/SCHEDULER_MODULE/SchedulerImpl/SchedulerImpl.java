package acsws.SCHEDULER_MODULE.SchedulerImpl;

import alma.acs.component.ComponentImplBase;
import acsws.SCHEDULER_MODULE.SchedulerOperations;

public class SchedulerImpl extends ComponentImplBase implements SchedulerOperations {
	public SchedulerImpl() {
		super();
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


/*******************************************************************************
* ALMA - Atacama Large Millimiter Array
* (c) European Southern Observatory, 2003 
*
*This library is free software; you can redistribute it and/or
*modify it under the terms of the GNU Lesser General Public
*License as published by the Free Software Foundation; either
*version 2.1 of the License, or (at your option) any later version.
*
*This library is distributed in the hope that it will be useful,
*but WITHOUT ANY WARRANTY; without even the implied warranty of
*MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
*Lesser General Public License for more details.
*
*You should have received a copy of the GNU Lesser General Public
*License along with this library; if not, write to the Free Software
*Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
*
* "@(#) $Id: AES2CPP.xslt,v 1.5 2012/01/27 10:59:54 bjeram Exp $"
*************  THIS FILE IS AUTOMATICALLY GENERATED !!!!!!
*/

#include "SYSTEMErr.h"

const char SYSTEMErr::AlreadyInAutomaticCompletion::m_shortDescription[]="Already in automatic mode";
bool SYSTEMErr::AlreadyInAutomaticCompletion::isEqual(ACSErr::Completion &completion) { return (completion.type == m_etype && completion.code == m_code ); }
        
const char SYSTEMErr::PositionOutOfLimitsCompletion::m_shortDescription[]="Position out of limits";
bool SYSTEMErr::PositionOutOfLimitsCompletion::isEqual(ACSErr::Completion &completion) { return (completion.type == m_etype && completion.code == m_code ); }
        
const char SYSTEMErr::ProposalNotYetReadyCompletion::m_shortDescription[]="Proposal is not ready";
bool SYSTEMErr::ProposalNotYetReadyCompletion::isEqual(ACSErr::Completion &completion) { return (completion.type == m_etype && completion.code == m_code ); }
        
const char SYSTEMErr::InvalidProposalStatusTransitionCompletion::m_shortDescription[]="Database: Invalid proposal status";
bool SYSTEMErr::InvalidProposalStatusTransitionCompletion::isEqual(ACSErr::Completion &completion) { return (completion.type == m_etype && completion.code == m_code ); }
        
const char SYSTEMErr::ImageAlreadyStoredCompletion::m_shortDescription[]="Image already stored";
bool SYSTEMErr::ImageAlreadyStoredCompletion::isEqual(ACSErr::Completion &completion) { return (completion.type == m_etype && completion.code == m_code ); }
        
const char SYSTEMErr::CameraIsOffCompletion::m_shortDescription[]="camera is off";
bool SYSTEMErr::CameraIsOffCompletion::isEqual(ACSErr::Completion &completion) { return (completion.type == m_etype && completion.code == m_code ); }
        
const char SYSTEMErr::SchedulerAlreadyRunningCompletion::m_shortDescription[]="Scheduler is already running";
bool SYSTEMErr::SchedulerAlreadyRunningCompletion::isEqual(ACSErr::Completion &completion) { return (completion.type == m_etype && completion.code == m_code ); }
        
const char SYSTEMErr::SchedulerAlreadyStoppedCompletion::m_shortDescription[]="Scheduler is already stopped";
bool SYSTEMErr::SchedulerAlreadyStoppedCompletion::isEqual(ACSErr::Completion &completion) { return (completion.type == m_etype && completion.code == m_code ); }
        
const char SYSTEMErr::NoProposalExecutingCompletion::m_shortDescription[]="No proposal is executing";
bool SYSTEMErr::NoProposalExecutingCompletion::isEqual(ACSErr::Completion &completion) { return (completion.type == m_etype && completion.code == m_code ); }
        
const char SYSTEMErr::SystemInAutoModeCompletion::m_shortDescription[]="System is in automatic mode";
bool SYSTEMErr::SystemInAutoModeCompletion::isEqual(ACSErr::Completion &completion) { return (completion.type == m_etype && completion.code == m_code ); }
        
const char SYSTEMErr::CannotOpenDeviceCompletion::m_shortDescription[]="Can't open device";
bool SYSTEMErr::CannotOpenDeviceCompletion::isEqual(ACSErr::Completion &completion) { return (completion.type == m_etype && completion.code == m_code ); }
        


const char SYSTEMErr::AlreadyInAutomaticExImpl::m_shortDescription[]="Already in automatic mode";
bool SYSTEMErr::AlreadyInAutomaticExImpl::isEqual(ACSErr::ACSbaseExImpl &ex) { return (ex.getErrorType() == m_etype && ex.getErrorCode() == m_code ); }
        
const char SYSTEMErr::PositionOutOfLimitsExImpl::m_shortDescription[]="Position out of limits";
bool SYSTEMErr::PositionOutOfLimitsExImpl::isEqual(ACSErr::ACSbaseExImpl &ex) { return (ex.getErrorType() == m_etype && ex.getErrorCode() == m_code ); }
        
const char SYSTEMErr::ProposalNotYetReadyExImpl::m_shortDescription[]="Proposal is not ready";
bool SYSTEMErr::ProposalNotYetReadyExImpl::isEqual(ACSErr::ACSbaseExImpl &ex) { return (ex.getErrorType() == m_etype && ex.getErrorCode() == m_code ); }
        
const char SYSTEMErr::InvalidProposalStatusTransitionExImpl::m_shortDescription[]="Database: Invalid proposal status";
bool SYSTEMErr::InvalidProposalStatusTransitionExImpl::isEqual(ACSErr::ACSbaseExImpl &ex) { return (ex.getErrorType() == m_etype && ex.getErrorCode() == m_code ); }
        
const char SYSTEMErr::ImageAlreadyStoredExImpl::m_shortDescription[]="Image already stored";
bool SYSTEMErr::ImageAlreadyStoredExImpl::isEqual(ACSErr::ACSbaseExImpl &ex) { return (ex.getErrorType() == m_etype && ex.getErrorCode() == m_code ); }
        
const char SYSTEMErr::CameraIsOffExImpl::m_shortDescription[]="camera is off";
bool SYSTEMErr::CameraIsOffExImpl::isEqual(ACSErr::ACSbaseExImpl &ex) { return (ex.getErrorType() == m_etype && ex.getErrorCode() == m_code ); }
        
const char SYSTEMErr::SchedulerAlreadyRunningExImpl::m_shortDescription[]="Scheduler is already running";
bool SYSTEMErr::SchedulerAlreadyRunningExImpl::isEqual(ACSErr::ACSbaseExImpl &ex) { return (ex.getErrorType() == m_etype && ex.getErrorCode() == m_code ); }
        
const char SYSTEMErr::SchedulerAlreadyStoppedExImpl::m_shortDescription[]="Scheduler is already stopped";
bool SYSTEMErr::SchedulerAlreadyStoppedExImpl::isEqual(ACSErr::ACSbaseExImpl &ex) { return (ex.getErrorType() == m_etype && ex.getErrorCode() == m_code ); }
        
const char SYSTEMErr::NoProposalExecutingExImpl::m_shortDescription[]="No proposal is executing";
bool SYSTEMErr::NoProposalExecutingExImpl::isEqual(ACSErr::ACSbaseExImpl &ex) { return (ex.getErrorType() == m_etype && ex.getErrorCode() == m_code ); }
        
const char SYSTEMErr::SystemInAutoModeExImpl::m_shortDescription[]="System is in automatic mode";
bool SYSTEMErr::SystemInAutoModeExImpl::isEqual(ACSErr::ACSbaseExImpl &ex) { return (ex.getErrorType() == m_etype && ex.getErrorCode() == m_code ); }
        
const char SYSTEMErr::CannotOpenDeviceExImpl::m_shortDescription[]="Can't open device";
bool SYSTEMErr::CannotOpenDeviceExImpl::isEqual(ACSErr::ACSbaseExImpl &ex) { return (ex.getErrorType() == m_etype && ex.getErrorCode() == m_code ); }
        
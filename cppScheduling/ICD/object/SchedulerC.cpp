// -*- C++ -*-
/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v2.4.3
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 *       http://www.cs.wustl.edu/~schmidt/doc-center.html
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       http://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     http://www.dre.vanderbilt.edu/~schmidt/TAO.html
 **/

// TAO_IDL - Generated from
// be/be_codegen.cpp:373


#include "SchedulerC.h"
#include "tao/AnyTypeCode/Null_RefCount_Policy.h"
#include "tao/AnyTypeCode/TypeCode_Constants.h"
#include "tao/AnyTypeCode/Alias_TypeCode_Static.h"
#include "tao/AnyTypeCode/Objref_TypeCode_Static.h"
#include "tao/CDR.h"
#include "tao/Exception_Data.h"
#include "tao/Invocation_Adapter.h"
#include "tao/Object_T.h"
#include "tao/CDR.h"
#include "tao/AnyTypeCode/Any.h"
#include "tao/AnyTypeCode/Any_Impl_T.h"
#include "ace/OS_NS_string.h"

#if !defined (__ACE_INLINE__)
#include "SchedulerC.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_cs.cpp:48
TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Traits specializations for SCHEDULER_MODULE::Scheduler.

SCHEDULER_MODULE::Scheduler_ptr
TAO::Objref_Traits<SCHEDULER_MODULE::Scheduler>::duplicate (
    SCHEDULER_MODULE::Scheduler_ptr p)
{
  return SCHEDULER_MODULE::Scheduler::_duplicate (p);
}

void
TAO::Objref_Traits<SCHEDULER_MODULE::Scheduler>::release (
    SCHEDULER_MODULE::Scheduler_ptr p)
{
  ::CORBA::release (p);
}

SCHEDULER_MODULE::Scheduler_ptr
TAO::Objref_Traits<SCHEDULER_MODULE::Scheduler>::nil (void)
{
  return SCHEDULER_MODULE::Scheduler::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<SCHEDULER_MODULE::Scheduler>::marshal (
    const SCHEDULER_MODULE::Scheduler_ptr p,
    TAO_OutputCDR & cdr)
{
  return ::CORBA::Object::marshal (p, cdr);
}

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_operation/operation_cs.cpp:88

void
SCHEDULER_MODULE::Scheduler::start (
  void)
{
  if (!this->is_evaluated ())
    {
      ::CORBA::Object::tao_object_initialize (this);
    }
  
  TAO::Arg_Traits< void>::ret_val _tao_retval;

  TAO::Argument *_the_tao_operation_signature [] =
    {
      &_tao_retval
    };

  static TAO::Exception_Data
  _tao_SCHEDULER_MODULE_Scheduler_start_exceptiondata [] = 
    {
      {
        "IDL:acsws/SYSTEMErr/SchedulerAlreadyRunningEx:1.0",
        SYSTEMErr::SchedulerAlreadyRunningEx::_alloc
#if TAO_HAS_INTERCEPTORS == 1
        , SYSTEMErr::_tc_SchedulerAlreadyRunningEx
#endif /* TAO_HAS_INTERCEPTORS */
      }
    };

  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      1,
      "start",
      5,
      TAO::TAO_CO_NONE | TAO::TAO_CO_THRU_POA_STRATEGY,
      TAO::TAO_TWOWAY_INVOCATION
      ,
      TAO::TAO_SYNCHRONOUS_INVOCATION,
      false
    );

  _tao_call.invoke (
      _tao_SCHEDULER_MODULE_Scheduler_start_exceptiondata,
      1
    );
}

// TAO_IDL - Generated from
// be/be_visitor_operation/operation_cs.cpp:88

void
SCHEDULER_MODULE::Scheduler::stop (
  void)
{
  if (!this->is_evaluated ())
    {
      ::CORBA::Object::tao_object_initialize (this);
    }
  
  TAO::Arg_Traits< void>::ret_val _tao_retval;

  TAO::Argument *_the_tao_operation_signature [] =
    {
      &_tao_retval
    };

  static TAO::Exception_Data
  _tao_SCHEDULER_MODULE_Scheduler_stop_exceptiondata [] = 
    {
      {
        "IDL:acsws/SYSTEMErr/SchedulerAlreadyStoppedEx:1.0",
        SYSTEMErr::SchedulerAlreadyStoppedEx::_alloc
#if TAO_HAS_INTERCEPTORS == 1
        , SYSTEMErr::_tc_SchedulerAlreadyStoppedEx
#endif /* TAO_HAS_INTERCEPTORS */
      }
    };

  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      1,
      "stop",
      4,
      TAO::TAO_CO_NONE | TAO::TAO_CO_THRU_POA_STRATEGY,
      TAO::TAO_TWOWAY_INVOCATION
      ,
      TAO::TAO_SYNCHRONOUS_INVOCATION,
      false
    );

  _tao_call.invoke (
      _tao_SCHEDULER_MODULE_Scheduler_stop_exceptiondata,
      1
    );
}

// TAO_IDL - Generated from
// be/be_visitor_operation/operation_cs.cpp:88

::CORBA::Long
SCHEDULER_MODULE::Scheduler::proposalUnderExecution (
  void)
{
  if (!this->is_evaluated ())
    {
      ::CORBA::Object::tao_object_initialize (this);
    }
  
  TAO::Arg_Traits< ::CORBA::Long>::ret_val _tao_retval;

  TAO::Argument *_the_tao_operation_signature [] =
    {
      &_tao_retval
    };

  static TAO::Exception_Data
  _tao_SCHEDULER_MODULE_Scheduler_proposalUnderExecution_exceptiondata [] = 
    {
      {
        "IDL:acsws/SYSTEMErr/NoProposalExecutingEx:1.0",
        SYSTEMErr::NoProposalExecutingEx::_alloc
#if TAO_HAS_INTERCEPTORS == 1
        , SYSTEMErr::_tc_NoProposalExecutingEx
#endif /* TAO_HAS_INTERCEPTORS */
      }
    };

  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      1,
      "proposalUnderExecution",
      22,
      TAO::TAO_CO_NONE | TAO::TAO_CO_THRU_POA_STRATEGY,
      TAO::TAO_TWOWAY_INVOCATION
      ,
      TAO::TAO_SYNCHRONOUS_INVOCATION,
      false
    );

  _tao_call.invoke (
      _tao_SCHEDULER_MODULE_Scheduler_proposalUnderExecution_exceptiondata,
      1
    );

  return _tao_retval.retn ();
}

SCHEDULER_MODULE::Scheduler::Scheduler (void)
{
}

SCHEDULER_MODULE::Scheduler::~Scheduler (void)
{
}

void
SCHEDULER_MODULE::Scheduler::_tao_any_destructor (void *_tao_void_pointer)
{
  Scheduler *_tao_tmp_pointer =
    static_cast<Scheduler *> (_tao_void_pointer);
  ::CORBA::release (_tao_tmp_pointer);
}

SCHEDULER_MODULE::Scheduler_ptr
SCHEDULER_MODULE::Scheduler::_narrow (
    ::CORBA::Object_ptr _tao_objref)
{
  return
    TAO::Narrow_Utils<Scheduler>::narrow (
        _tao_objref,
        "IDL:acsws/SCHEDULER_MODULE/Scheduler:1.0");
}

SCHEDULER_MODULE::Scheduler_ptr
SCHEDULER_MODULE::Scheduler::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref)
{
  return
    TAO::Narrow_Utils<Scheduler>::unchecked_narrow (
        _tao_objref);
}

SCHEDULER_MODULE::Scheduler_ptr
SCHEDULER_MODULE::Scheduler::_nil (void)
{
  return 0;
}

SCHEDULER_MODULE::Scheduler_ptr
SCHEDULER_MODULE::Scheduler::_duplicate (Scheduler_ptr obj)
{
  if (! ::CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  return obj;
}

void
SCHEDULER_MODULE::Scheduler::_tao_release (Scheduler_ptr obj)
{
  ::CORBA::release (obj);
}

::CORBA::Boolean
SCHEDULER_MODULE::Scheduler::_is_a (const char *value)
{
  if (
      ACE_OS::strcmp (
          value,
          "IDL:alma/ACS/ACSComponent:1.0"
        ) == 0 ||
      ACE_OS::strcmp (
          value,
          "IDL:acsws/SCHEDULER_MODULE/Scheduler:1.0"
        ) == 0 ||
      ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Object:1.0"
        ) == 0
    )
    {
      return true; // success using local knowledge
    }
  else
    {
      return this->::CORBA::Object::_is_a (value);
    }
}

const char* SCHEDULER_MODULE::Scheduler::_interface_repository_id (void) const
{
  return "IDL:acsws/SCHEDULER_MODULE/Scheduler:1.0";
}

::CORBA::Boolean
SCHEDULER_MODULE::Scheduler::marshal (TAO_OutputCDR &cdr)
{
  return (cdr << this);
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/objref_typecode.cpp:70

static TAO::TypeCode::Objref<char const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_SCHEDULER_MODULE_Scheduler (
    ::CORBA::tk_objref,
    "IDL:acsws/SCHEDULER_MODULE/Scheduler:1.0",
    "Scheduler");
  

namespace SCHEDULER_MODULE
{
  ::CORBA::TypeCode_ptr const _tc_Scheduler =
    &_tao_tc_SCHEDULER_MODULE_Scheduler;
}

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_cs.cpp:38
TAO_BEGIN_VERSIONED_NAMESPACE_DECL



namespace TAO
{
  template<>
  ::CORBA::Boolean
  Any_Impl_T<SCHEDULER_MODULE::Scheduler>::to_object (
      ::CORBA::Object_ptr &_tao_elem) const
  {
    _tao_elem = ::CORBA::Object::_duplicate (this->value_);
    return true;
  }
}
TAO_END_VERSIONED_NAMESPACE_DECL



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace SCHEDULER_MODULE
{
  

  /// Copying insertion.
  void
  operator<<= (
      ::CORBA::Any &_tao_any,
      Scheduler_ptr _tao_elem)
  {
    Scheduler_ptr _tao_objptr =
      Scheduler::_duplicate (_tao_elem);
    _tao_any <<= &_tao_objptr;
  }

  /// Non-copying insertion.
  void
  operator<<= (
      ::CORBA::Any &_tao_any,
      Scheduler_ptr *_tao_elem)
  {
    TAO::Any_Impl_T<Scheduler>::insert (
        _tao_any,
        Scheduler::_tao_any_destructor,
        _tc_Scheduler,
        *_tao_elem);
  }

  ::CORBA::Boolean
  operator>>= (
      const ::CORBA::Any &_tao_any,
      Scheduler_ptr &_tao_elem)
  {
    return
      TAO::Any_Impl_T<Scheduler>::extract (
          _tao_any,
          Scheduler::_tao_any_destructor,
          _tc_Scheduler,
          _tao_elem);
  }
}

#else

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



/// Copying insertion.
void
operator<<= (
    ::CORBA::Any &_tao_any,
    SCHEDULER_MODULE::Scheduler_ptr _tao_elem)
{
  SCHEDULER_MODULE::Scheduler_ptr _tao_objptr =
    SCHEDULER_MODULE::Scheduler::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

/// Non-copying insertion.
void
operator<<= (
    ::CORBA::Any &_tao_any,
    SCHEDULER_MODULE::Scheduler_ptr *_tao_elem)
{
  TAO::Any_Impl_T<SCHEDULER_MODULE::Scheduler>::insert (
      _tao_any,
      SCHEDULER_MODULE::Scheduler::_tao_any_destructor,
      SCHEDULER_MODULE::_tc_Scheduler,
      *_tao_elem);
}

::CORBA::Boolean
operator>>= (
    const ::CORBA::Any &_tao_any,
    SCHEDULER_MODULE::Scheduler_ptr &_tao_elem)
{
  return
    TAO::Any_Impl_T<SCHEDULER_MODULE::Scheduler>::extract (
        _tao_any,
        SCHEDULER_MODULE::Scheduler::_tao_any_destructor,
        SCHEDULER_MODULE::_tc_Scheduler,
        _tao_elem);
}

TAO_END_VERSIONED_NAMESPACE_DECL



#endif

// TAO_IDL - Generated from
// be/be_visitor_interface/cdr_op_cs.cpp:51

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const SCHEDULER_MODULE::Scheduler_ptr _tao_objref)
{
  ::CORBA::Object_ptr _tao_corba_obj = _tao_objref;
  return (strm << _tao_corba_obj);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    SCHEDULER_MODULE::Scheduler_ptr &_tao_objref)
{
  ::CORBA::Object_var obj;

  if (!(strm >> obj.inout ()))
    {
      return false;
    }
  
  typedef ::SCHEDULER_MODULE::Scheduler RHS_SCOPED_NAME;

  // Narrow to the right type.
  _tao_objref =
    TAO::Narrow_Utils<RHS_SCOPED_NAME>::unchecked_narrow (obj.in ());
    
  return true;
}

TAO_END_VERSIONED_NAMESPACE_DECL




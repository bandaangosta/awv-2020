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


#include "TelescopeC.h"
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
#include "TelescopeC.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_cs.cpp:48
TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Traits specializations for TELESCOPE_MODULE::Telescope.

TELESCOPE_MODULE::Telescope_ptr
TAO::Objref_Traits<TELESCOPE_MODULE::Telescope>::duplicate (
    TELESCOPE_MODULE::Telescope_ptr p)
{
  return TELESCOPE_MODULE::Telescope::_duplicate (p);
}

void
TAO::Objref_Traits<TELESCOPE_MODULE::Telescope>::release (
    TELESCOPE_MODULE::Telescope_ptr p)
{
  ::CORBA::release (p);
}

TELESCOPE_MODULE::Telescope_ptr
TAO::Objref_Traits<TELESCOPE_MODULE::Telescope>::nil (void)
{
  return TELESCOPE_MODULE::Telescope::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<TELESCOPE_MODULE::Telescope>::marshal (
    const TELESCOPE_MODULE::Telescope_ptr p,
    TAO_OutputCDR & cdr)
{
  return ::CORBA::Object::marshal (p, cdr);
}

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_operation/operation_cs.cpp:88

::TYPES::ImageType *
TELESCOPE_MODULE::Telescope::observe (
  const ::TYPES::Position & coordinates,
  ::CORBA::Long exposureTime)
{
  if (!this->is_evaluated ())
    {
      ::CORBA::Object::tao_object_initialize (this);
    }
  
  TAO::Arg_Traits< ::TYPES::ImageType>::ret_val _tao_retval;
  TAO::Arg_Traits< ::TYPES::Position>::in_arg_val _tao_coordinates (coordinates);
  TAO::Arg_Traits< ::CORBA::Long>::in_arg_val _tao_exposureTime (exposureTime);

  TAO::Argument *_the_tao_operation_signature [] =
    {
      &_tao_retval,
      &_tao_coordinates,
      &_tao_exposureTime
    };

  static TAO::Exception_Data
  _tao_TELESCOPE_MODULE_Telescope_observe_exceptiondata [] = 
    {
      {
        "IDL:acsws/SYSTEMErr/PositionOutOfLimitsEx:1.0",
        SYSTEMErr::PositionOutOfLimitsEx::_alloc
#if TAO_HAS_INTERCEPTORS == 1
        , SYSTEMErr::_tc_PositionOutOfLimitsEx
#endif /* TAO_HAS_INTERCEPTORS */
      }
    };

  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      3,
      "observe",
      7,
      TAO::TAO_CO_NONE | TAO::TAO_CO_THRU_POA_STRATEGY
      
    );

  _tao_call.invoke (
      _tao_TELESCOPE_MODULE_Telescope_observe_exceptiondata,
      1
    );

  return _tao_retval.retn ();
}

// TAO_IDL - Generated from
// be/be_visitor_operation/operation_cs.cpp:88

void
TELESCOPE_MODULE::Telescope::moveTo (
  const ::TYPES::Position & coordinates)
{
  if (!this->is_evaluated ())
    {
      ::CORBA::Object::tao_object_initialize (this);
    }
  
  TAO::Arg_Traits< void>::ret_val _tao_retval;
  TAO::Arg_Traits< ::TYPES::Position>::in_arg_val _tao_coordinates (coordinates);

  TAO::Argument *_the_tao_operation_signature [] =
    {
      &_tao_retval,
      &_tao_coordinates
    };

  static TAO::Exception_Data
  _tao_TELESCOPE_MODULE_Telescope_moveTo_exceptiondata [] = 
    {
      {
        "IDL:acsws/SYSTEMErr/PositionOutOfLimitsEx:1.0",
        SYSTEMErr::PositionOutOfLimitsEx::_alloc
#if TAO_HAS_INTERCEPTORS == 1
        , SYSTEMErr::_tc_PositionOutOfLimitsEx
#endif /* TAO_HAS_INTERCEPTORS */
      }
    };

  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      2,
      "moveTo",
      6,
      TAO::TAO_CO_NONE | TAO::TAO_CO_THRU_POA_STRATEGY
      
    );

  _tao_call.invoke (
      _tao_TELESCOPE_MODULE_Telescope_moveTo_exceptiondata,
      1
    );
}

// TAO_IDL - Generated from
// be/be_visitor_operation/operation_cs.cpp:88

::TYPES::Position
TELESCOPE_MODULE::Telescope::getCurrentPosition (
  void)
{
  if (!this->is_evaluated ())
    {
      ::CORBA::Object::tao_object_initialize (this);
    }
  
  TAO::Arg_Traits< ::TYPES::Position>::ret_val _tao_retval;

  TAO::Argument *_the_tao_operation_signature [] =
    {
      &_tao_retval
    };

  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      1,
      "getCurrentPosition",
      18,
      TAO::TAO_CO_NONE | TAO::TAO_CO_THRU_POA_STRATEGY,
      TAO::TAO_TWOWAY_INVOCATION
      ,
      TAO::TAO_SYNCHRONOUS_INVOCATION,
      false
    );

  _tao_call.invoke (0, 0);

  return _tao_retval.retn ();
}

TELESCOPE_MODULE::Telescope::Telescope (void)
{
}

TELESCOPE_MODULE::Telescope::~Telescope (void)
{
}

void
TELESCOPE_MODULE::Telescope::_tao_any_destructor (void *_tao_void_pointer)
{
  Telescope *_tao_tmp_pointer =
    static_cast<Telescope *> (_tao_void_pointer);
  ::CORBA::release (_tao_tmp_pointer);
}

TELESCOPE_MODULE::Telescope_ptr
TELESCOPE_MODULE::Telescope::_narrow (
    ::CORBA::Object_ptr _tao_objref)
{
  return
    TAO::Narrow_Utils<Telescope>::narrow (
        _tao_objref,
        "IDL:acsws/TELESCOPE_MODULE/Telescope:1.0");
}

TELESCOPE_MODULE::Telescope_ptr
TELESCOPE_MODULE::Telescope::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref)
{
  return
    TAO::Narrow_Utils<Telescope>::unchecked_narrow (
        _tao_objref);
}

TELESCOPE_MODULE::Telescope_ptr
TELESCOPE_MODULE::Telescope::_nil (void)
{
  return 0;
}

TELESCOPE_MODULE::Telescope_ptr
TELESCOPE_MODULE::Telescope::_duplicate (Telescope_ptr obj)
{
  if (! ::CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  return obj;
}

void
TELESCOPE_MODULE::Telescope::_tao_release (Telescope_ptr obj)
{
  ::CORBA::release (obj);
}

::CORBA::Boolean
TELESCOPE_MODULE::Telescope::_is_a (const char *value)
{
  if (
      ACE_OS::strcmp (
          value,
          "IDL:alma/ACS/ACSComponent:1.0"
        ) == 0 ||
      ACE_OS::strcmp (
          value,
          "IDL:acsws/TELESCOPE_MODULE/Telescope:1.0"
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

const char* TELESCOPE_MODULE::Telescope::_interface_repository_id (void) const
{
  return "IDL:acsws/TELESCOPE_MODULE/Telescope:1.0";
}

::CORBA::Boolean
TELESCOPE_MODULE::Telescope::marshal (TAO_OutputCDR &cdr)
{
  return (cdr << this);
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/objref_typecode.cpp:70

static TAO::TypeCode::Objref<char const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_TELESCOPE_MODULE_Telescope (
    ::CORBA::tk_objref,
    "IDL:acsws/TELESCOPE_MODULE/Telescope:1.0",
    "Telescope");
  

namespace TELESCOPE_MODULE
{
  ::CORBA::TypeCode_ptr const _tc_Telescope =
    &_tao_tc_TELESCOPE_MODULE_Telescope;
}

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_cs.cpp:38
TAO_BEGIN_VERSIONED_NAMESPACE_DECL



namespace TAO
{
  template<>
  ::CORBA::Boolean
  Any_Impl_T<TELESCOPE_MODULE::Telescope>::to_object (
      ::CORBA::Object_ptr &_tao_elem) const
  {
    _tao_elem = ::CORBA::Object::_duplicate (this->value_);
    return true;
  }
}
TAO_END_VERSIONED_NAMESPACE_DECL



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace TELESCOPE_MODULE
{
  

  /// Copying insertion.
  void
  operator<<= (
      ::CORBA::Any &_tao_any,
      Telescope_ptr _tao_elem)
  {
    Telescope_ptr _tao_objptr =
      Telescope::_duplicate (_tao_elem);
    _tao_any <<= &_tao_objptr;
  }

  /// Non-copying insertion.
  void
  operator<<= (
      ::CORBA::Any &_tao_any,
      Telescope_ptr *_tao_elem)
  {
    TAO::Any_Impl_T<Telescope>::insert (
        _tao_any,
        Telescope::_tao_any_destructor,
        _tc_Telescope,
        *_tao_elem);
  }

  ::CORBA::Boolean
  operator>>= (
      const ::CORBA::Any &_tao_any,
      Telescope_ptr &_tao_elem)
  {
    return
      TAO::Any_Impl_T<Telescope>::extract (
          _tao_any,
          Telescope::_tao_any_destructor,
          _tc_Telescope,
          _tao_elem);
  }
}

#else

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



/// Copying insertion.
void
operator<<= (
    ::CORBA::Any &_tao_any,
    TELESCOPE_MODULE::Telescope_ptr _tao_elem)
{
  TELESCOPE_MODULE::Telescope_ptr _tao_objptr =
    TELESCOPE_MODULE::Telescope::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

/// Non-copying insertion.
void
operator<<= (
    ::CORBA::Any &_tao_any,
    TELESCOPE_MODULE::Telescope_ptr *_tao_elem)
{
  TAO::Any_Impl_T<TELESCOPE_MODULE::Telescope>::insert (
      _tao_any,
      TELESCOPE_MODULE::Telescope::_tao_any_destructor,
      TELESCOPE_MODULE::_tc_Telescope,
      *_tao_elem);
}

::CORBA::Boolean
operator>>= (
    const ::CORBA::Any &_tao_any,
    TELESCOPE_MODULE::Telescope_ptr &_tao_elem)
{
  return
    TAO::Any_Impl_T<TELESCOPE_MODULE::Telescope>::extract (
        _tao_any,
        TELESCOPE_MODULE::Telescope::_tao_any_destructor,
        TELESCOPE_MODULE::_tc_Telescope,
        _tao_elem);
}

TAO_END_VERSIONED_NAMESPACE_DECL



#endif

// TAO_IDL - Generated from
// be/be_visitor_interface/cdr_op_cs.cpp:51

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const TELESCOPE_MODULE::Telescope_ptr _tao_objref)
{
  ::CORBA::Object_ptr _tao_corba_obj = _tao_objref;
  return (strm << _tao_corba_obj);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    TELESCOPE_MODULE::Telescope_ptr &_tao_objref)
{
  ::CORBA::Object_var obj;

  if (!(strm >> obj.inout ()))
    {
      return false;
    }
  
  typedef ::TELESCOPE_MODULE::Telescope RHS_SCOPED_NAME;

  // Narrow to the right type.
  _tao_objref =
    TAO::Narrow_Utils<RHS_SCOPED_NAME>::unchecked_narrow (obj.in ());
    
  return true;
}

TAO_END_VERSIONED_NAMESPACE_DECL




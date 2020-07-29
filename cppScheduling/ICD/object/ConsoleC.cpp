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


#include "ConsoleC.h"
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
#include "ConsoleC.inl"
#endif /* !defined INLINE */

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_cs.cpp:48
TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Traits specializations for CONSOLE_MODULE::Console.

CONSOLE_MODULE::Console_ptr
TAO::Objref_Traits<CONSOLE_MODULE::Console>::duplicate (
    CONSOLE_MODULE::Console_ptr p)
{
  return CONSOLE_MODULE::Console::_duplicate (p);
}

void
TAO::Objref_Traits<CONSOLE_MODULE::Console>::release (
    CONSOLE_MODULE::Console_ptr p)
{
  ::CORBA::release (p);
}

CONSOLE_MODULE::Console_ptr
TAO::Objref_Traits<CONSOLE_MODULE::Console>::nil (void)
{
  return CONSOLE_MODULE::Console::_nil ();
}

::CORBA::Boolean
TAO::Objref_Traits<CONSOLE_MODULE::Console>::marshal (
    const CONSOLE_MODULE::Console_ptr p,
    TAO_OutputCDR & cdr)
{
  return ::CORBA::Object::marshal (p, cdr);
}

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_operation/operation_cs.cpp:88

void
CONSOLE_MODULE::Console::setMode (
  ::CORBA::Boolean mode)
{
  if (!this->is_evaluated ())
    {
      ::CORBA::Object::tao_object_initialize (this);
    }
  
  TAO::Arg_Traits< void>::ret_val _tao_retval;
  TAO::Arg_Traits< ::ACE_InputCDR::to_boolean>::in_arg_val _tao_mode (mode);

  TAO::Argument *_the_tao_operation_signature [] =
    {
      &_tao_retval,
      &_tao_mode
    };

  static TAO::Exception_Data
  _tao_CONSOLE_MODULE_Console_setMode_exceptiondata [] = 
    {
      {
        "IDL:acsws/SYSTEMErr/AlreadyInAutomaticEx:1.0",
        SYSTEMErr::AlreadyInAutomaticEx::_alloc
#if TAO_HAS_INTERCEPTORS == 1
        , SYSTEMErr::_tc_AlreadyInAutomaticEx
#endif /* TAO_HAS_INTERCEPTORS */
      }
    };

  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      2,
      "setMode",
      7,
      TAO::TAO_CO_NONE | TAO::TAO_CO_THRU_POA_STRATEGY
      
    );

  _tao_call.invoke (
      _tao_CONSOLE_MODULE_Console_setMode_exceptiondata,
      1
    );
}

// TAO_IDL - Generated from
// be/be_visitor_operation/operation_cs.cpp:88

::CORBA::Boolean
CONSOLE_MODULE::Console::getMode (
  void)
{
  if (!this->is_evaluated ())
    {
      ::CORBA::Object::tao_object_initialize (this);
    }
  
  TAO::Arg_Traits< ::ACE_InputCDR::to_boolean>::ret_val _tao_retval;

  TAO::Argument *_the_tao_operation_signature [] =
    {
      &_tao_retval
    };

  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      1,
      "getMode",
      7,
      TAO::TAO_CO_NONE | TAO::TAO_CO_THRU_POA_STRATEGY,
      TAO::TAO_TWOWAY_INVOCATION
      ,
      TAO::TAO_SYNCHRONOUS_INVOCATION,
      false
    );

  _tao_call.invoke (0, 0);

  return _tao_retval.retn ();
}

// TAO_IDL - Generated from
// be/be_visitor_operation/operation_cs.cpp:88

void
CONSOLE_MODULE::Console::cameraOn (
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
  _tao_CONSOLE_MODULE_Console_cameraOn_exceptiondata [] = 
    {
      {
        "IDL:acsws/SYSTEMErr/SystemInAutoModeEx:1.0",
        SYSTEMErr::SystemInAutoModeEx::_alloc
#if TAO_HAS_INTERCEPTORS == 1
        , SYSTEMErr::_tc_SystemInAutoModeEx
#endif /* TAO_HAS_INTERCEPTORS */
      }
    };

  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      1,
      "cameraOn",
      8,
      TAO::TAO_CO_NONE | TAO::TAO_CO_THRU_POA_STRATEGY,
      TAO::TAO_TWOWAY_INVOCATION
      ,
      TAO::TAO_SYNCHRONOUS_INVOCATION,
      false
    );

  _tao_call.invoke (
      _tao_CONSOLE_MODULE_Console_cameraOn_exceptiondata,
      1
    );
}

// TAO_IDL - Generated from
// be/be_visitor_operation/operation_cs.cpp:88

void
CONSOLE_MODULE::Console::cameraOff (
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
  _tao_CONSOLE_MODULE_Console_cameraOff_exceptiondata [] = 
    {
      {
        "IDL:acsws/SYSTEMErr/SystemInAutoModeEx:1.0",
        SYSTEMErr::SystemInAutoModeEx::_alloc
#if TAO_HAS_INTERCEPTORS == 1
        , SYSTEMErr::_tc_SystemInAutoModeEx
#endif /* TAO_HAS_INTERCEPTORS */
      }
    };

  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      1,
      "cameraOff",
      9,
      TAO::TAO_CO_NONE | TAO::TAO_CO_THRU_POA_STRATEGY,
      TAO::TAO_TWOWAY_INVOCATION
      ,
      TAO::TAO_SYNCHRONOUS_INVOCATION,
      false
    );

  _tao_call.invoke (
      _tao_CONSOLE_MODULE_Console_cameraOff_exceptiondata,
      1
    );
}

// TAO_IDL - Generated from
// be/be_visitor_operation/operation_cs.cpp:88

void
CONSOLE_MODULE::Console::moveTelescope (
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
  _tao_CONSOLE_MODULE_Console_moveTelescope_exceptiondata [] = 
    {
      {
        "IDL:acsws/SYSTEMErr/PositionOutOfLimitsEx:1.0",
        SYSTEMErr::PositionOutOfLimitsEx::_alloc
#if TAO_HAS_INTERCEPTORS == 1
        , SYSTEMErr::_tc_PositionOutOfLimitsEx
#endif /* TAO_HAS_INTERCEPTORS */
      },

      {
        "IDL:acsws/SYSTEMErr/SystemInAutoModeEx:1.0",
        SYSTEMErr::SystemInAutoModeEx::_alloc
#if TAO_HAS_INTERCEPTORS == 1
        , SYSTEMErr::_tc_SystemInAutoModeEx
#endif /* TAO_HAS_INTERCEPTORS */
      }
    };

  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      2,
      "moveTelescope",
      13,
      TAO::TAO_CO_NONE | TAO::TAO_CO_THRU_POA_STRATEGY
      
    );

  _tao_call.invoke (
      _tao_CONSOLE_MODULE_Console_moveTelescope_exceptiondata,
      2
    );
}

// TAO_IDL - Generated from
// be/be_visitor_operation/operation_cs.cpp:88

::TYPES::Position
CONSOLE_MODULE::Console::getTelescopePosition (
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
      "getTelescopePosition",
      20,
      TAO::TAO_CO_NONE | TAO::TAO_CO_THRU_POA_STRATEGY,
      TAO::TAO_TWOWAY_INVOCATION
      ,
      TAO::TAO_SYNCHRONOUS_INVOCATION,
      false
    );

  _tao_call.invoke (0, 0);

  return _tao_retval.retn ();
}

// TAO_IDL - Generated from
// be/be_visitor_operation/operation_cs.cpp:88

::TYPES::ImageType *
CONSOLE_MODULE::Console::getCameraImage (
  void)
{
  if (!this->is_evaluated ())
    {
      ::CORBA::Object::tao_object_initialize (this);
    }
  
  TAO::Arg_Traits< ::TYPES::ImageType>::ret_val _tao_retval;

  TAO::Argument *_the_tao_operation_signature [] =
    {
      &_tao_retval
    };

  static TAO::Exception_Data
  _tao_CONSOLE_MODULE_Console_getCameraImage_exceptiondata [] = 
    {
      {
        "IDL:acsws/SYSTEMErr/SystemInAutoModeEx:1.0",
        SYSTEMErr::SystemInAutoModeEx::_alloc
#if TAO_HAS_INTERCEPTORS == 1
        , SYSTEMErr::_tc_SystemInAutoModeEx
#endif /* TAO_HAS_INTERCEPTORS */
      },

      {
        "IDL:acsws/SYSTEMErr/CameraIsOffEx:1.0",
        SYSTEMErr::CameraIsOffEx::_alloc
#if TAO_HAS_INTERCEPTORS == 1
        , SYSTEMErr::_tc_CameraIsOffEx
#endif /* TAO_HAS_INTERCEPTORS */
      }
    };

  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      1,
      "getCameraImage",
      14,
      TAO::TAO_CO_NONE | TAO::TAO_CO_THRU_POA_STRATEGY,
      TAO::TAO_TWOWAY_INVOCATION
      ,
      TAO::TAO_SYNCHRONOUS_INVOCATION,
      false
    );

  _tao_call.invoke (
      _tao_CONSOLE_MODULE_Console_getCameraImage_exceptiondata,
      2
    );

  return _tao_retval.retn ();
}

// TAO_IDL - Generated from
// be/be_visitor_operation/operation_cs.cpp:88

void
CONSOLE_MODULE::Console::setRGB (
  const ::TYPES::RGB & rgbConfig)
{
  if (!this->is_evaluated ())
    {
      ::CORBA::Object::tao_object_initialize (this);
    }
  
  TAO::Arg_Traits< void>::ret_val _tao_retval;
  TAO::Arg_Traits< ::TYPES::RGB>::in_arg_val _tao_rgbConfig (rgbConfig);

  TAO::Argument *_the_tao_operation_signature [] =
    {
      &_tao_retval,
      &_tao_rgbConfig
    };

  static TAO::Exception_Data
  _tao_CONSOLE_MODULE_Console_setRGB_exceptiondata [] = 
    {
      {
        "IDL:acsws/SYSTEMErr/CameraIsOffEx:1.0",
        SYSTEMErr::CameraIsOffEx::_alloc
#if TAO_HAS_INTERCEPTORS == 1
        , SYSTEMErr::_tc_CameraIsOffEx
#endif /* TAO_HAS_INTERCEPTORS */
      }
    };

  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      2,
      "setRGB",
      6,
      TAO::TAO_CO_NONE | TAO::TAO_CO_THRU_POA_STRATEGY
      
    );

  _tao_call.invoke (
      _tao_CONSOLE_MODULE_Console_setRGB_exceptiondata,
      1
    );
}

// TAO_IDL - Generated from
// be/be_visitor_operation/operation_cs.cpp:88

void
CONSOLE_MODULE::Console::setPixelBias (
  ::CORBA::Long bias)
{
  if (!this->is_evaluated ())
    {
      ::CORBA::Object::tao_object_initialize (this);
    }
  
  TAO::Arg_Traits< void>::ret_val _tao_retval;
  TAO::Arg_Traits< ::CORBA::Long>::in_arg_val _tao_bias (bias);

  TAO::Argument *_the_tao_operation_signature [] =
    {
      &_tao_retval,
      &_tao_bias
    };

  static TAO::Exception_Data
  _tao_CONSOLE_MODULE_Console_setPixelBias_exceptiondata [] = 
    {
      {
        "IDL:acsws/SYSTEMErr/CameraIsOffEx:1.0",
        SYSTEMErr::CameraIsOffEx::_alloc
#if TAO_HAS_INTERCEPTORS == 1
        , SYSTEMErr::_tc_CameraIsOffEx
#endif /* TAO_HAS_INTERCEPTORS */
      }
    };

  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      2,
      "setPixelBias",
      12,
      TAO::TAO_CO_NONE | TAO::TAO_CO_THRU_POA_STRATEGY
      
    );

  _tao_call.invoke (
      _tao_CONSOLE_MODULE_Console_setPixelBias_exceptiondata,
      1
    );
}

// TAO_IDL - Generated from
// be/be_visitor_operation/operation_cs.cpp:88

void
CONSOLE_MODULE::Console::setResetLevel (
  ::CORBA::Long resetLevel)
{
  if (!this->is_evaluated ())
    {
      ::CORBA::Object::tao_object_initialize (this);
    }
  
  TAO::Arg_Traits< void>::ret_val _tao_retval;
  TAO::Arg_Traits< ::CORBA::Long>::in_arg_val _tao_resetLevel (resetLevel);

  TAO::Argument *_the_tao_operation_signature [] =
    {
      &_tao_retval,
      &_tao_resetLevel
    };

  static TAO::Exception_Data
  _tao_CONSOLE_MODULE_Console_setResetLevel_exceptiondata [] = 
    {
      {
        "IDL:acsws/SYSTEMErr/CameraIsOffEx:1.0",
        SYSTEMErr::CameraIsOffEx::_alloc
#if TAO_HAS_INTERCEPTORS == 1
        , SYSTEMErr::_tc_CameraIsOffEx
#endif /* TAO_HAS_INTERCEPTORS */
      }
    };

  TAO::Invocation_Adapter _tao_call (
      this,
      _the_tao_operation_signature,
      2,
      "setResetLevel",
      13,
      TAO::TAO_CO_NONE | TAO::TAO_CO_THRU_POA_STRATEGY
      
    );

  _tao_call.invoke (
      _tao_CONSOLE_MODULE_Console_setResetLevel_exceptiondata,
      1
    );
}

CONSOLE_MODULE::Console::Console (void)
{
}

CONSOLE_MODULE::Console::~Console (void)
{
}

void
CONSOLE_MODULE::Console::_tao_any_destructor (void *_tao_void_pointer)
{
  Console *_tao_tmp_pointer =
    static_cast<Console *> (_tao_void_pointer);
  ::CORBA::release (_tao_tmp_pointer);
}

CONSOLE_MODULE::Console_ptr
CONSOLE_MODULE::Console::_narrow (
    ::CORBA::Object_ptr _tao_objref)
{
  return
    TAO::Narrow_Utils<Console>::narrow (
        _tao_objref,
        "IDL:acsws/CONSOLE_MODULE/Console:1.0");
}

CONSOLE_MODULE::Console_ptr
CONSOLE_MODULE::Console::_unchecked_narrow (
    ::CORBA::Object_ptr _tao_objref)
{
  return
    TAO::Narrow_Utils<Console>::unchecked_narrow (
        _tao_objref);
}

CONSOLE_MODULE::Console_ptr
CONSOLE_MODULE::Console::_nil (void)
{
  return 0;
}

CONSOLE_MODULE::Console_ptr
CONSOLE_MODULE::Console::_duplicate (Console_ptr obj)
{
  if (! ::CORBA::is_nil (obj))
    {
      obj->_add_ref ();
    }
  return obj;
}

void
CONSOLE_MODULE::Console::_tao_release (Console_ptr obj)
{
  ::CORBA::release (obj);
}

::CORBA::Boolean
CONSOLE_MODULE::Console::_is_a (const char *value)
{
  if (
      ACE_OS::strcmp (
          value,
          "IDL:alma/ACS/ACSComponent:1.0"
        ) == 0 ||
      ACE_OS::strcmp (
          value,
          "IDL:acsws/CONSOLE_MODULE/Console:1.0"
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

const char* CONSOLE_MODULE::Console::_interface_repository_id (void) const
{
  return "IDL:acsws/CONSOLE_MODULE/Console:1.0";
}

::CORBA::Boolean
CONSOLE_MODULE::Console::marshal (TAO_OutputCDR &cdr)
{
  return (cdr << this);
}

// TAO_IDL - Generated from
// be/be_visitor_typecode/objref_typecode.cpp:70

static TAO::TypeCode::Objref<char const *,
                             TAO::Null_RefCount_Policy>
  _tao_tc_CONSOLE_MODULE_Console (
    ::CORBA::tk_objref,
    "IDL:acsws/CONSOLE_MODULE/Console:1.0",
    "Console");
  

namespace CONSOLE_MODULE
{
  ::CORBA::TypeCode_ptr const _tc_Console =
    &_tao_tc_CONSOLE_MODULE_Console;
}

// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_cs.cpp:38
TAO_BEGIN_VERSIONED_NAMESPACE_DECL



namespace TAO
{
  template<>
  ::CORBA::Boolean
  Any_Impl_T<CONSOLE_MODULE::Console>::to_object (
      ::CORBA::Object_ptr &_tao_elem) const
  {
    _tao_elem = ::CORBA::Object::_duplicate (this->value_);
    return true;
  }
}
TAO_END_VERSIONED_NAMESPACE_DECL



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace CONSOLE_MODULE
{
  

  /// Copying insertion.
  void
  operator<<= (
      ::CORBA::Any &_tao_any,
      Console_ptr _tao_elem)
  {
    Console_ptr _tao_objptr =
      Console::_duplicate (_tao_elem);
    _tao_any <<= &_tao_objptr;
  }

  /// Non-copying insertion.
  void
  operator<<= (
      ::CORBA::Any &_tao_any,
      Console_ptr *_tao_elem)
  {
    TAO::Any_Impl_T<Console>::insert (
        _tao_any,
        Console::_tao_any_destructor,
        _tc_Console,
        *_tao_elem);
  }

  ::CORBA::Boolean
  operator>>= (
      const ::CORBA::Any &_tao_any,
      Console_ptr &_tao_elem)
  {
    return
      TAO::Any_Impl_T<Console>::extract (
          _tao_any,
          Console::_tao_any_destructor,
          _tc_Console,
          _tao_elem);
  }
}

#else

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



/// Copying insertion.
void
operator<<= (
    ::CORBA::Any &_tao_any,
    CONSOLE_MODULE::Console_ptr _tao_elem)
{
  CONSOLE_MODULE::Console_ptr _tao_objptr =
    CONSOLE_MODULE::Console::_duplicate (_tao_elem);
  _tao_any <<= &_tao_objptr;
}

/// Non-copying insertion.
void
operator<<= (
    ::CORBA::Any &_tao_any,
    CONSOLE_MODULE::Console_ptr *_tao_elem)
{
  TAO::Any_Impl_T<CONSOLE_MODULE::Console>::insert (
      _tao_any,
      CONSOLE_MODULE::Console::_tao_any_destructor,
      CONSOLE_MODULE::_tc_Console,
      *_tao_elem);
}

::CORBA::Boolean
operator>>= (
    const ::CORBA::Any &_tao_any,
    CONSOLE_MODULE::Console_ptr &_tao_elem)
{
  return
    TAO::Any_Impl_T<CONSOLE_MODULE::Console>::extract (
        _tao_any,
        CONSOLE_MODULE::Console::_tao_any_destructor,
        CONSOLE_MODULE::_tc_Console,
        _tao_elem);
}

TAO_END_VERSIONED_NAMESPACE_DECL



#endif

// TAO_IDL - Generated from
// be/be_visitor_interface/cdr_op_cs.cpp:51

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const CONSOLE_MODULE::Console_ptr _tao_objref)
{
  ::CORBA::Object_ptr _tao_corba_obj = _tao_objref;
  return (strm << _tao_corba_obj);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    CONSOLE_MODULE::Console_ptr &_tao_objref)
{
  ::CORBA::Object_var obj;

  if (!(strm >> obj.inout ()))
    {
      return false;
    }
  
  typedef ::CONSOLE_MODULE::Console RHS_SCOPED_NAME;

  // Narrow to the right type.
  _tao_objref =
    TAO::Narrow_Utils<RHS_SCOPED_NAME>::unchecked_narrow (obj.in ());
    
  return true;
}

TAO_END_VERSIONED_NAMESPACE_DECL




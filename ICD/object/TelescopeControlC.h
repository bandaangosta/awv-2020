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
// be/be_codegen.cpp:149

#ifndef _TAO_IDL__TMP__TELESCOPECONTROLC_H_
#define _TAO_IDL__TMP__TELESCOPECONTROLC_H_


#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include "tao/AnyTypeCode/AnyTypeCode_methods.h"
#include "tao/AnyTypeCode/Any.h"
#include "tao/ORB.h"
#include "tao/SystemException.h"
#include "tao/Basic_Types.h"
#include "tao/ORB_Constants.h"
#include "tao/Object.h"
#include "tao/AnyTypeCode/TypeCode.h"
#include "tao/AnyTypeCode/TypeCode_Constants.h"
#include "tao/String_Manager_T.h"
#include "tao/Objref_VarOut_T.h"
#include "tao/Arg_Traits_T.h"
#include "tao/Basic_Arguments.h"
#include "tao/Special_Basic_Arguments.h"
#include "tao/Any_Insert_Policy_T.h"
#include "tao/Fixed_Size_Argument_T.h"
#include "tao/Var_Size_Argument_T.h"
#include "tao/Object_Argument_T.h"
#include /**/ "tao/Version.h"
#include /**/ "tao/Versioned_Namespace.h"

#include "baciC.h"

#if TAO_MAJOR_VERSION != 2 || TAO_MINOR_VERSION != 4 || TAO_MICRO_VERSION != 3
#error This file should be regenerated with TAO_IDL
#endif

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO 

// TAO_IDL - Generated from
// be/be_visitor_root/root_ch.cpp:157
TAO_BEGIN_VERSIONED_NAMESPACE_DECL



namespace TAO
{
  template<typename T> class Narrow_Utils;
}
TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_module/module_ch.cpp:35

namespace TELESCOPE_MODULE
{

  // TAO_IDL - Generated from
  // be/be_interface.cpp:748

#if !defined (_TELESCOPE_MODULE_TELESCOPECONTROL__VAR_OUT_CH_)
#define _TELESCOPE_MODULE_TELESCOPECONTROL__VAR_OUT_CH_

  class TelescopeControl;
  typedef TelescopeControl *TelescopeControl_ptr;
  typedef TAO_Objref_Var_T<TelescopeControl> TelescopeControl_var;
  typedef TAO_Objref_Out_T<TelescopeControl> TelescopeControl_out;
  

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be/be_visitor_interface/interface_ch.cpp:40

  class  TelescopeControl
    : public virtual ::ACS::CharacteristicComponent
  
  {
  public:
    friend class TAO::Narrow_Utils<TelescopeControl>;

    // TAO_IDL - Generated from
    // be/be_type.cpp:304

    typedef TelescopeControl_ptr _ptr_type;
    typedef TelescopeControl_var _var_type;
    typedef TelescopeControl_out _out_type;

    static void _tao_any_destructor (void *);

    // The static operations.
    static TelescopeControl_ptr _duplicate (TelescopeControl_ptr obj);

    static void _tao_release (TelescopeControl_ptr obj);

    static TelescopeControl_ptr _narrow (::CORBA::Object_ptr obj);
    static TelescopeControl_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static TelescopeControl_ptr _nil (void);

    virtual void setTo (
      ::CORBA::Double altitude,
      ::CORBA::Double azimuth);

    virtual void objfix (
      ::CORBA::Double altitude,
      ::CORBA::Double azimuth);

    virtual void offSet (
      ::CORBA::Double altOffset,
      ::CORBA::Double azOffset);

    virtual void zenith (
      void);

    virtual void park (
      void);

    virtual void setUncalibrated (
      void);

    virtual void calibrateEncoders (
      void);

    virtual ::ACS::RWdouble_ptr commandedAltitude (
      void);

    virtual ::ACS::RWdouble_ptr commandedAzimuth (
      void);

    virtual ::ACS::ROdouble_ptr actualAltitude (
      void);

    virtual ::ACS::ROdouble_ptr actualAzimuth (
      void);

    virtual ::ACS::RWpattern_ptr status (
      void);

    // TAO_IDL - Generated from
    // be/be_visitor_interface/interface_ch.cpp:137

    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Concrete interface only.
    TelescopeControl (void);

    // Concrete non-local interface only.
    TelescopeControl (
        ::IOP::IOR *ior,
        TAO_ORB_Core *orb_core);
    
    // Non-local interface only.
    TelescopeControl (
        TAO_Stub *objref,
        ::CORBA::Boolean _tao_collocated = false,
        TAO_Abstract_ServantBase *servant = 0,
        TAO_ORB_Core *orb_core = 0);

    virtual ~TelescopeControl (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    TelescopeControl (const TelescopeControl &);

    void operator= (const TelescopeControl &);
  };

  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:34

  extern  ::CORBA::TypeCode_ptr const _tc_TelescopeControl;

// TAO_IDL - Generated from
// be/be_visitor_module/module_ch.cpp:64

} // module TELESCOPE_MODULE

// TAO_IDL - Generated from
// be/be_visitor_arg_traits.cpp:66

TAO_BEGIN_VERSIONED_NAMESPACE_DECL


// Arg traits specializations.
namespace TAO
{

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:145

#if !defined (_TELESCOPE_MODULE_TELESCOPECONTROL__ARG_TRAITS_)
#define _TELESCOPE_MODULE_TELESCOPECONTROL__ARG_TRAITS_

  template<>
  class  Arg_Traits< ::TELESCOPE_MODULE::TelescopeControl>
    : public
        Object_Arg_Traits_T<
            ::TELESCOPE_MODULE::TelescopeControl_ptr,
            ::TELESCOPE_MODULE::TelescopeControl_var,
            ::TELESCOPE_MODULE::TelescopeControl_out,
            TAO::Objref_Traits<TELESCOPE_MODULE::TelescopeControl>,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

#endif /* end #if !defined */
}

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_traits.cpp:60

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Traits specializations.
namespace TAO
{

#if !defined (_TELESCOPE_MODULE_TELESCOPECONTROL__TRAITS_)
#define _TELESCOPE_MODULE_TELESCOPECONTROL__TRAITS_

  template<>
  struct  Objref_Traits< ::TELESCOPE_MODULE::TelescopeControl>
  {
    static ::TELESCOPE_MODULE::TelescopeControl_ptr duplicate (
        ::TELESCOPE_MODULE::TelescopeControl_ptr p);
    static void release (
        ::TELESCOPE_MODULE::TelescopeControl_ptr p);
    static ::TELESCOPE_MODULE::TelescopeControl_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::TELESCOPE_MODULE::TelescopeControl_ptr p,
        TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */
}
TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_interface/any_op_ch.cpp:41



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace TELESCOPE_MODULE
{
   void operator<<= ( ::CORBA::Any &, TelescopeControl_ptr); // copying
   void operator<<= ( ::CORBA::Any &, TelescopeControl_ptr *); // non-copying
   ::CORBA::Boolean operator>>= (const ::CORBA::Any &, TelescopeControl_ptr &);
}

#else


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 void operator<<= (::CORBA::Any &, TELESCOPE_MODULE::TelescopeControl_ptr); // copying
 void operator<<= (::CORBA::Any &, TELESCOPE_MODULE::TelescopeControl_ptr *); // non-copying
 ::CORBA::Boolean operator>>= (const ::CORBA::Any &, TELESCOPE_MODULE::TelescopeControl_ptr &);
TAO_END_VERSIONED_NAMESPACE_DECL



#endif

// TAO_IDL - Generated from
// be/be_visitor_interface/cdr_op_ch.cpp:41

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 ::CORBA::Boolean operator<< (TAO_OutputCDR &, const TELESCOPE_MODULE::TelescopeControl_ptr );
 ::CORBA::Boolean operator>> (TAO_InputCDR &, TELESCOPE_MODULE::TelescopeControl_ptr &);

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_codegen.cpp:1700
#if defined (__ACE_INLINE__)
#include "TelescopeControlC.inl"
#endif /* defined INLINE */

#endif /* ifndef */


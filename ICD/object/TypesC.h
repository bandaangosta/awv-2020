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

#ifndef _TAO_IDL__TMP__TYPESC_H_
#define _TAO_IDL__TMP__TYPESC_H_


#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include "tao/AnyTypeCode/AnyTypeCode_methods.h"
#include "tao/AnyTypeCode/Any.h"
#include "tao/ORB.h"
#include "tao/Basic_Types.h"
#include "tao/Sequence_T.h"
#include "tao/Seq_Var_T.h"
#include "tao/Seq_Out_T.h"
#include "tao/VarOut_T.h"
#include "tao/Arg_Traits_T.h"
#include "tao/Basic_Arguments.h"
#include "tao/Special_Basic_Arguments.h"
#include "tao/Any_Insert_Policy_T.h"
#include "tao/Fixed_Size_Argument_T.h"
#include "tao/Var_Size_Argument_T.h"
#include /**/ "tao/Version.h"
#include /**/ "tao/Versioned_Namespace.h"

#if TAO_MAJOR_VERSION != 2 || TAO_MINOR_VERSION != 4 || TAO_MICRO_VERSION != 3
#error This file should be regenerated with TAO_IDL
#endif

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO 

// TAO_IDL - Generated from
// be/be_visitor_module/module_ch.cpp:35

namespace TYPES
{

  // TAO_IDL - Generated from
  // be/be_visitor_sequence/sequence_ch.cpp:99

#if !defined (_TYPES_IMAGETYPE_CH_)
#define _TYPES_IMAGETYPE_CH_

  class ImageType;
  typedef ::TAO_FixedSeq_Var_T<ImageType> ImageType_var;
  typedef ::TAO_Seq_Out_T<ImageType> ImageType_out;
  

  class  ImageType
    : public
        ::TAO::unbounded_value_sequence< ::CORBA::Octet>
  {
  public:
    ImageType (void);
    ImageType ( ::CORBA::ULong max);
    ImageType (
      ::CORBA::ULong max,
      ::CORBA::ULong length,
      ::CORBA::Octet* buffer,
      ::CORBA::Boolean release = false);
    ImageType (const ImageType &);
    virtual ~ImageType (void);
    

    // TAO_IDL - Generated from
    // be/be_type.cpp:304

    
    typedef ImageType_var _var_type;
    typedef ImageType_out _out_type;

    static void _tao_any_destructor (void *);

    
#if (TAO_NO_COPY_OCTET_SEQUENCES == 1)
    ImageType (::CORBA::ULong length, const ACE_Message_Block* mb)
      : ::TAO::unbounded_value_sequence< ::CORBA::Octet> (length, mb) {}
    
#endif /* TAO_NO_COPY_OCTET_SEQUENCE == 1 */
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:34

  extern  ::CORBA::TypeCode_ptr const _tc_ImageType;

  // TAO_IDL - Generated from
  // be/be_visitor_sequence/sequence_ch.cpp:99

#if !defined (_TYPES_IMAGELIST_CH_)
#define _TYPES_IMAGELIST_CH_

  class ImageList;
  typedef ::TAO_VarSeq_Var_T<ImageList> ImageList_var;
  typedef ::TAO_Seq_Out_T<ImageList> ImageList_out;
  

  class  ImageList
    : public
        ::TAO::unbounded_value_sequence< ImageType>
  {
  public:
    ImageList (void);
    ImageList ( ::CORBA::ULong max);
    ImageList (
      ::CORBA::ULong max,
      ::CORBA::ULong length,
      ImageType* buffer,
      ::CORBA::Boolean release = false);
    ImageList (const ImageList &);
    virtual ~ImageList (void);
    

    // TAO_IDL - Generated from
    // be/be_type.cpp:304

    
    typedef ImageList_var _var_type;
    typedef ImageList_out _out_type;

    static void _tao_any_destructor (void *);
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:34

  extern  ::CORBA::TypeCode_ptr const _tc_ImageList;

  // TAO_IDL - Generated from
  // be/be_type.cpp:258

  struct Position;

  typedef
    ::TAO_Fixed_Var_T<
        Position
      >
    Position_var;

  typedef
    Position &
    Position_out;

  // TAO_IDL - Generated from
  // be/be_visitor_structure/structure_ch.cpp:48

  struct  Position
  {

    // TAO_IDL - Generated from
    // be/be_type.cpp:304

    
    typedef Position_var _var_type;
    typedef Position_out _out_type;

    static void _tao_any_destructor (void *);
    
    ::CORBA::Double az;
    ::CORBA::Double el;
  };

  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:34

  extern  ::CORBA::TypeCode_ptr const _tc_Position;

  // TAO_IDL - Generated from
  // be/be_type.cpp:258

  struct Target;

  typedef
    ::TAO_Fixed_Var_T<
        Target
      >
    Target_var;

  typedef
    Target &
    Target_out;

  // TAO_IDL - Generated from
  // be/be_visitor_structure/structure_ch.cpp:48

  struct  Target
  {

    // TAO_IDL - Generated from
    // be/be_type.cpp:304

    
    typedef Target_var _var_type;
    typedef Target_out _out_type;

    static void _tao_any_destructor (void *);
    
    ::CORBA::Long tid;
    TYPES::Position coordinates;
    ::CORBA::Long expTime;
  };

  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:34

  extern  ::CORBA::TypeCode_ptr const _tc_Target;

  // TAO_IDL - Generated from
  // be/be_visitor_sequence/sequence_ch.cpp:99

#if !defined (_TYPES_TARGETLIST_CH_)
#define _TYPES_TARGETLIST_CH_

  class TargetList;
  typedef ::TAO_FixedSeq_Var_T<TargetList> TargetList_var;
  typedef ::TAO_Seq_Out_T<TargetList> TargetList_out;
  

  class  TargetList
    : public
        ::TAO::unbounded_value_sequence< Target>
  {
  public:
    TargetList (void);
    TargetList ( ::CORBA::ULong max);
    TargetList (
      ::CORBA::ULong max,
      ::CORBA::ULong length,
      Target* buffer,
      ::CORBA::Boolean release = false);
    TargetList (const TargetList &);
    virtual ~TargetList (void);
    

    // TAO_IDL - Generated from
    // be/be_type.cpp:304

    
    typedef TargetList_var _var_type;
    typedef TargetList_out _out_type;

    static void _tao_any_destructor (void *);
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:34

  extern  ::CORBA::TypeCode_ptr const _tc_TargetList;

  // TAO_IDL - Generated from
  // be/be_type.cpp:258

  struct Proposal;

  typedef
    ::TAO_Var_Var_T<
        Proposal
      >
    Proposal_var;

  typedef
    ::TAO_Out_T<
        Proposal
      >
    Proposal_out;

  // TAO_IDL - Generated from
  // be/be_visitor_structure/structure_ch.cpp:48

  struct  Proposal
  {

    // TAO_IDL - Generated from
    // be/be_type.cpp:304

    
    typedef Proposal_var _var_type;
    typedef Proposal_out _out_type;

    static void _tao_any_destructor (void *);
    
    ::CORBA::Long pid;
    TYPES::TargetList targets;
    ::CORBA::Long status;
  };

  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:34

  extern  ::CORBA::TypeCode_ptr const _tc_Proposal;

  // TAO_IDL - Generated from
  // be/be_visitor_sequence/sequence_ch.cpp:99

#if !defined (_TYPES_PROPOSALLIST_CH_)
#define _TYPES_PROPOSALLIST_CH_

  class ProposalList;
  typedef ::TAO_VarSeq_Var_T<ProposalList> ProposalList_var;
  typedef ::TAO_Seq_Out_T<ProposalList> ProposalList_out;
  

  class  ProposalList
    : public
        ::TAO::unbounded_value_sequence< Proposal>
  {
  public:
    ProposalList (void);
    ProposalList ( ::CORBA::ULong max);
    ProposalList (
      ::CORBA::ULong max,
      ::CORBA::ULong length,
      Proposal* buffer,
      ::CORBA::Boolean release = false);
    ProposalList (const ProposalList &);
    virtual ~ProposalList (void);
    

    // TAO_IDL - Generated from
    // be/be_type.cpp:304

    
    typedef ProposalList_var _var_type;
    typedef ProposalList_out _out_type;

    static void _tao_any_destructor (void *);
  };

#endif /* end #if !defined */

  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:34

  extern  ::CORBA::TypeCode_ptr const _tc_ProposalList;

  // TAO_IDL - Generated from
  // be/be_type.cpp:258

  struct RGB;

  typedef
    ::TAO_Fixed_Var_T<
        RGB
      >
    RGB_var;

  typedef
    RGB &
    RGB_out;

  // TAO_IDL - Generated from
  // be/be_visitor_structure/structure_ch.cpp:48

  struct  RGB
  {

    // TAO_IDL - Generated from
    // be/be_type.cpp:304

    
    typedef RGB_var _var_type;
    typedef RGB_out _out_type;

    static void _tao_any_destructor (void *);
    
    ::CORBA::Long red;
    ::CORBA::Long green;
    ::CORBA::Long blue;
  };

  // TAO_IDL - Generated from
  // be/be_visitor_typecode/typecode_decl.cpp:34

  extern  ::CORBA::TypeCode_ptr const _tc_RGB;

// TAO_IDL - Generated from
// be/be_visitor_module/module_ch.cpp:64

} // module TYPES

// TAO_IDL - Generated from
// be/be_visitor_arg_traits.cpp:66

TAO_BEGIN_VERSIONED_NAMESPACE_DECL


// Arg traits specializations.
namespace TAO
{

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:683

  template<>
  class Arg_Traits< ::TYPES::ImageType>
    : public
        Var_Size_Arg_Traits_T<
            ::TYPES::ImageType,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:683

  template<>
  class Arg_Traits< ::TYPES::ImageList>
    : public
        Var_Size_Arg_Traits_T<
            ::TYPES::ImageList,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:945

  template<>
  class Arg_Traits< ::TYPES::Position>
    : public
        Fixed_Size_Arg_Traits_T<
            ::TYPES::Position,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:945

  template<>
  class Arg_Traits< ::TYPES::Target>
    : public
        Fixed_Size_Arg_Traits_T<
            ::TYPES::Target,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:683

  template<>
  class Arg_Traits< ::TYPES::TargetList>
    : public
        Var_Size_Arg_Traits_T<
            ::TYPES::TargetList,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:945

  template<>
  class Arg_Traits< ::TYPES::Proposal>
    : public
        Var_Size_Arg_Traits_T<
            ::TYPES::Proposal,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:683

  template<>
  class Arg_Traits< ::TYPES::ProposalList>
    : public
        Var_Size_Arg_Traits_T<
            ::TYPES::ProposalList,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:945

  template<>
  class Arg_Traits< ::TYPES::RGB>
    : public
        Fixed_Size_Arg_Traits_T<
            ::TYPES::RGB,
            TAO::Any_Insert_Policy_Stream
          >
  {
  };
}

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_traits.cpp:60

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Traits specializations.
namespace TAO
{
}
TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_sequence/any_op_ch.cpp:47



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace TYPES
{
   void operator<<= ( ::CORBA::Any &, const ::TYPES::ImageType &); // copying version
   void operator<<= ( ::CORBA::Any &, ::TYPES::ImageType*); // noncopying version
   ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const ::TYPES::ImageType *&);
}

#else


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 void operator<<= ( ::CORBA::Any &, const TYPES::ImageType &); // copying version
 void operator<<= ( ::CORBA::Any &, TYPES::ImageType*); // noncopying version
 ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const TYPES::ImageType *&);
TAO_END_VERSIONED_NAMESPACE_DECL



#endif

// TAO_IDL - Generated from
// be/be_visitor_sequence/any_op_ch.cpp:47



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace TYPES
{
   void operator<<= ( ::CORBA::Any &, const ::TYPES::ImageList &); // copying version
   void operator<<= ( ::CORBA::Any &, ::TYPES::ImageList*); // noncopying version
   ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const ::TYPES::ImageList *&);
}

#else


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 void operator<<= ( ::CORBA::Any &, const TYPES::ImageList &); // copying version
 void operator<<= ( ::CORBA::Any &, TYPES::ImageList*); // noncopying version
 ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const TYPES::ImageList *&);
TAO_END_VERSIONED_NAMESPACE_DECL



#endif

// TAO_IDL - Generated from
// be/be_visitor_structure/any_op_ch.cpp:42



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace TYPES
{
   void operator<<= (::CORBA::Any &, const ::TYPES::Position &); // copying version
   void operator<<= (::CORBA::Any &, ::TYPES::Position*); // noncopying version
   ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const ::TYPES::Position *&);
}

#else


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 void operator<<= (::CORBA::Any &, const TYPES::Position &); // copying version
 void operator<<= (::CORBA::Any &, TYPES::Position*); // noncopying version
 ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const TYPES::Position *&);
TAO_END_VERSIONED_NAMESPACE_DECL



#endif

// TAO_IDL - Generated from
// be/be_visitor_structure/any_op_ch.cpp:42



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace TYPES
{
   void operator<<= (::CORBA::Any &, const ::TYPES::Target &); // copying version
   void operator<<= (::CORBA::Any &, ::TYPES::Target*); // noncopying version
   ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const ::TYPES::Target *&);
}

#else


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 void operator<<= (::CORBA::Any &, const TYPES::Target &); // copying version
 void operator<<= (::CORBA::Any &, TYPES::Target*); // noncopying version
 ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const TYPES::Target *&);
TAO_END_VERSIONED_NAMESPACE_DECL



#endif

// TAO_IDL - Generated from
// be/be_visitor_sequence/any_op_ch.cpp:47



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace TYPES
{
   void operator<<= ( ::CORBA::Any &, const ::TYPES::TargetList &); // copying version
   void operator<<= ( ::CORBA::Any &, ::TYPES::TargetList*); // noncopying version
   ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const ::TYPES::TargetList *&);
}

#else


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 void operator<<= ( ::CORBA::Any &, const TYPES::TargetList &); // copying version
 void operator<<= ( ::CORBA::Any &, TYPES::TargetList*); // noncopying version
 ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const TYPES::TargetList *&);
TAO_END_VERSIONED_NAMESPACE_DECL



#endif

// TAO_IDL - Generated from
// be/be_visitor_structure/any_op_ch.cpp:42



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace TYPES
{
   void operator<<= (::CORBA::Any &, const ::TYPES::Proposal &); // copying version
   void operator<<= (::CORBA::Any &, ::TYPES::Proposal*); // noncopying version
   ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const ::TYPES::Proposal *&);
}

#else


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 void operator<<= (::CORBA::Any &, const TYPES::Proposal &); // copying version
 void operator<<= (::CORBA::Any &, TYPES::Proposal*); // noncopying version
 ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const TYPES::Proposal *&);
TAO_END_VERSIONED_NAMESPACE_DECL



#endif

// TAO_IDL - Generated from
// be/be_visitor_sequence/any_op_ch.cpp:47



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace TYPES
{
   void operator<<= ( ::CORBA::Any &, const ::TYPES::ProposalList &); // copying version
   void operator<<= ( ::CORBA::Any &, ::TYPES::ProposalList*); // noncopying version
   ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const ::TYPES::ProposalList *&);
}

#else


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 void operator<<= ( ::CORBA::Any &, const TYPES::ProposalList &); // copying version
 void operator<<= ( ::CORBA::Any &, TYPES::ProposalList*); // noncopying version
 ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const TYPES::ProposalList *&);
TAO_END_VERSIONED_NAMESPACE_DECL



#endif

// TAO_IDL - Generated from
// be/be_visitor_structure/any_op_ch.cpp:42



#if defined (ACE_ANY_OPS_USE_NAMESPACE)

namespace TYPES
{
   void operator<<= (::CORBA::Any &, const ::TYPES::RGB &); // copying version
   void operator<<= (::CORBA::Any &, ::TYPES::RGB*); // noncopying version
   ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const ::TYPES::RGB *&);
}

#else


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 void operator<<= (::CORBA::Any &, const TYPES::RGB &); // copying version
 void operator<<= (::CORBA::Any &, TYPES::RGB*); // noncopying version
 ::CORBA::Boolean operator>>= (const ::CORBA::Any &, const TYPES::RGB *&);
TAO_END_VERSIONED_NAMESPACE_DECL



#endif

// TAO_IDL - Generated from
// be/be_visitor_sequence/cdr_op_ch.cpp:65

#if !defined _TAO_CDR_OP_TYPES_ImageType_H_
#define _TAO_CDR_OP_TYPES_ImageType_H_
TAO_BEGIN_VERSIONED_NAMESPACE_DECL


 ::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const TYPES::ImageType &_tao_sequence);
 ::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    TYPES::ImageType &_tao_sequence);

TAO_END_VERSIONED_NAMESPACE_DECL



#endif /* _TAO_CDR_OP_TYPES_ImageType_H_ */

// TAO_IDL - Generated from
// be/be_visitor_sequence/cdr_op_ch.cpp:65

#if !defined _TAO_CDR_OP_TYPES_ImageList_H_
#define _TAO_CDR_OP_TYPES_ImageList_H_
TAO_BEGIN_VERSIONED_NAMESPACE_DECL


 ::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const TYPES::ImageList &_tao_sequence);
 ::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    TYPES::ImageList &_tao_sequence);

TAO_END_VERSIONED_NAMESPACE_DECL



#endif /* _TAO_CDR_OP_TYPES_ImageList_H_ */

// TAO_IDL - Generated from
// be/be_visitor_structure/cdr_op_ch.cpp:43


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 ::CORBA::Boolean operator<< (TAO_OutputCDR &, const TYPES::Position &);
 ::CORBA::Boolean operator>> (TAO_InputCDR &, TYPES::Position &);

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_structure/cdr_op_ch.cpp:43


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 ::CORBA::Boolean operator<< (TAO_OutputCDR &, const TYPES::Target &);
 ::CORBA::Boolean operator>> (TAO_InputCDR &, TYPES::Target &);

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_sequence/cdr_op_ch.cpp:65

#if !defined _TAO_CDR_OP_TYPES_TargetList_H_
#define _TAO_CDR_OP_TYPES_TargetList_H_
TAO_BEGIN_VERSIONED_NAMESPACE_DECL


 ::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const TYPES::TargetList &_tao_sequence);
 ::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    TYPES::TargetList &_tao_sequence);

TAO_END_VERSIONED_NAMESPACE_DECL



#endif /* _TAO_CDR_OP_TYPES_TargetList_H_ */

// TAO_IDL - Generated from
// be/be_visitor_structure/cdr_op_ch.cpp:43


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 ::CORBA::Boolean operator<< (TAO_OutputCDR &, const TYPES::Proposal &);
 ::CORBA::Boolean operator>> (TAO_InputCDR &, TYPES::Proposal &);

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_sequence/cdr_op_ch.cpp:65

#if !defined _TAO_CDR_OP_TYPES_ProposalList_H_
#define _TAO_CDR_OP_TYPES_ProposalList_H_
TAO_BEGIN_VERSIONED_NAMESPACE_DECL


 ::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const TYPES::ProposalList &_tao_sequence);
 ::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    TYPES::ProposalList &_tao_sequence);

TAO_END_VERSIONED_NAMESPACE_DECL



#endif /* _TAO_CDR_OP_TYPES_ProposalList_H_ */

// TAO_IDL - Generated from
// be/be_visitor_structure/cdr_op_ch.cpp:43


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 ::CORBA::Boolean operator<< (TAO_OutputCDR &, const TYPES::RGB &);
 ::CORBA::Boolean operator>> (TAO_InputCDR &, TYPES::RGB &);

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_codegen.cpp:1700
#if defined (__ACE_INLINE__)
#include "TypesC.inl"
#endif /* defined INLINE */

#endif /* ifndef */


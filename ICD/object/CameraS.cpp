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
// be/be_codegen.cpp:649

#ifndef _TAO_IDL__TMP__CAMERAS_CPP_
#define _TAO_IDL__TMP__CAMERAS_CPP_


#include "CameraS.h"
#include "tao/PortableServer/Operation_Table_Perfect_Hash.h"
#include "tao/PortableServer/Upcall_Command.h"
#include "tao/PortableServer/Upcall_Wrapper.h"
#include "tao/TAO_Server_Request.h"
#include "tao/ORB_Core.h"
#include "tao/Profile.h"
#include "tao/Stub.h"
#include "tao/IFR_Client_Adapter.h"
#include "tao/Object_T.h"
#include "tao/AnyTypeCode/TypeCode.h"
#include "tao/AnyTypeCode/DynamicC.h"
#include "tao/CDR.h"
#include "tao/operation_details.h"
#include "tao/PortableInterceptor.h"
#include "ace/Dynamic_Service.h"
#include "ace/Malloc_Allocator.h"

// TAO_IDL - Generated from
// be/be_interface.cpp:1863

class TAO_CAMERA_MODULE_Camera_Perfect_Hash_OpTable
  : public TAO_Perfect_Hash_OpTable
{
private:
  unsigned int hash (const char *str, unsigned int len);

public:
  const TAO_operation_db_entry * lookup (const char *str, unsigned int len);
};

/* C++ code produced by gperf version 2.8 (ACE version) */
/* Command-line: /alma/ACS-2020JUN/TAO/ACE_wrappers/build/linux/bin/ace_gperf -m -M -J -c -C -D -E -T -f 0 -F 0,0 -a -o -t -p -K opname -L C++ -Z TAO_CAMERA_MODULE_Camera_Perfect_Hash_OpTable -N lookup  */
unsigned int
TAO_CAMERA_MODULE_Camera_Perfect_Hash_OpTable::hash (const char *str, unsigned int len)
{
  static const unsigned char asso_values[] =
    {
     27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
     27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
     27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
     27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
     27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
     27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
     27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
     27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
     27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
     27, 27, 27, 27, 27,  0, 27,  0, 27,  5,
      0,  0,  0,  0, 27, 27, 27, 27, 27, 27,
      0,  0, 27, 27, 10,  0,  5, 27, 27, 27,
     27, 27, 27, 27, 27, 27, 27, 27,
    };
  return len + asso_values[static_cast<int>(str[len - 1])] + asso_values[static_cast<int>(str[0])];
}

const TAO_operation_db_entry *
TAO_CAMERA_MODULE_Camera_Perfect_Hash_OpTable::lookup (const char *str, unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 16,
      MIN_WORD_LENGTH = 2,
      MAX_WORD_LENGTH = 26,
      MIN_HASH_VALUE = 2,
      MAX_HASH_VALUE = 26,
      HASH_VALUE_RANGE = 25,
      DUPLICATES = 0,
      WORDLIST_SIZE = 18
    };

  static const TAO_operation_db_entry wordlist[] =
    {
      {"",0,0},{"",0,0},
      {"on", &POA_CAMERA_MODULE::Camera::on_skel, 0},
      {"off", &POA_CAMERA_MODULE::Camera::off_skel, 0},
      {"",0,0},
      {"_is_a", &TAO_ServantBase::_is_a_thru_poa_skel, 0},
      {"",0,0},{"",0,0},
      {"getFrame", &POA_CAMERA_MODULE::Camera::getFrame_skel, 0},
      {"_get_name", &POA_ACS::ACSComponent::_get_name_skel, 0},
      {"_interface", &TAO_ServantBase::_interface_skel, 0},
      {"",0,0},{"",0,0},
      {"_get_isoSpeed", &POA_CAMERA_MODULE::Camera::_get_isoSpeed_skel, 0},
      {"_repository_id", &TAO_ServantBase::_repository_id_thru_poa_skel, 0},
      {"_component", &TAO_ServantBase::_component_thru_poa_skel, 0},
      {"",0,0},
      {"_get_shutterSpeed", &POA_CAMERA_MODULE::Camera::_get_shutterSpeed_skel, 0},
      {"_non_existent", &TAO_ServantBase::_non_existent_thru_poa_skel, 0},
      {"_get_componentState", &POA_ACS::ACSComponent::_get_componentState_skel, 0},
      {"descriptor", &POA_ACS::CharacteristicComponent::descriptor_skel, 0},
      {"",0,0},{"",0,0},
      {"get_all_characteristics", &POA_ACS::CharacteristicModel::get_all_characteristics_skel, 0},
      {"find_characteristic", &POA_ACS::CharacteristicModel::find_characteristic_skel, 0},
      {"",0,0},
      {"get_characteristic_by_name", &POA_ACS::CharacteristicModel::get_characteristic_by_name_skel, 0},
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      unsigned int key = hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= MIN_HASH_VALUE)
        {
          const char *s = wordlist[key].opname;

          if (*str == *s && !ACE_OS::strncmp (str + 1, s + 1, len - 1))
            return &wordlist[key];
        }
    }
  return 0;
}

static TAO_CAMERA_MODULE_Camera_Perfect_Hash_OpTable tao_CAMERA_MODULE_Camera_optable;

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_ss.cpp:90

POA_CAMERA_MODULE::Camera::Camera (void)
  : TAO_ServantBase ()
{
  this->optable_ = &tao_CAMERA_MODULE_Camera_optable;
}

POA_CAMERA_MODULE::Camera::Camera (const Camera& rhs)
  : TAO_Abstract_ServantBase (rhs),
    TAO_ServantBase (rhs),
    POA_ACS::ACSComponent (rhs),
    POA_ACS::CharacteristicModel (rhs),
    POA_ACS::CharacteristicComponent (rhs)
{
}

POA_CAMERA_MODULE::Camera::~Camera (void)
{
}

namespace POA_CAMERA_MODULE
{
  

  // TAO_IDL - Generated from
  // be/be_visitor_operation/upcall_command_ss.cpp:80

  class getFrame_Camera
    : public TAO::Upcall_Command
  {
  public:
    inline getFrame_Camera (
      POA_CAMERA_MODULE::Camera * servant,
      TAO_Operation_Details const * operation_details,
      TAO::Argument * const args[])
      : servant_ (servant)
        , operation_details_ (operation_details)
        , args_ (args)
    {
    }

    virtual void execute (void)
    {
      TAO::SArg_Traits< ::TYPES::ImageType>::ret_arg_type retval =
        TAO::Portable_Server::get_ret_arg< ::TYPES::ImageType> (
          this->operation_details_,
          this->args_);
      
      TAO::SArg_Traits< char *>::in_arg_type arg_1 =
        TAO::Portable_Server::get_in_arg< char *> (
          this->operation_details_,
          this->args_,
          1);
        
      TAO::SArg_Traits< char *>::in_arg_type arg_2 =
        TAO::Portable_Server::get_in_arg< char *> (
          this->operation_details_,
          this->args_,
          2);
        
      retval =
        this->servant_->getFrame (
          arg_1
          , arg_2);
    }
  
  private:
    POA_CAMERA_MODULE::Camera * const servant_;
    TAO_Operation_Details const * const operation_details_;
    TAO::Argument * const * const args_;
  };
}

// TAO_IDL - Generated from
// be/be_visitor_operation/operation_ss.cpp:168

void POA_CAMERA_MODULE::Camera::getFrame_skel (
  TAO_ServerRequest & server_request,
  TAO::Portable_Server::Servant_Upcall *TAO_INTERCEPTOR (servant_upcall),
  TAO_ServantBase *servant)
{
#if TAO_HAS_INTERCEPTORS == 1
  static ::CORBA::TypeCode_ptr const * const exceptions = 0;
  static ::CORBA::ULong const nexceptions = 0;
#endif /* TAO_HAS_INTERCEPTORS */

  TAO::SArg_Traits< ::TYPES::ImageType>::ret_val retval;
  TAO::SArg_Traits< char *>::in_arg_val _tao_exposureTime;
  TAO::SArg_Traits< char *>::in_arg_val _tao_iso;

  TAO::Argument * const args[] =
    {
      &retval,
      &_tao_exposureTime,
      &_tao_iso
    };
  
  static size_t const nargs = 3;

  POA_CAMERA_MODULE::Camera * const impl =
    dynamic_cast<POA_CAMERA_MODULE::Camera *> (servant);

  if (!impl)
    {
      throw ::CORBA::INTERNAL ();
    }

  getFrame_Camera command (
    impl,
    server_request.operation_details (),
    args);
  
  TAO::Upcall_Wrapper upcall_wrapper;
  upcall_wrapper.upcall (server_request
                         , args
                         , nargs
                         , command
#if TAO_HAS_INTERCEPTORS == 1
                         , servant_upcall
                         , exceptions
                         , nexceptions
#endif  /* TAO_HAS_INTERCEPTORS == 1 */
                         );
}


namespace POA_CAMERA_MODULE
{
  

  // TAO_IDL - Generated from
  // be/be_visitor_operation/upcall_command_ss.cpp:80

  class on_Camera
    : public TAO::Upcall_Command
  {
  public:
    inline on_Camera (
      POA_CAMERA_MODULE::Camera * servant)
      : servant_ (servant)
    {
    }

    virtual void execute (void)
    {
      this->servant_->on ();
    }
  
  private:
    POA_CAMERA_MODULE::Camera * const servant_;
  };
}

// TAO_IDL - Generated from
// be/be_visitor_operation/operation_ss.cpp:168

void POA_CAMERA_MODULE::Camera::on_skel (
  TAO_ServerRequest & server_request,
  TAO::Portable_Server::Servant_Upcall *TAO_INTERCEPTOR (servant_upcall),
  TAO_ServantBase *servant)
{
#if TAO_HAS_INTERCEPTORS == 1
  static ::CORBA::TypeCode_ptr const * const exceptions = 0;
  static ::CORBA::ULong const nexceptions = 0;
#endif /* TAO_HAS_INTERCEPTORS */

  TAO::SArg_Traits< void>::ret_val retval;

  TAO::Argument * const args[] =
    {
      &retval
    };
  
  static size_t const nargs = 1;

  POA_CAMERA_MODULE::Camera * const impl =
    dynamic_cast<POA_CAMERA_MODULE::Camera *> (servant);

  if (!impl)
    {
      throw ::CORBA::INTERNAL ();
    }

  on_Camera command (
    impl);
  
  TAO::Upcall_Wrapper upcall_wrapper;
  upcall_wrapper.upcall (server_request
                         , args
                         , nargs
                         , command
#if TAO_HAS_INTERCEPTORS == 1
                         , servant_upcall
                         , exceptions
                         , nexceptions
#endif  /* TAO_HAS_INTERCEPTORS == 1 */
                         );
}


namespace POA_CAMERA_MODULE
{
  

  // TAO_IDL - Generated from
  // be/be_visitor_operation/upcall_command_ss.cpp:80

  class off_Camera
    : public TAO::Upcall_Command
  {
  public:
    inline off_Camera (
      POA_CAMERA_MODULE::Camera * servant)
      : servant_ (servant)
    {
    }

    virtual void execute (void)
    {
      this->servant_->off ();
    }
  
  private:
    POA_CAMERA_MODULE::Camera * const servant_;
  };
}

// TAO_IDL - Generated from
// be/be_visitor_operation/operation_ss.cpp:168

void POA_CAMERA_MODULE::Camera::off_skel (
  TAO_ServerRequest & server_request,
  TAO::Portable_Server::Servant_Upcall *TAO_INTERCEPTOR (servant_upcall),
  TAO_ServantBase *servant)
{
#if TAO_HAS_INTERCEPTORS == 1
  static ::CORBA::TypeCode_ptr const * const exceptions = 0;
  static ::CORBA::ULong const nexceptions = 0;
#endif /* TAO_HAS_INTERCEPTORS */

  TAO::SArg_Traits< void>::ret_val retval;

  TAO::Argument * const args[] =
    {
      &retval
    };
  
  static size_t const nargs = 1;

  POA_CAMERA_MODULE::Camera * const impl =
    dynamic_cast<POA_CAMERA_MODULE::Camera *> (servant);

  if (!impl)
    {
      throw ::CORBA::INTERNAL ();
    }

  off_Camera command (
    impl);
  
  TAO::Upcall_Wrapper upcall_wrapper;
  upcall_wrapper.upcall (server_request
                         , args
                         , nargs
                         , command
#if TAO_HAS_INTERCEPTORS == 1
                         , servant_upcall
                         , exceptions
                         , nexceptions
#endif  /* TAO_HAS_INTERCEPTORS == 1 */
                         );
}


namespace POA_CAMERA_MODULE
{
  

  // TAO_IDL - Generated from
  // be/be_visitor_operation/upcall_command_ss.cpp:80

  class _get_isoSpeed_Camera
    : public TAO::Upcall_Command
  {
  public:
    inline _get_isoSpeed_Camera (
      POA_CAMERA_MODULE::Camera * servant,
      TAO_Operation_Details const * operation_details,
      TAO::Argument * const args[])
      : servant_ (servant)
        , operation_details_ (operation_details)
        , args_ (args)
    {
    }

    virtual void execute (void)
    {
      TAO::SArg_Traits< ::ACS::RWstring>::ret_arg_type retval =
        TAO::Portable_Server::get_ret_arg< ::ACS::RWstring> (
          this->operation_details_,
          this->args_);
      
      retval =
        this->servant_->isoSpeed ();
    }
  
  private:
    POA_CAMERA_MODULE::Camera * const servant_;
    TAO_Operation_Details const * const operation_details_;
    TAO::Argument * const * const args_;
  };
}

// TAO_IDL - Generated from
// be/be_visitor_operation/operation_ss.cpp:168

void POA_CAMERA_MODULE::Camera::_get_isoSpeed_skel (
  TAO_ServerRequest & server_request,
  TAO::Portable_Server::Servant_Upcall *TAO_INTERCEPTOR (servant_upcall),
  TAO_ServantBase *servant)
{
#if TAO_HAS_INTERCEPTORS == 1
  static ::CORBA::TypeCode_ptr const * const exceptions = 0;
  static ::CORBA::ULong const nexceptions = 0;
#endif /* TAO_HAS_INTERCEPTORS */

  TAO::SArg_Traits< ::ACS::RWstring>::ret_val retval;

  TAO::Argument * const args[] =
    {
      &retval
    };
  
  static size_t const nargs = 1;

  POA_CAMERA_MODULE::Camera * const impl =
    dynamic_cast<POA_CAMERA_MODULE::Camera *> (servant);

  if (!impl)
    {
      throw ::CORBA::INTERNAL ();
    }

  _get_isoSpeed_Camera command (
    impl,
    server_request.operation_details (),
    args);
  
  TAO::Upcall_Wrapper upcall_wrapper;
  upcall_wrapper.upcall (server_request
                         , args
                         , nargs
                         , command
#if TAO_HAS_INTERCEPTORS == 1
                         , servant_upcall
                         , exceptions
                         , nexceptions
#endif  /* TAO_HAS_INTERCEPTORS == 1 */
                         );
}


namespace POA_CAMERA_MODULE
{
  

  // TAO_IDL - Generated from
  // be/be_visitor_operation/upcall_command_ss.cpp:80

  class _get_shutterSpeed_Camera
    : public TAO::Upcall_Command
  {
  public:
    inline _get_shutterSpeed_Camera (
      POA_CAMERA_MODULE::Camera * servant,
      TAO_Operation_Details const * operation_details,
      TAO::Argument * const args[])
      : servant_ (servant)
        , operation_details_ (operation_details)
        , args_ (args)
    {
    }

    virtual void execute (void)
    {
      TAO::SArg_Traits< ::ACS::RWstring>::ret_arg_type retval =
        TAO::Portable_Server::get_ret_arg< ::ACS::RWstring> (
          this->operation_details_,
          this->args_);
      
      retval =
        this->servant_->shutterSpeed ();
    }
  
  private:
    POA_CAMERA_MODULE::Camera * const servant_;
    TAO_Operation_Details const * const operation_details_;
    TAO::Argument * const * const args_;
  };
}

// TAO_IDL - Generated from
// be/be_visitor_operation/operation_ss.cpp:168

void POA_CAMERA_MODULE::Camera::_get_shutterSpeed_skel (
  TAO_ServerRequest & server_request,
  TAO::Portable_Server::Servant_Upcall *TAO_INTERCEPTOR (servant_upcall),
  TAO_ServantBase *servant)
{
#if TAO_HAS_INTERCEPTORS == 1
  static ::CORBA::TypeCode_ptr const * const exceptions = 0;
  static ::CORBA::ULong const nexceptions = 0;
#endif /* TAO_HAS_INTERCEPTORS */

  TAO::SArg_Traits< ::ACS::RWstring>::ret_val retval;

  TAO::Argument * const args[] =
    {
      &retval
    };
  
  static size_t const nargs = 1;

  POA_CAMERA_MODULE::Camera * const impl =
    dynamic_cast<POA_CAMERA_MODULE::Camera *> (servant);

  if (!impl)
    {
      throw ::CORBA::INTERNAL ();
    }

  _get_shutterSpeed_Camera command (
    impl,
    server_request.operation_details (),
    args);
  
  TAO::Upcall_Wrapper upcall_wrapper;
  upcall_wrapper.upcall (server_request
                         , args
                         , nargs
                         , command
#if TAO_HAS_INTERCEPTORS == 1
                         , servant_upcall
                         , exceptions
                         , nexceptions
#endif  /* TAO_HAS_INTERCEPTORS == 1 */
                         );
}



// TAO_IDL - Generated from
// be/be_visitor_interface/interface_ss.cpp:163



::CORBA::Boolean POA_CAMERA_MODULE::Camera::_is_a (const char* value)
{
  return
    (
      ACE_OS::strcmp (
          value,
          "IDL:alma/ACS/ACSComponent:1.0"
        ) == 0 ||
      ACE_OS::strcmp (
          value,
          "IDL:alma/ACS/CharacteristicModel:1.0"
        ) == 0 ||
      ACE_OS::strcmp (
          value,
          "IDL:alma/ACS/CharacteristicComponent:1.0"
        ) == 0 ||
      ACE_OS::strcmp (
          value,
          "IDL:acsws/CAMERA_MODULE/Camera:1.0"
        ) == 0 ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
    );
}

const char* POA_CAMERA_MODULE::Camera::_interface_repository_id (void) const
{
  return "IDL:acsws/CAMERA_MODULE/Camera:1.0";
}

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_ss.cpp:423

void POA_CAMERA_MODULE::Camera::_dispatch (
  TAO_ServerRequest & req,
  TAO::Portable_Server::Servant_Upcall* servant_upcall)
{
  this->synchronous_upcall_dispatch (req, servant_upcall, this);
}

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_ss.cpp:370

CAMERA_MODULE::Camera *
POA_CAMERA_MODULE::Camera::_this (void)
{
  TAO_Stub *stub = this->_create_stub ();

  TAO_Stub_Auto_Ptr safe_stub (stub);
  ::CORBA::Object_ptr tmp = CORBA::Object_ptr ();

  ::CORBA::Boolean const _tao_opt_colloc =
    stub->servant_orb_var ()->orb_core ()->optimize_collocation_objects ();
  
  ACE_NEW_RETURN (
      tmp,
      ::CORBA::Object (stub, _tao_opt_colloc, this),
      0);
  
  ::CORBA::Object_var obj = tmp;
  (void) safe_stub.release ();

  typedef ::CAMERA_MODULE::Camera STUB_SCOPED_NAME;
  return
    TAO::Narrow_Utils<STUB_SCOPED_NAME>::unchecked_narrow (
        obj.in ());
}

#endif /* ifndef */

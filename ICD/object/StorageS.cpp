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

#ifndef _TAO_IDL__TMP__STORAGES_CPP_
#define _TAO_IDL__TMP__STORAGES_CPP_


#include "StorageS.h"
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

class TAO_STORAGE_MODULE_Storage_Perfect_Hash_OpTable
  : public TAO_Perfect_Hash_OpTable
{
private:
  unsigned int hash (const char *str, unsigned int len);

public:
  const TAO_operation_db_entry * lookup (const char *str, unsigned int len);
};

/* C++ code produced by gperf version 2.8 (ACE version) */
/* Command-line: /alma/ACS-2020JUN/TAO/ACE_wrappers/build/linux/bin/ace_gperf -m -M -J -c -C -D -E -T -f 0 -F 0,0 -a -o -t -p -K opname -L C++ -Z TAO_STORAGE_MODULE_Storage_Perfect_Hash_OpTable -N lookup  */
unsigned int
TAO_STORAGE_MODULE_Storage_Perfect_Hash_OpTable::hash (const char *str, unsigned int len)
{
  static const unsigned char asso_values[] =
    {
     40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
     40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
     40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
     40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
     40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
     40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
     40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
     40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
     40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
     40, 40, 40, 40, 40,  0, 40,  0, 40,  0,
     15,  0, 40, 10, 40, 40, 40, 40, 40, 40,
      0, 40, 40, 40, 40,  0,  5, 40, 40, 40,
     40, 40, 40, 40, 40, 40, 40, 40,
    };
  return len + asso_values[static_cast<int>(str[len - 1])] + asso_values[static_cast<int>(str[0])];
}

const TAO_operation_db_entry *
TAO_STORAGE_MODULE_Storage_Perfect_Hash_OpTable::lookup (const char *str, unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 11,
      MIN_WORD_LENGTH = 5,
      MAX_WORD_LENGTH = 19,
      MIN_HASH_VALUE = 5,
      MAX_HASH_VALUE = 39,
      HASH_VALUE_RANGE = 35,
      DUPLICATES = 0,
      WORDLIST_SIZE = 16
    };

  static const TAO_operation_db_entry wordlist[] =
    {
      {"",0,0},{"",0,0},{"",0,0},{"",0,0},{"",0,0},
      {"_is_a", &TAO_ServantBase::_is_a_thru_poa_skel, 0},
      {"",0,0},{"",0,0},{"",0,0},
      {"_get_name", &POA_ACS::ACSComponent::_get_name_skel, 0},
      {"_interface", &TAO_ServantBase::_interface_skel, 0},
      {"",0,0},
      {"clearAllData", &POA_STORAGE_MODULE::Storage::clearAllData_skel, 0},
      {"",0,0},{"",0,0},
      {"_component", &TAO_ServantBase::_component_thru_poa_skel, 0},
      {"storeObservation", &POA_STORAGE_MODULE::Storage::storeObservation_skel, 0},
      {"",0,0},
      {"_non_existent", &TAO_ServantBase::_non_existent_thru_poa_skel, 0},
      {"_get_componentState", &POA_ACS::ACSComponent::_get_componentState_skel, 0},
      {"",0,0},{"",0,0},{"",0,0},{"",0,0},
      {"getObservation", &POA_STORAGE_MODULE::Storage::getObservation_skel, 0},
      {"",0,0},{"",0,0},{"",0,0},{"",0,0},
      {"_repository_id", &TAO_ServantBase::_repository_id_thru_poa_skel, 0},
      {"",0,0},{"",0,0},{"",0,0},{"",0,0},{"",0,0},{"",0,0},{"",0,0},{"",0,0},{"",0,0},
      {"getNextValidId", &POA_STORAGE_MODULE::Storage::getNextValidId_skel, 0},
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

static TAO_STORAGE_MODULE_Storage_Perfect_Hash_OpTable tao_STORAGE_MODULE_Storage_optable;

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_ss.cpp:90

POA_STORAGE_MODULE::Storage::Storage (void)
  : TAO_ServantBase ()
{
  this->optable_ = &tao_STORAGE_MODULE_Storage_optable;
}

POA_STORAGE_MODULE::Storage::Storage (const Storage& rhs)
  : TAO_Abstract_ServantBase (rhs),
    TAO_ServantBase (rhs),
    POA_ACS::ACSComponent (rhs)
{
}

POA_STORAGE_MODULE::Storage::~Storage (void)
{
}

namespace POA_STORAGE_MODULE
{
  

  // TAO_IDL - Generated from
  // be/be_visitor_operation/upcall_command_ss.cpp:80

  class getNextValidId_Storage
    : public TAO::Upcall_Command
  {
  public:
    inline getNextValidId_Storage (
      POA_STORAGE_MODULE::Storage * servant,
      TAO_Operation_Details const * operation_details,
      TAO::Argument * const args[])
      : servant_ (servant)
        , operation_details_ (operation_details)
        , args_ (args)
    {
    }

    virtual void execute (void)
    {
      TAO::SArg_Traits< ::CORBA::Long>::ret_arg_type retval =
        TAO::Portable_Server::get_ret_arg< ::CORBA::Long> (
          this->operation_details_,
          this->args_);
      
      retval =
        this->servant_->getNextValidId ();
    }
  
  private:
    POA_STORAGE_MODULE::Storage * const servant_;
    TAO_Operation_Details const * const operation_details_;
    TAO::Argument * const * const args_;
  };
}

// TAO_IDL - Generated from
// be/be_visitor_operation/operation_ss.cpp:168

void POA_STORAGE_MODULE::Storage::getNextValidId_skel (
  TAO_ServerRequest & server_request,
  TAO::Portable_Server::Servant_Upcall *TAO_INTERCEPTOR (servant_upcall),
  TAO_ServantBase *servant)
{
#if TAO_HAS_INTERCEPTORS == 1
  static ::CORBA::TypeCode_ptr const * const exceptions = 0;
  static ::CORBA::ULong const nexceptions = 0;
#endif /* TAO_HAS_INTERCEPTORS */

  TAO::SArg_Traits< ::CORBA::Long>::ret_val retval;

  TAO::Argument * const args[] =
    {
      &retval
    };
  
  static size_t const nargs = 1;

  POA_STORAGE_MODULE::Storage * const impl =
    dynamic_cast<POA_STORAGE_MODULE::Storage *> (servant);

  if (!impl)
    {
      throw ::CORBA::INTERNAL ();
    }

  getNextValidId_Storage command (
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


namespace POA_STORAGE_MODULE
{
  

  // TAO_IDL - Generated from
  // be/be_visitor_operation/upcall_command_ss.cpp:80

  class storeObservation_Storage
    : public TAO::Upcall_Command
  {
  public:
    inline storeObservation_Storage (
      POA_STORAGE_MODULE::Storage * servant,
      TAO_Operation_Details const * operation_details,
      TAO::Argument * const args[])
      : servant_ (servant)
        , operation_details_ (operation_details)
        , args_ (args)
    {
    }

    virtual void execute (void)
    {
      TAO::SArg_Traits< ::TYPES::Proposal>::in_arg_type arg_1 =
        TAO::Portable_Server::get_in_arg< ::TYPES::Proposal> (
          this->operation_details_,
          this->args_,
          1);
        
      TAO::SArg_Traits< ::TYPES::ImageList>::in_arg_type arg_2 =
        TAO::Portable_Server::get_in_arg< ::TYPES::ImageList> (
          this->operation_details_,
          this->args_,
          2);
        
      this->servant_->storeObservation (
        arg_1
        , arg_2);
    }
  
  private:
    POA_STORAGE_MODULE::Storage * const servant_;
    TAO_Operation_Details const * const operation_details_;
    TAO::Argument * const * const args_;
  };
}

// TAO_IDL - Generated from
// be/be_visitor_operation/operation_ss.cpp:168

void POA_STORAGE_MODULE::Storage::storeObservation_skel (
  TAO_ServerRequest & server_request,
  TAO::Portable_Server::Servant_Upcall *TAO_INTERCEPTOR (servant_upcall),
  TAO_ServantBase *servant)
{
#if TAO_HAS_INTERCEPTORS == 1
  static ::CORBA::TypeCode_ptr const * const exceptions = 0;
  static ::CORBA::ULong const nexceptions = 0;
#endif /* TAO_HAS_INTERCEPTORS */

  TAO::SArg_Traits< void>::ret_val retval;
  TAO::SArg_Traits< ::TYPES::Proposal>::in_arg_val _tao_prop;
  TAO::SArg_Traits< ::TYPES::ImageList>::in_arg_val _tao_images;

  TAO::Argument * const args[] =
    {
      &retval,
      &_tao_prop,
      &_tao_images
    };
  
  static size_t const nargs = 3;

  POA_STORAGE_MODULE::Storage * const impl =
    dynamic_cast<POA_STORAGE_MODULE::Storage *> (servant);

  if (!impl)
    {
      throw ::CORBA::INTERNAL ();
    }

  storeObservation_Storage command (
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


namespace POA_STORAGE_MODULE
{
  

  // TAO_IDL - Generated from
  // be/be_visitor_operation/upcall_command_ss.cpp:80

  class clearAllData_Storage
    : public TAO::Upcall_Command
  {
  public:
    inline clearAllData_Storage (
      POA_STORAGE_MODULE::Storage * servant)
      : servant_ (servant)
    {
    }

    virtual void execute (void)
    {
      this->servant_->clearAllData ();
    }
  
  private:
    POA_STORAGE_MODULE::Storage * const servant_;
  };
}

// TAO_IDL - Generated from
// be/be_visitor_operation/operation_ss.cpp:168

void POA_STORAGE_MODULE::Storage::clearAllData_skel (
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

  POA_STORAGE_MODULE::Storage * const impl =
    dynamic_cast<POA_STORAGE_MODULE::Storage *> (servant);

  if (!impl)
    {
      throw ::CORBA::INTERNAL ();
    }

  clearAllData_Storage command (
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


namespace POA_STORAGE_MODULE
{
  

  // TAO_IDL - Generated from
  // be/be_visitor_operation/upcall_command_ss.cpp:80

  class getObservation_Storage
    : public TAO::Upcall_Command
  {
  public:
    inline getObservation_Storage (
      POA_STORAGE_MODULE::Storage * servant,
      TAO_Operation_Details const * operation_details,
      TAO::Argument * const args[])
      : servant_ (servant)
        , operation_details_ (operation_details)
        , args_ (args)
    {
    }

    virtual void execute (void)
    {
      TAO::SArg_Traits< ::TYPES::ImageList>::ret_arg_type retval =
        TAO::Portable_Server::get_ret_arg< ::TYPES::ImageList> (
          this->operation_details_,
          this->args_);
      
      TAO::SArg_Traits< ::CORBA::Long>::in_arg_type arg_1 =
        TAO::Portable_Server::get_in_arg< ::CORBA::Long> (
          this->operation_details_,
          this->args_,
          1);
        
      retval =
        this->servant_->getObservation (
          arg_1);
    }
  
  private:
    POA_STORAGE_MODULE::Storage * const servant_;
    TAO_Operation_Details const * const operation_details_;
    TAO::Argument * const * const args_;
  };
}

// TAO_IDL - Generated from
// be/be_visitor_operation/operation_ss.cpp:168

void POA_STORAGE_MODULE::Storage::getObservation_skel (
  TAO_ServerRequest & server_request,
  TAO::Portable_Server::Servant_Upcall *TAO_INTERCEPTOR (servant_upcall),
  TAO_ServantBase *servant)
{
#if TAO_HAS_INTERCEPTORS == 1
  static ::CORBA::TypeCode_ptr const * const exceptions = 0;
  static ::CORBA::ULong const nexceptions = 0;
#endif /* TAO_HAS_INTERCEPTORS */

  TAO::SArg_Traits< ::TYPES::ImageList>::ret_val retval;
  TAO::SArg_Traits< ::CORBA::Long>::in_arg_val _tao_pid;

  TAO::Argument * const args[] =
    {
      &retval,
      &_tao_pid
    };
  
  static size_t const nargs = 2;

  POA_STORAGE_MODULE::Storage * const impl =
    dynamic_cast<POA_STORAGE_MODULE::Storage *> (servant);

  if (!impl)
    {
      throw ::CORBA::INTERNAL ();
    }

  getObservation_Storage command (
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



::CORBA::Boolean POA_STORAGE_MODULE::Storage::_is_a (const char* value)
{
  return
    (
      ACE_OS::strcmp (
          value,
          "IDL:alma/ACS/ACSComponent:1.0"
        ) == 0 ||
      ACE_OS::strcmp (
          value,
          "IDL:acsws/STORAGE_MODULE/Storage:1.0"
        ) == 0 ||
      !ACE_OS::strcmp (
          value,
          "IDL:omg.org/CORBA/Object:1.0"
        )
    );
}

const char* POA_STORAGE_MODULE::Storage::_interface_repository_id (void) const
{
  return "IDL:acsws/STORAGE_MODULE/Storage:1.0";
}

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_ss.cpp:423

void POA_STORAGE_MODULE::Storage::_dispatch (
  TAO_ServerRequest & req,
  TAO::Portable_Server::Servant_Upcall* servant_upcall)
{
  this->synchronous_upcall_dispatch (req, servant_upcall, this);
}

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_ss.cpp:370

STORAGE_MODULE::Storage *
POA_STORAGE_MODULE::Storage::_this (void)
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

  typedef ::STORAGE_MODULE::Storage STUB_SCOPED_NAME;
  return
    TAO::Narrow_Utils<STUB_SCOPED_NAME>::unchecked_narrow (
        obj.in ());
}

#endif /* ifndef */


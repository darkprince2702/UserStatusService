/**
 * Autogenerated by Thrift Compiler (0.9.3)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef UserStatusService_H
#define UserStatusService_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "userstatusservice_types.h"

namespace userstatusservice {

#ifdef _WIN32
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class UserStatusServiceIf {
 public:
  virtual ~UserStatusServiceIf() {}
  virtual bool getUserStatus(const int64_t ID) = 0;
  virtual void setUserStatus(const int64_t ID, const bool status) = 0;
};

class UserStatusServiceIfFactory {
 public:
  typedef UserStatusServiceIf Handler;

  virtual ~UserStatusServiceIfFactory() {}

  virtual UserStatusServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(UserStatusServiceIf* /* handler */) = 0;
};

class UserStatusServiceIfSingletonFactory : virtual public UserStatusServiceIfFactory {
 public:
  UserStatusServiceIfSingletonFactory(const boost::shared_ptr<UserStatusServiceIf>& iface) : iface_(iface) {}
  virtual ~UserStatusServiceIfSingletonFactory() {}

  virtual UserStatusServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(UserStatusServiceIf* /* handler */) {}

 protected:
  boost::shared_ptr<UserStatusServiceIf> iface_;
};

class UserStatusServiceNull : virtual public UserStatusServiceIf {
 public:
  virtual ~UserStatusServiceNull() {}
  bool getUserStatus(const int64_t /* ID */) {
    bool _return = false;
    return _return;
  }
  void setUserStatus(const int64_t /* ID */, const bool /* status */) {
    return;
  }
};

typedef struct _UserStatusService_getUserStatus_args__isset {
  _UserStatusService_getUserStatus_args__isset() : ID(false) {}
  bool ID :1;
} _UserStatusService_getUserStatus_args__isset;

class UserStatusService_getUserStatus_args {
 public:

  UserStatusService_getUserStatus_args(const UserStatusService_getUserStatus_args&);
  UserStatusService_getUserStatus_args& operator=(const UserStatusService_getUserStatus_args&);
  UserStatusService_getUserStatus_args() : ID(0) {
  }

  virtual ~UserStatusService_getUserStatus_args() throw();
  int64_t ID;

  _UserStatusService_getUserStatus_args__isset __isset;

  void __set_ID(const int64_t val);

  bool operator == (const UserStatusService_getUserStatus_args & rhs) const
  {
    if (!(ID == rhs.ID))
      return false;
    return true;
  }
  bool operator != (const UserStatusService_getUserStatus_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UserStatusService_getUserStatus_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class UserStatusService_getUserStatus_pargs {
 public:


  virtual ~UserStatusService_getUserStatus_pargs() throw();
  const int64_t* ID;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UserStatusService_getUserStatus_result__isset {
  _UserStatusService_getUserStatus_result__isset() : success(false) {}
  bool success :1;
} _UserStatusService_getUserStatus_result__isset;

class UserStatusService_getUserStatus_result {
 public:

  UserStatusService_getUserStatus_result(const UserStatusService_getUserStatus_result&);
  UserStatusService_getUserStatus_result& operator=(const UserStatusService_getUserStatus_result&);
  UserStatusService_getUserStatus_result() : success(0) {
  }

  virtual ~UserStatusService_getUserStatus_result() throw();
  bool success;

  _UserStatusService_getUserStatus_result__isset __isset;

  void __set_success(const bool val);

  bool operator == (const UserStatusService_getUserStatus_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const UserStatusService_getUserStatus_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UserStatusService_getUserStatus_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _UserStatusService_getUserStatus_presult__isset {
  _UserStatusService_getUserStatus_presult__isset() : success(false) {}
  bool success :1;
} _UserStatusService_getUserStatus_presult__isset;

class UserStatusService_getUserStatus_presult {
 public:


  virtual ~UserStatusService_getUserStatus_presult() throw();
  bool* success;

  _UserStatusService_getUserStatus_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _UserStatusService_setUserStatus_args__isset {
  _UserStatusService_setUserStatus_args__isset() : ID(false), status(false) {}
  bool ID :1;
  bool status :1;
} _UserStatusService_setUserStatus_args__isset;

class UserStatusService_setUserStatus_args {
 public:

  UserStatusService_setUserStatus_args(const UserStatusService_setUserStatus_args&);
  UserStatusService_setUserStatus_args& operator=(const UserStatusService_setUserStatus_args&);
  UserStatusService_setUserStatus_args() : ID(0), status(0) {
  }

  virtual ~UserStatusService_setUserStatus_args() throw();
  int64_t ID;
  bool status;

  _UserStatusService_setUserStatus_args__isset __isset;

  void __set_ID(const int64_t val);

  void __set_status(const bool val);

  bool operator == (const UserStatusService_setUserStatus_args & rhs) const
  {
    if (!(ID == rhs.ID))
      return false;
    if (!(status == rhs.status))
      return false;
    return true;
  }
  bool operator != (const UserStatusService_setUserStatus_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UserStatusService_setUserStatus_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class UserStatusService_setUserStatus_pargs {
 public:


  virtual ~UserStatusService_setUserStatus_pargs() throw();
  const int64_t* ID;
  const bool* status;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class UserStatusService_setUserStatus_result {
 public:

  UserStatusService_setUserStatus_result(const UserStatusService_setUserStatus_result&);
  UserStatusService_setUserStatus_result& operator=(const UserStatusService_setUserStatus_result&);
  UserStatusService_setUserStatus_result() {
  }

  virtual ~UserStatusService_setUserStatus_result() throw();

  bool operator == (const UserStatusService_setUserStatus_result & /* rhs */) const
  {
    return true;
  }
  bool operator != (const UserStatusService_setUserStatus_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const UserStatusService_setUserStatus_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class UserStatusService_setUserStatus_presult {
 public:


  virtual ~UserStatusService_setUserStatus_presult() throw();

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class UserStatusServiceClient : virtual public UserStatusServiceIf {
 public:
  UserStatusServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  UserStatusServiceClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  bool getUserStatus(const int64_t ID);
  void send_getUserStatus(const int64_t ID);
  bool recv_getUserStatus();
  void setUserStatus(const int64_t ID, const bool status);
  void send_setUserStatus(const int64_t ID, const bool status);
  void recv_setUserStatus();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class UserStatusServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<UserStatusServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (UserStatusServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_getUserStatus(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_setUserStatus(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  UserStatusServiceProcessor(boost::shared_ptr<UserStatusServiceIf> iface) :
    iface_(iface) {
    processMap_["getUserStatus"] = &UserStatusServiceProcessor::process_getUserStatus;
    processMap_["setUserStatus"] = &UserStatusServiceProcessor::process_setUserStatus;
  }

  virtual ~UserStatusServiceProcessor() {}
};

class UserStatusServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  UserStatusServiceProcessorFactory(const ::boost::shared_ptr< UserStatusServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< UserStatusServiceIfFactory > handlerFactory_;
};

class UserStatusServiceMultiface : virtual public UserStatusServiceIf {
 public:
  UserStatusServiceMultiface(std::vector<boost::shared_ptr<UserStatusServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~UserStatusServiceMultiface() {}
 protected:
  std::vector<boost::shared_ptr<UserStatusServiceIf> > ifaces_;
  UserStatusServiceMultiface() {}
  void add(boost::shared_ptr<UserStatusServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  bool getUserStatus(const int64_t ID) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getUserStatus(ID);
    }
    return ifaces_[i]->getUserStatus(ID);
  }

  void setUserStatus(const int64_t ID, const bool status) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->setUserStatus(ID, status);
    }
    ifaces_[i]->setUserStatus(ID, status);
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class UserStatusServiceConcurrentClient : virtual public UserStatusServiceIf {
 public:
  UserStatusServiceConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  UserStatusServiceConcurrentClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  bool getUserStatus(const int64_t ID);
  int32_t send_getUserStatus(const int64_t ID);
  bool recv_getUserStatus(const int32_t seqid);
  void setUserStatus(const int64_t ID, const bool status);
  int32_t send_setUserStatus(const int64_t ID, const bool status);
  void recv_setUserStatus(const int32_t seqid);
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  ::apache::thrift::async::TConcurrentClientSyncInfo sync_;
};

#ifdef _WIN32
  #pragma warning( pop )
#endif

} // namespace

#endif

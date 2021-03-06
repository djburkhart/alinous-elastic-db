#ifndef ALINOUS_REMOTE_REGION_CLIENT_COMMAND_ABSTRACTNODEREGIONCOMMAND_H_
#define ALINOUS_REMOTE_REGION_CLIENT_COMMAND_ABSTRACTNODEREGIONCOMMAND_H_
namespace alinous {namespace remote {namespace region {namespace client {namespace command {
class AbstractNodeRegionCommand;}}}}}

namespace alinous {namespace net {
class AlinousSocket;}}

namespace java {namespace io {
class OutputStream;}}

namespace java {namespace io {
class InputStream;}}

namespace alinous {namespace remote {namespace region {namespace server {
class NodeRegionServer;}}}}

namespace java {namespace io {
class BufferedOutputStream;}}

namespace java {namespace lang {
class Throwable;}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace remote {namespace socket {
class NetworkBinaryBuffer;}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace remote {namespace region {namespace server {
class NodeRegionResponceAction;}}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace alinous {namespace system {
class AlinousException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::BufferedOutputStream;
using ::java::io::IOException;
using ::java::io::InputStream;
using ::java::io::OutputStream;
using ::java::util::ArrayList;
using ::java::util::List;
using ::alinous::net::AlinousSocket;
using ::alinous::remote::region::server::NodeRegionResponceAction;
using ::alinous::remote::region::server::NodeRegionServer;
using ::alinous::remote::socket::NetworkBinaryBuffer;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousException;



class AbstractNodeRegionCommand : public virtual IObject {
public:
	AbstractNodeRegionCommand(const AbstractNodeRegionCommand& base) = default;
public:
	AbstractNodeRegionCommand(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~AbstractNodeRegionCommand() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	int type;
	List<String>* errorMessage;
public:
	constexpr static const int TYPE_VOID{0};
	constexpr static const int TYPE_FINISH{1};
	constexpr static const int TYPE_CONNECT{2};
	constexpr static const int TYPE_TERMINATE{404};
	constexpr static const int TYPE_GET_SCHEMA_FROM_REGION{1001};
	constexpr static const int TYPE_CREATE_SCHEMA{1002};
	constexpr static const int TYPE_CREATE_TABLE{1003};
	constexpr static const int TYPE_INSERT_DATA{1004};
	constexpr static const int TYPE_TPC_COMMIT_SESSION{1005};
	constexpr static const int TYPE_SCAN{1006};
	constexpr static const int TYPE_SCAN_END{1007};
	constexpr static const int TYPE_CLEAR_SELECT_SESSION{1008};
public:
	int getType(ThreadContext* ctx) throw() ;
	AbstractNodeRegionCommand* sendCommand(AlinousSocket* socket, ThreadContext* ctx);
	virtual void executeOnServer(NodeRegionServer* nodeRegionServer, BufferedOutputStream* outStream, ThreadContext* ctx) = 0;
	virtual void readFromStream(InputStream* stream, int remain, ThreadContext* ctx) = 0;
	bool hasError(ThreadContext* ctx) throw() ;
	List<String>* getErrorMessage(ThreadContext* ctx) throw() ;
	virtual void writeByteStream(OutputStream* outStream, ThreadContext* ctx) = 0;
	void handleError(Throwable* e, ThreadContext* ctx) throw() ;
	void writeErrorByteStream(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() ;
	void readErrorFromStream(NetworkBinaryBuffer* buff, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}}}

#endif /* end of ALINOUS_REMOTE_REGION_CLIENT_COMMAND_ABSTRACTNODEREGIONCOMMAND_H_ */

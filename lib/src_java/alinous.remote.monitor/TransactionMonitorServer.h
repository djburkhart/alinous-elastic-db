#ifndef ALINOUS_REMOTE_MONITOR_TRANSACTIONMONITORSERVER_H_
#define ALINOUS_REMOTE_MONITOR_TRANSACTIONMONITORSERVER_H_
namespace alinous {namespace remote {namespace monitor {namespace command {namespace data {
class RegionInfoData;}}}}}

namespace alinous {namespace remote {namespace monitor {
class TransactionMonitorServer;}}}

namespace alinous {namespace system {namespace config {namespace remote {
class Monitor;}}}}

namespace alinous {namespace remote {namespace monitor {
class RegionNodeInfoManager;}}}

namespace alinous {namespace system {
class ISystemLog;}}

namespace alinous {namespace remote {namespace monitor {
class MonitorResponseActionFactory;}}}

namespace alinous {namespace remote {namespace socket {
class SocketServer;}}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace remote {namespace monitor {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::db::AlinousDbException;
using ::alinous::remote::monitor::command::data::RegionInfoData;
using ::alinous::remote::socket::SocketServer;
using ::alinous::system::ISystemLog;
using ::alinous::system::config::remote::Monitor;



class TransactionMonitorServer final : public virtual IObject {
public:
	TransactionMonitorServer(const TransactionMonitorServer& base) = default;
public:
	TransactionMonitorServer(int port, int maxthread, ThreadContext* ctx) throw() ;
	void __construct_impl(int port, int maxthread, ThreadContext* ctx) throw() ;
	virtual ~TransactionMonitorServer() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	int port;
	long long lastCommitId;
	long long lastOid;
	int maxthread;
	SocketServer* socketServer;
	RegionNodeInfoManager* nodeInfo;
public:
	static String* THREAD_NAME;
public:
	void getRegionInfo(RegionInfoData* data, ThreadContext* ctx) throw() ;
	TransactionMonitorServer* init(Monitor* monitorConf, ThreadContext* ctx);
	void start(ISystemLog* logger, ThreadContext* ctx) throw() ;
	void dispose(ThreadContext* ctx) throw() ;
	int getPort(ThreadContext* ctx) throw() ;
	long long updateNodeClusterRevision(long long nodeClusterRevision, ThreadContext* ctx) throw() ;
	long long getNextCommitId(ThreadContext* ctx) throw() ;
	long long getNextOid(ThreadContext* ctx) throw() ;
	RegionNodeInfoManager* getNodeInfo(ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_REMOTE_MONITOR_TRANSACTIONMONITORSERVER_H_ */

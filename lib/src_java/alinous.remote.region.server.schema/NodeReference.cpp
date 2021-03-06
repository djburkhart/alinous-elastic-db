#include "include/global.h"


#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.system/AlinousException.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.db.trx/DbVersionContext.h"
#include "alinous.remote.socket/ISocketConnection.h"
#include "alinous.remote.socket/SocketConnectionPool.h"
#include "alinous.remote.socket/ISocketConnectionFactory.h"
#include "alinous.remote.db.client/RemoteStorageConnectionInfo.h"
#include "alinous.remote.db.client/RemoteStorageClientConnectionFactory.h"
#include "java.io/FilterOutputStream.h"
#include "java.io/BufferedOutputStream.h"
#include "alinous.remote.db.client.command.data/SchemasStructureInfoData.h"
#include "alinous.remote.region.client.command.dml/ClientScanCommandData.h"
#include "alinous.remote.region.server.scan/ScanWorkerResult.h"
#include "alinous.remote.db.server/RemoteTableStorageServer.h"
#include "alinous.remote.db.client.command/AbstractRemoteStorageCommand.h"
#include "alinous.remote.db.client.command.ddl/CreateSchemaCommand.h"
#include "alinous.remote.db.client.command.ddl/CreateTableCommand.h"
#include "alinous.remote.db.client.command.dml/ScanStorageCommand.h"
#include "alinous.remote.db.client.command/GetTableSchemeCommand.h"
#include "alinous.remote.db.client.command/RemoteStorageCommandReader.h"
#include "alinous.remote.region.server.schema/NodeReference.h"

namespace alinous {namespace remote {namespace region {namespace server {namespace schema {





bool NodeReference::__init_done = __init_static_variables();
bool NodeReference::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NodeReference", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NodeReference::NodeReference(String* host, int port, bool ipv6, ThreadContext* ctx) throw()  : IObject(ctx), host(nullptr), port(0), ipv6(0), nodeConnectionPool(nullptr)
{
	__GC_MV(this, &(this->host), host, String);
	this->port = port;
	this->ipv6 = ipv6;
}
void NodeReference::__construct_impl(String* host, int port, bool ipv6, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->host), host, String);
	this->port = port;
	this->ipv6 = ipv6;
}
 NodeReference::~NodeReference() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NodeReference::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"NodeReference", L"~NodeReference");
	__e_obj1.add(this->host, this);
	host = nullptr;
	__e_obj1.add(this->nodeConnectionPool, this);
	nodeConnectionPool = nullptr;
	if(!prepare){
		return;
	}
}
String* NodeReference::toString(ThreadContext* ctx) throw() 
{
	StringBuilder* buff = (new(ctx) StringBuilder(256, ctx));
	if(this->ipv6)
	{
		buff->append(ConstStr::getCNST_STR_3617(), ctx);
	}
		else 
	{
		buff->append(ConstStr::getCNST_STR_3618(), ctx);
	}
	buff->append(host, ctx);
	buff->append(ConstStr::getCNST_STR_381(), ctx)->append(Integer::toString(this->port, ctx), ctx);
	return buff->toString(ctx);
}
void NodeReference::initConnectionPool(ThreadContext* ctx) throw() 
{
	RemoteStorageConnectionInfo* info = (new(ctx) RemoteStorageConnectionInfo(this->host, this->port, ctx));
	RemoteStorageClientConnectionFactory* factory = (new(ctx) RemoteStorageClientConnectionFactory(info, ctx));
	__GC_MV(this, &(this->nodeConnectionPool), (new(ctx) SocketConnectionPool(factory, ctx)), SocketConnectionPool);
}
void NodeReference::dispose(ThreadContext* ctx) throw() 
{
	if(this->nodeConnectionPool != nullptr)
	{
		this->nodeConnectionPool->dispose(ctx);
	}
}
SchemasStructureInfoData* NodeReference::getSchemeInfo(String* region, ThreadContext* ctx)
{
	GetTableSchemeCommand* cmd = (new(ctx) GetTableSchemeCommand(ctx));
	cmd->setRegion(region, ctx);
	cmd->setHost(this->host, ctx);
	cmd->setPort(this->port, ctx);
	cmd->setIpv6(this->ipv6, ctx);
	ISocketConnection* con = nullptr;
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			this->nodeConnectionPool->returnConnection(con, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			con = this->nodeConnectionPool->getConnection(ctx);
			AlinousSocket* socket = con->getSocket(ctx);
			AbstractRemoteStorageCommand* retcmd = cmd->sendCommand(socket, ctx);
			if(retcmd->getType(ctx) != AbstractRemoteStorageCommand::TYPE_GET_TABLE_SCHEME)
			{
				throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3619(), ctx));
			}
			cmd = static_cast<GetTableSchemeCommand*>(retcmd);
		}
		catch(UnknownHostException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3620(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3621(), e, ctx));
		}
	}
	return cmd->getData(ctx);
}
AbstractRemoteStorageCommand* NodeReference::sendCommand(AbstractRemoteStorageCommand* cmd, ThreadContext* ctx)
{
	ISocketConnection* con = nullptr;
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			this->nodeConnectionPool->returnConnection(con, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			con = this->nodeConnectionPool->getConnection(ctx);
			AlinousSocket* socket = con->getSocket(ctx);
			int type = cmd->getType(ctx);
			AbstractRemoteStorageCommand* retcmd = cmd->sendCommand(socket, ctx);
			if(retcmd->getType(ctx) != type)
			{
				throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3619(), ctx));
			}
			return retcmd;
		}
		catch(UnknownHostException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3622(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3622(), e, ctx));
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3622(), e, ctx));
		}
	}
}
void NodeReference::createSchema(String* schemaName, ThreadContext* ctx)
{
	CreateSchemaCommand* cmd = (new(ctx) CreateSchemaCommand(ctx));
	ISocketConnection* con = nullptr;
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			this->nodeConnectionPool->returnConnection(con, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			con = this->nodeConnectionPool->getConnection(ctx);
			AlinousSocket* socket = con->getSocket(ctx);
			AbstractRemoteStorageCommand* retcmd = cmd->sendCommand(socket, ctx);
			if(retcmd->getType(ctx) != AbstractRemoteStorageCommand::TYPE_CREATE_SCHEMA)
			{
				throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3619(), ctx));
			}
			cmd = static_cast<CreateSchemaCommand*>(retcmd);
		}
		catch(UnknownHostException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3622(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3622(), e, ctx));
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3622(), e, ctx));
		}
	}
}
void NodeReference::createTable(TableMetadata* meta, ThreadContext* ctx)
{
	CreateTableCommand* cmd = (new(ctx) CreateTableCommand(ctx));
	cmd->setMetadaata(meta, ctx);
	ISocketConnection* con = nullptr;
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			this->nodeConnectionPool->returnConnection(con, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			con = this->nodeConnectionPool->getConnection(ctx);
			AlinousSocket* socket = con->getSocket(ctx);
			AbstractRemoteStorageCommand* retcmd = cmd->sendCommand(socket, ctx);
			if(retcmd->getType(ctx) != AbstractRemoteStorageCommand::TYPE_CREATE_TABLE)
			{
				throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3619(), ctx));
			}
		}
		catch(UnknownHostException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3623(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3623(), e, ctx));
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3623(), e, ctx));
		}
	}
}
ScanWorkerResult* NodeReference::scan(DbVersionContext* vctx, ClientScanCommandData* data, ThreadContext* ctx)
{
	ScanStorageCommand* cmd = (new(ctx) ScanStorageCommand(ctx));
	cmd->setData(data, ctx);
	cmd->setVctx(vctx, ctx);
	ISocketConnection* con = nullptr;
	{
		std::function<void(void)> finallyLm2= [&, this]()
		{
			this->nodeConnectionPool->returnConnection(con, ctx);
		};
		Releaser finalyCaller2(finallyLm2);
		try
		{
			con = this->nodeConnectionPool->getConnection(ctx);
			AlinousSocket* socket = con->getSocket(ctx);
			AbstractRemoteStorageCommand* retcmd = cmd->sendCommand(socket, ctx);
			if(retcmd->getType(ctx) != ScanStorageCommand::TYPE_SCAN_STORAGE)
			{
				throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3619(), ctx));
			}
			cmd = static_cast<ScanStorageCommand*>(retcmd);
			return cmd->getResult(ctx);
		}
		catch(UnknownHostException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3623(), e, ctx));
		}
		catch(IOException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3623(), e, ctx));
		}
		catch(AlinousException* e)
		{
			throw (new(ctx) AlinousException(ConstStr::getCNST_STR_3623(), e, ctx));
		}
	}
}
String* NodeReference::getHost(ThreadContext* ctx) throw() 
{
	return host;
}
int NodeReference::getPort(ThreadContext* ctx) throw() 
{
	return port;
}
bool NodeReference::isIpv6(ThreadContext* ctx) throw() 
{
	return ipv6;
}
bool NodeReference::equals(String* host, int port, bool ipv6, ThreadContext* ctx) throw() 
{
	return this->ipv6 == ipv6 && this->port == port && this->host->equals(host, ctx);
}
bool NodeReference::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	NodeReference* ref = dynamic_cast<NodeReference*>(obj);
	return this->ipv6 == ref->isIpv6(ctx) && this->port == ref->getPort(ctx) && this->host->equals(ref->getHost(ctx), ctx);
}
void NodeReference::__cleanUp(ThreadContext* ctx){
}
}}}}}


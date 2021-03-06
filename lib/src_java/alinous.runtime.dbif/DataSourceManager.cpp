#include "include/global.h"


#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.db/AlinousDbException.h"
#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config/AlinousDbInstanceInfo.h"
#include "alinous.system.config/AlinousDbInfo.h"
#include "alinous.system.config/AlinousConfig.h"
#include "alinous.system/ISystemLog.h"
#include "alinous.system/AlinousCore.h"
#include "alinous.runtime.dbif/IDatabaseDriver.h"
#include "alinous.runtime.dbif/AlinousDatabaseHandler.h"
#include "alinous.runtime.dbif/DataSourceManager.h"

namespace alinous {namespace runtime {namespace dbif {





bool DataSourceManager::__init_done = __init_static_variables();
bool DataSourceManager::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DataSourceManager", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DataSourceManager::DataSourceManager(AlinousCore* core, ThreadContext* ctx) : IObject(ctx), drivers(GCUtils<HashMap<String,IDatabaseDriver> >::ins(this, (new(ctx) HashMap<String,IDatabaseDriver>(ctx)), ctx, __FILEW__, __LINE__, L"")), core(nullptr)
{
	__GC_MV(this, &(this->core), core, AlinousCore);
}
void DataSourceManager::__construct_impl(AlinousCore* core, ThreadContext* ctx)
{
	__GC_MV(this, &(this->core), core, AlinousCore);
}
 DataSourceManager::~DataSourceManager() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DataSourceManager::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DataSourceManager", L"~DataSourceManager");
	__e_obj1.add(this->drivers, this);
	drivers = nullptr;
	__e_obj1.add(this->core, this);
	core = nullptr;
	if(!prepare){
		return;
	}
}
void DataSourceManager::init(ThreadContext* ctx)
{
	AlinousConfig* config = this->core->getConfig(ctx);
	AlinousDbInfo* adbInfo = config->getAlinousDb(ctx);
	Iterator<String>* it = adbInfo->idSet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* id = it->next(ctx);
		AlinousDbInstanceInfo* instanceConfig = adbInfo->getInstance(id, ctx);
		IDatabaseDriver* driver = this->drivers->get(id, ctx);
		if(driver != nullptr)
		{
			this->core->getLogger(ctx)->logWarning(ConstStr::getCNST_STR_1180()->clone(ctx)->append(id, ctx)->append(ConstStr::getCNST_STR_1181(), ctx), ctx);
			continue;
		}
		driver = (new(ctx) AlinousDatabaseHandler(instanceConfig, ctx));
		{
			try
			{
				driver->initDriver(this->core, instanceConfig, ctx);
			}
			catch(AlinousDbException* e)
			{
				ISystemLog* log = this->core->getLogger(ctx);
				log->logError(e, ctx);
				continue;
			}
		}
		this->drivers->put(id, driver, ctx);
	}
}
IDatabaseDriver* DataSourceManager::get(String* id, ThreadContext* ctx) throw() 
{
	return this->drivers->get(id, ctx);
}
void DataSourceManager::dispose(ThreadContext* ctx) throw() 
{
	Iterator<String>* it = this->drivers->keySet(ctx)->iterator(ctx);
	while(it->hasNext(ctx))
	{
		String* id = it->next(ctx);
		IDatabaseDriver* driver = this->drivers->get(id, ctx);
		driver->dispose(ctx);
	}
	this->drivers->clear(ctx);
}
void DataSourceManager::__cleanUp(ThreadContext* ctx){
}
}}}


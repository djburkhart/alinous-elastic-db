#include "includes.h"


namespace alinous {namespace db {namespace table {namespace lockmonitor {





bool RowLockReleaser::__init_done = __init_static_variables();
bool RowLockReleaser::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RowLockReleaser", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RowLockReleaser::RowLockReleaser(DBThreadMonitor* monitor, DatabaseTable* table, long long oid, ThreadLocker* locker, ThreadContext* ctx) throw()  : IObject(ctx), IThreadAction(ctx), table(nullptr), oid(0), locker(nullptr), monitor(nullptr)
{
	__GC_MV(this, &(this->table), table, DatabaseTable);
	this->oid = oid;
	__GC_MV(this, &(this->locker), locker, ThreadLocker);
	__GC_MV(this, &(this->monitor), monitor, DBThreadMonitor);
}
void RowLockReleaser::__construct_impl(DBThreadMonitor* monitor, DatabaseTable* table, long long oid, ThreadLocker* locker, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->table), table, DatabaseTable);
	this->oid = oid;
	__GC_MV(this, &(this->locker), locker, ThreadLocker);
	__GC_MV(this, &(this->monitor), monitor, DBThreadMonitor);
}
 RowLockReleaser::~RowLockReleaser() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RowLockReleaser::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RowLockReleaser", L"~RowLockReleaser");
	__e_obj1.add(this->table, this);
	table = nullptr;
	__e_obj1.add(this->locker, this);
	locker = nullptr;
	__e_obj1.add(this->monitor, this);
	monitor = nullptr;
	if(!prepare){
		return;
	}
}
void RowLockReleaser::execute(ThreadContext* ctx)
{
}
}}}}


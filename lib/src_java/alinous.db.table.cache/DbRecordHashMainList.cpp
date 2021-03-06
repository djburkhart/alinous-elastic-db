#include "include/global.h"


#include "java.util/BitSet.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.system/AlinousException.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.db.table/IDatabaseRecord.h"
#include "alinous.lock/LockObject.h"
#include "alinous.lock/ConcurrentGate.h"
#include "alinous.buffer.storage/IFileStorage.h"
#include "alinous.buffer.storage/FileStorage.h"
#include "alinous.btree/BTreeGlobalCache.h"
#include "alinous.system/AlinousCore.h"
#include "java.lang/Number.h"
#include "java.lang/Comparable.h"
#include "java.lang/Integer.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree/BTree.h"
#include "alinous.db.table/IScannableIndex.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.db.table/TableMetadata.h"
#include "alinous.db.table/IDatabaseTable.h"
#include "alinous.db.table/DatabaseRecord.h"
#include "alinous.numeric/InternalDate.h"
#include "java.sql/Timestamp.h"
#include "alinous.db.table/DatabaseTableIdPublisher.h"
#include "alinous.db.table/IBtreeTableIndex.h"
#include "alinous.db.table/TableIndex.h"
#include "alinous.db.table/DatatableUpdateCache.h"
#include "alinous.db.table/AbstractDatabaseTable.h"
#include "alinous.db.table/DataTableStorageSupport.h"
#include "alinous.db.table.cache/DbRecordHashArray.h"
#include "alinous.db.table.cache/DbREcordHashListIterator.h"
#include "alinous.db.table.cache/DbRecordHashMainList.h"

namespace alinous {namespace db {namespace table {namespace cache {





bool DbRecordHashMainList::__init_done = __init_static_variables();
bool DbRecordHashMainList::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"DbRecordHashMainList", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 DbRecordHashMainList::DbRecordHashMainList(ThreadContext* ctx) throw()  : IObject(ctx), MAX_HASH(0), MAX_HASH_MASK(0), arrays(nullptr), bitset(__GC_INS(this, (new(ctx) BitSet(ctx)), BitSet)), numElements(0)
{
}
void DbRecordHashMainList::__construct_impl(ThreadContext* ctx) throw() 
{
}
 DbRecordHashMainList::~DbRecordHashMainList() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void DbRecordHashMainList::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"DbRecordHashMainList", L"~DbRecordHashMainList");
	__e_obj1.add(this->arrays, this);
	arrays = nullptr;
	__e_obj1.add(this->bitset, this);
	bitset = nullptr;
	if(!prepare){
		return;
	}
}
DbRecordHashMainList* DbRecordHashMainList::init(int MAX_HASH, ThreadContext* ctx)
{
	if((MAX_HASH & 1) != 0)
	{
		throw (new(ctx) AlinousException(ConstStr::getCNST_STR_1758(), ctx));
	}
	this->MAX_HASH = MAX_HASH;
	this->MAX_HASH_MASK = this->MAX_HASH - 1;
	__GC_MV(this, &(this->arrays), ArrayAllocator<DbRecordHashArray>::allocate(ctx, MAX_HASH), IArrayObject<DbRecordHashArray>);
	for(int i = 0; i != MAX_HASH; i ++ )
	{
		arrays->set((new(ctx) DbRecordHashArray(4, ctx)),i, ctx);
	}
	return this;
}
int DbRecordHashMainList::size(ThreadContext* ctx) throw() 
{
	return this->numElements;
}
DatabaseRecord* DbRecordHashMainList::addElement(DatabaseRecord* ptr, ThreadContext* ctx) throw() 
{
	int hashcode = ((int)(ptr->getHashKey(ctx) & MAX_HASH_MASK));
	arrays->get(hashcode)->add(ptr, ctx);
	bitset->set(hashcode, ctx);
	++numElements;
	return ptr;
}
bool DbRecordHashMainList::removeByObj(DatabaseRecord* obj, ThreadContext* ctx) throw() 
{
	int hashcode = ((int)(obj->getHashKey(ctx) & MAX_HASH_MASK));
	bool result = arrays->get(hashcode)->removeByObj(obj, ctx);
	if(result)
	{
		--numElements;
	}
	if(arrays->get(hashcode)->size(ctx) == 0)
	{
		bitset->clear(hashcode, ctx);
	}
	return result;
}
DatabaseRecord* DbRecordHashMainList::search(DataTableStorageSupport* table, long long position, ThreadContext* ctx) throw() 
{
	int hashcode = ((int)(((unsigned long long)((position + table->getTableId(ctx)->intValue(ctx)) * 2654404609L))>> 32));
	hashcode = hashcode & MAX_HASH_MASK;
	return arrays->get(hashcode)->search(table, position, ctx);
}
void DbRecordHashMainList::reset(ThreadContext* ctx) throw() 
{
	for(int i = 0; i != MAX_HASH; i ++ )
	{
		arrays->get(i)->reset(ctx);
	}
	bitset->clear(ctx);
	numElements = 0;
}
DbREcordHashListIterator* DbRecordHashMainList::iterator(ThreadContext* ctx) throw() 
{
	return (new(ctx) DbREcordHashListIterator(arrays, bitset, MAX_HASH, ctx));
}
void DbRecordHashMainList::__cleanUp(ThreadContext* ctx){
}
}}}}


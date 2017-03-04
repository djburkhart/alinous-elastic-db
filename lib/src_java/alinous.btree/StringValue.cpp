#include "include/global.h"


#include "alinous.buffer/FifoElement.h"
#include "alinous.buffer.storage/FileStorageEntry.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.lock/LockObject.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree.scan/INodeIterator.h"
#include "alinous.lock/ConcurrentGate.h"
#include "alinous.buffer.storage/FileAccessWrapper.h"
#include "alinous.buffer.storage/FileStorageBlock.h"
#include "alinous.buffer.storage/IFileStorage.h"
#include "alinous.buffer.storage/FileStorageEntryWriter.h"
#include "alinous.buffer.storage/FileStorageEntryReader.h"
#include "alinous.buffer.storage/FileStorage.h"
#include "alinous.buffer/FifoIterator.h"
#include "alinous.buffer/FifoList.h"
#include "java.util/BitSet.h"
#include "alinous.btree/BTreeCacheArray.h"
#include "alinous.btree/BTreeException.h"
#include "alinous.buffer/HashArrayListIterator.h"
#include "alinous.buffer/HashArrayList.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.btree/IBTreeNode.h"
#include "alinous.btree/BTreeCacheRecord.h"
#include "alinous.btree/BTreeGlobalCache.h"
#include "alinous.btree/AbstractNode.h"
#include "alinous.btree/BTreeNodeHandler.h"
#include "alinous.btree/AbstractBTreeNode.h"
#include "alinous.btree/BTreeNode.h"
#include "alinous.btree/BTreeMaxNode.h"
#include "alinous.btree/AbstractBTreeLeafContainer.h"
#include "alinous.btree/BTreeMaxLeafContainer.h"
#include "alinous.btree/BTreeValues.h"
#include "alinous.btree/KeyValue.h"
#include "alinous.btree/BTreeLeafNode.h"
#include "alinous.btree/BTreeNodeLoader.h"
#include "alinous.btree/NodeRef.h"
#include "alinous.btree/BTreeLeafContainer.h"
#include "alinous.btree/IBTree.h"
#include "alinous.btree/TimestampValue.h"
#include "alinous.btree/IntKey.h"
#include "alinous.btree/IntValue.h"
#include "alinous.btree/LongValue.h"
#include "alinous.btree/StringValue.h"
#include "alinous.btree/DoubleValue.h"
#include "alinous.btree/LongKey.h"
#include "alinous.btree/StringKey.h"
#include "alinous.btree/DoubleKey.h"
#include "alinous.btree/TimestampKey.h"
#include "alinous.btree/KeyValueFactory.h"
#include "alinous.btree/BTree.h"
#include "alinous.btree/BTreeMachine.h"

namespace alinous {namespace btree {





const StringValue::ValueFetcher StringValue:: __fetcher = (StringValue::ValueFetcher(nullptr));
constexpr const int StringValue::BASE_SIZE;
bool StringValue::__init_done = __init_static_variables();
bool StringValue::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"StringValue", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 StringValue::StringValue(String* fetchString, ThreadContext* ctx) throw()  : IObject(ctx), IBTreeValue(ctx), value(nullptr)
{
	__GC_MV(this, &(this->value), fetchString, String);
}
void StringValue::__construct_impl(String* fetchString, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->value), fetchString, String);
}
 StringValue::~StringValue() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void StringValue::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"StringValue", L"~StringValue");
	__e_obj1.add(this->value, this);
	value = nullptr;
	if(!prepare){
		return;
	}
}
int StringValue::diskSize(ThreadContext* ctx) throw() 
{
	return IBTreeValue::TYPE_SIZE + BASE_SIZE + (value->length(ctx) * 2);
}
void StringValue::appendToEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx) throw() 
{
	builder->putInt(IBTreeValue::TYPE_INT, ctx);
	builder->putString(value, ctx);
}
bool StringValue::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	return this->value->equals(obj, ctx);
}
IValueFetcher* StringValue::getFetcher(ThreadContext* ctx) throw() 
{
	return StringValue::fetcher;
}
}}

namespace alinous {namespace btree {





bool StringValue::ValueFetcher::__init_done = __init_static_variables();
bool StringValue::ValueFetcher::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"StringValue::ValueFetcher", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 StringValue::ValueFetcher::~ValueFetcher() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void StringValue::ValueFetcher::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IBTreeValue* StringValue::ValueFetcher::valueFromFetcher(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) throw() 
{
	IBTreeValue* value = (new(ctx) StringValue(fetcher->fetchString(ctx), ctx));
	return value;
}
}}


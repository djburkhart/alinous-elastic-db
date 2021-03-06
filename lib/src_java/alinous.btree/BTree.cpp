#include "include/global.h"


#include "alinous.buffer/FifoElement.h"
#include "alinous.buffer.storage/FileStorageEntry.h"
#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.lock/LockObject.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "java.lang/Comparable.h"
#include "alinous.btree/IBTreeKey.h"
#include "alinous.btree.scan/INodeIterator.h"
#include "alinous.lock/ConcurrentGate.h"
#include "alinous.buffer.storage/FileStorageBlock.h"
#include "alinous.buffer.storage/IFileStorage.h"
#include "alinous.buffer.storage/FileStorageEntryWriter.h"
#include "alinous.buffer.storage/FileStorageEntryReader.h"
#include "alinous.buffer.storage/FileStorage.h"
#include "alinous.buffer/FifoList.h"
#include "alinous.buffer/FifoIterator.h"
#include "alinous.btree/BTreeCacheArray.h"
#include "alinous.btree/BTreeException.h"
#include "alinous.buffer/HashArrayList.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.btree/IBTreeNode.h"
#include "alinous.btree/BTreeCacheRecord.h"
#include "alinous.btree/BTreeGlobalCache.h"
#include "alinous.btree.scan/AbstractNodeIterator.h"
#include "alinous.btree.scan/NodeIterator.h"
#include "alinous.btree/AbstractNode.h"
#include "alinous.btree/BTreeNodeHandler.h"
#include "alinous.btree/AbstractBTreeNode.h"
#include "alinous.btree/BTreeNode.h"
#include "alinous.btree.scan/MaxNodeIterator.h"
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





bool BTree::__init_done = __init_static_variables();
bool BTree::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"BTree", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 BTree::BTree(ThreadContext* ctx) throw()  : IObject(ctx), IBTree(ctx), root(0), storage(nullptr), nodeCapacity(0), keyType(0), valueType(0), loader(nullptr), fetcher(nullptr), gate(nullptr)
{
}
void BTree::__construct_impl(ThreadContext* ctx) throw() 
{
}
 BTree::~BTree() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void BTree::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"BTree", L"~BTree");
	__e_obj1.add(this->storage, this);
	storage = nullptr;
	__e_obj1.add(this->loader, this);
	loader = nullptr;
	__e_obj1.add(this->fetcher, this);
	fetcher = nullptr;
	__e_obj1.add(this->gate, this);
	gate = nullptr;
	if(!prepare){
		return;
	}
}
void BTree::closeGate(ThreadContext* ctx)
{
	this->gate->close(ctx);
}
void BTree::openGate(ThreadContext* ctx)
{
	this->gate->open(ctx);
}
void BTree::enterGate(ThreadContext* ctx)
{
	this->gate->enter(ctx);
}
void BTree::exitGate(ThreadContext* ctx) throw() 
{
	this->gate->exit(ctx);
}
BTree* BTree::init(File* file, BTreeGlobalCache* cacheEngine, DiskCacheManager* diskCache, ThreadContext* ctx)
{
	__GC_MV(this, &(this->storage), (new(ctx) FileStorage(diskCache, file, ConstStr::getCNST_STR_1670(), ctx)), FileStorage);
	__GC_MV(this, &(this->loader), (new(ctx) BTreeNodeLoader(this->storage, cacheEngine, ctx)), BTreeNodeLoader);
	this->root = 0;
	__GC_MV(this, &(this->fetcher), (new(ctx) FileStorageEntryFetcher(ctx)), FileStorageEntryFetcher);
	return this;
}
ArrayList<IBTreeValue>* BTree::getValues(IBTreeKey* key, ThreadContext* ctx)
{
	if(this->root == (long long)0)
	{
		return nullptr;
	}
	IBTreeNode* node = findByKey(key, ctx);
	if(node == nullptr)
	{
		return nullptr;
	}
	ArrayList<IBTreeValue>* values = node->getValues(ctx);
	node->endUse(ctx);
	return values;
}
bool BTree::putUniqueKeyValue(IBTreeKey* key, IBTreeValue* value, ThreadContext* ctx)
{
	if(this->root == (long long)0)
	{
		putRooNode(ctx);
	}
	IBTreeNode* node = findByKey(key, ctx);
	if(node != nullptr)
	{
		return false;
	}
	node = internalPutKey(key, ctx);
	ArrayList<IBTreeValue>* values = node->getValues(ctx);
	if(values->contains(value, ctx))
	{
		values->remove(value, ctx);
	}
	values->add(value, ctx);
	this->loader->saveBTreeNode(node, ctx);
	node->endUse(ctx);
	return true;
}
void BTree::appendKeyValue(IBTreeKey* key, IBTreeValue* value, ThreadContext* ctx)
{
	if(this->root == (long long)0)
	{
		putRooNode(ctx);
	}
	IBTreeNode* node = findByKey(key, ctx);
	if(node == nullptr)
	{
		node = internalPutKey(key, ctx);
	}
	ArrayList<IBTreeValue>* values = node->getValues(ctx);
	values->add(value, ctx);
	this->loader->saveBTreeNode(node, ctx);
	node->endUse(ctx);
}
void BTree::putKeyValue(IBTreeKey* key, IBTreeValue* value, ThreadContext* ctx)
{
	if(this->root == (long long)0)
	{
		putRooNode(ctx);
	}
	IBTreeNode* node = findByKey(key, ctx);
	if(node == nullptr)
	{
		node = internalPutKey(key, ctx);
	}
	ArrayList<IBTreeValue>* values = node->getValues(ctx);
	if(values->contains(value, ctx))
	{
		values->remove(value, ctx);
	}
	values->add(value, ctx);
	this->loader->saveBTreeNode(node, ctx);
	node->endUse(ctx);
}
IBTreeNode* BTree::findByKey(IBTreeKey* key, ThreadContext* ctx)
{
	if(this->root == (long long)0)
	{
		return nullptr;
	}
	IBTreeNode* node = this->getRootNode(ctx);
	IBTreeNode* lastNode = nullptr;
	while(!node->isHasLeaf(ctx))
	{
		lastNode = node;
		node = node->getNodeAtInsertPosition(key, ctx);
		node->use(ctx);
		lastNode->endUse(ctx);
	}
	lastNode = node;
	IBTreeNode* leaf = node->getNodeAtInsertPosition(key, ctx);
	lastNode->endUse(ctx);
	if(leaf == nullptr)
	{
		return nullptr;
	}
	leaf->use(ctx);
	if(leaf->getKey(ctx)->equals(key, ctx))
	{
		return leaf;
	}
	leaf->endUse(ctx);
	return nullptr;
}
void BTree::putKey(IBTreeKey* key, ThreadContext* ctx)
{
	if(this->root == (long long)0)
	{
		putRooNode(ctx);
	}
	BTreeLeafNode* newNode = this->loader->newLeafNode(key, ctx);
	IBTreeNode* rootObj = getRootNode(ctx);
	BTreeMachine* machine = (new(ctx) BTreeMachine(rootObj, this, ctx));
	machine->insertLeaf(newNode, ctx);
	newNode->endUse(ctx);
	rootObj->endUse(ctx);
	machine->destroy(ctx);
}
void BTree::removeKey(IBTreeKey* key, ThreadContext* ctx)
{
	if(this->root == (long long)0)
	{
		return;
	}
	IBTreeNode* rootObj = nullptr;
	{
		try
		{
			rootObj = getRootNode(ctx);
			BTreeMachine* machine = (new(ctx) BTreeMachine(rootObj, this, ctx));
			machine->removeKey(key, ctx);
		}
		catch(Throwable* e)
		{
			if(rootObj != nullptr)
			{
				rootObj->endUse(ctx);
			}
			throw e;
		}
	}
	if(rootObj != nullptr)
	{
		rootObj->endUse(ctx);
	}
}
void BTree::saveNode(IBTreeNode* node, ThreadContext* ctx)
{
	this->loader->saveBTreeNode(node, ctx);
}
IBTreeNode* BTree::getRootNode(ThreadContext* ctx)
{
	IBTreeNode* node = this->loader->loadBTreeNode(this->root, ctx);
	return node;
}
void BTree::initTreeStorage(int nodeCapacity, int keyType, int valueType, long long capacity, long long BLOCK_SIZE, ThreadContext* ctx)
{
	if(capacity < (long long)256)
	{
		capacity = 256;
	}
	this->nodeCapacity = nodeCapacity;
	this->keyType = keyType;
	this->valueType = valueType;
	this->storage->createStorage(capacity, BLOCK_SIZE, ctx);
	{
		try
		{
			this->storage->open(ctx);
			updateMasterSection(ctx);
		}
		catch(Throwable* e)
		{
			this->storage->close(ctx);
			throw e;
		}
	}
	this->storage->close(ctx);
}
void BTree::open(ThreadContext* ctx)
{
	if(!this->storage->isCreated(ctx))
	{
		throw (new(ctx) BTreeException(ConstStr::getCNST_STR_1671(), ctx));
	}
	this->storage->open(ctx);
	this->loader->open(ctx);
	loadStorageinfo(ctx);
	__GC_MV(this, &(this->gate), (new(ctx) ConcurrentGate(ctx)), ConcurrentGate);
}
void BTree::printNode(StringBuffer* buff, ThreadContext* ctx)
{
	IBTreeNode* rootNode = getRootNode(ctx);
	rootNode->printNode(buff, 0, ctx);
	rootNode->endUse(ctx);
}
bool BTree::isOpened(ThreadContext* ctx) throw() 
{
	return this->storage->isOpened(ctx);
}
void BTree::close(ThreadContext* ctx)
{
	{
		try
		{
			updateMasterSection(ctx);
			this->loader->close(ctx);
			this->storage->close(ctx);
		}
		catch(Throwable* e)
		{
			this->gate->close(ctx);
			throw e;
		}
	}
	this->gate->close(ctx);
}
void BTree::assertCache(ThreadContext* ctx)
{
	this->loader->assertCache(ctx);
}
void BTree::updateMasterSection(ThreadContext* ctx)
{
	FileStorageEntryBuilder* builder = (new(ctx) FileStorageEntryBuilder(ctx));
	builder->putInt(this->nodeCapacity, ctx);
	builder->putLong(this->root, ctx);
	builder->putInt(this->keyType, ctx);
	builder->putInt(this->valueType, ctx);
	FileStorageEntryWriter* writer = this->storage->getWriter(ctx);
	FileStorageEntry* entry = builder->toEntry((long long)FileStorage::DATA_BEGIN, ctx);
	writer->write(entry, ctx);
}
bool BTree::isEmpty(ThreadContext* ctx) throw() 
{
	return this->root == (long long)0;
}
long long BTree::getRoot(ThreadContext* ctx) throw() 
{
	return root;
}
void BTree::setRoot(long long root, ThreadContext* ctx) throw() 
{
	this->root = root;
}
BTreeNodeLoader* BTree::getLoader(ThreadContext* ctx) throw() 
{
	return loader;
}
int BTree::getNodeCapacity(ThreadContext* ctx) throw() 
{
	return nodeCapacity;
}
BTreeLeafNode* BTree::internalPutKey(IBTreeKey* key, ThreadContext* ctx)
{
	BTreeLeafNode* newNode = this->loader->newLeafNode(key, ctx);
	IBTreeNode* rootObj = getRootNode(ctx);
	BTreeMachine* machine = (new(ctx) BTreeMachine(rootObj, this, ctx));
	machine->insertLeaf(newNode, ctx);
	rootObj->endUse(ctx);
	machine->destroy(ctx);
	return newNode;
}
void BTree::putRooNode(ThreadContext* ctx)
{
	IBTreeNode* node = this->loader->newBTreeMaxLeafContainer(this->nodeCapacity, ctx);
	this->root = node->getFilePointer(ctx);
	node->endUse(ctx);
}
void BTree::loadStorageinfo(ThreadContext* ctx)
{
	FileStorageEntryReader* reader = this->storage->getReader(ctx);
	FileStorageEntry* entry = reader->read((long long)FileStorage::DATA_BEGIN, ctx);
	this->fetcher->load(entry, ctx);
	this->nodeCapacity = this->fetcher->fetchInt(ctx);
	this->root = this->fetcher->fetchLong(ctx);
	this->keyType = this->fetcher->fetchInt(ctx);
	this->valueType = this->fetcher->fetchInt(ctx);
	this->fetcher->close(ctx);
}
void BTree::__cleanUp(ThreadContext* ctx){
}
}}


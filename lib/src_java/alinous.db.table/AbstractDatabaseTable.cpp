#include "includes.h"


namespace alinous {namespace db {namespace table {





bool AbstractDatabaseTable::__init_done = __init_static_variables();
bool AbstractDatabaseTable::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AbstractDatabaseTable", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AbstractDatabaseTable::AbstractDatabaseTable(String* schema, String* name, String* baseDir, ThreadContext* ctx) throw()  : IObject(ctx), tableId(nullptr), metadata(nullptr), indexes(GCUtils<ArrayList<TableIndex> >::ins(this, (new(ctx) ArrayList<TableIndex>(ctx)), ctx, __FILEW__, __LINE__, L"")), primaryIndex(nullptr), name(nullptr), baseDir(nullptr), oidIndexPath(nullptr), dataStoragePath(nullptr), oidIndex(nullptr), dataStorage(nullptr), storageLock(nullptr), schmeUpdated(nullptr), updateHistoryCache(nullptr)
{
	__GC_MV(this, &(this->tableId), (new(ctx) Integer(DatabaseTableIdPublisher::getId(name, ctx), ctx)), Integer);
	__GC_MV(this, &(this->metadata), (new(ctx) TableMetadata(schema, name, ctx)), TableMetadata);
	__GC_MV(this, &(this->name), name, String);
	__GC_MV(this, &(this->baseDir), baseDir, String);
	__GC_MV(this, &(this->oidIndex), nullptr, BTree);
	getDataStorageName(ctx);
	getOidIndexName(ctx);
	__GC_MV(this, &(this->storageLock), (new(ctx) ConcurrentGate(ctx)), ConcurrentGate);
	__GC_MV(this, &(this->schmeUpdated), (new(ctx) Timestamp(System::currentTimeMillis(ctx), ctx)), Timestamp);
	__GC_MV(this, &(this->updateHistoryCache), nullptr, DatatableUpdateCache);
}
void AbstractDatabaseTable::__construct_impl(String* schema, String* name, String* baseDir, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->tableId), (new(ctx) Integer(DatabaseTableIdPublisher::getId(name, ctx), ctx)), Integer);
	__GC_MV(this, &(this->metadata), (new(ctx) TableMetadata(schema, name, ctx)), TableMetadata);
	__GC_MV(this, &(this->name), name, String);
	__GC_MV(this, &(this->baseDir), baseDir, String);
	__GC_MV(this, &(this->oidIndex), nullptr, BTree);
	getDataStorageName(ctx);
	getOidIndexName(ctx);
	__GC_MV(this, &(this->storageLock), (new(ctx) ConcurrentGate(ctx)), ConcurrentGate);
	__GC_MV(this, &(this->schmeUpdated), (new(ctx) Timestamp(System::currentTimeMillis(ctx), ctx)), Timestamp);
	__GC_MV(this, &(this->updateHistoryCache), nullptr, DatatableUpdateCache);
}
 AbstractDatabaseTable::~AbstractDatabaseTable() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AbstractDatabaseTable::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AbstractDatabaseTable", L"~AbstractDatabaseTable");
	__e_obj1.add(this->tableId, this);
	tableId = nullptr;
	__e_obj1.add(this->metadata, this);
	metadata = nullptr;
	__e_obj1.add(this->indexes, this);
	indexes = nullptr;
	__e_obj1.add(this->primaryIndex, this);
	primaryIndex = nullptr;
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->baseDir, this);
	baseDir = nullptr;
	__e_obj1.add(this->oidIndexPath, this);
	oidIndexPath = nullptr;
	__e_obj1.add(this->dataStoragePath, this);
	dataStoragePath = nullptr;
	__e_obj1.add(this->oidIndex, this);
	oidIndex = nullptr;
	__e_obj1.add(this->dataStorage, this);
	dataStorage = nullptr;
	__e_obj1.add(this->storageLock, this);
	storageLock = nullptr;
	__e_obj1.add(this->schmeUpdated, this);
	schmeUpdated = nullptr;
	__e_obj1.add(this->updateHistoryCache, this);
	updateHistoryCache = nullptr;
	if(!prepare){
		return;
	}
}
void AbstractDatabaseTable::open(AlinousDatabase* database, ThreadContext* ctx)
{
	getDataStorageName(ctx);
	getOidIndexName(ctx);
	__GC_MV(this, &(this->dataStorage), (new(ctx) FileStorage(database->getCore(ctx)->diskCache, (new(ctx) File(dataStoragePath, ctx)), ConstStr::getCNST_STR_1551(), ctx)), FileStorage);
	{
		try
		{
			__GC_MV(this, &(this->oidIndex), (new(ctx) BTree(ctx))->init((new(ctx) File(this->oidIndexPath, ctx)), database->getBtreeCache(ctx), database->getCore(ctx)->diskCache, ctx), BTree);
		}
		catch(Throwable* e)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1566(), e, ctx));
		}
	}
	__GC_MV(this, &(this->updateHistoryCache), (new(ctx) DatatableUpdateCache(this, ctx)), DatatableUpdateCache);
	open(true, database, ctx);
}
void AbstractDatabaseTable::open(bool loadscheme, AlinousDatabase* database, ThreadContext* ctx)
{
	{
		try
		{
			this->dataStorage->open(ctx);
			this->oidIndex->open(ctx);
			this->updateHistoryCache->open(database, ctx);
		}
		catch(IOException* e)
		{
			throw (new(ctx) DatabaseException(e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) DatabaseException(e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) DatabaseException(e, ctx));
		}
	}
	if(loadscheme)
	{
		{
			try
			{
				loadScheme(ctx);
			}
			catch(IOException* e)
			{
				throw (new(ctx) DatabaseException(e, ctx));
			}
			catch(AlinousDbException* e)
			{
				throw (new(ctx) DatabaseException(e, ctx));
			}
			catch(InterruptedException* e)
			{
				throw (new(ctx) DatabaseException(e, ctx));
			}
		}
	}
	{
		try
		{
			this->primaryIndex->open(database, ctx);
			int maxLoop = this->indexes->size(ctx);
			for(int i = 0; i != maxLoop; ++i)
			{
				TableIndex* index = this->indexes->get(i, ctx);
				index->open(database, ctx);
			}
		}
		catch(IOException* e)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1573(), e, ctx));
		}
		catch(BTreeException* e)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1573(), e, ctx));
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1573(), e, ctx));
		}
	}
}
void AbstractDatabaseTable::close(ThreadContext* ctx) throw() 
{
	{
		try
		{
			syncScheme(ctx);
		}
		catch(VariableException* e1)
		{
			e1->printStackTrace(ctx);
		}
		catch(IOException* e1)
		{
			e1->printStackTrace(ctx);
		}
		catch(InterruptedException* e1)
		{
			e1->printStackTrace(ctx);
		}
	}
	if(this->dataStorage != nullptr && this->dataStorage->isOpened(ctx))
	{
		this->dataStorage->close(ctx);
	}
	if(this->oidIndex != nullptr && this->oidIndex->isOpened(ctx))
	{
		{
			try
			{
				this->oidIndex->close(ctx);
			}
			catch(IOException* e)
			{
				e->printStackTrace(ctx);
			}
			catch(InterruptedException* e)
			{
				e->printStackTrace(ctx);
			}
		}
	}
	{
		try
		{
			this->primaryIndex->close(ctx);
			int maxLoop = this->indexes->size(ctx);
			for(int i = 0; i != maxLoop; ++i)
			{
				TableIndex* index = this->indexes->get(i, ctx);
				index->close(ctx);
			}
		}
		catch(IOException* e)
		{
			e->printStackTrace(ctx);
		}
		catch(InterruptedException* e)
		{
			e->printStackTrace(ctx);
		}
	}
	this->updateHistoryCache->close(ctx);
	this->storageLock->dispose(ctx);
}
TableMetadata* AbstractDatabaseTable::getMetadata(ThreadContext* ctx) throw() 
{
	return metadata;
}
ArrayList<TableIndex>* AbstractDatabaseTable::getIndexes(ThreadContext* ctx) throw() 
{
	return indexes;
}
String* AbstractDatabaseTable::getName(ThreadContext* ctx) throw() 
{
	return name;
}
String* AbstractDatabaseTable::getSchemaName(ThreadContext* ctx) throw() 
{
	return this->metadata->getSchema(ctx);
}
String* AbstractDatabaseTable::getBaseDir(ThreadContext* ctx) throw() 
{
	return baseDir;
}
bool AbstractDatabaseTable::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	return (dynamic_cast<DatabaseTable*>(obj))->tableId->intValue(ctx) == this->tableId->intValue(ctx);
}
Timestamp* AbstractDatabaseTable::getSchmeUpdated(ThreadContext* ctx) throw() 
{
	return schmeUpdated;
}
DatatableUpdateCache* AbstractDatabaseTable::getUpdateHistoryCache(ThreadContext* ctx) throw() 
{
	return updateHistoryCache;
}
TableIndex* AbstractDatabaseTable::getPrimaryIndex(ThreadContext* ctx) throw() 
{
	return primaryIndex;
}
int AbstractDatabaseTable::getColumnCount(ThreadContext* ctx) throw() 
{
	return this->metadata->getColumnCount(ctx);
}
FileStorage* AbstractDatabaseTable::getDataStorage(ThreadContext* ctx) throw() 
{
	return dataStorage;
}
BTree* AbstractDatabaseTable::getOidIndex(ThreadContext* ctx) throw() 
{
	return oidIndex;
}
void AbstractDatabaseTable::syncScheme(ThreadContext* ctx)
{
	FileStorageEntryWriter* writer = this->dataStorage->getWriter(ctx);
	int cap = this->metadata->fileSize(ctx);
	cap += indexSchemeSize(ctx);
	cap += 8;
	FileStorageEntryBuilder* builder = (new(ctx) FileStorageEntryBuilder(cap, ctx));
	this->metadata->toFileEntry(builder, ctx);
	syncIndexScheme(builder, ctx);
	builder->putLong(this->schmeUpdated->getTime(ctx), ctx);
	FileStorageEntry* entry = builder->toEntry((long long)FileStorage::DATA_BEGIN, ctx);
	writer->write(entry, ctx);
	writer->end(ctx);
}
String* AbstractDatabaseTable::getDataStorageName(ThreadContext* ctx) throw() 
{
	if(this->dataStoragePath == nullptr)
	{
		StringBuilder* buff = (new(ctx) StringBuilder(ctx));
		buff->append(this->baseDir, ctx);
		if(!this->baseDir->endsWith(ConstStr::getCNST_STR_984(), ctx))
		{
			buff->append(ConstStr::getCNST_STR_984(), ctx);
		}
		buff->append(this->name, ctx)->append(ConstStr::getCNST_STR_1574(), ctx);
		__GC_MV(this, &(this->dataStoragePath), buff->toString(ctx), String);
	}
	return this->dataStoragePath;
}
int AbstractDatabaseTable::indexSchemeSize(ThreadContext* ctx) throw() 
{
	int total = this->primaryIndex->archiveSize(ctx);
	total += 4;
	int maxLoop = this->indexes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableIndex* index = this->indexes->get(i, ctx);
		total += index->archiveSize(ctx);
	}
	return total;
}
void AbstractDatabaseTable::syncIndexScheme(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	this->primaryIndex->appendToEntry(builder, ctx);
	int maxLoop = this->indexes->size(ctx);
	builder->putInt(maxLoop, ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableIndex* index = this->indexes->get(i, ctx);
		index->appendToEntry(builder, ctx);
	}
}
void AbstractDatabaseTable::loadScheme(ThreadContext* ctx)
{
	FileStorageEntryReader* reader = 0;
	{
		try
		{
			reader = this->dataStorage->getReader(ctx);
		}
		catch(InterruptedException* e)
		{
			throw (new(ctx) AlinousDbException(ConstStr::getCNST_STR_1575(), e, ctx));
		}
	}
	FileStorageEntry* entry = reader->readFirstEntry(ctx);
	FileStorageEntryFetcher* fetcher = (new(ctx) FileStorageEntryFetcher(entry, ctx));
	__GC_MV(this, &(this->metadata), TableMetadata::loadFromFetcher(fetcher, ctx), TableMetadata);
	loadIndexes(fetcher, ctx);
	long long mills = fetcher->fetchLong(ctx);
	__GC_MV(this, &(this->schmeUpdated), (new(ctx) Timestamp(mills, ctx)), Timestamp);
	fetcher->close(ctx);
}
String* AbstractDatabaseTable::getOidIndexName(ThreadContext* ctx) throw() 
{
	if(this->oidIndexPath == nullptr)
	{
		StringBuilder* buff = (new(ctx) StringBuilder(ctx));
		buff->append(this->baseDir, ctx);
		if(!this->baseDir->endsWith(ConstStr::getCNST_STR_984(), ctx))
		{
			buff->append(ConstStr::getCNST_STR_984(), ctx);
		}
		buff->append(ConstStr::getCNST_STR_1567(), ctx)->append(this->name, ctx)->append(ConstStr::getCNST_STR_1576(), ctx);
		__GC_MV(this, &(this->oidIndexPath), buff->toString(ctx), String);
	}
	return this->oidIndexPath;
}
void AbstractDatabaseTable::loadIndexes(FileStorageEntryFetcher* fetcher, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->primaryIndex), TableIndex::valueFromFetcher(fetcher, this->baseDir, ctx), TableIndex);
	int maxLoop = fetcher->fetchInt(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		TableIndex* index = TableIndex::valueFromFetcher(fetcher, this->baseDir, ctx);
		this->indexes->add(index, ctx);
	}
}
}}}


#ifndef ALINOUS_DB_TABLE_IDATABASETABLE_H_
#define ALINOUS_DB_TABLE_IDATABASETABLE_H_
namespace java {namespace lang {
class Integer;}}

namespace alinous {namespace db {namespace table {
class IScannableIndex;}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableColumnIdentifier;}}}}

namespace alinous {namespace db {namespace table {
class TableMetadata;}}}

namespace alinous {namespace db {namespace table {
class IDatabaseRecord;}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class IThreadLocker;}}}}

namespace alinous {namespace system {
class AlinousCore;}}

namespace alinous {namespace btree {
class BTreeGlobalCache;}}

namespace alinous {namespace runtime {namespace parallel {
class ThreadPool;}}}

namespace alinous {namespace db {namespace trx {
class DbTransaction;}}}

namespace alinous {namespace runtime {namespace parallel {
class SequentialBackgroundJob;}}}

namespace alinous {namespace system {
class ISystemLog;}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace db {namespace table {
class TableColumnMetadata;}}}

namespace alinous {namespace remote {namespace region {namespace client {namespace command {
class AbstractNodeRegionCommand;}}}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class DatabaseLockException;}}}}

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

namespace alinous {namespace db {namespace table {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::util::ArrayList;
using ::java::util::List;
using ::alinous::btree::BTreeException;
using ::alinous::btree::BTreeGlobalCache;
using ::alinous::compile::sql::analyze::ScanTableColumnIdentifier;
using ::alinous::db::AlinousDbException;
using ::alinous::db::table::lockmonitor::DatabaseLockException;
using ::alinous::db::table::lockmonitor::IThreadLocker;
using ::alinous::db::trx::DbTransaction;
using ::alinous::remote::region::client::command::AbstractNodeRegionCommand;
using ::alinous::runtime::dom::VariableException;
using ::alinous::runtime::parallel::SequentialBackgroundJob;
using ::alinous::runtime::parallel::ThreadPool;
using ::alinous::system::AlinousCore;
using ::alinous::system::AlinousException;
using ::alinous::system::ISystemLog;



class IDatabaseTable : public virtual IObject {
public:
	IDatabaseTable(const IDatabaseTable& base) = default;
public:
	IDatabaseTable(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~IDatabaseTable() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	virtual Integer* getTableId(ThreadContext* ctx) throw()  = 0;
	virtual int getColumnCount(ThreadContext* ctx) throw()  = 0;
	virtual IScannableIndex* getTableIndexByColIds(ArrayList<ScanTableColumnIdentifier>* colIdList, ThreadContext* ctx) throw()  = 0;
	virtual IScannableIndex* getPrimaryIndex(ThreadContext* ctx) throw()  = 0;
	virtual TableMetadata* getMetadata(ThreadContext* ctx) throw()  = 0;
	virtual IDatabaseRecord* loadRecord(long long position, ThreadContext* ctx) = 0;
	virtual IScannableIndex* getAbailableIndex(ArrayList<String>* columnsStr, ThreadContext* ctx) throw()  = 0;
	virtual IScannableIndex* getAbailableIndexByScanColId(ArrayList<ScanTableColumnIdentifier>* joinRequest, ThreadContext* ctx) throw()  = 0;
	virtual IScannableIndex* getTableIndex(ArrayList<String>* columns, ThreadContext* ctx) throw()  = 0;
	virtual IThreadLocker* newThreadLocker(String* fullName, ThreadContext* ctx) throw()  = 0;
	virtual void updateUnlockRow(long long oid, IThreadLocker* locker, ThreadContext* ctx) = 0;
	virtual void updateLockRow(long long oid, IThreadLocker* locker, ThreadContext* ctx) = 0;
	virtual void shareUnlockRow(long long oid, IThreadLocker* locker, ThreadContext* ctx) = 0;
	virtual void shareLockRow(long long oid, IThreadLocker* locker, ThreadContext* ctx) = 0;
	virtual void shareUnlockTable(IThreadLocker* locker, ThreadContext* ctx) = 0;
	virtual void shareLockTable(IThreadLocker* locker, ThreadContext* ctx) = 0;
	virtual void updateUnlockTable(IThreadLocker* locker, ThreadContext* ctx) = 0;
	virtual void updateLockTable(IThreadLocker* locker, ThreadContext* ctx) = 0;
	virtual bool hasLaterVersion(long long oid, long long currentId, ThreadContext* ctx) = 0;
	virtual bool hasLaterVersionBefore(long long oid, long long maxCommitId, long long currentCommitId, ThreadContext* ctx) = 0;
	virtual String* getName(ThreadContext* ctx) throw()  = 0;
	virtual void open(AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx) = 0;
	virtual void createTable(TableMetadata* metadata, ThreadPool* threadPool, AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx) = 0;
	virtual void lockStorage(ThreadContext* ctx) = 0;
	virtual void unlockStorage(ThreadContext* ctx) = 0;
	virtual ArrayList<IScannableIndex>* getIndexes(ThreadContext* ctx) throw()  = 0;
	virtual void insertData(DbTransaction* trx, IDatabaseRecord* record, long long newCommitId, IArrayObject<SequentialBackgroundJob>* jobs, ISystemLog* logger, ThreadContext* ctx) = 0;
	virtual void insertData(DbTransaction* trx, List<IDatabaseRecord>* records, long long newCommitId, IArrayObject<SequentialBackgroundJob>* jobs, ISystemLog* logger, ThreadContext* ctx) = 0;
	virtual void updateData(IDatabaseRecord* record, long long newCommitId, IArrayObject<SequentialBackgroundJob>* jobs, ISystemLog* logger, ThreadContext* ctx) = 0;
	virtual void createIndex(String* getindexName, ArrayList<String>* columns, AlinousCore* core, BTreeGlobalCache* cache, ThreadContext* ctx) = 0;
	virtual void close(ThreadContext* ctx) throw()  = 0;
	virtual String* getFullName(ThreadContext* ctx) throw()  = 0;
	virtual void finishCommitSession(DbTransaction* trx, long long newCommitId, ThreadContext* ctx) = 0;
	virtual void cleanSelectLocks(DbTransaction* trx, long long newCommitId, ThreadContext* ctx) = 0;
	virtual IScannableIndex* getTableUniqueIndexByCols(List<TableColumnMetadata>* columns, ThreadContext* ctx) throw()  = 0;
	virtual void tcpInsertCommit(IDatabaseRecord* data, IArrayObject<SequentialBackgroundJob>* jobs, ISystemLog* log, ThreadContext* ctx) = 0;
	virtual long long getNextOid(ThreadContext* ctx) throw()  = 0;
	virtual void setNextOid(long long nextOid, ThreadContext* ctx) throw()  = 0;
	virtual AbstractNodeRegionCommand* sendCommand(AbstractNodeRegionCommand* cmd, ThreadContext* ctx) = 0;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_DB_TABLE_IDATABASETABLE_H_ */

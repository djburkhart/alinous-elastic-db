#ifndef ALINOUS_DB_TABLE_SCAN_TABLEFULLSCANNER_H_
#define ALINOUS_DB_TABLE_SCAN_TABLEFULLSCANNER_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace db {namespace table {namespace scan {
class TableFullScanner;}}}}

namespace alinous {namespace compile {namespace sql {namespace analyze {
class ScanTableIdentifier;}}}}

namespace alinous {namespace db {namespace trx {
class DbTransaction;}}}

namespace alinous {namespace db {namespace table {
class DatabaseTable;}}}

namespace alinous {namespace btree {namespace scan {
class BTreeScanner;}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultIndexKey;}}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanException;}}}}

namespace alinous {namespace runtime {namespace dom {
class VariableException;}}}

namespace java {namespace io {
class IOException;}}

namespace java {namespace lang {
class InterruptedException;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace system {
class AlinousException;}}

namespace alinous {namespace db {namespace table {
class DatabaseRecord;}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ScanResultRecord;}}}}

namespace alinous {namespace btree {
class IBTreeNode;}}

namespace alinous {namespace db {namespace table {
class TableIndexValue;}}}

namespace alinous {namespace db {namespace table {
class DatabaseException;}}}

namespace java {namespace lang {
class Throwable;}}

namespace alinous {namespace system {
class ISystemLog;}}

namespace alinous {namespace db {namespace table {
class TableIndex;}}}

namespace alinous {namespace btree {
class BTree;}}

namespace alinous {namespace btree {
class IBTreeValue;}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class ThreadLocker;}}}}

namespace alinous {namespace db {namespace trx {namespace scan {
class ITableTargetScanner;}}}}

namespace alinous {namespace db {namespace table {
class IDatabaseRecord;}}}

namespace alinous {namespace db {namespace table {namespace lockmonitor {
class DatabaseLockException;}}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace db {namespace table {namespace scan {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::io::IOException;
using ::java::util::ArrayList;
using ::alinous::btree::BTree;
using ::alinous::btree::BTreeException;
using ::alinous::btree::IBTreeNode;
using ::alinous::btree::IBTreeValue;
using ::alinous::btree::scan::BTreeScanner;
using ::alinous::compile::sql::analyze::ScanTableIdentifier;
using ::alinous::db::table::DatabaseException;
using ::alinous::db::table::DatabaseRecord;
using ::alinous::db::table::DatabaseTable;
using ::alinous::db::table::IDatabaseRecord;
using ::alinous::db::table::TableIndex;
using ::alinous::db::table::TableIndexValue;
using ::alinous::db::table::lockmonitor::DatabaseLockException;
using ::alinous::db::table::lockmonitor::ThreadLocker;
using ::alinous::db::trx::DbTransaction;
using ::alinous::db::trx::scan::ITableTargetScanner;
using ::alinous::db::trx::scan::ScanException;
using ::alinous::db::trx::scan::ScanResultIndexKey;
using ::alinous::db::trx::scan::ScanResultRecord;
using ::alinous::runtime::dom::VariableException;
using ::alinous::system::AlinousException;
using ::alinous::system::ISystemLog;



class TableFullScanner final : public ITableTargetScanner, public virtual IObject {
public:
	TableFullScanner(const TableFullScanner& base) = default;
public:
	TableFullScanner(ThreadContext* ctx) throw()  : IObject(ctx), ITableTargetScanner(ctx), trx(nullptr), index(nullptr), storage(nullptr), scanner(nullptr), tableStore(nullptr), values(nullptr), current(0), lockMode(0), locker(nullptr), nextresult(nullptr), tableId(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~TableFullScanner() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	DbTransaction* trx;
	TableIndex* index;
	BTree* storage;
	BTreeScanner* scanner;
	DatabaseTable* tableStore;
	ArrayList<IBTreeValue>* values;
	int current;
	int lockMode;
	ThreadLocker* locker;
	ScanResultRecord* nextresult;
	ScanTableIdentifier* tableId;
public:
	TableFullScanner* init(ScanTableIdentifier* tableId, DbTransaction* trx, DatabaseTable* tableStore, int lockMode, ThreadContext* ctx);
	void startScan(ScanResultIndexKey* indexKeyValue, ThreadContext* ctx) final;
	bool hasNext(bool debug, ThreadContext* ctx) final;
	void endScan(ThreadContext* ctx) final;
	ScanResultRecord* next(bool debug, ThreadContext* ctx) final;
	void dispose(ISystemLog* core, ThreadContext* ctx) final;
private:
	bool loadNextRecord(ThreadContext* ctx);
	DatabaseRecord* nextIndexValue(ThreadContext* ctx);
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}}

#endif /* end of ALINOUS_DB_TABLE_SCAN_TABLEFULLSCANNER_H_ */

#ifndef ALINOUS_DB_TABLE_DATATABLEUPDATESUPPORT_H_
#define ALINOUS_DB_TABLE_DATATABLEUPDATESUPPORT_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace db {namespace table {
class IDatabaseRecord;}}}

namespace alinous {namespace runtime {namespace parallel {
class SequentialBackgroundJob;}}}

namespace alinous {namespace system {
class ISystemLog;}}

namespace alinous {namespace db {namespace table {
class DatabaseRecord;}}}

namespace alinous {namespace db {namespace trx {
class DbTransaction;}}}

namespace java {namespace util {
template <typename  T> class List;}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryWriter;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntryBuilder;}}}

namespace alinous {namespace buffer {namespace storage {
class FileStorageEntry;}}}

namespace alinous {namespace db {namespace table {
class OidIndexJob;}}}

namespace alinous {namespace db {namespace table {
class IndexInsertJob;}}}

namespace alinous {namespace db {namespace table {
class IScannableIndex;}}}

namespace alinous {namespace db {namespace table {
class DatatableDDLSupport;}}}

namespace java {namespace io {
class IOException;}}

namespace alinous {namespace btree {
class BTreeException;}}

namespace alinous {namespace db {
class AlinousDbException;}}

namespace alinous {namespace system {
class AlinousException;}}

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
using ::alinous::buffer::storage::FileStorageEntry;
using ::alinous::buffer::storage::FileStorageEntryBuilder;
using ::alinous::buffer::storage::FileStorageEntryWriter;
using ::alinous::db::AlinousDbException;
using ::alinous::db::trx::DbTransaction;
using ::alinous::runtime::parallel::SequentialBackgroundJob;
using ::alinous::system::AlinousException;
using ::alinous::system::ISystemLog;



class DatatableUpdateSupport : public DatatableDDLSupport {
public:
	DatatableUpdateSupport(const DatatableUpdateSupport& base) = default;
public:
	DatatableUpdateSupport(String* schema, String* name, String* baseDir, ThreadContext* ctx) throw() ;
	void __construct_impl(String* schema, String* name, String* baseDir, ThreadContext* ctx) throw() ;
	virtual ~DatatableUpdateSupport() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	void updateData(IDatabaseRecord* data, long long commitId, IArrayObject<SequentialBackgroundJob>* jobs, ISystemLog* log, ThreadContext* ctx) final;
	void insertData(DbTransaction* trx, IDatabaseRecord* data, long long commitId, IArrayObject<SequentialBackgroundJob>* jobs, ISystemLog* log, ThreadContext* ctx) final;
	void insertData(DbTransaction* trx, List<IDatabaseRecord>* records, long long newCommitId, IArrayObject<SequentialBackgroundJob>* jobs, ISystemLog* logger, ThreadContext* ctx) final;
	void tcpInsertCommit(IDatabaseRecord* dbrecord, IArrayObject<SequentialBackgroundJob>* jobs, ISystemLog* log, ThreadContext* ctx) final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_DB_TABLE_DATATABLEUPDATESUPPORT_H_ */

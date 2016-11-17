#include "includes.h"


namespace alinous {namespace compile {namespace sql {





bool CreateTableStatement::__init_done = __init_static_variables();
bool CreateTableStatement::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"CreateTableStatement", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 CreateTableStatement::~CreateTableStatement() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void CreateTableStatement::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"CreateTableStatement", L"~CreateTableStatement");
	__e_obj1.add(this->table, this);
	table = nullptr;
	__e_obj1.add(this->columns, this);
	columns = nullptr;
	__e_obj1.add(this->uniques, this);
	uniques = nullptr;
	__e_obj1.add(this->checks, this);
	checks = nullptr;
	__e_obj1.add(this->primaryKeys, this);
	primaryKeys = nullptr;
	__e_obj1.add(this->metadata, this);
	metadata = nullptr;
	if(!prepare){
		return;
	}
	AbstractSQLStatement::__releaseRegerences(true, ctx);
}
TableSchema* CreateTableStatement::createMetadata(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	TableJoinTarget* tbl = static_cast<TableJoinTarget*>(this->table);
	ArrayList<String>* segments = tbl->getName(ctx)->getSegments(ctx);
	String* schemeName = nullptr;
	String* tblName = nullptr;
	if(segments->size(ctx) == 1)
	{
		schemeName = ConstStr::getCNST_STR_951();
		tblName = segments->get(0, ctx);
	}
		else 
	{
		if(segments->size(ctx) == 2)
		{
			schemeName = segments->get(0, ctx);
			tblName = segments->get(1, ctx);
		}
	}
	TableSchema* schema = (new(ctx) TableSchema(schemeName, nullptr, ctx));
	TableMetadata* tblMetadata = (new(ctx) TableMetadata(tblName, ctx));
	schema->addTableMetadata(tblMetadata, ctx);
	int maxLoop = this->columns->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		DdlColumnDescriptor* colDesc = this->columns->get(i, ctx);
		TableColumnMetadata* colMeta = colDesc->toMetadata(machine, debug, ctx);
		tblMetadata->addColumn(colMeta, ctx);
	}
	ArrayList<String>* prims = this->primaryKeys->getColumns(ctx);
	maxLoop = prims->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* prim = prims->get(i, ctx);
		tblMetadata->addPrimaryKey(prim, ctx);
	}
	tblMetadata->setChecks(this->checks, ctx);
	return schema;
}
void CreateTableStatement::validate(SourceValidator* validator, ThreadContext* ctx) throw() 
{
	if(!((dynamic_cast<TableJoinTarget*>(this->table) != 0)))
	{
		validator->addError(ConstStr::getCNST_STR_1003(), this, ctx);
	}
		else 
	{
		TableJoinTarget* tbl = static_cast<TableJoinTarget*>(this->table);
		ArrayList<String>* segments = tbl->getName(ctx)->getSegments(ctx);
		if(segments->size(ctx) > 2)
		{
			validator->addError(ConstStr::getCNST_STR_1003(), this, ctx);
		}
	}
	int maxLoop = this->columns->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		DdlColumnDescriptor* colDesc = this->columns->get(i, ctx);
		colDesc->validate(validator, ctx);
	}
	if(this->primaryKeys == nullptr)
	{
		validator->addError(ConstStr::getCNST_STR_1004(), this, ctx);
	}
}
TableMetadata* CreateTableStatement::getMetadata(ThreadContext* ctx) throw() 
{
	return metadata;
}
bool CreateTableStatement::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->table != nullptr && !this->table->visit(visitor, this, ctx))
	{
		return false;
	}
	int max = this->columns->size(ctx);
	for(int i = 0; i != max; ++i)
	{
		if(!this->columns->get(i, ctx)->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	max = this->uniques->size(ctx);
	for(int i = 0; i != max; ++i)
	{
		if(!this->uniques->get(i, ctx)->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	max = this->checks->size(ctx);
	for(int i = 0; i != max; ++i)
	{
		if(!this->checks->get(i, ctx)->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	if(this->primaryKeys != nullptr && !this->primaryKeys->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool CreateTableStatement::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->table != nullptr)
	{
		this->table->analyse(context, leftValue, ctx);
	}
	int max = this->columns->size(ctx);
	for(int i = 0; i != max; ++i)
	{
		this->columns->get(i, ctx)->analyse(context, leftValue, ctx);
	}
	max = this->uniques->size(ctx);
	for(int i = 0; i != max; ++i)
	{
		this->uniques->get(i, ctx)->analyse(context, leftValue, ctx);
	}
	max = this->checks->size(ctx);
	for(int i = 0; i != max; ++i)
	{
		this->checks->get(i, ctx)->analyse(context, leftValue, ctx);
	}
	if(this->primaryKeys != nullptr)
	{
		this->primaryKeys->analyse(context, leftValue, ctx);
	}
	return true;
}
void CreateTableStatement::addColumn(DdlColumnDescriptor* col, ThreadContext* ctx) throw() 
{
	this->columns->add(col, ctx);
}
void CreateTableStatement::addUnique(Unique* unique, ThreadContext* ctx) throw() 
{
	this->uniques->add(unique, ctx);
}
void CreateTableStatement::addCheckDef(CheckDefinition* def, ThreadContext* ctx) throw() 
{
	this->checks->add(def, ctx);
}
IJoinTarget* CreateTableStatement::getTable(ThreadContext* ctx) throw() 
{
	return table;
}
void CreateTableStatement::setTable(IJoinTarget* table, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->table), table, IJoinTarget);
}
PrimaryKeys* CreateTableStatement::getPrimaryKeys(ThreadContext* ctx) throw() 
{
	return primaryKeys;
}
void CreateTableStatement::setPrimaryKeys(PrimaryKeys* primaryKeys, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->primaryKeys), primaryKeys, PrimaryKeys);
}
ArrayList<DdlColumnDescriptor>* CreateTableStatement::getColumns(ThreadContext* ctx) throw() 
{
	return columns;
}
ArrayList<Unique>* CreateTableStatement::getUniques(ThreadContext* ctx) throw() 
{
	return uniques;
}
ArrayList<CheckDefinition>* CreateTableStatement::getChecks(ThreadContext* ctx) throw() 
{
	return checks;
}
IStatement::StatementType CreateTableStatement::getType(ThreadContext* ctx) throw() 
{
	return StatementType::CREATE_TABLE;
}
void CreateTableStatement::analyzeSQL(SQLAnalyseContext* context, bool debug, ThreadContext* ctx) throw() 
{
}
}}}


#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile/IStatement.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.db.table/DatabaseException.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.stmt/AbstractAlinousStatement.h"
#include "alinous.compile.stmt/StatementList.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.expression/AbstractExpression.h"
#include "alinous.compile.expression.blexp/BooleanSubExpression.h"
#include "alinous.compile.expression.blexp/AbstractBooleanCollectionExpression.h"
#include "alinous.compile.expression.blexp/AndExpression.h"
#include "alinous.compile.expression.blexp/ConditionalAndExpression.h"
#include "alinous.compile.expression.blexp/ConditionalOrExpression.h"
#include "alinous.compile.expression.blexp/AbstractBooleanExpression.h"
#include "alinous.compile.expression.blexp/EqualityExpression.h"
#include "alinous.compile.expression.blexp/ExclusiveOrExpression.h"
#include "alinous.compile.expression.blexp/InclusiveOrExpression.h"
#include "alinous.system/AlinousNotSupportedException.h"
#include "alinous.compile.expression.blexp/InstanceOfExpression.h"
#include "alinous.compile.expression.blexp/NotExpression.h"
#include "alinous.compile.expression.blexp/RelationalExpression.h"
#include "alinous.compile.expression/FunctionArguments.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.expression/IDomSegment.h"
#include "alinous.compile.expression/DomNameSegment.h"
#include "alinous.compile.expression/DomIndexSegment.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMemberVariable.h"
#include "alinous.compile.declare.function/FunctionArgumentDefine.h"
#include "alinous.compile.declare.function/FunctionArgumentsListDefine.h"
#include "alinous.compile.declare.function/ReturnValueDefinition.h"
#include "alinous.compile.stmt/StatementBlock.h"
#include "alinous.compile.expression.expstream/FunctionCallExpression.h"
#include "alinous.compile.declare/VirtualTable.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.stmt/TypedVariableDeclare.h"
#include "alinous.compile.expression.expstream/ExpStreamSegment.h"
#include "alinous.compile.expression.expstream/ExpressionStream.h"
#include "alinous.compile.expression.expstream/ExpStreamCast.h"
#include "alinous.compile.expression.expstream/ExpStreamParenthesis.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.compile.sql/ISqlStatement.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.parts/ISQLExpressionPart.h"
#include "alinous.compile.sql.parts/AbstractExpressionPart.h"
#include "alinous.compile.sql.parts/SQLExpressionList.h"
#include "alinous.compile.sql.select/SQLGroupBy.h"
#include "alinous.compile.sql.select/SQLLimitOffset.h"
#include "alinous.compile.sql.select/SQLWhere.h"
#include "alinous.db.trx.scan/ITableTargetScanner.h"
#include "alinous.compile.sql.analyze/IndexColumnMatchCondition.h"
#include "alinous.compile.sql.expression.blexp/ISQLBoolExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanExpression.h"
#include "alinous.compile.sql.select.join/SQLJoinCondition.h"
#include "alinous.compile.sql.select.join/IJoin.h"
#include "alinous.compile.sql.select.join/IJoinTarget.h"
#include "alinous.compile.sql.select.join/AbstractJoinTarget.h"
#include "alinous.compile.sql.select.join/TableJoinTarget.h"
#include "alinous.compile.sql/AbstractSQLStatement.h"
#include "alinous.compile.sql/CreateIndexStatement.h"
#include "alinous.compile.sql/InsertStatement.h"
#include "alinous.compile.sql.select/SQLFrom.h"
#include "alinous.compile.sql/SelectStatement.h"
#include "alinous.compile.sql/UpdateSet.h"
#include "alinous.compile.sql/UpdateStatement.h"
#include "alinous.db.trx/DbTransaction.h"
#include "alinous.db.trx.scan/ScanResultRecord.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.compile.sql.expression/AbstractSQLExpression.h"
#include "alinous.compile.sql.expression/SQLColumnIdentifier.h"
#include "alinous.compile.sql.expression/SQLExpressionStream.h"
#include "alinous.compile.sql/InsertValues.h"
#include "alinous.compile.sql.expression/SQLSubExpression.h"
#include "alinous.compile.sql.expression/AbstractSQLCollectionExpression.h"
#include "alinous.compile.sql.expression/SQLAdditiveExpression.h"
#include "alinous.compile.sql.expression/SQLLiteral.h"
#include "alinous.compile.sql.expression/SQLMultiplicativeExpression.h"
#include "alinous.compile.sql.expression/SQLParenthesisExpression.h"
#include "alinous.compile.sql.expression/SQLSubqueryExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLBoolSubExpression.h"
#include "alinous.compile.sql.expression.blexp/AbstractSQLBooleanCollectionExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLAndExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLBooleanLiteral.h"
#include "alinous.compile.sql.expression.blexp/SQLEqualityExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLIsNullExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLLikeExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLNotExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLOrExpression.h"
#include "alinous.compile.sql.expression.blexp/SQLRelationalExpression.h"
#include "alinous.compile.sql.parts/SQLExpressionListAll.h"
#include "alinous.compile.expression/SubExpression.h"
#include "alinous.compile.expression/AbstractCollectionExpression.h"
#include "alinous.compile.expression/AdditiveExpression.h"
#include "alinous.compile.expression/MultiplicativeExpression.h"
#include "alinous.compile.expression/ShiftExpression.h"
#include "alinous.compile.declare/ClassExtends.h"
#include "alinous.compile.expression/AllocationExpression.h"
#include "alinous.compile.expression/BitReverseExpression.h"
#include "alinous.compile.expression/CastExpression.h"
#include "alinous.compile.expression/ConditionalExpression.h"
#include "alinous.compile.expression/Literal.h"
#include "alinous.compile.expression/BooleanLiteral.h"
#include "alinous.compile.expression/NullLiteral.h"
#include "alinous.compile.expression/ParenthesisExpression.h"
#include "alinous.compile.expression/PreDecrementExpression.h"
#include "alinous.compile.expression/PreIncrementExpression.h"
#include "alinous.compile.expression/UnaryExpression.h"
#include "alinous.compile.expression/IExpressionFactory.h"
#include "alinous.runtime/AlinousModulePackage.h"
#include "alinous.runtime/AlinousModule.h"
#include "alinous.compile/IncludePreprocessor.h"
#include "alinous.compile/AlinousSrc.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.compile.declare.function/ThrowsDefine.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.declare/ClassImplements.h"
#include "alinous.compile.sql/BeginStatement.h"
#include "alinous.compile.sql/CommitStatement.h"
#include "alinous.compile.sql.ddl/CheckDefinition.h"
#include "alinous.compile.sql.ddl/ColumnTypeDescriptor.h"
#include "alinous.compile.sql.ddl/DdlColumnDescriptor.h"
#include "alinous.compile.sql.ddl/PrimaryKeys.h"
#include "alinous.compile.sql.ddl/ShardKeys.h"
#include "alinous.compile.sql.ddl/Unique.h"
#include "alinous.compile.sql/CreateTableStatement.h"
#include "alinous.compile.sql/DeleteStatement.h"
#include "alinous.compile.sql/DropIndexStatement.h"
#include "alinous.compile.sql/DropTableStatement.h"
#include "alinous.compile.sql/RollbackStatement.h"
#include "alinous.compile.sql.analyze/JoinStrategyPart.h"
#include "alinous.compile.sql.analyze/JoinStrategy.h"
#include "alinous.db.trx.scan/ScannedResultIndexScanner.h"
#include "alinous.compile.sql.select.join/AbstractSQLJoin.h"
#include "alinous.compile.sql.select.join/InnerJoin.h"
#include "alinous.compile.sql.select.join/CrossJoin.h"
#include "alinous.compile.sql.select.join/DomVariableJoinTarget.h"
#include "alinous.compile.sql.select.join/JoinSubQueryTarget.h"
#include "alinous.compile.sql.select.join/LeftJoin.h"
#include "alinous.compile.sql.select.join/NaturalJoin.h"
#include "alinous.compile.sql.select.join/RightJoin.h"
#include "alinous.compile.sql.select.join/TableList.h"
#include "alinous.compile.sql.select.join/WrappedJoinTarget.h"
#include "alinous.compile.stmt/AssignmentStatement.h"
#include "alinous.compile.stmt/BreakStatement.h"
#include "alinous.compile.stmt/CaseStatement.h"
#include "alinous.compile.stmt/CatchBlock.h"
#include "alinous.compile.stmt/ContinueStatement.h"
#include "alinous.compile.stmt/DefaultStatement.h"
#include "alinous.compile.stmt/LabeledStatement.h"
#include "alinous.compile.stmt/DoWhileStatement.h"
#include "alinous.compile.stmt/ExpressionStatement.h"
#include "alinous.compile.stmt/FinallyBlock.h"
#include "alinous.compile.stmt/ForUpdatePart.h"
#include "alinous.compile.stmt/ForStatement.h"
#include "alinous.compile.stmt/IfStatement.h"
#include "alinous.compile.stmt/ReturnStatement.h"
#include "alinous.compile.stmt/SwitchCasePart.h"
#include "alinous.compile.stmt/SwitchStatement.h"
#include "alinous.compile.stmt/ThrowStatement.h"
#include "alinous.compile.stmt/TryBlock.h"
#include "alinous.compile.stmt/WhileStatement.h"
#include "alinous.compile/AlinousElementNetworkFactory.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile.sql.expression.blexp/SQLInExpression.h"

namespace alinous {namespace compile {namespace sql {namespace expression {namespace blexp {





bool SQLInExpression::__init_done = __init_static_variables();
bool SQLInExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"SQLInExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 SQLInExpression::SQLInExpression(ThreadContext* ctx) throw()  : IObject(ctx), AbstractSQLBooleanExpression(ctx), first(nullptr), list(nullptr)
{
}
void SQLInExpression::__construct_impl(ThreadContext* ctx) throw() 
{
}
 SQLInExpression::~SQLInExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void SQLInExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"SQLInExpression", L"~SQLInExpression");
	__e_obj1.add(this->first, this);
	first = nullptr;
	__e_obj1.add(this->list, this);
	list = nullptr;
	if(!prepare){
		return;
	}
	AbstractSQLBooleanExpression::__releaseRegerences(true, ctx);
}
bool SQLInExpression::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->first != nullptr && !this->first->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->list != nullptr && !this->list->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool SQLInExpression::isConstant(ThreadContext* ctx) throw() 
{
	if(this->first != nullptr && !this->first->isConstant(ctx))
	{
		return false;
	}
	if(this->list != nullptr && !this->list->isConstant(ctx))
	{
		return false;
	}
	return true;
}
bool SQLInExpression::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->first != nullptr)
	{
		this->first->analyse(context, leftValue, ctx);
	}
	if(this->list != nullptr)
	{
		this->list->analyse(context, leftValue, ctx);
	}
	return true;
}
ISQLExpression* SQLInExpression::getFirst(ThreadContext* ctx) throw() 
{
	return first;
}
void SQLInExpression::setFirst(ISQLExpression* first, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->first), first, ISQLExpression);
}
SQLExpressionList* SQLInExpression::getList(ThreadContext* ctx) throw() 
{
	return list;
}
void SQLInExpression::setList(SQLExpressionList* list, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->list), list, SQLExpressionList);
}
IAlinousVariable* SQLInExpression::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	throw (new(ctx) AlinousNotSupportedException(ctx));
}
ExpressionSourceId* SQLInExpression::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, (new(ctx) AlinousType(AlinousType::BOOL_TYPE, AlinousType::TYPE_PRIMITIVE, ctx)), ctx));
}
bool SQLInExpression::analyseSQL(SQLAnalyseContext* context, bool leftValue, bool debug, ThreadContext* ctx)
{
	if(this->first != nullptr)
	{
		this->first->analyseSQL(context, leftValue, debug, ctx);
	}
	if(this->list != nullptr)
	{
		this->list->analyseSQL(context, leftValue, debug, ctx);
	}
	ArrayList<ScanTableColumnIdentifier>* colList = this->first->getColumns(ctx);
	if(colList == nullptr || colList->isEmpty(ctx))
	{
		throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1139(), ctx));
	}
	return true;
}
bool SQLInExpression::hasTable(ScanTableIdentifier* table, ThreadContext* ctx) throw() 
{
	if(this->first != nullptr && this->first->hasTable(table, ctx))
	{
		return true;
	}
	if(this->list != nullptr && this->list->hasTable(table, ctx))
	{
		return true;
	}
	return false;
}
ArrayList<ScanTableColumnIdentifier>* SQLInExpression::getColumns(ThreadContext* ctx) throw() 
{
	ArrayList<ScanTableColumnIdentifier>* list = (new(ctx) ArrayList<ScanTableColumnIdentifier>(ctx));
	list = SQLAnalyseContext::joinList(list, this->first, ctx);
	list = SQLAnalyseContext::joinList(list, this->list, ctx);
	return list;
}
bool SQLInExpression::hasSubExp(ThreadContext* ctx) throw() 
{
	return false;
}
bool SQLInExpression::isJoinCondition(ThreadContext* ctx) throw() 
{
	return false;
}
void SQLInExpression::collectJoinCondition(ArrayList<ISQLExpression>* list, ThreadContext* ctx) throw() 
{
}
bool SQLInExpression::isColumnIdentifier(ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<ScanTableColumnIdentifier>* SQLInExpression::getIndexTargetColumn(ThreadContext* ctx) throw() 
{
	ArrayList<ScanTableColumnIdentifier>* cols = this->first->getColumns(ctx);
	return cols;
}
IndexColumnMatchCondition* SQLInExpression::getIndexScanPart(ThreadContext* ctx) throw() 
{
	if(isJoinCondition(ctx))
	{
		return nullptr;
	}
	if(this->first->isColumnIdentifier(ctx))
	{
		IndexColumnMatchCondition* matchingCondition = (new(ctx) IndexColumnMatchCondition(this->first->toColumnIdentifier(ctx), this->list->getList(ctx), ctx));
		return matchingCondition;
	}
	return nullptr;
}
ScanTableColumnIdentifier* SQLInExpression::toColumnIdentifier(ThreadContext* ctx) throw() 
{
	return nullptr;
}
VariantValue* SQLInExpression::resolveSQLExpression(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	VariantValue* val = this->first->resolveSQLExpression(record, machine, debug, ctx);
	ArrayList<VariantValue>* valueList = this->list->resolveSQLExpressionAsArray(record, machine, debug, ctx);
	int maxLoop = valueList->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		VariantValue* invalue = valueList->get(i, ctx);
		if(val->compareTo(invalue, ctx) == 0)
		{
			return (new(ctx) VariantValue(((char)1), ctx));
		}
	}
	return (new(ctx) VariantValue(((char)0), ctx));
}
bool SQLInExpression::hasArrayResult(ThreadContext* ctx) throw() 
{
	return false;
}
ArrayList<VariantValue>* SQLInExpression::resolveSQLExpressionAsArray(ScanResultRecord* record, ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	throw (new(ctx) DatabaseException(ConstStr::getCNST_STR_1118(), ctx));
}
int SQLInExpression::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::sQLInExpression;
}
void SQLInExpression::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	__readData(buff, ctx);
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<ISQLExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1126(), ctx));
		}
		__GC_MV(this, &(this->first), static_cast<ISQLExpression*>(el), ISQLExpression);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<SQLExpressionList*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1119(), ctx));
		}
		__GC_MV(this, &(this->list), static_cast<SQLExpressionList*>(el), SQLExpressionList);
	}
}
void SQLInExpression::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__SQLInExpression, ctx);
	__writeData(buff, ctx);
	bool isnull = (this->first == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->first->writeData(buff, ctx);
	}
	isnull = (this->list == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->list->writeData(buff, ctx);
	}
}
int SQLInExpression::fileSize(ThreadContext* ctx)
{
	int total = __fileSize(ctx);
	bool isnull = (this->first == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->first->fileSize(ctx);
	}
	isnull = (this->list == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->list->fileSize(ctx);
	}
	return total;
}
void SQLInExpression::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__SQLInExpression, ctx);
	__toFileEntry(builder, ctx);
	bool isnull = (this->first == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->first->toFileEntry(builder, ctx);
	}
	isnull = (this->list == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->list->toFileEntry(builder, ctx);
	}
}
void SQLInExpression::fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	__fromFileEntry(fetcher, ctx);
	bool isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		IExpression* el = IExpressionFactory::fromFetcher(fetcher, ctx);
		if(el == nullptr || !((dynamic_cast<ISQLExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1126(), ctx));
		}
		__GC_MV(this, &(this->first), static_cast<ISQLExpression*>(el), ISQLExpression);
	}
	isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		IExpression* el = IExpressionFactory::fromFetcher(fetcher, ctx);
		if(el == nullptr || !((dynamic_cast<SQLExpressionList*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1119(), ctx));
		}
		__GC_MV(this, &(this->list), static_cast<SQLExpressionList*>(el), SQLExpressionList);
	}
}
void SQLInExpression::__cleanUp(ThreadContext* ctx){
}
}}}}}


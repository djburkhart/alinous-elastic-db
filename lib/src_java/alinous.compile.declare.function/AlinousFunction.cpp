#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.compile.analyse/SourceValidator.h"
#include "alinous.compile/IStatement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.stmt/AbstractAlinousStatement.h"
#include "alinous.compile.stmt/StatementList.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
#include "alinous.compile/Token.h"
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
#include "alinous.compile.expression.blexp/InstanceOfExpression.h"
#include "alinous.compile.expression.blexp/NotExpression.h"
#include "alinous.compile.expression.blexp/RelationalExpression.h"
#include "alinous.compile.expression/FunctionArguments.h"
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
#include "alinous.compile.sql.expression.blexp/SQLInExpression.h"
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
#include "alinous.compile.expression/IDomSegment.h"
#include "alinous.compile.expression/DomIndexSegment.h"
#include "alinous.compile.expression/DomNameSegment.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile/IncludePreprocessor.h"
#include "alinous.compile/AlinousSrc.h"
#include "alinous.runtime/AlinousModulePackage.h"
#include "alinous.runtime/AlinousModule.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.declare/ClassImplements.h"
#include "alinous.compile.declare.function/ThrowsDefine.h"
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
#include "alinous.compile.analyse.tools/FunctionCallCollector.h"
#include "alinous.compile.declare.function/AlinousFunction.h"

namespace alinous {namespace compile {namespace declare {namespace function {





bool AlinousFunction::__init_done = __init_static_variables();
bool AlinousFunction::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousFunction", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousFunction::AlinousFunction(ThreadContext* ctx) throw()  : IObject(ctx), IDeclare(ctx), name(nullptr), returnType(nullptr), arguments(nullptr), throwsDefine(nullptr), block(nullptr), analysedReturnType(nullptr)
{
}
void AlinousFunction::__construct_impl(ThreadContext* ctx) throw() 
{
}
 AlinousFunction::~AlinousFunction() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousFunction::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousFunction", L"~AlinousFunction");
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->returnType, this);
	returnType = nullptr;
	__e_obj1.add(this->arguments, this);
	arguments = nullptr;
	__e_obj1.add(this->throwsDefine, this);
	throwsDefine = nullptr;
	__e_obj1.add(this->block, this);
	block = nullptr;
	__e_obj1.add(this->analysedReturnType, this);
	analysedReturnType = nullptr;
	if(!prepare){
		return;
	}
	IDeclare::__releaseRegerences(true, ctx);
}
String* AlinousFunction::getFunctionName(ThreadContext* ctx) throw() 
{
	return this->name->toString(ctx);
}
bool AlinousFunction::sameSig(AlinousFunction* other, ThreadContext* ctx) throw() 
{
	if(!this->name->equals(other->name, ctx))
	{
		return false;
	}
	if(!this->arguments->same(other->arguments, ctx))
	{
		return false;
	}
	return true;
}
bool AlinousFunction::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	if(this->name != nullptr && !this->name->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->returnType != nullptr && !this->returnType->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->arguments != nullptr && !this->arguments->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->throwsDefine != nullptr && !this->throwsDefine->visit(visitor, this, ctx))
	{
		return false;
	}
	if(this->block != nullptr && !this->block->visit(visitor, this, ctx))
	{
		return false;
	}
	return true;
}
bool AlinousFunction::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	this->name->analyse(context, leftValue, ctx);
	if(this->returnType != nullptr)
	{
		this->returnType->analyse(context, leftValue, ctx);
	}
	this->arguments->analyse(context, leftValue, ctx);
	if(this->throwsDefine != nullptr)
	{
		this->throwsDefine->analyse(context, leftValue, ctx);
	}
	this->block->analyse(context, leftValue, ctx);
	if(this->returnType != nullptr && !this->returnType->isVoid(ctx))
	{
		__GC_MV(this, &(this->analysedReturnType), this->returnType->getAnalysedType(ctx), AlinousType);
	}
		else 
	{
		if(this->returnType != nullptr && this->returnType->isVoid(ctx))
		{
			__GC_MV(this, &(this->analysedReturnType), (new(ctx) AlinousType(AlinousType::NULL_TYPE, AlinousType::TYPE_VOID, ctx)), AlinousType);
		}
	}
	return true;
}
FunctionCallExpression* AlinousFunction::callSuperConstructor(ThreadContext* ctx) throw() 
{
	IStatement* stmt = this->block->getFirstStatement(ctx);
	if(stmt == nullptr)
	{
		return nullptr;
	}
	FunctionCallCollector* visitor = (new(ctx) FunctionCallCollector(ctx));
	stmt->visit(visitor, this->parent, ctx);
	int maxLoop = visitor->getList(ctx)->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		FunctionCallExpression* func = visitor->getList(ctx)->get(i, ctx);
		if(func->body->equals(ConstStr::getCNST_STR_1097(), ctx))
		{
			return func;
		}
	}
	return nullptr;
}
String* AlinousFunction::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	if(this->returnType != nullptr)
	{
		buff->append(this->returnType->toString(ctx), ctx)->append(ConstStr::getCNST_STR_380(), ctx);
	}
	buff->append(this->name->toString(ctx), ctx);
	if(this->arguments != nullptr)
	{
		buff->append(this->arguments->toString(ctx), ctx);
	}
		else 
	{
		buff->append(ConstStr::getCNST_STR_1098(), ctx);
	}
	return buff->toString(ctx);
}
AlinousName* AlinousFunction::getName(ThreadContext* ctx) throw() 
{
	return name;
}
void AlinousFunction::setName(AlinousName* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, AlinousName);
}
ReturnValueDefinition* AlinousFunction::getReturnType(ThreadContext* ctx) throw() 
{
	return returnType;
}
void AlinousFunction::setReturnType(ReturnValueDefinition* returnType, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->returnType), returnType, ReturnValueDefinition);
}
FunctionArgumentsListDefine* AlinousFunction::getArguments(ThreadContext* ctx) throw() 
{
	return arguments;
}
void AlinousFunction::setArguments(FunctionArgumentsListDefine* arguments, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->arguments), arguments, FunctionArgumentsListDefine);
}
ThrowsDefine* AlinousFunction::getThrowsDefine(ThreadContext* ctx) throw() 
{
	return throwsDefine;
}
void AlinousFunction::setThrowsDefine(ThrowsDefine* throwsDefine, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->throwsDefine), throwsDefine, ThrowsDefine);
}
StatementBlock* AlinousFunction::getBlock(ThreadContext* ctx) throw() 
{
	return block;
}
void AlinousFunction::setBlock(StatementBlock* block, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->block), block, StatementBlock);
}
AlinousType* AlinousFunction::getAnalysedReturnType(ThreadContext* ctx) throw() 
{
	return analysedReturnType;
}
int AlinousFunction::getLine(ThreadContext* ctx) throw() 
{
	return IDeclare::getLine(ctx);
}
int AlinousFunction::getStartPosition(ThreadContext* ctx) throw() 
{
	return IDeclare::getStartPosition(ctx);
}
int AlinousFunction::getEndLine(ThreadContext* ctx) throw() 
{
	return IDeclare::getEndLine(ctx);
}
int AlinousFunction::getEndPosition(ThreadContext* ctx) throw() 
{
	return IDeclare::getEndPosition(ctx);
}
AbstractSrcElement* AlinousFunction::getParent(ThreadContext* ctx) throw() 
{
	return IDeclare::getParent(ctx);
}
void AlinousFunction::setParent(AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	IDeclare::setParent(parent, ctx);
}
void AlinousFunction::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<AlinousName*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1033(), ctx));
		}
		__GC_MV(this, &(this->name), static_cast<AlinousName*>(el), AlinousName);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<ReturnValueDefinition*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1099(), ctx));
		}
		__GC_MV(this, &(this->returnType), static_cast<ReturnValueDefinition*>(el), ReturnValueDefinition);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<FunctionArgumentsListDefine*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1100(), ctx));
		}
		__GC_MV(this, &(this->arguments), static_cast<FunctionArgumentsListDefine*>(el), FunctionArgumentsListDefine);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<ThrowsDefine*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1101(), ctx));
		}
		__GC_MV(this, &(this->throwsDefine), static_cast<ThrowsDefine*>(el), ThrowsDefine);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<StatementBlock*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1102(), ctx));
		}
		__GC_MV(this, &(this->block), static_cast<StatementBlock*>(el), StatementBlock);
	}
}
void AlinousFunction::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__AlinousFunction, ctx);
	bool isnull = (this->name == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->name->writeData(buff, ctx);
	}
	isnull = (this->returnType == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->returnType->writeData(buff, ctx);
	}
	isnull = (this->arguments == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->arguments->writeData(buff, ctx);
	}
	isnull = (this->throwsDefine == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->throwsDefine->writeData(buff, ctx);
	}
	isnull = (this->block == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		this->block->writeData(buff, ctx);
	}
}
void AlinousFunction::__cleanUp(ThreadContext* ctx){
}
}}}}


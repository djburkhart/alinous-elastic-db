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
#include "alinous.html/IDomObject.h"
#include "alinous.html/DomNode.h"
#include "alinous.system/AlinousException.h"
#include "alinous.runtime/ExecutionException.h"
#include "alinous.runtime.dom/VariableException.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.btree/IValueFetcher.h"
#include "alinous.btree/IBTreeValue.h"
#include "alinous.compile.analyse/DomVariableDeclareSource.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.runtime.dom/IDomVariableContainer.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.dom/IDomVariable.h"
#include "alinous.runtime.dom.typed/ITypedVariable.h"
#include "alinous.runtime.dom.clazz/IAlinousClassVariable.h"
#include "alinous.compile.stmt/AbstractAlinousStatement.h"
#include "alinous.compile.stmt/StatementList.h"
#include "alinous.runtime.dom.typed/ITypedCaller.h"
#include "alinous.runtime.dom.typed/AbstractTypedVariable.h"
#include "alinous.runtime.dom.typed/TypedVariableArray.h"
#include "alinous.runtime.dom.typed/TimestampVariable.h"
#include "alinous.runtime.dom.typed/TimeVariable.h"
#include "alinous.runtime.dom.typed/ShortVariable.h"
#include "alinous.runtime.dom.typed/LongVariable.h"
#include "alinous.runtime.dom.typed/IntegerVariable.h"
#include "alinous.runtime.dom.typed/FloatVariable.h"
#include "alinous.runtime.dom.typed/DoubleVariable.h"
#include "alinous.runtime.dom.typed/CharVariable.h"
#include "alinous.runtime.dom.typed/ByteVariable.h"
#include "alinous.runtime.dom.typed/StringVariable.h"
#include "alinous.runtime.dom.typed/BoolVariable.h"
#include "alinous.runtime.variant/VariantValue.h"
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
#include "alinous.compile.analyse/ExpressionStreamResult.h"
#include "alinous.compile.expression/FunctionArguments.h"
#include "alinous.compile.declare.function/FunctionArgumentsListDefine.h"
#include "alinous.compile.declare/VirtualTable.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile.declare.function/ReturnValueDefinition.h"
#include "alinous.compile.stmt/StatementBlock.h"
#include "alinous.runtime.dom.clazz/AlinousClassVariable.h"
#include "alinous.compile.expression.expstream/FunctionCallExpression.h"
#include "alinous.compile.expression.expstream/ExpressionStream.h"
#include "alinous.compile.expression.expstream/ExpStreamCast.h"
#include "alinous.compile.expression.expstream/ExpStreamParenthesis.h"
#include "alinous.compile.sql.analyze/ScanTableIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableColumnIdentifier.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.db.table/IDatabaseRecord.h"
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
#include "alinous.runtime/AlinousModulePackage.h"
#include "alinous.runtime/AlinousModule.h"
#include "alinous.compile/IncludePreprocessor.h"
#include "alinous.compile/AlinousSrc.h"
#include "alinous.compile/Token.h"
#include "alinous.compile.expression/IDomSegment.h"
#include "alinous.compile.expression/DomIndexSegment.h"
#include "alinous.compile.expression/DomNameSegment.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.declare.function/FunctionArgumentDefine.h"
#include "alinous.compile.stmt/TypedVariableDeclare.h"
#include "alinous.compile.analyse/TypedVariableDeclareSource.h"
#include "alinous.compile.analyse/VariableDeclareHolder.h"
#include "alinous.compile.expression/DomVariableDescriptor.h"
#include "alinous.runtime.dom/DomVariable.h"
#include "alinous.runtime.dom.typed/BigDecimalVariable.h"
#include "alinous.runtime.dom/DocumentVariable.h"
#include "alinous.compile.analyse/AlinousType.h"
#include "alinous.compile.declare.function/ThrowsDefine.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.declare/AlinousName.h"
#include "alinous.compile.declare/ClassImplements.h"
#include "alinous.compile.declare/ClassMemberVariable.h"
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
#include "alinous.compile.expression.expstream/IdentifierVariable.h"
#include "alinous.compile.expression.expstream/ExpStreamSegment.h"

namespace alinous {namespace compile {namespace expression {namespace expstream {



constexpr EnumBase __ExpStreamSegment__SegmentType::__DEFAULT_NULL;
constexpr EnumBase __ExpStreamSegment__SegmentType::SEG_FUNC_PREFIX;
constexpr EnumBase __ExpStreamSegment__SegmentType::SEG_STATIC_CLASS_PREFIX;
constexpr EnumBase __ExpStreamSegment__SegmentType::SEG_DOM_PROPERTY;
constexpr EnumBase __ExpStreamSegment__SegmentType::SEG_VARIABLE;
constexpr EnumBase __ExpStreamSegment__SegmentType::SEG_STATIC_VARIABLE;
constexpr EnumBase __ExpStreamSegment__SegmentType::SEG_MEMBER_VARIABLE;
constexpr EnumBase __ExpStreamSegment__SegmentType::SEG_MEMBER_DOM_VARIABLE;
constexpr EnumBase __ExpStreamSegment__SegmentType::SEG_THIS;
constexpr EnumBase __ExpStreamSegment__SegmentType::SEG_SQL;


bool ExpStreamSegment::__init_done = __init_static_variables();
bool ExpStreamSegment::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ExpStreamSegment", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ExpStreamSegment::ExpStreamSegment(ThreadContext* ctx) throw()  : IObject(ctx), AbstractExpression(ctx), domPath(nullptr), prefix(nullptr), name(nullptr), arrayIndexes(GCUtils<ArrayList<IExpression> >::ins(this, (new(ctx) ArrayList<IExpression>(ctx)), ctx, __FILEW__, __LINE__, L"")), analysedType(nullptr), domDeclare(nullptr), typedDeclare(nullptr), argumentDeclare(nullptr), memberVariableDef(nullptr), staticVariableDef(nullptr)
{
}
void ExpStreamSegment::__construct_impl(ThreadContext* ctx) throw() 
{
}
 ExpStreamSegment::~ExpStreamSegment() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ExpStreamSegment::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"ExpStreamSegment", L"~ExpStreamSegment");
	__e_obj1.add(this->domPath, this);
	domPath = nullptr;
	__e_obj1.add(this->prefix, this);
	prefix = nullptr;
	__e_obj1.add(this->name, this);
	name = nullptr;
	__e_obj1.add(this->arrayIndexes, this);
	arrayIndexes = nullptr;
	__e_obj1.add(this->analysedType, this);
	analysedType = nullptr;
	__e_obj1.add(this->domDeclare, this);
	domDeclare = nullptr;
	__e_obj1.add(this->typedDeclare, this);
	typedDeclare = nullptr;
	__e_obj1.add(this->argumentDeclare, this);
	argumentDeclare = nullptr;
	__e_obj1.add(this->memberVariableDef, this);
	memberVariableDef = nullptr;
	__e_obj1.add(this->staticVariableDef, this);
	staticVariableDef = nullptr;
	if(!prepare){
		return;
	}
	AbstractExpression::__releaseRegerences(true, ctx);
}
IAlinousVariable* ExpStreamSegment::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	switch(this->segmentType) {
	case ExpStreamSegment::SegmentType::SEG_THIS:
		return machine->getThisPtr(ctx);
	case ExpStreamSegment::SegmentType::SEG_STATIC_VARIABLE:
		return this->staticVariableDef->getStaticValue(ctx);
	case ExpStreamSegment::SegmentType::SEG_MEMBER_VARIABLE:
		return returnMemberVariable(machine, debug, ctx);
	case ExpStreamSegment::SegmentType::SEG_MEMBER_DOM_VARIABLE:
		return returnMemberDomVariable(machine, debug, ctx);
	case ExpStreamSegment::SegmentType::SEG_FUNC_PREFIX:
	case ExpStreamSegment::SegmentType::SEG_STATIC_CLASS_PREFIX:
		return (new(ctx) IdentifierVariable(this->name, ctx));
	case ExpStreamSegment::SegmentType::SEG_VARIABLE:
	case ExpStreamSegment::SegmentType::SEG_DOM_PROPERTY:
	default:
		break ;
	}
	IAlinousVariable* lastSegmentVariable = machine->getStreamLastValue(ctx);
	if(lastSegmentVariable == nullptr)
	{
		return handleFirstSegment(machine, debug, ctx);
	}
	int variableClass = lastSegmentVariable->getVariableClass(ctx);
	switch(variableClass) {
	case IAlinousVariable::CLASS_DOM:
		return getDomProperty(machine, static_cast<IDomVariable*>(lastSegmentVariable), debug, ctx);
	case IAlinousVariable::CLASS_OBJECT:
		return getClassMemberVariable(machine, static_cast<AlinousClassVariable*>(lastSegmentVariable), ctx);
	case IAlinousVariable::CLASS_TYPED:
	case IAlinousVariable::CLASS_IDENTIFIER:
		return addDescriptor(machine, static_cast<IdentifierVariable*>(lastSegmentVariable), debug, ctx);
	case IAlinousVariable::CLASS_VARIANT:
	default:
		break ;
	}
	throw (new(ctx) VariableException(ConstStr::getCNST_STR_1050(), ctx));
}
bool ExpStreamSegment::visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw() 
{
	if(!visitor->visit(this, parent, ctx))
	{
		return false;
	}
	int maxLoop = this->arrayIndexes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IExpression* exp = this->arrayIndexes->get(i, ctx);
		if(!exp->visit(visitor, this, ctx))
		{
			return false;
		}
	}
	return true;
}
bool ExpStreamSegment::isConstant(ThreadContext* ctx) throw() 
{
	return false;
}
bool ExpStreamSegment::analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	ExpressionStreamResult* result = context->getExpressionStreamResult(ctx);
	AlinousType* type = result->getType(ctx);
	if(type == nullptr)
	{
		return analyseFirstSegment(result, context, leftValue, ctx);
	}
	int typeClass = type->getTypeClass(ctx);
	switch(typeClass) {
	case AlinousType::TYPE_PRIMITIVE:
		break ;
	case AlinousType::TYPE_STANDARD_OBJ:
		break ;
	case AlinousType::TYPE_CLASS_OBJ:
		return analyseAfterClassObject(result, context, leftValue, ctx);
	case AlinousType::TYPE_DOM:
		return analyseAfterDom(result, context, leftValue, ctx);
	default:
		break ;
	}
	return false;
}
ExpressionSourceId* ExpStreamSegment::getSourceId(ThreadContext* ctx) throw() 
{
	return (new(ctx) ExpressionSourceId(nullptr, this, this->analysedType, ctx));
}
void ExpStreamSegment::addArrayIndex(IExpression* exp, ThreadContext* ctx) throw() 
{
	this->arrayIndexes->add(exp, ctx);
}
String* ExpStreamSegment::getPrefix(ThreadContext* ctx) throw() 
{
	return prefix;
}
void ExpStreamSegment::setPrefix(String* prefix, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->prefix), prefix, String);
}
String* ExpStreamSegment::getName(ThreadContext* ctx) throw() 
{
	return name;
}
void ExpStreamSegment::setName(String* name, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->name), name, String);
}
ArrayList<IExpression>* ExpStreamSegment::getArrayIndexes(ThreadContext* ctx) throw() 
{
	return arrayIndexes;
}
AlinousType* ExpStreamSegment::getAnalysedType(ThreadContext* ctx) throw() 
{
	return analysedType;
}
DomVariableDescriptor* ExpStreamSegment::getDomPath(ThreadContext* ctx) throw() 
{
	return domPath;
}
DomVariableDeclareSource* ExpStreamSegment::getDomDeclare(ThreadContext* ctx) throw() 
{
	return domDeclare;
}
ExpStreamSegment::SegmentType ExpStreamSegment::getSegmentType(ThreadContext* ctx) throw() 
{
	return segmentType;
}
String* ExpStreamSegment::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	if(this->prefix != nullptr)
	{
		buff->append(this->prefix, ctx);
	}
	buff->append(this->name, ctx);
	int maxLoop = this->arrayIndexes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		buff->append(ConstStr::getCNST_STR_1054(), ctx);
	}
	return buff->toString(ctx);
}
ClassMemberVariable* ExpStreamSegment::getMemberVariableDef(ThreadContext* ctx) throw() 
{
	return memberVariableDef;
}
int ExpStreamSegment::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::expStreamSegment;
}
void ExpStreamSegment::readData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	bool isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->prefix), buff->getString(ctx), String);
	}
	isnull = buff->getBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->name), buff->getString(ctx), String);
	}
	int maxLoop = buff->getInt(ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		IAlinousElement* el = AlinousElementNetworkFactory::formNetworkData(buff, ctx);
		if(el == nullptr || !((dynamic_cast<IExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1027(), ctx));
		}
		this->arrayIndexes->add(static_cast<IExpression*>(el), ctx);
	}
}
void ExpStreamSegment::writeData(NetworkBinaryBuffer* buff, ThreadContext* ctx)
{
	buff->putInt(ICommandData::__ExpStreamSegment, ctx);
	bool isnull = (this->prefix == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		buff->putString(this->prefix, ctx);
	}
	isnull = (this->name == nullptr);
	buff->putBoolean(isnull, ctx);
	if(!isnull)
	{
		buff->putString(this->name, ctx);
	}
	int maxLoop = this->arrayIndexes->size(ctx);
	buff->putInt(maxLoop, ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		IExpression* exp = this->arrayIndexes->get(i, ctx);
		exp->writeData(buff, ctx);
	}
}
int ExpStreamSegment::fileSize(ThreadContext* ctx)
{
	int total = 4;
	bool isnull = (this->prefix == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->prefix->length(ctx) * 2 + 4;
	}
	isnull = (this->name == nullptr);
	total += 1;
	if(!isnull)
	{
		total += this->name->length(ctx) * 2 + 4;
	}
	int maxLoop = this->arrayIndexes->size(ctx);
	total += 4;
	for(int i = 0; i < maxLoop; ++i)
	{
		IExpression* exp = this->arrayIndexes->get(i, ctx);
		exp->fileSize(ctx);
	}
	return total;
}
void ExpStreamSegment::toFileEntry(FileStorageEntryBuilder* builder, ThreadContext* ctx)
{
	builder->putInt(IExpressionFactory::__ExpStreamSegment, ctx);
	bool isnull = (this->prefix == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		builder->putString(this->prefix, ctx);
	}
	isnull = (this->name == nullptr);
	builder->putBoolean(isnull, ctx);
	if(!isnull)
	{
		builder->putString(this->name, ctx);
	}
	int maxLoop = this->arrayIndexes->size(ctx);
	builder->putInt(maxLoop, ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		IExpression* exp = this->arrayIndexes->get(i, ctx);
		exp->toFileEntry(builder, ctx);
	}
}
void ExpStreamSegment::fromFileEntry(FileStorageEntryFetcher* fetcher, ThreadContext* ctx)
{
	bool isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->prefix), fetcher->fetchString(ctx), String);
	}
	isnull = fetcher->fetchBoolean(ctx);
	if(!isnull)
	{
		__GC_MV(this, &(this->name), fetcher->fetchString(ctx), String);
	}
	int maxLoop = fetcher->fetchInt(ctx);
	for(int i = 0; i < maxLoop; ++i)
	{
		IExpression* el = IExpressionFactory::fromFetcher(fetcher, ctx);
		if(el == nullptr || !((dynamic_cast<IExpression*>(el) != 0)))
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1027(), ctx));
		}
		this->arrayIndexes->add(static_cast<IExpression*>(el), ctx);
	}
}
IAlinousVariable* ExpStreamSegment::returnMemberDomVariable(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	if(!this->arrayIndexes->isEmpty(ctx))
	{
		return returnMemberDomVariableArray(machine, debug, ctx);
	}
	IDomVariable* lastSegmentVariable = static_cast<IDomVariable*>(machine->getStreamLastValue(ctx));
	IDomVariable* val = static_cast<IDomVariable*>(lastSegmentVariable->getProperty(this->name, ctx));
	if(val != nullptr)
	{
		return val;
	}
	val = (new(ctx) DocumentVariable(ctx));
	if(machine->isLeftValue(ctx))
	{
		lastSegmentVariable->setProperty(this->name, val, ctx);
	}
	return val;
}
IAlinousVariable* ExpStreamSegment::returnMemberDomVariableArray(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	IDomVariable* lastSegmentVariable = static_cast<IDomVariable*>(machine->getStreamLastValue(ctx));
	IDomVariable* val = static_cast<IDomVariable*>(lastSegmentVariable->getProperty(this->name, ctx));
	if(val != nullptr)
	{
		int maxLoop = this->arrayIndexes->size(ctx);
		IDomVariable* current = val;
		for(int i = 0; i != maxLoop; ++i)
		{
			IAlinousVariable* index = this->arrayIndexes->get(i, ctx)->resolveExpression(machine, debug, ctx);
			int iindex = index->getIntValue(ctx);
			IDomVariable* element = static_cast<IDomVariable*>(current->get(iindex, ctx));
			if(element == nullptr)
			{
				if(i == maxLoop - 1)
				{
					element = (new(ctx) DocumentVariable(ctx));
				}
								else 
				{
					element = (new(ctx) DocumentVariable(true, ctx));
				}
				if(machine->isLeftValue(ctx))
				{
					current->set(element, iindex, ctx);
				}
			}
			current = element;
		}
		return current;
	}
	val = (new(ctx) DocumentVariable(true, ctx));
	if(machine->isLeftValue(ctx))
	{
		lastSegmentVariable->setProperty(this->name, val, ctx);
		int maxLoop = this->arrayIndexes->size(ctx);
		IDomVariable* current = val;
		for(int i = 0; i != maxLoop; ++i)
		{
			IAlinousVariable* index = this->arrayIndexes->get(i, ctx)->resolveExpression(machine, debug, ctx);
			int iindex = index->getIntValue(ctx);
			IDomVariable* newElement = (new(ctx) DocumentVariable(ctx));
			if(i == maxLoop - 1)
			{
				newElement = (new(ctx) DocumentVariable(ctx));
			}
						else 
			{
				newElement = (new(ctx) DocumentVariable(true, ctx));
			}
			current->set(newElement, iindex, ctx);
			current = newElement;
		}
		return current;
	}
	return (new(ctx) DocumentVariable(ctx));
}
IAlinousVariable* ExpStreamSegment::returnMemberVariable(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	AlinousClassVariable* obj = machine->getThisPtr(ctx);
	IAlinousVariable* retValue = obj->getMemberVariable(this->name, ctx);
	int maxLoop = this->arrayIndexes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IExpression* exp = this->arrayIndexes->get(i, ctx);
		IAlinousVariable* val = exp->resolveExpression(machine, debug, ctx);
		int index = val->getIntValue(ctx);
		retValue = (static_cast<TypedVariableArray*>(retValue))->get(index, ctx);
	}
	return retValue;
}
IAlinousVariable* ExpStreamSegment::addDescriptor(ScriptMachine* machine, IdentifierVariable* lastIdentifier, bool debug, ThreadContext* ctx)
{
	DomVariableDescriptor* domDesc = lastIdentifier->getDomDescriptor(ctx);
	DomNameSegment* nameSegment = (new(ctx) DomNameSegment(ctx));
	nameSegment->setName(this->name, ctx);
	domDesc->addSegment(nameSegment, ctx);
	int maxLoop = this->arrayIndexes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IExpression* exp = this->arrayIndexes->get(i, ctx);
		IAlinousVariable* val = exp->resolveExpression(machine, debug, ctx);
		int index = val->getIntValue(ctx);
		DomIndexSegment* iseg = (new(ctx) DomIndexSegment(ctx));
		iseg->setIndex(Literal::intLiteral(index, ctx), ctx);
		domDesc->addSegment(iseg, ctx);
	}
	return lastIdentifier;
}
IAlinousVariable* ExpStreamSegment::getClassMemberVariable(ScriptMachine* machine, AlinousClassVariable* classVariable, ThreadContext* ctx) throw() 
{
	IAlinousVariable* val = classVariable->getMemberVariable(this->name, ctx);
	return val;
}
IAlinousVariable* ExpStreamSegment::getDomProperty(ScriptMachine* machine, IDomVariable* lastSegmentVariable, bool debug, ThreadContext* ctx)
{
	if(lastSegmentVariable->getDomType(ctx) == IDomVariable::TYPE_ARRAY)
	{
		throw (new(ctx) VariableException(ConstStr::getCNST_STR_1051(), ctx));
	}
	IDomVariable* dom = static_cast<IDomVariable*>(lastSegmentVariable);
	IDomVariable* prop = static_cast<IDomVariable*>(dom->getProperty(this->name, ctx));
	if(!this->arrayIndexes->isEmpty(ctx))
	{
		return handleDomArrayIndexes(machine, prop, debug, ctx);
	}
	return prop;
}
IDomVariable* ExpStreamSegment::handleDomArrayIndexes(ScriptMachine* machine, IDomVariable* prop, bool debug, ThreadContext* ctx)
{
	IDomVariable* current = prop;
	int maxLoop = this->arrayIndexes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		if(current->getDomType(ctx) != IDomVariable::TYPE_ARRAY)
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1052(), ctx));
		}
		IExpression* idxexp = this->arrayIndexes->get(i, ctx);
		IAlinousVariable* val = idxexp->resolveExpression(machine, debug, ctx);
		int index = val->toIntVariable(ctx)->getIntValue(ctx);
		current = static_cast<IDomVariable*>(current->get(index, ctx));
	}
	return current;
}
IAlinousVariable* ExpStreamSegment::handleFirstSegment(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	if(this->prefix == nullptr)
	{
		return handleTypedObjectOrPrefix(machine, debug, ctx);
	}
	DomVariableDescriptor* desc = createDomDescriptor(machine, debug, ctx);
	if(machine->isLeftValue(ctx))
	{
		IdentifierVariable* dentifiler = (new(ctx) IdentifierVariable(desc, ctx));
		return dentifiler;
	}
	IAlinousVariable* dom = machine->getByDescriptor(desc, debug, ctx);
	machine->setStreamLastValue(dom, ctx);
	return dom;
}
DomVariableDescriptor* ExpStreamSegment::createDomDescriptor(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	DomVariableDescriptor* desc = (new(ctx) DomVariableDescriptor(ctx));
	desc->setPrefix(this->prefix, ctx);
	DomNameSegment* dseg = (new(ctx) DomNameSegment(ctx));
	dseg->setName(this->name, ctx);
	desc->addSegment(dseg, ctx);
	int maxLoop = this->arrayIndexes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IExpression* idxexp = this->arrayIndexes->get(i, ctx);
		IAlinousVariable* val = idxexp->resolveExpression(machine, debug, ctx);
		int index = val->toIntVariable(ctx)->getIntValue(ctx);
		DomIndexSegment* iseg = (new(ctx) DomIndexSegment(ctx));
		iseg->setIndex(Literal::intLiteral(index, ctx), ctx);
		desc->addSegment(iseg, ctx);
	}
	return desc;
}
IAlinousVariable* ExpStreamSegment::handleTypedObjectOrPrefix(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	if(machine->isLeftValue(ctx))
	{
		return (new(ctx) IdentifierVariable(this->name, this->arrayIndexes, ctx));
	}
	ITypedVariable* variable = machine->getTypedVariable(this->name, ctx);
	if(variable != nullptr)
	{
		if(!this->arrayIndexes->isEmpty(ctx))
		{
			return handleTypedArrayIndexes(machine, variable, debug, ctx);
		}
		return variable;
	}
	return (new(ctx) IdentifierVariable(this->name, ctx));
}
IAlinousVariable* ExpStreamSegment::handleTypedArrayIndexes(ScriptMachine* machine, ITypedVariable* variable, bool debug, ThreadContext* ctx)
{
	ITypedVariable* current = variable;
	int maxLoop = this->arrayIndexes->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		if(current->getTypedType(ctx) != ITypedVariable::TYPE_ARRAY)
		{
			throw (new(ctx) VariableException(ConstStr::getCNST_STR_1052(), ctx));
		}
		IExpression* idxexp = this->arrayIndexes->get(i, ctx);
		IAlinousVariable* val = idxexp->resolveExpression(machine, debug, ctx);
		int index = val->toIntVariable(ctx)->getIntValue(ctx);
		current = (static_cast<TypedVariableArray*>(current))->get(index, ctx);
	}
	return current;
}
bool ExpStreamSegment::analyseAfterDom(ExpressionStreamResult* result, SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	DomVariableDescriptor* desc = result->getDomPath(ctx);
	if(desc == nullptr)
	{
		return memberDomVariable(result, context, leftValue, ctx);
	}
	DomNameSegment* seg = (new(ctx) DomNameSegment(ctx));
	seg->setName(this->name, ctx);
	desc->addSegment(seg, ctx);
	ExpressionSourceId* id = desc->getSourceId(ctx);
	String* idStr = id->getId(ctx);
	VariableDeclareHolder* holder = context->getCurrentStack(ctx);
	this->segmentType = SegmentType::SEG_DOM_PROPERTY;
	__GC_MV(this, &(this->domPath), desc, DomVariableDescriptor);
	__GC_MV(this, &(this->analysedType), nullptr, AlinousType);
	__GC_MV(this, &(this->domDeclare), holder->getDomDeclare(ctx)->get(idStr, ctx), DomVariableDeclareSource);
	AlinousType* alinousType = (new(ctx) AlinousType(ctx));
	result->clear(ctx);
	result->setDomPath(desc, ctx);
	result->setType(alinousType, ctx);
	return true;
}
bool ExpStreamSegment::memberDomVariable(ExpressionStreamResult* result, SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	this->segmentType = SegmentType::SEG_MEMBER_DOM_VARIABLE;
	__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(AlinousType::NULL_TYPE, AlinousType::TYPE_DOM, ctx)), AlinousType);
	result->clear(ctx);
	result->setType(this->analysedType, ctx);
	return true;
}
bool ExpStreamSegment::analyseAfterClassObject(ExpressionStreamResult* result, SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	AlinousType* lastType = result->getType(ctx);
	int type = lastType->getTypeClass(ctx);
	if(type != AlinousType::TYPE_CLASS_OBJ)
	{
		return false;
	}
	if(result->isStaticMember(ctx))
	{
		AlinousClass* clazz = lastType->getClazz(ctx);
		ClassMemberVariable* val = clazz->getStaticMemberVariable(this->name, ctx);
		__GC_MV(this, &(this->staticVariableDef), val, ClassMemberVariable);
		__GC_MV(this, &(this->analysedType), val->getAnalysedType(ctx), AlinousType);
		this->segmentType = SegmentType::SEG_STATIC_VARIABLE;
		result->clear(ctx);
		result->setType(this->analysedType, ctx);
		return true;
	}
	AlinousClass* clazz = lastType->getClazz(ctx);
	ClassMemberVariable* val = clazz->getMember(this->name, ctx);
	this->segmentType = SegmentType::SEG_MEMBER_VARIABLE;
	__GC_MV(this, &(this->analysedType), val->getAnalysedType(ctx), AlinousType);
	__GC_MV(this, &(this->memberVariableDef), val, ClassMemberVariable);
	result->clear(ctx);
	result->setType(this->analysedType, ctx);
	return true;
}
bool ExpStreamSegment::analyseFirstSegment(ExpressionStreamResult* result, SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->prefix == nullptr)
	{
		return analyseFirstObject(result, context, leftValue, ctx);
	}
	DomVariableDescriptor* desc = (new(ctx) DomVariableDescriptor(ctx));
	result->setDomPath(desc, ctx);
	DomNameSegment* seg = (new(ctx) DomNameSegment(ctx));
	seg->setName(this->name, ctx);
	desc->addSegment(seg, ctx);
	ExpressionSourceId* id = desc->getSourceId(ctx);
	String* idStr = id->getId(ctx);
	VariableDeclareHolder* holder = context->getCurrentStack(ctx);
	this->segmentType = SegmentType::SEG_DOM_PROPERTY;
	__GC_MV(this, &(this->domPath), desc, DomVariableDescriptor);
	__GC_MV(this, &(this->analysedType), nullptr, AlinousType);
	__GC_MV(this, &(this->domDeclare), holder->getDomDeclare(ctx)->get(idStr, ctx), DomVariableDeclareSource);
	AlinousType* alinousType = (new(ctx) AlinousType(ctx));
	result->clear(ctx);
	result->setDomPath(desc, ctx);
	result->setType(alinousType, ctx);
	if(leftValue && result->isLastSegment(ctx))
	{
		DomVariableDeclareSource* srcDeclare = (new(ctx) DomVariableDeclareSource(idStr, this, ctx));
		holder->getDomDeclare(ctx)->put(idStr, srcDeclare, ctx);
	}
	return true;
}
bool ExpStreamSegment::analyseFirstObject(ExpressionStreamResult* result, SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw() 
{
	if(this->name->equals(ConstStr::getCNST_STR_1053(), ctx))
	{
		this->segmentType = SegmentType::SEG_THIS;
		result->clear(ctx);
		AlinousClass* clazz = getAlinousClass(ctx);
		__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(clazz, ctx)), AlinousType);
		result->setType(this->analysedType, ctx);
		return true;
	}
	VariableDeclareHolder* holder = context->getCurrentStack(ctx);
	TypedVariableDeclareSource* dec = holder->getTypedVariableDeclare(this->name, ctx);
	if(dec == nullptr)
	{
		AlinousClass* thisclazz = getAlinousClass(ctx);
		ClassMethodFunction* functionScope = getClassMethodFunction(ctx);
		if(thisclazz != nullptr && functionScope != nullptr && !functionScope->isStatic(ctx))
		{
			ClassMemberVariable* memberVariable = thisclazz->getMember(this->name, ctx);
			if(memberVariable != nullptr)
			{
				__GC_MV(this, &(this->analysedType), memberVariable->getAnalysedType(ctx), AlinousType);
				__GC_MV(this, &(this->memberVariableDef), memberVariable, ClassMemberVariable);
				this->segmentType = SegmentType::SEG_MEMBER_VARIABLE;
				result->clear(ctx);
				result->setType(this->analysedType, ctx);
				return true;
			}
		}
		if(context->isFunctionPrefix(this->name, ctx))
		{
			this->segmentType = SegmentType::SEG_FUNC_PREFIX;
			result->clear(ctx);
			result->setFunctionPrefix(this->name, ctx);
			return true;
		}
		AlinousName* aname = (new(ctx) AlinousName(ctx));
		aname->addSegment(this->name, ctx);
		AlinousClass* clazz = context->findClassDeclare(aname, ctx);
		if(clazz != nullptr)
		{
			this->segmentType = SegmentType::SEG_STATIC_CLASS_PREFIX;
			__GC_MV(this, &(this->analysedType), (new(ctx) AlinousType(clazz, ctx)), AlinousType);
			result->clear(ctx);
			result->setType(this->analysedType, ctx);
			result->setStaticMember(true, ctx);
			return true;
		}
		return false;
	}
	__GC_MV(this, &(this->typedDeclare), dec->getTypedVariableDeclare(ctx), TypedVariableDeclare);
	if(this->typedDeclare != nullptr)
	{
		__GC_MV(this, &(this->analysedType), typedDeclare->getAnalysedType(ctx), AlinousType);
	}
	__GC_MV(this, &(this->argumentDeclare), dec->getArgumentDefine(ctx), FunctionArgumentDefine);
	if(this->argumentDeclare != nullptr)
	{
		__GC_MV(this, &(this->analysedType), argumentDeclare->getAnalysedType(ctx), AlinousType);
	}
	this->segmentType = SegmentType::SEG_VARIABLE;
	result->clear(ctx);
	result->setType(this->analysedType, ctx);
	return true;
}
void ExpStreamSegment::__cleanUp(ThreadContext* ctx){
}
}}}}


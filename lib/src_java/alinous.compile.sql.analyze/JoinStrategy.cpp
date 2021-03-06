#include "include/global.h"


#include "alinous.buffer.storage/FileStorageEntryBuilder.h"
#include "alinous.buffer.storage/FileStorageEntryFetcher.h"
#include "alinous.compile/ExpressionSourceId.h"
#include "alinous.compile/IAlinousVisitorContainer.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.remote.socket/ICommandData.h"
#include "alinous.compile/IAlinousElement.h"
#include "alinous.compile.declare/IDeclare.h"
#include "alinous.remote.socket/NetworkBinaryBuffer.h"
#include "alinous.compile.declare.function/AlinousFunction.h"
#include "alinous.compile.declare/ClassMemberModifiers.h"
#include "alinous.compile.declare/IClassMember.h"
#include "alinous.compile.declare/AbstractClassMember.h"
#include "alinous.compile.declare/ClassMethodFunction.h"
#include "alinous.compile/Token.h"
#include "alinous.runtime.dom/IAlinousVariable.h"
#include "alinous.runtime.engine/ScriptMachine.h"
#include "alinous.compile.declare/AlinousClass.h"
#include "alinous.compile.analyse/SrcAnalyseContext.h"
#include "alinous.compile.expression/IExpression.h"
#include "alinous.compile.sql.analyze/ScanTableMetadata.h"
#include "alinous.compile.sql.analyze/SQLAnalyseContext.h"
#include "alinous.compile.sql.expression/ISQLExpression.h"
#include "alinous.compile.sql.analyze/IndexConditionDetector.h"
#include "alinous.compile.sql.analyze/JoinStrategyPart.h"
#include "alinous.compile.sql.analyze/JoinConditionDetector.h"
#include "alinous.compile.sql.analyze/JoinStrategy.h"

namespace alinous {namespace compile {namespace sql {namespace analyze {





bool JoinStrategy::__init_done = __init_static_variables();
bool JoinStrategy::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"JoinStrategy", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 JoinStrategy::JoinStrategy(bool inner, ThreadContext* ctx) throw()  : IObject(ctx), joinCondition(nullptr), whereCondition(nullptr), joinPart(nullptr), innerPart(nullptr), inner(0), bestParts(nullptr)
{
	this->inner = inner;
}
void JoinStrategy::__construct_impl(bool inner, ThreadContext* ctx) throw() 
{
	this->inner = inner;
}
 JoinStrategy::~JoinStrategy() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void JoinStrategy::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"JoinStrategy", L"~JoinStrategy");
	__e_obj1.add(this->joinCondition, this);
	joinCondition = nullptr;
	__e_obj1.add(this->whereCondition, this);
	whereCondition = nullptr;
	__e_obj1.add(this->joinPart, this);
	joinPart = nullptr;
	__e_obj1.add(this->innerPart, this);
	innerPart = nullptr;
	__e_obj1.add(this->bestParts, this);
	bestParts = nullptr;
	if(!prepare){
		return;
	}
}
void JoinStrategy::analyze(SQLAnalyseContext* context, ScanTableMetadata* leftMetadata, ScanTableMetadata* rightMetadata, ThreadContext* ctx) throw() 
{
	if(this->joinCondition != nullptr)
	{
		GCUtils<ArrayList<JoinStrategyPart> >::mv(this, &(this->joinPart), JoinConditionDetector::getJoinPart(context, leftMetadata, rightMetadata, this->joinCondition, ctx), ctx);
	}
	if(this->whereCondition != nullptr)
	{
		GCUtils<ArrayList<JoinStrategyPart> >::mv(this, &(this->innerPart), JoinConditionDetector::getJoinPart(context, leftMetadata, rightMetadata, this->whereCondition, ctx), ctx);
	}
	analyzeBestJoinKey(ctx);
}
void JoinStrategy::setJoinCondition(ISQLExpression* joinCondition, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->joinCondition), joinCondition, ISQLExpression);
}
void JoinStrategy::setWhereCondition(ISQLExpression* whereCondition, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->whereCondition), whereCondition, ISQLExpression);
}
ISQLExpression* JoinStrategy::getJoinCondition(ThreadContext* ctx) throw() 
{
	return joinCondition;
}
ArrayList<JoinStrategyPart>* JoinStrategy::getJoinPart(ThreadContext* ctx) throw() 
{
	return joinPart;
}
ArrayList<JoinStrategyPart>* JoinStrategy::getInnerPart(ThreadContext* ctx) throw() 
{
	return innerPart;
}
bool JoinStrategy::isInner(ThreadContext* ctx) throw() 
{
	return inner;
}
ArrayList<JoinStrategyPart>* JoinStrategy::getBestParts(ThreadContext* ctx) throw() 
{
	return bestParts;
}
void JoinStrategy::analyzeBestJoinKey(ThreadContext* ctx) throw() 
{
	ArrayList<JoinStrategyPart>* joinParts = nullptr;
	if(this->innerPart != nullptr && this->innerPart->size(ctx) == 1)
	{
		joinParts = this->innerPart;
		this->inner = true;
		GCUtils<ArrayList<JoinStrategyPart> >::mv(this, &(this->bestParts), this->innerPart, ctx);
	}
		else 
	{
		if(this->joinCondition != nullptr)
		{
			joinParts = this->joinPart;
			GCUtils<ArrayList<JoinStrategyPart> >::mv(this, &(this->bestParts), this->joinPart, ctx);
		}
				else 
		{
			return;
		}
	}
	int maxLoop = joinParts->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		JoinStrategyPart* part = joinParts->get(i, ctx);
		if(part->requireFullScan(ctx))
		{
			continue;
		}
		part->calcIindexStatus(ctx);
	}
}
void JoinStrategy::includes(IndexConditionDetector* arg0, JoinConditionDetector* arg1, ThreadContext* ctx) throw() 
{
}
void JoinStrategy::__cleanUp(ThreadContext* ctx){
}
}}}}


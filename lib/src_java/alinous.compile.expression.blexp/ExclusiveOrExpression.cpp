#include "includes.h"


namespace alinous {namespace compile {namespace expression {namespace blexp {





bool ExclusiveOrExpression::__init_done = __init_static_variables();
bool ExclusiveOrExpression::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"ExclusiveOrExpression", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 ExclusiveOrExpression::~ExclusiveOrExpression() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void ExclusiveOrExpression::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractBooleanCollectionExpression::__releaseRegerences(true, ctx);
}
IAlinousVariable* ExclusiveOrExpression::resolveExpression(ScriptMachine* machine, bool debug, ThreadContext* ctx)
{
	IAlinousVariable* val = machine->resolveExpression(this->first, debug, ctx);
	val = val->copy(ctx);
	int maxLoop = this->expressions->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		IExpression* exp = this->expressions->get(i, ctx);
		IAlinousVariable* operand = machine->resolveExpression(exp, debug, ctx);
		val = val->bitExor(operand, ctx);
	}
	return val;
}
int ExclusiveOrExpression::getExpressionType(ThreadContext* ctx) throw() 
{
	return IExpression::exclusiveOrExpression;
}
}}}}


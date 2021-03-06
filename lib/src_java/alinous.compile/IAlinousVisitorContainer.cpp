#include "include/global.h"


#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.compile/IAlinousElementVisitor.h"
#include "alinous.compile/IAlinousVisitorContainer.h"

namespace alinous {namespace compile {




bool IAlinousVisitorContainer::__init_done = __init_static_variables();
bool IAlinousVisitorContainer::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"IAlinousVisitorContainer", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 IAlinousVisitorContainer::IAlinousVisitorContainer(ThreadContext* ctx) throw()  : IObject(ctx)
{
}
void IAlinousVisitorContainer::__construct_impl(ThreadContext* ctx) throw() 
{
}
 IAlinousVisitorContainer::~IAlinousVisitorContainer() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void IAlinousVisitorContainer::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
void IAlinousVisitorContainer::__cleanUp(ThreadContext* ctx){
}
}}


#include "includes.h"


namespace alinous {namespace runtime {





bool AlinousModulePackage::__init_done = __init_static_variables();
bool AlinousModulePackage::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousModulePackage", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousModulePackage::AlinousModulePackage(String* path, ThreadContext* ctx) throw()  : IObject(ctx), segments(GCUtils<ArrayList<String> >::ins(this, (new(ctx) ArrayList<String>(ctx)), ctx, __FILEW__, __LINE__, L""))
{
	IArrayObject<String>* segments = path->split(ConstStr::getCNST_STR_984(), ctx);
	int maxLoop = segments->length;
	for(int i = 0; i != maxLoop; ++i)
	{
		String* seg = segments->get(i);
		int dot = seg->indexOf((int)L'.', ctx);
		if(dot >= 0)
		{
			seg = seg->substring(0, dot, ctx);
		}
		if(seg->length(ctx) == 0)
		{
			continue;
		}
		this->segments->add(seg, ctx);
	}
}
void AlinousModulePackage::__construct_impl(String* path, ThreadContext* ctx) throw() 
{
	IArrayObject<String>* segments = path->split(ConstStr::getCNST_STR_984(), ctx);
	int maxLoop = segments->length;
	for(int i = 0; i != maxLoop; ++i)
	{
		String* seg = segments->get(i);
		int dot = seg->indexOf((int)L'.', ctx);
		if(dot >= 0)
		{
			seg = seg->substring(0, dot, ctx);
		}
		if(seg->length(ctx) == 0)
		{
			continue;
		}
		this->segments->add(seg, ctx);
	}
}
 AlinousModulePackage::~AlinousModulePackage() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousModulePackage::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"AlinousModulePackage", L"~AlinousModulePackage");
	__e_obj1.add(this->segments, this);
	segments = nullptr;
	if(!prepare){
		return;
	}
}
bool AlinousModulePackage::equals(IObject* obj, ThreadContext* ctx) throw() 
{
	if(!((dynamic_cast<AlinousModulePackage*>(obj) != 0)))
	{
		return false;
	}
	AlinousModulePackage* other = dynamic_cast<AlinousModulePackage*>(obj);
	int maxLoop = this->segments->size(ctx);
	if(maxLoop != other->segments->size(ctx))
	{
		return false;
	}
	for(int i = 0; i != maxLoop; ++i)
	{
		if(!this->segments->get(i, ctx)->equals(other->segments->get(i, ctx), ctx))
		{
			return false;
		}
	}
	return true;
}
String* AlinousModulePackage::toString(ThreadContext* ctx) throw() 
{
	StringBuffer* buff = (new(ctx) StringBuffer(ctx));
	int maxLoop = segments->size(ctx);
	for(int i = 0; i != maxLoop; ++i)
	{
		String* seg = this->segments->get(i, ctx);
		if(i != 0)
		{
			buff->append(ConstStr::getCNST_STR_947(), ctx);
		}
		buff->append(seg, ctx);
	}
	return buff->toString(ctx);
}
}}


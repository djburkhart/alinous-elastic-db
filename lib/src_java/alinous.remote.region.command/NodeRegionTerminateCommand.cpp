#include "includes.h"


namespace alinous {namespace remote {namespace region {namespace command {





bool NodeRegionTerminateCommand::__init_done = __init_static_variables();
bool NodeRegionTerminateCommand::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"NodeRegionTerminateCommand", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 NodeRegionTerminateCommand::NodeRegionTerminateCommand(ThreadContext* ctx) throw()  : IObject(ctx), AbstractNodeRegionCommand(ctx)
{
	this->type = NodeRegionVoidCommand::TYPE_TERMINATE;
}
void NodeRegionTerminateCommand::__construct_impl(ThreadContext* ctx) throw() 
{
	this->type = NodeRegionVoidCommand::TYPE_TERMINATE;
}
 NodeRegionTerminateCommand::~NodeRegionTerminateCommand() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void NodeRegionTerminateCommand::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
	AbstractNodeRegionCommand::__releaseRegerences(true, ctx);
}
void NodeRegionTerminateCommand::readFromStream(InputStream* stream, ThreadContext* ctx)
{
}
void NodeRegionTerminateCommand::writeByteStream(OutputStream* out, ThreadContext* ctx)
{
	ByteBuffer* buffer = ByteBuffer::allocate(256, ctx);
	buffer->putInt(this->type, ctx);
	IArrayObjectPrimitive<char>* bytes = buffer->array(ctx);
	out->write(bytes, ctx);
}
}}}}

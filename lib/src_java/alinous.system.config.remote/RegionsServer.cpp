#include "include/global.h"


#include "alinous.html.xpath/IVariableValue.h"
#include "alinous.html/IDomObject.h"
#include "alinous.html/Attribute.h"
#include "alinous.html/DomNode.h"
#include "alinous.html/DomDocument.h"
#include "alinous.html.xpath.match/MatchCandidate.h"
#include "alinous.html.xpath.match/MatchingException.h"
#include "alinous.html.xpath.match/MatchCandidatesCollection.h"
#include "alinous.parser.xpath/ParseException.h"
#include "alinous.html.xpath.match/Matcher.h"
#include "alinous.compile/Token.h"
#include "alinous.compile/AbstractSrcElement.h"
#include "alinous.system/AlinousException.h"
#include "alinous.system.config/AlinousInitException.h"
#include "alinous.system.config/IAlinousConfigElement.h"
#include "alinous.system.config.remote/MonitorRef.h"
#include "alinous.system.config.remote/RegionsServer.h"

namespace alinous {namespace system {namespace config {namespace remote {





bool RegionsServer::__init_done = __init_static_variables();
bool RegionsServer::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"RegionsServer", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 RegionsServer::RegionsServer(ThreadContext* ctx) throw()  : IObject(ctx), IAlinousConfigElement(ctx), port(0), maxCon(8), monitorRef(nullptr), region(nullptr)
{
}
void RegionsServer::__construct_impl(ThreadContext* ctx) throw() 
{
}
 RegionsServer::~RegionsServer() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void RegionsServer::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	ObjectEraser __e_obj1(ctx, __FILEW__, __LINE__, L"RegionsServer", L"~RegionsServer");
	__e_obj1.add(this->monitorRef, this);
	monitorRef = nullptr;
	__e_obj1.add(this->region, this);
	region = nullptr;
	if(!prepare){
		return;
	}
}
int RegionsServer::getPort(ThreadContext* ctx) throw() 
{
	return port;
}
void RegionsServer::setPort(int port, ThreadContext* ctx) throw() 
{
	this->port = port;
}
int RegionsServer::getMaxCon(ThreadContext* ctx) throw() 
{
	return maxCon;
}
void RegionsServer::setMaxCon(int maxCon, ThreadContext* ctx) throw() 
{
	this->maxCon = maxCon;
}
MonitorRef* RegionsServer::getMonitorRef(ThreadContext* ctx) throw() 
{
	return monitorRef;
}
void RegionsServer::setMonitorRef(MonitorRef* monitorRef, ThreadContext* ctx) throw() 
{
	__GC_MV(this, &(this->monitorRef), monitorRef, MonitorRef);
}
String* RegionsServer::getRegion(ThreadContext* ctx) throw() 
{
	return region;
}
RegionsServer* RegionsServer::parseInstance(MatchCandidate* candidate, DomDocument* document, Matcher* matcher, ThreadContext* ctx)
{
	RegionsServer* regions = (new(ctx) RegionsServer(ctx));
	DomNode* selfDom = candidate->getCandidateDom(ctx);
	IVariableValue* attr = selfDom->getAttributeValue(ConstStr::getCNST_STR_977(), ctx);
	if(attr == nullptr)
	{
		throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_990(), ctx));
	}
	{
		try
		{
			int port = Integer::parseInt(attr->toString(ctx)->trim(ctx), ctx);
			regions->setPort(port, ctx);
		}
		catch(Throwable* e)
		{
			throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_991(), ctx));
		}
	}
	attr = selfDom->getAttributeValue(ConstStr::getCNST_STR_992(), ctx);
	if(attr != nullptr)
	{
		{
			try
			{
				int n = Integer::parseInt(attr->toString(ctx)->trim(ctx), ctx);
				regions->setMaxCon(n, ctx);
			}
			catch(Throwable* e)
			{
				throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_991(), ctx));
			}
		}
	}
	MatchCandidatesCollection* result = matcher->match(document, selfDom, ConstStr::getCNST_STR_976(), ctx);
	ArrayList<MatchCandidate>* list = result->getCandidatesList(ctx);
	if(list->isEmpty(ctx))
	{
		throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_993(), ctx));
	}
		else 
	{
		if(list->size(ctx) != 1)
		{
			throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_994(), ctx));
		}
	}
	MatchCandidate* moncandidate = list->get(0, ctx);
	MonitorRef* monitorRef = MonitorRef::parseInstance(moncandidate, document, matcher, ctx);
	regions->setMonitorRef(monitorRef, ctx);
	result = matcher->match(document, selfDom, ConstStr::getCNST_STR_995(), ctx);
	list = result->getCandidatesList(ctx);
	if(list->isEmpty(ctx))
	{
		throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_996(), ctx));
	}
		else 
	{
		if(list->size(ctx) != 1)
		{
			throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_997(), ctx));
		}
	}
	moncandidate = list->get(0, ctx);
	DomNode* regionDom = moncandidate->getCandidateDom(ctx);
	attr = regionDom->getAttributeValue(ConstStr::getCNST_STR_998(), ctx);
	if(attr == nullptr)
	{
		throw (new(ctx) AlinousInitException(ConstStr::getCNST_STR_999(), ctx));
	}
	__GC_MV(regions, &(regions->region), attr->toString(ctx)->trim(ctx), String);
	return regions;
}
void RegionsServer::__cleanUp(ThreadContext* ctx){
}
}}}}


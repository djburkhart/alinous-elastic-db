#ifndef ALINOUS_SYSTEM_CONFIG_MAILINFO_H_
#define ALINOUS_SYSTEM_CONFIG_MAILINFO_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace system {namespace config {
class IAlinousConfigElement;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace system {namespace config {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class MailInfo final : public IAlinousConfigElement, public virtual IObject {
public:
	MailInfo(const MailInfo& base) = default;
public:
	MailInfo(ThreadContext* ctx) throw() ;
	void __construct_impl(ThreadContext* ctx) throw() ;
	virtual ~MailInfo() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_SYSTEM_CONFIG_MAILINFO_H_ */

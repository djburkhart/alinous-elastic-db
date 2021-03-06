#ifndef ALINOUS_HTML_XPATH_NUMBERVALUE_H_
#define ALINOUS_HTML_XPATH_NUMBERVALUE_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace html {namespace xpath {
class IVariableValue;}}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace html {namespace xpath {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;



class NumberValue final : public IVariableValue, public virtual IObject {
public:
	NumberValue(const NumberValue& base) = default;
public:
	NumberValue(int v, ThreadContext* ctx) throw() ;
	void __construct_impl(int v, ThreadContext* ctx) throw() ;
	virtual ~NumberValue() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	int value;
public:
	int getValue(ThreadContext* ctx) throw() ;
	String* toString(ThreadContext* ctx) throw()  final;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx);
};

}}}

#endif /* end of ALINOUS_HTML_XPATH_NUMBERVALUE_H_ */

#ifndef ALINOUS_COMPILE_STMT_STATEMENTBLOCK_H_
#define ALINOUS_COMPILE_STMT_STATEMENTBLOCK_H_
namespace alinous{namespace annotation{
class OneSource;
}}
namespace alinous {namespace compile {
class IAlinousElementVisitor;}}

namespace alinous {namespace compile {
class AbstractSrcElement;}}

namespace alinous {namespace compile {
class IStatement;}}

namespace alinous {namespace compile {namespace analyse {
class SrcAnalyseContext;}}}

namespace alinous {namespace compile {namespace declare {namespace function {
class AlinousFunction;}}}}

namespace alinous {namespace compile {namespace declare {namespace function {
class FunctionArgumentsListDefine;}}}}

namespace alinous {namespace compile {namespace analyse {
class VariableDeclareHolder;}}}

namespace alinous {namespace compile {namespace declare {namespace function {
class FunctionArgumentDefine;}}}}

namespace alinous {namespace compile {namespace stmt {
class StatementList;}}}

namespace alinous {namespace compile {namespace analyse {
class SourceValidator;}}}

namespace alinous {namespace compile {namespace stmt {
class AbstractAlinousStatement;}}}

namespace alinous {
class ThreadContext;
}

namespace alinous {namespace compile {namespace stmt {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::java::util::ArrayList;
using ::alinous::compile::AbstractSrcElement;
using ::alinous::compile::IAlinousElementVisitor;
using ::alinous::compile::IStatement;
using ::alinous::compile::analyse::SourceValidator;
using ::alinous::compile::analyse::SrcAnalyseContext;
using ::alinous::compile::analyse::VariableDeclareHolder;
using ::alinous::compile::declare::function::AlinousFunction;
using ::alinous::compile::declare::function::FunctionArgumentDefine;
using ::alinous::compile::declare::function::FunctionArgumentsListDefine;



class StatementBlock final : public AbstractAlinousStatement {
public:
	StatementBlock(const StatementBlock& base) = default;
public:
	StatementBlock(ThreadContext* ctx) throw()  : IObject(ctx), AbstractAlinousStatement(ctx), list(nullptr)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~StatementBlock() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
private:
	StatementList* list;
public:
	bool visit(IAlinousElementVisitor* visitor, AbstractSrcElement* parent, ThreadContext* ctx) throw()  final;
	IStatement* getFirstStatement(ThreadContext* ctx) throw() ;
	bool analyse(SrcAnalyseContext* context, bool leftValue, ThreadContext* ctx) throw()  final;
	StatementList* getList(ThreadContext* ctx) throw() ;
	void setList(StatementList* list, ThreadContext* ctx) throw() ;
	IStatement::StatementType getType(ThreadContext* ctx) throw()  final;
	void validate(SourceValidator* validator, ThreadContext* ctx) throw()  final;
private:
	void addArgumentsToAnalysingStack(AlinousFunction* func, SrcAnalyseContext* context, ThreadContext* ctx) throw() ;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of ALINOUS_COMPILE_STMT_STATEMENTBLOCK_H_ */

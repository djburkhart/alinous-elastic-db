#include "includes.h"


namespace alinous {namespace parser {namespace xpath {




constexpr const long long AlinousXpathParserConstants::EOF;
constexpr const long long AlinousXpathParserConstants::NOTASCII;
constexpr const long long AlinousXpathParserConstants::ASCILETTER;
constexpr const long long AlinousXpathParserConstants::NUMBERLETTER;
constexpr const long long AlinousXpathParserConstants::CHARACTOR;
constexpr const long long AlinousXpathParserConstants::SEMI_COLON;
constexpr const long long AlinousXpathParserConstants::EQUALS;
constexpr const long long AlinousXpathParserConstants::ASTERISK;
constexpr const long long AlinousXpathParserConstants::PLUSPLUS;
constexpr const long long AlinousXpathParserConstants::PLUS;
constexpr const long long AlinousXpathParserConstants::MINUSMINUS;
constexpr const long long AlinousXpathParserConstants::MINUS;
constexpr const long long AlinousXpathParserConstants::DIV;
constexpr const long long AlinousXpathParserConstants::MODULO;
constexpr const long long AlinousXpathParserConstants::LOGICAL_AND;
constexpr const long long AlinousXpathParserConstants::LOGICAL_OR;
constexpr const long long AlinousXpathParserConstants::BIT_AND;
constexpr const long long AlinousXpathParserConstants::BIT_OR;
constexpr const long long AlinousXpathParserConstants::L_PARENTHESIS;
constexpr const long long AlinousXpathParserConstants::R_PARENTHESIS;
constexpr const long long AlinousXpathParserConstants::L_BRACKET;
constexpr const long long AlinousXpathParserConstants::R_BRACKET;
constexpr const long long AlinousXpathParserConstants::DOLLAR;
constexpr const long long AlinousXpathParserConstants::DOT;
constexpr const long long AlinousXpathParserConstants::COMMA;
constexpr const long long AlinousXpathParserConstants::SQL_NOT_EQUALS;
constexpr const long long AlinousXpathParserConstants::AT_AT_MARK;
constexpr const long long AlinousXpathParserConstants::AT_MARK;
constexpr const long long AlinousXpathParserConstants::L_BRACE;
constexpr const long long AlinousXpathParserConstants::R_BRACE;
constexpr const long long AlinousXpathParserConstants::CMP_EQUALS;
constexpr const long long AlinousXpathParserConstants::CMP_NOTEQUALS;
constexpr const long long AlinousXpathParserConstants::GT;
constexpr const long long AlinousXpathParserConstants::GEQ;
constexpr const long long AlinousXpathParserConstants::LT;
constexpr const long long AlinousXpathParserConstants::LEQ;
constexpr const long long AlinousXpathParserConstants::NOT;
constexpr const long long AlinousXpathParserConstants::COLON;
constexpr const long long AlinousXpathParserConstants::XPATH_AND;
constexpr const long long AlinousXpathParserConstants::XPATH_OR;
constexpr const long long AlinousXpathParserConstants::NOT_LIT;
constexpr const long long AlinousXpathParserConstants::IDENTIFIER;
constexpr const long long AlinousXpathParserConstants::NUMERIC;
constexpr const long long AlinousXpathParserConstants::DOUBLE;
constexpr const long long AlinousXpathParserConstants::DQSTRLIT;
constexpr const long long AlinousXpathParserConstants::SQSTRLIT;
constexpr const long long AlinousXpathParserConstants::DEFAULT;
constexpr const long long AlinousXpathParserConstants::SQ_STR;
constexpr const long long AlinousXpathParserConstants::DQ_STR;
const StaticArrayObject<UnicodeStringWrapper> AlinousXpathParserConstants::__tokenImage = {ConstStr::getCNST_STR_1313(), ConstStr::getCNST_STR_1314(), ConstStr::getCNST_STR_1315(), ConstStr::getCNST_STR_1316(), ConstStr::getCNST_STR_1317(), ConstStr::getCNST_STR_1318(), ConstStr::getCNST_STR_1319(), ConstStr::getCNST_STR_1320(), ConstStr::getCNST_STR_1321(), ConstStr::getCNST_STR_1334(), ConstStr::getCNST_STR_1335(), ConstStr::getCNST_STR_1336(), ConstStr::getCNST_STR_1337(), ConstStr::getCNST_STR_1338(), ConstStr::getCNST_STR_1339(), ConstStr::getCNST_STR_1340(), ConstStr::getCNST_STR_1341(), ConstStr::getCNST_STR_1342(), ConstStr::getCNST_STR_1343(), ConstStr::getCNST_STR_1344(), ConstStr::getCNST_STR_1345(), ConstStr::getCNST_STR_1346(), ConstStr::getCNST_STR_1347(), ConstStr::getCNST_STR_1348(), ConstStr::getCNST_STR_1349(), ConstStr::getCNST_STR_1350(), ConstStr::getCNST_STR_1351(), ConstStr::getCNST_STR_1352(), ConstStr::getCNST_STR_1353(), ConstStr::getCNST_STR_1519(), ConstStr::getCNST_STR_1354(), ConstStr::getCNST_STR_1355(), ConstStr::getCNST_STR_1356(), ConstStr::getCNST_STR_1357(), ConstStr::getCNST_STR_1358(), ConstStr::getCNST_STR_1359(), ConstStr::getCNST_STR_1360(), ConstStr::getCNST_STR_1361(), ConstStr::getCNST_STR_1362(), ConstStr::getCNST_STR_1363(), ConstStr::getCNST_STR_1364(), ConstStr::getCNST_STR_1365(), ConstStr::getCNST_STR_1756(), ConstStr::getCNST_STR_1757(), ConstStr::getCNST_STR_1758(), ConstStr::getCNST_STR_1499(), ConstStr::getCNST_STR_1759(), ConstStr::getCNST_STR_1760(), ConstStr::getCNST_STR_1761(), ConstStr::getCNST_STR_1762(), ConstStr::getCNST_STR_1761(), ConstStr::getCNST_STR_1763(), ConstStr::getCNST_STR_1764(), ConstStr::getCNST_STR_1765(), ConstStr::getCNST_STR_1762(), ConstStr::getCNST_STR_1766(), ConstStr::getCNST_STR_1763(), ConstStr::getCNST_STR_1767(), ConstStr::getCNST_STR_1768()};
IArrayObject<String>* AlinousXpathParserConstants::tokenImage = (IArrayObject<String>*)const_cast<StaticArrayObject<UnicodeStringWrapper>*>(&__tokenImage);
bool AlinousXpathParserConstants::__init_done = __init_static_variables();
bool AlinousXpathParserConstants::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"AlinousXpathParserConstants", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 AlinousXpathParserConstants::~AlinousXpathParserConstants() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void AlinousXpathParserConstants::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
}}}


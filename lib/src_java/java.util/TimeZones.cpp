#include "includes.h"


namespace java {namespace util {





constexpr const int TimeZones::HALF_HOUR;
constexpr const int TimeZones::ONE_HOUR;
bool TimeZones::__init_done = __init_static_variables();
bool TimeZones::__init_static_variables(){
	Java2CppSystem::getSelf();
	ThreadContext* ctx = ThreadContext::newThreadContext();
	{
		GCNotifier __refobj1(ctx, __FILEW__, __LINE__, L"TimeZones", L"__init_static_variables");
	}
	ctx->localGC();
	delete ctx;
	return true;
}
 TimeZones::~TimeZones() throw() 
{
	ThreadContext *ctx = ThreadContext::getCurentContext();
	if(ctx != nullptr){ctx->incGcDenial();}
	__releaseRegerences(false, ctx);
	if(ctx != nullptr){ctx->decGcDenial();}
}
void TimeZones::__releaseRegerences(bool prepare, ThreadContext* ctx) throw() 
{
	if(!prepare){
		return;
	}
}
IArrayObject<TimeZone>* TimeZones::getTimeZones(ThreadContext* ctx) throw() 
{
	return ((IArrayObject<TimeZone>*)new(ctx) ArrayObject<TimeZone>({(new(ctx) SimpleTimeZone(-11 * ONE_HOUR, ConstStr::getCNST_STR_566(), ctx)), (new(ctx) SimpleTimeZone(-10 * ONE_HOUR, ConstStr::getCNST_STR_567(), ctx)), (new(ctx) SimpleTimeZone(-9 * ONE_HOUR, ConstStr::getCNST_STR_568(), Calendar::APRIL, 1, -Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(-8 * ONE_HOUR, ConstStr::getCNST_STR_26(), Calendar::APRIL, 1, -Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(-7 * ONE_HOUR, ConstStr::getCNST_STR_24(), Calendar::APRIL, 1, -Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(-7 * ONE_HOUR, ConstStr::getCNST_STR_569(), ctx)), (new(ctx) SimpleTimeZone(-6 * ONE_HOUR, ConstStr::getCNST_STR_22(), Calendar::APRIL, 1, -Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(-5 * ONE_HOUR, ConstStr::getCNST_STR_20(), Calendar::APRIL, 1, -Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(-5 * ONE_HOUR, ConstStr::getCNST_STR_570(), ctx)), (new(ctx) SimpleTimeZone(-4 * ONE_HOUR, ConstStr::getCNST_STR_571(), ctx)), (new(ctx) SimpleTimeZone(-3 * ONE_HOUR - 1800000, ConstStr::getCNST_STR_572(), Calendar::APRIL, 1, -Calendar::SUNDAY, 60000, Calendar::OCTOBER, -1, Calendar::SUNDAY, 60000, ctx)), (new(ctx) SimpleTimeZone(-3 * ONE_HOUR, ConstStr::getCNST_STR_573(), ctx)), (new(ctx) SimpleTimeZone(-3 * ONE_HOUR, ConstStr::getCNST_STR_574(), Calendar::OCTOBER, 8, -Calendar::SUNDAY, 0 * ONE_HOUR, Calendar::FEBRUARY, 15, -Calendar::SUNDAY, 0 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(0 * ONE_HOUR, ConstStr::getCNST_STR_575(), ctx)), (new(ctx) SimpleTimeZone(0 * ONE_HOUR, ConstStr::getCNST_STR_576(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(1 * ONE_HOUR, ConstStr::getCNST_STR_577(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(1 * ONE_HOUR, ConstStr::getCNST_STR_578(), Calendar::MARCH, 21, 0, 0 * ONE_HOUR, Calendar::SEPTEMBER, 23, 0, 0 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(2 * ONE_HOUR, ConstStr::getCNST_STR_579(), Calendar::APRIL, -1, Calendar::FRIDAY, 0 * ONE_HOUR, Calendar::SEPTEMBER, -1, Calendar::THURSDAY, 23 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(2 * ONE_HOUR, ConstStr::getCNST_STR_580(), ctx)), (new(ctx) SimpleTimeZone(2 * ONE_HOUR, ConstStr::getCNST_STR_581(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(3 * ONE_HOUR, ConstStr::getCNST_STR_582(), ctx)), (new(ctx) SimpleTimeZone(3 * ONE_HOUR + 1800000, ConstStr::getCNST_STR_583(), Calendar::MARCH, 21, 0, 0 * ONE_HOUR, Calendar::SEPTEMBER, 23, 0, 0 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(4 * ONE_HOUR, ConstStr::getCNST_STR_584(), Calendar::MARCH, -1, Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(5 * ONE_HOUR, ConstStr::getCNST_STR_585(), ctx)), (new(ctx) SimpleTimeZone(5 * ONE_HOUR + 1800000, ConstStr::getCNST_STR_586(), ctx)), (new(ctx) SimpleTimeZone(6 * ONE_HOUR, ConstStr::getCNST_STR_587(), ctx)), (new(ctx) SimpleTimeZone(7 * ONE_HOUR, ConstStr::getCNST_STR_588(), ctx)), (new(ctx) SimpleTimeZone(8 * ONE_HOUR, ConstStr::getCNST_STR_589(), ctx)), (new(ctx) SimpleTimeZone(9 * ONE_HOUR, ConstStr::getCNST_STR_590(), ctx)), (new(ctx) SimpleTimeZone(9 * ONE_HOUR + 1800000, ConstStr::getCNST_STR_591(), ctx)), (new(ctx) SimpleTimeZone(10 * ONE_HOUR, ConstStr::getCNST_STR_592(), Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::MARCH, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(11 * ONE_HOUR, ConstStr::getCNST_STR_593(), ctx)), (new(ctx) SimpleTimeZone(12 * ONE_HOUR, ConstStr::getCNST_STR_594(), Calendar::OCTOBER, 1, -Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::MARCH, 15, -Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(-6 * ONE_HOUR, ConstStr::getCNST_STR_595(), ctx)), (new(ctx) SimpleTimeZone(-4 * ONE_HOUR, ConstStr::getCNST_STR_596(), Calendar::APRIL, 1, -Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(-2 * ONE_HOUR, ConstStr::getCNST_STR_597(), ctx)), (new(ctx) SimpleTimeZone(0 * ONE_HOUR, ConstStr::getCNST_STR_598(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(1 * ONE_HOUR, ConstStr::getCNST_STR_599(), ctx)), (new(ctx) SimpleTimeZone(2 * ONE_HOUR, ConstStr::getCNST_STR_600(), Calendar::APRIL, -1, Calendar::FRIDAY, 0 * ONE_HOUR, Calendar::SEPTEMBER, -1, Calendar::THURSDAY, 23 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(2 * ONE_HOUR, ConstStr::getCNST_STR_601(), ctx)), (new(ctx) SimpleTimeZone(2 * ONE_HOUR, ConstStr::getCNST_STR_602(), Calendar::APRIL, 9, 0, 1 * ONE_HOUR, Calendar::SEPTEMBER, 24, 0, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(2 * ONE_HOUR, ConstStr::getCNST_STR_603(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(3 * ONE_HOUR, ConstStr::getCNST_STR_604(), Calendar::MARCH, -1, Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(4 * ONE_HOUR + 1800000, ConstStr::getCNST_STR_605(), ctx)), (new(ctx) SimpleTimeZone(9 * ONE_HOUR + 1800000, ConstStr::getCNST_STR_606(), Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::MARCH, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(10 * ONE_HOUR, ConstStr::getCNST_STR_607(), ctx)), (new(ctx) SimpleTimeZone(10 * ONE_HOUR, ConstStr::getCNST_STR_608(), Calendar::OCTOBER, 1, -Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::MARCH, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(-9 * ONE_HOUR - 1800000, ConstStr::getCNST_STR_609(), ctx)), (new(ctx) SimpleTimeZone(-1 * ONE_HOUR, ConstStr::getCNST_STR_610(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(4 * ONE_HOUR, ConstStr::getCNST_STR_611(), ctx)), (new(ctx) SimpleTimeZone(20700000, ConstStr::getCNST_STR_612(), ctx)), (new(ctx) SimpleTimeZone(6 * ONE_HOUR + 1800000, ConstStr::getCNST_STR_613(), ctx)), (new(ctx) SimpleTimeZone(45900000, ConstStr::getCNST_STR_614(), Calendar::OCTOBER, 1, -Calendar::SUNDAY, 9900000, Calendar::MARCH, 15, -Calendar::SUNDAY, 9900000, ctx)), (new(ctx) SimpleTimeZone(-11 * ONE_HOUR, ConstStr::getCNST_STR_615(), ctx)), (new(ctx) SimpleTimeZone(-11 * ONE_HOUR, ConstStr::getCNST_STR_616(), ctx)), (new(ctx) SimpleTimeZone(-11 * ONE_HOUR, ConstStr::getCNST_STR_617(), ctx)), (new(ctx) SimpleTimeZone(-10 * ONE_HOUR, ConstStr::getCNST_STR_618(), Calendar::APRIL, 1, -Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(-10 * ONE_HOUR, ConstStr::getCNST_STR_619(), ctx)), (new(ctx) SimpleTimeZone(-10 * ONE_HOUR, ConstStr::getCNST_STR_620(), ctx)), (new(ctx) SimpleTimeZone(-10 * ONE_HOUR, ConstStr::getCNST_STR_621(), ctx)), (new(ctx) SimpleTimeZone(-10 * ONE_HOUR, ConstStr::getCNST_STR_622(), ctx)), (new(ctx) SimpleTimeZone(-9 * ONE_HOUR, ConstStr::getCNST_STR_623(), Calendar::APRIL, 1, -Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(-9 * ONE_HOUR, ConstStr::getCNST_STR_624(), ctx)), (new(ctx) SimpleTimeZone(-8 * ONE_HOUR, ConstStr::getCNST_STR_625(), Calendar::APRIL, 1, -Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(-8 * ONE_HOUR, ConstStr::getCNST_STR_626(), Calendar::APRIL, 1, -Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(-8 * ONE_HOUR, ConstStr::getCNST_STR_627(), Calendar::APRIL, 1, -Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(-8 * ONE_HOUR, ConstStr::getCNST_STR_628(), ctx)), (new(ctx) SimpleTimeZone(-7 * ONE_HOUR, ConstStr::getCNST_STR_629(), ctx)), (new(ctx) SimpleTimeZone(-7 * ONE_HOUR, ConstStr::getCNST_STR_630(), Calendar::APRIL, 1, -Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(-7 * ONE_HOUR, ConstStr::getCNST_STR_631(), Calendar::APRIL, 1, -Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(-7 * ONE_HOUR, ConstStr::getCNST_STR_632(), Calendar::MAY, 1, -Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::SEPTEMBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(-7 * ONE_HOUR, ConstStr::getCNST_STR_633(), ctx)), (new(ctx) SimpleTimeZone(-6 * ONE_HOUR, ConstStr::getCNST_STR_634(), ctx)), (new(ctx) SimpleTimeZone(-6 * ONE_HOUR, ConstStr::getCNST_STR_635(), Calendar::APRIL, 1, -Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(-6 * ONE_HOUR, ConstStr::getCNST_STR_636(), ctx)), (new(ctx) SimpleTimeZone(-6 * ONE_HOUR, ConstStr::getCNST_STR_637(), ctx)), (new(ctx) SimpleTimeZone(-6 * ONE_HOUR, ConstStr::getCNST_STR_638(), Calendar::MAY, 1, -Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::SEPTEMBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(-6 * ONE_HOUR, ConstStr::getCNST_STR_639(), ctx)), (new(ctx) SimpleTimeZone(-6 * ONE_HOUR, ConstStr::getCNST_STR_640(), ctx)), (new(ctx) SimpleTimeZone(-6 * ONE_HOUR, ConstStr::getCNST_STR_641(), Calendar::APRIL, 1, -Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(-6 * ONE_HOUR, ConstStr::getCNST_STR_642(), Calendar::OCTOBER, 9, -Calendar::SUNDAY, 4 * ONE_HOUR, Calendar::MARCH, 9, -Calendar::SUNDAY, 3 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(-6 * ONE_HOUR, ConstStr::getCNST_STR_643(), ctx)), (new(ctx) SimpleTimeZone(-5 * ONE_HOUR, ConstStr::getCNST_STR_644(), ctx)), (new(ctx) SimpleTimeZone(-5 * ONE_HOUR, ConstStr::getCNST_STR_645(), ctx)), (new(ctx) SimpleTimeZone(-5 * ONE_HOUR, ConstStr::getCNST_STR_646(), Calendar::APRIL, 1, -Calendar::SUNDAY, 0 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 0 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(-5 * ONE_HOUR, ConstStr::getCNST_STR_647(), ctx)), (new(ctx) SimpleTimeZone(-5 * ONE_HOUR, ConstStr::getCNST_STR_648(), Calendar::APRIL, 1, -Calendar::SUNDAY, 0 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 0 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(-5 * ONE_HOUR, ConstStr::getCNST_STR_649(), ctx)), (new(ctx) SimpleTimeZone(-5 * ONE_HOUR, ConstStr::getCNST_STR_650(), ctx)), (new(ctx) SimpleTimeZone(-5 * ONE_HOUR, ConstStr::getCNST_STR_651(), ctx)), (new(ctx) SimpleTimeZone(-5 * ONE_HOUR, ConstStr::getCNST_STR_652(), Calendar::APRIL, 1, -Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(-5 * ONE_HOUR, ConstStr::getCNST_STR_653(), Calendar::APRIL, 1, -Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(-5 * ONE_HOUR, ConstStr::getCNST_STR_654(), Calendar::APRIL, 1, -Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(-5 * ONE_HOUR, ConstStr::getCNST_STR_655(), ctx)), (new(ctx) SimpleTimeZone(-5 * ONE_HOUR, ConstStr::getCNST_STR_656(), ctx)), (new(ctx) SimpleTimeZone(-5 * ONE_HOUR, ConstStr::getCNST_STR_657(), ctx)), (new(ctx) SimpleTimeZone(-5 * ONE_HOUR, ConstStr::getCNST_STR_658(), ctx)), (new(ctx) SimpleTimeZone(-4 * ONE_HOUR, ConstStr::getCNST_STR_659(), ctx)), (new(ctx) SimpleTimeZone(-4 * ONE_HOUR, ConstStr::getCNST_STR_660(), ctx)), (new(ctx) SimpleTimeZone(-4 * ONE_HOUR, ConstStr::getCNST_STR_661(), ctx)), (new(ctx) SimpleTimeZone(-4 * ONE_HOUR, ConstStr::getCNST_STR_662(), Calendar::OCTOBER, 1, -Calendar::SUNDAY, 0 * ONE_HOUR, Calendar::MARCH, 1, -Calendar::SUNDAY, 0 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(-4 * ONE_HOUR, ConstStr::getCNST_STR_663(), ctx)), (new(ctx) SimpleTimeZone(-4 * ONE_HOUR, ConstStr::getCNST_STR_664(), ctx)), (new(ctx) SimpleTimeZone(-4 * ONE_HOUR, ConstStr::getCNST_STR_665(), Calendar::OCTOBER, 8, -Calendar::SUNDAY, 0 * ONE_HOUR, Calendar::FEBRUARY, 15, -Calendar::SUNDAY, 0 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(-4 * ONE_HOUR, ConstStr::getCNST_STR_666(), ctx)), (new(ctx) SimpleTimeZone(-4 * ONE_HOUR, ConstStr::getCNST_STR_667(), ctx)), (new(ctx) SimpleTimeZone(-4 * ONE_HOUR, ConstStr::getCNST_STR_668(), ctx)), (new(ctx) SimpleTimeZone(-4 * ONE_HOUR, ConstStr::getCNST_STR_669(), ctx)), (new(ctx) SimpleTimeZone(-4 * ONE_HOUR, ConstStr::getCNST_STR_670(), ctx)), (new(ctx) SimpleTimeZone(-4 * ONE_HOUR, ConstStr::getCNST_STR_671(), ctx)), (new(ctx) SimpleTimeZone(-4 * ONE_HOUR, ConstStr::getCNST_STR_672(), ctx)), (new(ctx) SimpleTimeZone(-4 * ONE_HOUR, ConstStr::getCNST_STR_673(), ctx)), (new(ctx) SimpleTimeZone(-4 * ONE_HOUR, ConstStr::getCNST_STR_674(), ctx)), (new(ctx) SimpleTimeZone(-4 * ONE_HOUR, ConstStr::getCNST_STR_675(), ctx)), (new(ctx) SimpleTimeZone(-4 * ONE_HOUR, ConstStr::getCNST_STR_676(), ctx)), (new(ctx) SimpleTimeZone(-4 * ONE_HOUR, ConstStr::getCNST_STR_677(), Calendar::OCTOBER, 9, -Calendar::SUNDAY, 4 * ONE_HOUR, Calendar::MARCH, 9, -Calendar::SUNDAY, 3 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(-4 * ONE_HOUR, ConstStr::getCNST_STR_678(), ctx)), (new(ctx) SimpleTimeZone(-4 * ONE_HOUR, ConstStr::getCNST_STR_679(), ctx)), (new(ctx) SimpleTimeZone(-4 * ONE_HOUR, ConstStr::getCNST_STR_680(), ctx)), (new(ctx) SimpleTimeZone(-4 * ONE_HOUR, ConstStr::getCNST_STR_681(), ctx)), (new(ctx) SimpleTimeZone(-4 * ONE_HOUR, ConstStr::getCNST_STR_682(), ctx)), (new(ctx) SimpleTimeZone(-4 * ONE_HOUR, ConstStr::getCNST_STR_683(), Calendar::APRIL, 1, -Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(-4 * ONE_HOUR, ConstStr::getCNST_STR_684(), ctx)), (new(ctx) SimpleTimeZone(-4 * ONE_HOUR, ConstStr::getCNST_STR_685(), Calendar::OCTOBER, 9, -Calendar::SUNDAY, 0 * ONE_HOUR, Calendar::MARCH, 9, -Calendar::SUNDAY, 0 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(-4 * ONE_HOUR, ConstStr::getCNST_STR_686(), Calendar::APRIL, 1, -Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(-4 * ONE_HOUR, ConstStr::getCNST_STR_687(), Calendar::SEPTEMBER, 1, -Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::APRIL, 15, -Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(-3 * ONE_HOUR - 1800000, ConstStr::getCNST_STR_688(), Calendar::APRIL, 1, -Calendar::SUNDAY, 60000, Calendar::OCTOBER, -1, Calendar::SUNDAY, 60000, ctx)), (new(ctx) SimpleTimeZone(-3 * ONE_HOUR, ConstStr::getCNST_STR_689(), ctx)), (new(ctx) SimpleTimeZone(-3 * ONE_HOUR, ConstStr::getCNST_STR_690(), ctx)), (new(ctx) SimpleTimeZone(-3 * ONE_HOUR, ConstStr::getCNST_STR_691(), ctx)), (new(ctx) SimpleTimeZone(-3 * ONE_HOUR, ConstStr::getCNST_STR_692(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(-3 * ONE_HOUR, ConstStr::getCNST_STR_693(), Calendar::APRIL, 1, -Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(-3 * ONE_HOUR, ConstStr::getCNST_STR_694(), ctx)), (new(ctx) SimpleTimeZone(-3 * ONE_HOUR, ConstStr::getCNST_STR_695(), ctx)), (new(ctx) SimpleTimeZone(-3 * ONE_HOUR, ConstStr::getCNST_STR_696(), Calendar::OCTOBER, 8, -Calendar::SUNDAY, 0 * ONE_HOUR, Calendar::FEBRUARY, 15, -Calendar::SUNDAY, 0 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(-2 * ONE_HOUR, ConstStr::getCNST_STR_697(), ctx)), (new(ctx) SimpleTimeZone(-1 * ONE_HOUR, ConstStr::getCNST_STR_698(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(-1 * ONE_HOUR, ConstStr::getCNST_STR_699(), ctx)), (new(ctx) SimpleTimeZone(0 * ONE_HOUR, ConstStr::getCNST_STR_700(), ctx)), (new(ctx) SimpleTimeZone(0 * ONE_HOUR, ConstStr::getCNST_STR_701(), ctx)), (new(ctx) SimpleTimeZone(0 * ONE_HOUR, ConstStr::getCNST_STR_702(), ctx)), (new(ctx) SimpleTimeZone(0 * ONE_HOUR, ConstStr::getCNST_STR_703(), ctx)), (new(ctx) SimpleTimeZone(0 * ONE_HOUR, ConstStr::getCNST_STR_704(), ctx)), (new(ctx) SimpleTimeZone(0 * ONE_HOUR, ConstStr::getCNST_STR_705(), ctx)), (new(ctx) SimpleTimeZone(0 * ONE_HOUR, ConstStr::getCNST_STR_706(), ctx)), (new(ctx) SimpleTimeZone(0 * ONE_HOUR, ConstStr::getCNST_STR_707(), ctx)), (new(ctx) SimpleTimeZone(0 * ONE_HOUR, ConstStr::getCNST_STR_708(), ctx)), (new(ctx) SimpleTimeZone(0 * ONE_HOUR, ConstStr::getCNST_STR_709(), ctx)), (new(ctx) SimpleTimeZone(0 * ONE_HOUR, ConstStr::getCNST_STR_710(), ctx)), (new(ctx) SimpleTimeZone(0 * ONE_HOUR, ConstStr::getCNST_STR_711(), ctx)), (new(ctx) SimpleTimeZone(0 * ONE_HOUR, ConstStr::getCNST_STR_712(), ctx)), (new(ctx) SimpleTimeZone(0 * ONE_HOUR, ConstStr::getCNST_STR_713(), ctx)), (new(ctx) SimpleTimeZone(0 * ONE_HOUR, ConstStr::getCNST_STR_714(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(0 * ONE_HOUR, ConstStr::getCNST_STR_715(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(0 * ONE_HOUR, ConstStr::getCNST_STR_716(), ctx)), (new(ctx) SimpleTimeZone(0 * ONE_HOUR, ConstStr::getCNST_STR_717(), ctx)), (new(ctx) SimpleTimeZone(0 * ONE_HOUR, ConstStr::getCNST_STR_718(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(0 * ONE_HOUR, ConstStr::getCNST_STR_719(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(1 * ONE_HOUR, ConstStr::getCNST_STR_720(), ctx)), (new(ctx) SimpleTimeZone(1 * ONE_HOUR, ConstStr::getCNST_STR_721(), ctx)), (new(ctx) SimpleTimeZone(1 * ONE_HOUR, ConstStr::getCNST_STR_722(), ctx)), (new(ctx) SimpleTimeZone(1 * ONE_HOUR, ConstStr::getCNST_STR_723(), ctx)), (new(ctx) SimpleTimeZone(1 * ONE_HOUR, ConstStr::getCNST_STR_724(), ctx)), (new(ctx) SimpleTimeZone(1 * ONE_HOUR, ConstStr::getCNST_STR_725(), ctx)), (new(ctx) SimpleTimeZone(1 * ONE_HOUR, ConstStr::getCNST_STR_726(), ctx)), (new(ctx) SimpleTimeZone(1 * ONE_HOUR, ConstStr::getCNST_STR_727(), ctx)), (new(ctx) SimpleTimeZone(1 * ONE_HOUR, ConstStr::getCNST_STR_728(), ctx)), (new(ctx) SimpleTimeZone(1 * ONE_HOUR, ConstStr::getCNST_STR_729(), ctx)), (new(ctx) SimpleTimeZone(1 * ONE_HOUR, ConstStr::getCNST_STR_730(), ctx)), (new(ctx) SimpleTimeZone(1 * ONE_HOUR, ConstStr::getCNST_STR_731(), Calendar::SEPTEMBER, 1, -Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::APRIL, 1, -Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(1 * ONE_HOUR, ConstStr::getCNST_STR_732(), ctx)), (new(ctx) SimpleTimeZone(1 * ONE_HOUR, ConstStr::getCNST_STR_733(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(1 * ONE_HOUR, ConstStr::getCNST_STR_734(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(1 * ONE_HOUR, ConstStr::getCNST_STR_735(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(1 * ONE_HOUR, ConstStr::getCNST_STR_736(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(1 * ONE_HOUR, ConstStr::getCNST_STR_737(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(1 * ONE_HOUR, ConstStr::getCNST_STR_738(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(1 * ONE_HOUR, ConstStr::getCNST_STR_739(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(1 * ONE_HOUR, ConstStr::getCNST_STR_740(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(1 * ONE_HOUR, ConstStr::getCNST_STR_741(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(1 * ONE_HOUR, ConstStr::getCNST_STR_742(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(1 * ONE_HOUR, ConstStr::getCNST_STR_743(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(1 * ONE_HOUR, ConstStr::getCNST_STR_744(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(1 * ONE_HOUR, ConstStr::getCNST_STR_745(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(1 * ONE_HOUR, ConstStr::getCNST_STR_746(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(1 * ONE_HOUR, ConstStr::getCNST_STR_747(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(1 * ONE_HOUR, ConstStr::getCNST_STR_748(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(1 * ONE_HOUR, ConstStr::getCNST_STR_749(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(1 * ONE_HOUR, ConstStr::getCNST_STR_750(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(1 * ONE_HOUR, ConstStr::getCNST_STR_751(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(1 * ONE_HOUR, ConstStr::getCNST_STR_752(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(1 * ONE_HOUR, ConstStr::getCNST_STR_753(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(1 * ONE_HOUR, ConstStr::getCNST_STR_754(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(2 * ONE_HOUR, ConstStr::getCNST_STR_755(), ctx)), (new(ctx) SimpleTimeZone(2 * ONE_HOUR, ConstStr::getCNST_STR_756(), ctx)), (new(ctx) SimpleTimeZone(2 * ONE_HOUR, ConstStr::getCNST_STR_757(), ctx)), (new(ctx) SimpleTimeZone(2 * ONE_HOUR, ConstStr::getCNST_STR_758(), ctx)), (new(ctx) SimpleTimeZone(2 * ONE_HOUR, ConstStr::getCNST_STR_759(), ctx)), (new(ctx) SimpleTimeZone(2 * ONE_HOUR, ConstStr::getCNST_STR_760(), ctx)), (new(ctx) SimpleTimeZone(2 * ONE_HOUR, ConstStr::getCNST_STR_761(), ctx)), (new(ctx) SimpleTimeZone(2 * ONE_HOUR, ConstStr::getCNST_STR_762(), ctx)), (new(ctx) SimpleTimeZone(2 * ONE_HOUR, ConstStr::getCNST_STR_763(), ctx)), (new(ctx) SimpleTimeZone(2 * ONE_HOUR, ConstStr::getCNST_STR_764(), ctx)), (new(ctx) SimpleTimeZone(2 * ONE_HOUR, ConstStr::getCNST_STR_765(), ctx)), (new(ctx) SimpleTimeZone(2 * ONE_HOUR, ConstStr::getCNST_STR_766(), Calendar::MARCH, -1, Calendar::THURSDAY, 0 * ONE_HOUR, Calendar::SEPTEMBER, -1, Calendar::THURSDAY, 0 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(2 * ONE_HOUR, ConstStr::getCNST_STR_767(), Calendar::MARCH, -1, Calendar::SUNDAY, 0 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 0 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(2 * ONE_HOUR, ConstStr::getCNST_STR_768(), Calendar::APRIL, 1, 0, 0 * ONE_HOUR, Calendar::OCTOBER, 1, 0, 0 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(2 * ONE_HOUR, ConstStr::getCNST_STR_769(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(2 * ONE_HOUR, ConstStr::getCNST_STR_770(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(2 * ONE_HOUR, ConstStr::getCNST_STR_771(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(2 * ONE_HOUR, ConstStr::getCNST_STR_772(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(2 * ONE_HOUR, ConstStr::getCNST_STR_773(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(2 * ONE_HOUR, ConstStr::getCNST_STR_774(), Calendar::MARCH, -1, Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(2 * ONE_HOUR, ConstStr::getCNST_STR_775(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(2 * ONE_HOUR, ConstStr::getCNST_STR_776(), Calendar::MARCH, -1, Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(2 * ONE_HOUR, ConstStr::getCNST_STR_777(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(2 * ONE_HOUR, ConstStr::getCNST_STR_778(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(2 * ONE_HOUR, ConstStr::getCNST_STR_779(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(2 * ONE_HOUR, ConstStr::getCNST_STR_780(), ctx)), (new(ctx) SimpleTimeZone(2 * ONE_HOUR, ConstStr::getCNST_STR_781(), ctx)), (new(ctx) SimpleTimeZone(3 * ONE_HOUR, ConstStr::getCNST_STR_782(), ctx)), (new(ctx) SimpleTimeZone(3 * ONE_HOUR, ConstStr::getCNST_STR_783(), ctx)), (new(ctx) SimpleTimeZone(3 * ONE_HOUR, ConstStr::getCNST_STR_784(), ctx)), (new(ctx) SimpleTimeZone(3 * ONE_HOUR, ConstStr::getCNST_STR_785(), ctx)), (new(ctx) SimpleTimeZone(3 * ONE_HOUR, ConstStr::getCNST_STR_786(), ctx)), (new(ctx) SimpleTimeZone(3 * ONE_HOUR, ConstStr::getCNST_STR_787(), ctx)), (new(ctx) SimpleTimeZone(3 * ONE_HOUR, ConstStr::getCNST_STR_788(), ctx)), (new(ctx) SimpleTimeZone(3 * ONE_HOUR, ConstStr::getCNST_STR_789(), ctx)), (new(ctx) SimpleTimeZone(3 * ONE_HOUR, ConstStr::getCNST_STR_790(), ctx)), (new(ctx) SimpleTimeZone(3 * ONE_HOUR, ConstStr::getCNST_STR_791(), Calendar::APRIL, 1, 0, 3 * ONE_HOUR, Calendar::OCTOBER, 1, 0, 3 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(3 * ONE_HOUR, ConstStr::getCNST_STR_792(), ctx)), (new(ctx) SimpleTimeZone(3 * ONE_HOUR, ConstStr::getCNST_STR_793(), ctx)), (new(ctx) SimpleTimeZone(3 * ONE_HOUR, ConstStr::getCNST_STR_794(), ctx)), (new(ctx) SimpleTimeZone(3 * ONE_HOUR, ConstStr::getCNST_STR_795(), ctx)), (new(ctx) SimpleTimeZone(3 * ONE_HOUR, ConstStr::getCNST_STR_796(), ctx)), (new(ctx) SimpleTimeZone(3 * ONE_HOUR, ConstStr::getCNST_STR_797(), ctx)), (new(ctx) SimpleTimeZone(3 * ONE_HOUR, ConstStr::getCNST_STR_798(), ctx)), (new(ctx) SimpleTimeZone(4 * ONE_HOUR, ConstStr::getCNST_STR_799(), Calendar::MARCH, -1, Calendar::SUNDAY, 0 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 0 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(4 * ONE_HOUR, ConstStr::getCNST_STR_800(), Calendar::MARCH, -1, Calendar::SUNDAY, 1 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 1 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(4 * ONE_HOUR, ConstStr::getCNST_STR_801(), ctx)), (new(ctx) SimpleTimeZone(4 * ONE_HOUR, ConstStr::getCNST_STR_802(), Calendar::MARCH, -1, Calendar::SUNDAY, 0 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 0 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(4 * ONE_HOUR, ConstStr::getCNST_STR_803(), Calendar::MARCH, -1, Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(4 * ONE_HOUR, ConstStr::getCNST_STR_804(), Calendar::MARCH, -1, Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(4 * ONE_HOUR, ConstStr::getCNST_STR_805(), ctx)), (new(ctx) SimpleTimeZone(4 * ONE_HOUR, ConstStr::getCNST_STR_806(), ctx)), (new(ctx) SimpleTimeZone(4 * ONE_HOUR, ConstStr::getCNST_STR_807(), ctx)), (new(ctx) SimpleTimeZone(5 * ONE_HOUR, ConstStr::getCNST_STR_808(), Calendar::MARCH, -1, Calendar::SUNDAY, 0 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 0 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(5 * ONE_HOUR, ConstStr::getCNST_STR_809(), ctx)), (new(ctx) SimpleTimeZone(5 * ONE_HOUR, ConstStr::getCNST_STR_810(), ctx)), (new(ctx) SimpleTimeZone(5 * ONE_HOUR, ConstStr::getCNST_STR_811(), Calendar::MARCH, -1, Calendar::SUNDAY, 2 * ONE_HOUR + 1800000, Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR + 1800000, ctx)), (new(ctx) SimpleTimeZone(5 * ONE_HOUR, ConstStr::getCNST_STR_812(), ctx)), (new(ctx) SimpleTimeZone(5 * ONE_HOUR, ConstStr::getCNST_STR_813(), ctx)), (new(ctx) SimpleTimeZone(5 * ONE_HOUR, ConstStr::getCNST_STR_814(), ctx)), (new(ctx) SimpleTimeZone(5 * ONE_HOUR, ConstStr::getCNST_STR_815(), Calendar::MARCH, -1, Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(5 * ONE_HOUR, ConstStr::getCNST_STR_816(), ctx)), (new(ctx) SimpleTimeZone(5 * ONE_HOUR, ConstStr::getCNST_STR_817(), ctx)), (new(ctx) SimpleTimeZone(5 * ONE_HOUR + 1800000, ConstStr::getCNST_STR_818(), ctx)), (new(ctx) SimpleTimeZone(6 * ONE_HOUR, ConstStr::getCNST_STR_819(), ctx)), (new(ctx) SimpleTimeZone(6 * ONE_HOUR, ConstStr::getCNST_STR_820(), Calendar::MARCH, -1, Calendar::SUNDAY, 0 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 0 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(5 * ONE_HOUR + HALF_HOUR, ConstStr::getCNST_STR_821(), ctx)), (new(ctx) SimpleTimeZone(6 * ONE_HOUR, ConstStr::getCNST_STR_822(), ctx)), (new(ctx) SimpleTimeZone(6 * ONE_HOUR, ConstStr::getCNST_STR_823(), ctx)), (new(ctx) SimpleTimeZone(6 * ONE_HOUR, ConstStr::getCNST_STR_824(), Calendar::MARCH, -1, Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(6 * ONE_HOUR, ConstStr::getCNST_STR_825(), ctx)), (new(ctx) SimpleTimeZone(6 * ONE_HOUR, ConstStr::getCNST_STR_826(), ctx)), (new(ctx) SimpleTimeZone(6 * ONE_HOUR, ConstStr::getCNST_STR_827(), ctx)), (new(ctx) SimpleTimeZone(6 * ONE_HOUR + 1800000, ConstStr::getCNST_STR_828(), ctx)), (new(ctx) SimpleTimeZone(7 * ONE_HOUR, ConstStr::getCNST_STR_829(), ctx)), (new(ctx) SimpleTimeZone(7 * ONE_HOUR, ConstStr::getCNST_STR_830(), ctx)), (new(ctx) SimpleTimeZone(7 * ONE_HOUR, ConstStr::getCNST_STR_831(), Calendar::MARCH, -1, Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(7 * ONE_HOUR, ConstStr::getCNST_STR_832(), ctx)), (new(ctx) SimpleTimeZone(7 * ONE_HOUR, ConstStr::getCNST_STR_833(), ctx)), (new(ctx) SimpleTimeZone(7 * ONE_HOUR, ConstStr::getCNST_STR_834(), ctx)), (new(ctx) SimpleTimeZone(7 * ONE_HOUR, ConstStr::getCNST_STR_835(), ctx)), (new(ctx) SimpleTimeZone(8 * ONE_HOUR, ConstStr::getCNST_STR_836(), ctx)), (new(ctx) SimpleTimeZone(8 * ONE_HOUR, ConstStr::getCNST_STR_837(), ctx)), (new(ctx) SimpleTimeZone(8 * ONE_HOUR, ConstStr::getCNST_STR_838(), ctx)), (new(ctx) SimpleTimeZone(8 * ONE_HOUR, ConstStr::getCNST_STR_839(), Calendar::MARCH, -1, Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(8 * ONE_HOUR, ConstStr::getCNST_STR_840(), ctx)), (new(ctx) SimpleTimeZone(8 * ONE_HOUR, ConstStr::getCNST_STR_841(), ctx)), (new(ctx) SimpleTimeZone(8 * ONE_HOUR, ConstStr::getCNST_STR_842(), ctx)), (new(ctx) SimpleTimeZone(8 * ONE_HOUR, ConstStr::getCNST_STR_843(), ctx)), (new(ctx) SimpleTimeZone(8 * ONE_HOUR, ConstStr::getCNST_STR_844(), ctx)), (new(ctx) SimpleTimeZone(8 * ONE_HOUR, ConstStr::getCNST_STR_845(), ctx)), (new(ctx) SimpleTimeZone(8 * ONE_HOUR, ConstStr::getCNST_STR_846(), ctx)), (new(ctx) SimpleTimeZone(8 * ONE_HOUR, ConstStr::getCNST_STR_847(), ctx)), (new(ctx) SimpleTimeZone(8 * ONE_HOUR, ConstStr::getCNST_STR_848(), ctx)), (new(ctx) SimpleTimeZone(8 * ONE_HOUR, ConstStr::getCNST_STR_849(), ctx)), (new(ctx) SimpleTimeZone(9 * ONE_HOUR, ConstStr::getCNST_STR_850(), ctx)), (new(ctx) SimpleTimeZone(9 * ONE_HOUR, ConstStr::getCNST_STR_851(), ctx)), (new(ctx) SimpleTimeZone(9 * ONE_HOUR, ConstStr::getCNST_STR_852(), ctx)), (new(ctx) SimpleTimeZone(9 * ONE_HOUR, ConstStr::getCNST_STR_853(), ctx)), (new(ctx) SimpleTimeZone(9 * ONE_HOUR, ConstStr::getCNST_STR_854(), Calendar::MARCH, -1, Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(9 * ONE_HOUR, ConstStr::getCNST_STR_855(), ctx)), (new(ctx) SimpleTimeZone(9 * ONE_HOUR + 1800000, ConstStr::getCNST_STR_856(), Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::MARCH, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(9 * ONE_HOUR + 1800000, ConstStr::getCNST_STR_857(), ctx)), (new(ctx) SimpleTimeZone(10 * ONE_HOUR, ConstStr::getCNST_STR_858(), ctx)), (new(ctx) SimpleTimeZone(10 * ONE_HOUR, ConstStr::getCNST_STR_859(), Calendar::MARCH, -1, Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(10 * ONE_HOUR, ConstStr::getCNST_STR_860(), Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::MARCH, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(10 * ONE_HOUR, ConstStr::getCNST_STR_861(), ctx)), (new(ctx) SimpleTimeZone(10 * ONE_HOUR, ConstStr::getCNST_STR_862(), ctx)), (new(ctx) SimpleTimeZone(10 * ONE_HOUR, ConstStr::getCNST_STR_863(), ctx)), (new(ctx) SimpleTimeZone(10 * ONE_HOUR, ConstStr::getCNST_STR_864(), ctx)), (new(ctx) SimpleTimeZone(10 * ONE_HOUR + 1800000, ConstStr::getCNST_STR_865(), Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::MARCH, -1, Calendar::SUNDAY, 2 * ONE_HOUR, 1800000, ctx)), (new(ctx) SimpleTimeZone(11 * ONE_HOUR, ConstStr::getCNST_STR_866(), Calendar::MARCH, -1, Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(11 * ONE_HOUR, ConstStr::getCNST_STR_867(), ctx)), (new(ctx) SimpleTimeZone(11 * ONE_HOUR, ConstStr::getCNST_STR_868(), ctx)), (new(ctx) SimpleTimeZone(11 * ONE_HOUR, ConstStr::getCNST_STR_869(), ctx)), (new(ctx) SimpleTimeZone(11 * ONE_HOUR, ConstStr::getCNST_STR_870(), ctx)), (new(ctx) SimpleTimeZone(11 * ONE_HOUR, ConstStr::getCNST_STR_871(), ctx)), (new(ctx) SimpleTimeZone(11 * ONE_HOUR + 1800000, ConstStr::getCNST_STR_872(), ctx)), (new(ctx) SimpleTimeZone(12 * ONE_HOUR, ConstStr::getCNST_STR_873(), Calendar::OCTOBER, 1, -Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::MARCH, 15, -Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(12 * ONE_HOUR, ConstStr::getCNST_STR_874(), Calendar::MARCH, -1, Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(12 * ONE_HOUR, ConstStr::getCNST_STR_875(), Calendar::MARCH, -1, Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::OCTOBER, -1, Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(12 * ONE_HOUR, ConstStr::getCNST_STR_876(), Calendar::OCTOBER, 1, -Calendar::SUNDAY, 2 * ONE_HOUR, Calendar::MARCH, 15, -Calendar::SUNDAY, 2 * ONE_HOUR, ctx)), (new(ctx) SimpleTimeZone(12 * ONE_HOUR, ConstStr::getCNST_STR_877(), ctx)), (new(ctx) SimpleTimeZone(12 * ONE_HOUR, ConstStr::getCNST_STR_878(), ctx)), (new(ctx) SimpleTimeZone(12 * ONE_HOUR, ConstStr::getCNST_STR_879(), ctx)), (new(ctx) SimpleTimeZone(12 * ONE_HOUR, ConstStr::getCNST_STR_880(), ctx)), (new(ctx) SimpleTimeZone(12 * ONE_HOUR, ConstStr::getCNST_STR_881(), ctx)), (new(ctx) SimpleTimeZone(12 * ONE_HOUR, ConstStr::getCNST_STR_882(), ctx)), (new(ctx) SimpleTimeZone(12 * ONE_HOUR, ConstStr::getCNST_STR_883(), ctx)), (new(ctx) SimpleTimeZone(13 * ONE_HOUR, ConstStr::getCNST_STR_884(), ctx)), (new(ctx) SimpleTimeZone(13 * ONE_HOUR, ConstStr::getCNST_STR_885(), ctx)), (new(ctx) SimpleTimeZone(14 * ONE_HOUR, ConstStr::getCNST_STR_886(), ctx))}, ctx));
}
}}


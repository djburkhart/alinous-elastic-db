#ifndef COM_GOOGLE_RE2J_UNICODETABLES_H_
#define COM_GOOGLE_RE2J_UNICODETABLES_H_
namespace alinous{namespace annotation{
class HeaderOnly;
}}
namespace alinous {namespace util {
template <typename  T, typename V> class StaticMap;}}

namespace java {namespace lang {
class IObject;
}}

namespace alinous {
class ThreadContext;
}

namespace com {namespace google {namespace re2j {

using namespace ::alinous;
using namespace ::java::lang;
using ::java::util::Iterator;
using ::alinous::util::StaticMap;



class UnicodeTables final : public virtual IObject {
public:
	UnicodeTables(const UnicodeTables& base) = default;
public:
	UnicodeTables(ThreadContext* ctx) throw()  : IObject(ctx)
	{
	}
	void __construct_impl(ThreadContext* ctx) throw() 
	{
	}
	virtual ~UnicodeTables() throw();
	virtual void __releaseRegerences(bool prepare, ThreadContext* ctx) throw();
public:
	constexpr static const int UpperCase{0};
	constexpr static const int LowerCase{1};
	constexpr static const int TitleCase{2};
	constexpr static const int UpperLower{0x110000};
	static IArrayObject<IArrayObjectPrimitive<int>>* Cc;
	static IArrayObject<IArrayObjectPrimitive<int>>* Cf;
	static IArrayObject<IArrayObjectPrimitive<int>>* Co;
	static IArrayObject<IArrayObjectPrimitive<int>>* Cs;
	static IArrayObject<IArrayObjectPrimitive<int>>* Digit;
	static IArrayObject<IArrayObjectPrimitive<int>>* Nd;
	static IArrayObject<IArrayObjectPrimitive<int>>* Letter;
	static IArrayObject<IArrayObjectPrimitive<int>>* L;
	static IArrayObject<IArrayObjectPrimitive<int>>* Lm;
	static IArrayObject<IArrayObjectPrimitive<int>>* Lo;
	static IArrayObject<IArrayObjectPrimitive<int>>* Lower;
	static IArrayObject<IArrayObjectPrimitive<int>>* Ll;
	static IArrayObject<IArrayObjectPrimitive<int>>* Mark;
	static IArrayObject<IArrayObjectPrimitive<int>>* M;
	static IArrayObject<IArrayObjectPrimitive<int>>* Mc;
	static IArrayObject<IArrayObjectPrimitive<int>>* Me;
	static IArrayObject<IArrayObjectPrimitive<int>>* Mn;
	static IArrayObject<IArrayObjectPrimitive<int>>* Nl;
	static IArrayObject<IArrayObjectPrimitive<int>>* No;
	static IArrayObject<IArrayObjectPrimitive<int>>* Number;
	static IArrayObject<IArrayObjectPrimitive<int>>* N;
	static IArrayObject<IArrayObjectPrimitive<int>>* Other;
	static IArrayObject<IArrayObjectPrimitive<int>>* C;
	static IArrayObject<IArrayObjectPrimitive<int>>* Pc;
	static IArrayObject<IArrayObjectPrimitive<int>>* Pd;
	static IArrayObject<IArrayObjectPrimitive<int>>* Pe;
	static IArrayObject<IArrayObjectPrimitive<int>>* Pf;
	static IArrayObject<IArrayObjectPrimitive<int>>* Pi;
	static IArrayObject<IArrayObjectPrimitive<int>>* Po;
	static IArrayObject<IArrayObjectPrimitive<int>>* Ps;
	static IArrayObject<IArrayObjectPrimitive<int>>* Punct;
	static IArrayObject<IArrayObjectPrimitive<int>>* P;
	static IArrayObject<IArrayObjectPrimitive<int>>* Sc;
	static IArrayObject<IArrayObjectPrimitive<int>>* Sk;
	static IArrayObject<IArrayObjectPrimitive<int>>* Sm;
	static IArrayObject<IArrayObjectPrimitive<int>>* So;
	static IArrayObject<IArrayObjectPrimitive<int>>* Space;
	static IArrayObject<IArrayObjectPrimitive<int>>* Z;
	static IArrayObject<IArrayObjectPrimitive<int>>* Symbol;
	static IArrayObject<IArrayObjectPrimitive<int>>* S;
	static IArrayObject<IArrayObjectPrimitive<int>>* Title;
	static IArrayObject<IArrayObjectPrimitive<int>>* Lt;
	static IArrayObject<IArrayObjectPrimitive<int>>* Upper;
	static IArrayObject<IArrayObjectPrimitive<int>>* Lu;
	static IArrayObject<IArrayObjectPrimitive<int>>* Zl;
	static IArrayObject<IArrayObjectPrimitive<int>>* Zp;
	static IArrayObject<IArrayObjectPrimitive<int>>* Zs;
	static IArrayObject<IArrayObjectPrimitive<int>>* Arabic;
	static IArrayObject<IArrayObjectPrimitive<int>>* Armenian;
	static IArrayObject<IArrayObjectPrimitive<int>>* Avestan;
	static IArrayObject<IArrayObjectPrimitive<int>>* Balinese;
	static IArrayObject<IArrayObjectPrimitive<int>>* Bamum;
	static IArrayObject<IArrayObjectPrimitive<int>>* Batak;
	static IArrayObject<IArrayObjectPrimitive<int>>* Bengali;
	static IArrayObject<IArrayObjectPrimitive<int>>* Bopomofo;
	static IArrayObject<IArrayObjectPrimitive<int>>* Brahmi;
	static IArrayObject<IArrayObjectPrimitive<int>>* Braille;
	static IArrayObject<IArrayObjectPrimitive<int>>* Buginese;
	static IArrayObject<IArrayObjectPrimitive<int>>* Buhid;
	static IArrayObject<IArrayObjectPrimitive<int>>* Canadian_Aboriginal;
	static IArrayObject<IArrayObjectPrimitive<int>>* Carian;
	static IArrayObject<IArrayObjectPrimitive<int>>* Cham;
	static IArrayObject<IArrayObjectPrimitive<int>>* Cherokee;
	static IArrayObject<IArrayObjectPrimitive<int>>* Common;
	static IArrayObject<IArrayObjectPrimitive<int>>* Coptic;
	static IArrayObject<IArrayObjectPrimitive<int>>* Cuneiform;
	static IArrayObject<IArrayObjectPrimitive<int>>* Cypriot;
	static IArrayObject<IArrayObjectPrimitive<int>>* Cyrillic;
	static IArrayObject<IArrayObjectPrimitive<int>>* Deseret;
	static IArrayObject<IArrayObjectPrimitive<int>>* Devanagari;
	static IArrayObject<IArrayObjectPrimitive<int>>* Egyptian_Hieroglyphs;
	static IArrayObject<IArrayObjectPrimitive<int>>* Ethiopic;
	static IArrayObject<IArrayObjectPrimitive<int>>* Georgian;
	static IArrayObject<IArrayObjectPrimitive<int>>* Glagolitic;
	static IArrayObject<IArrayObjectPrimitive<int>>* Gothic;
	static IArrayObject<IArrayObjectPrimitive<int>>* Greek;
	static IArrayObject<IArrayObjectPrimitive<int>>* Gujarati;
	static IArrayObject<IArrayObjectPrimitive<int>>* Gurmukhi;
	static IArrayObject<IArrayObjectPrimitive<int>>* Han;
	static IArrayObject<IArrayObjectPrimitive<int>>* Hangul;
	static IArrayObject<IArrayObjectPrimitive<int>>* Hanunoo;
	static IArrayObject<IArrayObjectPrimitive<int>>* Hebrew;
	static IArrayObject<IArrayObjectPrimitive<int>>* Hiragana;
	static IArrayObject<IArrayObjectPrimitive<int>>* Imperial_Aramaic;
	static IArrayObject<IArrayObjectPrimitive<int>>* Inherited;
	static IArrayObject<IArrayObjectPrimitive<int>>* Inscriptional_Pahlavi;
	static IArrayObject<IArrayObjectPrimitive<int>>* Inscriptional_Parthian;
	static IArrayObject<IArrayObjectPrimitive<int>>* Javanese;
	static IArrayObject<IArrayObjectPrimitive<int>>* Kaithi;
	static IArrayObject<IArrayObjectPrimitive<int>>* Kannada;
	static IArrayObject<IArrayObjectPrimitive<int>>* Katakana;
	static IArrayObject<IArrayObjectPrimitive<int>>* Kayah_Li;
	static IArrayObject<IArrayObjectPrimitive<int>>* Kharoshthi;
	static IArrayObject<IArrayObjectPrimitive<int>>* Khmer;
	static IArrayObject<IArrayObjectPrimitive<int>>* Lao;
	static IArrayObject<IArrayObjectPrimitive<int>>* Latin;
	static IArrayObject<IArrayObjectPrimitive<int>>* Lepcha;
	static IArrayObject<IArrayObjectPrimitive<int>>* Limbu;
	static IArrayObject<IArrayObjectPrimitive<int>>* Linear_B;
	static IArrayObject<IArrayObjectPrimitive<int>>* Lisu;
	static IArrayObject<IArrayObjectPrimitive<int>>* Lycian;
	static IArrayObject<IArrayObjectPrimitive<int>>* Lydian;
	static IArrayObject<IArrayObjectPrimitive<int>>* Malayalam;
	static IArrayObject<IArrayObjectPrimitive<int>>* Mandaic;
	static IArrayObject<IArrayObjectPrimitive<int>>* Meetei_Mayek;
	static IArrayObject<IArrayObjectPrimitive<int>>* Mongolian;
	static IArrayObject<IArrayObjectPrimitive<int>>* Myanmar;
	static IArrayObject<IArrayObjectPrimitive<int>>* New_Tai_Lue;
	static IArrayObject<IArrayObjectPrimitive<int>>* Nko;
	static IArrayObject<IArrayObjectPrimitive<int>>* Ogham;
	static IArrayObject<IArrayObjectPrimitive<int>>* Ol_Chiki;
	static IArrayObject<IArrayObjectPrimitive<int>>* Old_Italic;
	static IArrayObject<IArrayObjectPrimitive<int>>* Old_Persian;
	static IArrayObject<IArrayObjectPrimitive<int>>* Old_South_Arabian;
	static IArrayObject<IArrayObjectPrimitive<int>>* Old_Turkic;
	static IArrayObject<IArrayObjectPrimitive<int>>* Oriya;
	static IArrayObject<IArrayObjectPrimitive<int>>* Osmanya;
	static IArrayObject<IArrayObjectPrimitive<int>>* Phags_Pa;
	static IArrayObject<IArrayObjectPrimitive<int>>* Phoenician;
	static IArrayObject<IArrayObjectPrimitive<int>>* Rejang;
	static IArrayObject<IArrayObjectPrimitive<int>>* Runic;
	static IArrayObject<IArrayObjectPrimitive<int>>* Samaritan;
	static IArrayObject<IArrayObjectPrimitive<int>>* Saurashtra;
	static IArrayObject<IArrayObjectPrimitive<int>>* Shavian;
	static IArrayObject<IArrayObjectPrimitive<int>>* Sinhala;
	static IArrayObject<IArrayObjectPrimitive<int>>* Sundanese;
	static IArrayObject<IArrayObjectPrimitive<int>>* Syloti_Nagri;
	static IArrayObject<IArrayObjectPrimitive<int>>* Syriac;
	static IArrayObject<IArrayObjectPrimitive<int>>* Tagalog;
	static IArrayObject<IArrayObjectPrimitive<int>>* Tagbanwa;
	static IArrayObject<IArrayObjectPrimitive<int>>* Tai_Le;
	static IArrayObject<IArrayObjectPrimitive<int>>* Tai_Tham;
	static IArrayObject<IArrayObjectPrimitive<int>>* Tai_Viet;
	static IArrayObject<IArrayObjectPrimitive<int>>* Tamil;
	static IArrayObject<IArrayObjectPrimitive<int>>* Telugu;
	static IArrayObject<IArrayObjectPrimitive<int>>* Thaana;
	static IArrayObject<IArrayObjectPrimitive<int>>* Thai;
	static IArrayObject<IArrayObjectPrimitive<int>>* Tibetan;
	static IArrayObject<IArrayObjectPrimitive<int>>* Tifinagh;
	static IArrayObject<IArrayObjectPrimitive<int>>* Ugaritic;
	static IArrayObject<IArrayObjectPrimitive<int>>* Vai;
	static IArrayObject<IArrayObjectPrimitive<int>>* Yi;
	static IArrayObject<IArrayObjectPrimitive<int>>* ASCII_Hex_Digit;
	static IArrayObject<IArrayObjectPrimitive<int>>* Bidi_Control;
	static IArrayObject<IArrayObjectPrimitive<int>>* Dash;
	static IArrayObject<IArrayObjectPrimitive<int>>* Deprecated;
	static IArrayObject<IArrayObjectPrimitive<int>>* Diacritic;
	static IArrayObject<IArrayObjectPrimitive<int>>* Extender;
	static IArrayObject<IArrayObjectPrimitive<int>>* Hex_Digit;
	static IArrayObject<IArrayObjectPrimitive<int>>* Hyphen;
	static IArrayObject<IArrayObjectPrimitive<int>>* IDS_Binary_Operator;
	static IArrayObject<IArrayObjectPrimitive<int>>* IDS_Trinary_Operator;
	static IArrayObject<IArrayObjectPrimitive<int>>* Ideographic;
	static IArrayObject<IArrayObjectPrimitive<int>>* Join_Control;
	static IArrayObject<IArrayObjectPrimitive<int>>* Logical_Order_Exception;
	static IArrayObject<IArrayObjectPrimitive<int>>* Noncharacter_Code_Point;
	static IArrayObject<IArrayObjectPrimitive<int>>* Other_Alphabetic;
	static IArrayObject<IArrayObjectPrimitive<int>>* Other_Default_Ignorable_Code_Point;
	static IArrayObject<IArrayObjectPrimitive<int>>* Other_Grapheme_Extend;
	static IArrayObject<IArrayObjectPrimitive<int>>* Other_ID_Continue;
	static IArrayObject<IArrayObjectPrimitive<int>>* Other_ID_Start;
	static IArrayObject<IArrayObjectPrimitive<int>>* Other_Lowercase;
	static IArrayObject<IArrayObjectPrimitive<int>>* Other_Math;
	static IArrayObject<IArrayObjectPrimitive<int>>* Other_Uppercase;
	static IArrayObject<IArrayObjectPrimitive<int>>* Pattern_Syntax;
	static IArrayObject<IArrayObjectPrimitive<int>>* Pattern_White_Space;
	static IArrayObject<IArrayObjectPrimitive<int>>* Quotation_Mark;
	static IArrayObject<IArrayObjectPrimitive<int>>* Radical;
	static IArrayObject<IArrayObjectPrimitive<int>>* STerm;
	static IArrayObject<IArrayObjectPrimitive<int>>* Soft_Dotted;
	static IArrayObject<IArrayObjectPrimitive<int>>* Terminal_Punctuation;
	static IArrayObject<IArrayObjectPrimitive<int>>* Unified_Ideograph;
	static IArrayObject<IArrayObjectPrimitive<int>>* Variation_Selector;
	static IArrayObject<IArrayObjectPrimitive<int>>* White_Space;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> __CASE_RANGES;
	static IArrayObject<IArrayObjectPrimitive<int>>* CASE_RANGES;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> __CASE_ORBIT;
	static IArrayObject<IArrayObjectPrimitive<int>>* CASE_ORBIT;
	static StaticMap<String, IArrayObject<IArrayObjectPrimitive<int>>> __HASH__PROPERTIES;
	static StaticMap<String,IArrayObject<IArrayObjectPrimitive<int>>>* PROPERTIES;
	static StaticMap<String, IArrayObject<IArrayObjectPrimitive<int>>> __HASH__FOLD_CATEGORIES;
	static StaticMap<String,IArrayObject<IArrayObjectPrimitive<int>>>* FOLD_CATEGORIES;
	static StaticMap<String, IArrayObject<IArrayObjectPrimitive<int>>> __HASH__FOLD_SCRIPT;
	static StaticMap<String,IArrayObject<IArrayObjectPrimitive<int>>>* FOLD_SCRIPT;
	static StaticMap<String, IArrayObject<IArrayObjectPrimitive<int>>> __HASH__SCRIPTS;
	static StaticMap<String,IArrayObject<IArrayObjectPrimitive<int>>>* SCRIPTS;
	static StaticMap<String, IArrayObject<IArrayObjectPrimitive<int>>> __HASH__CATEGORIES;
	static StaticMap<String,IArrayObject<IArrayObjectPrimitive<int>>>* CATEGORIES;
private:
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Sm;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Sm;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Sk;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Sk;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Sc;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Sc;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Lu;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Lu;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Lt;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Lt;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Lo;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Lo;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Katakana;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Katakana;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Malayalam;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Malayalam;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Phags_Pa;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Phags_Pa;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Inscriptional_Parthian;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Inscriptional_Parthian;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Latin;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Latin;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Inscriptional_Pahlavi;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Inscriptional_Pahlavi;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Osmanya;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Osmanya;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Khmer;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Khmer;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Inherited;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Inherited;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Telugu;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Telugu;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Samaritan;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Samaritan;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Bopomofo;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Bopomofo;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Imperial_Aramaic;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Imperial_Aramaic;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Kaithi;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Kaithi;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Mandaic;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Mandaic;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Old_South_Arabian;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Old_South_Arabian;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Kayah_Li;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Kayah_Li;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___New_Tai_Lue;
	static IArrayObject<IArrayObjectPrimitive<int>>* _New_Tai_Lue;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Tai_Le;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Tai_Le;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Kharoshthi;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Kharoshthi;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Common;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Common;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Kannada;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Kannada;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Old_Turkic;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Old_Turkic;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Tamil;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Tamil;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Tagalog;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Tagalog;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Brahmi;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Brahmi;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Arabic;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Arabic;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Tagbanwa;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Tagbanwa;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Canadian_Aboriginal;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Canadian_Aboriginal;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Tibetan;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Tibetan;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Coptic;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Coptic;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Hiragana;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Hiragana;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Limbu;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Limbu;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Egyptian_Hieroglyphs;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Egyptian_Hieroglyphs;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Avestan;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Avestan;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Myanmar;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Myanmar;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Armenian;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Armenian;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Sinhala;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Sinhala;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Bengali;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Bengali;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Greek;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Greek;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Cham;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Cham;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Hebrew;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Hebrew;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Meetei_Mayek;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Meetei_Mayek;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Saurashtra;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Saurashtra;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Hangul;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Hangul;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Runic;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Runic;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Deseret;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Deseret;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Lisu;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Lisu;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Sundanese;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Sundanese;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Glagolitic;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Glagolitic;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Oriya;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Oriya;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Buhid;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Buhid;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Ethiopic;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Ethiopic;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Javanese;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Javanese;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Syloti_Nagri;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Syloti_Nagri;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Vai;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Vai;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Cherokee;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Cherokee;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Ogham;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Ogham;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Batak;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Batak;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Syriac;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Syriac;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Gurmukhi;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Gurmukhi;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Tai_Tham;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Tai_Tham;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Ol_Chiki;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Ol_Chiki;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Mongolian;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Mongolian;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Hanunoo;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Hanunoo;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Cypriot;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Cypriot;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Buginese;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Buginese;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Bamum;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Bamum;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Lepcha;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Lepcha;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Thaana;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Thaana;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Old_Persian;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Old_Persian;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Cuneiform;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Cuneiform;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Rejang;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Rejang;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Georgian;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Georgian;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Shavian;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Shavian;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Lycian;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Lycian;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Nko;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Nko;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Yi;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Yi;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Lao;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Lao;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Linear_B;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Linear_B;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Old_Italic;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Old_Italic;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Tai_Viet;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Tai_Viet;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Devanagari;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Devanagari;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Lydian;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Lydian;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Tifinagh;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Tifinagh;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Ugaritic;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Ugaritic;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Thai;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Thai;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Cyrillic;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Cyrillic;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Gujarati;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Gujarati;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Carian;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Carian;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Phoenician;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Phoenician;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Balinese;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Balinese;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Braille;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Braille;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Han;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Han;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Gothic;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Gothic;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Pattern_Syntax;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Pattern_Syntax;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Other_ID_Start;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Other_ID_Start;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Pattern_White_Space;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Pattern_White_Space;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Other_Lowercase;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Other_Lowercase;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Soft_Dotted;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Soft_Dotted;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Hex_Digit;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Hex_Digit;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___ASCII_Hex_Digit;
	static IArrayObject<IArrayObjectPrimitive<int>>* _ASCII_Hex_Digit;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Deprecated;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Deprecated;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Terminal_Punctuation;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Terminal_Punctuation;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Quotation_Mark;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Quotation_Mark;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Other_ID_Continue;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Other_ID_Continue;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Bidi_Control;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Bidi_Control;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Variation_Selector;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Variation_Selector;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Noncharacter_Code_Point;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Noncharacter_Code_Point;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Other_Math;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Other_Math;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Unified_Ideograph;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Unified_Ideograph;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Hyphen;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Hyphen;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___IDS_Binary_Operator;
	static IArrayObject<IArrayObjectPrimitive<int>>* _IDS_Binary_Operator;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Logical_Order_Exception;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Logical_Order_Exception;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Radical;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Radical;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Other_Uppercase;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Other_Uppercase;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___STerm;
	static IArrayObject<IArrayObjectPrimitive<int>>* _STerm;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Other_Alphabetic;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Other_Alphabetic;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Diacritic;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Diacritic;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Extender;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Extender;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Join_Control;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Join_Control;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Ideographic;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Ideographic;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Dash;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Dash;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___IDS_Trinary_Operator;
	static IArrayObject<IArrayObjectPrimitive<int>>* _IDS_Trinary_Operator;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Other_Grapheme_Extend;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Other_Grapheme_Extend;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___Other_Default_Ignorable_Code_Point;
	static IArrayObject<IArrayObjectPrimitive<int>>* _Other_Default_Ignorable_Code_Point;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> ___White_Space;
	static IArrayObject<IArrayObjectPrimitive<int>>* _White_Space;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> __foldLl;
	static IArrayObject<IArrayObjectPrimitive<int>>* foldLl;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> __foldInherited;
	static IArrayObject<IArrayObjectPrimitive<int>>* foldInherited;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> __foldM;
	static IArrayObject<IArrayObjectPrimitive<int>>* foldM;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> __foldL;
	static IArrayObject<IArrayObjectPrimitive<int>>* foldL;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> __foldMn;
	static IArrayObject<IArrayObjectPrimitive<int>>* foldMn;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> __foldCommon;
	static IArrayObject<IArrayObjectPrimitive<int>>* foldCommon;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> __foldGreek;
	static IArrayObject<IArrayObjectPrimitive<int>>* foldGreek;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> __foldLu;
	static IArrayObject<IArrayObjectPrimitive<int>>* foldLu;
	static const StaticArrayObject<StaticArrayObjectPrimitive<int>> __foldLt;
	static IArrayObject<IArrayObjectPrimitive<int>>* foldLt;
public:
	static bool __init_done;
	static bool __init_static_variables();
public:
	static void __cleanUp(ThreadContext* ctx){
	}
};

}}}

#endif /* end of COM_GOOGLE_RE2J_UNICODETABLES_H_ */

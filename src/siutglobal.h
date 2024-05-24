#ifndef SIUT_GLOBAL_H
#define SIUT_GLOBAL_H

#include <qglobal.h>
/*
#if defined Q_CC_GNU && defined Q_OS_WIN32
# define QF_CC_MINGW
# define WINVER 0x0501 /// pro mingw jako, ze to je pro XP a vys
#endif
*/
/// Declaration of macros required for exporting symbols
/// into shared libraries
#if defined(SIUT_BUILD_DLL)
//#warning "EXPORT"
#  define SIUT_DECL_EXPORT Q_DECL_EXPORT
#else
//#warning "IMPORT"
#  define SIUT_DECL_EXPORT Q_DECL_IMPORT
#endif

// #define SI_QUOTE(x) #x
// #define SI_EXPAND_AND_QUOTE(x) SI_QUOTE(x)
#define SI_QUOTE_QSTRINGLITERAL(x) QStringLiteral(#x)

#define SI_VARIANTMAP_FIELD(ptype, getter_prefix, setter_prefix, name_rest) \
	public: bool getter_prefix##name_rest##_isset() const {return contains(SI_QUOTE_QSTRINGLITERAL(getter_prefix##name_rest));} \
	public: ptype getter_prefix##name_rest() const {return qvariant_cast<ptype>(value(SI_QUOTE_QSTRINGLITERAL(getter_prefix##name_rest)));} \
	public: void setter_prefix##name_rest(const ptype &val) {(*this)[SI_QUOTE_QSTRINGLITERAL(getter_prefix##name_rest)] = QVariant::fromValue(val);}


#endif 

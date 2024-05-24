#ifndef SIUT_SICARD_H
#define SIUT_SICARD_H

#include "sipunch.h"

#include <necrolog.h>

#include <QSharedDataPointer>
#include <QVariantMap>
#include <QCoreApplication>

namespace siut {

class SIUT_DECL_EXPORT SICard : public QVariantMap
{
	Q_DECLARE_TR_FUNCTIONS(SICard)
	using Super = QVariantMap;
public:
	using PunchList = QVariantList;
	static constexpr int INVALID_SI_TIME = 0xEEEE;

	SICard();
	SICard(const QVariantMap &o) : Super(o) {}
	SICard(int card_number);

	SI_VARIANTMAP_FIELD(int, s, setS, tationNumber)
	SI_VARIANTMAP_FIELD(int, c, setC, ardNumber)
	SI_VARIANTMAP_FIELD(int, c, setC, heckTime)
	SI_VARIANTMAP_FIELD(int, s, setS, tartTime)
	SI_VARIANTMAP_FIELD(int, f, setF, inishTime)
	SI_VARIANTMAP_FIELD(int, f, setF, inishTimeMs)
	SI_VARIANTMAP_FIELD(QVariantList, p, setP, unches)

	QString toString() const;

	int punchCount() const;
	SIPunch punchAt(int i) const;
	//void addPunch(const SIPunch &p);
	QList<SIPunch> punchList() const;

	static bool isTimeValid(int time);
	static int toAMms(int time_msec);
	static int toAM(int time_sec);
};

}

//Q_DECLARE_METATYPE(siut::SICard)

#endif // SICARD_H

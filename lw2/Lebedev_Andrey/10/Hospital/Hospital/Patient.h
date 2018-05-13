#pragma once
#include "DoctorType.h"

class CPatient
{
public:
	CPatient();

	void takeReferral(DoctorType referral);
	DoctorType getReferral() const;
	size_t getId() const;

private:
	static size_t id;

	const size_t m_id;
	DoctorType m_referral;
};

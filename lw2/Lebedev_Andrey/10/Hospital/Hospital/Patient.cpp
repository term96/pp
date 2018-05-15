#include "stdafx.h"
#include "Patient.h"

size_t CPatient::nextPatientId = 1;

CPatient::CPatient()
	: m_id(nextPatientId++)
{
}

void CPatient::takeReferral(DoctorType referral)
{
	m_referral = referral;
}

DoctorType CPatient::getReferral() const
{
	return m_referral;
}

size_t CPatient::getId() const
{
	return m_id;
}

#include "stdafx.h"
#include "MainDoctor.h"

size_t CMainDoctor::id = 1;

CMainDoctor::CMainDoctor()
	: CDoctor(DoctorType::MAIN)
	, m_randomDevice()
	, m_randomEngine(m_randomDevice())
	, m_distribution()
	, m_id(id++)
{
}

void CMainDoctor::giveReferral(CPatient & patient)
{
	std::printf("Patient #%d has came to %s\n", patient.getId(), getType().c_str());
	WaitForSingleObject(m_mutex, INFINITE);

	const int random = m_distribution(m_randomEngine);
	DoctorType referredDoctor;

	static const size_t DOCTOR_TYPES_NUMBER = 3;
	switch (random % DOCTOR_TYPES_NUMBER)
	{
	case 0:
		referredDoctor = DoctorType::DENTIST;
		break;
	case 1:
		referredDoctor = DoctorType::SURGEON;
		break;
	case 2:
		referredDoctor = DoctorType::THERAPIST;
	}
	
	std::printf("Patient #%d is getting referral from %s\n", patient.getId(), getType().c_str());
	patient.takeReferral(referredDoctor);

	std::printf("Patient #%d has left %s\n", patient.getId(), getType().c_str());
	ReleaseMutex(m_mutex);
}

std::string CMainDoctor::getType() const
{
	return "main doctor #" + std::to_string(m_id);
}

#include "stdafx.h"
#include "Doctor.h"

const size_t CDoctor::HEAL_TIME_MS = 50;

CDoctor::CDoctor(DoctorType type)
	: m_type(type)
{
	m_mutex = CreateMutex(NULL, false, NULL);
}

CDoctor::~CDoctor()
{
	CloseHandle(m_mutex);
}

void CDoctor::healPatient(CPatient & patient) const
{
	std::printf("Patient #%d has came to %s\n", patient.getId(), getType().c_str());
	WaitForSingleObject(m_mutex, INFINITE);

	std::printf("Patient #%d has started healing by %s\n", patient.getId(), getType().c_str());
	Sleep(HEAL_TIME_MS);

	std::printf("Patient #%d has finished healing by %s\n", patient.getId(), getType().c_str());
	ReleaseMutex(m_mutex);
}

std::string CDoctor::getType() const
{
	switch (m_type)
	{
	case DoctorType::DENTIST:
		return std::move("dentist");
	case DoctorType::THERAPIST:
		return std::move("therapist");
	case DoctorType::SURGEON:
		return std::move("surgeon");
	default:
		return std::move("main doctor");
	}
}

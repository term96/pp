#pragma once
#include <random>
#include "DoctorType.h"
#include "Patient.h"

class CDoctor
{
public:
	CDoctor(DoctorType type);
	~CDoctor();
	CDoctor(CDoctor &) = delete;

	void healPatient(CPatient & patient) const;

protected:
	std::string getType() const;

	static const size_t HEAL_TIME_MS;

	DoctorType m_type;
	HANDLE m_mutex;
};

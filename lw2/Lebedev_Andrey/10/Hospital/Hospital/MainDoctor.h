#pragma once
#include "Doctor.h"

class CPatient;

class CMainDoctor :
	public CDoctor
{
public:
	CMainDoctor();

	void giveReferral(CPatient & patient);

private:
	std::string getType() const;
	DoctorType generateReferral();

	static size_t nextMainDoctorId;

	const size_t m_id;
	std::random_device m_randomDevice;
	std::mt19937 m_randomEngine;
	std::uniform_int_distribution<> m_distribution;
};

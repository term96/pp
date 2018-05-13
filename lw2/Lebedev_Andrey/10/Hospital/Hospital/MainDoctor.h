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
	std::random_device m_randomDevice;
	std::mt19937 m_randomEngine;
	std::uniform_int_distribution<> m_distribution;
};

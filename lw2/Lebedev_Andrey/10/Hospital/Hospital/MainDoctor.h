#pragma once
#include "Doctor.h"
class CMainDoctor :
	public CDoctor
{
public:
	CMainDoctor();

	Type giveReferral();

private:
	std::random_device m_randomDevice;
	std::mt19937 m_randomEngine;
	std::uniform_int_distribution<> m_distribution;
};


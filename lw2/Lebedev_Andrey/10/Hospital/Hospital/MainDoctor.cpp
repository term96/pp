#include "stdafx.h"
#include "MainDoctor.h"


CMainDoctor::CMainDoctor()
	: CDoctor(Type::MAIN)
	, m_randomDevice()
	, m_randomEngine(m_randomDevice())
	, m_distribution()
{
}

CDoctor::Type CMainDoctor::giveReferral()
{
	WaitForSingleObject(m_mutex, INFINITE);

	const int random = m_distribution(m_randomEngine);
	Type referredDoctor;
	std::cout << random << '\n';
	switch (random % 3)
	{
	case 0: 
		referredDoctor = Type::DENTIST;
		break;
	case 1:
		referredDoctor = Type::SURGEON;
		break;
	default: 
		referredDoctor = Type::THERAPIST;
	}
	
	ReleaseMutex(m_mutex);
	return referredDoctor;
}

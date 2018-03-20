#include "stdafx.h"
#include "Doctor.h"

CDoctor::CDoctor(Type type)
	: m_type(type)
{
	m_mutex = CreateMutex(NULL, false, NULL);
}

CDoctor::~CDoctor()
{
	CloseHandle(m_mutex);
}

void CDoctor::healPatient() const
{
	WaitForSingleObject(m_mutex, INFINITE);

	const int sleepTimeMs = 50;
	Sleep(sleepTimeMs);

	ReleaseMutex(m_mutex);
}

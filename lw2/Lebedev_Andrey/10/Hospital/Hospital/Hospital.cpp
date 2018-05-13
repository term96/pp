#include "stdafx.h"
#include "Doctor.h"
#include "MainDoctor.h"
#include "Patient.h"

const size_t THREADS_NUMBER = 4;

struct ThreadData {
	ThreadData(CMainDoctor * firstMain, CMainDoctor * secondMain, CDoctor * surgeon, CDoctor * dentist, CDoctor * therapist)
	{
		m_firstMain = firstMain;
		m_secondMain = secondMain;
		m_surgeon = surgeon;
		m_dentist = dentist;
		m_therapist = therapist;
	}
	~ThreadData()
	{
		delete m_firstMain;
		delete m_secondMain;
		delete m_surgeon;
		delete m_dentist;
		delete m_therapist;
	}
	CMainDoctor * m_firstMain;
	CMainDoctor * m_secondMain;
	CDoctor * m_surgeon;
	CDoctor * m_dentist;
	CDoctor * m_therapist;
};

DWORD WINAPI threadProc(LPVOID lpParameter)
{
	ThreadData * data = (ThreadData *) lpParameter;
	CPatient patient;
	if (patient.getId() % 2 == 0)
	{
		data->m_firstMain->giveReferral(patient);
	}
	else
	{
		data->m_secondMain->giveReferral(patient);
	}
	switch (patient.getReferral())
	{
	case DoctorType::SURGEON:
		data->m_surgeon->healPatient(patient);
		break;
	case DoctorType::DENTIST:
		data->m_dentist->healPatient(patient);
		break;
	case DoctorType::THERAPIST:
		data->m_therapist->healPatient(patient);
		break;
	}
	return 0;
}

int main()
{
	HANDLE * threads = new HANDLE[THREADS_NUMBER];
	ThreadData threadData(new CMainDoctor(), new CMainDoctor(), new CDoctor(DoctorType::SURGEON), new CDoctor(DoctorType::DENTIST), new CDoctor(DoctorType::THERAPIST));

	for (size_t i = 0; i < THREADS_NUMBER; i++)
	{
		threads[i] = CreateThread(NULL, 0, threadProc, &threadData, 0, NULL);
	}

	WaitForMultipleObjects(THREADS_NUMBER, threads, true, INFINITE);
	for (size_t i = 0; i < THREADS_NUMBER; i++)
	{
		CloseHandle(threads);
	}

	delete threads;
    return 0;
}

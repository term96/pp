#include "stdafx.h"
#include "Doctor.h"
#include "MainDoctor.h"
#include "Patient.h"

const size_t THREADS_NUMBER = 10;

struct ThreadData {
	ThreadData(CMainDoctor * firstMain, CMainDoctor * secondMain, CDoctor * surgeon, CDoctor * dentist, CDoctor * therapist)
	{
		m_firstMain = firstMain;
		m_secondMain = secondMain;
		m_surgeon = surgeon;
		m_dentist = dentist;
		m_therapist = therapist;
	}
	CMainDoctor * m_firstMain;
	CMainDoctor * m_secondMain;
	CDoctor * m_surgeon;
	CDoctor * m_dentist;
	CDoctor * m_therapist;
};

int main()
{
	HANDLE * threads = new HANDLE[THREADS_NUMBER];
    return 0;
}

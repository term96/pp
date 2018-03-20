#include "stdafx.h"
#include "MainDoctor.h"

struct Doctors
{
	CMainDoctor * mainDoctor;
};

DWORD WINAPI passDoctors(LPVOID * params)
{
	std::cout << "Got: " << ((Doctors *)params)->mainDoctor->giveReferral() << '\n';
	return 0;
}

int main()
{
	Doctors doctors;
	doctors.mainDoctor = new CMainDoctor();

	HANDLE patient = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)passDoctors, (LPVOID) &doctors, 0, NULL);
	WaitForSingleObject(patient, INFINITE);
	CloseHandle(patient);

    return 0;
}

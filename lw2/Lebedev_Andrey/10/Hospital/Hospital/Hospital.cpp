#include "stdafx.h"
#include "Doctor.h"
#include "MainDoctor.h"
#include "Patient.h"

int main()
{
	CPatient patient[10];
	CMainDoctor * main = new CMainDoctor();
	CDoctor * surgeon = new CDoctor(DoctorType::SURGEON);
	CDoctor * dentist = new CDoctor(DoctorType::DENTIST);
	CDoctor * therapist = new CDoctor(DoctorType::THERAPIST);

	for (size_t i = 0; i < 10; i++)
	{
		main->giveReferral(patient[i]);
		switch (patient[i].getReferral())
		{
		case DoctorType::SURGEON:
			surgeon->healPatient(patient[i]);
			break;
		case DoctorType::DENTIST:
			dentist->healPatient(patient[i]);
			break;
		case DoctorType::THERAPIST:
			therapist->healPatient(patient[i]);
			break;
		}
	}

	delete main;
	delete surgeon;
	delete dentist;
	delete therapist;

    return 0;
}

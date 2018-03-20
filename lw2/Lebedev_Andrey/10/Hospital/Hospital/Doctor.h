#pragma once
#include <random>

class CDoctor
{
public:
	enum Type {
		MAIN, SURGEON, DENTIST, THERAPIST
	};

	CDoctor(Type type);
	~CDoctor();

	void healPatient() const;

protected:
	Type m_type;
	HANDLE m_mutex;
};

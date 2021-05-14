/* Citation and Sources...
Module: Patient
Filename: TriagePatient.cpp
Version 1.0
Author: Aryaman Rastogi
-----------------------------------------------------------
Date:           April 02, 2021
-----------------------------------------------------------
I have done all the coding by myself and only took reference from the
code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include "TriagePatient.h"
#include<cstring>
#include "utils.h"
#include<string>
using namespace std;

namespace sdds
{
	int nextTriageTicket = 1;
	TriagePatient::TriagePatient() : Patient(nextTriageTicket)
	{
		m_symptoms = nullptr;
		nextTriageTicket++;
	}
	char TriagePatient::type()const
	{
		return 'T';
	}
	std::ostream& TriagePatient::csvWrite(std::ostream& ostr) const
	{
		Patient::csvWrite(ostr);
		ostr << ',' << m_symptoms;
		return ostr;
	}
	std::istream& TriagePatient::csvRead(std::istream& istr)
	{
		delete[] m_symptoms;
		m_symptoms = nullptr;
		Patient::csvRead(istr);
		char a = 0;
		while (a != ',')
		{
			istr.get(a);
		}
		
		
		
		//char* symptom;
		////istr.getline(symptom, '\n');
		//symptom = getcstr();
		//m_symptoms = new char[strlen(symptom) + 1];
		//strcpy(m_symptoms, symptom);
		//delete[] symptom;
		//std::cout << "here in triage";


		string symptom;
		getline(istr,symptom, '\n');
		m_symptoms = new char[strlen(symptom.c_str()) + 1];
		strcpy(m_symptoms, symptom.c_str());
		

		
		
		
		nextTriageTicket = Patient::number() + 1;
		return istr;
	}
	std::ostream& TriagePatient::write(std::ostream& ostr)const
	{
		if (Patient::fileIO())
		{
			csvWrite(ostr);
		}
		else
		{
			ostr << "TRIAGE" << std::endl;
			nextTriageTicket = Patient::number() + 1;
			Patient::write(ostr);
			ostr << std::endl << "Symptoms: " << m_symptoms << std::endl;
		}		
		return ostr;
	}
	std::istream& TriagePatient::read(std::istream& istr)
	{
		if (Patient::fileIO())
		{
			csvRead(istr);
		}
		else
		{
			delete[] m_symptoms;
			m_symptoms = nullptr;
			Patient::read(istr);
			char* symptom;
			istr.ignore();
			symptom = getcstr("Symptoms: ");
			m_symptoms = new char[strlen(symptom) + 1];
			strcpy(m_symptoms, symptom);
			delete[] symptom;
		}
		return istr;
	}
	TriagePatient::~TriagePatient()
	{
		delete[] m_symptoms;
		m_symptoms = nullptr;
	}
}
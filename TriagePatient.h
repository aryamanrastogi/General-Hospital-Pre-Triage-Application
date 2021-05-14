/* Citation and Sources...
Module: Patient
Filename: TriagePatient.h
Version 1.0
Author: Aryaman Rastogi
-----------------------------------------------------------
Date:           April 02, 2021
-----------------------------------------------------------
I have done all the coding by myself and only took reference from the
code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H
#include "Patient.h"
namespace sdds
{
	class TriagePatient : public Patient
	{
		char* m_symptoms;
	public:
		//Initializes the symptoms character pointer to null and then sets the Triage Ticket number to the current global value and then increases the global value by one
		TriagePatient();
		//Identifies the Patient object as a Triage patient by returning the letter T
		virtual char type()const;
		//Adds the symptoms to the comma-separated values of the patient
		std::ostream& csvWrite(std::ostream& ostr) const;
		//Reads a comma-separated record of a triage Patient and sets the global ticket number to the next number after the Patient's ticket number
		std::istream& csvRead(std::istream& istr);
		//Based on the return value of the fileIO method it will either write the patient in a comma - separated format or a descriptive format for screen or ticket
		std::ostream& write(std::ostream& ostr)const;
		// to read either comma seperated values or perform a fool - proof entry from the console
		std::istream& read(std::istream& istr);
		//Deletes the memory pointed by the symptoms member variable
		~TriagePatient();
	};
}
#endif // !SDDS_TRIAGEPATIENT_H
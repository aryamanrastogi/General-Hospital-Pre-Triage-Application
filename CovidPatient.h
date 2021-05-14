/* Citation and Sources...
Module: Patient
Filename: CovidPatient.h
Version 1.0
Author: Aryaman Rastogi
-----------------------------------------------------------
Date:           April 02, 2021
-----------------------------------------------------------
I have done all the coding by myself and only took reference from the
code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_
#include "Patient.h"
namespace sdds
{
	class CovidPatient : public Patient
	{
	public:
		//Sets the Ticket number to the current global value and then increases the global value by one
		CovidPatient();
		//Identifies the Patient object as a Covid patient by returning the letter C 
		virtual char type()const;
		//Reads a comma-separated record of a Patient and sets the global ticket number to the next number after the Patient's ticket number
		std::istream& csvRead(std::istream& istr);
		//Based on the return value of the fileIO method it will either write the patient in a comma - separated format or a descriptive format for screen or ticket
		std::ostream& write(std::ostream&)const;
		//Based on the return value of the fileIO method it will either read the patient in a comma - separated format from istream or perform a fool - proof entry from the console
		std::istream& read(std::istream&);
	};
}
#endif // !SDDS_COVIDPATIENT_H_




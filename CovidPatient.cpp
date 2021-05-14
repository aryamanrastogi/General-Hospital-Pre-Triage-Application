/* Citation and Sources...
Module: Patient
Filename: CovidPatient.cpp
Version 1.0
Author: Aryaman Rastogi
-----------------------------------------------------------
Date:           April 02, 2021
-----------------------------------------------------------
I have done all the coding by myself and only took reference from the
code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#include"CovidPatient.h"
namespace sdds
{	
	//global variable
	int nextCovidTicket = 1;

	CovidPatient::CovidPatient() : Patient(nextCovidTicket)
	{
		nextCovidTicket++;
	}
	char CovidPatient::type()const
	{
		return 'C';
	}
	std::istream& CovidPatient::csvRead(std::istream& istr)
	{
		Patient::csvRead(istr);
		nextCovidTicket = Patient::number() + 1;
		char a = 0;
		while (a != '\n')
		{
			istr.get(a);
		}
		return istr;
	}
	std::ostream& CovidPatient::write(std::ostream& ostr)const
	{
		if (Patient::fileIO())
		{
			Patient::csvWrite(ostr);
		}
		else
		{
			ostr << "COVID TEST" << std::endl;
			nextCovidTicket = Patient::number() + 1;
			Patient::write(ostr);
			ostr << std::endl;
		}
		return ostr;
	}
	std::istream& CovidPatient::read(std::istream& istr)
	{
		if (Patient::fileIO())
		{
			Patient::csvRead(istr);
		}
		else
		{
			Patient::read(istr);
		}
		return istr;
	}
}
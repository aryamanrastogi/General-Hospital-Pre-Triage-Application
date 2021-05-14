/* Citation and Sources...
Module: Patient
Filename: Patient.h
Version 1.0
Author: Aryaman Rastogi
-----------------------------------------------------------
Date:           March 25, 2021
-----------------------------------------------------------
I have done all the coding by myself and only took reference from the
code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_
#include "IOAble.h"
#include "Ticket.h"
namespace sdds
{
	class Patient : public IOAble
	{
		char* m_name;
		int m_OHIP;
		Ticket m_ticket;
		bool m_flag;
	public:		
		//constructor
		Patient(int number = 0, bool flag=false);
		//copy constructor deleted so the patient can not be copied to another patient
		Patient(const Patient&) = delete;
		//copy assignment operator deleted so the patient can not be assigned to another patient
		Patient& operator = (const Patient&) = delete;
		//destructor
		~Patient();
		//pure virtual function type():  In future derived objects, this function will return a single character that identifies the type of the patient (COVID test patient or Triage patient).
		virtual char type()const = 0;

		bool fileIO() const;
		void fileIO(bool);
		
		//to compare the character with return value of type()
		bool operator == (char)const;
		//to compare the return values of type() from current and incoming object
		bool operator == (const Patient& )const;
		//sets the ticket time of the patient, it calls the Ticket object's resetTime function
		void setArrivalTime();
		//type casting patient object returns the time of the ticket		
		operator Time() const;
		//returns the number of the ticket
		int number()const;
		
		//to write the comma seperated values
		std::ostream& csvWrite(std::ostream& ostr) const;
		//to read the comma seprated values
		std::istream& csvRead(std::istream& istr);
		//to write(mostly to the console) the user inputted values 
		std::ostream& write(std::ostream& ostr)const;
		//to read from console the user inputted values 
		std::istream& read(std::istream& istr);
	};
}
#endif
/* Citation and Sources...
Module: Patient
Filename: Patient.cpp
Version 1.0
Author: Aryaman Rastogi
-----------------------------------------------------------
Date:           March 25, 2021
-----------------------------------------------------------
I have done all the coding by myself and only took reference from the
code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include"Patient.h"
#include "utils.h"
#include<string>
#include<cstring>
namespace sdds
{
	Patient::Patient(int number, bool flag):m_ticket(number)
	{
		m_flag = flag;
		m_name = nullptr;
		m_OHIP = 0;
	}
	Patient::~Patient()
	{
		delete[] m_name;
		m_name = nullptr;
	}
	bool Patient::fileIO()const 
	{
		return m_flag;
	}
	void Patient::fileIO(bool value)
	{
		m_flag = value;
	}
	bool Patient::operator==(char character)const
	{
		if (type() == character)
		{
			return true;
		}
		return false;
	}
	bool Patient::operator == (const Patient& patient)const
	{
		if (type() == patient.type())
		{
			return true;
		}
		return false;
	}
	void Patient::setArrivalTime()
	{
		m_ticket.resetTime();
	}
	Patient::operator Time() const
	{		
		return (Time)m_ticket;
	}
	int Patient::number()const
	{
		return m_ticket.number();
	}	
	std::ostream& Patient::csvWrite(std::ostream& ostr) const
	{
		if (m_name != nullptr)
		{
			ostr << type() << "," << m_name << "," << m_OHIP << ",";
			m_ticket.csvWrite(ostr);
		}
		return ostr;
	}
	std::istream& Patient::csvRead(std::istream& istr)
	{		
		std::string name;
		char delimiter = 0;							

		getline(istr, name, ','); 
		//to check if the values to be inputted exist
		if (strlen(name.c_str()) > 0)
		{
			if (m_name != nullptr)
			{
				delete[] m_name;
				m_name = nullptr;
			}
			m_name = new char[strlen(name.c_str()) + 1];
			strcpy(m_name, name.c_str());
			istr >> m_OHIP;
			istr.get(delimiter);
			m_ticket.csvRead(istr);
		}
		return istr;
	}
	std::ostream& Patient::write(std::ostream& ostr)const
	{
		m_ticket.write(ostr);
		ostr << std::endl;		
		for (int i = 0; i < (int)strlen(m_name) && i<25; i++)
		{
			if (m_name[i] != '\n')
			{
				ostr << m_name[i];
			}
		}
		ostr << ", OHIP: ";
		ostr << m_OHIP;
		return ostr;
	}
	std::istream& Patient::read(std::istream& istr)
	{
		char* name;
		name = getcstr("Name: ");
		if (name != nullptr)
		{
			if (m_name != nullptr)
			{
				delete[] m_name;
				m_name = nullptr;
			}
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
			delete[] name;
			m_OHIP = getInt(100000000, 999999999, "OHIP: ", "Invalid OHIP Number, ");
		}
		return istr;
	}
}

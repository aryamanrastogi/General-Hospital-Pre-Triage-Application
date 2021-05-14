/* Citation and Sources...
Module: IOAble
Filename: IOAble.cpp
Version 1.0
Author: Aryaman Rastogi
-----------------------------------------------------------
Date:           March 19, 2021
-----------------------------------------------------------
I have done all the coding by myself and only took reference from the
code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#include"IOAble.h"
#include<iostream>
namespace sdds
{
	//Empty destructor
	IOAble::~IOAble()
	{
		//empty
	}

	std::ostream& operator<<(std::ostream& ostr, const IOAble& obj)
	{
		obj.write(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, IOAble& obj)
	{
		obj.read(istr);
		return istr;
	}
}
/* Citation and Sources...
Module: IOAble
Filename: IOAble.h
Version 1.0
Author: Aryaman Rastogi
-----------------------------------------------------------
Date:           March 19, 2021
-----------------------------------------------------------
I have done all the coding by myself and only took reference from the
code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#ifndef SDDS_IOAble_H
#define SDDS_IOAble_H
#include<iostream>
namespace sdds
{
	class IOAble
	{
	public:
		//Pure Virtual Functions
		
		//for future comma-separated ostream outputs
		virtual std::ostream& csvWrite(std::ostream&)const = 0;
		//for future comma - separated istream input
		virtual std::istream& csvRead(std::istream&) = 0;
		//for future ostream outputs
		virtual std::ostream& write(std::ostream&)const = 0;
		//for future istream inputs
		virtual std::istream& read(std::istream&) = 0;
		//virtual destructor
		virtual ~IOAble() = 0;
	};
	//insertion operator to insert the information of an IOAble object into ostream using the IOAble::write function
	std::ostream& operator<<(std::ostream& ostr, const IOAble&);
	//extraction operator to extract information from an istream into an IOAble object using the IOAble::read function
	std::istream& operator>>(std::istream& istr, IOAble&);

}
#endif // !SDDS_IOAble_H

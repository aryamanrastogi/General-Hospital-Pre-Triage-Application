/* Citation and Sources...
Module: Time
Filename: Time.h
Version 1.0
Author: Aryaman Rastogi
-----------------------------------------------------------
Date:           March 16, 2021
-----------------------------------------------------------
I have done all the coding by myself and only took reference from the
code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H
#include <iostream>
namespace sdds
{
    class Time
    {
        unsigned int m_min;
    public:
        Time& setToNow();
        Time(unsigned int min = 0);// constructor
        //Writes the time into a stream in HH:MM format
        std::ostream& write(std::ostream& ostr) const;
        //Reads the time from a stream in H:M format      
        std::istream& read(std::istream& istr);
        //calculates time difference between current and incomming object's time and set corrent object's eqaul to the result
        Time& operator-=(const Time& D);
        //calculates time difference between current and incomming object's time
        Time operator-(const Time& D)const;
        //calculates sum of current and incomming object's time and set corrent object's eqaul to the result
        Time& operator+=(const Time& D);
        //calculates sum of current and incomming object's time
        Time operator+(const Time& D)const;

        Time& operator=(unsigned int val);
        Time& operator *= (unsigned int val);
        Time& operator /= (unsigned int val);
        Time operator *(unsigned int val)const;
        Time operator /(unsigned int val)const;

        operator unsigned int()const;
        operator int()const;
    };
    std::ostream& operator<<(std::ostream& ostr, const Time& D);
    std::istream& operator>>(std::istream& istr, Time& D);
}

#endif // !SDDS_TIME_H


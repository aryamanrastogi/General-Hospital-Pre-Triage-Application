/* Citation and Sources...
Module: Time
Filename: Time.cpp
Version 1.0
Author: Aryaman Rastogi
-----------------------------------------------------------
Date:           March 16, 2021
-----------------------------------------------------------
I have done all the coding by myself and only took reference from the
code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds
{

    Time& Time::setToNow()
    {
        m_min = getTime();
        return *this;
    }

    Time::Time(unsigned int min)
    {
        m_min = min;
    }

    std::ostream& Time::write(std::ostream& ostr) const
    {
        ostr.fill('0');
        ostr.width(2);
        ostr << (int)m_min / 60 << ':';
        ostr.fill('0');
        ostr.width(2);
        ostr << m_min % 60;
        return ostr;
    }

    std::istream& Time::read(std::istream& istr)
    {                
        int hours = 0,
            minutes = 0;
        char delimiter = ' ';                        
        istr >> hours;
        istr >> delimiter;
        istr >> minutes;       
        if (hours < 0)
        {
            istr.setstate(ios::failbit);
        }
        else if (delimiter != ':')
        {
            istr.setstate(ios::failbit);
        }
        else if (minutes < 0)
        {
            istr.setstate(ios::failbit);
        }        
        m_min = (hours * 60) + minutes;
        return istr;
    }

    Time& Time::operator-=(const Time& D)
    {
        if (m_min >= D.m_min)
        {
            m_min = m_min - D.m_min;
        }
        else if (m_min < D.m_min)
        {
            int flag = 1;
            int i = 0;
            while (flag)
            {
                i++;
                if ((int)((24 * 60 * i) - (D.m_min)) > 0)
                {
                    flag = 0;
                }
            }
            m_min = (m_min + 24 * 60 * i) - D.m_min; //turning a 24-hour clock backwards
        }
        return *this;
    }

    Time Time::operator-(const Time& D)const
    {
        unsigned min;
        int flag = 1;
        if (m_min >= D.m_min)
        {
            min = (m_min - D.m_min);
        }
        else if (m_min < D.m_min)
        {
            int i = 0;
            while (flag)
            {
                i++;
                if ((int)((D.m_min) - (24 * 60 * i)) < 0)
                {
                    flag = 0;
                }
            }
            min = (m_min + 24 * 60 * i) - D.m_min;//turning a 24-hour clock backwards
        }
        return min;
    }

    Time& Time::operator+=(const Time& D)
    {
        m_min = m_min + D.m_min;
        return *this;
    }

    Time Time::operator+(const Time& D)const
    {
        return (m_min + D.m_min);
    }

    Time& Time::operator=(unsigned int val)
    {
        m_min = val;
        return *this;
    }

    Time& Time::operator *= (unsigned int val)
    {
        m_min = m_min * val;
        return *this;
    }

    Time Time::operator *(unsigned int val)const
    {
        Time obj;
        obj.m_min = m_min * val;
        return obj;
    }

    Time& Time::operator /= (unsigned int val)
    {
        m_min = m_min / val;
        return *this;
    }

    Time Time::operator /(unsigned int val)const
    {
        Time obj;
        obj.m_min = m_min / val;
        return obj;
    }

    Time::operator int()const
    {
        return (int)m_min;
    }

    Time::operator unsigned int()const
    {
        return m_min;
    }

    std::ostream& operator<<(std::ostream& ostr, const Time& D)
    {
        D.write(ostr);
        return ostr;
    }

    std::istream& operator>>(std::istream& istr, Time& D)
    {
        D.read(istr);
        return istr;
    }
}
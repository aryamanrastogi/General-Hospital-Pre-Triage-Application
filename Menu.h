/* Citation and Sources...
Module: Menu
Filename: Menu.h
Version 1.0
Author: Aryaman Rastogi
-----------------------------------------------------------
Date:           March 19, 2021
-----------------------------------------------------------
I have done all the coding by myself and only took reference from the
code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#ifndef SDDS_MENU_H
#define SDDS_MENU_H
namespace sdds
{
    class Menu
    {
        char* m_text; // holds the menu content dynamically
        int m_noOfSel;  // holds the number of options displayed in menu content
        void display()const;
    public:
        Menu();/////////////////////////////////////
        Menu(const char* MenuContent, int NoOfSelections);
        virtual ~Menu();
        int& operator>>(int& Selection);
        // add safe copying logic
        
        //copy constructor
        Menu(const Menu& src);
        //copy assiginment operator
        Menu& operator=(const Menu&) = delete;
    };
}

#endif // !SDDS_MENU_H
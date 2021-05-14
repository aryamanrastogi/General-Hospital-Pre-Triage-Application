/* Citation and Sources...
Module: Menu
Filename: Menu.cpp
Version 1.0
Author: Aryaman Rastogi
-----------------------------------------------------------
Date:           March 19, 2021
-----------------------------------------------------------
I have done all the coding by myself and only took reference from the
code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include"utils.h"
#include<iostream>
#include<cstring>
using namespace std;
namespace sdds
{
	Menu::Menu()
	{
		m_text = nullptr;
		m_noOfSel = 0;
	}

	//Constructor
	Menu::Menu(const char* MenuContent, int NoOfSelections)
	{
		m_text = nullptr;
		m_text = new char[strlen(MenuContent) + 1];
		strcpy(m_text, MenuContent);
		m_noOfSel = NoOfSelections;
	}

	//destructor
	Menu::~Menu()
	{
		delete[] m_text;
		m_text = nullptr;
	}

	//copy constructor
	Menu::Menu(const Menu& src)
	{
		m_noOfSel = src.m_noOfSel;
		m_text = nullptr;
		if (src.m_text != nullptr)
		{
			m_text = new char[strlen(src.m_text) + 1];
			strcpy(m_text, src.m_text);
		}
	}

	//Displays the Menu content
	void Menu::display()const
	{
		cout << m_text << endl;
		cout << "0- Exit" << endl;

	}

	//The member insertion operator 	
	int& Menu::operator>>(int& Selection)
	{
		display();
		Selection = getInt(0, m_noOfSel, "> ", "Invalid option ");
		return Selection;
	}


}

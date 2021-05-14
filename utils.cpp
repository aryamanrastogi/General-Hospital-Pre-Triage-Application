/* Citation and Sources...
Module: utils
Filename: utils.cpp
Version 1.0
Author: Aryaman Rastogi
-----------------------------------------------------------
Date:           March 16, 2021
-----------------------------------------------------------
I have done all the coding by myself and only took reference from the
code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {
   bool debug = false;  // made global in utils.h

   int getTime()
   {
       int mins = -1;
       if (debug)
       {
           Time t(0);
           cout << "Enter current time: ";
           do
           {
               cin.clear();
               cin >> t;   // needs extraction operator overloaded for Time
          

               if (!cin)
               {
                   cout << "Invlid time, try agian (HH:MM): ";
                   cin.clear();
               }
               else
               {
                   mins = int(t);
               }

               cin.ignore(1000, '\n');
               
           } while (mins < 0);
       }
       else
       {
           time_t t = time(NULL);
           tm lt = *localtime(&t);
           mins = lt.tm_hour * 60 + lt.tm_min;
       }
       return mins;
   }

   //This function performs a fool-proof integer entry from the console
   int getInt(const char* prompt  // User entry prompt
   )
   {
       int number; // to store the input if it is an integer
       unsigned intlength = 0; 
       char integer[12]; // to accomodate the number within the integer range (-2,147,483,647 to +2,147,483,647) 

       if (prompt != nullptr)
       {
           cout << prompt;
       }       

       scanf(" %[^\n]s", integer);       
       //to check if the first value satisfies condition to be an integer 
       while (!isdigit(integer[0]) && integer[0] != '+' && integer[0] != '-')
       {
           cout << "Bad integer value, try again: ";           
           scanf(" %[^\n]s", integer);
       }
       //to check if all the values entered are numbers 
       while (intlength == 0)
       {           
           for (unsigned i = 0; i < strlen(integer); i++)
           {
               if (i == 0 && (integer[i] == '+' || integer[i] == '-'))
               {                                
                   intlength++;
               }
               if (isdigit(integer[i]))
               {                                 
                   intlength++;
               }                   
           }           
           if (intlength != strlen(integer))
           {               
               intlength = 0;
               cout << "Enter only an integer, try again: ";               
               scanf(" %[^\n]s", integer);
           }
       }
       
       int i, //iterrator          
           lengthOfnum = strlen(integer),
           x = 0; 
       //to convert the character string to integer
       if (integer[0] == '+' || integer[0] == '-' || integer[0] == '0' || isdigit(integer[0]))
       {
           if (integer[0] == '+' || integer[0] == '-')
           {
               for (i = 1; i < lengthOfnum; i++)
               {
                   number = integer[i] - '0';
                   if (integer[0] == '+' && (x > (2147483647) / 10 || x == (2147483647) / 10) && number > 7)
                   {
                       x = 2147483647;
                       i = lengthOfnum;
                   }
                   else if (integer[0] == '-' && ((x > ((2147483646 / 10) + (2 / 10))) || (x == ((2147483646 / 10 + 2 / 10)) && number >= 8)))
                   {
                       x = -2147483647 - 1;
                       i = lengthOfnum;
                   }
                   else
                   {
                       x = x * 10 + number;
                   }            
               }
           }
           else if (isdigit(integer[0]))
           {
               for (i = 0; i < lengthOfnum; i++)
               {
                   number = integer[i] - '0';
                   if (isdigit(integer[0]) && (x > (2147483647) / 10 || x == (2147483647)) / 10 && number > 7)
                   {
                       x = 2147483647;
                       i = lengthOfnum;
                   }
                   else
                   {
                       x = x * 10 + number;
                   }                 
               }
           }
           number = x;
       }
       else
       {
           number = 0;
       }
       if (integer[0] == '-')
       {
           //to avoid overflow
           if (x != -2147483647 - 1)
           {
               number = number * -1;
           }
       }       
       return number;
   }

   //This function performs a fool - proof integer entry from the console within a range
   int getInt(
       int min,   // minimum acceptable value
       int max,   // maximum acceptable value
       const char* prompt,  // User entry prompt
       const char* errorMessage, // Invalid value error message
       bool showRangeAtError    // display the range if invalud value entered 
   )
   {       
       int value = getInt(prompt);
       while (value > max || value < min)
       {
           if (errorMessage != nullptr)
           {              
               cerr << errorMessage;
           }
           if (showRangeAtError)
           {   // is of the form "[MM <= value <= XX]"
               cout << '[' << min << " <= " << "value" << " <= " << max << ']'<<": ";
           }           
           value = getInt(); //call with no prompt
       }       
       return value;
   }
   
   //Prompts the user for the entry if the prompt argument is not null.
   char* getcstr(
       const char* prompt,   // User entry prompt
       std::istream& istr,  // the Stream to read from
       char delimiter  // Delimiter to mark the end of data
   )
   {
       //while (cin.get() != '\n');
       string str;
           if (prompt != nullptr)
           {
               cout << prompt;
           }
           getline(istr, str, delimiter);
           char* cpy =nullptr;
           cpy = new char[str.size() + 1];         
           strcpy(cpy, &str[0]);
           return cpy;
   }
}
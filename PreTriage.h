/* Citation and Sources...
Module: PreTriage
Filename: PreTriage.cpp
Version 1.0
Author: Aryaman Rastogi
-----------------------------------------------------------
Date:           April 11, 2021
-----------------------------------------------------------
I have done all the coding by myself and only took reference from the
code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#include"Time.h"
#include"Patient.h"
#include"Menu.h"
namespace sdds
{   
    const int maxNoOfPatients = 100;
    class PreTriage
    {
        Time
            m_averCovidWait,
            m_averTriageWait;
        Patient* m_lineup[maxNoOfPatients]{};
        char* m_dataFilename = nullptr;
        int m_lineupSize = 0;
        Menu
            m_appMenu,
            m_pMenu;
        //Registers a new patient
        void reg();
        //Calls the next patient in line to be admitted to the COVID test centre or Triage centre
        void admit();
        //Receives a constant Patient Referenceand returns the total estimated wait time for that type of Patient(COVID or Triage)
        const Time getWaitTime(const Patient& p)const;
        //Receives the reference of the admitting patient and adjusts the average wait time of that type of patient base on the admittance time of the patient.
        void setAverageWaitTime(const Patient& p);
        void removePatientFromLineup(int index);
        //Finds the index of the first patient in line which matches the type argument
        int indexOfFirstInLine(char type) const;
        //Loads the average wait times and the patient records from the data file and stores them in the m_lineup array.
        void load();
    public:
        //constructor
        PreTriage(const char* dataFilename);
        //destructor
        ~PreTriage();
        //displays m_appMenu and gets the selection
        void run(void);
    };
}
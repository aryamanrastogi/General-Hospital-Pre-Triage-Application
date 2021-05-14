/* Citation and Sources...
Module: PreTriage
Filename: PreTriage.h
Version 1.0
Author: Aryaman Rastogi
-----------------------------------------------------------
Date:           April 11, 2021
-----------------------------------------------------------
I have done all the coding by myself and only took reference from the
code that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include "Patient.h"
#include "CovidPatient.h"
#include "TriagePatient.h"
#include "PreTriage.h"
#include "utils.h"

namespace sdds
{
    PreTriage::PreTriage(const char* dataFilename) :
        m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2),
        m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2)
    {
        if (dataFilename != nullptr)
        {
            m_dataFilename = new char[strlen(dataFilename) + 1];
            strcpy(m_dataFilename, dataFilename);
        }
        m_averCovidWait = 15;
        m_averTriageWait = 5;
        load();
    };

    PreTriage::~PreTriage()
    {        
        std::ofstream fout(m_dataFilename, std::ios::trunc);

        std::cout << "Saving Average Wait Times," << std::endl;
        std::cout << "   COVID Test: " << m_averCovidWait << std::endl;
        std::cout << "   Triage: " << m_averTriageWait << std::endl;

        fout << m_averCovidWait << "," << m_averTriageWait << std::endl;
        
        std::cout << "Saving m_lineup..." << std::endl;
        for (int i = 0; i < m_lineupSize; i++)
        {
            m_lineup[i]->csvWrite(fout);
            fout << std::endl;
            std::cout << (i + 1) << "- ";
            m_lineup[i]->csvWrite(std::cout) << std::endl;
        }
        std::cout << "done!\n";
        
        fout.close();
        for (int i = 0; i < m_lineupSize; i++)
        {
            delete m_lineup[i];
        }
        delete[] m_dataFilename;
    };

    const Time PreTriage::getWaitTime(const Patient& p)const
    {
        unsigned int count = 0;
        for (int i = 0; i < m_lineupSize; i++)
        {
            if (p == *m_lineup[i])count++;
        }
        return Time(p) * count;
    };

    void PreTriage::setAverageWaitTime(const Patient& p)
    {
        Time CP;
        CP.setToNow();
        if (p == 'C')
        {
            m_averCovidWait = ((int)(CP - Time(p)) + ((int)m_averCovidWait * (p.number() - 1))) / p.number();
        }
        else
        {
            m_averTriageWait = ((int)(CP - Time(p)) + ((int)m_averTriageWait * (p.number() - 1))) / p.number();
        }
    };

    void PreTriage::removePatientFromLineup(int index)
    {
        removeDynamicElement(m_lineup, index, m_lineupSize);
    };

    int PreTriage::indexOfFirstInLine(char type) const
    {
        int index = -1;
        for (int i = 0; i < m_lineupSize; i++)
        {
            if (*(m_lineup[i]) == type)
            {
                index = i;
                break;
            }
        }
        return index;
    };

    void PreTriage::load()
    {
        Patient* p = nullptr;
        char type = '\0';
        std::ifstream fin(m_dataFilename);
        std::cout << "Loading data...\n";
        if (fin)
        {
            fin >> m_averCovidWait;
            fin.ignore();
            fin >> m_averTriageWait;
            fin.ignore(100, '\n');
            if ((int)m_averCovidWait == 0)
            {
                m_averCovidWait = 15;
            }
            if ((int)m_averTriageWait == 0)
            {
                m_averTriageWait = 5;
            }
        }
        while (m_lineupSize < maxNoOfPatients)
        {
            fin.get(type);
            fin.ignore();
            if (type == 'C')
            {
                p = new CovidPatient();
            }
            else if (type == 'T')
            {
                p = new TriagePatient();
            }
            else
            {
                break;
            }
            type = '\0';

            if (p)
            {
                p->fileIO(true);
                p->csvRead(fin);
                p->fileIO(false);
                m_lineup[m_lineupSize] = p;
                m_lineupSize++;
            }
        }
        if (m_lineupSize >= maxNoOfPatients)
        {
            std::cout << "Warning: number of records exceeded " << maxNoOfPatients << std::endl;
        }
        if (m_lineupSize == 0)
        {
            std::cout << "No data or bad data file!" << std::endl << std::endl;
        }
        else
        {
            std::cout << m_lineupSize << " Records imported..." << std::endl << std::endl;
        }
        fin.close();
    };

    void PreTriage::reg()
    {
        if (m_lineupSize == maxNoOfPatients)
        {
            std::cout << "Line up full!" << std::endl;
        }
        else
        {
            int selection;
            m_pMenu >> selection;
            switch (selection)
            {
            case 1: m_lineup[m_lineupSize] = new CovidPatient();
                break;
            case 2: m_lineup[m_lineupSize] = new TriagePatient();
                break;
            case 0:
                break;
            }
            m_lineup[m_lineupSize]->setArrivalTime();
            std::cout << "Please enter patient information: \n";
            std::cin >> *(m_lineup[m_lineupSize]);
            std::cout << std::endl;
            std::cout << "******************************************" << std::endl;
            std::cout << *m_lineup[m_lineupSize];
            std::cout << "Estimated Wait Time: " << getWaitTime(*(m_lineup[m_lineupSize])) << std::endl;
            std::cout << "******************************************" << std::endl << std::endl;
            m_lineupSize++;
        }
    };

    void PreTriage::admit()
    {
        int selection;
        char type = '\0';
        m_pMenu >> selection;
        switch (selection)
        {
        case 1: type = 'C';
            break;
        case 2: type = 'T';
            break;
        case 0:
            break;
        }
        int indexOfPatient = -1;
        if (type) indexOfPatient = indexOfFirstInLine(type);
        if (indexOfPatient > -1)
        {
            std::cout << "\n******************************************" << std::endl;
            m_lineup[indexOfPatient]->fileIO(false);
            std::cout << "Calling for " << *m_lineup[indexOfPatient];
            std::cout << "******************************************" << std::endl << std::endl;
            setAverageWaitTime(*m_lineup[indexOfPatient]);
            removePatientFromLineup(indexOfPatient);
        }
    };

    void PreTriage::run(void)
    {
        int selection;
        do
        {
            m_appMenu >> selection;
            switch (selection)
            {
            case 1: reg();
                break;
            case 2: admit();
                break;
            case 0:
                break;
            }
        } while (selection != 0);
    };
}
/* Citation and Sources...
Final Project Milestone 5
Module: PreTriage
Filename: PreTriage.h
Version 1.0
Author   Ridwan Khan
Revision History
-----------------------------------------------------------
Date      Reason
2024/04/08  Preliminary release
2023/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SENECA_PRETRIAGE_H_
#define SENECA_PRETRIAGE_H_

#include "Time.h"
#include "Patient.h"

namespace seneca {

    const int maxNoOfPatients = 100; // Maximum number of patients

    class PreTriage {
        Time m_averCovidWait; // Average wait time for Covid test
        Time m_averTriageWait; // Average wait time for Triage
        Patient* m_lineup[maxNoOfPatients]; // Lineup of patients
        char* m_dataFilename; // Data filename
        int m_lineupSize; // Number of patients in the lineup

    public:
        PreTriage(const char* dataFilename);
        ~PreTriage();

    private:
        Time getWaitTime(const Patient& p) const;
        void setAverageWaitTime(const Patient& p);
        int indexOfFirstInLine(char type) const;
        void load();
        void save();
        void registerPatient();
        void admit();
        void lineup();
    public:
        void run();
    };
}

#endif // SENECA_PRETRIAGE_H_

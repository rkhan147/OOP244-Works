/* Citation and Sources...
Final Project Milestone 5
Module: PreTriage
Filename: PreTriage.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include "PreTriage.h"
#include "Menu.h"
#include "TestPatient.h"
#include "TriagePatient.h"
#include "Utils.h"
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>

namespace seneca {

    PreTriage::PreTriage(const char* dataFilename) {
        m_dataFilename = new char[strlen(dataFilename) + 1];
        strcpy(m_dataFilename, dataFilename);
        m_averCovidWait = 15;
        m_averTriageWait = 5;
        m_lineupSize = 0;
        for (int i = 0; i < maxNoOfPatients; ++i) {
            m_lineup[i] = nullptr;
        }
        load();
    }

    PreTriage::~PreTriage() {
        save();
        for (int i = 0; i < m_lineupSize; ++i) {
            delete m_lineup[i];
        }
        delete[] m_dataFilename;
    }

    void PreTriage::load() {
        std::cout << "Loading data..." << std::endl;
        std::ifstream file(m_dataFilename);
        int count = 0;
        if (file) {
            // Read the first line and split it by comma
            std::string line;
            std::getline(file, line);
            std::stringstream sstream(line);
            std::string token;

            // Update m_averCovidWait
            std::getline(sstream, token, ',');
            std::stringstream ss1(token);
            m_averCovidWait.read(ss1);

            // Update m_averTriageWait
            std::getline(sstream, token, ',');
            std::stringstream ss2(token);
            m_averTriageWait.read(ss2);

            while (std::getline(file, line)) {
                if (m_lineupSize >= maxNoOfPatients) {
                    std::cout << "Warning: number of records exceeded 100" << std::endl;
                    break;
                }

                if (line[0] == 'C') {
                    m_lineup[m_lineupSize] = new TestPatient();
                }
                else if (line[0] == 'T') {
                    m_lineup[m_lineupSize] = new TriagePatient();
                }
                if (m_lineup[m_lineupSize]) {
                    std::stringstream sstream(line.substr(2));
                    m_lineup[m_lineupSize]->read(sstream);
                    ++m_lineupSize;
                    ++count;
                }
            }
            file.close();
        }
        if (count == 0) {
            std::cout << "No data or bad data file!\n" << std::endl;
        }
        else {
            std::cout << count << " Records imported...\n" << std::endl;
        }
    }


    void PreTriage::save() {
        std::cout << "Saving lineup..." << std::endl;
        std::ofstream file(m_dataFilename);
        int countC = 0;
        int countT = 0;
        if (file) {
            file << m_averCovidWait << "," << m_averTriageWait << std::endl;
            for (int i = 0; i < m_lineupSize; ++i) {
                m_lineup[i]->write(file);
                file << std::endl;
                if (m_lineup[i]->type() == 'C') {
                    ++countC;
                }
                else {
                    ++countT;
                }
            }
        }
        std::cout << countC << " Contagion Tests and " << countT << " Triage records were saved!" << std::endl;
    }

    Time PreTriage::getWaitTime(const Patient& p) const {
        int count = 0;
        for (int i = 0; i < m_lineupSize; ++i) {
            if (*m_lineup[i] == p.type()) {
                ++count;
            }
        }
        return Time(count * (p.type() == 'C' ? m_averCovidWait : m_averTriageWait));
    }

    void PreTriage::setAverageWaitTime(const Patient& p) {
        int PTN = p.number();
        Time PTT = p.time();
        Time CT = CT.reset();  // Assuming Time() returns the current time
        Time AWT = p.type() == 'C' ? m_averCovidWait : m_averTriageWait;
        AWT = ((CT - PTT) + (AWT * (PTN - 1))) / PTN;
        if (p.type() == 'C') {
            m_averCovidWait = AWT;
        }
        else {
            m_averTriageWait = AWT;
        }
    }

    int PreTriage::indexOfFirstInLine(char type) const {
        for (int i = 0; i < m_lineupSize; ++i) {
            if (*m_lineup[i] == type) {
                return i;
            }
        }
        return -1;
    }

    void PreTriage::registerPatient() {
        if (m_lineupSize >= maxNoOfPatients) {
            std::cout << "Line up full!" << std::endl;
            return;
        }
        Menu menu("Select Type of Registration:\n1- Contagion Test\n2- Triage\n", 1);
        int selection;
        menu >> selection;
        switch (selection) {
        case 1:
            m_lineup[m_lineupSize] = new TestPatient();
            break;
        case 2:
            m_lineup[m_lineupSize] = new TriagePatient();
            break;
        default:
            return;
        }
        if (m_lineup[m_lineupSize]) {
            std::cout << "Please enter patient information: \n";
            m_lineup[m_lineupSize]->setArrivalTime();
            m_lineup[m_lineupSize]->read(std::cin);
            std::cout << "\n******************************************" << std::endl;
            m_lineup[m_lineupSize]->write(std::cout);
            std::cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]) << std::endl;
            std::cout << "******************************************\n\n";
            m_lineupSize++;
        }
    }

    void PreTriage::admit() {
        Menu menu("Select Type of Admittance:\n1- Contagion Test\n2- Triage\n", 1);
        int selection;
        menu >> selection;
        char type;
        if (selection == 1) {
            type = 'C';
        }
        else if (selection == 2) {
            type = 'T';
        }
        else {
            return;
        }
        int index = indexOfFirstInLine(type);
        if (index == -1) {
            std::cout << "Lineup is empty!" << std::endl;
            return;
        }
        Time currentTime;
        std::cout << std::endl;
        std::cout << "******************************************" << std::endl;
        std::cout << "Call time: [" << currentTime.reset() << "]" << std::endl;
        std::cout << "Calling at for " << *m_lineup[index];
        std::cout << "******************************************" << std::endl << std::endl;
        setAverageWaitTime(*m_lineup[index]);
        removeDynamicElement(m_lineup, index, m_lineupSize);
        if (type == 'C') {
            m_averCovidWait = getWaitTime(*m_lineup[index]);
        }
        else {
            m_averTriageWait = getWaitTime(*m_lineup[index]);
        }
    }

    void PreTriage::lineup() {
        Menu menu("Select The Lineup:\n1- Contagion Test\n2- Triage\n", 1);
        int selection;
        menu >> selection;
        char type;
        if (selection == 1) {
            type = 'C';
        }
        else if (selection == 2) {
            type = 'T';
        }
        else {
            return;
        }
        std::cout << "Row - Patient name                                          OHIP     Tk #  Time" << std::endl;
        std::cout << "-------------------------------------------------------------------------------" << std::endl;
        int count = 1;
        for (int i = 0; i < m_lineupSize; ++i) {
            if (*m_lineup[i] == type) {
                std::cout << count << "   - ";
                std::stringstream sstream;
                m_lineup[i]->write(sstream);
                std::string line, name, OHIP, ticketNumber, time;
                std::getline(sstream, line, ',');
                std::getline(sstream, name, ',');
                std::getline(sstream, OHIP, ',');
                std::getline(sstream, ticketNumber, ',');
                std::getline(sstream, time, ',');
                std::cout << std::left << std::setfill('.') << std::setw(53) << name << OHIP;
                std::cout << "   " << ticketNumber << " " << time << std::endl;
                count++;
            }
        }
        std::cout << "-------------------------------------------------------------------------------" << std::endl;
    }

    void PreTriage::run() {
        Menu menu("General Healthcare Facility Pre-Triage Application\n1- Register\n2- Admit\n3- View Lineup\n", 0);
        while (true) {
            int selection;
            menu >> selection;
            if (selection == 1) {
                registerPatient();
            }
            else if (selection == 2) {
                admit();
            }
            else if (selection == 3) {
                lineup();
            }
            else {
                break;
            }
        }
    }
}

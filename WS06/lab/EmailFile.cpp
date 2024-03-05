/***********************************************************************
// OOP244 Workshop # 6
//
// File: EmailFile.cpp
// Version 1.0
// Date:
// Author: Sina Talebi Moghaddam
// Description
// This file must be completed by students
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <cstring>
#include "EmailFile.h"

using namespace std;
namespace seneca
{

    Email& Email::operator=(const Email& rhs) {

        if (this != &rhs && rhs.m_email && rhs.m_name) {
            delete[] m_email;
            m_email = nullptr;
            m_email = new char[strlen(rhs.m_email) + 1];
            strcpy(m_email, rhs.m_email);
            delete[] m_name;
            m_name = nullptr;
            m_name = new char[strlen(rhs.m_name) + 1];
            strcpy(m_name, rhs.m_name);
            strcpy(m_year, rhs.m_year);
        }

        return *this;
    }

    bool Email::load(std::ifstream& in) {

        char buffer[BUFFER_SIZE];
        bool result = false;

        if (in.getline(buffer, BUFFER_SIZE, ',')) {
            delete[] m_email;
            m_email = new char[strlen(buffer) + 1];
            strcpy(m_email, buffer);

            if (in.getline(buffer, BUFFER_SIZE, ',')) {
                delete[] m_name;
                m_name = new char[strlen(buffer) + 1];
                strcpy(m_name, buffer);

                if (in.getline(buffer, BUFFER_SIZE, '\n')) {
                    strcpy(m_year, buffer);
                    result = true;
                }
            }
        }

        return result;
    }

    Email::~Email() {
        delete[] m_name;
        delete[] m_email;
    }

    void EmailFile::setFilename(const char* filename)
    {
        delete[] m_filename;
        m_filename = nullptr;
        if (filename)
        {
            m_filename = new char[strlen(filename) + 1];
            m_filename[0] = '\0';
            strcpy(m_filename, filename);
        }
    }

    void EmailFile::setEmpty()
    {
        delete[] m_emailLines;
        delete[] m_filename;
        m_emailLines = nullptr;
        m_filename = nullptr;
        m_noOfEmails = 0;
    }

    bool EmailFile::setNoOfEmails() {

        bool isValid = false;
        ifstream file(m_filename);

        if (!file.is_open()) {
            cout << "Failed to open file: " << m_filename << endl;
        }
        else
        {
            m_noOfEmails = 0;
            while (file) {
                m_noOfEmails += (file.get() == '\n');
            }
            file.close();

            if (m_noOfEmails == 0)
            {
                delete[] m_filename;
                m_filename = nullptr;
            }
            else {
                m_noOfEmails++;
                isValid = true;
            }
        }
        return isValid;
    }

    void EmailFile::loadEmails() {
        if (m_filename != nullptr) {
            delete[] m_emailLines;
            m_emailLines = new Email[m_noOfEmails];
            std::ifstream file(m_filename);
            for (int i = 0; i < m_noOfEmails; ++i) {
                if (!m_emailLines[i].load(file)) {
                    break;
                }
            }
            file.close();
        }
    }

    EmailFile::EmailFile() : m_emailLines(nullptr), m_filename(nullptr), m_noOfEmails(0) {}

    EmailFile::EmailFile(const char* filename) : EmailFile() {
        if (filename != nullptr) {
            setFilename(filename);
            if (setNoOfEmails()) {
                loadEmails();
            }
        }
    }

    EmailFile::EmailFile(const EmailFile& other) : EmailFile() {
        *this = other;
    }

    EmailFile& EmailFile::operator=(const EmailFile& other) {
        if (this != &other) {
            delete[] m_emailLines;
            delete[] m_filename;
            m_emailLines = nullptr;
            m_filename = nullptr;
            m_noOfEmails = other.m_noOfEmails;
            if (other.m_filename != nullptr) {
                setFilename(other.m_filename);
                loadEmails();
            }
        }
        return *this;
    }

    EmailFile::~EmailFile() {
        delete[] m_emailLines;
        delete[] m_filename;
    }

    EmailFile::operator bool() const {
        return m_filename != nullptr;
    }

    std::ostream& EmailFile::view(std::ostream& ostr) const
    {
        if (m_filename) {
            ostr << m_filename << endl;
            ostr.width(strlen(m_filename));
            ostr.fill('=');
            ostr << "=" << endl;
            ostr.fill(' ');
            for (int i = 0; i < m_noOfEmails - 1; i++) {
                ostr.width(35);
                ostr.setf(ios::left);
                ostr << m_emailLines[i].m_email;
                ostr.width(25);
                ostr << m_emailLines[i].m_name;
                ostr << "Year = " << m_emailLines[i].m_year << endl;
            }
        }

        return ostr;
    }

    std::ostream& operator<<(std::ostream& ostr, const EmailFile& text)
    {
        return text.view(ostr);
    }

    bool EmailFile::saveToFile(const char* filename) const {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cout << "Error: Could not open file: " << filename << std::endl;
            return false;
        }
        for (int i = 0; i < m_noOfEmails - 1; ++i) {
            file << m_emailLines[i].m_email << ','
                << m_emailLines[i].m_name << ','
                << m_emailLines[i].m_year << '\n';
        }
        file.close();
        return true;
    }

}

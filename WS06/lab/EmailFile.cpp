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
namespace seneca {

    // Email class implementations
    Email::~Email() {
        delete[] m_email;
        delete[] m_name;
    }

    Email& Email::operator=(const Email& rhs) {
        if (this != &rhs && rhs.m_email && rhs.m_name) {
            delete[] m_email;
            m_email = new char[strlen(rhs.m_email) + 1];
            strcpy(m_email, rhs.m_email);
            delete[] m_name;
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

    // EmailFile class implementations
    EmailFile::EmailFile() : m_emailLines(nullptr), m_filename(nullptr), m_noOfEmails(0) {}

    EmailFile::EmailFile(const char* filename) : EmailFile() {
        if (filename) {
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
            m_emailLines = nullptr;
            m_noOfEmails = other.m_noOfEmails;
            copyEmails(other);
        }
        return *this;
    }

    EmailFile::~EmailFile() {
        delete[] m_emailLines;
        delete[] m_filename;
    }

    void EmailFile::copyEmails(const EmailFile& src) {
        if (src.m_emailLines) {
            m_emailLines = new Email[src.m_noOfEmails];
            for (int i = 0; i < src.m_noOfEmails; ++i) {
                m_emailLines[i] = src.m_emailLines[i];
            }
        }
    }

    void EmailFile::setFilename(const char* filename) {
        delete[] m_filename;
        if (filename) {
            m_filename = new char[strlen(filename) + 1];
            strcpy(m_filename, filename);
        }
        else {
            m_filename = nullptr;
        }
    }

    void EmailFile::setEmpty() {
        delete[] m_emailLines;
        m_emailLines = nullptr;

        delete[] m_filename;
        m_filename = nullptr;

        m_noOfEmails = 0;
    }

    bool EmailFile::setNoOfEmails() {
        ifstream file(m_filename);
        if (!file) {
            cout << "Failed to open file: " << m_filename << endl;
            return false;
        }

        m_noOfEmails = 0;
        char c;
        while (file.get(c)) {
            if (c == '\n') {
                m_noOfEmails++;
            }
        }
        file.close();
        if (m_noOfEmails > 0) {
            m_noOfEmails++;
        }
        return true;
    }


    void EmailFile::loadEmails() {
        if (m_filename) {
            ifstream file(m_filename);
            if (file) {
                m_emailLines = new Email[m_noOfEmails];
                int i = 0;
                while (file && i < m_noOfEmails) {
                    if (!m_emailLines[i].load(file)) {
                        break;
                    }
                    i++;
                }
                m_noOfEmails = i;
            }
        }
    }

    bool EmailFile::saveToFile(const char* filename) const {
        ofstream out(filename);
        if (!out) {
            cerr << "Error: Could not open file: " << filename << endl;
            return false;
        }
        for (int i = 0; i < m_noOfEmails; ++i) {
            out << m_emailLines[i].m_email << ',' << m_emailLines[i].m_name << ',' << m_emailLines[i].m_year << endl;
        }
        return true;
    }

    void EmailFile::fileCat(const EmailFile& obj, const char* name) {
        if (*this && obj) {
            Email* temp = new Email[m_noOfEmails + obj.m_noOfEmails];
            for (int i = 0; i < m_noOfEmails; ++i) {
                temp[i] = m_emailLines[i];
            }
            for (int j = 0; j < obj.m_noOfEmails; ++j) {
                temp[m_noOfEmails + j] = obj.m_emailLines[j];
            }
            delete[] m_emailLines;
            m_emailLines = temp;
            m_noOfEmails += obj.m_noOfEmails;
            if (name) {
                setFilename(name);
            }
            saveToFile(m_filename);
        }
    }

    EmailFile::operator bool() const {
        return m_filename != nullptr && m_emailLines != nullptr && m_noOfEmails > 0;
    }

    std::ostream& EmailFile::view(std::ostream& ostr) const {
        if (m_filename) {
            ostr << m_filename << endl;
            ostr.width(strlen(m_filename));
            ostr.fill('=');
            ostr << "=" << endl;
            ostr.fill(' ');
            for (int i = 0; i < m_noOfEmails; i++) {
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

    std::ostream& operator<<(std::ostream& ostr, const EmailFile& text) {
        return text.view(ostr);
    }

}


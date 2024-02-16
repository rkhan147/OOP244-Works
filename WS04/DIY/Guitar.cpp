/***********************************************************************
// OOP244 Workshop #4 p2: tester program
//
// Version 1.0
// Date: Summer 2023
// Author Michael Huang
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
// Implementation
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Guitar.h"
using namespace std;

namespace seneca {

    const char* GuitarStr::material() const {
        return m_material;
    }

    double GuitarStr::gauge() const {
        return m_gauge;
    }

    GuitarStr::GuitarStr() {
        m_material[0] = '\0';
        m_gauge = 0.0;
    }

    GuitarStr::GuitarStr(const char* ma, double ga) {
        strncpy(m_material, ma, MAT_LEN);
        m_material[MAT_LEN - 1] = '\0';
        m_gauge = ga;
    }

    Guitar::Guitar(const char* mod) {
        m_strings = nullptr;
        m_numStrings = 0;
        strncpy(m_model, mod, MOD_LEN);
    }

    Guitar::Guitar(GuitarStr strs[], int ns, const char* mod) {
        if (ns > 0 && strs != nullptr && mod != nullptr) {
            m_strings = new GuitarStr[ns];
            for (int i = 0; i < ns; i++) {
                m_strings[i] = strs[i];
            }
            m_numStrings = ns;
            strncpy(m_model, mod, MOD_LEN);
        }
        else {
            m_strings = nullptr;
            m_numStrings = 0;
            m_model[0] = '\0';
        }
    }

    Guitar::~Guitar() {
        delete[] m_strings;
    }

    bool Guitar::changeString(const GuitarStr& gs, int sn) {
        if (sn >= 0 && sn < m_numStrings) {
            m_strings[sn] = gs;
            return true;
        }
        return false;
    }

    void Guitar::reString(GuitarStr strs[], int ns) {
        delete[] m_strings;
        if (ns > 0 && strs != nullptr) {
            m_strings = new GuitarStr[ns];
            for (int i = 0; i < ns; i++) {
                m_strings[i] = strs[i];
            }
            m_numStrings = ns;
        }
        else {
            m_strings = nullptr;
            m_numStrings = 0;
        }
    }

    void Guitar::deString() {
        delete[] m_strings;
        m_strings = nullptr;
        m_numStrings = 0;
    }

    bool Guitar::strung() const {
        return m_numStrings > 0;
    }

    bool Guitar::matchGauge(double ga) const {
        for (int i = 0; i < m_numStrings; i++) {
            if (m_strings[i].gauge() == ga) {
                return true;
            }
        }
        return false;
    }

ostream& Guitar::display(ostream& os) const {
    if (m_numStrings == 0) {
        os << "***Empty Guitar***\n";
    } else {
        os << "Guitar Model: " << m_model << "\n";
        os << "Strings: " << m_numStrings << "\n";
        os << fixed;
        os << setprecision(1);
        for (int i = 0; i < m_numStrings; i++) {
            os << "#" << (i + 1) << setw(MAT_LEN) << right << m_strings[i].material() << " | " << m_strings[i].gauge() << "\n";
        }
        os.unsetf(ios_base::floatfield);  // Reset to default floating-point format
    }
    return os;
}
}
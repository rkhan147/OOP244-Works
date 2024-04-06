/* Citation and Sources...
Final Project Milestone 1
Module: Time
Filename: Time.h
Version 1.0
Author   Ridwan Khan
Revision History
-----------------------------------------------------------
Date      Reason
2024/03/13  Preliminary release
2023/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SENECA_TIME_H_
#define SENECA_TIME_H_

#include <iostream>

namespace seneca {
    class Time {
        unsigned int m_minutes; // Attribute to store number of minutes

    public:
        /**
         * @brief Default constructor initializing Time object with given number of minutes.
         * @param min Number of minutes, defaults to 0.
         */
        Time(unsigned int min = 0u);

        /**
         * @brief Resets the Time object to current time.
         * @return Reference to the current Time object.
         */
        Time& reset();

        /**
         * @brief Writes the time in HH:MM format to the ostream.
         * @param os Reference to the output stream.
         */
        void write(std::ostream& os) const;

        /**
         * @brief Reads the time from istream in the H:M format.
         * @param is Reference to the input stream.
         */
        void read(std::istream& is);

        /**
         * @brief Conversion operator to unsigned int.
         * @return Number of minutes held in the Time object.
         */
        operator unsigned int() const;

        /**
         * @brief Multiplication assignment operator.
         * @param val Value to multiply with.
         * @return Reference to the current Time object.
         */
        Time& operator*=(int val);

        /**
         * @brief Subtraction assignment operator.
         * @param D Time object to subtract.
         * @return Reference to the current Time object.
         */
        Time& operator-=(const Time& D);

        /**
         * @brief Subtraction operator.
         * @param T Time object to subtract.
         * @return New Time object representing the time difference.
         */
        Time operator-(const Time& T) const;
    };

    /**
     * @brief Overload of insertion operator to insert Time object into ostream.
     * @param os Reference to the output stream.
     * @param T Time object to insert.
     * @return Reference to the output stream.
     */
    std::ostream& operator<<(std::ostream& os, const Time& T);

    /**
     * @brief Overload of extraction operator to extract data from istream into Time object.
     * @param is Reference to the input stream.
     * @param T Time object to extract data into.
     * @return Reference to the input stream.
     */
    std::istream& operator>>(std::istream& is, Time& T);
}

#endif // !SENECA_TIME_H_
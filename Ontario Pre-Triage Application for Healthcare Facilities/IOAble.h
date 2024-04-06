/* Citation and Sources...
Final Project Milestone 2
Module: IOAble
Filename: IOAble.h
Version 1.0
Author   Ridwan Khan
Revision History
-----------------------------------------------------------
Date      Reason
2024/03/16  Preliminary release
2023/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SENECA_IOABLE_H
#define SENECA_IOABLE_H

#include <iostream>

namespace seneca {

    class IOAble {
    public:
        /**
         * @brief Pure virtual function for writing to ostream.
         * @param ostr Reference to an output stream.
         * @return Reference to the same output stream.
         */
        virtual std::ostream& write(std::ostream& ostr) const = 0;

        /**
         * @brief Pure virtual function for reading from istream.
         * @param istr Reference to an input stream.
         * @return Reference to the same input stream.
         */
        virtual std::istream& read(std::istream& istr) = 0;

        /**
         * @brief Virtual destructor.
         */
        virtual ~IOAble() {};
    };

    /**
     * @brief Overload of insertion operator to insert IOAble object into ostream.
     * @param ostr Reference to the output stream.
     * @param io Reference to the IOAble object.
     * @return Reference to the output stream.
     */
    std::ostream& operator<<(std::ostream& ostr, const IOAble& io);

    /**
     * @brief Overload of extraction operator to extract data from istream into IOAble object.
     * @param istr Reference to the input stream.
     * @param io Reference to the IOAble object.
     * @return Reference to the input stream.
     */
    std::istream& operator>>(std::istream& istr, IOAble& io);
}

#endif // !SENECA_IOABLE_H
#include <iostream>
#include <iomanip>
#include "file.h"
#include "io.h"
#include "graph.h"
#include "StMark.h"

namespace seneca {
    
    bool printReport(const char* filename) {

        struct StMark s[MAX_NO_RECS];
        int samples[10] = {};

        if (openFile(filename)) {

            int size = readMarks(s);
            bubbleSort(s, size);
            getSamples(s, samples, size);
            printGraph(samples, 10, "Students' mark distribution");
            printStudentRecords(s, size);
            closeFile();

            return true;
        }

        return false;
    }

    void bubbleSort(struct StMark* s, int size) {

        for (int i = 0; i < size - 1; ++i) {

            for (int j = 0; j < size - i - 1; ++j) {

                if (s[j].mark < s[j + 1].mark) {

                    swap(s[j], s[j + 1]);

                }
            }
        }
    }

    void swap(StMark& a, StMark& b) {

        StMark temp = a;
        a = b;
        b = temp;

    }

    void getSamples(struct StMark* s, int samples[], int size) {

        for (int i = 0; i < size; i++) {

            if (s[i].mark > 90) samples[0]++;
            else if (s[i].mark > 80 && s[i].mark <= 90) samples[1]++;
            else if (s[i].mark > 70 && s[i].mark <= 80) samples[2]++;
            else if (s[i].mark > 60 && s[i].mark <= 70) samples[3]++;
            else if (s[i].mark > 50 && s[i].mark <= 60) samples[4]++;
            else if (s[i].mark > 40 && s[i].mark <= 50) samples[5]++;
            else if (s[i].mark > 30 && s[i].mark <= 40) samples[6]++;
            else if (s[i].mark > 20 && s[i].mark <= 30) samples[7]++;
            else if (s[i].mark > 10 && s[i].mark <= 20) samples[8]++;
            else if (s[i].mark >= 0 && s[i].mark <= 10) samples[9]++;
        }
    }
    void printStudentRecords(struct StMark* s, int size) {

        for (int i = 0; i < size; i++) {

            std::cout << 
                std::left << 
                std::setw(3) << 
                i + 1 << 
                ": [" << 
                std::left << 
                std::setw(3) << 
                s[i].mark << 
                "] " <<
                s[i].name <<
                " " <<
                s[i].surname <<
                std::endl;
        }
    }
}
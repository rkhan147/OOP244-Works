/*
Name: Ridwan Khan
Email: rkhan147@myseneca.ca
ID: 162409213
Date: 2024-04-05

I have done all the coding by myself and only copied the code that
my professor provided to complete my workshops and assignments.
*/
#ifndef SENECA_MATCHPAIR_H
#define SENECA_MATCHPAIR_H

template<typename T, typename U>
struct Pair {
    T first;
    U second;
};

template<typename T, typename U>
void addDynamicPairElement(Pair<T, U>*& pArray, const T& first, const U& second, int& size) {
    Pair<T, U>* temp = new Pair<T, U>[size + 1];
    for (int k = 0; pArray && k < size; k++) {
        temp[k] = pArray[k];
    }
    temp[size].first = first;
    temp[size].second = second;
    delete[] pArray;
    pArray = temp;
    size++;
}

template<typename T, typename U>
Pair<T, U>* matches(const T arr1[], const U arr2[], int size1, int size2, int& size3) {
    Pair<T, U>* pt = nullptr;
    size3 = 0;
    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) {
            if (arr1[i] == arr2[j]) {
                addDynamicPairElement(pt, arr1[i], arr2[j], size3);
            }
        }
    }
    return pt;
}

template<typename T>
void releaseMem(T* ptr) {
    if (ptr) {
        delete[] ptr;
        ptr = nullptr;
    }
}

#endif
/*

Name: Ridwan Khan
Email: rkhan147@myseneca.ca
ID: 162409213
Date: January 21, 2024

I have done all the coding by myself and only copied the
code that my professor provided to complete my workshops and
assignments.

*/

/***********************************************************************
OOP244 Workshop # p2: 
Version 1.0
Date	   winter 2024
Author	Fardad Soleimanloo
Description
  tests the file module of workshop 1 part 2(DIY)
Revision History
-----------------------------------------------------------
Name            Date            Reason
***********************************************************************/
#ifndef SENECA_STMARK_H
#define SENECA_STMARK_H
namespace seneca {

   /// <summary>
   /// Record of a mark received by a student.
   /// </summary>
   struct StMark {
      char name[21];
      char surname[31];
      int mark;
   };

   /// <summary>
   /// Tries to open the students' mark data file. 
   /// If successful it will print a report based on the 
   /// date in the file.
   /// </summary>
   /// <param name="filename">, holds the data file name</param>
   /// <returns>True if the date files is opened succesfully, 
   /// otherwise returns false</returns>
   bool printReport(const char* filename);
   void bubbleSort(struct StMark* s, int size);
   void swap(StMark& a, StMark& b);
   void getSamples(struct StMark* s, int samples[], int size);
   void printStudentRecords(struct StMark* s, int size);

}
#endif // !SENECA_STMARK_H
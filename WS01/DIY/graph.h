/*

Name: Ridwan Khan
Email: rkhan147@myseneca.ca
ID: 162409213
Date: January 13, 2024

I have done all the coding by myself and only copied the 
code that my professor provided to complete my workshops and 
assignments.

*/

#pragma once
#ifndef SENECA_GRAPH_H // replace with relevant names
#define SENECA_GRAPH_H
namespace seneca {

	// Fills the samples array with the statistic samples
	void getSamples(int samples[], int noOfSamples);
	// Finds the largest sample in the samples array, if it is larger than 70,
	// therwise it will return 70. 
	int findMax(int samples[], int noOfSamples);
	// Prints a scaled bar relevant to the maximum value in samples array
	void printBar(int val, int max);
	// Prints a graph comparing the sample values visually 
	void printGraph(int samples[], int noOfSamples, const char* label);

}
#endif
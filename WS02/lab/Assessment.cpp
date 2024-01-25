#include <iostream>
#include "Assessment.h"

namespace seneca {

	bool read(int& value, FILE* fptr)
	{
		return false;
	}
	bool read(double& value, FILE* fptr)
	{
		return false;
	}
	bool read(char* cstr, FILE* fptr)
	{
		return false;
	}
	bool read(Assessment& assess, FILE* fptr)
	{
		return false;
	}
	void freeMem(Assessment*& aptr, int size)
	{
	}
	int read(Assessment*& aptr, FILE* fptr)
	{
		return 0;
	}

}
#include "utils.h"

char* getCurrentDay()
{
	time_t currTime;
	tm* currTm;

	char *dateString1 = new char[11];
	time(&currTime);

	currTm = localtime(&currTime);

	strftime(dateString1, 11, "%d/%m/%Y", currTm);

	return dateString1;
}

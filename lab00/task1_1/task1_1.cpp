// task1_1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

int main(int argc, char* argv[])
{
	const int MIN_NUMBER = 1;
	const int MAX_NUMBER = 100;
	const int STEP = 2;
	int i;
	for (i = MAX_NUMBER; i >= MIN_NUMBER; i -= STEP)
	{
		printf("%d", i);
		if (i != MIN_NUMBER)
		{
			printf(", ");
		}
	}

	printf("\n");

	return 0;
}
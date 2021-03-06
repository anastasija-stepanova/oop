#include "stdafx.h"
#include "VectorProcessor.h"
using namespace std;


int _tmain()
{
	vector<double> numbers;

	if (!ReadNumbersIntoVector(cin, numbers))
	{
		return 1;
	}

	sort(numbers.begin(), numbers.end());
	vector<double> modifiedVector;
	ProcessVector(numbers, modifiedVector);
	PrintVectorNumbers(cout, numbers);

    return 0;
}

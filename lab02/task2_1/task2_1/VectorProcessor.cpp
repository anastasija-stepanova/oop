#include "stdafx.h"
#include "VectorProcessor.h"

bool ReadNumbersIntoVector(std::istream &input, std::vector<double> &numbers)
{
	while (!input.eof())
	{
		double number = 0;
		if (input >> number)
		{
			if ((number < DBL_MIN) || (number > DBL_MAX))
			{
				return false;
			}
			numbers.push_back(number);
		}
		else
		{
			break;
		}
	}
	return true;
}

void PrintVectorNumbers(std::ostream &output, std::vector<double> &numbers)
{
	output << std::fixed;
	output.precision(3);

	std::vector <int>::size_type vectorNumbersSize = numbers.size();
	for (std::vector <int>::size_type i = 0; i < vectorNumbersSize; ++i)
	{
		output << numbers[i] << ' ';
	}
	output << "\n";
}

void ProcessVector(std::vector<double> &numbers)
{
	if (numbers.empty())
	{
		return;
	}
	double minNumber = numbers[0];
	std::transform(numbers.begin(), numbers.end(), numbers.begin(), [=](double number) { return number *= minNumber; });
}
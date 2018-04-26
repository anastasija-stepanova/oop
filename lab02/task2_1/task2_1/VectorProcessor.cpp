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

	for (auto number : numbers)
	{
		output << number << ' ';
	}
	output << "\n";
}

void ProcessVector(std::vector<double> &numbers, std::vector<double> &modifiedNumbers)
{
	modifiedNumbers.resize(numbers.size());
	if (numbers.empty())
	{
		return;
	}
	const double minNumber = *min_element(numbers.begin(), numbers.end());
	std::transform(numbers.begin(), numbers.end(), modifiedNumbers.begin(), [=](double number) { return number *= minNumber; });
}

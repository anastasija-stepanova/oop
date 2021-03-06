// FindMaxEx.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "FindMaxEx.h"
#include "CAthlete.h"
#include <functional>

using namespace std;

int main()
{
	vector<CAthlete> athletes = {
		CAthlete("Misha", 50, 160),
		CAthlete("Valya", 49, 158),
		CAthlete("Roma", 75, 180),
		CAthlete("Petya", 61, 177),
		CAthlete("Sasha", 84, 190),
	};

	cout << "Athlete with max height: " << endl;
	CAthlete withMaxHeight;
	FindMax(athletes, withMaxHeight, [](const auto& first, const auto& second) {
		return first.GetHeight() < second.GetHeight();
	});

	withMaxHeight.GetAthleteInfo(withMaxHeight);

	cout << "Sportsman with max weight: " << endl;
	CAthlete withMaxWeight;
	FindMax(athletes, withMaxWeight, [](const auto& first, const auto& second) {
		return first.GetWeight() < second.GetWeight();
	});

	withMaxWeight.GetAthleteInfo(withMaxWeight);

	return 0;
}

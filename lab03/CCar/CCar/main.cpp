#include "stdafx.h"
#include "CCar.h"
#include "CCarController.h"

using namespace std;

int main()
{
	CCar car;
	CCarController carControl(car, cin, cout);

	while (!cin.eof() && !cin.fail())
	{
		cout << "> ";
		if (!carControl.HandleCommand())	
		{
			cout << "Unknown command!" << endl;
		}
	}
	return 0;
}
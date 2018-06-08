#include "stdafx.h"
#include "CShapeCreator.h"

using namespace std;

void DoReadShape();

int main()
{
	try
	{
		DoReadShape();
	}
	catch (exception & e)
	{
		cout << e.what() << endl;
	}
	return 0;
}

void DoReadShape()
{
	CShapeCreator creator;
	creator.Run(cin);
	string command;
	while (getline(cin, command))
	{
	}
}

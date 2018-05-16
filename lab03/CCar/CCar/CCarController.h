#pragma once
#include "stdafx.h"
#include "CCar.h"

using namespace std;

class CCarController
{
public:
	CCarController(CCar & car, istream & input, ostream & output);
	bool HandleCommand();

private:
	typedef map<string, function<void(istream & args)>> ActionMap;
	CCar & m_car;
	istream & m_input;
	ostream & m_output;
	const ActionMap m_actionMap;

	void Info(istream& input);
	void EngineOn(istream& input);
	void EngineOff(istream& input);
	void SetGear(istream & input);
	void SetSpeed(istream & input);
};

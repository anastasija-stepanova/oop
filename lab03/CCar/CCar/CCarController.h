#include <map>
#include <functional>
#include "CCar.h"

class CCarController
{
public:
	CCarController(CCar& car, std::istream& input, std::ostream& output);
	bool HandleCommand();

private:
	typedef std::map<std::string, std::function<void(std::istream& args)>> ActionMap;
	CCar& m_car;
	std::istream& m_input;
	std::ostream& m_output;
	const ActionMap m_actionMap;

	void Info(std::istream& input);
	void EngineOn(std::istream& input);
	void EngineOff(std::istream& input);
	void SetGear(std::istream& input);
	void SetSpeed(std::istream& input);
	void Exit(std::istream& input);
};
#pragma once
#include <vector>
#include <string>

class ICommand
{
public:
	virtual ~ICommand() = default;

	virtual void Execute(const std::vector<std::string>& params) = 0;
};
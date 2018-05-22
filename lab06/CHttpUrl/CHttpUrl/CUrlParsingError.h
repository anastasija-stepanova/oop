#pragma once
#include <string>
#include <exception>

class CUrlParsingError : public std::invalid_argument
{
public:
	CUrlParsingError(const std::string& message = std::string());
};

#pragma once

class IPerson
{
public:
	virtual std::string GetName() const = 0;
	virtual std::string GetSurname() const = 0;
	virtual std::string GetPatronymic() const = 0;
	virtual std::string GetAddress() const = 0;
};
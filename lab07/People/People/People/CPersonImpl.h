#pragma once

template <class Base>
class CPersonImpl : public Base
{
public:
	CPersonImpl(const std::string& name,
		const std::string& surname,
		const std::string& patronymic,
		const std::string& address)
		: m_name(name)
		, m_surname(surname)
		, m_patronymic(patronymic)
		, m_address(address)
	{
	}

	virtual std::string GetName() const
	{
		return m_name;
	}

	virtual std::string GetSurname() const
	{
		return m_surname;
	}

	virtual std::string GetPatronymic() const
	{
		return m_patronymic;
	}

	virtual std::string GetAddress() const
	{
		return m_address;
	}

private:
	std::string m_name;
	std::string m_surname;
	std::string m_patronymic;
	std::string m_address;
};
#pragma once
#include "CPersonImpl.h"

template <class Base>
class CStudentImpl : public CPersonImpl<Base>
{
public:
	CStudentImpl(const std::string& name,
		const std::string& surname,
		const std::string& patronymic,
		const std::string& address,
		const std::string& universityName,
		size_t studentTicketNumber)
		: CPersonImpl<Base>(name, surname, patronymic, address)
		, m_universityName(universityName)
		, m_studentTicketNumber(studentTicketNumber)
	{
	}

	std::string GetUniversityName() const
	{
		return m_universityName;
	}

	size_t GetStudentTicketNumber() const
	{
		return m_studentTicketNumber;
	}

private:
	std::string m_universityName;
	size_t m_studentTicketNumber;
};
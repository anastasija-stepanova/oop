#pragma once
#include "CStudentImpl.h"
#include "IStudent.h"


class CStudent : public CStudentImpl<IStudent>
{
public:
	CStudent(const std::string& name,
		const std::string& surname,
		const std::string& patronymic,
		const std::string& address,
		const std::string& universityName,
		size_t studentTicketNumber);
};
#include "stdafx.h"
#include "CStudent.h"


CStudent::CStudent(const std::string& name,
	const std::string& surname,
	const std::string& patronymic,
	const std::string& address,
	const std::string& universityName,
	size_t studentTicketNumber)
	: CStudentImpl<IStudent>(name, surname, patronymic, address, universityName, studentTicketNumber)
{
}
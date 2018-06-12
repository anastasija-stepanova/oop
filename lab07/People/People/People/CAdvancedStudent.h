#pragma once

#include "CStudentImpl.h"
#include "IAdvancedStudent.h"

class CAdvancedStudent : public CStudentImpl<IAdvancedStudent>
{
public:
	CAdvancedStudent(const std::string& name,
		const std::string& surname,
		const std::string& patronymic,
		const std::string& address,
		const std::string& universityName,
		size_t studentTicketNumber,
		std::string dissertationTopic);

	std::string GetDissertationThesis() const;
private:
	std::string m_dissertationThesis;
};
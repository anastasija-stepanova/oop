#pragma once
#include "CPersonImpl.h"
#include "IPupil.h"

class CPupil : public CPersonImpl<IPupil>
{
public:
	CPupil(const std::string& name,
		const std::string& surname,
		const std::string& patronymic,
		const std::string& address,
		const std::string & schoolName,
		const std::string & schoolClass);

	std::string GetSchoolName() const;
	std::string GetSchoolClass() const;
private:
	std::string m_schoolName;
	std::string m_schoolClass;
};
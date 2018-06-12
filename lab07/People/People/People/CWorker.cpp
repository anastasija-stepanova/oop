#include "stdafx.h"
#include "CWorker.h"
#include "CPersonImpl.h"

CWorker::CWorker(const std::string& name,
	const std::string& surname,
	const std::string& patronymic,
	const std::string& address,
	const std::string& specialty)
	: CPersonImpl<IWorker>(name, surname, patronymic, address)
	, m_specialty(specialty)
{
}

std::string CWorker::GetSpecialty() const
{
	return m_specialty;
}
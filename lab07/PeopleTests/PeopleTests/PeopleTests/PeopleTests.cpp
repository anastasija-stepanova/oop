#include "stdafx.h"
#include "../../../People/People/People/CAdvancedStudent.h"
#include "../../../People/People/People/CPupil.h"
#include "../../../People/People/People/CStudent.h"
#include "../../../People/People/People/CTeacher.h"
#include "../../../People/People/People/CWorker.h"

struct PupilFixture
{
	const std::string name = "Vasya";
	const std::string surname = "Pupkin";
	const std::string patronymic = "Pupkovich";
	const std::string address = "Arbat 28";
	const std::string schoolName = "Licey 1";
	const std::string schoolClass = "1D";
	CPupil pupil;
	PupilFixture()
		: pupil(name, surname, patronymic, address, schoolName, schoolClass)
	{
	}
};

BOOST_FIXTURE_TEST_SUITE(pupil, PupilFixture)

	BOOST_AUTO_TEST_CASE(can_get_pupil_name)
	{
		BOOST_CHECK_EQUAL(pupil.GetName(), name);
	}

	BOOST_AUTO_TEST_CASE(can_get_pupil_surname)
	{
		BOOST_CHECK_EQUAL(pupil.GetSurname(), surname);
	}

	BOOST_AUTO_TEST_CASE(can_get_pupil_patronymic)
	{
		BOOST_CHECK_EQUAL(pupil.GetPatronymic(), patronymic);
	}

	BOOST_AUTO_TEST_CASE(can_get_pupil_address)
	{
		BOOST_CHECK_EQUAL(pupil.GetAddress(), address);
	}

	BOOST_AUTO_TEST_CASE(can_get_pupil_school_name)
	{
		BOOST_CHECK_EQUAL(pupil.GetSchoolName(), schoolName);
	}

	BOOST_AUTO_TEST_CASE(can_get_pupil_school_class)
	{
		BOOST_CHECK_EQUAL(pupil.GetSchoolClass(), schoolClass);
	}

BOOST_AUTO_TEST_SUITE_END()

struct TeacherFixture
{
	const std::string name = "Petr";
	const std::string surname = "Petrov";
	const std::string patronymic = "Petrovich";
	const std::string address = "Petrova 1";
	const std::string subjectName = "English";
	CTeacher teacher;
	TeacherFixture()
		: teacher(name, surname, patronymic, address, subjectName)
	{
	}
};

BOOST_FIXTURE_TEST_SUITE(teacher, TeacherFixture)

	BOOST_AUTO_TEST_CASE(can_get_teacher_name)
	{
		BOOST_CHECK_EQUAL(teacher.GetName(), name);
	}

	BOOST_AUTO_TEST_CASE(can_get_teacher_surname)
	{
		BOOST_CHECK_EQUAL(teacher.GetSurname(), surname);
	}

	BOOST_AUTO_TEST_CASE(can_get_teacher_patronymic)
	{
		BOOST_CHECK_EQUAL(teacher.GetPatronymic(), patronymic);
	}

	BOOST_AUTO_TEST_CASE(can_get_teacher_address)
	{
		BOOST_CHECK_EQUAL(teacher.GetAddress(), address);
	}

	BOOST_AUTO_TEST_CASE(can_get_teacher_subject_name)
	{
		BOOST_CHECK_EQUAL(teacher.GetSubjectName(), subjectName);
	}

BOOST_AUTO_TEST_SUITE_END()

struct AdvancedStudentFixture
{
	const std::string name = "Vasya";
	const std::string surname = "Pupkin";
	const std::string patronymic = "Pupkovich";
	const std::string address = "Arbat 28";
	const std::string universityName = "PGTU";
	const size_t studentTicketNumber = 1112224444;
	const std::string dissertationThesis = "Neuronet";
	CAdvancedStudent advancedStudent;
	AdvancedStudentFixture()
		: advancedStudent(name, surname, patronymic, address, universityName, studentTicketNumber, dissertationThesis)
	{
	}
};

BOOST_FIXTURE_TEST_SUITE(advanced_student, AdvancedStudentFixture)

	BOOST_AUTO_TEST_CASE(can_get_advanced_student_name)
	{
		BOOST_CHECK_EQUAL(advancedStudent.GetName(), name);
	}

	BOOST_AUTO_TEST_CASE(can_get_advanced_student_surname)
	{
		BOOST_CHECK_EQUAL(advancedStudent.GetSurname(), surname);
	}

	BOOST_AUTO_TEST_CASE(can_get_advanced_student_patronymic)
	{
		BOOST_CHECK_EQUAL(advancedStudent.GetPatronymic(), patronymic);
	}

	BOOST_AUTO_TEST_CASE(can_get_advanced_student_address)
	{
		BOOST_CHECK_EQUAL(advancedStudent.GetAddress(), address);
	}

	BOOST_AUTO_TEST_CASE(can_get_advanced_student_university_name)
	{
		BOOST_CHECK_EQUAL(advancedStudent.GetUniversityName(), universityName);
	}

	BOOST_AUTO_TEST_CASE(can_get_advanced_student_ticket_number)
	{
		BOOST_CHECK_EQUAL(advancedStudent.GetStudentTicketNumber(), studentTicketNumber);
	}

	BOOST_AUTO_TEST_CASE(can_get_advanced_student_dissertation_thesis)
	{
		BOOST_CHECK_EQUAL(advancedStudent.GetDissertationThesis(), dissertationThesis);
	}

BOOST_AUTO_TEST_SUITE_END()

struct StudentFixture
{
	const std::string name = "Vasya";
	const std::string surname = "Pupkin";
	const std::string patronymic = "Pupkevich";
	const std::string address = "Arbat 28";
	const std::string universityName = "PGTU";
	const size_t studentTicketNumber = 1112224444;
	CStudent student;
	StudentFixture()
		: student(name, surname, patronymic, address, universityName, studentTicketNumber)
	{
	}
};

BOOST_FIXTURE_TEST_SUITE(student, StudentFixture)

	BOOST_AUTO_TEST_CASE(can_get_student_name)
	{
		BOOST_CHECK_EQUAL(student.GetName(), name);
	}

	BOOST_AUTO_TEST_CASE(can_get_student_surname)
	{
		BOOST_CHECK_EQUAL(student.GetSurname(), surname);
	}

	BOOST_AUTO_TEST_CASE(can_get_student_patronymic)
	{
		BOOST_CHECK_EQUAL(student.GetPatronymic(), patronymic);
	}

	BOOST_AUTO_TEST_CASE(can_get_student_address)
	{
		BOOST_CHECK_EQUAL(student.GetAddress(), address);
	}

	BOOST_AUTO_TEST_CASE(can_get_student_university_name)
	{
		BOOST_CHECK_EQUAL(student.GetUniversityName(), universityName);
	}

	BOOST_AUTO_TEST_CASE(can_get_student_ticket_number)
	{
		BOOST_CHECK_EQUAL(student.GetStudentTicketNumber(), studentTicketNumber);
	}

BOOST_AUTO_TEST_SUITE_END()

struct WorkerFixture
{
	const std::string name = "Vasya";
	const std::string surname = "Pupkin";
	const std::string patronymic = "Pupkevich";
	const std::string address = "Arbat 28";
	const std::string specialty = "Programmer";
	CWorker worker;
	WorkerFixture()
		: worker(name, surname, patronymic, address, specialty)
	{
	}
};

BOOST_FIXTURE_TEST_SUITE(worker, WorkerFixture)

	BOOST_AUTO_TEST_CASE(can_get_worker_name)
	{
		BOOST_CHECK_EQUAL(worker.GetName(), name);
	}

	BOOST_AUTO_TEST_CASE(can_get_worker_surname)
	{
		BOOST_CHECK_EQUAL(worker.GetSurname(), surname);
	}

	BOOST_AUTO_TEST_CASE(can_get_worker_patronymic)
	{
		BOOST_CHECK_EQUAL(worker.GetPatronymic(), patronymic);
	}

	BOOST_AUTO_TEST_CASE(can_get_worker_address)
	{
		BOOST_CHECK_EQUAL(worker.GetAddress(), address);
	}

	BOOST_AUTO_TEST_CASE(can_get_worker_speciality)
	{
		BOOST_CHECK_EQUAL(worker.GetSpecialty(), specialty);
	}
BOOST_AUTO_TEST_SUITE_END()

#include "Subject.h"

Subject::Subject(int _year, string _semester, string _subject, string _professer, string _grade, float _result, int _credit)
	: year(_year), semester(_semester), subject(_subject), professer(_professer), grade(_grade), result(_result), credit(_credit)
{
}

int Subject::GetYear() const
{
	return year;
}

string Subject::GetSemester() const
{
	return semester;
}

string Subject::GetSubject() const
{
	return subject;
}

string Subject::GetProfesser() const
{
	return professer;
}

string Subject::GetGrade() const
{
	return grade;
}

float Subject::GetResult() const
{
	return result;
}

int Subject::GetCredit() const
{
	return credit;
}

void Subject::SetGrade(string _grade)
{
	grade = _grade;
}

void Subject::SetResult(float _result)
{
	result = _result;
}

void Subject::SetCredit(int _credit)
{
	credit = _credit;
}
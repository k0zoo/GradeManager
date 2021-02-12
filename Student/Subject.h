#pragma once

#include <iostream>
using namespace std;

class Subject
{
private:
	int year;			//연도
	string semester;	//학기	
	string subject;		//과목명
	string professer;	//교수
	string grade;		//등급	ex)A+
	float result;		//성적	ex)4.5
	int credit;			//학점	ex)3학점

public:
	Subject(int _year, string _semester, string _subject, 
		string _professer, string _grade, float _result, int _credit);

public:
	int GetYear() const;
	string GetSemester() const;
	string GetSubject() const;
	string GetProfesser() const;
	string GetGrade() const;
	float GetResult() const;
	int GetCredit() const;
	void SetGrade(string _grade);
	void SetResult(float _result);
	void SetCredit(int _credit);

};

class CompareByString
{
private:
	string str;

public:
	CompareByString(string _str) { str = _str; }

	bool operator()(Subject* subject)
	{
		if (subject->GetSubject() == str)
			return true;
		else
			return false;
	}
};


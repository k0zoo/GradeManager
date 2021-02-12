#pragma once

#include <iostream>
using namespace std;

class Subject
{
private:
	int year;			//����
	string semester;	//�б�	
	string subject;		//�����
	string professer;	//����
	string grade;		//���	ex)A+
	float result;		//����	ex)4.5
	int credit;			//����	ex)3����

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


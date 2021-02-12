#pragma once

#include <iostream>
using namespace std;

class Stu
{
private:
	string id;		//아이디
	string pw;		//비밀번호
	string name;	//이름
	string major;	//학과
	const int stunumber;	//학번

public:
	Stu(string _id, string _pw, string _name, string _major, int _stunumber);

public:
	string GetId() const;
	string GetPw() const;
	string GetName() const;
	string GetMajor() const;
	int GetStuNumber() const;
	//void SetPw(string _pw);
	void SetMajor(string _major);
};

class CompareByStr
{
private:
	string str;

public:
	CompareByStr(string _str) { str = _str; }

	bool operator()(Stu* stu)
	{
		if (stu->GetId() == str)
			return true;
		else
			return false;
	}
};


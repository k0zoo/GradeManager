#include "Stu.h"

Stu::Stu(string _id, string _pw, string _name, string _major, int _stunumber)
	: id(_id), pw(_pw), name(_name), major(_major), stunumber(_stunumber)
{
}

string Stu::GetId() const
{
	return id;
}

string Stu::GetPw() const
{
	return pw;
}

string Stu::GetName() const
{
	return name;
}

string Stu::GetMajor() const
{
	return major;
}

int Stu::GetStuNumber() const
{
	return stunumber;
}

//void Stu::SetPw(string _pw);

void Stu::SetMajor(string _major)
{
	major = _major;
}

#include "StuManager.h"
#include "App.h"
#include "wbglobal.h"

StuManager::StuManager(App* pApp)
{
	app = pApp;
}

StuManager::~StuManager()
{
	vector<Stu*>::iterator begin = base.begin();
	vector<Stu*>::iterator end = base.end();

	for (; begin != end; begin++)
	{
		Stu* pstu = *begin;
		delete pstu;
	}

	delete app;
}

void StuManager::StuLogin()
{
	try
	{
		string id = wbglobal::getstr("ID");

		CompareByStr cbs(id);
		vector<Stu*>::iterator seek = find_if(base.begin(), base.end(), cbs);
		if (seek == base.end())
			throw "존재하는 ID가 없습니다. 다시 입력해주세요.";

		string pw = wbglobal::getstr("PASSWORD");

		Stu* student = *seek;

		if (student->GetPw() != pw)
			throw "비밀번호가 틀렸습니다. 다시 입력해주세요.";
		
		cout << student->GetName() << "님 환영합니다." << endl;
		app->Run_2();
	}
	catch (const char* msg)
	{
		cout << "[에러] " << msg << endl;
	}
}

void StuManager::StuInsert()
{
	try
	{
		string id = wbglobal::getstr("ID");

		for (int i = 0; i < (int)base.size(); i++)
		{
			Stu* stu = base[i];
			if (stu->GetId() == id)
				throw "이미 존재하는 ID입니다.";
		}

		string pw = wbglobal::getstr("PASSWORD");

		string name = wbglobal::getstr("이름을 입력하세요");
		string major = wbglobal::getstr("학과를 입력하세요");
		int stunumber = wbglobal::getnum("학번을 입력하세요");

		for (int i = 0; i < (int)base.size(); i++)
		{
			Stu* stu = base[i];
			if (stu->GetStuNumber() == stunumber)
				throw "해당 학번은 이미 존재합니다.";
		}

		Stu* newStu = new Stu(id, pw, name, major, stunumber);

		base.push_back(newStu);

		cout << "회원가입이 완료되었습니다! 로그인하여 프로그램을 이용해보세요!" << endl;
	}
	catch (const char* msg)
	{
		cout << "[에러] " << msg << endl;
	}
}


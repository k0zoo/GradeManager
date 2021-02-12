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
			throw "�����ϴ� ID�� �����ϴ�. �ٽ� �Է����ּ���.";

		string pw = wbglobal::getstr("PASSWORD");

		Stu* student = *seek;

		if (student->GetPw() != pw)
			throw "��й�ȣ�� Ʋ�Ƚ��ϴ�. �ٽ� �Է����ּ���.";
		
		cout << student->GetName() << "�� ȯ���մϴ�." << endl;
		app->Run_2();
	}
	catch (const char* msg)
	{
		cout << "[����] " << msg << endl;
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
				throw "�̹� �����ϴ� ID�Դϴ�.";
		}

		string pw = wbglobal::getstr("PASSWORD");

		string name = wbglobal::getstr("�̸��� �Է��ϼ���");
		string major = wbglobal::getstr("�а��� �Է��ϼ���");
		int stunumber = wbglobal::getnum("�й��� �Է��ϼ���");

		for (int i = 0; i < (int)base.size(); i++)
		{
			Stu* stu = base[i];
			if (stu->GetStuNumber() == stunumber)
				throw "�ش� �й��� �̹� �����մϴ�.";
		}

		Stu* newStu = new Stu(id, pw, name, major, stunumber);

		base.push_back(newStu);

		cout << "ȸ�������� �Ϸ�Ǿ����ϴ�! �α����Ͽ� ���α׷��� �̿��غ�����!" << endl;
	}
	catch (const char* msg)
	{
		cout << "[����] " << msg << endl;
	}
}


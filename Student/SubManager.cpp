#include <iostream>
using namespace std;

#include "SubManager.h"
#include "wbglobal.h"

SubManager::SubManager()
{
}

SubManager::~SubManager()
{
	for (int i = 0; i < (int)base.size(); i++)
	{
		Subject* psub = base[i];

		delete psub;
	}
}

void SubManager::SubPrintAll()		//���� ��� ���
{
	cout << "[��ȣ]\t[����]\t[�б�]\t\t[�����]\t\t[����]\t[���]\t[����]\t[����]" << endl;

	for (int i = 0; i < (int)base.size(); i++)
	{		
		Subject* psub = base[i];
		if (psub != NULL)
			cout << "  [" << i << "] " << "\t " << psub->GetYear()<< " \t  " << psub->GetSemester() << "\t\t" << psub->GetSubject() << "\t\t" 
			<< psub->GetProfesser() << " \t" << psub->GetGrade() << " \t" << psub->GetResult() << " \t" << psub->GetCredit() << endl;
	}

	int allcredit = 0, pcredit = 0;
	float mulvalue = 0, average = 0;

	for (int i = 0; i < (int)base.size(); i++)
	{
		Subject* sub = base[i];
		if (sub != NULL)
		{
			allcredit += sub->GetCredit();
			mulvalue += sub->GetResult() * sub->GetCredit();
			if (sub->GetGrade() == "F" || sub->GetGrade() == "NP")
				allcredit -= sub->GetCredit();
			if (sub->GetGrade() == "P")
			{
				allcredit -= sub->GetCredit();
				pcredit += sub->GetCredit();
			}
		}
	}
	average = mulvalue / allcredit;
	cout << "\n";
	cout << "\n";
	cout << "[�̼� ����] " << allcredit + pcredit << "\t[��� ����] " << average << endl;
}

void SubManager::SubInsert()		//���� �߰�
{
	try
	{
		cout << "***** ����� P/NP�� ������ ������ 0���� �Է����ּ��� *****" << endl;
		int year = wbglobal::getnum("������ �Է��ϼ���");
		string semester = wbglobal::getstr("�б⸦ �Է��ϼ���");
		string subject = wbglobal::getstr("������� �Է��ϼ���");

		for (int i = 0; i < (int)base.size(); i++)
		{
			Subject* psub = base[i];
			if (psub->GetSubject() == subject)
				throw "�̹� �����ϴ� �����Դϴ�.";
		}

		string professer = wbglobal::getstr("�������� �Է��ϼ���");
		string grade = wbglobal::getstr("����� �Է��ϼ���");
		float result = wbglobal::getfloat("������ �Է��ϼ���");
		int credit = wbglobal::getnum("������ �Է��ϼ���");

		Subject* newSub = new Subject(year, semester, subject, professer, grade, result, credit);

		base.push_back(newSub);
	}
	catch (const char* msg)
	{
		cout << "[����] " << msg << endl;
	}
}

void SubManager::SubDelete()    	//���� ����
{
	try
	{
		string subject = wbglobal::getstr("������ ������� �Է��ϼ���");

		CompareByString sbs(subject);
		vector<Subject*>::iterator seek = find_if(base.begin(), base.end(), sbs);
		if (seek == base.end())
			throw "�ش� ������ �������� �ʽ��ϴ�.";

		Subject* psub = *seek;
		delete psub;
		base.erase(seek);

		cout << "�����Ǿ����ϴ�" << endl;
	}
	catch (const char* msg)
	{
		cout << "[����] " << msg << endl;
	}
}

void SubManager::SubUpdate()		//���� ����
{
	try
	{
		// 1. ���� �Է�
		string subject = wbglobal::getstr("�˻��� ������� �Է��ϼ���");

		string up_grade = wbglobal::getstr("������ ����� �Է��ϼ���");
		float up_result = wbglobal::getfloat("������ ������ �Է��ϼ���");
		int up_credit = wbglobal::getnum("������ ������ �Է��ϼ���");


		//2. ����
		CompareByString sbs(subject);
		vector<Subject*>::iterator seek = find_if(base.begin(), base.end(), sbs);
		if (seek == base.end())
			throw "�ش� ������ �������� �ʽ��ϴ�.";

		Subject* psub = *seek;
		psub->SetGrade(up_grade);
		psub->SetResult(up_result);
		psub->SetCredit(up_credit);

		//3. ������
		cout << "���, ����, ������ �����Ǿ����ϴ�." << endl;
	}
	catch (const char* msg)
	{
		cout << "[����] " << msg << endl;
	}
}
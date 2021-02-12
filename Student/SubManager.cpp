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

void SubManager::SubPrintAll()		//과목 모두 출력
{
	cout << "[번호]\t[연도]\t[학기]\t\t[과목명]\t\t[교수]\t[등급]\t[성적]\t[학점]" << endl;

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
	cout << "[이수 학점] " << allcredit + pcredit << "\t[평균 성적] " << average << endl;
}

void SubManager::SubInsert()		//과목 추가
{
	try
	{
		cout << "***** 등급이 P/NP인 과목은 성적을 0으로 입력해주세요 *****" << endl;
		int year = wbglobal::getnum("연도를 입력하세요");
		string semester = wbglobal::getstr("학기를 입력하세요");
		string subject = wbglobal::getstr("과목명을 입력하세요");

		for (int i = 0; i < (int)base.size(); i++)
		{
			Subject* psub = base[i];
			if (psub->GetSubject() == subject)
				throw "이미 존재하는 과목입니다.";
		}

		string professer = wbglobal::getstr("교수명을 입력하세요");
		string grade = wbglobal::getstr("등급을 입력하세요");
		float result = wbglobal::getfloat("성적을 입력하세요");
		int credit = wbglobal::getnum("학점을 입력하세요");

		Subject* newSub = new Subject(year, semester, subject, professer, grade, result, credit);

		base.push_back(newSub);
	}
	catch (const char* msg)
	{
		cout << "[에러] " << msg << endl;
	}
}

void SubManager::SubDelete()    	//과목 삭제
{
	try
	{
		string subject = wbglobal::getstr("삭제할 과목명을 입력하세요");

		CompareByString sbs(subject);
		vector<Subject*>::iterator seek = find_if(base.begin(), base.end(), sbs);
		if (seek == base.end())
			throw "해당 과목은 존재하지 않습니다.";

		Subject* psub = *seek;
		delete psub;
		base.erase(seek);

		cout << "삭제되었습니다" << endl;
	}
	catch (const char* msg)
	{
		cout << "[에러] " << msg << endl;
	}
}

void SubManager::SubUpdate()		//과목 수정
{
	try
	{
		// 1. 정보 입력
		string subject = wbglobal::getstr("검색할 과목명을 입력하세요");

		string up_grade = wbglobal::getstr("수정할 등급을 입력하세요");
		float up_result = wbglobal::getfloat("수정할 성적을 입력하세요");
		int up_credit = wbglobal::getnum("수정할 학점을 입력하세요");


		//2. 연산
		CompareByString sbs(subject);
		vector<Subject*>::iterator seek = find_if(base.begin(), base.end(), sbs);
		if (seek == base.end())
			throw "해당 과목은 존재하지 않습니다.";

		Subject* psub = *seek;
		psub->SetGrade(up_grade);
		psub->SetResult(up_result);
		psub->SetCredit(up_credit);

		//3. 결과출력
		cout << "등급, 성적, 학점이 수정되었습니다." << endl;
	}
	catch (const char* msg)
	{
		cout << "[에러] " << msg << endl;
	}
}
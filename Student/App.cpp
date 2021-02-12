#include <iostream>
using namespace std;
#include <conio.h>
#include "App.h"
#include "wbglobal.h"

App::App()
{
	Init();
	pstu = new StuManager(this);
	psub = new SubManager;
}

App::~App()
{
	Exit();
	delete pstu;
	delete psub;
}

void App::Init()
{
	Logo();
}

void App::Run_1()
{
	while (true)
	{
		wbglobal::clrscr();

		char retval = Menuprint_1();

		switch (retval)
		{
		case '1': pstu->StuLogin();					break;
		case '2': pstu->StuInsert();				break;
		case '3': cout << "프로그램 종료" << endl;	return;
		}
		wbglobal::pause();
	}
}

void App::Run_2()
{
	while (true)
	{
		wbglobal::clrscr();

		char retval = Menuprint_2();

		switch (retval)
		{
		case '1': psub->SubPrintAll();				break;
		case '2': psub->SubInsert();				break;
		case '3': psub->SubDelete();				break;
		case '4': psub->SubUpdate();				break;
		case '5': cout << "프로그램 종료" << endl;	return;
		}
		wbglobal::pause();
	}
}

void App::Exit()
{
	Ending();
}

void App::Logo()
{
	wbglobal::clrscr();
	cout << "=====================================================" << endl;
	cout << "                                                     " << endl;
	cout << "              대학교 학점 관리 프로그램              " << endl;
	cout << "                                                     " << endl;
	cout << "                                                     " << endl;
	cout << "                                                     " << endl;
	cout << "                   프로그램 시작                     " << endl;
	cout << "                                                     " << endl;
	cout << "=====================================================" << endl;
	wbglobal::pause();
}

void App::Ending()
{
	wbglobal::clrscr();
	cout << "=====================================================" << endl;
	cout << "                                                     " << endl;
	cout << "              대학교 학점 관리 프로그램              " << endl;
	cout << "                                                     " << endl;
	cout << "                                                     " << endl;
	cout << "                                                     " << endl;
	cout << "                   프로그램 종료                     " << endl;
	cout << "                                                     " << endl;
	cout << "=====================================================" << endl;
	wbglobal::pause();
}

char App::Menuprint_1()
{
	wbglobal::clrscr();
	cout << "====================== M E N U ======================" << endl;
	cout << "                                                     " << endl;
	cout << "                      1. 로그인                      " << endl;
	cout << "                     2. 회원가입                     " << endl;
	cout << "                  3. 프로그램 종료                   " << endl;
	cout << "                                                     " << endl;
	cout << "=====================================================" << endl;

	return _getch();
	wbglobal::pause();
}

char App::Menuprint_2()
{
	wbglobal::clrscr();
	cout << "====================== M E N U ======================" << endl;
	cout << "                                                     " << endl;
	cout << "                  1. 전체 성적 확인                  " << endl;
	cout << "                    2. 성적 입력                     " << endl;
	cout << "                    3. 성적 삭제                     " << endl;
	cout << "                    4. 성적 수정                     " << endl;
	cout << "                  5. 프로그램 종료                   " << endl;
	cout << "                                                     " << endl;
	cout << "=====================================================" << endl;

	return _getch();
	wbglobal::pause();
}
#pragma once

#include <iostream>
using namespace std;

class wbglobal
{
private:
	wbglobal() {}		//객체 생성 불가.
	~wbglobal() {}
public:
	static void clrscr();					//화면 지우기
	static void pause();					//잠시 멈추기
	static int getnum(const char* msg);		//수를 입력받는 메서드
	static string getstr(const char* msg);	//문자열을 입력받는 메서드
	static float getfloat(const char* msg);	//실수 입력받는 메서드
};


#pragma once

#include <iostream>
using namespace std;

class wbglobal
{
private:
	wbglobal() {}		//��ü ���� �Ұ�.
	~wbglobal() {}
public:
	static void clrscr();					//ȭ�� �����
	static void pause();					//��� ���߱�
	static int getnum(const char* msg);		//���� �Է¹޴� �޼���
	static string getstr(const char* msg);	//���ڿ��� �Է¹޴� �޼���
	static float getfloat(const char* msg);	//�Ǽ� �Է¹޴� �޼���
};


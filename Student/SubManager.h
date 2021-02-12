#pragma once

#include <iostream>
using namespace std;
#include <vector>
using std::vector;

#include "Subject.h"

class SubManager
{
private:
	vector<Subject*> base;	//�������

public:
	SubManager();
	~SubManager();

public:
	void SubPrintAll();		//���� ��� ���
	void SubInsert();		//���� �߰�
	void SubDelete();		//���� ����
	void SubUpdate();		//���� ����

};


#pragma once

#include <iostream>
#include <vector>
using namespace std;
#include "Stu.h"
#include "App.h"

class StuManager
{
	class App* app;

private:
	vector<Stu*> base;	//�������

public:
	StuManager(App* pApp);
	~StuManager();

public:
	void StuLogin();	//�α���
	void StuInsert();	//�����߰�(ȸ������)
};


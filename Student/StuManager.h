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
	vector<Stu*> base;	//저장공간

public:
	StuManager(App* pApp);
	~StuManager();

public:
	void StuLogin();	//로그인
	void StuInsert();	//계정추가(회원가입)
};


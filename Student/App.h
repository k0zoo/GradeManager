#pragma once

#include "StuManager.h"
#include "SubManager.h"
#include "wbglobal.h"

class App
{
	class StuManager* pstu;
	class SubManager* psub;

public:
	App();
	~App();

public:
	void Run_1();
	void Run_2();

private:
	void Init();	
	void Exit();	
	void Logo();
	void Ending();
	char Menuprint_1();
	char Menuprint_2();
};


#pragma once

#include <iostream>
using namespace std;
#include <vector>
using std::vector;

#include "Subject.h"

class SubManager
{
private:
	vector<Subject*> base;	//저장공간

public:
	SubManager();
	~SubManager();

public:
	void SubPrintAll();		//과목 모두 출력
	void SubInsert();		//과목 추가
	void SubDelete();		//과목 삭제
	void SubUpdate();		//과목 수정

};


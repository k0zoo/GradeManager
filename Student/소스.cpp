#include <iostream>
using namespace std;

#include "App.h"

int main()
{
	App* papp = new App;

	papp->Run_1();

	delete papp;

	return 0;
}
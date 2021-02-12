#include <conio.h>
#include "wbglobal.h"

void wbglobal::clrscr()
{
	system("cls");
}

void wbglobal::pause()
{
	system("pause");
}

int wbglobal::getnum(const char* msg)
{
	cout << msg << " : ";
	//방법1
//	int num;
//	cin >> num;							//scanf_s("%d", &num);
//	return num;							

	//방법2. 정수를 문자열 형태로 입력받아서 -> 정수로 변환 : 안전하다.
	int num;
	char buf[255 + 1];					// scanf_s("%s", &buf, sizeof(buf)-1);
	cin.getline(buf, sizeof(buf) - 1);	// gets_s(buf, size(buf)-1);
	cin.clear();						// 상태초기화
	sscanf_s(buf, "%d", &num);			// 문자열에 있는 정수를 &num저장:문자열->정수
	return num;
}

string wbglobal::getstr(const char* msg)
{
	cout << msg << " : ";
	char buf[255 + 1];
	cin.getline(buf, sizeof(buf) - 1);  // gets_s
	cin.clear();
	return buf;
}

float wbglobal::getfloat(const char* msg)
{
	cout << msg << " : ";
	float num;
	char buf[255 + 1];					// scanf_s("%s", buf, sizeof(buf)-1);
	cin.getline(buf, sizeof(buf) - 1);	// gets_s(buf, size(buf)-1);
	cin.clear();						// 상태초기화
	sscanf_s(buf, "%f", &num);			// 문자열에 있는 정수를 &num저장:문자열->정수
	return num;
}
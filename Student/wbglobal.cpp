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
	//���1
//	int num;
//	cin >> num;							//scanf_s("%d", &num);
//	return num;							

	//���2. ������ ���ڿ� ���·� �Է¹޾Ƽ� -> ������ ��ȯ : �����ϴ�.
	int num;
	char buf[255 + 1];					// scanf_s("%s", &buf, sizeof(buf)-1);
	cin.getline(buf, sizeof(buf) - 1);	// gets_s(buf, size(buf)-1);
	cin.clear();						// �����ʱ�ȭ
	sscanf_s(buf, "%d", &num);			// ���ڿ��� �ִ� ������ &num����:���ڿ�->����
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
	cin.clear();						// �����ʱ�ȭ
	sscanf_s(buf, "%f", &num);			// ���ڿ��� �ִ� ������ &num����:���ڿ�->����
	return num;
}
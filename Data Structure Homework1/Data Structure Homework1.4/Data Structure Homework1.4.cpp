// Data Structure Homework1.4.cpp: 定义控制台应用程序的入口点。
// Write by HXBer

#include"stdafx.h"
#include"iostream"
#include"cstdio"
using namespace std;
int main()
{
	int form[20];
	for (int i = 0; i<10; i++)
		form[i] = i + 1;
	for (int i = 0; i<10; i++)
	{
		int tmp = form[i];
		form[i] = form[9 - i];
		form[9 - i] = tmp;
	}
	for (int i = 0; i<10; i++)
		cout << form[i];
	system("pause");
	return 0;
}

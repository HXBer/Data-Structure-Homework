// Data Structure Homework1.1.cpp: 定义控制台应用程序的入口点。
//Write by HXBer

#include "stdafx.h"
#include"iostream"
#include"cstdio"
using namespace std;
int main()
{
	int form[20];
	for (int i = 0; i<10; i++)
		form[i] = i + 1;
	for (int i = 9; i >= 0; i--)
		cout << form[i] << endl;
	return 0;
}

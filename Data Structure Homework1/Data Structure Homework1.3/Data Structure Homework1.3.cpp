// Data Structure Homework1.3.cpp: 定义控制台应用程序的入口点。
// Write by HXBer


#include "stdafx.h"
#include"iostream"
#include"cstdio"
using namespace std;
int main()
{
	struct student
	{
		int Number;
		char Name[10];
		double Mark[3];
		double Average;
	}student[10];
	for (int i = 0; i<5; i++)
	{
		cin >> student[i].Number;
		cin >> student[i].Name;
		cin >> student[i].Mark[0];
		cin >> student[i].Mark[1];
		cin >> student[i].Mark[2];
		student[i].Average = (student[i].Mark[0] + student[i].Mark[1] + student[i].Mark[2]) / 3;

	}
	for (int i = 0; i < 5; i++)
	{
		cout << student[i].Number << " ";
		cout << student[i].Name << " ";
		cout << student[i].Mark[0] << " ";
		cout << student[i].Mark[1] << " ";
		cout << student[i].Mark[2] << " ";
		cout << student[i].Average << endl;
	}
	system("pause");
	return 0;
}


// Data Structure Homework1.2.cpp: 定义控制台应用程序的入口点。
//Write by HXBer

#include "stdafx.h"
#include"iostream"
#include"cstdio"
using namespace std;
int  swap(int *a, int* b)

{
	int t;
	t = *a;
	*a = *b;
	*b = t;
	return 0;
}
int main()
{
	int form[20];
	int tmp1 = 0, tmp2 = 0, MAXN = 0, MINN = 1000;
	for (int i = 0; i<10; i++)
	{
		cin >> form[i];
		if (form[i]>MAXN)
		{
			MAXN = form[i];
			tmp1 = i;
		}
		if (form[i]<MINN)
		{
			MINN = form[i];
			tmp2 = i;
		}
	}
	swap(&form[0], &form[tmp1]);
	for (int i = 0; i<10; i++)
		cout << form[i] << " ";
	cout << endl;
	swap(&form[9], &form[tmp2]);
	for (int i = 0; i<10; i++)
		cout << form[i] << " ";
	return 0;
}



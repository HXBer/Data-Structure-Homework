// Data Structure Homework1.5.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"iostream"
#include"cstdio"
using namespace std;
int main()
{
	int form[20] = { 1,2,3,4,5,7,8,9,10 };
	int n;
	cin >> n;
	for (int i = 0; i < 10; i++)
	{
		if (n < form[i])
		{
			for (int j = 9; j >= i; j--)
			{
				int *tmp = &form[j];
				form[j + 1] = form[j];
			}
			form[i] = n;
			break;
		}
	}
	for (int i = 0; i < 10; i++)
		cout << form[i] << " ";
	system("pause");
}

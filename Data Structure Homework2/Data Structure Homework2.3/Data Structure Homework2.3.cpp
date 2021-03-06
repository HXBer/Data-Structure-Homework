// Data Structure Homework2.3.cpp: 定义控制台应用程序的入口点。
// Write by HXBer

#include "stdafx.h"
#include "iostream"
#include "cstdio"
#include "conio.h"
#include "stdlib.h" 
# define LIST_INIT_SIZE   10
# define LISTINCREMENT   5
typedef  struct {
	int *elem;
	int length;
	int ListSize;
} sqlist;

int TestListSize(sqlist *str)
{
	if (str->length >= str->ListSize)
	{
		int *newbase = (int *)realloc(str->elem, (str->ListSize + LISTINCREMENT) * sizeof(int));
		if (!*newbase)
		{
			std::cout << "Uable to allocate the required memory!\n";
			return 0;
		}
		else
		{
			str->elem = newbase;
			str->ListSize++;
		}
	}
	return 1;
}

int InitList(sqlist *str)  /*initial the list l*/
{
	str->elem = (int *)malloc(LIST_INIT_SIZE * sizeof(int));
	if (!str->elem)
	{
		std::cout << "Unable to allocate the required memory！\n";
		return 1;
	}
	else
	{
		str->length = 0;
		str->ListSize = LIST_INIT_SIZE;
		std::cout << "OK\n";
		return 0;
	}
}
int CheckInDuplicate(sqlist *str)
{
	for (int i = 0; i < str->length - 1; i++)
	{
		if (str->elem[i] == str->elem[i + 1])
		{
			//std::cout <<str->elem[i]<< "\nFuck"<< str->elem[i + 1];
			for (int j = i; j < str->length - 1; j++)
			{
				str->elem[j] = str->elem[j + 1];
			}
			str->length--;
			i--;
		}
	}
	std::cout << "\nnoob\n\n";
	return 1;
}

int main()
{
	sqlist list, *l;
	l = &list;
	InitList(l);
	std::cout << "\nInput your number\n";
	for (int i = 0;; i++)
	{
		std::cin >> l->elem[i];
		l->length++;
		if (l->length >= l->ListSize) TestListSize(l);
		if (getchar() == '\n')break;
	}
	//std::cout << l->length << std::endl << l->ListSize;
	CheckInDuplicate(l);
	for (int i = 0; i < l->length; i++)
		std::cout << l->elem[i] << " ";
	system("pause");
	return 0;
}
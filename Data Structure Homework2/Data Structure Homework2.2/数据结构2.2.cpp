// 数据结构2.2.cpp: 定义控制台应用程序的入口点。
//

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

int InsertList(sqlist *str, int where, int number)
{
	if (where < 1 || where > str->length + 1)
		return 0;
	TestListSize(str);
	for (int i = str->length + 1; i >= where; i--)
	{
		str->elem[i] = str->elem[i - 1];
	}
	str->length++;
	str->elem[where - 1] = number;
	return 1;
}
int DeleteList(sqlist *str, int where)
{
	if (where < 1 || where > str->length)
	{
		std::cout << "Out of the memory";
		return 0;
	}
	/*
	for(int i = where-1; i <str->length-1 ;i++)
	{
	str->elem[i]=str->elem[i+1];
	}*/
	//***************
	int *l = &str->elem[where - 1];
	int *r = &str->elem[str->length - 1];
	for (; l < r; l++)
		*l = *(l + 1);
	//***************
	str->length--;
	return 1;
}
int SearchList(sqlist *str, int number)
{
	for (int i = 0; i<str->length; i++)
	{
		if (str->elem[i] == number)
		{
			std::cout << "\nFind it! It's" << i + 1 << "th\n";
			return 1;
		}
	}
	std::cout << "\nI can't find it\n";
	return 0;
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
	std::cout << "\nInput 1 for Insert , Input 2 for Delete , Input 3 for Search\n";
	char ch;
	do
	{
		ch = _getch();
		if (ch == '1')
		{
			int where, number;
			std::cout << "\nWhere to input?\n";
			std::cin >> where;
			std::cout << "\nWhich number to input?\n";
			std::cin >> number;
			if (InsertList(l, where, number))std::cout << "\nnoob\n\n";
			for (int i = 0; i < l->length; i++)
				std::cout << l->elem[i] << " ";
			break;
		}
		else if (ch == '2')
		{
			int where;
			std::cout << "\nWhere to delete?\n";
			std::cin >> where;
			if (DeleteList(l, where))std::cout << "\nnoob\n\n";
			for (int i = 0; i < l->length; i++)
				std::cout << l->elem[i] << " ";
			break;
		}
		else if (ch == '3')
		{
			int number;
			std::cout << "\nWhich number need to search?\n";
			std::cin >> number;
			if (SearchList(l, number))std::cout << "\nnoob\n";
			break;
		}
	} while (ch != '1' || ch != '2' || ch != '3');
	system("pause");
	return 0;
}
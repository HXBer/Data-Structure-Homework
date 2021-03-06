// Data Structure Homework2.1.cpp: 定义控制台应用程序的入口点。
// Write by HXBer

#include "stdafx.h"
#include "iostream"
#include "cstdio"
# define LIST_INIT_SIZE   10
# define LISTINCREMENT   5
typedef  struct {
	int *elem;
	int length;
	int ListSize;
} sqlist;

int InitList_sq(sqlist *l)  /*initial the list l*/
{
	l->elem = (int *)malloc(LIST_INIT_SIZE * sizeof(int));
	if (!l->elem)
	{
		std::cout << "无法分配空间！\n";
		return 1;
	}
	else
	{
		l->length = 0;
		l->ListSize = LIST_INIT_SIZE;
		std::cout << "OK\n";
		return 0;
	}
}
void Alternate(sqlist *A, sqlist *B)
{
	sqlist list, *C;
	C = &list;
	InitList_sq(C);
	C->length = A->length + B->length;
	for (int i = 0; i < 5; i++)
	{
		C->elem[2 * i] = A->elem[i];
		C->elem[2 * i + 1] = B->elem[i];
	}
	std::cout << "\n";
	for (int i = 0; i < C->length; i++)
	{
		std::cout << C->elem[i] << " ";
	}
	std::cout << "\nDone!\n";
}
void main()
{
	sqlist list1, list2, *A, *B;
	A = &list1;
	B = &list2;
	InitList_sq(A);
	InitList_sq(B);
	A->length = 5;
	B->length = 5;
	for (int i = 0; i < 5; i++)
		std::cin >> A->elem[i];
	for (int i = 0; i < 5; i++)
		std::cin >> B->elem[i];
	Alternate(A, B);

	system("pause");
}

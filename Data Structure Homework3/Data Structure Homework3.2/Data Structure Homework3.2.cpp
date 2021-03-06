// Data Structure Homework3.2.cpp: 定义控制台应用程序的入口点。
//Write by HXBer

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "iostream"
#include "windows.h"
#include "conio.h"
bool ok = true;
typedef struct Node {
	int data;
	struct Node * next;
}Node;
typedef struct Node* LinkList;

int InitList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
	if (!*L)return 0;
	return 1;
}

int CreateListPlus(LinkList *L, int n) {
	LinkList p, temp;
	temp = (*L);
	int tmp=0;
	for (int i = 0; i < n; i++)
	{
		int number;
		std::cin >> number;
		if (number < tmp)continue;
		tmp = number;
		p = (LinkList)malloc(sizeof(Node));
		p->data = number;
		//std::cout << "Node[" << i + 1 << "]=" << p->data << std::endl;
		p->next = NULL;
		temp->next = p;
		temp = p;
	}
	printf("\nNon-Decreasing linked list created successful!\n\n");		//Non - Decreasing非递减序列
	return 1;
}

int PrintList(LinkList *L) {
	LinkList p;
	int i = 0;
	p = (*L)->next;//p指向第一个节点；
	printf("\n\n-----------Printing Linkedlist-----------\n\n");
	if (p == NULL)
	{
		std::cout << "This is a empty linkedlist!\n";
		return 0;
	}
	while (p)
	{
		std::cout << p->data << std::endl;
		p = p->next;
	}
	return 1;
}

int LocalList(LinkList *L, int number)
{
	LinkList p;
	int local = 1;
	p = (*L)->next;
	if (!p)
	{
		std::cout << "This is a emputy linkedlist!\n";
		return 0;
	}
	while (p->data != number)
	{
		local++;
		p = p->next;
	}
	if (!p) { std::cout << number << " doesn't in the linkedlist!"; return 0; }
	std::cout << "\nThe number " << number << " is on the " << local << " th.\n";
	return 1;
}

int DeleteListPlus(LinkList *L, int number)
{
	LinkList p, tmp;
	p = (*L)->next;
	if (!p)
	{
		std::cout << "This is a emputy linkedlist!\n";
		return 0;
	}
	while (p->next->next->data != number)
	{
		p = p->next;
	}
	tmp = p->next;
	p->next = p->next->next;
	free(tmp);
	return 1;
}

int DeleteAllList(LinkList *L)
{
	LinkList tmp, p;
	p = (*L)->next;
	if (!p)
	{
		std::cout << "This is a emputy linkedlist!\n";
		return 0;
	}
	while (p)
	{
		tmp = p;
		p = p->next;
		free(tmp);
	}
	std::cout << "Done!\n";
	return 1;
}

int DeleteRepea(LinkList *L)
{
	LinkList p, tmp;
	p = (*L)->next;
	if (!p)
	{
		std::cout << "This is a emputy linkedlist!\n";
		return 0;
	}
	while (p->next)
	{
		if (p->next->data == p->data)
		{
			tmp = p->next;
			p->next = p->next->next;
			free(tmp);
		}
		p = p->next;
	}
	
	return 1;
}

int main()
{
	int n, number;
	LinkList list, *l;
	l = &list;
	if (InitList(l))std::cout << "Initialise successful!\n\n";					//Initialise 初始化
	else
	{
		std::cout << "Initialise failed!\n\n";
		return 0;
	}
	std::cout << "How many number do u want to input?\n";
	std::cin >> n;
	std::cout << "Input your numbers separated by a blank space\n";		//separated  隔开
	CreateListPlus(l, n);
	std::cout << "Use 1 to local the number of the linkLlist;\nUse 2 to delete one number of the linkedlist;\nUse 3 to delete all all number of the linkedlist\nUse 4 to deleteRepea\nUse 5 to do nothing\n\n";
	char ch;
	do
	{
		ch = _getch();
		if (ch == '1')
		{
			std::cout << "\nWhich number do u want to local\n";
			std::cin >> number;
			LocalList(l, number);
		}
		else if (ch == '2')
		{
			std::cout << "\nU want to delete the number before?\n";
			std::cin >> number;
			DeleteListPlus(l, number);
		}
		else if (ch == '3') { DeleteAllList(l); ok = 0; }
		else if (ch == '4')DeleteRepea(l);
		else if (ch == '5')ok = true;
	} while (ch != '1' && ch != '2' && ch != '3'&& ch != '4'&& ch != '5');
	if (ok)PrintList(l);
	system("pause");
}


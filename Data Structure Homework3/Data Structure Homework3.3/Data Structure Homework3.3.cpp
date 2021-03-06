// Data Structure Homework3.3.cpp: 定义控制台应用程序的入口点。
//Write by HXBer
//Josephus Circle problem

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

int CreateList(LinkList *L, int n) {
	LinkList p, temp; 
	temp = (*L);
	for (int i = 1; i <=n; i++)
	{
		p = (LinkList)malloc(sizeof(Node));
		p->data = i;
		std::cout << "Node[" << i << "]=" << p->data << std::endl;
		p->next = (*L)->next;
		temp->next = p;		//?
		temp = p;
		//std::cout << temp->next->data;
	}

	printf("\nLinked list created successful!\n\n");
	return 1;
}

int PrintList(LinkList *L) 
{
	//int test = 0;		//Circular linked list test
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
		//test++;      
		std::cout << p->data << std::endl;
		p = p->next;
	}
	return 1;
}

int main()
{
	int n, m;
	LinkList list, *l;
	l = &list;
	if (InitList(l))std::cout << "Initialise successful!\n\n";					//Initialise 初始化
	else
	{
		std::cout << "Initialise failed!\n\n";
		return 0;
	}
	std::cout << "Input n"<<std::endl;
	std::cin >> n;
	std::cout << "Input m" << std::endl;
	std::cin >> m;
	CreateList(l, n);
	LinkList p,tmp;
	p = list;
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m-1; j++)
		{
			p = p->next;					//?
		}
		std::cout <<"Delete "<< p->next->data<<" at "<<i<<"th."<<std::endl;
		tmp = p->next;
		p->next = p->next->next;
		free(tmp);
		std::cout << std::endl;
	}
	system("pause");
}


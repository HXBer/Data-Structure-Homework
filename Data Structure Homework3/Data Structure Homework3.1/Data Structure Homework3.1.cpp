// Data Structure Homework3.1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"stdio.h"
#include"stdlib.h"
typedef struct node          //定义结点
{
	int data;             //结点的数据域为整型
	struct node *next;      //结点的指针域
}ListNode;
typedef ListNode * LinkList;         // 自定义LinkList单链表类型
LinkList CreatListR1();              //函数，用尾插入法建立带头结点的单链表
ListNode *LocateNode(LinkList head, int key);              //函数，按值查找结点
void DeleteList(LinkList head, int key);                   //函数，删除指定值的结点
void printlist(LinkList head);                    //函数，打印链表中的所有值
void DeleteAll(LinkList head);                    //函数，删除所有结点，释放内存
												  //==========主函数==============
void main()
{
	int num;
	char ch;
	LinkList head;
	head = CreatListR1();          //用尾插入法建立单链表，返回头指针
	printlist(head);             //遍历链表输出其值
	printf(" Delete node (y/n):");  //输入"y"或"n"去选择是否删除结点
	scanf("%c", &ch);
	if (ch == ’y’) || ch == ’Y’){
	printf("Please input Delete_data:");
	scanf("%d", num);	        //输入要删除的字符串
	DeleteList(head, num);
	printlist(head);
  }
  DeleteAll(head);            //删除所有结点，释放内存
}
//==========用尾插入法建立带头结点的单链表===========
LinkList CreatListR1(void)
{
	……
		return head;        //返回头指针
}
//==========按值查找结点，找到则返回该结点的位置，否则返回NULL==========
ListNode *LocateNode(LinkList head, int key)
{
	……
		return p;    //若p=NULL则查找失败，否则p指向找到的值为key的结点
}
//==========删除带头结点的单链表中的指定结点=======
void DeleteList(LinkList head, int key)
{

	//按key值查找结点的
	//若没有找到结点，退出
	//若找到，则从单链表中删除该结点，并释放结点
	……

}
//===========打印链表,输出所有结点的值=======
void printlist(LinkList head)
{
	……
}
//==========删除所有结点，释放空间===========
void DeleteAll(LinkList head)
{
	……
}

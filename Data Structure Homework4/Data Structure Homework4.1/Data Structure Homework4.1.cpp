// Data Structure Homework4.1.cpp 
// Write by HXBer

#include "iostream"
#define MaxSize 100
using namespace std;
typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int top;
}SqStack;

void InitStack(SqStack *st) //初始化栈
{
	st->top = -1;
}

int StackEmpty(SqStack *st) //判断栈为空
{
	return (st->top == -1);
}

void Push(SqStack *st, ElemType x) //元素进栈
{
	if (st->top == MaxSize - 1)
	{
		printf("栈上溢出!\n");
	}
	else
	{
		st->top++;           //移动栈顶位置
		st->data[st->top] = x; //元素进栈
	}
}

void Pop(SqStack *st, ElemType *e) //出栈
{
	if (st->top == -1)
	{
		printf("栈下溢出\n");
	}
	else
	{
		*e = st->data[st->top]; //元素出栈
		st->top--;           //移动栈顶位置		
	}
}

int main()
{
	SqStack L;
	SqStack *st = &L;
	ElemType e;
	int i;
	InitStack(st);
	while (1)
	{
		char ch = getchar();
		if (ch == '\n')break;
		if (ch == '[' &&ch == '(')
		{
			Push(st, ch);
		}
		else if (ch == ')')
		{
			if (L.top != '(')
			{
				std::cout << "Doesn't match!";
				return 0;
			}
			else
			{
				Pop(st, &L.top);
			}
		}
		else if (ch == ']')
		{
			if (L.top != '[')
			{
				std::cout << "Doesn't match!";
				return 0;
			}
			else
			{
				Pop(st, &L.top);
			}
		}
	}
	std::cout << "Match!";
	return 0;
}

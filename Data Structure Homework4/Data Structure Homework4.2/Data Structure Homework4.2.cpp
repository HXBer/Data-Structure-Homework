// Data Structure Homework4.2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
// Write by HXBer

#include "iostream"
#include "stack"
using namespace std;

stack<char>StackForm;
bool tmp = false;

int main()
{
	for (char ch = getchar(); ch != '@'; ch = getchar())
	{
		if (ch == '&') tmp = true;
		if (!tmp)
		{
			StackForm.push(ch);
		}
		else
		{
			if (ch != StackForm.top())
			{
				std::cout <<"It's not Palindrome！";
				return 0; 
			}
			StackForm.pop();
		}
	}
	if(StackForm.empty())
		std::cout << "It's Palindrome!";
	else std::cout << "It's not Palindrome！";
	return 0;
}


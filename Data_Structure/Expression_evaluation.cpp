//四则运算，不包含括号。
//Author:Qingqing Guo, sunnyguoqq@outlook.com

#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
#define OK 1
#define ERROR 0
#define MAXSIZE 100
typedef int Status;

typedef struct
{
	int *base;
	int *top;
	int stacksize;
}SqStack;

/*初始化*/
Status InitStack(SqStack &S)
{
	S.base = new int[MAXSIZE];
	if (!S.base)
		exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}

/*入栈*/
Status Push(SqStack &S, int e)
{
	if (S.top - S.base == S.stacksize)
		return ERROR;
	*S.top++= e;
	return OK;
}

/*出栈*/
Status Pop1(SqStack &S, int e)//数字
{
	if (S.top == S.base)
		return ERROR;
	e = *--S.top;
	return OK;
}
Status Pop2(SqStack &S, char e)//运算符
{
	if (S.top == S.base)
		return ERROR;
	e = *--S.top;
	return OK;
}

/*取栈顶元素*/
Status GetTop(SqStack S)
{
	if (S.top != S.base)
		return *(S.top - 1);
	return OK;
}

/*判断优先级*/
int isFirst(char ch)
{
	int temp;
	if (42 == (int)ch || 47 == (int)ch)
	{
		temp = 3;
		return temp;
	}
	else if (43 == (int)ch || 45 == (int)ch || 61 == (int)ch)//+、-
	{
		temp = 2;
		return temp;
	}
	else if (35 == (int)ch || 61 == (int)ch)//#、=
	{
		temp = 1;
		return temp;
	}
}

/*计算每一步的值*/
int Operate(int a,int b,char c)
{
	int sum = 0;
	switch ((int)c)
	{
	case 42:
		sum = a * b;
		break;
	case 43:
		sum = a + b;
		break;
	case 45:
		sum = a - b;
		break;
	case 47:
		sum = a / b;
		break;
	}
	return sum;
}

/*计算最后的值*/
void EvaluateExpression(SqStack &S1, SqStack &S2, string str)
{
	int a = 0, b = 0;//接收要进行运算的两个值
	int a1 = 0, b1 = 0;//如果S1里面还有元素，继续接收，进行运算
	int e = 0;//删除元素
	int flag = 0;
	char e1 = '0';
	int len = 0;//字符串的长度
	char c = '0';
	char c1 = '0';
	len = str.length();
	Push(S2, '#');
	for (int i = 0; i <= len - 1; i++)
	{

		if ((int)str[i] >= 48 && (int)str[i] <= 57)//数字压入S1
		{
			flag = (int)str[i] - '0';
			Push(S1, flag);
		}
		else {
			if (isFirst(GetTop(S2)) < isFirst(str[i])|| 35 == isFirst(GetTop(S2)))//运算符比较优先级
			{
				Push(S2, (int)str[i]);
			}
			else if (isFirst(GetTop(S2)) >= isFirst(str[i]))
			{
				a = GetTop(S1);
				Pop1(S1, e);
				b = GetTop(S1);
				Pop1(S1, e);
				c = GetTop(S2);
				Pop2(S2, e);
				Push(S1, Operate(b, a, c));
				if (S1.top != S1.base)
				{
					a1 = GetTop(S1);
					Pop1(S1, e);
					b1 = GetTop(S1);
					Pop1(S1, e);
					c1 = GetTop(S2);
					Push(S1, Operate(b1, a1, c1));
				}
				cout << GetTop(S1) << endl;
			}
		}
	}
}

int main()
{
	SqStack S1, S2;
	string str;
	cout << "请输入你要计算的表达式：";
	getline(cin, str);
	InitStack(S1);//数字
	InitStack(S2);//运算符
	EvaluateExpression(S1, S2, str);
	return 0;
}


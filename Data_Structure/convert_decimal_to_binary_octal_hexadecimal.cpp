/*利用栈实现十进制与二进制、八进制、十六机制的互换*/
/*author: Qingqing Guo; sunnyguoqq@outlook.com*/

#include<iostream>
using namespace std;
#define OK 1
#define ERROR 0
#define MAXSIZE 100
typedef int Status;
typedef int SElemType;

typedef struct
{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

//初始化
Status InitStack(SqStack &S)
{
	S.base = new int[MAXSIZE];
	if(!S.base)
		exit(OVERFLOW)；
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return OK;
}
//入栈
Status Push(SqStack &S, int e)
{
	if(S.top - S.base == S.stacksize)
		return ERROR；
	*S.top++ = e;
	return OK;
}
//取栈顶元素
Status GetTop(SqStack S)
{
	if(S.top != S.base)
		return *(S.top-1);
}
//进制转换
Status Transmits(SqStack &S, SqStack &S1, int n)
{
	int num, res;
	if( n == 2 )
	{
		if(S.top != S.base)
		{
			num = *(S.top-1);
			while(num != 0)
			{
				res = num % 2;
				Push(S1, res);
				num /= 2;
			}
			while(S1.top-1 != S1.base)
			{
				cout<<GetTop(S1);
				S1.top--;
			}
		}
	}
	if( n == 8)
	{
		if(S.top != S.base)
		{
			num = *(S.top-1);
			while(num != 0)
			{
				res = num % 8;
				Push(S1, res);
				num /= 8;
			}
			while(S1.top-1 != S1.base)
			{
				cout<<GetTop(S1);
				S1.top--;
			}
		}
	}
	if( n == 16)
	{
		if(S.top != S.base)
		{
			num = *(S.top-1);
			while(num != 0)
			{
				res = num % 16;
				Push( S1, res);
				num /= 16;
			}
			while(S1.top-1 != S1.base)
			{
				cout<<GetTop(S1);
				S1.top--;
			}
		}
	}
	return OK;
}

int main()
{
	SqStack S, S1;
	int e, n;
	cout << "要转换的值：";
	cin >> e;
	cout <<"转换成几进制：";
	cin >> n;
	InitStack(S);
	InitSStack(S1);
	Push(S, e);
	cout << Transmits(S, S1, n);
	return 0;
}	

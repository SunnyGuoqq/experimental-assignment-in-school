#include<iostream>
using namespace std;
#define MAXSIZE 100

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode, *LinkList;
//升序的插入数据
void CreatList(LinkList &L, int n)
{
	L = new LNode;
	LNode *r, *p;
	L->next = NULL;
	r = L;//尾指针指向头节点
	cout << "输入节点数据：";//使用后插法向单链表中插入有序的数据
	for (int i = 0; i < n; ++i) {
		p = new LNode;
		cin >> p->data;
		p->next = NULL;
		r->next = p;
		r = p;//r指向新的尾节点
	}
}
void insertList(LinkList L, int x)
{
	LNode *pre, *p, *s;
	pre = L;
	p = pre->next;
	s = new LNode;//创建新节点，储存将要插入单链表的数据。
	s->data = x;
	s->next = NULL;
	//当本节点不为空，且数据域的数据域中的数据小于将要插入的数据时，节点后移。
	while (p != NULL && p->data < x) {
		pre = p;
		p = p->next;
	}
	s->next = pre->next;//插入节点
	pre->next = s;
}
void printList(LinkList L)
{
	LNode *q;
	q = L->next;
	cout << "链表中的数据:";
	while (q != NULL)
	{
		cout << q->data<<",";
		q = q->next;
	}
}

int main()
{
	int n, x;
	LinkList L;
	cout << "单链表共有几个元素：";
	cin >> n;
	cout << "插入的数据：";
	cin >> x;
	CreatList(L, n);
	insertList(L, x);
	printList(L);
	return 0;
}


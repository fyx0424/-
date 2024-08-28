#include <iostream>
using namespace std;
#define MAXSIZE 0x3f3f3f3f;
//单向链表
//链表的定义
struct lnode
{
	int data;//结点的数据域
	lnode* next;//结点的指针域
};
typedef lnode* linklist;
//链表的初始化
bool initlist(linklist& l)//插入题外话：LinkList &L等价于 Lnode *&L，Lnode *&L是一个指向指针的引用
{
	l = new lnode;//堆区开辟一个头结点，结点的数据类型为Lnode
	l->next = nullptr;//空表，也就是说头结点的指针指向为空
	return true;
}
//头插法创建单向链表
void creatlisthead(linklist& l, const size_t n)
{
	for (int i = 0; i < n; ++i)
	{
		linklist p = new lnode;
		cin >> p->data;
		p->next = l->next;
		l->next = p;
	}
}
//尾插法创建单向链表
void creatlisttail(linklist& l, const size_t n)
{
	lnode* r = l;
	for (int i = 0; i < n; ++i)
	{
		lnode* p = new lnode;
		cin >> p->data;
		p->next = r->next;
		r->next = p;
		r = r->next;
	}
}
//判断链表是否为空
bool isempty(const linklist& l)
{
	if (l->next)
	{
		return false;
	}
	else
		return true;
}
//销毁链表
bool destroylist(linklist& l)
{
	//判断链表是否为空
	if (isempty(l))
	{
		cout << "empty" << endl;
		return false;
	}
	while (l)
	{
		auto temp = l->next;//将头指针指向下一个结点
		delete l;
	}
	return true;
}
//统计链表长度
size_t getlength(const linklist& l)
{
	lnode* p;
	p = l->next;
	size_t cnt = 0;
	while (p)
	{
		++cnt;
		p = p->next;
	}
	return cnt;
}
//取链表中第i个元素的值
bool getelem(const linklist& l, const int& i, int & e)
{
	if (i < 0)
	{
		cout << "out" << endl;
		return false;
   }
	lnode* p = l->next;
	for (int j = 1; j < i + 1; ++j)
	{
		p = p->next;
		if (!p)
		{
			cout << "out" << endl;
			return false;//如果此时p为空，意味着已经到达链表尾端，停止循环
		}
	}
	e = p->data;
	return true;
}
//按值查找链表
size_t locateelem(linklist& l, int& e)
{
	lnode* p = l->next;
	size_t cnt = 1;
	while (p)
	{
		if (p->data == e)
		{
			return cnt;
		}
		++cnt;
		p = p->next;
	}
	cout << "not found" << endl;
	return 0;
}
//在链表中插入元素
bool insertlist(linklist& l, const int& i, const int& e)
{
	lnode* p = l;
	int j = 0;
	while (p && j < i - 1)
	{
		p = p->next;
		++j;
	}
	//异常判断
	if (!p || i < 0)
	{
		cerr << "out of range" << endl;
		return false;
	}
	linklist insert = new lnode;
	insert->data = e;
	insert->next = p->next;
	p->next = insert;
	return true;
}
//删除链表的某个结点
bool eraselist(linklist& l, const int& i)
{
	lnode* p = l;
	int j = 0;
	while (p->next && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!(p->next) || i < 0)
	{
		cerr << "out of range" << endl;
		return false;
	}
	lnode* q = p->next;
	p->next = p->next->next;
	delete q;
	return true;
}
int main()
{

}
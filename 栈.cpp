#include<iostream>
using namespace std;
#define MAXSIZE 0x3f3f3f3f
//1 - 顺序栈
//
//顺序栈的定义
struct sqstack
{
	int* base;
	int* top;
	int stacksize;
};
//顺序栈的初始化
bool initstack(sqstack& s)
{
	s.base = new int[MAXSIZE];
	if (!s.base)
	{
		cout << "faile" << endl;
		return false;
	}
	s.top = s.base;
	s.stacksize = MAXSIZE;
	return true;
}
//压栈
bool push(sqstack& s, int& e)
{
	//判断栈是否已满
	if ((s.top - s.base) == s.stacksize)
	{
		cout << "full" << endl;
		return false;
	}
	*(s.top) = e;
	++(s.top);
	return true;
}
//创建一个栈
bool createstack(sqstack s, const int n)
{
	for (int i = 0; i < n; ++i)
	{
		int input;
		cin >> input;
		if (!push(s, input))
		{
			cout << "error" << i << endl;
			return false;
		}
		return true;
	}
}
//判断顺序栈是否为空
bool isempty(sqstack& s)
{
	if (s.base == s.top)
	{
		return true;
	}
	else
		return false;
}
//弹栈
bool pop(sqstack& s, int& e)
{
	if (!isempty(s))
	{
		cout << "empty !error" << endl;
		return false;
	}
	--(s.top);
	e = *(s.top);
	return true;
}
//获取栈的元素个数
int stacklenfth(sqstack& s)
{
	return static_cast<int>(s.top - s.base);
}
//清空顺序栈
bool clearstack(sqstack& s)
{
	if (s.base)
	{
		s.top = s.base;
		return true;
	}
	else
		return false;
}
//销毁顺序栈
void destoystack(sqstack& s)
{
	if (s.base)
	{
		delete[] s.base;
		s.stacksize = 0;
		s.base = s.top = nullptr;
	}
}
//2 - 链式栈
//
//链式栈的定义
typedef struct stacknode
{
	int data;
	stacknode* next;
}*linkstack;
//栈的初始化
void initstack(linkstack& s)
{
	//创建头结点
	s = new stacknode;
	s->next = nullptr;
	s->data = 0;//表示栈的元素个数
}
//压栈
void push(linkstack& s, const int& e)
{
	//插入元素
	stacknode* temp = new stacknode;
	temp->data = e;
	temp->next = s->next;
	s->next = temp;
	++(s->data);//元素个数加一
}
//弹栈
void pop(linkstack&s,int &e)
{
	//删除元素
	stacknode* p = s->next;
	e = p->data;
	s->next = p->next;
	--(s->data);
	delete p;
}
//创建栈
void createstack(linkstack& s, const int n)
{
	int input;
	for (int i = 0; i < n; ++i)
	{
		cin >> input;
		push(s, input);
	}
}
//获取栈的元素个数
int StackLength(linkstack& s)
{
	return s->data;
}
//清空栈
bool clearstack(linkstack& s)
{
	if (!(s->next))
	{
		cout << "empty" << endl;
		return false;
	}
	stacknode* q, * p = s->next;
	while (p)
	{
		q = p;
		p = p -> next;
		delete q;
	}
	s->data = 0;
	s->next = nullptr;
	return true;
}
//销毁栈
bool DestoryStack(linkstack& s)
{
	if (s)
	{
		cerr << "error" << endl;
		return false;
	}
	while (s)
	{
		stacknode* temp = s;
		s = s->next;
		delete temp;
	}
	return true;
}
int main()
{

}

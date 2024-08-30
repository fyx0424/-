#include<iostream>
using namespace std;
#define MAXSIZE 0x3f3f3f3f
//1 - ˳��ջ
//
//˳��ջ�Ķ���
struct sqstack
{
	int* base;
	int* top;
	int stacksize;
};
//˳��ջ�ĳ�ʼ��
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
//ѹջ
bool push(sqstack& s, int& e)
{
	//�ж�ջ�Ƿ�����
	if ((s.top - s.base) == s.stacksize)
	{
		cout << "full" << endl;
		return false;
	}
	*(s.top) = e;
	++(s.top);
	return true;
}
//����һ��ջ
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
//�ж�˳��ջ�Ƿ�Ϊ��
bool isempty(sqstack& s)
{
	if (s.base == s.top)
	{
		return true;
	}
	else
		return false;
}
//��ջ
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
//��ȡջ��Ԫ�ظ���
int stacklenfth(sqstack& s)
{
	return static_cast<int>(s.top - s.base);
}
//���˳��ջ
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
//����˳��ջ
void destoystack(sqstack& s)
{
	if (s.base)
	{
		delete[] s.base;
		s.stacksize = 0;
		s.base = s.top = nullptr;
	}
}
//2 - ��ʽջ
//
//��ʽջ�Ķ���
typedef struct stacknode
{
	int data;
	stacknode* next;
}*linkstack;
//ջ�ĳ�ʼ��
void initstack(linkstack& s)
{
	//����ͷ���
	s = new stacknode;
	s->next = nullptr;
	s->data = 0;//��ʾջ��Ԫ�ظ���
}
//ѹջ
void push(linkstack& s, const int& e)
{
	//����Ԫ��
	stacknode* temp = new stacknode;
	temp->data = e;
	temp->next = s->next;
	s->next = temp;
	++(s->data);//Ԫ�ظ�����һ
}
//��ջ
void pop(linkstack&s,int &e)
{
	//ɾ��Ԫ��
	stacknode* p = s->next;
	e = p->data;
	s->next = p->next;
	--(s->data);
	delete p;
}
//����ջ
void createstack(linkstack& s, const int n)
{
	int input;
	for (int i = 0; i < n; ++i)
	{
		cin >> input;
		push(s, input);
	}
}
//��ȡջ��Ԫ�ظ���
int StackLength(linkstack& s)
{
	return s->data;
}
//���ջ
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
//����ջ
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

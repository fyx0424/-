#include <iostream>
using namespace std;
#define MAXSIZE 0x3f3f3f3f;
//��������
//����Ķ���
struct lnode
{
	int data;//����������
	lnode* next;//����ָ����
};
typedef lnode* linklist;
//����ĳ�ʼ��
bool initlist(linklist& l)//�������⻰��LinkList &L�ȼ��� Lnode *&L��Lnode *&L��һ��ָ��ָ�������
{
	l = new lnode;//��������һ��ͷ��㣬������������ΪLnode
	l->next = nullptr;//�ձ�Ҳ����˵ͷ����ָ��ָ��Ϊ��
	return true;
}
//ͷ�巨������������
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
//β�巨������������
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
//�ж������Ƿ�Ϊ��
bool isempty(const linklist& l)
{
	if (l->next)
	{
		return false;
	}
	else
		return true;
}
//��������
bool destroylist(linklist& l)
{
	//�ж������Ƿ�Ϊ��
	if (isempty(l))
	{
		cout << "empty" << endl;
		return false;
	}
	while (l)
	{
		auto temp = l->next;//��ͷָ��ָ����һ�����
		delete l;
	}
	return true;
}
//ͳ��������
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
//ȡ�����е�i��Ԫ�ص�ֵ
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
			return false;//�����ʱpΪ�գ���ζ���Ѿ���������β�ˣ�ֹͣѭ��
		}
	}
	e = p->data;
	return true;
}
//��ֵ��������
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
//�������в���Ԫ��
bool insertlist(linklist& l, const int& i, const int& e)
{
	lnode* p = l;
	int j = 0;
	while (p && j < i - 1)
	{
		p = p->next;
		++j;
	}
	//�쳣�ж�
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
//ɾ�������ĳ�����
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
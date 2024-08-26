#include <iostream>
using namespace std;
#define MAXSIZE 0x3f3f3f3f
//class list
//{
//public:
//		int len;
//		int a;
//private:
//	
//
//};
//���Ա���
struct sqlist
{
	int* elem;//��ͷ
	int length;//����
};
//���Ա��ʼ��
bool initlist(sqlist& l)
{
	l.elem = new int[MAXSIZE];//�ڶ��������ڴ�
	if (!l.elem)
	{
		cout << "error" << endl;
		return false;
	}
	l.length = 0;//�趨���Ա���Ϊ0;
	return 1;

}
//���Ա������
void destorylist(sqlist& l)
{
	if (l.elem)
	{
		delete l.elem;
	}
}
//���Ա�����
void clearlist(sqlist &l)
{
	l.length = 0;
}
//�ж����Ա��Ƿ�Ϊ��
bool isempty(const sqlist& l)
{
	return static_cast<bool>(l.length);
}
//���Ա��ȡֵ
bool getelem(const sqlist& l, const size_t i, int &e)
{
	if (i<1 || i>MAXSIZE)
	{
		cout << "out" << endl;
		return false;
	}
	e = l.elem[i - 1];
	return true;
}
//���Ա�Ĳ���
int locatelist(const sqlist& l, const int& e)
{
	for (int i = 0; i < l.length; ++i)
	{
		if (l.elem[i] == e)
		{
			return i + 1;//���ҳɹ������������Ԫ�صĵ�һ���±�ֵ
		}
   }
	return 0;
}
//���Ա�Ĳ���
bool insertlist(sqlist& l, const int& e, const int& i)
{
	//�ж����Ա����Ƿ�С����󳤶�MAXSIZE
	if (l.length == MAXSIZE)
	{
		cout << "not" << endl;
		return false;
	}
	if (i<0 || i>l.length)
	{
		cout << "not" << endl;
		return false;
	}
	if (l.length > 0)
	{
		//��λ�ڲ���λ��֮���Ԫ���������Ų��һλ
		for (int p = l.length - 1; p >= i; --p)
		{
			l.elem[p + 1] = l.elem[p];
		}
	}
	//����Ԫ��
	l.elem[i] = e;
	//���Ա���+1
	l.length += 1;
	return true;

}
//���Ա��ɾ��
bool eraselist(sqlist& l, const int& i)
{
	//�쳣�ж�
	if (i<0 || i>l.length)
	{
		cout << "not" << endl;
		return false;
	}
	if (l.length == 0)
	{
		cout << "not" << endl;
		return false;
	}
	//��λ��ɾ��λ��֮���Ԫ��������ǰŲ��һλ
	for (int p = i + 1; p < l.length; ++p)
	{
		l.elem[p - 1] = l.elem[p];
	}
	l. length -= 1;
	return true;
}
int main()
{

}
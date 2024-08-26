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
//线性表定义
struct sqlist
{
	int* elem;//表头
	int length;//长度
};
//线性表初始化
bool initlist(sqlist& l)
{
	l.elem = new int[MAXSIZE];//在堆区开辟内存
	if (!l.elem)
	{
		cout << "error" << endl;
		return false;
	}
	l.length = 0;//设定线性表长度为0;
	return 1;

}
//线性表的销毁
void destorylist(sqlist& l)
{
	if (l.elem)
	{
		delete l.elem;
	}
}
//线性表的清空
void clearlist(sqlist &l)
{
	l.length = 0;
}
//判断线性表是否为空
bool isempty(const sqlist& l)
{
	return static_cast<bool>(l.length);
}
//线性表的取值
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
//线性表的查找
int locatelist(const sqlist& l, const int& e)
{
	for (int i = 0; i < l.length; ++i)
	{
		if (l.elem[i] == e)
		{
			return i + 1;//查找成功，返回其查找元素的第一个下标值
		}
   }
	return 0;
}
//线性表的插入
bool insertlist(sqlist& l, const int& e, const int& i)
{
	//判断线性表长度是否小于最大长度MAXSIZE
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
		//将位于插入位置之后的元素依次向后挪动一位
		for (int p = l.length - 1; p >= i; --p)
		{
			l.elem[p + 1] = l.elem[p];
		}
	}
	//插入元素
	l.elem[i] = e;
	//线性表长度+1
	l.length += 1;
	return true;

}
//线性表的删除
bool eraselist(sqlist& l, const int& i)
{
	//异常判断
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
	//将位于删除位置之后的元素依次向前挪动一位
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
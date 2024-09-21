#include <iostream>
using namespace std;
//1 - ��������
//
//ֱ�Ӳ�������
void insertsort(sqlsit& l)
{
	for (int i = 1; i <= l.length; ++i)
	{
		l.elem[0] = l.elem[i];
		int j = i - 1;
		for (; l.elem[0].key < l.elem[j].key; --j)
		{
			l.elem[j + 1] = l.elem[j];
		}
		l.elem[j + 1] = l.elem[0];
	}
	//�㷨ʱ�临�Ӷȣ�O(n^2)���ռ临�Ӷȣ�O(1)
}

//�۰��������
void binsertsort(sqlist& l)
{
	for (int i = 2; i < l.length; ++i)
	{
		l.elem[0] = l.elem[i];// //�ڱ�λ
		int low = 1, high = i - 1;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (l.elem[0].key < l.elem[mid].key)
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
		//�������ĸ���˼�룬�ǽ��۰�����ıȽ����䣬����С������С�ڵ����ڱ�Ԫ�ص��Ǹ�Ԫ�ص�λ��
	   //Ȼ�����λ���ټ�1�����Ǵ�Ԫ��Ӧ�ò����λ��
		for (int j = i; j >= high + 1; --j)
		{
			l.elem[j + 1] = l.elem[j];
		}
		l.elem[high + 1] = l.elem[0];
	}
}
//2 - ��������
//
//ð������

void bubblesort(sqlist& l)
{
	for (int i = 0; i < l.length; ++i)
	{
		for (int j = 0; j < l.length - i; ++j)
		{
			if (l.elem[j].key < l.elem[j + 1].key)
			{
				elemtype temp = l.elem[j];
				l.elem[j] = l.elem[j + 1];
				l.elem[j + 1] = temp;
			}
		}
		//�㷨ʱ�临�Ӷȣ�O(n^2)���ռ临�Ӷȣ�O(1)
	}
}

//��������
int partition(sqlist& l, int low, int high)
{
	//�����ڱ�λ
	l.elem[0] = l.elem[low];
	//��������Ԫ��
	int pivotkey = l.elem[0].key;
	//ѭ������ʼ
	while (low < high)
	{
		//�ӱ�β��ʼ��Ԫ��
		while (low < high && l.elem[high.key >= pivotkey)
		{
			--high;//��ǰ�ƶ�high
		}
		//�����������ѭ���ˣ���ζ��Ҫôlow==high�ˣ�Ҫô�ڱ�β�ҵ���һ��С������
		l.elem[low] = l.elem[high];
		//�ӱ�ͷ��ʼ��Ԫ��
		while (low < high && l.elem[low].key < pivotkey)
			++low;//����ƶ�low
		//�����������ѭ���ˣ���ζ��Ҫôlow==high�ˣ�Ҫô�ڱ�β�ҵ���һ����������Ԫ�ص�Ԫ��
		l.elem[high] = l.elem[low];
	} //��ͷlow�ͱ�βhigh���ʱ���˳�ѭ��
	l.elem[low] = l.elem[0];
	//�������������Ԫ�ص�λ��
	return low; //low��ʵ�ǵ���high������low���߷���high��һ������
}
void qsort(sqlist& l, int low, int high)
{
	//��������������������
	if (low < high)
	{
		int pivotloc = partition(l, low, high);
		//�ٶ����е���벿�ֽ�������������λ��
		qsort(l, low, pivotloc - 1);
		//�ٶ����е��Ұ벿�ֽ�������������λ��
		qsort(l, pivotloc + 1, high);
	}
}
int main()
{

}
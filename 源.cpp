#include <iostream>
using namespace std;
//1 - 插入排序
//
//直接插入排序
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
	//算法时间复杂度：O(n^2)，空间复杂度：O(1)
}

//折半插入排序
void binsertsort(sqlist& l)
{
	for (int i = 2; i < l.length; ++i)
	{
		l.elem[0] = l.elem[i];// //哨兵位
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
		//这个排序的根本思想，是将折半排序的比较区间，逐渐缩小到最大的小于等于哨兵元素的那个元素的位置
	   //然后这个位置再加1，就是此元素应该插入的位置
		for (int j = i; j >= high + 1; --j)
		{
			l.elem[j + 1] = l.elem[j];
		}
		l.elem[high + 1] = l.elem[0];
	}
}
//2 - 交换排序
//
//冒泡排序

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
		//算法时间复杂度：O(n^2)，空间复杂度：O(1)
	}
}

//快速排序
int partition(sqlist& l, int low, int high)
{
	//设置哨兵位
	l.elem[0] = l.elem[low];
	//设置中心元素
	int pivotkey = l.elem[0].key;
	//循环排序开始
	while (low < high)
	{
		//从表尾开始找元素
		while (low < high && l.elem[high.key >= pivotkey)
		{
			--high;//向前移动high
		}
		//跳出上面这个循环了，意味着要么low==high了，要么在表尾找到了一个小于中心
		l.elem[low] = l.elem[high];
		//从表头开始找元素
		while (low < high && l.elem[low].key < pivotkey)
			++low;//向后移动low
		//跳出上面这个循环了，意味着要么low==high了，要么在表尾找到了一个大于中心元素的元素
		l.elem[high] = l.elem[low];
	} //表头low和表尾high相等时，退出循环
	l.elem[low] = l.elem[0];
	//返回排序后中心元素的位置
	return low; //low其实是等于high，返回low或者返回high是一个道理
}
void qsort(sqlist& l, int low, int high)
{
	//好像二叉树的先序遍历啊
	if (low < high)
	{
		int pivotloc = partition(l, low, high);
		//再对序列的左半部分进行排序找中心位置
		qsort(l, low, pivotloc - 1);
		//再对序列的右半部分进行排序找中心位置
		qsort(l, pivotloc + 1, high);
	}
}
int main()
{

}
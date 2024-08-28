#include <stdio.h>
#include <stdlib.h>
// 定义链表节点结构
typedef struct lnode
{
	int data;// 节点数据
	struct lnode* next;// 指向下一个节点的指针
};
// 创建链表节点
lnode* createnode(int data)
{
	lnode* newnode = new lnode;
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}
// 打印链表
void printlist(lnode* head)
{
	lnode* p = head->next;// 跳过头节点
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("NULL\\n");
}
int main()
{
	// 创建头节点
	lnode* l = createnode(0);
	// 创建一些数据节点
	lnode* node1 = createnode(1);
	lnode* node2 = createnode(2);
	lnode* node3 = createnode(3);
	// 连接节点
	l->next = node1;
	node1->next = node2;
	node2->next = node3;
	// 打印链表
	printlist(l);

	lnode* p = l->next;
	if (p != NULL) {
		printf("第一个数据节点的值是: %d\\n", p->data);
	}
	else {
		printf("链表为空\\n");
	}

	// 释放内存
	delete(node3);
	delete(node2);
	delete(node1);
	delete(l);

	return 0;

}
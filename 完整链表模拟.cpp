#include <stdio.h>
#include <stdlib.h>
// ��������ڵ�ṹ
typedef struct lnode
{
	int data;// �ڵ�����
	struct lnode* next;// ָ����һ���ڵ��ָ��
};
// ��������ڵ�
lnode* createnode(int data)
{
	lnode* newnode = new lnode;
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}
// ��ӡ����
void printlist(lnode* head)
{
	lnode* p = head->next;// ����ͷ�ڵ�
	while (p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("NULL\\n");
}
int main()
{
	// ����ͷ�ڵ�
	lnode* l = createnode(0);
	// ����һЩ���ݽڵ�
	lnode* node1 = createnode(1);
	lnode* node2 = createnode(2);
	lnode* node3 = createnode(3);
	// ���ӽڵ�
	l->next = node1;
	node1->next = node2;
	node2->next = node3;
	// ��ӡ����
	printlist(l);

	lnode* p = l->next;
	if (p != NULL) {
		printf("��һ�����ݽڵ��ֵ��: %d\\n", p->data);
	}
	else {
		printf("����Ϊ��\\n");
	}

	// �ͷ��ڴ�
	delete(node3);
	delete(node2);
	delete(node1);
	delete(l);

	return 0;

}
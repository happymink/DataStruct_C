#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
}; ListNode;

typedef struct {
	ListNode* head;
	int length;
} ListType;


/////////////////////////////////////////////////////////////////////////////////
void init(ListType* list)
{
	list->length = 0;
	list->head = NULL;
}

// phead : ����Ʈ�� ��� �������� ������
// p  : ���� ��� (pre)
// new_node : �߰��� ��� 
void insert_node(ListNode** phead, ListNode* p, ListNode* new_node)
{
	//���鸮��Ʈ�� ���
	if (*phead == NULL) {
		new_node->link = NULL;
		*phead = new_node;
	}
	// ù ��° ���� �߰��ϴ� ��� (�� �տ� �ƹ��� ����)
	else if (p == NULL) {
		new_node->link = *phead; //���� �߿�, ���ο� ��� ��ũ���� ����
		*phead = new_node;
	}
	//�־��� ��ġ�� �߰��ϴ� ��� p (pre) ������ new_node �߰�
	else {
		new_node->link = p->link;
		p->link = new_node;
	}
}

void remove_node(ListNode** phead, ListNode* p, ListNode* removed)
{

}
// pos ��ġ�� ��� �����͸� ã�Ƽ� ����
ListNode* get_node_at(ListType* list, int pos)
{
	ListNode* tmp_node = list->head; //���纻�� ���� �ݺ�
	
	// position ����ڵ�
	if (pos < 0)
		return NULL;

	for (int i = 0; i < pos; i++) {
		tmp_node = tmp_node->link;
	}

	return tmp_node;
}

// ���Ḯ��Ʈ�� ��� ������ ��ȯ
int get_length(ListType* list)
{
	return list->length;
}

// list ���Ḯ��Ʈ�� position ��ġ�� data�� �߰�
void add(ListType* list, int position, element data)
{
	ListNode* p; //pre
	//position ���� ��ȿ�� �˻�
	if ((position >= 0) && (position <= list->length)) {
		// ���� �߰��� ListNode ����
		ListNode* node = (ListNode*)malloc(sizeof(ListNode));
		
		//�޸� ������ ��ȿ�� Ȯ��
		if (node == NULL) {
			printf("�޸� �Ҵ� ����\n");
			return;
		}

		node->data = data;
		p = get_node_at(list, position); //�ӽ�����

		insert_node(&(list->head), p, node); 
		list->length++;
	}
}

void add_last(ListType* list, element data)
{
	add(list, get_length(list), data);
}

void add_first(ListType* list, element data)
{
	add(list, 0, data);
}

// list ���Ḯ��Ʈ�� position ��ġ�� data�� ����
void deleteNode(ListType* list, int position)
{

}

// ���Ḯ��Ʈ�� ����ִ��� Ȯ�� Ture/False ����
int is_empty(ListType *list)
{
	return 0;
}

// ���Ḯ��Ʈ�� ���� ���
void display(ListType* list)
{

}

void clear(ListType* list)
{

}

//item ���� ���Ḯ��Ʈ�� �����ϴ��� �˻��ؼ� True/False ����
int is_in_list(ListType* list, element item)
{
	return 0;
}

//pos ��ġ�� ��� ���� �о ��ȯ
element get_entry(ListType* list, int pos)
{
	return 0;
}
/////////////////////////////////////////////////////////////////////////////////
void main()
{
	ListType list;
	FILE* fp;
	int nTemp;

	init(&list);

	fp = fopen("data.txt", "r");

	if (fp == NULL) {
		printf("error\n");
		return;
	}
	
	while (!feof(fp)) {
		fscanf(fp, "%d", &nTemp);
		add_last(&list, nTemp);
	}

	fclose(fp);

	display(&list);
	clear(&list);

}

//���� display �߰� get node at ����
// clear�� ������
// �����ϸ鼭 ����Ʈ .. Ŭ����� �����ð���


//�ǽ��Ѱ� �۵��ǰ� �ϰ� display ����

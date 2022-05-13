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

// phead : 리스트의 헤드 포인터의 포인터
// p  : 선행 노드 (pre)
// new_node : 추가할 노드 
void insert_node(ListNode** phead, ListNode* p, ListNode* new_node)
{
	//공백리스트인 경우
	if (*phead == NULL) {
		new_node->link = NULL;
		*phead = new_node;
	}
	// 첫 번째 노드로 추가하는 경우 (내 앞에 아무도 없음)
	else if (p == NULL) {
		new_node->link = *phead; //순서 중요, 새로운 노드 링크부터 설정
		*phead = new_node;
	}
	//주어진 위치에 추가하는 경우 p (pre) 다음에 new_node 추가
	else {
		new_node->link = p->link;
		p->link = new_node;
	}
}

void remove_node(ListNode** phead, ListNode* p, ListNode* removed)
{

}
// pos 위치에 노드 포인터를 찾아서 리턴
ListNode* get_node_at(ListType* list, int pos)
{
	ListNode* tmp_node = list->head; //복사본을 만들어서 반복
	
	// position 방어코드
	if (pos < 0)
		return NULL;

	for (int i = 0; i < pos; i++) {
		tmp_node = tmp_node->link;
	}

	return tmp_node;
}

// 연결리시트의 노드 개수를 반환
int get_length(ListType* list)
{
	return list->length;
}

// list 연결리스트의 position 위치에 data를 추가
void add(ListType* list, int position, element data)
{
	ListNode* p; //pre
	//position 값의 유효성 검사
	if ((position >= 0) && (position <= list->length)) {
		// 새로 추가할 ListNode 생성
		ListNode* node = (ListNode*)malloc(sizeof(ListNode));
		
		//메모리 포인터 유효성 확인
		if (node == NULL) {
			printf("메모리 할당 오류\n");
			return;
		}

		node->data = data;
		p = get_node_at(list, position); //임시저장

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

// list 연결리스트의 position 위치에 data를 삭제
void deleteNode(ListType* list, int position)
{

}

// 연결리스트가 비어있는지 확인 Ture/False 리턴
int is_empty(ListType *list)
{
	return 0;
}

// 연결리스트의 내용 출력
void display(ListType* list)
{

}

void clear(ListType* list)
{

}

//item 값이 연결리스트에 존재하는지 검색해서 True/False 리턴
int is_in_list(ListType* list, element item)
{
	return 0;
}

//pos 위치의 노드 값을 읽어서 반환
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

//과제 display 추가 get node at 참조
// clear은 복잡해
// 루프하면서 딜리트 .. 클리어는 다음시간에


//실습한거 작동되게 하고 display 구현

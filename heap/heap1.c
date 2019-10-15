#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
typedef struct {
	int key;
} element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;


// 생성 함수
HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType)); // 동적 할당
}
// 초기화 함수
void init(HeapType* h)
{
	h->heap_size = 0;
}

/* item을 heap_size를 가진 히프 h에 삽입 */
void insert_max_heap(HeapType* h, element item) {

	int i;
	i = ++(h->heap_size);

	/* 부모 노드의 키가 item의 키보다 크고 heap_size 가 0이 아닐 때,
	부모 노드를 새로운 노드로 이동시키고 부모 노드 인덱스로 바꾼다 */
	if ((i != 1) && (item.key > h->heap[i / 2].key)) {

		h->heap[i] = h->heap[i / 2]; // 새로운 노드 위치로 부모 노드 이동
		i /= 2; // 부모 노드 인덱스

	}

	/* item의 key 값이 제일 작은 경우는 바로 이쪽으로 옵니다. */
	h->heap[i] = item; // 부모 노드에 새로운 노드 삽입
}

element delete_max_heap(HeapType* h) {
	int parent, child;
	element item, temp;

	parent = 1;
	child = 2;
	item = h->heap[1]; // 루트 노드
	temp = h->heap[(h->heap_size)--]; // 말단 노드

	while (child <= h->heap_size) {
		/* 왼쪽 자식 노드와 오른쪽 자식 노드 중 더 큰 값을 찾아서 부모 노드와 비교*/
		if ((child < h->heap_size) &&
			h->heap[child].key<h->heap[child+1].key) 
			child++; // 오른쪽 자식 노드의 인덱스

		if (h->heap[child].key <= temp.key) break;
		
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

int main(void)
{
	element e1 = { 10 }, e2 = { 5 }, e3 = { 30 };
	element e4, e5, e6;
	HeapType* heap;

	heap = create(); 	// 히프 생성
	init(heap);	// 초기화

				// 삽입
	insert_max_heap(heap, e1);
	insert_max_heap(heap, e2);
	insert_max_heap(heap, e3);

	// 삭제
	e4 = delete_max_heap(heap);
	printf("< %d > ", e4.key);
	e5 = delete_max_heap(heap);
	printf("< %d > ", e5.key);
	e6 = delete_max_heap(heap);
	printf("< %d > \n", e6.key);

	free(heap);
	return 0;
}
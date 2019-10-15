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


// ���� �Լ�
HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType)); // ���� �Ҵ�
}
// �ʱ�ȭ �Լ�
void init(HeapType* h)
{
	h->heap_size = 0;
}

/* item�� heap_size�� ���� ���� h�� ���� */
void insert_max_heap(HeapType* h, element item) {

	int i;
	i = ++(h->heap_size);

	/* �θ� ����� Ű�� item�� Ű���� ũ�� heap_size �� 0�� �ƴ� ��,
	�θ� ��带 ���ο� ���� �̵���Ű�� �θ� ��� �ε����� �ٲ۴� */
	if ((i != 1) && (item.key > h->heap[i / 2].key)) {

		h->heap[i] = h->heap[i / 2]; // ���ο� ��� ��ġ�� �θ� ��� �̵�
		i /= 2; // �θ� ��� �ε���

	}

	/* item�� key ���� ���� ���� ���� �ٷ� �������� �ɴϴ�. */
	h->heap[i] = item; // �θ� ��忡 ���ο� ��� ����
}

element delete_max_heap(HeapType* h) {
	int parent, child;
	element item, temp;

	parent = 1;
	child = 2;
	item = h->heap[1]; // ��Ʈ ���
	temp = h->heap[(h->heap_size)--]; // ���� ���

	while (child <= h->heap_size) {
		/* ���� �ڽ� ���� ������ �ڽ� ��� �� �� ū ���� ã�Ƽ� �θ� ���� ��*/
		if ((child < h->heap_size) &&
			h->heap[child].key<h->heap[child+1].key) 
			child++; // ������ �ڽ� ����� �ε���

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

	heap = create(); 	// ���� ����
	init(heap);	// �ʱ�ȭ

				// ����
	insert_max_heap(heap, e1);
	insert_max_heap(heap, e2);
	insert_max_heap(heap, e3);

	// ����
	e4 = delete_max_heap(heap);
	printf("< %d > ", e4.key);
	e5 = delete_max_heap(heap);
	printf("< %d > ", e5.key);
	e6 = delete_max_heap(heap);
	printf("< %d > \n", e6.key);

	free(heap);
	return 0;
}
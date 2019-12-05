#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE];
int n;

int partition(int list[], int left, int right)
{
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left]; // 나눌 배열의 가장 왼쪽이라고 가정
	do {
		// pivot 다음 인덱스로 이동
		do 
			low++; 
		while (list[low] < pivot);
		// 마지막 인덱스로 이동
		do
			high--;
		while (list[high] > pivot); 
		if (low < high) SWAP(list[low], list[high], temp);
	} while (low < high);

	// pivot과 경계선에 있는 값 교환
	SWAP(list[left], list[high], temp);
	return high;
}
void quick_sort(int list[], int left, int right)
{
	if (left < right) {
		int q = partition(list, left, right); 
		quick_sort(list, left, q - 1); //왼쪽부터
		quick_sort(list, q + 1, right); //오른쪽부터
	}
}

// 오름차순
int main(void)
{
	int i;
	n = MAX_SIZE;
	srand(time(NULL));
	for (i = 0; i < n; i++)      	// 난수 생성 및 출력 
		list[i] = rand() % 100;
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");

	quick_sort(list, 0, n - 1); // 퀵정렬 호출 
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}
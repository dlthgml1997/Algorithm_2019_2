// gap 만큼 떨어진 요소들을 삽입 정렬 
// 오름차순
// 정렬의 범위는 first에서 last
inc_insertion_sort(int list[], int first, int last, int gap)
{
	int i, j, key;
	// 같은 index에 해당하는 요소끼리 비교
	for (i = first + gap; i <= last; i = i + gap) { // 같은 인덱스의 한 단계 뒷 값
		key = list[i]; 
		for (j = i - gap; j >= first && key < list[j]; j = j - gap) // 같은 인덱스의 앞 값들이 크면 
			list[j + gap] = list[j]; // 뒷 값에 앞 값을 삽입
		list[j + gap] = key; // 두번째 for문을 거치지 않았다면 그대로, 거쳤다면 앞 값에 뒷 값을 삽입.
	}
}

void shell_sort(int list[], int n)   // n = list의 size
{
	int i, gap;
	for (gap = n / 2; gap > 0; gap = gap / 2) { 
		if ((gap % 2) == 0) gap++;		
		for (i = 0; i < gap; i++)		// 부분 리스트의 개수는 gap (항상 홀수)
			inc_insertion_sort(list, i, n - 1, gap);
	}
}
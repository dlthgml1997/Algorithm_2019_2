// gap ��ŭ ������ ��ҵ��� ���� ���� 
// ��������
// ������ ������ first���� last
inc_insertion_sort(int list[], int first, int last, int gap)
{
	int i, j, key;
	// ���� index�� �ش��ϴ� ��ҳ��� ��
	for (i = first + gap; i <= last; i = i + gap) { // ���� �ε����� �� �ܰ� �� ��
		key = list[i]; 
		for (j = i - gap; j >= first && key < list[j]; j = j - gap) // ���� �ε����� �� ������ ũ�� 
			list[j + gap] = list[j]; // �� ���� �� ���� ����
		list[j + gap] = key; // �ι�° for���� ��ġ�� �ʾҴٸ� �״��, ���ƴٸ� �� ���� �� ���� ����.
	}
}

void shell_sort(int list[], int n)   // n = list�� size
{
	int i, gap;
	for (gap = n / 2; gap > 0; gap = gap / 2) { 
		if ((gap % 2) == 0) gap++;		
		for (i = 0; i < gap; i++)		// �κ� ����Ʈ�� ������ gap (�׻� Ȧ��)
			inc_insertion_sort(list, i, n - 1, gap);
	}
}
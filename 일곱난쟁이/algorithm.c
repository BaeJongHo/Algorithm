#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int people[9]; //20, 7, 23, 19, 10, 15, 25, 8, 13 
	int sum = 0;
	int count = 9;
	int noDwarf1, noDwarf2;
	int dwarf[7];
	int j = 0;
	int s = 0;
	int height;

	while (1) {
		scanf("%d", &height);
		if (height < 100) {
			people[s] = height;
			s++;
		}

		if (s == 9)
			break;
	}

	//����� Ű�� ��
	for (int i = 0; i < count; i++) {
		sum += people[i];
	}

	//�θ��� ���� 100�� �Ǵ� ��ġ�� ã��
	for (int i = 0; i < count-1; i++) {
		for (int j = i+1; j < count; j++) {
			if (sum - people[i] - people[j] == 100) {
				noDwarf1 = i;
				noDwarf2 = j;
			}
		}
	}
	
	//ã�� ��ġ�� ���� �θ��� ������ ����Ʈ �ۼ�
	for (int i = 0; i < count; i++) {
		if (i != noDwarf1 && i != noDwarf2) {
			dwarf[j] = people[i];
			j++;
		}
	}
	
	int temp;
	int count1 = 7;
	//���� �������� ����Ʈ ����
	for (int i = 0; i < count1; i++) {
		for (int j = 0; j < count1 - 1; j++) {
			if (dwarf[j] > dwarf[j+1])          
			{                                 
				temp = dwarf[j];
				dwarf[j] = dwarf[j+1];
				dwarf[j + 1] = temp;
			}
		}
	}

	//���
	for (int i = 0; i < count1; i++) {
		printf("%d\n", dwarf[i]);
	}

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#define LENGTH 1000
int main() {
	//char particle[1000000];
	//�峹���n��!;,&*......�����Ÿ��A����P�_�|�ǩǪ�
	char article[LENGTH];
	char input[LENGTH];
	printf("�}�l�p��\n");
	//printf("��J�峹:\n%s\n", article);
	int count = 1, wpm, n, c = 0, r;//�p��r�ƻP���r�t��,cmp�������ܼ�,getc�ܼ�,�H���Ʀr
	FILE* fptr;
	char ch, name[30], nu;
	srand(time(NULL));
	r = rand() % 10 + 1;
	//printf("%d\n", r);
	sprintf(name, "%d.txt", r);
	fptr = fopen(name, "r");
	if (fptr != NULL)
	{
		while (fgets(article, LENGTH, fptr) != NULL)
		{
			printf("%s", article);

		}
		fclose(fptr);
		//�}�l�p��
		printf("\n");
		clock_t t1, t2;
		t1 = clock();

		//�q��LŪ�����X�Ӫ�����x�s��input�}�C
		fgets(input, LENGTH, stdin);
		//printf("%s", input);

		//�����p�ɨæC�L�X�p�ɮɶ��M
		t2 = clock();
		printf("�p�ɮɶ���:%lf\n", (t2 - t1) / (double)(CLOCKS_PER_SEC));

		//�����峹�P��J���P�B

		input[strlen(input) - 1] = '\0';
		n = strcmp(article, input);
		if (n == 0) {
			printf("�����ǰt\n");
			for (int i = 0;i <= LENGTH;i++) {
				if (article[i] == ' ') {
					count++;
				}
			}
			printf("��%d�ӳ�r", count);
			wpm = count / ((t2 - t1) / (double)(CLOCKS_PER_SEC) / 60);
			printf("wpm:%d", wpm);
		}
		else {
			printf("��J���~\n");
		}


	}

	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#define LENGTH 500

//char c = '%';
float wrongWord; //���~�r��
float typeRight;
float fileLen;


int main()
{
	static int ss = 0;
	char ch, name[30];
	char article[LENGTH];
	char input[LENGTH];
	//char particle[1000000];
	//�峹���n��!;,&*......�����Ÿ��A����P�_�|�ǩǪ�

	//printf("��J�峹:\n%s\n", article);
	int count = 1, wpm, n, c = 0, r;//�p��r�ƻP���r�t��,cmp�������ܼ�,getc�ܼ�,�H���Ʀr


	printf("�}�l�p��\n");
	FILE* fptr;
	srand(time(NULL));
	r = rand() % 10 + 1;
	sprintf(name, "%d.txt", r);
	fptr = fopen(name, "r");
	if (fptr != NULL)
	{
		while ((ch = getc(fptr)) != EOF)
		{
			printf("%c", ch);
			article[ss] = ch;
			fileLen++;
			ss++;
		}
		printf("\n");

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
		printf("\n***********************************\n");
		printf("���絲�G:\n");
		printf("�p�ɮɶ���:%lf��\n", (t2 - t1) / (double)(CLOCKS_PER_SEC));

		input[strlen(input) - 1] = '\0';
		//n = strcmp(article, input);
		//****

		//�����峹�P��J���P�B
		for (int i = 0; i <= ss; i++)
		{
			if (input[i] != article[i])
			{
				wrongWord++;
			}
		}
		typeRight = (fileLen - wrongWord + 1) / fileLen * 100;
		if (typeRight == 100)
		{
			n = 0;
		}
		else
			n = 2;
		//****
		if (n == 0)
		{
			printf("�ǰt���A:�����ǰt\n");
			for (int i = 0; i <= LENGTH; i++)
			{
				if (article[i] == ' ')
				{
					count++;
				}
			}

			printf("��r��:%d\n", count);
			wpm = count / ((t2 - t1) / (double)(CLOCKS_PER_SEC) / 60);
			printf("wpm:%d\n", wpm);
			printf("���r���T�v: %.1f", typeRight);
			//printf('%');
			printf("\n\n");
		}
		else
		{
			//printf("LENGTH: %f\n", fileLen);
			printf("�ǰt���A:��J���~\n");
			printf("���r���T�v: %.1f\n\n", typeRight);
		}

	}

	system("pause");
	return 0;
}
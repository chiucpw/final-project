#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#define LENGTH 500

//char c = '%';
float wrongWord; //錯誤字數
float typeRight;
float fileLen;


int main()
{
	static int ss = 0;
	char ch, name[30];
	char article[LENGTH];
	char input[LENGTH];
	//char particle[1000000];
	//文章不要有!;,&*......等的符號，比較判斷會怪怪的

	//printf("輸入文章:\n%s\n", article);
	int count = 1, wpm, n, c = 0, r;//計算字數與打字速度,cmp的辨識變數,getc變數,隨機數字


	printf("開始計時\n");
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

	}
	//開始計時
	printf("\n");
	clock_t t1, t2;
	t1 = clock();

	//從鍵盤讀取打出來的資料儲存到input陣列
	fgets(input, LENGTH, stdin);
	//printf("%s", input);

	//結束計時並列印出計時時間和
	t2 = clock();
	printf("\n***********************************\n");
	printf("測驗結果:\n");
	printf("計時時間為:%lf秒\n", (t2 - t1) / (double)(CLOCKS_PER_SEC));

	input[strlen(input) - 1] = '\0';
	//n = strcmp(article, input);
	//****

	//比較原文章與輸入不同處
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
		printf("匹配狀態:完全匹配\n");
		for (int i = 0; i <= LENGTH; i++)
		{
			if (article[i] == ' ')
			{
				count++;
			}
		}

		printf("單字數:%d\n", count);
		wpm = count / ((t2 - t1) / (double)(CLOCKS_PER_SEC) / 60);
		printf("wpm:%d\n", wpm);
		printf("打字正確率: %.1f", typeRight);
		//printf('%');
		printf("\n\n");
	}
	else
	{
		//printf("LENGTH: %f\n", fileLen);
		printf("匹配狀態:輸入錯誤\n");
		printf("打字正確率: %.1f\n\n", typeRight);
	}

	system("pause");
	return 0;
}

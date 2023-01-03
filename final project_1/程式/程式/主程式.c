#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#define LENGTH 1000
int main() {
	//char particle[1000000];
	//文章不要有!;,&*......等的符號，比較判斷會怪怪的
	char article[LENGTH];
	char input[LENGTH];
	printf("開始計時\n");
	//printf("輸入文章:\n%s\n", article);
	int count = 1, wpm, n, c = 0, r;//計算字數與打字速度,cmp的辨識變數,getc變數,隨機數字
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
		//開始計時
		printf("\n");
		clock_t t1, t2;
		t1 = clock();

		//從鍵盤讀取打出來的資料儲存到input陣列
		fgets(input, LENGTH, stdin);
		//printf("%s", input);

		//結束計時並列印出計時時間和
		t2 = clock();
		printf("計時時間為:%lf\n", (t2 - t1) / (double)(CLOCKS_PER_SEC));

		//比較原文章與輸入不同處

		input[strlen(input) - 1] = '\0';
		n = strcmp(article, input);
		if (n == 0) {
			printf("完全匹配\n");
			for (int i = 0;i <= LENGTH;i++) {
				if (article[i] == ' ') {
					count++;
				}
			}
			printf("有%d個單字", count);
			wpm = count / ((t2 - t1) / (double)(CLOCKS_PER_SEC) / 60);
			printf("wpm:%d", wpm);
		}
		else {
			printf("輸入錯誤\n");
		}


	}

	system("pause");
	return 0;
}
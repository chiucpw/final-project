#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define LENGTH 1000

int main()
{
	int count = 1, wpm, n, c = 0, r;
	FILE* fptr;
	char ch, name[30], nu;
	char article[LENGTH];

	srand(time(NULL));
	r = rand() % 10 + 1;
	sprintf(name, "%d.txt", r);
	fptr = fopen(name, "r");
	if (fptr != NULL)
	{
		while (fgets(article, LENGTH, fptr) != NULL)
		{
			printf("%s", article);

		}
		fclose(fptr);
	}
}

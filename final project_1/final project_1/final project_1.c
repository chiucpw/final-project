#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* fptr;
	char ch;

	fptr = fopen("article.txt", "r");
	if (fptr != NULL)
	{
		while ((ch = getc(fptr)) != EOF)
		{
			printf("%c", ch);
		}
		fclose(fptr);
	}
}

#include "stdio.h"

int read_str(FILE* fin)
{
	char buf[14][100];

	for(int i=0; i<14; i++)
	{
		fscanf(fin, "%s",buf[i]);
		printf("%d %s\n",i, buf[i]);
	}

int main()
{
	FILE* fin = fopen("task1.txt", "r");
	FILE* fout = fopen("result.txt", "w");

	for(int i=0; i<14; i++)
	{
		fscanf(fin, "%s",buf[i]);
		printf("%d %s\n",i, buf[i]);
	}

	return 0;
}

#include "stdio.h"

int main()
{
	char buf[200][100];
	FILE* fin = fopen("task1.txt", "r");
	FILE* fout = fopen("result.txt", "w");

	for(int i=0; i<200; i++)
	{
		fscanf(fin, "%s",buf[i]);
		printf("%d %s\n",i+1, buf[i]);
	}

	return 0;
}

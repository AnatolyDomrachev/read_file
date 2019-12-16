#include "stdio.h"

int main()
{
	char buf[300];
	FILE* fin = fopen("task1.txt", "r");

	for(int i=0; i<5; i++)
	{
		fgets(buf, 200, fin);
		printf("%s",buf);
	}

	do
	{
		fscanf(fin, "%154c",buf);
		buf[154] = '\0';
		printf("%s\n",buf);
	}
	while( fgets(buf, 300, fin));
	return 0;
}

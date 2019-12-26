#include "stdio.h"
#include "struct.h"

int read_str(FILE* fin)
{
	struct str sst;
	char c;
	fscanf(fin, "%c%s%d%c%Lf", &c, sst.name_s, &sst.name_n, &c, &sst.time);
	printf("%c %s %d %c %.15Lf \n", c, sst.name_s, sst.name_n, c, sst.time);
	printf("%.15Lf \n", sst.time);
	return 1;
}

int main()
{
	FILE* fin = fopen("task1.txt", "r");
	FILE* fout = fopen("result.txt", "w");
	int a = 1;

	//while(a == 1)
	//{
		a = read_str(fin);
	//}

	return 0;
}

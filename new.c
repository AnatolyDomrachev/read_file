#include "stdio.h"
#include "struct.h"

int read_str(FILE* fin)
{
	struct str sst;
	char c;
	fscanf(fin, "%c%s%d%c%Lf%c%30c", &c, sst.name_s, &sst.name_n, &c, &sst.time, &c, sst.obs );
	sst.obs[30] = '\0';
	printf("%c %s %d %c %.15Lf %c %s \n", c, sst.name_s, sst.name_n, c, sst.time, c, sst.obs );
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

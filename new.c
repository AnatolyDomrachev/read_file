#include "stdio.h"
#include "struct.h"

int read_str(FILE* fin)
{
	struct str sst;
	char c;
	fscanf(fin, "%c%s%d%c%Lf%c%30c%c%d%d%f%c%d%d%f%c%d%c%20c%c%14c%c%9c%c%d%c", &c, sst.name_s, &sst.name_n, &c, &sst.time, &c, sst.obs, &c, &sst.ra.v1, &sst.ra.v2, &sst.ra.v3, &c, &sst.de.v1, &sst.de.v2, &sst.de.v3, &c, &sst.cf, &c, sst.region, &c, sst.af, &c, sst.ff, &c, &sst.id, &c);
	sst.obs[30] = '\0';
	sst.region[20] = '\0';
	sst.af[14] = '\0';
	sst.ff[9] = '\0';
	printf("%c %s %d %c %.15Lf %c %s %c %2d %2d %2.2f %c %2d %2d %2.2f %c %d  %c %s %c %s %c %s %c %d %c \n", c, sst.name_s, sst.name_n, c, sst.time, c, sst.obs , c, sst.ra.v1, sst.ra.v2, sst.ra.v3, c, sst.de.v1, sst.de.v2, sst.de.v3, c, sst.cf, c, sst.region, c, sst.af, c, sst.ff, c, sst.id, c);
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

#include "stdio.h"
#include "struct.h"

void read_str(FILE* fin, struct str* sst)
{
	char c;
	fscanf(fin, "%c%12c%c%Lf%c%30c%c%d%d%f%c%d%d%f%c%d%c%20c%c%14c%c%9c%c%d%c", 
			&c, sst->name, &c, &sst->time, &c, sst->obs, &c, &sst->ra.v1, &sst->ra.v2, &sst->ra.v3, &c, &sst->de.v1, &sst->de.v2, &sst->de.v3, &c, &sst->cf, &c, sst->region, &c, sst->af, &c, sst->ff, &c, &sst->id, &c);
	sst->name[12] = '\0';
	sst->obs[30] = '\0';
	sst->region[20] = '\0';
	sst->af[14] = '\0';
	sst->ff[9] = '\0';
}

void print_str(struct str sst)
{
	printf("|%s|%20Lf|%s|%02d %02d %05.2f|%3d %02d %5.2f|%10d|%s|%s|%s|%4d|\n",
			sst.name, sst.time, sst.obs , sst.ra.v1, sst.ra.v2, sst.ra.v3, sst.de.v1, sst.de.v2, sst.de.v3, sst.cf, sst.region, sst.af, sst.ff, sst.id);
}
int main()
{
	char buf[300];
	struct str sst;
	FILE* fin = fopen("task1.txt", "r");
	FILE* fout = fopen("result.txt", "w");
	int a = 1;

	for(int i=0; i< 5000; i++)
	{
		fgets(buf, 200, fin);
		//printf("%s",buf);

		read_str(fin, &sst);
		print_str(sst);
	}

	return 0;
}

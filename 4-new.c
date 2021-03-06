#include "stdio.h"
#include "struct.h"

char read_str(FILE* fin, struct str* sst)
{
	char c;

	fscanf(fin, "%c", &c);
	if(c != '|')
		return c;

	fscanf(fin, "%12c%c%Lf%c%30c%c%d%d%f%c%d%d%f%c%f%c%20c%c%14c%c%9c%c%d%c", 
			sst->name, &c, &sst->time, &c, sst->obs, &c, &sst->ra.v1, &sst->ra.v2, &sst->ra.v3, &c, &sst->de.v1, &sst->de.v2, &sst->de.v3, &c, &sst->cf, &c, sst->region, &c, sst->af, &c, sst->ff, &c, &sst->id, &c);
	sst->name[12] = '\0';
	sst->obs[30] = '\0';
	sst->region[20] = '\0';
	sst->af[14] = '\0';
	sst->ff[9] = '\0';
	return c;
}

void print_str(struct str sst)
{
	printf("|%s|%21.15Lf|%s|%02d %02d %05.2f|%3d %02d %5.2f|%10.1f|%s|%s|%s|%4d|\n",
			sst.name, sst.time, sst.obs , sst.ra.v1, sst.ra.v2, sst.ra.v3, sst.de.v1, sst.de.v2, sst.de.v3, sst.cf, sst.region, sst.af, sst.ff, sst.id);
}
int main()
{
	char buf[300];
	char c;
	struct str sst;
	FILE* fin = fopen("task1.txt.def", "r");
	FILE* fout = fopen("result.txt", "w");
	int a = 1;

	for(int i=0; i<5; i++)
	{
		fgets(buf, 200, fin);
		printf("%s", buf);
	}

	while(!feof(fin))
	{
			c = read_str(fin, &sst);
			if(c == '|')
			{
				print_str(sst);
				fgets(buf, 200, fin);
			}
			else
			{
				fgets(buf, 200, fin);
				printf("%c%s",c, buf);
			}
	}


	return 0;
}

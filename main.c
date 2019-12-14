#include "stdio.h"

struct s_data
{
	int NAME;
	double TIME;
	char OBSERVATORY[40];
	int _RA2000[4];
	int _DECL2000[4];
	int COORD_FLAG;
	char REGION[20];
	char AFTERGLOW_FLAG;
	char FLUX_FLAG;
	int ID;
};

int main()
{
	struct s_data data;
	FILE* fin = fopen("task1.txt", "r");

	char buf[300];

	do
	{
		fscanf(fin, "%154c",buf);
		buf[154] = '\0';
		printf("%s\n",buf);
	}
	while( fgets(buf, 300, fin));
	return 0;
}

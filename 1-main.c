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

	while(1)
	{
		fscanf(fin, "|   GRB %x|%lf|%30c|%d %d %d.%d| %d %d %d.%d|        %d|%20c|             %c|        %c|   %d|",
			&data.NAME, &data.TIME, data.OBSERVATORY,
			&data._RA2000[0],&data._RA2000[1],&data._RA2000[2],&data._RA2000[3] , 
			&data._DECL2000[0],&data._DECL2000[1],&data._DECL2000[2],&data._DECL2000[3] , 
			&data.COORD_FLAG, data.REGION, &data.AFTERGLOW_FLAG, &data.FLUX_FLAG, &data.ID);
		printf("|   GRB %x|%lf|%s|%d %d %d.%d| %d %d %d.%d|%d|%s|%c|%c|%d|\n",
			data.NAME, data.TIME, data.OBSERVATORY,
			data._RA2000[0],data._RA2000[1],data._RA2000[2],data._RA2000[3] , 
			data._DECL2000[0],data._DECL2000[1],data._DECL2000[2],data._DECL2000[3] , 
			data.COORD_FLAG, data.REGION, data.AFTERGLOW_FLAG, data.FLUX_FLAG, data.ID);
		fgets(buf, 300, fin);
	}
	return 0;
}

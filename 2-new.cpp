#include <iostream> 
#include <fstream> 
#include "stdio.h"

struct rade
{
	int v1;
	int v2;
	float v3;
};
 
struct str
{
	char name_s[20];    
	int name_n;    
	long double time;         
	char obs[40];
	struct rade ra;
	struct rade de;
	float cf;
	char region[30];
	char af[20];
	char ff[10];
	int id ;
};

using  namespace  std;

char read_str(FILE* fin, struct str* sst)
{
	char c;

	fscanf(fin, "%c", &c);
	if(c != '|')
		return c;

	fscanf(fin, "%s%X%c%Lf%c%30c%c%d%d%f%c%d%d%f%c%f%c%20c%c%14c%c%9c%c%d%c", 
			sst->name_s, &sst->name_n, &c, &sst->time, &c, sst->obs, &c, &sst->ra.v1, &sst->ra.v2, &sst->ra.v3, &c, &sst->de.v1, &sst->de.v2, &sst->de.v3, &c, &sst->cf, &c, sst->region, &c, sst->af, &c, sst->ff, &c, &sst->id, &c);
	sst->obs[30] = '\0';
	sst->region[20] = '\0';
	sst->af[14] = '\0';
	sst->ff[9] = '\0';
	return c;
}

void print_str(ofstream&  outfile, struct str sst)
{
	outfile << "| " << sst.name_s << " ";
	outfile.width(7);
	outfile << hex << uppercase << sst.name_n;
	outfile << "|";
	outfile.precision(15);
	outfile.width(21);
	outfile.fill('0');
	outfile << sst.time;
	outfile << "|" << sst.obs;
	outfile << "|";
	outfile.width(2);
	outfile.fill('0');
        outfile << dec << sst.ra.v1 << " ";
	outfile.width(2);
	outfile.fill('0');
        outfile << sst.ra.v2 << " ";
	outfile.width(5);
	outfile.precision(2);
	outfile.fill('0');
        outfile << sst.ra.v3;
	outfile << "|";
	outfile.width(3);
	outfile.fill(' ');
	outfile << sst.de.v1 << " ";
	outfile.width(2);
	outfile.fill('0');
        outfile << sst.de.v2 << " ";
	outfile.width(5);
	outfile.precision(2);
	outfile.fill('0');
        outfile << sst.de.v3;
	outfile << "|";
	outfile.width(10);
	outfile.precision(1);
	outfile.fill(' ');
	outfile << sst.cf;
	outfile << "|";
	outfile.width(20);
	outfile << sst.region;
	outfile << "|";
	outfile.width(14);
	outfile << sst.af;
	outfile << "|";
	outfile.width(9);
	outfile << sst.ff;
	outfile << "|";
	outfile.width(4);
	outfile << sst.id;
	outfile << "|";
	outfile << endl;
}


int main()
{
	char buf[300];
	char c;
	struct str sst;
	FILE* fin = fopen("task1.txt", "r");
	ofstream  outfile  ("result.txt");
	int a = 1;

	for(int i=0; i<5; i++)
	{
		fgets(buf, 200, fin);
		outfile << buf;
	}

	while(!feof(fin))
	{
			c = read_str(fin, &sst);
			if(c == '|')
				print_str(outfile, sst);
			else
			{
				fgets(buf, 200, fin);
				break;
			}
			fgets(buf, 200, fin);
	}
	outfile << c << buf;
	fclose(fin);
	outfile.close();
	return 0;
}

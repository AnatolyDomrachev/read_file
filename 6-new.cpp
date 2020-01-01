#include <iostream> 
#include <fstream> 
//#include <iomanip>

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

char read_str(ifstream*  infile, struct str* sst)
{
	char c;
	*infile >> c;
	*infile >> sst->name_s;
	*infile >> hex >> sst->name_n;
	*infile >> c;
	*infile >> sst->time;
	*infile >> c;
	infile->read(sst->obs, 30);
	sst->obs[30] = '\0';
	*infile >> c;
	*infile >> sst->ra.v1;
	*infile >> c;
	*infile >> sst->ra.v2;
	*infile >> c;
	*infile >> sst->ra.v3;
	*infile >> c;
	*infile >> sst->de.v1;
	*infile >> c;
	*infile >> sst->de.v2;
	*infile >> c;
	*infile >> sst->de.v3;
	*infile >> c;
	*infile >> sst->cf;
	*infile >> c;
	infile->read(sst->region, 20);
	sst->region[20] = '\0';
	*infile >> c;
	infile->read(sst->af, 14);
	sst->af[14] = '\0';
	*infile >> c;
	infile->read(sst->ff, 9);
	sst->ff[9] = '\0';
	*infile >> c;
	*infile >> sst->id;
}


int main()
{
	struct str sst;
	ifstream  infile  ("task1.txt.new");
	char c;
	ofstream  outfile  ("result.txt");

	read_str(&infile, &sst);
	print_str(sst, fout);

	cout << "| " << sst.name_s << " ";
	cout.width(7);
	cout << hex << uppercase << sst.name_n;
	cout.precision(20);
	cout << "|" << sst.time;
	cout << "|" << sst.obs;
	cout << "|";
	cout.width(2);
	cout.fill('0');
        cout << sst.ra.v1 << " ";
	cout.width(2);
	cout.fill('0');
        cout << sst.ra.v2 << " ";
	cout.width(5);
	cout.precision(2);
	std::cout.setf(std::ios::fixed);
	cout.fill('0');
        cout << sst.ra.v3;
	cout << "| ";
	cout.width(2);
	cout.fill('0');
	cout << sst.de.v1 << " ";
	cout.width(2);
	cout.fill('0');
        cout << sst.de.v2 << " ";
	cout.width(5);
	cout.precision(2);
	cout.fill('0');
        cout << sst.de.v3;
	cout << "|";
	cout.width(10);
	cout.precision(1);
	cout.fill(' ');
	cout << sst.cf;
	cout << "|";
	cout.width(20);
	cout << sst.region;
	cout << "|";
	cout.width(14);
	cout << sst.af;
	cout << "|";
	cout.width(9);
	cout << sst.ff;
	cout << "|";
	cout.width(4);
	cout << sst.id;
	cout << "|";

	cout << endl;
	return 0;
}


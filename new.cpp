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

int main()
{
	struct str sst;
	ifstream  infile  ("task1.txt.new");
	char c;
	ofstream  outfile  ("result.txt");

	infile >> c;
	infile >> sst.name_s;
	infile >> hex >> sst.name_n;
	infile >> c;
	infile >> sst.time;

	cout << "| " << sst.name_s << " ";
	cout.width(7);
	cout << hex << uppercase << sst.name_n;
	cout.precision(20);
	cout << "|" << sst.time;
	cout << endl;
	return 0;
}


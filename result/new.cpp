#include <iostream> 
#include <fstream> 

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

char read_str(ifstream&  infile, struct str* sst)
{
	char c;
	string s; 

	infile >> sst->name_s;
	infile >> hex >> sst->name_n;
	infile >> c;
	infile >> sst->time;
	infile >> c;
	infile.read(sst->obs, 30);
	sst->obs[30] = '\0';
	infile >> c;
	infile >> dec >> sst->ra.v1;
	infile >> c;
	infile >> sst->ra.v2;
	infile >> c;
	infile >> sst->ra.v3;
	infile >> c;
	infile >> sst->de.v1;
	infile >> c;
	infile >> sst->de.v2;
	infile >> c;
	infile >> sst->de.v3;
	infile >> c;
	infile >> sst->cf;
	infile >> c;
	infile.read(sst->region, 20);
	sst->region[20] = '\0';
	infile >> c;
	infile.read(sst->af, 14);
	sst->af[14] = '\0';
	infile >> c;
	infile.read(sst->ff, 9);
	sst->ff[9] = '\0';
	infile >> c;
	infile >> sst->id;
	getline(infile, s);
}

char print_str(ofstream&  outfile, struct str sst)
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

// сложить числа из столбца TIME, например 2 и 10 число
double sum_2_10(char* fname)
{
	struct str sst;
	string s;
	char c;
	ifstream  infile  (fname);

	for(int i=0; i<5; i++)
		getline(infile, s);

	long double sum = 0;         

	for(int i=1; i<11;i++)
	{
		infile >> c;
		read_str(infile, &sst);
		if(i==2 || i==10)
			sum += sst.time;
	}

	infile.close();
	return sum;
}




int main()
{
	struct str sst;
	char c;
	string s;

	// сложить числа из столбца TIME, например 2 и 10 число
	long double sum;         
	sum = sum_2_10("task1.txt");
	cout.precision(15);
	cout << "Сумма 2 и 10 = " << sum << endl;
	// Конец


	ifstream  infile  ("task1.txt");
	ofstream  outfile  ("result.txt");

	outfile.setf(ios::fixed);

	for(int i=0; i<5; i++)
	{
		getline(infile, s);
		outfile << s << endl;
	}

	while(!infile.eof())
	{
		infile >> c;
		if(c == '|')
		{
			read_str(infile, &sst);
			print_str(outfile, sst);
		}
		else
		{
			getline(infile, s);
			break;
		}
	}

	outfile << c << s << endl;
	infile.close();
	outfile.close();
	return 0;
}


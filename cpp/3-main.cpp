#include <iostream> 
#include <fstream> 
#include <iomanip>

using  namespace  std;

int main()
{
	string arr[20];
	int bytes[20];
	int spaces[20];
	int num;
	long int seek = 0;
	long int begin;
	int start;
	string str;
	ifstream  infile  ("task1.txt");
	ofstream  outfile  ("result.txt");

	for(int i=0; i<5; i++)
	{
		getline(infile, str);
		outfile << str << endl;
	}

	start = infile.tellg();

	while(!infile.eof())
	{
		num = 0;
		infile.seekg(seek*156 + start , ios_base::beg); 

		begin = infile.tellg();
		//num = 0;
		while(1)
		{
			infile >> arr[num];
			bytes[num] = infile.tellg();
			num++;
			if(infile.tellg() > begin + 153)
			{
				getline(infile, str);
				break;
			}
		}

		spaces[0] = 1;
		for(int i=0; i<num; i++)
			spaces[i+1] = bytes[i+1] -  bytes[i];
		
		for(int i=0; i<num; i++)
			outfile << setw(spaces[i]) << arr[i];

		outfile << endl;
		seek++;
	}

	return 0;
}



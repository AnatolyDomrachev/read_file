#include <iostream> 
#include <fstream> 
#include <iomanip>

using  namespace  std;

int main()
{
	ifstream  file  ("task1.txt");
	char arr[20][100];
	int bytes[20];
	int spaces[20];
	int num;
	int line = 1;
	long int seek = 0;
	long int begin;

	while(!file.eof())
	{
		if(seek != 0)
			file.seekg(seek*154,ios_base::beg); 

		begin = file.tellg();
		//num = 0;
		do
		{
			file >> arr[num];
			bytes[num] = file.tellg();
			num++;
		}
		while(file.tellg() < begin + 154);

		cout << endl;
		spaces[0] = 1;
		for(int i=0; i<num; i++)
			spaces[i+1] = bytes[i+1] -  bytes[i];
		
		cout << endl;
		for(int i=0; i<=num; i++)
			cout << setw(spaces[i]) << arr[i];

		line++;
		seek++;
	}

	return 0;
}



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
		num = 0;
		do
		{
			file >> arr[num];
			bytes[num] = file.tellg();
			num++;
		}
		while(file.tellg() < 154*line);

		cout << endl;
		spaces[0] = 1;
		for(int i=0; i<num; i++)
			spaces[i+1] = bytes[i+1] -  bytes[i];
		
		cout << endl;
		for(int i=0; i<=num; i++)
			cout << setw(spaces[i]) << arr[i];

		line++;
	}

	return 0;
}



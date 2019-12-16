#include <iostream> 
#include <fstream> 
#include <iomanip>

using  namespace  std;

int main()
{
	ifstream  file  ("task1.txt");
	char arr[15][100];
	int bytes[15];
	int spaces[15];

	while(!file.eof())
	{
		for(int i=0; i<14; i++)
		{
			file >> arr[i];
			bytes[i] = file.tellg();
		}

		cout << endl;
		spaces[0] = 1;
		for(int i=0; i<13; i++)
			spaces[i+1] = bytes[i+1] -  bytes[i];
		
		cout << endl;
		for(int i=0; i<14; i++)
			cout << setw(spaces[i]) << arr[i];
	}

	return 0;
}



#include <iostream> 
#include <fstream> 
#include <iomanip>

using  namespace  std;

int main()
{
	ifstream  file  ("task1.txt");
	string arr[20];
	int bytes[20];
	int spaces[20];
	int num;
	int line = 1;
	long int seek = 0;
	long int begin;
	string str;

	while(!file.eof())
	{
		num = 0;
		file.seekg(seek*156,ios_base::beg); 

		begin = file.tellg();
		//num = 0;
		while(1)
		{
			file >> arr[num];
			bytes[num] = file.tellg();
			num++;
			if(file.tellg() > begin + 153)
			{
				getline(file, str);
				break;
			}
		}

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



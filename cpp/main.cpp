#include <iostream> 
#include <fstream> 
#include <iomanip>

using  namespace  std;

int main()
{
	ifstream  file  ("task1.txt");
	char arr[15][100];

	for(int i=0; i<15; i++)
		file >> arr[i];

	for(int i=0; i<15; i++)
		cout << arr[i];

	//cout << setw(20) << "Hello there.";
	cout << setw(20) << "Hello there.";
	return 0;
}


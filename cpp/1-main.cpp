#include <iostream> 
#include <fstream> 
using  namespace  std;

struct s_data
{
	char NAME[50];
	char TIME[50];
	char OBSERVATORY[50];
	char _RA2000[50];
	char _DECL2000[50];
	char COORD_FLAG[50];
	char REGION[50];
	char AFTERGLOW_FLAG[50];
	char FLUX_FLAG[50];
	char ID[50];
};

int  main() 
{  
	struct s_data data;
	char s[100];
	ifstream  file  ("task1.txt");
	if  (file.is_open())  // вызов метода is_open()  
		cout  <<  "Все ОК! Файл открыт!\n\n"  << endl;
	else 
	{  
		cout  <<  "Файл не открыт!\n\n"  <<  endl;
		return  -1;
	} 

	while(!file.eof())                  
	{
		file >> data.NAME;
		file >> data.TIME;
		file >> data.OBSERVATORY;
		file >> data._RA2000[0];
		file >> data._RA2000[1];
		file >> data._RA2000[2];
		file >> data._RA2000[3] ;
		file >> data._DECL2000[0];
		file >> data._DECL2000[1];
		file >> data._DECL2000[2];
		file >> data._DECL2000[3] ;
		file >> data.COORD_FLAG;
		file >> data.REGION;
		file >> data.AFTERGLOW_FLAG;
		file >> data.FLUX_FLAG;
		file >> data.ID;
	}
	return 0;
}



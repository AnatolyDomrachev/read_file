#include <iostream> 
#include <fstream> 
using  namespace  std;

struct s_data
{
	int NAME;
	double TIME;
	char OBSERVATORY[40];
	int _RA2000[4];
	int _DECL2000[4];
	int COORD_FLAG;
	char REGION[30];
	char AFTERGLOW_FLAG;
	char FLUX_FLAG;
	int ID;
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



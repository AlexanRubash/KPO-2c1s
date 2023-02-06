#include <iostream>
#include <fstream>

using namespace std;

//meta-data
#define WCHAR_T_FLAG 1		
#define INT_FLAG 2


int main()
{	
	//������ ��� ������
	int first = 2556;										
	wchar_t second = L'�';
	int third = -1;
	int fourth = 2147483647;
	wchar_t fifth = L'\n';

	//������ � ����
	ofstream tfile("serializationdata.txt", ios::binary);

	tfile << INT_FLAG;
	tfile.write((char *)&first, sizeof(int));

	tfile << WCHAR_T_FLAG;
	tfile.write((char*)&second, sizeof(wchar_t));

	tfile << INT_FLAG;
	tfile.write((char*)&third, sizeof(int));

	tfile << INT_FLAG;
	tfile.write((char*)&fourth, sizeof(int));

	tfile << WCHAR_T_FLAG;
	tfile.write((char*)&fifth, sizeof(wchar_t));



	tfile.close();
}
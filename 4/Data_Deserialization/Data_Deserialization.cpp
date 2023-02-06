#include <iostream>
#include <fstream>

using namespace std;

//meta-data
#define WCHAR_T_FLAG 1		

#define INT_FLAG 2

#define HEADER ".586\n.MODEL FLAT, STDCALL\nincludelib kernel32.lib\nExitProcess PROTO : DWORD\n.STACK 4096\n.CONST\n.DATA\n\n"

#define FOOTER "\n\n.CODE\nmain PROC\nSTART :\npush - 1\ncall ExitProcess\nmain ENDP\nend main\n"

int main()
{
	ifstream ffile("C:/Users/rubas/Desktop/Универ/2-1/kpo/4/Lab_4/serializationdata.txt");

	ofstream tfile("C:/Users/rubas/Desktop/Универ/2-1/kpo/4/Manifesto_Deserializaton/Manifesto_Deserializaton.asm");

	int Int_buffer;
	wchar_t Wchar_t_buffer;

	char Flag_buffer;

	if (ffile.is_open())
	{
		tfile << HEADER;

		ffile.read((char*)&Flag_buffer, 1);
		for (int Int_count = 0, Wchar_t_count = 0, Int_arr = 0; !ffile.eof(); ) 
		{			
			if (Flag_buffer == INT_FLAG)
			{
				tfile << "Int";
				tfile << Int_count;
				++Int_count;
				tfile << " SDWORD ";
				
				ffile.read((char*)&Int_buffer, sizeof(int));
				tfile << Int_buffer;
				tfile << '\n';
			}
			else if (Flag_buffer == WCHAR_T_FLAG)
			{
				tfile << "Wchar_t";
				tfile << Wchar_t_count;
				++Wchar_t_count;
				tfile << " WORD ";

				ffile.read((char*)&Wchar_t_buffer, sizeof(wchar_t));
				tfile << Wchar_t_buffer;
				tfile << '\n';
			}

			ffile.read((char*)&Flag_buffer, 1);
		}

		tfile << FOOTER;
	}
	else
	{
		cout << "Open error!!!";
	}

	ffile.close();
	tfile.close();
}
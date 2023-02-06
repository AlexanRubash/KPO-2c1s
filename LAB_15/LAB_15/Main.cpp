#include <wchar.h>
#include "Error.h"
#include "Parm.h"
#include "In.h"
#include "In.h"
#include "Log.h"
#include "Out.h"

#include <tchar.h>
using namespace Error;

//#define TEST_ERROR
//#define TEST_GETPARM
//#define TEST_GETIN
//#define TEST_LOG
#define TEST_OUT

#ifdef TEST_ERROR

////////////////////////////////////////////////// TEST ERROR ///////////////////////////////////////////
int main()
{
	setlocale(0, "rus");
	//out.open("protocol_Error.txt");
	
	cout << "---���� Error::geterror---" << endl << endl;
	try { throw ERROR_THROW(100); }
	catch (ERROR e)
	{
		cout << "������ " << e.id << ": " << e.message << endl << endl;

		//out<< "������ " << e.id << ": " << e.message << endl << endl;
	}

	cout << "---���� Error::geterrorin---" << endl << endl;
	//out<< "---���� Error::geterrorin---" << endl << endl;

	try { throw ERROR_THROW_IN(111, 7, 7); }
	catch (ERROR e)
	{
		cout << "������ " << e.id << ": " << e.message
			<< ", ������ " << e.inext.line
			<< ", ������� " << e.inext.col << endl << endl;

		/*out << "������ " << e.id << ": " << e.message
			<< ", ������ " << e.inext.line
			<< ", ������� " << e.inext.col << endl << endl;*/
	}


}
////////////////////////////////////////////////// TEST ERROR ///////////////////////////////////////////

#endif // TEST_ERROR



#ifdef TEST_GETPARM

////////////////////////////////////////////////// TEST GETPARM ///////////////////////////////////////////
int wmain(int argc, _TCHAR* argv[])
{
	setlocale(0, "rus");
	//out.open("protocol_Parm.txt");

	cout << "--- ���� Parm::getparm ---" << endl << endl;
	out<< "--- ���� Parm::getparm ---" << endl << endl;
	
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		wcout << "-in:" << parm.in << ", -out:" << parm.out << ", -log:" << parm.log << endl << endl;

		//out << "-in:" << fwrite(parm.in, 2 ,sizeof(parm.in)/2, "protocol_Parm.txt")  << ", -out:" << parm.out << ", -log:" << parm.log << endl << endl;
	}
	catch (Error::ERROR e)
	{
		cout << "������ " << e.id << ": " << e.message << endl << endl;

		//out << "������ " << e.id << ": " << e.message << endl << endl;
	}

	return 0;
}
////////////////////////////////////////////////// TEST GETPARM ///////////////////////////////////////////

#endif // TEST_GETPARM



#ifdef TEST_GETIN

////////////////////////////////////////////////// TEST GETIN /////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	cout << "----  ���� In::getin  ----" << endl << endl;
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		In::IN in = In::getin(parm.in);
		cout << in.text << endl;
		cout << "����� ��������: " << in.size << endl;
		cout << "����� �����: " << in.lines << endl;
		cout << "���������: " << in.ignor << endl;
	}
	catch (Error::ERROR e)
	{
		cout << "������ " << e.id << ": " << e.message << endl;
		cout << "������ " << e.inext.line << " ������� " << e.inext.col << endl << endl;
	}
	catch (...)
	{
		cout << "���� ����!!!";
	}
	
}
////////////////////////////////////////////////// TEST GETIN /////////////////////////////////////////////

#endif // TEST_GETIN



#ifdef TEST_LOG

////////////////////////////////////////////////// TEST LOG ///////////////////////////////////////////////
int wmain(int argc, _TCHAR* argv[])
{
	Log::LOG log = Log::INITLOG;
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		In::IN in = In::getin(parm.in);

		log = Log::getlog(parm.log);
		Log::WriteLine(log, (char*)"����:", (char*)" ��� ������ \n", "");
		Log::WriteLine(log, (wchar_t*)L"����:", (wchar_t*)L" ��� ������ \n", L"");
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		
		Log::WriteIn(log, in);
		Log::Close(log);


		/*Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getlog(parm.log);
		Log::WriteLine(log, (char*)"����:", (char*)" ��� ������ \n", "");
		Log::WriteLine(log, (wchar_t*)L"����:", (wchar_t*)L" ��� ������ \n", L"");
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		In::IN in = In::getin(parm.in);
		Log::WriteIn(log, in);
		Log::Close(log);*/

	}
	catch (Error::ERROR e)
	{
		Log::WriteError(log, e);
	}
}
////////////////////////////////////////////////// TEST LOG ///////////////////////////////////////////////

#endif // TEST_LOG

////////////////////////////////////////////////// TEST OUT ///////////////////////////////////////////////
#ifdef TEST_OUT

int wmain(int argc, _TCHAR* argv[])
{
	Out::OUT out = Out::INITOUT;
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		In::IN in = In::getin(parm.in);

		out = Out::getout(parm.out);
		
		Out::WriteOut(out, in);
		Out::Close(out);
	}
	catch (Error::ERROR e)
	{
		Out::WriteError(out, e);
	}
}

#endif // TEST_OUT
////////////////////////////////////////////////// TEST OUT ///////////////////////////////////////////////
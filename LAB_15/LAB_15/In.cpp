#include <iostream>
#include <fstream>

#include "Error.h"
#include "In.h"

using namespace std;

namespace In
{
	IN getin(wchar_t* infile)
	{
		IN val{ 0,0,0,nullptr,IN_CODE_TABLE };

		val.text = new unsigned char[IN_MAX_LEN_TEXT];

		unsigned char uch;

		ifstream fin;
		fin.open(infile);

		if (!fin.is_open())throw ERROR_THROW(110);

		while ((uch = fin.get()) && (!fin.eof()))
		{
			switch (val.code[uch])
			{

			case IN::F:
			{
				throw ERROR_THROW_IN(111, val.lines, ++val.size + val.ignor); //лайн = T+I+1
				continue;
			}

			case IN::T:
			{
				val.text[val.size++] = uch;

				if (uch == IN_CODE_ENDL) val.lines++;

				continue;
			}

			case IN::I:
			{
				val.ignor++;
				continue;
			}

			case '|': /*'-'*/
			{
				val.text[val.size++] = '|' /*'-'*/;

				if (uch == IN_CODE_ENDL) val.lines++;

				continue;
			}

			}

		}

		if (val.size == 0) throw exception();

		else val.text[val.size++] = '\0';
		val.size += val.ignor - 1; //итоговвый размер - T+I-1('\0')

		fin.close();
		return val;
	}

}



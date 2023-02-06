#include <iostream>
#include <fstream>

#include "Error.h"
#include "In.h"

using namespace std;

namespace In
{
	IN getin(wchar_t* infile)
	{
		In::IN val{0,0};

		unsigned char uch;
		bool lexemeFlag = false;
		bool spaceFlag = false;

		ifstream fin;
		fin.open(infile);

		if (!fin.is_open())throw ERROR_THROW(110);

		while ((uch = fin.get()) && (!fin.eof()))
		{
			switch (val.code[uch])
			{
				case IN::F:
				{
					throw ERROR_THROW_IN(111, val.lines, (int)(val.text.size()+1) + val.ignor);
					continue;
				}

				case IN::T:
				{
					if (uch == '\n') val.lines++;
					val.text.push_back(uch);
					spaceFlag = false;
					continue;
				}

				//////////////////////////////////////////////////
				case IN::D:
				{
					val.text.push_back(uch);
					spaceFlag = false;
					continue;
				}
				//////////////////////////////////////////////////

				case IN::L:
				{
					val.text.push_back(uch);
					lexemeFlag = !lexemeFlag;
					continue;
				}

				case IN::S:
				{
					if (spaceFlag)
					{
						if (lexemeFlag)
						{
							val.text.push_back(uch);
							continue;
						}

						++val.ignor;
						continue;
					}

					val.text.push_back(uch);
					spaceFlag = true;
					continue;
				}
			}
		}

		val.size = val.text.size();

		string strD = "(){}*+,-/<=>;";
		
		//��������� "��������" - �������� �����
		for (size_t i = 0; i < val.text.size(); i++)
		{
			if (strD.find(val.text[i]) != -1) 
			{
				if (i != 0 && val.text[i - 1] == ' ')
				{
					val.text.erase(i - 1, 1);
					++val.ignor;
					--i;
				}

				if (val.text[i + 1] == ' ')
				{
					val.text.erase(i + 1, 1);
					++val.ignor;
				}

				
			}
		}

		spaceFlag = false;
		val.spaceLexeme = val.text;
		strD.push_back('\n');
		for (size_t i = 0; i < val.spaceLexeme.size(); i++)
		{
			if (strD.find(val.spaceLexeme[i]) != -1)
			{
				bool next = false;
				bool previous = false;

				if (val.spaceLexeme[i + 1] != '$')
				{
					val.spaceLexeme.insert(i + 1, "$");
					next = true;
				}

				if (val.spaceLexeme[i - 1] != '$')
				{
					val.spaceLexeme.insert(i, "$");
					previous = true;
				}

				if (next && previous) i += 2;
				else ++i;
			}

			else if (val.spaceLexeme[i] == '\'') spaceFlag = !spaceFlag;
			else if ((val.spaceLexeme[i] == ' ') && !spaceFlag) val.spaceLexeme[i] = '$';
		}
		
		fin.close();
		return val;
	}

}
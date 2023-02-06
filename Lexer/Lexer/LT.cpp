#include "LT.h"
#include <fstream>


namespace LT
{
	LexTable Create(int size)
	{
		if (size > LT_MAXSIZE) throw ERROR_THROW(105);
		LexTable tableLex;
		tableLex.table = new Entry[size];
		tableLex.maxsize = size;
		tableLex.size = NULL;
		return tableLex;
	}

	void Add(LexTable& lextable, Entry entry)
	{
		if (lextable.size >= lextable.maxsize) throw ERROR_THROW(106);
		lextable.table[lextable.size++] = entry;
	}

	Entry GetEntry(LexTable& lextable, int n)
	{
		if (n > lextable.maxsize)
		{
			throw ERROR_THROW(117)
		}
		return lextable.table[n];
	}

	void PrintLexTable(const wchar_t* in, LexTable& lextable)
	{
		std::ofstream* lex_stream = new std::ofstream;
		lex_stream->open(in);
		(*lex_stream) << "--------- Таблица лексем(красивая) ---------";

		if (lex_stream->is_open())
		{
			size_t str_numb = 0;
			for (size_t i = 0; i < lextable.size; i++)
			{
				(*lex_stream) << '\n' << lextable.table[i].sn << ".\t";
				
				if (str_numb != lextable.table[i + 1].sn)
				{
					++str_numb;

					if (lextable.table[i].idxTI == LT_TI_NULLIDX)
						(*lex_stream) << lextable.table[i].lexema;
					else 
						(*lex_stream)<<" "<< lextable.table[i].lexema << "_" << lextable.table[i].idxTI<<" ";
					
					continue;
				}

				for (; str_numb == lextable.table[i].sn; i++)
				{
					if (lextable.table[i].idxTI == LT_TI_NULLIDX)
						(*lex_stream) << lextable.table[i].lexema;
					else
						(*lex_stream)<<" "<< lextable.table[i].lexema << "_" << lextable.table[i].idxTI << " ";
				}

				++str_numb;
				--i;
			}

			(*lex_stream) << "\n\n--------- Таблица лексем(полная) ---------\n";

			for (size_t i = 0; i < lextable.size; i++)
			{
				(*lex_stream) << i << ".\t";
				(*lex_stream) << "сокращенная лексема" << "\t" << "номер строки" << "\t" << "индекс в ТИ" << "\t" << "лексема" << std::endl;
				(*lex_stream) << "\t" << lextable.table[i].lexema << "\t\t\t";
				(*lex_stream) << lextable.table[i].sn << "\t\t";
				(*lex_stream) << lextable.table[i].idxTI << "\t\t";
				(*lex_stream) << lextable.table[i].tekst;

				(*lex_stream) << std::endl << std::endl;
			}
		}
		else
			throw ERROR_THROW(128);
		lex_stream->close();
		delete lex_stream;
	}

	void Delete(LexTable& lextable)
	{
		delete[] lextable.table;
	}
}
#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "Error.h"

#define LEXEMA_FIXSIZE 1				// фиксироваyный размер лексемы
#define LT_MAXSIZE 4096					// максимальное количество строк в таблице лексем
#define LT_TI_NULLIDX 0xffffffff		// нет элемента таблицы идентификатора
#define LEX_INTEGER 't'					// лексема для integer
#define LEX_STRING 't'					// лексема для string
#define LEX_ID 'i'						// лексема для идентификатора
#define LEX_LITERAL 'l'					// лексема для литерала
#define LEX_FUNCTION 'f'				// лексема для function
#define LEX_DECLARE 'd'					// лексема для declare
#define LEX_RETURN 'r'					// лексема для return
#define LEX_PRINT 'p'					// лексема для print
#define LEX_SEMICOLON ';'				
#define LEX_COMMA ','
#define LEX_LEFTBRACE '{'
#define LEX_BRACELET '}'
#define LEX_LEFTHESIS '('
#define LEX_RIGHTHESIS ')'
#define LEX_PLUS 'v'					// +
#define LEX_MINUS 'v'					// -
#define LEX_STAR 'v'					// *
#define LEX_DIRSLASH 'v'				// /
#define LEX_EQUALS '='					// =
#define LEX_COMMAND_COMPLETION ';'		// ;
//#define LEX_MAIN 'm'					// main

namespace LT {					// ТЛ	

	struct Entry					 // строка ТЛ
	{
		char lexema;		// лексема
		int sn;								// номер строки в исходном тексте
		int idxTI;							// индекс в ТИ или LT_TI_NULLIDX

		std::string tekst;

		Entry(unsigned char lexema, int sn, int idxTI, std::string tekst)
		{
			this->lexema = lexema;
			this->sn = sn;
			this->idxTI = idxTI;
			this->tekst = tekst;
		}

		Entry()
		{
			lexema = '?';
			sn = 0;
			idxTI = -228;
			tekst = "-";
		}
	};
	
	struct LexTable					  // экземпляр ТЛ
	{
		int maxsize; // емкость таблицы лексем < LT_MAXSIZE
		int size; // текущий размер таблицы лексем < maxsize
		Entry* table; // массив строк таблицы лексем
	};

	LexTable Create(int size); // создать таблицы лексем

	void Add(LexTable& lextable, Entry entry); // добавить строку в таблицу лексем

	Entry GetEntry(LexTable& lextable, int n); // получить строку из таблицы лексем

	void PrintLexTable(const wchar_t* in, LexTable& lextable);

	void Delete(LexTable& lextable); // удалить таблицу лексем(освободить память)

};

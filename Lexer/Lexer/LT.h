#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "Error.h"

#define LEXEMA_FIXSIZE 1				// ���������y��� ������ �������
#define LT_MAXSIZE 4096					// ������������ ���������� ����� � ������� ������
#define LT_TI_NULLIDX 0xffffffff		// ��� �������� ������� ��������������
#define LEX_INTEGER 't'					// ������� ��� integer
#define LEX_STRING 't'					// ������� ��� string
#define LEX_ID 'i'						// ������� ��� ��������������
#define LEX_LITERAL 'l'					// ������� ��� ��������
#define LEX_FUNCTION 'f'				// ������� ��� function
#define LEX_DECLARE 'd'					// ������� ��� declare
#define LEX_RETURN 'r'					// ������� ��� return
#define LEX_PRINT 'p'					// ������� ��� print
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

namespace LT {					// ��	

	struct Entry					 // ������ ��
	{
		char lexema;		// �������
		int sn;								// ����� ������ � �������� ������
		int idxTI;							// ������ � �� ��� LT_TI_NULLIDX

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
	
	struct LexTable					  // ��������� ��
	{
		int maxsize; // ������� ������� ������ < LT_MAXSIZE
		int size; // ������� ������ ������� ������ < maxsize
		Entry* table; // ������ ����� ������� ������
	};

	LexTable Create(int size); // ������� ������� ������

	void Add(LexTable& lextable, Entry entry); // �������� ������ � ������� ������

	Entry GetEntry(LexTable& lextable, int n); // �������� ������ �� ������� ������

	void PrintLexTable(const wchar_t* in, LexTable& lextable);

	void Delete(LexTable& lextable); // ������� ������� ������(���������� ������)

};

#pragma once

#include "FST.h"
#include <stack>

namespace LexAnalys
{
	struct LT_IT_Tables
	{
		LT::LexTable lexTable;
		IT::IdTable idTable;
	};

	LT_IT_Tables GetTables(In::IN in, size_t ltSize, size_t itSize);

	vector<string> SeparateLexeme(string lexemes);

	struct regularExpression
	{
		short transitionsNumber;
		FST::NODE* nodes;
		char lexemeName;

		regularExpression(char lN, short tN, FST::NODE n, ...);
	};

	char GetLexemeName(string lexeme, size_t lineNumber);
}
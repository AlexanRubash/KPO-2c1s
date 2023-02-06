#include "LexicalAnalysis.h"

namespace LexAnalys
{
	LT_IT_Tables GetTables(In::IN in, size_t ltSize, size_t itSize)
	{
		LT_IT_Tables lt_it_Tables = { LT::Create(ltSize), IT::Create(itSize) };

		vector<string> lexemesBuffer = SeparateLexeme(in.spaceLexeme);

		char lexemeName;			// ����������� ��� ������� 
		size_t literalIndex = 0;	// for literal name
		size_t lineNumber = 0;

		//��� ����������� �������� ���������
		stack<string> visibily;
		visibily.push("GLOBAL");

		//������� ��� �������� lexemesBuffer
		size_t i = 0;

		//��� ���������� ���� ������ � ��������(�� ���������) ��� ��������������
		auto Set_IDDATATYPE_VALUE_F = [&](IT::Entry& temp)
		{
			if (lexemesBuffer[i - 2] == "integer")
			{
				temp.iddatatype = IT::IDDATATYPE::INT;
				temp.value.vint = 0;
			}

			if (lexemesBuffer[i - 2] == "string")
			{
				temp.iddatatype = IT::IDDATATYPE::STR;
				temp.value.vstr.len = 0;
				//temp.value.vstr.str[0] = '\0';

				memset(temp.value.vstr.str, '\0', sizeof(char) * TI_STR_MAXSIZE);
			}
		};

		auto Set_IDDATATYPE_VALUE_V_P = [&](IT::Entry& temp)
		{
			if (lexemesBuffer[i - 1] == "integer")
			{
				temp.iddatatype = IT::IDDATATYPE::INT;
				temp.value.vint = 0;
			}

			if (lexemesBuffer[i - 1] == "string")
			{
				temp.iddatatype = IT::IDDATATYPE::STR;
				temp.value.vstr.len = 0;
				//temp.value.vstr.str[0] = '\0';

				memset(temp.value.vstr.str, '\0', sizeof(char) * TI_STR_MAXSIZE);
			}
		};

		for (; i < lexemesBuffer.size(); i++)
		{
			//������� ������ ������ � �������� ����
			if (lexemesBuffer[i] == "\n")				
			{
				++lineNumber;
				continue;
			}   

			lexemeName = GetLexemeName(lexemesBuffer[i],lineNumber);

			if (lexemeName == LEX_ID)
			{
				//if(i == 0) throw ERROR_THROW(119);

				if (lexemesBuffer[i - 1] == "function")
				{
					IT::Entry temp;

					temp.idxfirstLE = lt_it_Tables.lexTable.size;

					temp.id = lexemesBuffer[i].substr(0, ID_MAXSIZE);
					
					Set_IDDATATYPE_VALUE_F(temp);

						
					temp.idtype = IT::IDTYPE::F;

					temp.visibility = visibily.top();

					IT::Add(lt_it_Tables.idTable, temp);

					visibily.push(lexemesBuffer[i]);

					//add to lex table
					Add(lt_it_Tables.lexTable, LT::Entry(lexemeName, lineNumber, lt_it_Tables.idTable.size - 1, lexemesBuffer[i]) );
				}

				//����������, �������� �������
				else if (lexemesBuffer[i - 1] == "string" || lexemesBuffer[i - 1] == "integer")
				{
					if (lexemesBuffer[i - 2] == "declare")
					{
						IT::Entry temp;

						temp.idxfirstLE = lt_it_Tables.lexTable.size;

						temp.id = lexemesBuffer[i].substr(0, ID_MAXSIZE);
						
						Set_IDDATATYPE_VALUE_V_P(temp);


						temp.idtype = IT::IDTYPE::V;

						temp.visibility = visibily.top();

						IT::Add(lt_it_Tables.idTable, temp);

						//add to lex table
						Add(lt_it_Tables.lexTable, LT::Entry(lexemeName, lineNumber, lt_it_Tables.idTable.size - 1, lexemesBuffer[i]));
					}

					else
					{
						IT::Entry temp;

						temp.idxfirstLE = lt_it_Tables.lexTable.size;

						temp.id = lexemesBuffer[i].substr(0, ID_MAXSIZE);
						
						Set_IDDATATYPE_VALUE_V_P(temp);


						temp.idtype = IT::IDTYPE::P;

						temp.visibility = visibily.top();

						IT::Add(lt_it_Tables.idTable, temp);

						//add to lex table
						Add(lt_it_Tables.lexTable, LT::Entry(lexemeName, lineNumber, lt_it_Tables.idTable.size - 1, lexemesBuffer[i]));
					}
				}

				//�� ������ ������������� �������������� ����� ����������. ������� ������� ���������
				else
				{
					for (int j = lt_it_Tables.idTable.size-1; j >= 0; j--)
					{
						if(lt_it_Tables.idTable.table[j].id == lexemesBuffer[i] && lt_it_Tables.idTable.table[j].visibility == visibily.top())
							Add(lt_it_Tables.lexTable, LT::Entry(lexemeName, lineNumber, j, lexemesBuffer[i]));
					}
				}
			}

			//�������
			else if (lexemeName == LEX_LITERAL)
			{
				//string ������� 
				if (lexemesBuffer[i][0] == '\'')
				{
					IT::Entry temp;

					temp.idxfirstLE = lt_it_Tables.lexTable.size;

					// create name
					temp.id = "L_"+ to_string(literalIndex++);
	
					temp.iddatatype = IT::IDDATATYPE::STR;

					temp.idtype = IT::IDTYPE::L;

					// ����� ������
					temp.value.vstr.len = lexemesBuffer[i].size() - 2;

					// ����� ���� ������
					size_t count = 1;
					for (; count < lexemesBuffer[i].size()-1; count++)
					{
						temp.value.vstr.str[count - 1] = lexemesBuffer[i][count];
					}
					temp.value.vstr.str[count-1] = '\0';

					temp.visibility = "-";

					IT::Add(lt_it_Tables.idTable, temp);

					//add to lex table
					Add(lt_it_Tables.lexTable, LT::Entry(lexemeName, lineNumber, lt_it_Tables.idTable.size - 1, lexemesBuffer[i]));
				}
				//int �������
				else
				{
					IT::Entry temp;

					temp.idxfirstLE = lt_it_Tables.lexTable.size;

					temp.id = "L_" + to_string(literalIndex++);

					temp.iddatatype = IT::IDDATATYPE::INT;

					temp.idtype = IT::IDTYPE::L;

					// ����� �������� ��� int
					temp.value.vint = stoi(lexemesBuffer[i]);

					temp.visibility = "-";

					IT::Add(lt_it_Tables.idTable, temp);

					//add to lex table
					Add(lt_it_Tables.lexTable, LT::Entry(lexemeName, lineNumber, lt_it_Tables.idTable.size - 1, lexemesBuffer[i]));
				}
			}

			//������ �������
			else
			{
				//������� ��������� ���������, ��� '}' ����������!
				if(lexemeName == '}') visibily.pop();

				//������� ��������� ���������, ��� ')' ������������!
				//�.� ')' ����� ���� ��������������
				if (lexemeName == ')')
				{
					for (int j = i-1; j >= 0; j--)
					{
						if (lexemesBuffer[j][0] == '\n') continue;

						if (lexemesBuffer[j][0] == '(')
						{
							if (GetLexemeName(lexemesBuffer[j - 1],lineNumber) != LEX_ID) break;

							if (lexemesBuffer[j - 1] != visibily.top()) break;

							for (int j = i + 1; j < lexemesBuffer.size(); j++)
							{
								if (lexemesBuffer[j][0] == '\n') continue;

								if (lexemesBuffer[j][0] != '{') visibily.pop();
								break;
							}
							break;
						}
					}
				}

				Add(lt_it_Tables.lexTable, LT::Entry(lexemeName , lineNumber,  LT_TI_NULLIDX, lexemesBuffer[i]));
			}
		}

		return lt_it_Tables;
	}

	vector<string> SeparateLexeme(string lexemes)
	{
		std::string separator = "$";
		std::vector<std::string> tempBuffer;
		int position;

		while ((position = lexemes.find(separator)) && position != -1)
		{
			tempBuffer.push_back(lexemes.substr(0, position));
			lexemes.erase(0, position + separator.length());
		}

		return tempBuffer;
	}

	vector<regularExpression> REBuffer =
	{
		

		regularExpression(LEX_DECLARE, 8,
		FST::NODE(1, FST::RELATION('d',1)),
		FST::NODE(1, FST::RELATION('e',2)),
		FST::NODE(1, FST::RELATION('c',3)),
		FST::NODE(1, FST::RELATION('l',4)),
		FST::NODE(1, FST::RELATION('a',5)),
		FST::NODE(1, FST::RELATION('r',6)),
		FST::NODE(1, FST::RELATION('e',7)),
		FST::NODE()
		),

		regularExpression(LEX_INTEGER, 8,
		FST::NODE(1, FST::RELATION('i',1)),
		FST::NODE(1, FST::RELATION('n',2)),
		FST::NODE(1, FST::RELATION('t',3)),
		FST::NODE(1, FST::RELATION('e',4)),
		FST::NODE(1, FST::RELATION('g',5)),
		FST::NODE(1, FST::RELATION('e',6)),
		FST::NODE(1, FST::RELATION('r',7)),
		FST::NODE()
		),

		regularExpression(LEX_STRING, 7,
		FST::NODE(1, FST::RELATION('s',1)),
		FST::NODE(1, FST::RELATION('t',2)),
		FST::NODE(1, FST::RELATION('r',3)),
		FST::NODE(1, FST::RELATION('i',4)),
		FST::NODE(1, FST::RELATION('n',5)),
		FST::NODE(1, FST::RELATION('g',6)),
		FST::NODE()
		),

		regularExpression(LEX_FUNCTION, 9,
		FST::NODE(1, FST::RELATION('f',1)),
		FST::NODE(1, FST::RELATION('u',2)),
		FST::NODE(1, FST::RELATION('n',3)),
		FST::NODE(1, FST::RELATION('c',4)),
		FST::NODE(1, FST::RELATION('t',5)),
		FST::NODE(1, FST::RELATION('i',6)),
		FST::NODE(1, FST::RELATION('o',7)),
		FST::NODE(1, FST::RELATION('n',8)),
		FST::NODE()
		),

		regularExpression(LEX_RETURN, 7,
		FST::NODE(1, FST::RELATION('r',1)),
		FST::NODE(1, FST::RELATION('e',2)),
		FST::NODE(1, FST::RELATION('t',3)),
		FST::NODE(1, FST::RELATION('u',4)),
		FST::NODE(1, FST::RELATION('r',5)),
		FST::NODE(1, FST::RELATION('n',6)),
		FST::NODE()
		),

		regularExpression(LEX_PRINT, 6,
		FST::NODE(1, FST::RELATION('p',1)),
		FST::NODE(1, FST::RELATION('r',2)),
		FST::NODE(1, FST::RELATION('i',3)),
		FST::NODE(1, FST::RELATION('n',4)),
		FST::NODE(1, FST::RELATION('t',5)),
		FST::NODE()
		),

		regularExpression(LEX_COMMAND_COMPLETION, 2,
		FST::NODE(1, FST::RELATION(';', 1)),
		FST::NODE()
		),

		regularExpression(LEX_COMMA, 2,
		FST::NODE(1, FST::RELATION(',', 1)),
		FST::NODE()
		),

		regularExpression(LEX_LEFTHESIS, 2,
		FST::NODE(1, FST::RELATION('(', 1)),
		FST::NODE()
		),

		regularExpression(LEX_RIGHTHESIS, 2,
		FST::NODE(1, FST::RELATION(')', 1)),
		FST::NODE()
		),

		regularExpression(LEX_EQUALS, 2,
		FST::NODE(1, FST::RELATION('=', 1)),
		FST::NODE()
		),

		regularExpression(LEX_BRACELET, 2,
		FST::NODE(1, FST::RELATION('}', 1)),
		FST::NODE()
		),

		regularExpression(LEX_LEFTBRACE, 2,
		FST::NODE(1, FST::RELATION('{', 1)),
		FST::NODE()
		),

		regularExpression(LEX_DIRSLASH, 2,
		FST::NODE(1, FST::RELATION('/', 1)),
		FST::NODE()
		),

		regularExpression(LEX_PLUS, 2,
		FST::NODE(1, FST::RELATION('+', 1)),
		FST::NODE()
		),

		regularExpression(LEX_MINUS, 2,
		FST::NODE(1, FST::RELATION('-', 1)),
		FST::NODE()
		),

		regularExpression(LEX_STAR, 2,
		FST::NODE(1, FST::RELATION('*', 1)),
		FST::NODE()
		),

		regularExpression(LEX_LITERAL, 2,
		FST::NODE(22,
		FST::RELATION('-', 0), FST::RELATION('1', 0), FST::RELATION('2', 0), FST::RELATION('3', 0), FST::RELATION('4', 0), FST::RELATION('5', 0), FST::RELATION('6', 0),
		FST::RELATION('7', 0), FST::RELATION('8', 0), FST::RELATION('9', 0),FST::RELATION('0', 0),

		FST::RELATION('1', 1), FST::RELATION('2', 1), FST::RELATION('3', 1), FST::RELATION('4', 1), FST::RELATION('5', 1), FST::RELATION('6', 1),
		FST::RELATION('7', 1), FST::RELATION('8', 1), FST::RELATION('9', 1), FST::RELATION('0', 1)),
		FST::NODE()
		),

			regularExpression(LEX_ID, 2,
				FST::NODE(72,
					FST::RELATION('a', 0), FST::RELATION('b', 0), FST::RELATION('c', 0), FST::RELATION('d', 0), FST::RELATION('e', 0), FST::RELATION('f', 0),
					FST::RELATION('g', 0), FST::RELATION('h', 0), FST::RELATION('i', 0), FST::RELATION('j', 0), FST::RELATION('k', 0), FST::RELATION('l', 0),
					FST::RELATION('m', 0), FST::RELATION('n', 0), FST::RELATION('o', 0), FST::RELATION('p', 0), FST::RELATION('q', 0), FST::RELATION('r', 0),
					FST::RELATION('s', 0), FST::RELATION('t', 0), FST::RELATION('u', 0), FST::RELATION('v', 0), FST::RELATION('w', 0), FST::RELATION('x', 0),
					FST::RELATION('y', 0), FST::RELATION('z', 0),

					FST::RELATION('1', 0), FST::RELATION('2', 0), FST::RELATION('3', 0), FST::RELATION('4', 0),
					FST::RELATION('5', 0), FST::RELATION('6', 0), FST::RELATION('7', 0), FST::RELATION('8', 0), FST::RELATION('9', 0), FST::RELATION('0', 0),

					FST::RELATION('a', 1), FST::RELATION('b', 1), FST::RELATION('c', 1), FST::RELATION('d', 1), FST::RELATION('e', 1), FST::RELATION('f', 1),
					FST::RELATION('g', 1), FST::RELATION('h', 1), FST::RELATION('i', 1), FST::RELATION('j', 1), FST::RELATION('k', 1), FST::RELATION('l', 1),
					FST::RELATION('m', 1), FST::RELATION('n', 1), FST::RELATION('o', 1), FST::RELATION('p', 1), FST::RELATION('q', 1), FST::RELATION('r', 1),
					FST::RELATION('s', 1), FST::RELATION('t', 1), FST::RELATION('u', 1), FST::RELATION('v', 1), FST::RELATION('w', 1), FST::RELATION('x', 1),
					FST::RELATION('y', 1), FST::RELATION('z', 1)),
				FST::RELATION('1', 1), FST::RELATION('2', 1), FST::RELATION('3', 1), FST::RELATION('4', 1),
				FST::RELATION('5', 1), FST::RELATION('6', 1), FST::RELATION('7', 1), FST::RELATION('8', 1), FST::RELATION('9', 1), FST::RELATION('0', 1),
				FST::NODE()
			),

		regularExpression(LEX_LITERAL, 4,
			FST::NODE(2, FST::RELATION('\'', 1), FST::RELATION('\'', 2)),
			FST::NODE(274,
				FST::RELATION('a', 1), FST::RELATION('b', 1), FST::RELATION('c', 1), FST::RELATION('d', 1), FST::RELATION('e', 1), FST::RELATION('f', 1),
				FST::RELATION('g', 1), FST::RELATION('h', 1), FST::RELATION('i', 1), FST::RELATION('j', 1), FST::RELATION('k', 1), FST::RELATION('l', 1),
				FST::RELATION('m', 1), FST::RELATION('n', 1), FST::RELATION('o', 1), FST::RELATION('p', 1), FST::RELATION('q', 1), FST::RELATION('r', 1),
				FST::RELATION('s', 1), FST::RELATION('t', 1), FST::RELATION('u', 1), FST::RELATION('v', 1), FST::RELATION('w', 1), FST::RELATION('x', 1),
				FST::RELATION('y', 1), FST::RELATION('z', 1), FST::RELATION('1', 1), FST::RELATION('2', 1), FST::RELATION('3', 1), FST::RELATION('4', 1),
				FST::RELATION('5', 1), FST::RELATION('6', 1), FST::RELATION('7', 1), FST::RELATION('8', 1), FST::RELATION('9', 1), FST::RELATION('0', 1),

				FST::RELATION('A', 1), FST::RELATION('B', 1), FST::RELATION('C', 1), FST::RELATION('D', 1), FST::RELATION('E', 1), FST::RELATION('F', 1),
				FST::RELATION('G', 1), FST::RELATION('H', 1), FST::RELATION('I', 1), FST::RELATION('J', 1), FST::RELATION('K', 1), FST::RELATION('L', 1),
				FST::RELATION('M', 1), FST::RELATION('N', 1), FST::RELATION('O', 1), FST::RELATION('P', 1), FST::RELATION('Q', 1), FST::RELATION('R', 1),
				FST::RELATION('S', 1), FST::RELATION('T', 1), FST::RELATION('U', 1), FST::RELATION('V', 1), FST::RELATION('W', 1), FST::RELATION('X', 1),
				FST::RELATION('Y', 1), FST::RELATION('Z', 1),

				FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),
				FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),
				FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),
				FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),
				FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),
				FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION(' ', 1), FST::RELATION('.', 1), FST::RELATION(',', 1),
				FST::RELATION('?', 1), FST::RELATION('!', 1), FST::RELATION(';', 1), FST::RELATION(':', 1), FST::RELATION('-', 1), FST::RELATION(')', 1),
				FST::RELATION('(', 1),

				FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),
				FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),
				FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),
				FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),
				FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),
				FST::RELATION('�', 1), FST::RELATION('�', 1), FST::RELATION('�', 1),

				FST::RELATION('a', 2), FST::RELATION('b', 2), FST::RELATION('c', 2), FST::RELATION('d', 2), FST::RELATION('e', 2), FST::RELATION('f', 2),
				FST::RELATION('g', 2), FST::RELATION('h', 2), FST::RELATION('i', 2), FST::RELATION('j', 2), FST::RELATION('k', 2), FST::RELATION('l', 2),
				FST::RELATION('m', 2), FST::RELATION('n', 2), FST::RELATION('o', 2), FST::RELATION('p', 2), FST::RELATION('q', 2), FST::RELATION('r', 2),
				FST::RELATION('s', 2), FST::RELATION('t', 2), FST::RELATION('u', 2), FST::RELATION('v', 2), FST::RELATION('w', 2), FST::RELATION('x', 2),
				FST::RELATION('y', 2), FST::RELATION('z', 2), FST::RELATION('1', 2), FST::RELATION('2', 2), FST::RELATION('3', 2), FST::RELATION('4', 2),
				FST::RELATION('5', 2), FST::RELATION('6', 2), FST::RELATION('7', 2), FST::RELATION('8', 2), FST::RELATION('9', 2), FST::RELATION('0', 2),

				FST::RELATION('A', 2), FST::RELATION('B', 2), FST::RELATION('C', 2), FST::RELATION('D', 2), FST::RELATION('E', 2), FST::RELATION('F', 2),
				FST::RELATION('G', 2), FST::RELATION('H', 2), FST::RELATION('I', 2), FST::RELATION('J', 2), FST::RELATION('K', 2), FST::RELATION('L', 2),
				FST::RELATION('M', 2), FST::RELATION('N', 2), FST::RELATION('O', 2), FST::RELATION('P', 2), FST::RELATION('Q', 2), FST::RELATION('R', 2),
				FST::RELATION('S', 2), FST::RELATION('T', 2), FST::RELATION('U', 2), FST::RELATION('V', 2), FST::RELATION('W', 2), FST::RELATION('X', 2),
				FST::RELATION('Y', 2), FST::RELATION('Z', 2),

				FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2),
				FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2),
				FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2),
				FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2),
				FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2),
				FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2),

				FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2),
				FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2),
				FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2),
				FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2),
				FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2),
				FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION('�', 2), FST::RELATION(' ', 2), FST::RELATION('.', 2), FST::RELATION(',', 2),
				FST::RELATION('?', 2), FST::RELATION('!', 2), FST::RELATION(';', 2), FST::RELATION(':', 2), FST::RELATION('-', 2), FST::RELATION(')', 2),
				FST::RELATION('(', 2)),

			FST::NODE(1, FST::RELATION('\'', 3)),
			FST::NODE()
		),
	};

	regularExpression::regularExpression(char lN, short tN, FST::NODE n, ...)
	{
		transitionsNumber = tN;
		nodes = new FST::NODE[tN];
		FST::NODE* p = &n;
		lexemeName = lN;

		for (short k = 0; k < tN; k++)
			nodes[k] = p[k];
	}

	char GetLexemeName(string lexeme, size_t lineNumber)
	{
		for (size_t i = 0; i < REBuffer.size(); i++)
		{
			FST::FST tempFST(lexeme.c_str(), REBuffer[i].transitionsNumber, REBuffer[i].nodes);

			if (execute(tempFST)) return REBuffer[i].lexemeName;
		}

		throw ERROR_THROW_IN(118,lineNumber+1,0);
	}
}

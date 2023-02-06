#include <iostream>
#include <string> 
#include <stack>
#include <vector>
#include <map>

#include <conio.h>

using namespace std;

#define poping_operation_in_result(stack) char operation = stack.top(); stack.pop(); result_str += operation;

#define NUMBER_CHECK(existingSymbol)( 'A' <= existingSymbol && existingSymbol <= 'Z' ||\
									  'a' <= existingSymbol && existingSymbol <= 'z')

#define OPEN_BRACKET_CHECK(existingSymbol)( existingSymbol == '(')
#define CLOSING_BRACKET_CHECK(existingSymbol)( existingSymbol == ')')
#define PLUS_CHECK(existingSymbol)( existingSymbol == '+')
#define MINUS_CHECK(existingSymbol)( existingSymbol == '-')
#define MULTIPLY_CHECK(existingSymbol)( existingSymbol == '*')
#define DIVIDE_CHECK(existingSymbol)( existingSymbol == '/')

string PolishNotation_NikitaKovkel(string str)
{
	string result_str;
	stack <char> operations;
	map <char, int> operations_priority = {
		{'(', 1},
		{')', 1},
		{'+', 2},
		{'-', 2},
		{'*', 3},
		{'/', 3}
	};

	str.erase(remove(str.begin(), str.end(), ' '), str.end());

	for (int i = 0; i < str.length(); i++) {
		if (!operations_priority[str[i]])
			result_str += str[i];
		else {
			if ((operations.size() == 0 || str[i] == '('))
				operations.push(str[i]);
			else if (operations.size() && str[i] == ')') {
				while (operations.size() && operations.top() != '(') {
					poping_operation_in_result(operations);
				}
				operations.pop();
			}
			else {
				while (operations.size() != 0 && (operations_priority[operations.top()] >= operations_priority[str[i]])) {
					poping_operation_in_result(operations);
				}
				operations.push(str[i]);
			}
		}
	}
	while (operations.size()) {
		poping_operation_in_result(operations);
	}

	return result_str;
}

bool CheckString(string& acceptedString)
{
	bool numberFlag = false;
	bool arithmeticSignFlag = false;
	bool openBracketFlag = false;
	bool closingBracketFlag = false;

	stack<char> openBracketBuffer;
	stack<char> closingBracketBuffer;

	for (char existingSymbol : acceptedString)
	{
		//Проверяем все допустимые символы
		if (!(NUMBER_CHECK(existingSymbol) ||
			OPEN_BRACKET_CHECK(existingSymbol) ||
			CLOSING_BRACKET_CHECK(existingSymbol) ||
			PLUS_CHECK(existingSymbol) ||
			MINUS_CHECK(existingSymbol) ||
			MULTIPLY_CHECK(existingSymbol) ||
			DIVIDE_CHECK(existingSymbol)))
			return false;

		//Проверяем случай, когда идут 2 числа подряд
		else if (NUMBER_CHECK(existingSymbol))
		{
			if (numberFlag) return false;

			numberFlag = true;

			arithmeticSignFlag = openBracketFlag = closingBracketFlag = false;
		}

		//Проверяем случай, когда идут 2 арифметических знака подряд
		else if (PLUS_CHECK(existingSymbol) ||
			MINUS_CHECK(existingSymbol) ||
			MULTIPLY_CHECK(existingSymbol) ||
			DIVIDE_CHECK(existingSymbol))
		{
			if (arithmeticSignFlag) return false;

			arithmeticSignFlag = true;

			numberFlag = openBracketFlag = closingBracketFlag = false;
		}

		//Попалась скобка (
		else if (OPEN_BRACKET_CHECK(existingSymbol))
		{
			//if (!(arithmeticSignFlag || openBracketFlag) && (numberFlag == arithmeticSignFlag == openBracketFlag == closingBracketFlag == false)) return false;
			//if (!(arithmeticSignFlag || openBracketFlag) && !(!numberFlag && !arithmeticSignFlag && !openBracketFlag && !closingBracketFlag)) return false;
			if (!(arithmeticSignFlag || openBracketFlag) && (numberFlag || arithmeticSignFlag || openBracketFlag || closingBracketFlag)) return false;
			openBracketBuffer.push(existingSymbol);

			openBracketFlag = true;

			numberFlag = arithmeticSignFlag = closingBracketFlag = false;
		}

		//Попалась скобка )
		else if (CLOSING_BRACKET_CHECK(existingSymbol))
		{
			if (!(numberFlag || closingBracketFlag)) return false;
			closingBracketBuffer.push(existingSymbol);

			closingBracketFlag = true;

			numberFlag = arithmeticSignFlag = openBracketFlag = false;
		}
	}

	//Проврка - последний символ не арифмет. знак (+ - * /)
	if (arithmeticSignFlag) return false;

	//Проверка правильности скобок
	if (openBracketBuffer.empty() && closingBracketBuffer.empty()) return true;
	if (openBracketBuffer.size() != closingBracketBuffer.size()) return false;

	return true;
}

bool PolishNotation(string& acceptedString)
{
	if (!CheckString(acceptedString)) return false;

	string polishString;
	stack<char> arithmeticSignBuffer;

	for (char existingSymbol : acceptedString)
	{
		if (NUMBER_CHECK(existingSymbol)) polishString.push_back(existingSymbol);
		else
		{
			if (existingSymbol == ')')
			{
				while (arithmeticSignBuffer.top() != '(')
				{
					polishString.push_back(arithmeticSignBuffer.top());
					arithmeticSignBuffer.pop();
				}

				arithmeticSignBuffer.pop();
			}
			else
			{
				if (arithmeticSignBuffer.empty() || arithmeticSignBuffer.top() == '(')
				{
					arithmeticSignBuffer.push(existingSymbol);
				}
				else
				{
					if ((arithmeticSignBuffer.top() == '*' || arithmeticSignBuffer.top() == '/') && (PLUS_CHECK(existingSymbol) || MINUS_CHECK(existingSymbol)))
					{
						polishString.push_back(arithmeticSignBuffer.top());
						arithmeticSignBuffer.pop();

						arithmeticSignBuffer.push(existingSymbol);
					}
					else
					{
						arithmeticSignBuffer.push(existingSymbol);
					}
				}

			}

		}
	}

	while (!arithmeticSignBuffer.empty())
	{
		polishString.push_back(arithmeticSignBuffer.top());
		arithmeticSignBuffer.pop();
	}

	acceptedString = polishString;

	return true;
}

int main()
{
	setlocale(0, "rus");

	string str = "a+b* c";

	auto nikitastr = PolishNotation_NikitaKovkel(str);

	for (;;)
	{
		cout << "Enter string: "; std::getline(std::cin, str);

		if (PolishNotation(str)) cout << "PolishNotation: " << str;
		else cout << "ERROR!!!";

		short ButtonCod = _getch();
		if (ButtonCod == 239) break;

		system("cls");
	}
}
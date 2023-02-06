#include "FST.h"
#include "stdafx.h"

//#define Lection
#define MyVariant

int main(int argc, _TCHAR* argv[])
{
	setlocale(0, "rus");

#ifdef Lection
	FST::FST fst1(
		"aabbaba",
		4,
		FST::NODE(3, FST::RELATION('a', 0), FST::RELATION('b', 0), FST::RELATION('a', 1)),
		FST::NODE(1, FST::RELATION('b', 2)),
		FST::NODE(1, FST::RELATION('a', 3)),
		FST::NODE()
	);
	if (FST::execute(fst1))
		std::cout << "Цепочка " << fst1.string << " распознана" << std::endl;
	else  std::cout << "Цепочка " << fst1.string << " не распознана" << std::endl;

	FST::FST fst2(
		"aaabbbabba",
		4,
		FST::NODE(3, FST::RELATION('a', 0), FST::RELATION('b', 0), FST::RELATION('a', 1)),
		FST::NODE(1, FST::RELATION('b', 2)),
		FST::NODE(1, FST::RELATION('a', 3)),
		FST::NODE()
	);
	if (FST::execute(fst2))
		std::cout << "Цепочка " << fst2.string << " распознана" << std::endl;
	else  std::cout << "Цепочка " << fst2.string << " не распознана" << std::endl;
#endif // Lection

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifdef MyVariant
	string arr_str[] = { /*"acbcdfcgf",
						 "acbcefcgf",
						 "accbcbcdfccgf",
						 "acbcefbcefcgf",
						 "acbcefbcefccgf",
						 "acbcefbcefcccgf",
						 "acbcefbcefccccgf",
						 "acbcdf",
						 "bcbcefbcefccccgf",
						 "arcbcdfcgf",*/

						 /*"dbccdccgbebebcccccccchb",
						 "abc",

						 "abcdcebchb",
						 "abcdcgbchb",
						 "abccdccgbchb",
						 "abccdccgbccccchb",
						 "abccdccgbebchb",
						 "abccdccgbebcccccccchb",
						 "abccdccgbebebccccccchb"*/

						 "abcbefbg",
						 "abbcbefbg",
						 "abccbefbg",
						 "abccbefbg",
						 "abccbbbbbefbg",
						 "abcddddddddddbefbg",
						 "abcddddddddddbbbbbbbefbg",

						 "abc",
						 "abcbefbc"

						



	};

	size_t arr_str_size = 0;
	for (auto temp : arr_str) ++arr_str_size;

	for (size_t i = 0; i < arr_str_size;)
	{
		arr_str[i].push_back('\0');

		FST::FST fst(
			(arr_str[i]).c_str(),

			/*9,
			FST::NODE(1, FST::RELATION('a', 1)),
			FST::NODE(2, FST::RELATION('c', 1), FST::RELATION('b', 2)),
			FST::NODE(1, FST::RELATION('c', 3)),
			FST::NODE(3, FST::RELATION('b', 2), FST::RELATION('d', 4), FST::RELATION('e', 4)),
			FST::NODE(1, FST::RELATION('f', 5)),
			FST::NODE(2, FST::RELATION('b', 2), FST::RELATION('c', 6)),
			FST::NODE(2, FST::RELATION('c', 6), FST::RELATION('g', 7)),
			FST::NODE(1, FST::RELATION('f', 8)),
			FST::NODE()*/

			/*6,
			FST::NODE(1, FST::RELATION('a', 1)),
			FST::NODE(1, FST::RELATION('b', 2)),
			FST::NODE(4, FST::RELATION('b', 2), FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('e', 3)),
			FST::NODE(4, FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('e', 3), FST::RELATION('b', 4)),
			FST::NODE(2, FST::RELATION('b', 4), FST::RELATION('f', 5)),
			FST::NODE()*/

			/*11,
			FST::NODE(1, FST::RELATION('a', 1)),
			FST::NODE(1, FST::RELATION('b', 2)),
			FST::NODE(2, FST::RELATION('c', 3)),
			FST::NODE(2, FST::RELATION('c', 3), FST::RELATION('d', 4)),
			FST::NODE(1, FST::RELATION('c', 5)),
			FST::NODE(3, FST::RELATION('c', 5), FST::RELATION('e', 6), FST::RELATION('g', 6)),
			FST::NODE(1, FST::RELATION('b', 7)),
			FST::NODE(3, FST::RELATION('e', 6), FST::RELATION('g', 6), FST::RELATION('c', 8)),
			FST::NODE(2, FST::RELATION('c', 8), FST::RELATION('h', 9)),
			FST::NODE(1, FST::RELATION('b', 10)),
			FST::NODE()*/

			9,
			FST::NODE(1, FST::RELATION('a', 1)),
			FST::NODE(1, FST::RELATION('b', 2)),
			FST::NODE(3, FST::RELATION('b', 2), FST::RELATION('c', 3), FST::RELATION('d', 3)),
			FST::NODE(3, FST::RELATION('c', 3), FST::RELATION('d', 3), FST::RELATION('b', 4)),
			FST::NODE(2, FST::RELATION('b', 4), FST::RELATION('e', 5)),
			FST::NODE(1, FST::RELATION('f', 6)),
			FST::NODE(1, FST::RELATION('b', 7)),
			FST::NODE(2, FST::RELATION('b', 7), FST::RELATION('g', 8)),
			FST::NODE()

		/*	4,
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

				FST::RELATION('а', 1), FST::RELATION('б', 1), FST::RELATION('в', 1), FST::RELATION('г', 1), FST::RELATION('д', 1), FST::RELATION('е', 1),
				FST::RELATION('ё', 1), FST::RELATION('ж', 1), FST::RELATION('з', 1), FST::RELATION('и', 1), FST::RELATION('й', 1), FST::RELATION('к', 1),
				FST::RELATION('л', 1), FST::RELATION('м', 1), FST::RELATION('н', 1), FST::RELATION('о', 1), FST::RELATION('п', 1), FST::RELATION('р', 1),
				FST::RELATION('с', 1), FST::RELATION('т', 1), FST::RELATION('у', 1), FST::RELATION('ф', 1), FST::RELATION('х', 1), FST::RELATION('ц', 1),
				FST::RELATION('ч', 1), FST::RELATION('ш', 1), FST::RELATION('щ', 1), FST::RELATION('ъ', 1), FST::RELATION('ы', 1), FST::RELATION('ь', 1),
				FST::RELATION('э', 1), FST::RELATION('ю', 1), FST::RELATION('я', 1), FST::RELATION(' ', 1), FST::RELATION('.', 1), FST::RELATION(',', 1),
				FST::RELATION('?', 1), FST::RELATION('!', 1), FST::RELATION(';', 1), FST::RELATION(':', 1), FST::RELATION('-', 1), FST::RELATION(')', 1),
				FST::RELATION('(', 1),

				FST::RELATION('А', 1), FST::RELATION('Б', 1), FST::RELATION('В', 1), FST::RELATION('Г', 1), FST::RELATION('Д', 1), FST::RELATION('Е', 1),
				FST::RELATION('Ё', 1), FST::RELATION('Ж', 1), FST::RELATION('З', 1), FST::RELATION('И', 1), FST::RELATION('Й', 1), FST::RELATION('К', 1),
				FST::RELATION('Л', 1), FST::RELATION('М', 1), FST::RELATION('Н', 1), FST::RELATION('О', 1), FST::RELATION('П', 1), FST::RELATION('Р', 1),
				FST::RELATION('С', 1), FST::RELATION('Т', 1), FST::RELATION('у', 1), FST::RELATION('Ф', 1), FST::RELATION('Х', 1), FST::RELATION('Ц', 1),
				FST::RELATION('Ч', 1), FST::RELATION('Ш', 1), FST::RELATION('Щ', 1), FST::RELATION('Ъ', 1), FST::RELATION('Ы', 1), FST::RELATION('Ь', 1),
				FST::RELATION('Э', 1), FST::RELATION('Ю', 1), FST::RELATION('Я', 1),

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

				FST::RELATION('А', 2), FST::RELATION('Б', 2), FST::RELATION('В', 2), FST::RELATION('Г', 2), FST::RELATION('Д', 2), FST::RELATION('Е', 2),
				FST::RELATION('Ё', 2), FST::RELATION('Ж', 2), FST::RELATION('З', 2), FST::RELATION('И', 2), FST::RELATION('Й', 2), FST::RELATION('К', 2),
				FST::RELATION('Л', 2), FST::RELATION('М', 2), FST::RELATION('Н', 2), FST::RELATION('О', 2), FST::RELATION('П', 2), FST::RELATION('Р', 2),
				FST::RELATION('С', 2), FST::RELATION('Т', 2), FST::RELATION('у', 2), FST::RELATION('Ф', 2), FST::RELATION('Х', 2), FST::RELATION('Ц', 2),
				FST::RELATION('Ч', 2), FST::RELATION('Ш', 2), FST::RELATION('Щ', 2), FST::RELATION('Ъ', 2), FST::RELATION('Ы', 2), FST::RELATION('Ь', 2),
				FST::RELATION('Э', 2), FST::RELATION('Ю', 2), FST::RELATION('Я', 2),

				FST::RELATION('а', 2), FST::RELATION('б', 2), FST::RELATION('в', 2), FST::RELATION('г', 2), FST::RELATION('д', 2), FST::RELATION('е', 2),
				FST::RELATION('ё', 2), FST::RELATION('ж', 2), FST::RELATION('з', 2), FST::RELATION('и', 2), FST::RELATION('й', 2), FST::RELATION('к', 2),
				FST::RELATION('л', 2), FST::RELATION('м', 2), FST::RELATION('н', 2), FST::RELATION('о', 2), FST::RELATION('п', 2), FST::RELATION('р', 2),
				FST::RELATION('с', 2), FST::RELATION('т', 2), FST::RELATION('у', 2), FST::RELATION('ф', 2), FST::RELATION('х', 2), FST::RELATION('ц', 2),
				FST::RELATION('ч', 2), FST::RELATION('ш', 2), FST::RELATION('щ', 2), FST::RELATION('ъ', 2), FST::RELATION('ы', 2), FST::RELATION('ь', 2),
				FST::RELATION('э', 2), FST::RELATION('ю', 2), FST::RELATION('я', 2), FST::RELATION(' ', 2), FST::RELATION('.', 2), FST::RELATION(',', 2),
				FST::RELATION('?', 2), FST::RELATION('!', 2), FST::RELATION(';', 2), FST::RELATION(':', 2), FST::RELATION('-', 2), FST::RELATION(')', 2),
				FST::RELATION('(', 2)),

			FST::NODE(1, FST::RELATION('\'', 3)),
			FST::NODE()*/
		);
		if (FST::execute(fst))
			std::cout << "Цепочка " << fst.string << " распознана" << std::endl;

		else  std::cout << "Цепочка " << fst.string << " не распознана" << std::endl;

		++i;
	}
#endif // MyVariant

	return 0;
}
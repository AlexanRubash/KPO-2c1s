#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "Error.h"


#define ID_MAXSIZE 5				// максимальное количество символов в идентификаторе 
#define TI_MAXSIZE 4096				// максимальное количество строк в таблице идентификаторе
#define TI_INT_DEFAULT 0x00000000   // значение по умолчанию для типа integer
#define TI_STR_DEFAULT 0x00			// значение по умолчанию для типа string
#define TI_NULLIDX 0xffffffff		// нет элемента таблицы идентификаторов 
#define TI_STR_MAXSIZE 255

//#define GLOBAL_VISIBILITY_AREA "Global";

namespace IT		// ТИ
{
	enum IDDATATYPE		// типы данных идентификаторов:
	{
		INT = 1,	// integer
		STR = 2		// string
	};

	enum IDTYPE		// типы идентификаторов: 
	{
		V = 1,                        // переменная
		F = 2,                        // функция
		P = 3,                        // параметр
		L = 4                         // литерал
	};

	struct Entry	// строка ТИ
	{
		int idxfirstLE;               // индекс первой строки в ТЛ

		std::string id;				  // идентификатор (автоматически усекается до ID_MAXISZE)

		IDDATATYPE iddatatype;        // тип данных
		IDTYPE idtype;                // тип идентификатора
		union
		{
			int vint;				  // значение integer
			struct
			{
				int len;						// количество символов в string
				char str[TI_STR_MAXSIZE];	// символы в string

			}vstr;//[TI_STR_MAXSIZE];				// значение string
		}value;						  // значение идентификатора

		std::string visibility;   // область видимости
	};

	struct IdTable					  // экземпляр ТИ
	{
		int maxsize;				  // емкость ТИ  <  TI_MAXSIZE
		int size;					  // текущий размер ТИ  <  maxsize
		Entry* table;				  // массив строк ТИ
	};

	IdTable Create(			// создаем ТИ
		int size			// емкость ТИ  <  TI_MAXSIZE
	);

	void Add(				// добавить строку в ТИ
		IdTable& idtable,	// экземпляр ТИ
		Entry entry				// строка ТИ
	);

	Entry GetEntry(			// получить строку ТИ
		IdTable& idtable,	// экземпляр ТИ
		int n				// номер получаемой строки
	);

	int IsId(
		IdTable& idtable,
		const char* id,
		int start
	);

	void PrintIdTable(const wchar_t* in, IdTable& idtable);
	std::string Mysetw(size_t width);

	void Delete(IdTable& idtable); // удалить ТЛ (освободить память)
}
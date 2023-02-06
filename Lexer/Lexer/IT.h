#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "Error.h"


#define ID_MAXSIZE 5				// ������������ ���������� �������� � �������������� 
#define TI_MAXSIZE 4096				// ������������ ���������� ����� � ������� ��������������
#define TI_INT_DEFAULT 0x00000000   // �������� �� ��������� ��� ���� integer
#define TI_STR_DEFAULT 0x00			// �������� �� ��������� ��� ���� string
#define TI_NULLIDX 0xffffffff		// ��� �������� ������� ��������������� 
#define TI_STR_MAXSIZE 255

//#define GLOBAL_VISIBILITY_AREA "Global";

namespace IT		// ��
{
	enum IDDATATYPE		// ���� ������ ���������������:
	{
		INT = 1,	// integer
		STR = 2		// string
	};

	enum IDTYPE		// ���� ���������������: 
	{
		V = 1,                        // ����������
		F = 2,                        // �������
		P = 3,                        // ��������
		L = 4                         // �������
	};

	struct Entry	// ������ ��
	{
		int idxfirstLE;               // ������ ������ ������ � ��

		std::string id;				  // ������������� (������������� ��������� �� ID_MAXISZE)

		IDDATATYPE iddatatype;        // ��� ������
		IDTYPE idtype;                // ��� ��������������
		union
		{
			int vint;				  // �������� integer
			struct
			{
				int len;						// ���������� �������� � string
				char str[TI_STR_MAXSIZE];	// ������� � string

			}vstr;//[TI_STR_MAXSIZE];				// �������� string
		}value;						  // �������� ��������������

		std::string visibility;   // ������� ���������
	};

	struct IdTable					  // ��������� ��
	{
		int maxsize;				  // ������� ��  <  TI_MAXSIZE
		int size;					  // ������� ������ ��  <  maxsize
		Entry* table;				  // ������ ����� ��
	};

	IdTable Create(			// ������� ��
		int size			// ������� ��  <  TI_MAXSIZE
	);

	void Add(				// �������� ������ � ��
		IdTable& idtable,	// ��������� ��
		Entry entry				// ������ ��
	);

	Entry GetEntry(			// �������� ������ ��
		IdTable& idtable,	// ��������� ��
		int n				// ����� ���������� ������
	);

	int IsId(
		IdTable& idtable,
		const char* id,
		int start
	);

	void PrintIdTable(const wchar_t* in, IdTable& idtable);
	std::string Mysetw(size_t width);

	void Delete(IdTable& idtable); // ������� �� (���������� ������)
}
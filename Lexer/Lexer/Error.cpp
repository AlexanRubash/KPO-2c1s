#include "Error.h"

namespace Error
{
	ERROR errors[ERROR_MAX_ENTRY]
	{
		ERROR_ENTRY(0,"������������ ��� ������"),
		ERROR_ENTRY(1,"��������� ����"),
		ERROR_ENTRY_NODEF(2),ERROR_ENTRY_NODEF(3),ERROR_ENTRY_NODEF(4),ERROR_ENTRY_NODEF(5),
		ERROR_ENTRY_NODEF(6),ERROR_ENTRY_NODEF(7),ERROR_ENTRY_NODEF(8),ERROR_ENTRY_NODEF(9),
		ERROR_ENTRY_NODEF10(10),ERROR_ENTRY_NODEF10(20),ERROR_ENTRY_NODEF10(30),ERROR_ENTRY_NODEF10(40),ERROR_ENTRY_NODEF10(50),
		ERROR_ENTRY_NODEF10(60),ERROR_ENTRY_NODEF10(70),ERROR_ENTRY_NODEF10(80),ERROR_ENTRY_NODEF10(90),
		ERROR_ENTRY(100,"�������� -in ������ ���� �����"),
		ERROR_ENTRY_NODEF(101), ERROR_ENTRY_NODEF(102), ERROR_ENTRY_NODEF(103),
		ERROR_ENTRY(104, "��������� ����� �������� ���������"),
		ERROR_ENTRY(105, "������ ������� ������� ������ ������� ������"),
		ERROR_ENTRY(106, "������ �������  ������ �������� ������������ ���������"),
		ERROR_ENTRY(107, "������ ������� ������� ������ ������� ���������������"),
		ERROR_ENTRY(108, "������ ������� ��������������� �������� ������������ ���������"),
		ERROR_ENTRY_NODEF(109),
		ERROR_ENTRY(110, "������ ��� �������� ����� � �������� ����� (-in)"),
		ERROR_ENTRY(111, "�� ��������� ������� �������� ����� (-in)"),
		ERROR_ENTRY(112, "������ ��� �������� ����� ��������� (-log)"),
		ERROR_ENTRY(113, "������ ������������ �������"),
		ERROR_ENTRY(114, "������ ��� �������� ����� ��������� ����� (-out)"),
		ERROR_ENTRY(115, "�������� ���� (-in) ����"),
		ERROR_ENTRY(116, "�������� ������ ������� ���������������"),
		ERROR_ENTRY(117, "�������� ������ ������� ������"),
		ERROR_ENTRY(118, "������������������� �������"),
		ERROR_ENTRY(119, "����������� ��� ��������������(�������� ������������ � ����� ������ �����)"),
		ERROR_ENTRY_NODEF10(120), ERROR_ENTRY_NODEF10(130), ERROR_ENTRY_NODEF10(140), ERROR_ENTRY_NODEF10(150),
		ERROR_ENTRY_NODEF10(160), ERROR_ENTRY_NODEF10(170), ERROR_ENTRY_NODEF10(180), ERROR_ENTRY_NODEF10(190),
		ERROR_ENTRY_NODEF100(200), ERROR_ENTRY_NODEF100(300), ERROR_ENTRY_NODEF100(400), ERROR_ENTRY_NODEF100(500),
		ERROR_ENTRY_NODEF100(600), ERROR_ENTRY_NODEF100(700), ERROR_ENTRY_NODEF100(800), ERROR_ENTRY_NODEF100(900)
	};

	ERROR geterror(int id)
	{
		if (0 > id || id > ERROR_MAX_ENTRY) return errors[0];
		else return errors[id];
	}

	ERROR geterrorin(int id, int line = -1, int col = -1)
	{
		if (0 > id || id > ERROR_MAX_ENTRY) return errors[0];
		else
		{
			errors[id].inext.line = line;
			errors[id].inext.col = col;
			return errors[id];
		}
	}
};

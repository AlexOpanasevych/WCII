#pragma once
#include "pch.h"
#include "Screenable.h"


class Unit;

class Field : public Screenable {
	private:
		int fieldLen;
// OLD code
//		DynArr** field;


	protected:
		DynArr* members;
	public:
// OLD code
//		DynArr** getField();
		Field(int width, int heigth);
		Field();
		virtual ~Field();
		DynArr* getMembers();
		void freeElements(); // ������� ���� ����� ����(�� ������, ��������� ����������, �� ����� ��������� � ����)
		int setCell(cordScr cordsNew, Unit * target); // ���������� �� ������ � ������� ����������� ������ ����
		int changeCell(cordScr cords, Unit * target); // �������� ������(�������� � ������ � ������� ������������)
		virtual void render(); // ������������(������������)
		bool checkFree(cordScr cords, int type); // ��������� ������ �� ������� ����� ������ ���� (������ ������ ���� ���� � ���� ���� ����)
		bool classifyEvent(Command_c command);
		virtual void operateEvent(Command_c command);
};


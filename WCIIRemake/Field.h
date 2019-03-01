#pragma once
#include "pch.h"
#include "Screenable.h"


class Unit;

class Field : public Screenable {
	private:
		int fieldLen;
		DynArr** field;
		int width;
		int height;
	protected:
		DynArr* members;
	public:
		DynArr** getField();
		DynArr* getMembers();
		Field(int width, int heigth); 
		Field();
		virtual ~Field();
		void freeElements(); // ������� ���� ����� ����(�� ������, ��������� ����������, �� ����� ��������� � ����)
		int setCell(cordScr cordsNew, Unit * target); // ���������� �� ������ � ������� ����������� ������ ����
		int changeCell(cordScr cords, Unit * target); // �������� ������(�������� � ������ � ������� ������������)
		virtual void render(); // ������������(������������)
		bool checkFree(cordScr cords, int type); // ��������� ������ �� ������� ����� ������ ���� (������ ������ ���� ���� � ���� ���� ����)
		bool classifyEvent(Command_c command);
		virtual void operateEvent(Command_c command);
};


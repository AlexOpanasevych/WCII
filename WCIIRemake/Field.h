#pragma once
#include "pch.h"
#include "Screenable.h"


class FieldPreset {
public:
	int width;
	int heigth;
	
};

class Unit;

class Field : public Screenable {
	private:
		int fieldLen;
	protected:
		DynArr* members;
	public:
		Field(int width, int heigth);
		Field() : Field(30, 30) {}
		Field(FieldPreset preset) : Field(preset.width, preset.heigth) {}
		virtual ~Field();
		DynArr* getMembers();
		void freeElements(); // ������� ���� ����� ����(�� ������, ��������� ���������, �� ����� ��������� � ����)
		int setCell(cordScr cordsNew, Unit * target); // ���������� �� ������ � ������� ����������� ������ ����
		int changeCell(cordScr cords, Unit * target); // �������� ������(�������� � ������ � ������� ������������)
		virtual void render(); // ������������(������������)
		bool checkFree(cordScr cords, int type); // ��������� ������ �� ������� ����� ������ ���� (������ ������ ���� ���� � ���� ���� ����)
		bool classifyEvent(Command_c* command);
		virtual void operateEvent(Command_c* command);
		//Field commands(Events)
		bool spawnEvent(Command_c* command);
		bool writeEvent(Command_c* command);
};


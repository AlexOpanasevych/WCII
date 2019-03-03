#pragma once

#include "pch.h"
#include "Screenable.h"
#include "Threadable.h"
#include "FastPath.h"
#include <ctime>
#include <stdlib.h>

class Unit : public Screenable, public Threadable{
protected:
	Field* field;
	char value;//for debug
	int type;
	cordScr moveDest;

	bool threadFlag;
public:

//	Unit(Unit** field);
	Unit(cordScr cords, char value,int type, Field* field);
	Unit(cordScr cords, Field* field) : Unit(cords, 'd', 1, field) {}
	Unit(cordScr cords, int type, Field* field) : Unit(cords, 'd', type, field) {}
	Unit(char value, int type, Field* field) : Unit(cordScr(0, 0), value, type, field) {}
	Unit(char value, Field* field) : Unit(cordScr(0, 0), value, 1, field) {}
	Unit() : Unit(cordScr(0, 0), NULL) {}
	virtual ~Unit();
	char getValue(); // ���������� ���������� �������� ����� �����(��� �������� ���� ��� �������� � �������) 
	int getType(); // ���������� �������� ��� �����(����� ����� ������������� �� ����������, ��������� � ������� ������)
	int move(int direction); //����������� �� ����, direction: 1-up,2-down,3-rigth,4-left (����� �������� ��� 4 ��������)
	bool goTo(cordScr* dest);
	virtual void render(); // ������������(������������)
	bool classifyEvent(Command_c command);
	virtual void threadFunction();
	virtual void operateEvent(Command_c command);
private:
	int findPath(cordScr destC); // ��������� ����� ����(� ��������)
private:
	//UNIT COMMANDS(EVENTS)
	bool selectEvent(Command_c command);
	bool echoEvent(Command_c command);
	bool tpEvent(Command_c command);
	bool moveEvent(Command_c command);

};


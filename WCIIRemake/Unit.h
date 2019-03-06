#pragma once

#include "pch.h"
#include "Screenable.h"
#include "Threadable.h"
#include "FastPath.h"
#include <ctime>
#include <stdlib.h>

class Unit : public Screenable{
protected:
	Field* field;
	char value; //for debug
	int type;
	bool threadFlag;
	int health;
	int attackLength;
	int team; 
	//TODO: add friend teams list
public:
	Unit(char value, int type, Field* field, int health, int team, int attackLength);
	Unit() : Unit('d', 1, NULL, 100, 0, 0) {}
	virtual ~Unit();

	char getValue(); // ���������� ���������� �������� ����� �����(��� �������� ���� ��� �������� � �������) 
	int getType(); // ���������� �������� ��� �����(����� ����� ������������� �� ����������, ��������� � ������� ������)
	virtual void render(); // ������������(������������)
	bool classifyEvent(Command_c command);
	//virtual void threadFunction();
	virtual void operateEvent(Command_c command);
protected:
	bool getDamage(int damage);
	//void attack();
protected:
	//UNIT COMMANDS(EVENTS)
	bool selectEvent(Command_c command);
	bool echoEvent(Command_c command);
	bool damageEvent(Command_c command);

};


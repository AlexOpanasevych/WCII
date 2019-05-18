#pragma once

#include "pch.h"
#include "Screenable.h"
#include "Threadable.h"
#include "FastPath.h"
#include "CommandPatterns.h"
#include "MultiTeamSelector.h"
#include <ctime>
#include <stdlib.h>

class Unit : public Screenable, public CommandPatterns, public MultiTeamSelector {
protected:
	Field* field;
	char value; //for debug
	int type;
	bool threadFlag;
	int health;
	int attackLength;
	int team; 
	string typeName;
	//TODO: add friend teams list
public:
	Unit(char value, int type, Field* field, int health, int team);
	Unit() : Unit('d', 1, NULL, 100, 0) {}
	virtual ~Unit();
	int getTeam();
	int getHealth();
	char getValue(); // ���������� ���������� �������� ����� �����(��� �������� ���� ��� �������� � �������) 
	int getType(); // ���������� �������� ��� �����(����� ����� ������������� �� ����������, ��������� � ������� ������)
	virtual void render(); // ������������(������������)
	bool classifyEvent(Command_c* command);
	virtual void operateEvent(Command_c* command);
protected:
	bool getDamage(int damage);
	virtual void stopAllThreads();
	virtual void fillCommandPatterns();
protected:
	//UNIT COMMANDS(EVENTS)
	bool selectEvent(Command_c* command);
	bool echoEvent(Command_c* command);
	bool damageEvent(Command_c* command);
	bool getInfoEvent(Command_c * command);

public:
	static void selectIdCommand(Command_c* command, CommandPatterns* oParent);
	static void unselectIdCommand(Command_c* command, CommandPatterns* oParent);
	static void damageIdCommand(Command_c* command, CommandPatterns* oParent);
	static void getInfoIdCommand(Command_c* command, CommandPatterns* oParent);
	static void echoIdCommand(Command_c* command, CommandPatterns* oParent);
	static void getInfoUnitsCommand(Command_c* command, CommandPatterns* oParent);
	static void getInfoTeamUnitsCommand(Command_c* command, CommandPatterns* oParent);
	static void selectTeamCommand(Command_c* command, CommandPatterns* oParent);
};

// select team [int:team] id [int:id]
// unselect team [int:team] id [int::id]
// damage id [int:id] power [int:power]
// get info id [int::id]
// echo id [int:id] [quotes string:message]
// get info units
// get team [int:team] info units
// select team [int:team] {flags}

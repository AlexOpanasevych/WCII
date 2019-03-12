#pragma once
#include "Unit.h"
#include "MoveToTHREAD.h"

class LiveUnit : public Unit {
private:
	cordScr moveDest;
	ThreadId MoveToTHRDDescriptor;
public:
	LiveUnit(char value, int type, Field* field, int health, int team, int attackLength);
	LiveUnit() : LiveUnit('d', 1, NULL, 100, 0, 0) {}
	~LiveUnit();
	ThreadId getMoveToTHRDDescriptor();
	cordScr* getMoveDest();
	bool goTo(cordScr* dest);
private:
	int findPath(cordScr destC); // ��������� ����� ����(� ��������)
	int move(int direction); //����������� �� ����, direction: 1-up,2-down,3-rigth,4-left (����� �������� ��� 4 ��������)
//	virtual void threadFunction();
	bool classifyEvent(Command_c command);
	virtual void operateEvent(Command_c command);
//LIVEUNIT COMMANDS(EVENTS)
protected:
	bool tpEvent(Command_c command);
	bool moveEvent(Command_c command);
};


#pragma once
#include "pch.h"
#include "Screenable.h"
#include "DynArr.h"
#include "ScreenDrawindTHREAD.h"
#include "CommandPatterns.h"
#include "Eventable.h"


class MScreen : public Screenable{
private:
	DynArr* elements;
//	int width;
//	int height;
	int bufLen;
	ThreadId screenDrawingTHRDDescriptor;
public:
	char* buff;
public:
	MScreen(int width, int heigth);
	MScreen() : MScreen(80, 25) {}
	virtual ~MScreen();
	void setRatio(int width, int heigth); // ���������� ����� screen ratio (�� ��� �� ����������� ��������� :) )
	void freeElements(); // ������� ���������� ���� ����� ������
	char* getBuff(); // ���������� ����� � ���� �������(�����������) ��������
	int getWidth(); // ���������� ������ ������
	int getHeight(); // ���������� ������ ������ 
	int putToBuff(cordScr cords, char c); // �������� ������ � ����� �� ����� �����������
	int addElement(cordScr cords, int width, int heigth, Screenable* element); // �������� ������� �� ����� �� ����� �����������, ������ ��� ������ � ������
	void initBuff(); // ���������������� �����
	void clear(); // �������� ����� ������
	void draw(); // ������������ (����������)
	virtual void render(); // ������������(������������)
	virtual void catchEvent(Command_c* command, bool showHelp);
protected:
	virtual void fillEventPatterns();
public: //MScreen EVENTS
	static void exitGameCommand(Command_c* command, Eventable* oParent);
	static void renderScreenIdCommand(Command_c* command, Eventable* oParent);
	static void drawScreenIdCommand(Command_c* command, Eventable* oParent);
	static void stopThreadsCommand(Command_c* command, Eventable* oParent);
};

// exit game
// render screen id [int:id]
// draw screen id [int:id]
// stop threads


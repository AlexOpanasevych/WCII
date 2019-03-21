#pragma once
#include "pch.h"
#include "Screenable.h"
#include "DynArr.h"
#include "ScreenDrawindTHREAD.h"



class MScreen : public Screenable {
private:
	DynArr* elements;
//	int width;
//	int height;
	int bufLen;
	ThreadId screenDrawingTHRDDescriptor;
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
	char *buff;
	virtual void operateEvent(Command_c command);
private:
	void classifyEvent(Command_c command);
//MScreen COMMANDS(EVENTS)
protected:
	bool exitGameEvent(Command_c command);
	bool renderScreenEvent(Command_c command);
	bool drawScreenEvent(Command_c command);
};

#pragma once
#include "pch.h"
#include "Obj.h"
#include "cordScr.h"

class MScreen;



// ����� ��� ���� ���������, ������� ����� ���������� �� ������ (����������� �� ����)
class Screenable : public Obj {
	protected:
		cordScr cords;
		int width;
		int heigth;
		MScreen* scr;
		int layer;
	public:
		Screenable(cordScr cords, int width, int heigth, MScreen* scr);
		Screenable();
		virtual ~Screenable();
		int getWidth();
		int getHeigth();
		cordScr getCord(); //���������� ���������� 
		int setCord(cordScr cords); // ���������� ����������
		int setup(cordScr cords, int width, int heigth, MScreen* scr); // ���������������� ������� (�������� ����������, ���� �������� �������, ��� ������ � ������ � ��������� �� �����, ��� �� ����� ��������������)
		virtual void render(int layer); // ������������(������������)
		virtual void settingUp();
};


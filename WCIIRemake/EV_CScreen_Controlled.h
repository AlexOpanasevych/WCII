#pragma once
#include "EV_CScreen.h"

class ConsoleCommandController;

class EV_CScreen_Controlled : public EV_CScreen {
public:
	ConsoleCommandController* parentCCC;
public:
	EV_CScreen_Controlled(cordScr icords, int iwidth, int iheigth, CScreenPixel dafaultFill, int ilayer, ConsoleCommandController* iparentCCC);
	~EV_CScreen_Controlled();
	void move(int direction);
	void calcPlacemnt();
};


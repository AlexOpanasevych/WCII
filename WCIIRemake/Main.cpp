#include "pch.h"

Console* defaultConsole;
Controller* gameController;
extern ThreadDescriptor* gameThreads;
ConsoleCommandController* defaultConComCon;
GameMaster* gameMaster;


#include <conio.h>

class screenItem : public Screenable {
	virtual void render(int layer) {
		this->scr->putToBuff(this->cords, 't');
	}
};

int main() {
//	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

	new ThreadDescriptor();
	defaultConsole = new Console();
	defaultConComCon = new ConsoleCommandController(defaultConsole, gameController, 0);
	gameMaster = new GameMaster();

/*
	MScreen* screenMain = new MScreen(50, 30);
	screenMain->setCord(cordScr(20, 70));
	MScreen* IScreen1 = new MScreen(20, 20);
	MScreen* IScreen2 = new MScreen(20, 30);
	screenMain->addElement(cordScr(5, 5), 20, 20, IScreen1);
	screenItem item1;
	IScreen1->addElement(cordScr(0, 0), 1, 1, &item1);

	_getch();
*/


//	EventHndlrTHREAD* evHdlrThread = (EventHndlrTHREAD*)(gameThreads->getThread(gameController->getEventHandlerDescriptor()));
	GameAlifeTHREAD* HgameAlifeThread = (GameAlifeTHREAD*)(gameThreads->getThread(gameMaster->getGameAlifeTHREADDescriptor()));

	if (HgameAlifeThread) {
		HANDLE gameAlifeHandle = HgameAlifeThread->getThreadHandle();
		if (gameAlifeHandle) {
			WaitForSingleObject(gameAlifeHandle, INFINITE);
		}
	}

}

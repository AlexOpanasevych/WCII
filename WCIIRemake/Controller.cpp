#include "pch.h"
#include "Controller.h"


Controller::Controller(Field* ifield,/* MScreen* screen,*/ Console* ioconsole) {
	this->console = ioconsole;
	this->field = ifield;
	this->members = new DynArr();
}


Controller::~Controller() {
}

Command_c Controller::getCommand() {
	string command;
	command = console->getLine();
	return parseCommand(command);
}


bool Controller::readCondition(char character) {
//	if ((isalnum(character) || character == '-') && character != 0) {
	if ((character != ' ') && character != 0) {
		return true;
	}
	return false;
}

string Controller::commandType(char character) {
	if (character == '-') {
		return "flag";
	}
	if (isalpha(character)) {
		return "command";
	}
	if (isdigit(character)) {
		return "number";
	}
	return "unknown";
}

pair <string, string> Controller::nextToken(string command) {
	bool readBegin = true;
	pair <string, string> temp;
	while (!readCondition(command[ParserPosition])) {
		if (command[ParserPosition] == 0) {
			temp.first = "\0";
			temp.second = "end";
			return temp;
		}
		ParserPosition++;
	}

	while (readCondition(command[ParserPosition])) {
		temp.first += command[ParserPosition];
		if (readBegin) {
			temp.second = commandType(temp.first[0]); // add better classification for commands
		}
		readBegin = false;
		ParserPosition++;
	}
	return temp;
}


void Controller::initParser() {
	ParserPosition = 0;
}

Command_c Controller::parseCommand(string command)
{
	initParser();
	pair <string, string> temp;
	Command_c command_c;
	temp = nextToken(command);
	for (int i = 0; temp.second != "end"; i++) {
		command_c.args.push_back(temp);
		temp = nextToken(command);
	}
	return command_c;
}

void Controller::throwCommand(Command_c command) {

	command.printCommand();

	for (int i = 0; i < members->count(); i++) {
		members->get(i)->operateEvent(command);
	}
}



void Controller::EventHandler() {
	cout << "HandleEvent" << endl;
	while (true) {
		throwCommand(getCommand());
	}
}



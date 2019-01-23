/*Gary Zeri
ID: 2321569
zeri@chapman.edu
CPSC298-01
Assignment 1, Ch1 Ex1
Program to take meeting room capacity, and number of individuals attending the meeting to inform whether or not holding the meeting is legal.*/

#include "Menu.h"
using namespace std;

//declare all function prototypes here
void checkLegality(int roomCapacity, int attendees);

/////////////////////////////////////////////////////////////////////

int main(){

	Menu menu;
	menu.addText("TurboLaw\nMeeting Safety Software, Enterprise Edition\n");

	//loop for to ensure main program can be rerun	
	do{
		menu.display();
		checkLegality(menu.parseNumber("What is the maximum capacity of the meeting room?\n"),
				menu.parseNumber("How many people will be attending the meeting?\n"));

	}while(menu.parseBool("Would you like to check if another meeting is legal? y/n\n"));
	
	return 0;
}

/////////////////////////////////////////////////////////////////////

//checkLegality function
//has a void return
//roomCapacity, float for how many individuals can fit into a room
//attendees, number of individuals attending the meeting
void checkLegality(int roomCapacity, int attendees){

	Menu menu;
	string people;

	//check if people should be singulaar or plural
	if(roomCapacity - attendees > 1 || roomCapacity - attendees < -1)
		people = " people";
	else
		people = " person";

	if(attendees > roomCapacity){
		menu.addText("\n\nLegal Alert! Legal Alert!\n");
		menu.addText(to_string(attendees) + people + " can not safely attend the meeting!\n");
		menu.addText(to_string(attendees - roomCapacity) + people + "must leave the meeting in order for fire safety regulations to be followed.\n");
	}
	else if(attendees < roomCapacity){
		menu.addText("\n\nThis meeting is within the fire safety code.\n");
		menu.addText(to_string(roomCapacity - attendees) + " more" + people + " can can still safely attend the meeting.\n");
	}
	else
		menu.addText("\n\nYou are at meeting room capacity, as long as no more individuals attend this meeting, it is legal for it to be held.\n");
	

	menu.display();
}

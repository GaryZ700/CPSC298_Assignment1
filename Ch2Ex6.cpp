/*Gary Zeri
ID: 2321569
zeri@chapman.edu
CPSC298-01
Assignment 1, Ch1 Ex1
Program that takes the weight and radius of a sphere and states whether that sphere will either sink or float in the water.*/

#include <iomanip>
#include <cmath>
#include "Menu.h"
using namespace std;

//declare all constants here
const float FLUID_SPECIFIC_WEIGHT = 62.4;

//declare all function protypes here
void floatCheck(float weight, float radius);

/////////////////////////////////////////////////////////////////////

int main(){

	Menu menu;
	menu.addText("Floating Sphere Checker\n");
	
	//loop to allow user to rerun program
	do{
		menu.display();
	
		floatCheck( menu.parseNumber("Please enter the weight of the sphere in pounds: "),
			menu.parseNumber("Please enter the radius of the sphere in feet: "));
	}while(menu.parseBool("Would you like to check the floating abillities of another sphere? y/n\n"));

}

/////////////////////////////////////////////////////////////////////

//floatCheck function
//has a void return
//weight, float of weight for the sphere
//radius, float of radius for the sphere
void floatCheck(float weight, float radius){

	Menu menu;
	ostringstream output;	
	output << "\nA sphere with a radius of " << radius << " ft. and weighing " << weight << " lbs. will ";


	//compute the volume of the object
	float volume = M_PI * (4/3) * pow(radius, 3);

	//compute the buoyant force
	float buoyantForce = volume * FLUID_SPECIFIC_WEIGHT;

	if(buoyantForce >= weight)
		output << "float ";
	else
		output << "sink ";

	output << "in water.\n";
	menu.addText(output.str());
	menu.display();

}

/*Gary Zeri
2321569
zeri@chapman.edu
CPSC298-01
Assignment 1, Ch1 Ex1
Program to take the weight of a box of cereal in ounces and then output the weight of the box in metric tons, and how many boxes would be needed for a ton of cereal.*/

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//check if running on linux/max or Windows to determine screen clear command
#ifdef _WIN32
	const char* CLEAR = "cls";
#else
	const char* CLEAR = "clear";
#endif

//declare all constant variables here
const float OZ_IN_TON = 35273.92;
const string SPACE = "     ";

//declare all function prototypes here
void introText();
void inputErrorMsg();
void displayResults(float oz, float ozInTon);
bool repeat();
void clearInput();

/////////////////////////////////////////////////////////////////////

int main(){

	do{

		//declare all local variables here
		float oz;

		//display introduction text to the user	
		introText();

		cin >> oz;

		//check if input from user was of the correct type
		while(cin.fail()){
			
			//reset the input stream 
			clearInput();

			inputErrorMsg();
			cin >> oz;
		}
		
		displayResults(oz, OZ_IN_TON);
	
	}while(repeat());

	return 0;
}

/////////////////////////////////////////////////////////////////////
//All function defined here

/*introText function
   void return */
void introText(){

	system(CLEAR);

	cout << "\nThe Allmighty Ceral Weight ConverterTron (Patent Pending)\n\n";
	cout << SPACE << "This program takes the weight of a box of cereal in ounces, outputs the weight of the box in metric tons,\n";
	cout << SPACE << "and then states how many boxes would be required to have a ton of cereal.\n";

	cout << "\n \nCereal Weight in Ounces: ";
}

//-------------------------------------------------------------------

/*inputErrorMsg function
 * void return */
void inputErrorMsg(){

	system(CLEAR);

	cout << "\nWoah there buddy! \n";
	cout << "I not sure what you just typed in...but it sure wasn't a number!!\n";
	cout << "Let's try this again,\n";
	cout << "\n\nCeral Weight in Ounces: ";

}

//-------------------------------------------------------------------

/*displayResults function
 * void return */
void displayResults(float oz, float ozInTon){
	
	float ton = oz / ozInTon;
	float boxesInTon = ozInTon / oz;

	system(CLEAR);

	cout << "\nThe Allmighty Ceral Weight ConverterTron (Patent Pending), has completed its calculations!\n";
	cout << "\n\nWeight of Box in Tons: " << ton << "\n\n";
	cout << boxesInTon << " boxes are needed to have a ton of cereal.\n(Warning!! This value is computed for theortical purposes only. Actual consumption of a ton of ceral has been known to cause health issues according to the Surgeon General.)\n";

}

//-------------------------------------------------------------------

/*repeat function
 * returns bool depending on whether or not the user would like to rerun the program. */
bool repeat(){

	char input;

	cout << "\n\nWould you like to perform another cereal calculation? y/n\n\n";

	cin >> input;

	while(true){

		if(input == 'y' || input == 'Y')
			return true;
		else if(input == 'n' || input == 'N') 
			return false;

		cout << "Try again, that was a wrong answer!\n";
		cin >> input;

		clearInput();
	}

}

//-------------------------------------------------------------------

/*clearInput function
 * void return */
void clearInput(){

	cin.clear();
	cin.ignore(10000, '\n');
}

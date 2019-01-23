/*Gary Zeri
2321569
zeri@chapman.edu
CPSC298-01
Assignment 1, Ch1 Ex1
Program to calculate 6 months retroactive pay due to an employee, the employee's new salary, and the employee's new monthly salary based on a percentage pay increase.*/

#include <iomanip>
#include "Menu.h"
using namespace std;

//constants declared here
const double PAY_INCREASE = 0.076;

//declare function prototypes here
void displayNewSalary(float previousSalary);

/////////////////////////////////////////////////////////////////////

int main(){

	float employeePay;

	Menu menu;
	menu.addText("Retroactive Pay Cacluator 9000\n\n");
	
	//loop for to ensure main program can be rerun	
	do{

	menu.display();
	displayNewSalary(menu.parseNumber("Please Enter Employee's Previous Annual Salary: $"));

	}while(menu.parseBool("Would you like to perform another calculation? y/n \n"));
	
	return 0;
}

/////////////////////////////////////////////////////////////////////

//displayNewSalary function
//has a void return
//previousSalary, float of what employee was previsouly paid 
void displayNewSalary(float previousSalary){

	float yearlySalary = previousSalary * (1 + PAY_INCREASE);
	float monthlyPay = yearlySalary / 12.0;
	float retroactivePay = monthlyPay * 6.0;

	ostringstream output;
	output << fixed << setprecision(2);
	output << "\n\nRetroactive Pay Due: $" << retroactivePay;
	output << "\nNew Yearly Salary: $" << yearlySalary;
	output << "\nNew Monthly Pay: $" << monthlyPay << "\n";	

	Menu menu;
	menu.addText(output.str());	
	menu.display();
}


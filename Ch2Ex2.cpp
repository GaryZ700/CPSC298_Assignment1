/*Gary Zeri
ID: 2321569
zeri@chapman.edu
CPSC298-01
Assignment 1, Ch2 Ex2
Program to how long it will take to pay of a debit with a certain interest rate and montly payment.*/

#include <iostream>
using namespace std;

//declare all constants here
const float DEBIT = 1000;
const float MONTHLY_INTEREST_RATE = 0.015;
const float MONTHLY_PAYMENT = 50;

/////////////////////////////////////////////////////////////////////

int main(){

	float debit = DEBIT;	
	int loopCounter = 0;

	//loop to count number of months to pay off debit
	while(debit > 0){
		
		//add interest to debit
		debit *= 1+MONTHLY_INTEREST_RATE;
		
		//check if monthly payment is greater than total remaining debit
		if(debit >= MONTHLY_PAYMENT)
			debit -= MONTHLY_PAYMENT;
		else
			debit = 0;
		
		loopCounter += 1;
	}

	cout << "In order to pay off a debit of $" << DEBIT << " at a monthly interest rate of " << MONTHLY_INTEREST_RATE*100 << "% with monthly payments of $" << MONTHLY_PAYMENT << ", it will take " << loopCounter << " months to pay off the debit.\n";

}

/////////////////////////////////////////////////////////////////////



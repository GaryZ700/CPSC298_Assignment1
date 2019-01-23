/*Gary Zeri
ID: 2321569
zeri@chapman.edu
CPSC298-01
Assignment 1, Ch1 Ex1
Program to find and print all of the prime numbers between 3 and 100.*/

//declare all constants here
const int MAX_RANGE = 100;
const int MIN_RANGE = 3;

#include <iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////

int main(){

	bool anyPrime = false;
	cout << "List of prime numbers between " << MAX_RANGE << " and " << MIN_RANGE << ":\n";

	//loop to iterate over all numbers from min to max range
	for(int i=MIN_RANGE; i<=MAX_RANGE; ++i){
	
		//loop to check if number i is prime
		for(int j=2; j<=i; j++){
		
			//if checked all numbers less than i, 
			//then i must be a prime number, and it wil be added to the arry of prime numbers
			if(j==i){

				anyPrime = true;
				cout << "	" << i << "\n";
			}

			//check if i can be evenly divided by a number that is not itself or 1, if yes, then break this loop because the number is not prime
			else if(i%j == 0)
				break;

		}
	
	}

	//if there are no prime numbers then tell that to the user
	if(!anyPrime)
		cout << "	NO PRIME NUMBERS FOUND!\n";  

	
}

/////////////////////////////////////////////////////////////////////



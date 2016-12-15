// this porgarm to reads the resistances of the four resistors and computes the total resistance.

#include<iostream>		// required for cout, cin, endl (language).
using namespace std;	 // compiler use library names.

int main()		// startting point.
{			// code blocks, statements enclosed.

	float Rp, Rt, R1, R2, R3, R4;			// declaring and initialize varible.

	
	cout<< "Enter the value of R1: "<<endl;		// output the statment for the user to enter R1.
	cin>> R1;		 //allow the user to input the resistor R1.

	cout<< "Enter the value of R2: "<< endl;	// output the statment for the user to enter R2.
	cin>> R2;			// allow the user to input the resistor R2.

	cout<< "Enter the value of R3: "<< endl;		// output the statment for the user to enter R3.
	cin>> R3;			//allow the user to input the resistor R3.

	cout<< "Enter the vaule of R4: "<< endl;	 // output the statment for the user to enter R4.
	cin>> R4;			//allow the user to input the resistor R4.

	Rp =  ( 1/ ( (1/R2) + (1/R3) + (1/R4) ) );	// calculate the total parallel resistances R2, R3 and R4.

	Rt = R1 + Rp;		// computes the total resistance.

	cout.setf(ios::fixed);
	cout.precision(2);

	cout<< "The total resistance is = "<< Rt<< endl; // outputing the result.
	

	system("pause");	 //  to pause the program.
	return 0;	// exit program.
}				// code blocks, statements enclosed, end of the program.
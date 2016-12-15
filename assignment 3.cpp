// this program to evaluate the source voltage Vs.

#include<iostream>		// required for cout, endl.
#include<cmath>			// required for square root and power.
using namespace std;	// compiler use library namees.

const double R = 10, P = 260, Vt = 120;	// define the constants.

int main()		// startting point.
{		// code blocks, statements enclosed.

	double pf, Vs;	// declaring and initialize varible.
	cout<< " Enter the power factor pf: " << endl;		// output the statment for the user to enter power factor.
	cin>> pf; 		//allow the user to input the power factor pf.

	Vs = sqrt ( pow( Vt + (2*R*P)/Vt, 2 ) + pow( (2*R*P)/(pf*Vt), 2) * ( 1 - pow(pf, 2)) ); // calculating the source voltage Vs.

	cout.setf(ios::fixed); // required for fixe dicemal points.
	cout.precision(2);		// cout two dicemal points.

	cout<< " The value of the source voltage Vs = " << Vs << endl; // outputing the result.


	system("pause");	//  to pause the program.
	return 0;		// exit program.

} 	// code blocks, statements enclosed, end of the program.
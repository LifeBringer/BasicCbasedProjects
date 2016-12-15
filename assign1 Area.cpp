// this programe will compute the area A of any ellipse.

#include<iostream>		// required for cout, cin, endl (language).
using namespace std;		// compiler use library names.

const double PI = 3.1415;		// define the constant pi.

int main()		// startting point.
{			// code blocks, statements enclosed.
	
	double A, a, b;		// declaring and initialize varible.
	cout <<" Enter the first length a = "  << endl;		// output the statment for the user.
	cin>> a;		// allow the user to input the first length a.
	cout << " Enter the second length b = "  << endl;		// output the statment for the user.
	cin>> b;		// allow the user to input the second length b.
	
	A = PI * a * b;		// calculating Area.

	cout.setf(ios::fixed); // required for fixe dicemal points.
	cout.precision(2);		// cout two dicemal points.

	cout << " The area of the ellipse = "<< A << endl;		// outputing the result.


	system("pause");	 //  to pause the program.
	return 0;	 // exit program.
}		// code blocks, statements enclosed, end of the program.

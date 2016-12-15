
//this program will determines whether the blue car was speeding.

#include <iostream> // required for cout, cin, endl (language).

using namespace std; // compiler use library names.

const double m1= 907.1847, v1= 0, v3= 13.4112; // defind constant.

int main ()  // startting point.
{			// code blocks, statements enclosed.
	double m2, v2; // declaring and initialize varible.

	cout << "Enter the wight of the blue car in kg m2 = " << endl; // output the statment for the user.

	cin >> m2; // allow the user to enter the weight of the blue.

	
	v2 = ( ( (m1 + m2) * v3 ) - (m1 * v1) ) / m2; // calculating the speed.

	cout << "The blue car's speed is =" << v2<< endl; // output the speed of the blue.
	
		if ( v2 <= 29.0576 ) // if condition to test the speed of the blue car and determain whether the blue car were speeding or not.
			{
				cout << "so the blue car was not speeding "<<endl; // output if the condition is true.
			}
		else 
			{
				cout << "so the blue car was speeding "<<endl; // output if the condition is false.
			}

		system("pause");	 //  to pause the program.
	return 0;	 // exit program.
}		// code blocks, statements enclosed, end of the program.

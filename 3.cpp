
// this program will print out the table showing the meter voltage corresponding to water temperatures varying from 0 °C to 100 °C in increments of 10 degrees.

#include <iostream> // required for cout, cin, endl (language).

using namespace std; // compiler use library names.

int main()   // startting point.
{			// code blocks, statements enclosed.

   double T, Vm; // declaring and initialize varible T, Vm.

	for ( T=0; T<= 100; T+= 10) // for (repetation statment) to print values of T as long as the condition is true.
	{

		Vm = (20 * T + 2000)/(250 + T); // the equation that will be used to find out the Vm for each amount of T.

		cout << "When the temperuter is "<< T << ", the meter voltag is "<< Vm <<endl; // This is the output message the user will get to show table values of T and Vm. 
	}

  system("pause");	 //  to pause the program.
	return 0;	 // exit program.
}		// code blocks, statements enclosed, end of the program.

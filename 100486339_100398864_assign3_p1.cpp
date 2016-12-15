/* ========================================================
 *											*
 *				Members 1: (Me)						*
 *											*
	========================================================*/

// Purpose: This program outputs the mean and deviation of inputed \
variables

#include<iostream>
#include<iomanip>

using namespace std;

// Compute the mean of an array of double values 
double mean(const double x[], int size) {
	double sum(0);
	//Sums every x-point of the array
	for (int i=0; i < size; i++) {
		sum += x[i];}
	//Prevents division by 0
	if (size != 0) {return sum/(double)size;
	} else {return -1;}
}

// Compute the deviation of double values 
double deviation(const double x[], int size) {
	double ave = mean(x, size);
	double dev(0);
	// Summing the square of the x-mean difference 
	for(int i(0); i < size; i++) {
		double a = x[i] - ave;
		dev += a*a;
		//dev += pow(x[i] - ave, 2.);
	}
	// Checks that we're not dividing by 0
	
	if(size != 0) {
		return sqrt(dev/((double)size-1));
	} else { return -1;}
}

int main() {
	// Repeat is set to 'C' to prevent accidental output loss
	char repeat;
	//The do is used to check the repeat flag after the first run
	do { 
		//Setting the length of the input values.
		double x[10];
		const int n = 10;
		cout << "Enter the 10 numbers: ";
		cin >> x[0] >> x[1] >> x[2] >> x[3] >> x[4] >> x[5] >> x[6] >> x[7] >> x[8] >> x[9];
		//Makes sure the user entered the right number of points
		//if (sizeof x/sizeof(int) == 10) {
			cout << "The mean is " << setprecision(3) << mean(x, n) << endl; 
			cout << "The deviation is " << fixed << setprecision(5) << deviation(x, n) << endl;
		//} else { cout << "Please enter the right number of digits" << endl;}
		cout << "Would you like to continue? Enter 'Y' to continue or 'E' to exit. ";
		cin >> repeat;
		cout << endl << endl;
		if (repeat == 'E') {exit(0);}
	} while (repeat == 'Y' || repeat == 'y' || repeat == 'C');

	return 0;
}


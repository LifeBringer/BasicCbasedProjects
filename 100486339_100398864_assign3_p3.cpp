/* ========================================================
 *											*
 *				Members 1: (Me)						*
 *											*
	========================================================*/

/* Purpose: Determines the voltage output of an amplifer
depending on the values set for input voltage, resistors,
and type of amplifier selected. */

#include<iostream>
#include<string>
#include<cmath>

using namespace std;

double v_output(double g, double vi, double vsat, double R1, double R2);
double inverting_amplifier(double vi, double vsat, double R1, double R2);
double noninverting_amplifier(double vi, double vsat, double R1, double R2);
double voltage_divider_amplifier(double vi, double vsat, double R1, double R2);

int main () {
	// Repeat is set to 'C' to prevent accidental output loss
	char repeat('C');
	do {
		// V saturated is outlined by the problem question as 15 volts
		const double vsat(15.0);
		double g(0), R1(0), R2(0), vi(0), voutput(0);
		cout << " Please enter the input voltage: "; cin >> vi; 
		
		cout << "\n The input voltage is v1 = " << vi << " V." << endl;
		// The following daisy chains the values from one input into the other. \
		 There might be a problem with the sample output, where the R1 and R2 may be switched.
		int noninvert_output = ceil(noninverting_amplifier(vi, vsat, 75, 5));
		cout << " The output voltage of the non-inverting amplifier is v2 = " << noninvert_output << " V." << endl;

		int volt_divider_output = ceil(voltage_divider_amplifier(noninvert_output, vsat, 25, 75));
		cout << " The output voltage of the voltage divider amplifier is v3 = " << volt_divider_output << " V." << endl;

		int invert_output = ceil(inverting_amplifier(volt_divider_output, vsat, 15, 15));
		cout << " The output voltage of the inverting amplifier v4 = " << invert_output << " V." << endl;

	cout << "\n Would you like to continue? Enter 'C' to continue or 'E' to exit. ";
	cin >> repeat;
	cout << "\n" << endl;
	} while (repeat == 'C' || repeat == 'c');
	cout << "\n" << endl;
	return 0;
}

//Takes the initial conditions and returns the final v ouput
double v_output(double g, double vi, double vsat, double R1, double R2) {
	double v_output(-1);
	// Applies modifications for certain condition checks
	double vi_g = g*vi;
	double neg_vsat = -1*vsat;
	// Checks the conditions to set v_output to the approriate value
	if (vi_g > vsat) {
		v_output = vsat;
	} else if (abs(vi_g)) {
		v_output = vi_g;
	} else if (vi_g < neg_vsat) {
		v_output = neg_vsat;
	} else { cout << " Invlaid input, check your values." << endl; return -1;}
	return v_output;
}

//The difference in amplifiers is only defined by how g is calculated \
the following functions determines the appropriate g and returns the output
double inverting_amplifier(double vi, double vsat, double R1, double R2) {
	const double g = -R1/R2; //Gain of the circuit by the inverting amplifier
	return v_output(g, vi, vsat, R1, R2);
}

double noninverting_amplifier(double vi, double vsat, double R1, double R2) {
	const double g = 1+(R1/R2); //Gain of the circuit by the noninverting amplifier
	return v_output(g, vi, vsat, R1, R2);
}

double voltage_divider_amplifier(double vi, double vsat, double R1, double R2) {
	const double g = R2/(R1+R2); //Gain of the circuit by the voltage divider amplifier
	return v_output(g, vi, vsat, R1, R2);
}

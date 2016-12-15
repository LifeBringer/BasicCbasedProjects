/* ========================================================
 *															*
 *				Members 1: Ramiz Alda (100398864)			*
 *											*
	========================================================*/

// Purpose: This program converts decimal or base 10 digits \
into roman numeral characters

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

int main() {
	int input;
	cout << " Please enter an integer (less than 4000) to convert into a roman numeral: ";
	cin >> input;
	
	// We extract the numbers of individual place values
	int ones(input%10), tens(input%100/10), hundreds(input%1000/100), thousands(input%10000/1000);

	// Alternatively we could have coverted the above into base 5

	if (input > 3999 || thousands >= 4) {
		cout << " The value entered must be less than 4000";
		
	} else {
		cout << " The roman numeral form of " << input << " is ";

		for (int place(4); place > 0; place--) {
			int place_val;
			string numeral, numeral_half, next_numeral;
			// sets place value currently outputted for, base 5 \
			would have had 6 switches instead of 3
			switch (place) {
			case 1:
				place_val = ones;
				numeral = "I";
				numeral_half = "V";
				next_numeral = "X";
				break;
			case 2:
				place_val = tens;
				numeral = "X";
				numeral_half = "L";
				next_numeral = "C";
				break;
			case 3:
				place_val = hundreds;
				numeral = "C";
				numeral_half = "D";
				next_numeral = "M";
				break;
			case 4:
				place_val = thousands;
				numeral = "M";
				numeral_half = "";
				next_numeral = "";
				break;
			default:
				cout << "You managed to break me!" << endl;
				break;
			}
			// Outputs roman numerals per decimal place value
			if (place_val == 1) {
				cout << numeral;
			} else if (place_val == 2) {
				cout << numeral << numeral;
			} else if (place_val == 3) {
				cout << numeral << numeral << numeral;
			} else if (place_val == 4) {
				cout << numeral << numeral_half;
			} else if (place_val == 5) {
				cout << numeral_half;
			} else if (place_val == 6) {
				cout << numeral_half << numeral;
			} else if (place_val == 7) {
				cout << numeral_half << numeral << numeral;
			} else if (place_val == 8) {
				cout << numeral_half << numeral << numeral << numeral;
			} else if (place_val == 9) {
				cout << numeral << next_numeral;
			} else {
				// for 0s
				cout << "";
			}
		}
	}
	cout << "\n" << endl;
	system("pause");
	return 0;
}

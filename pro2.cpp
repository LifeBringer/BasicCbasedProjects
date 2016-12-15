
// this program will check a credit card number whether it's vaild or invaild.

#include<iostream>		// required for cout, cin, endl (language).

using namespace std;		// compiler use library names.

int main()	// startting point.

{			// code blocks, statements enclosed.

	int num;		// declaring and initialize varibles that will be used in the program.
	int num1;
	int num2;
	int digit1;
	int digit2;
	int sum1=0;
	int sum2=0;
	int sum=0;
	char c;

	cout<<"Enter the credit card number: "<<endl; // output the statmet for the user.

	cin>>num; // allow the user to enter the credit card number.

	num1 = num;	// define integer to integer.
	num2 = num;

	if (num>= 10000000 && num<= 99999999)   // if condition to check if the number entered is 8 digit or not.
	{		// if the ( if ) condition is true.
			for (int i = 0; num1> 0; i++) // repetation statment to get values of i, for the first process.
				{
					digit1 = num1 %10; // to get the reminder.
					if (i % 2==0)	// check if the divition by 2 get reminder 0 (even numbers).
					{
						sum1 +=digit1; // if the condition is true sum the numbers.
					}	
					num1 /=10; // if the condition false.
				} 

		for (int z = 0; num2> 0; z++) // repetation statment to get values of i, for the second process.
		{
			if (z % 2 !=0 ) // check if the divition by 2 get reminder not equal 0 (odd numbers)
			   {
					digit2 = num2 % 10; // to get the reminder.
					digit2 *=2;  // double the numbers.
					while (digit2 >0) // while condition.
					{ sum2 += digit2 %10; // to sum the double nmubers
					digit2 /= 10;
					}
			}
				num2 /=10; // if the condition is false.
			} 

		sum = sum1 +sum2; // add the two processes.

		if (sum % 10 == 0) // check the last digit whether it's zero or not.

			{ 
			cout<<"The credit card number is valid"<<endl; // the output if the condition is true ( the last digit is zero).
		}
		else
			{
			cout<<"The credit card number is not valid"<<endl; // the output if the condition is false ( the last digit is not zero).
		} 
	}
	
	else // if the if condition is false ( the number is not contain 8 digits).
	{
		cout<<"incorrect input, the credit card number should contain 8 digits"<<endl; // the output if the condition is false.
	}

	cout <<"press letter c if you might to continue checking more number or e to exit"<<endl; // output to tell the user whether to continou or exit.
	cin >> c; // allow the user to enter the decision.

	while( c != 'e') // if the diecision is to continou.
	{
		system("pause"); //  to pause the program.
	}
	
	return 0; // if it's not exit the program.
}
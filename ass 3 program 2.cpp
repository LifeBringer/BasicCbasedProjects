#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
using namespace std;



//Main fuction to run program
int main()
{
	int chipherKey=5; // set chipher key to 5
	char ch;
	cout<<"Welcome to ENGR1200U Cryptographic Techniques Program"<<endl;
	do{
		cout<<"Please enter your selection:"<<endl;
		cout<<"1. Encrypt"<<endl;
		cout<<"2. Decrypt"<<endl;
		cout<<"Your Choice : ";
		cin>>ch;//Get user choice
		if(ch=='1')// if 1 then encrypt file
		{
			const string AFILE = "hello.txt";//file to read from
			const string BFILE = "hello.out";//file to write
			ifstream afile;
			ofstream bfile;
			/*  Open input files.  */
			afile.open(AFILE.c_str());
			if (afile.fail()){
				cerr << AFILE << " failed to open.\n";
				exit(1);
			}
			/*  Open output files.  */
			bfile.open(BFILE.c_str());
			if (bfile.fail()){
				cerr << BFILE << " failed to open.\n";
				exit(1);
			}
			do
			{
				/*  Get the character file.  */
				char a;
				afile.get(a);
				if (a>=65 && a<=90) {
					a = (a-'A'+chipherKey)%26+'A'; //encrypt using formula
				}
				/*  put the character in file.  */
				bfile.put(a);
			}while (!afile.eof());// read until file ends
			afile.close();// close file
			bfile.close();// close file
		}
		else if(ch=='2')// if 2 then decrypt file
		{
			const string AFILE = "new_hello.txt";//file to write
			const string BFILE = "hello.out";//file to read
			ifstream afile;
			ofstream bfile;
			/*  Open input files.  */
			bfile.open(AFILE.c_str());
			if (bfile.fail()){
				cerr << AFILE << " failed to open.\n";
				exit(1);
			}
			/*  Open output files.  */
			afile.open(BFILE.c_str());
			if (afile.fail()){
				cerr << BFILE << " failed to open.\n";
				exit(1);
			}

			do
			{
				/*  Get the character file.  */
				char a;
				afile.get(a);
				if (a>=65 && a<=90){
					a = (a+'A'-chipherKey)%26+'A'; //decrypt using formula
				}
				/*  put the character in file.  */
				bfile.put(a);
			}while (!afile.eof());// read until file ends
			afile.close();// close file
			bfile.close();// close file
		}
		else// if not 1 or 2 then inform user and read choice again
		{
			ch='C';
			cout<<"Invalid Choice!!! Try Again"<<endl;
			continue;// skip next statements of loop and start from begining
		}
		cout<<"Press C to Continue, E to exit"<<endl;
		cin>>ch;
	}while((ch!='E' || ch!='e') && (ch=='c' || ch=='C'));// if c or C is entered then restart loop else exit

	system("pause");
	return 0;
}
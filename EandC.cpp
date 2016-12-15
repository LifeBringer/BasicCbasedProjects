// this program will encrypting and decrypting files using functions.
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
/**************************************************************
* This function displays the menu options as in the handout *
**************************************************************/
void displayMenu()
{
	// 1. Get user input (e.g. encrypt/decrypt and filenames)
	// 2. Call the appropriate function(s) to process encryption/decryption
	// 3. Then, get user input to continue or exit the program
	string line;
	int choice;
	string infile, outfile;
	while(true)
	{
		cout<<"Welcome to ENGR1200U Cryptographic Techniques Program"<<endl;
		cout<<"Please enter your selection:"<<endl;
		cout << "1. Encrypt" << endl;
		cout << "2. Decrypt" << endl;
		cout << "3. Exit the program or press any key to continue" << endl;
		getline(cin, line);
		choice = atoi(line.c_str());
		if(choice == 1) // get encrypt choice
		{
	cout << "Enter file name to encrypt: "; //let the user enter the name of the file which want to be encrypted
	cin >> infile;
    cout << "Enter output file name: "; // put name for the new file 
	cin >> outfile;
	encrypt(infile, outfile);
		}
		else if(choice == 2) // get the decrypt choice
		{
	 cout << "Enter file name to decrypt: ";//let the user enter the name of the file which want to be decrypted
	 cin >> infile;
	 cout << "Enter output file name: "; // put name for the new file 
	 cin >> outfile;
     decrypt(infile, outfile);
		}
		else if(choice == 3) // exit the program
			break;
	}
}
/**************************************************************
* This function encrypts the content of infile and saves the *
* encrypted text into outfile *
* @param infile string (file that has raw text) *
* @param outfile string (file that will have encrypted text) *
**************************************************************/
void encrypt(string infile, string outfile)
{
	fstream fi(infile.c_str(), ios::in); // open the file that will encrypt from
	if(!fi.is_open())
	{
	cout << "Fail to open " << infile << endl; // check to see if there are any issues with opening the file
	exit(1); // terminate the program
	}
	fstream fo(outfile.c_str(), ios::out); // open the file that will have encrypted file
	if(!fo.is_open())
	{
	cout << "Fail to open " << outfile << endl; // check to see if there are any issues with opening the file
	fi.close();
	exit(1); // terminate the program
	}
	char c;
	while(!fi.eof()) 
	{
		c = fi.get();
		if(fi.eof())
			break;
		fo << ceaserCipher(c, key); // saves the encrypted in the new file
	}
	fi.close(); // close files 
	fo.close();
}
/**************************************************************
* This function decrypts the content of infile and saves the *
* decrypted text into outfile *
* @param infile string (file that has encrypted text) *
* @param outfile string (file that will have decrypted text) *
**************************************************************/
void decrypt(string infile, string outfile)
{ 
	fstream fi(infile.c_str(), ios::in); // open the file that will decrypt from
	if(!fi.is_open())
	{
	cout << "Fail to open " << infile << endl; // check to see if there are any issues with opening the file
	exit(1); // terminate the program
	}
	fstream fo(outfile.c_str(), ios::out); // open the file that will have encrypted file
	if(!fo.is_open())
	{
	cout << "Fail to open " << outfile << endl; // check to see if there are any issues with opening the file
	fi.close();
	exit(1); // terminate the program
	}
	char c;
	while(!fi.eof())
	{
		c = fi.get();
		if(fi.eof())
			break;
		fo << ceaserDecipher(c, key); // saves the decrypted in the new file
	}
	fi.close(); // close files
	fo.close();
}
int key = 5;
/**************************************************************
* This function takes an character and a cipher key to return *
* an encrypted character. *
* @param c is a char (the character to be encrypted) *
* @param key is an integer (cipher key given in the handout) *
**************************************************************/
char ceaserCipher(char c, int key)
{
  if(c >= 'a' && c <= 'z')
	return (char)(((int)c-(int)'a' + key) % 26  + (int)'a');//encrypted it as (ASCII code - 97 + key) % 26 + 97
  else if(c >= 'A' && c <= 'Z')
	return (char)(((int)c-(int)'A' + key) % 26  + (int)'A');//encrypted it as (ASCII code - 65 + key) % 26 + 65
  else  return c;
}
/**************************************************************
* This function takes an encrypted character and a cipher key *
* to return a decrypted character. *
* @param c is a char (the character to be decrypted) *
* @param key is an integer (cipher key given in the handout) *
**************************************************************/
char ceaserDecipher(char c, int key)
{
	if(c >= 'a' && c <= 'z')
	{
		int x = (int)c - (int)'a' - key;	//Reverse the encryption as ASCII - 97 - key
		if (x < 0) x += 26;					//If underflow, add 26
		x = x % 26;							//mod with 26
		x += (int)'a';						//add back 97
		return (char)x;
	}
	else if(c >= 'A' && c <= 'Z')
	{
		int x = (int)c - (int)'A' - key;
		if (x < 0) x += 26;
		x = x % 26;
		x += (int)'A';
		return (char)x;
	}
	else
		return c;
}
/**************************************************************
* This is the main function of the program. *
* @return a value to terminate the program successfully *
**************************************************************/
int main()
{
	displayMenu();
	return 0;
}
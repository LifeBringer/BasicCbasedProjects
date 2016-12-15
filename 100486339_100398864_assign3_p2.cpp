#include <iostream>
#include <iomanip>

using namespace std;


void addsub(int a, int& sub, int add)
{   
  sub = a - 1;   
  add = a + 1;
}
int main()
{ 
  int a = 5; 
  int b = 0;  
  int c = 0;  
  addsub(a, b, c); 
  cout << "Subtract = " << b << ", Add = " << c;
  system("pause");
 return 0;
}
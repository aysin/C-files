// Aysin ORuz
// Lab 2
// Editor: JNotePad
// Compiler: Xcode
//



#include <iostream>
using std::cout;
using std::cin;
using std::endl;


#include <string>
using std::string;

#include <cstdlib>

int main()
{
  int n;
  int a;
  int b;
  string buf;
    
  // Print out the name and lab
  cout << " Aysin Oruz - 1331735 \n";
  cout << " Lab 2, Part B \n";
  cout << " Computer Science 165 \n";
    
  while (true)
   {
    //promt to user enter or quit
    cout << " Enter five digit number please or Q to quit \n";
    cin >> buf; n = atoi (buf.c_str());
    cin.ignore(1000,10);
    
    if( buf[0] == 'q' || buf[0] == 'Q') break;
    
    a = n % 10;      // geting the percentage of the number
    b = n / 10000;   // dividing the number to 100000
        
    if ( ! a == b )
    {
      cout << "This is not a palindrome \n";
      continue;
    }

    // checking the palindrome
    n = n % 10;
    n = n / 100;
     
     if ( a == b ) cout << " This is palindrome\n";
     else cout << " This is not a palindrome\n";
    
    }
}
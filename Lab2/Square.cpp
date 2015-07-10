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
  int a;
  int b;
  int num=0;
  string buf;
    
  //initialize a and b
  a = 1;
  b = 1;
    
  // Print out the name and lab
  cout<<" Aysin Oruz - 1331735 \n";
  cout<<" Lab 2, Part A \n";
  cout<<" Computer Science 165 \n\n";
    
  // ask user to repeat the process again at end of the first promt
  while( true )
  {
   a=1;
   cout << "Please enter size of square between #1-20: \n";
   cin >> buf; num = atoi (buf.c_str());
   cin.ignore(1000, 10);
       
   if( num < 1 || num > 20 )
   break; 

   //process of printing square
   while ( num >= a)
   {
     b = 1;
     while ( num >= b )
       {
        if ( a == 1 || a == num || b == 1 || b == num )
          cout << "*";
        else
          cout << " ";
          b++;
       }
      cout << endl;
      a++;
    }
  }
}
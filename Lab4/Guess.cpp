// Aysin ORuz
// Lab 4, Part C
// Editor: JNotePad
// Compiler: Xcode
//


#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <cstdlib>

#include <string>
using std::string;

#include <ctime>

void gues ( int, int );


int main()
{
  int num;
  int guess;
  string buf;
  char again='y' ;
    
  // Print out the name and lab
  cout<<" Aysin Oruz - 1331735 \n";
  cout<<" Lab 4, Part C \n";
  cout<<" Computer Science 165 \n\n";
    
  // random number producer
  srand((int)time(0));
    
  // random number between 1 and 1000
  num = 1 + rand() % 1000;
    
  cout << "Guess My Number Game\n\n";
  while( again == 'Y'|| again == 'y' )
  {   
   do
   {
    cout << "Enter a guess between 1 and 1000 : ";
    cin >> buf; guess = atoi (buf.c_str());
    cin.ignore (1000,10);
            
    // Read from function
    gues(guess, num);
           
   } while (guess != num);
        
  cout<<"\nWould you like to play again? Press Y to continue: \n";
  cin>> again; 
  }
}

void gues (int find, int num )
{
    
  if (find > num)
   cout << "Too high!\n\n";
  else if (find < num)
   cout << "Too low!\n\n";
  else
   cout << "\nExcellent!! You got it :) \n ";

}

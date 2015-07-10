//
//  main.cpp
//  Test2
//
//  Created by Aysin Oruz on 9/10/13.
//  Copyright (c) 2013 Aysin Oruz. All rights reserved.
//
//  Lab 4 Part A


#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <cstdlib>

#include <string>
using std::string;

//Function header
void square(int, char);

int main()
{
    
  int side;
  char input;
  string buf;
    
  // Print out the name and lab
  cout<<" Aysin Oruz - 1331735 \n";
  cout<<" Lab 4, Part A \n";
  cout<<" Computer Science 165 \n\n";
  while ( true )
  {

   //Ask user to enter a number 
   cout<<"Please enter a size to create a square. Numbers should be between 1-20. Then please enter a charachter: \n\n";
   cin>>buf; side = atoi (buf.c_str());
   cin>>input;
  
   //If the user enters out of range program breaks out
   if ( side >20 || side < 1 )
   break;

   //Reads the function and prints out the result
   square( side, input );
  }
    
}



//Main Function
void square( int side, char fillCharacter )
{
  for( int i = 1; i <= side; i++ )
   {
    for( int j = 1; j <= side; j++)
     {
      cout << fillCharacter;
     }
    cout << endl;
   }
}
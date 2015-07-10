// Aysin Oruz
// Lab 7 - 1331735
// Compiler & Editor : XCode
// Com. Sci. 165  - Prof. Burns

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include<string>

#include <cstring>


//Prototype for finding the size of array
int myStrLen ( const char[]);
void myStrCpy(char[], const char[]);
int myStrCmp(const char[], const char[]);



int main()
{
  // Print out the name and lab
  cout<<"Aysin Oruz - 1331735 \n";
  cout<<"Lab 7\n";
  cout<<"Computer Science 165 \n\n";
  
  char source[128];
  char copyTo[128]="Hello World!";
  cout<<"Enter a string please: "<<endl;    //Ask user to enter a string of char array
  cin.getline(source, 128);                 //Limit is 127 + Null Terminator
  
  //Print the string and compare it
  cout << "String: " << source << endl;
  cout << "Length: " << myStrLen(source) << endl;  //Call the length function to print out the size
  if (myStrCmp(source, copyTo) == 0)                //Compare function called. Print out if they match or not
    cout << "Entered string is equals to second string. GOOD ONE!"<<endl;
  else
    cout << "Entered string is NOT equals to second string." <<endl;
  
  //Change the string, print it and compare it
  myStrCpy( source , copyTo);
  cout<< "Copied String: "<< source << endl;
  cout<< "Copied String Length: "<< myStrLen(source) << endl;   //Print out the length of the copied array
  if (strcmp (source, copyTo) == '\0')                        //Call the compare function and print true or false
    cout << "The changed string is equals." << endl;
  else
    cout << "The changed string is NOT equals still." << endl;
  
  {  //Scope of new Code to use strlen, strcmp, strcpy
    char source[128];
    char copyTo[128]="Hello World!";
    cout<<"Enter a string please: "<<endl;
    cin.getline(source, 128);
    
    //Print the string and compare it
    cout << "String: " << source << endl;
    cout << "Length: " << strlen(source) << endl;          //print out the size
    if (strcmp(source, copyTo) == 0)                      //Compare - Print out if they match or not
      cout << "Entered string is equals to second string. GOOD ONE! "<<endl;
    else
      cout << "Entered string is NOT equals to second string. " <<endl;
    
    //Change the string, print it and compare it
    strcpy( source , copyTo);
    cout<< "Copied String: " << source << endl;
    cout<< "Copied String Length: " << strlen(source) << endl;   //Print out the length of the copied array
    if (strcmp (source, copyTo) == '\0')                        //Call the compare function and print true or false
      cout << "The changed string is equals" << endl;
    else
      cout << "The changed string is NOT equals" << endl;
  }
}

//String Length Function
int myStrLen ( const char c[])
{
  int cCounter = 0;     // Records # of chars
  
  //Count the chars
  for( int i = 0; ; i++)
  {
    if (c[i] == '\0')  //if the char array is reaches the Null terminator - Exit
      break;
    else
      cCounter ++;  //Other wise count the letters
  }
  return cCounter;   //return how many char is entered
}

//Copy Function
void myStrCpy ( char copyAgain[], const char copy[])
{
  int j = 0;    //counting variable
  while ( true )
  {
    copyAgain[j] = copy[j];   //Copy the second string onto first one
    if (copy[j] == '\0')
      break;   //If the second array reaches the null termionator exit
    j++;
  }
} //End of copy function

//Compare Function
int myStrCmp(const char compareA[], const char compareB[])
{
  int c = 0;
  
  while( compareA[c] == compareB[c] )  // While the first string and second one is true compare the letters
  {
    if( compareA[c] == '\0' || compareB[c] == '\0' )  // Break if one of the string reach the Null Terminator
      break;
    c++;
  }
  if( compareA[c] == '\0' && compareB[c] == '\0' )
    return 0;  //Return true if Both are reach the
  else
    return 1; //Return False if the strings are not equal
}
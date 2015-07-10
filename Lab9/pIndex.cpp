#include <iostream>
using std::cin;
using std::cout;
using std::endl;

//struct definition
struct tod
{
  int hour;    //the hour, 0-23
  int minute;  //the minute 0-59
  int second;  //the second, 0-59
  char descr [32];  //the description of the time of day
};

//utility function prototype
void coutTod (const tod&);
void coutTod (int, const tod[]);


int main()
{
  // Print out the name and lab
  cout<<"Aysin Oruz - 1331735 \n";
  cout<<"Lab 9 - Part C \n";
  cout<<"Computer Science 165 \n\n";
  
  //decleare and initilize the time to noon
  tod theTime [] = {{12, 0, 0, "Noon"},
    {13, 30, 0, "Lunch time"},
    {0, 0, 0, "Midnight"},
    {23, 0, 0, "Bed time"},
    {18, 35, 0, "Supper time"}};
  
  tod* tIndex[5];          //Pointer
  tIndex[0] = &theTime[2]; // midnight
  tIndex[1] = &theTime[0]; // noon
  tIndex[2] = &theTime[1]; // Lunch
  tIndex[3] = &theTime[4]; // supper Time
  tIndex[4] = &theTime[3]; // bed time
  
  tod* aIndex[5];          // Pointer
  aIndex[0] = &theTime[3]; //bed time
  aIndex[1] = &theTime[1]; //Lunch
  aIndex[2] = &theTime[2]; //Midnight
  aIndex[3] = &theTime[0]; //Noon
  aIndex[4] = &theTime[4]; //Supper
  
  //Original For loop to present the array
  for ( int i = 0; i < 5 ; i++ )
  {
    cout<< "Original Order " << theTime[i].descr << " is : " << theTime[i].hour << ':';
    coutTod (theTime[i]);
  }
  
  //To take a empty colon
  cout<< endl;
  
  //Chronological Order
  for ( int k = 0; k < 5 ; k++ )
  {
    cout<< "Chronological Order " << tIndex[k]->descr << " is : " << tIndex[k]->hour << ':';
    coutTod (*tIndex[k]);
  }
  cout<< endl;
  
  //Alphabetic Order
  for ( int j = 0; j < 5 ; j++ )
  {
    cout<< "Alphabetic Order " << aIndex[j]->descr << " is : " << aIndex[j]->hour << ':';
    coutTod (*aIndex[j]);
  }
  
}

void coutTod(const tod& t)
{
  if (t.minute < 10)
    cout << '0';
  cout << t.minute << ':';
  if (t.second < 10)
    cout << '0';
  cout << t.second << endl;
}
//overloads the existing function by the same name
void coutTod (int, const tod theTime[])
{
  for ( int i = 0; i < 5 ; i++ )    // go to loop 5 times and print out the description
  {
    cout<< theTime[i].descr << " is " << theTime[i].hour << ':';
    coutTod (theTime[i]);
  }
}



//Aysin Oruz
//Com Sci 165
//Compiler and EDitor : XCode


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
void coutTod (int, const tod[]);   // Number of items in the array
long diffTod (const tod&, const tod&);
int isAfter(const tod&, const tod&); // true if 1st is after 2nd
int isBefore(const tod&, const tod&); // true if 1st is before 2nd

int main()
{
  //decleare and initilize the time to noon
  tod theTime [] = {{12, 0, 0, "Noon"},
    {0, 0, 0, "Midnight"},
    {13, 30, 0, "Lunch time"},
    {18, 35, 0, "Supper time"},
    {23, 59, 59, "Bed time"}};
  
  // Print out the name and lab
  cout<<"Aysin Oruz - 1331735 \n";
  cout<<"Lab 8 \n";
  cout<<"Computer Science 165 \n\n";
  
  // Call the function coutTod to calculate and print out the how many h/m/s till the second entry
  coutTod(5,theTime);
  cout << "\nFrom " << theTime[2].descr << " to " << theTime[0].descr << " is " << diffTod(theTime[2], theTime[0]) << endl;
  cout << "From " << theTime[1].descr << " to " << theTime[4].descr << " is " << diffTod(theTime[1], theTime[4]) << endl;
  cout << "From " << theTime[3].descr << " to " << theTime[2].descr << " is " << diffTod(theTime[3], theTime[2]) << endl << endl;
  
  // if -else statements to check two times has been read and print which one is first or after
  if (isBefore (theTime [2], theTime[0]))
    cout << theTime[2].descr << " is before " << theTime[0].descr << endl;
  else
    cout << theTime[2].descr << " is after " << theTime[0].descr << endl;
  
  if (isBefore (theTime [4], theTime[1]))
    cout << theTime[4].descr << " is before " << theTime[1].descr << endl;
  else
    cout << theTime[4].descr << " is after " << theTime[1].descr << endl;
  
  if (isBefore (theTime [3], theTime[2]))
    cout << theTime[3].descr << " is before " << theTime[2].descr << endl;
  else
    cout << theTime[3].descr << " is after " << theTime[2].descr << endl;
  
}

//void function to add 00 to second and minute
void coutTod(const tod& t)
{
  if (t.minute < 10)    // if the minute is more than 10 add '0'
    cout << '0';
  cout << t.minute << ':';
  if (t.second < 10)
    cout << '0';       // if the second is more than 10 add '0'
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

long diffTod(const tod& t1, const tod& t2)    // function to calculate the difference between hours
{
  long timeDiff = ((long)(t1.hour - t2.hour) * 3600L)
  + ((long)(t1.minute - t2.minute) * 60L)
  + (long)(t1.second - t2.second);
  
  return timeDiff;    // return the difference to the main function
}

int isAfter(const tod& t1, const tod& t2) // function that prints out which period of day became after
{
  if (diffTod(t2, t1) < 0)
		return -1;
  
	else
		return 0;      //// true if 1st is after 2nd
  
}
int isBefore(const tod& t1, const tod& t2)   // function that prints out which period of day became before
{
  if (diffTod(t2, t1) > 0)
		return -1;
  
	else
		return 0;             // true if 1st is before 2nd
}

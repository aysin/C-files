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
void coutTod (int, const tod*);   // Number of items in the array
long diffTod (const tod&, const tod&);
int isAfter(const tod&, const tod&); // true if 1st is after 2nd
int isBefore(const tod&, const tod&); // true if 1st is before 2nd

int main()
{
  //decleare and initilize the time  to be unpredictable
  tod theTime [5];
  
  cout << "The time: " << (unsigned long) &theTime << endl;
  cout << "The time [0]: " << (unsigned long) &theTime[0] << endl;
  cout << "The time [1]: " << (unsigned long) &theTime[1] << endl;
  cout << "The time [2]: " << (unsigned long) &theTime[2] << endl;
  cout << "The time [3]: " << (unsigned long) &theTime[3] << endl;
  cout << "The time [4]: " << (unsigned long) &theTime[4] << endl;
  cout << "The time [0].hour: " << (unsigned long) &theTime[0].hour << " minute: "
  << (unsigned long) &theTime[0].minute << " second: " << (unsigned long) &theTime[0].second << "  " << endl;
  cout << "The time [1].hour: " << (unsigned long) &theTime[1].hour << " minute: "
  << (unsigned long) &theTime[1].minute << " second: " << (unsigned long) &theTime[1].second << "  " << endl;
  cout << "The time [2].hour: " << (unsigned long) &theTime[2].hour << " minute: "
  << (unsigned long) &theTime[2].minute << " second: " << (unsigned long) &theTime[2].second << "  " << endl;
  cout << "The time [3].hour: " << (unsigned long) &theTime[3].hour << " minute: "
  << (unsigned long) &theTime[3].minute << " second: " << (unsigned long) &theTime[3].second << "  " << endl;
  cout << "The time [4].hour: " << (unsigned long) &theTime[4].hour << " minute: "
  << (unsigned long) &theTime[4].minute << " second: " << (unsigned long) &theTime[4].second << "  " << endl;
  
  // Print Size of Tod struct and pointers
  cout << "Size of tod:  " << sizeof (tod) << endl;
  cout << "Size of tod pointers:  " << sizeof (tod*) << endl;
  
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

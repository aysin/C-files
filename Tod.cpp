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
};

int main()
{
  //decleare and initilize the time to noon
  tod theTime = {12};
  
  //print the time
  cout << "The time is " << theTime.hour << ':'
  << theTime.minute << ':'
  << theTime.second <<endl;
  
  // Add on hour and minute and print one more time with new line
  theTime.hour += 1;
  theTime.minute += 30;
  
  cout << "Now the time is " << theTime.hour << ':'
  << theTime.minute << ':'
  << theTime.second << endl;
}


//3.Step
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
};

int main()
{
  //decleare and initilize the time to noon
  tod noon = {12, 0, 0};
  tod midnight = {00, 0, 0};
  tod lunchTime = {13, 30, 0};
  tod supperTime = {6, 30, 0};
  tod bedTime = { 8, 0, 0};
    
  
  //print the time
  cout << "Noon is " << noon.hour << ':' << noon.minute << ':' << noon.second <<endl;
  cout << "Lunch time is " << lunchTime.hour << ':' << lunchTime.minute << ':' << lunchTime.second <<endl;
  cout << "Supper time is " << supperTime.hour << ':' << supperTime.minute << ':' << supperTime.second <<endl;
  cout << "Bed time is " << bedTime.hour << ':' << bedTime.minute << ':' << bedTime.second <<endl;
  cout << "Midnight is " << midnight.hour << ':' << midnight.minute << ':' << midnight.second <<endl;

}


//Step 4

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

int main()
{
  //decleare and initilize the time to noon
  tod theTime [] = {{12, 0, 0, "Noon"},
    {0, 0, 0, "Midnight"},
    {13, 30, 0, "Lunch time"},
    {18, 35, 0, "Supper time"},
    {23, 0, 0, "Bed time"}};
 
  for ( int i = 0; i < 5 ; i++ )
  {
    cout<< theTime[i].descr << " is " << theTime[i].hour << ':' << theTime[i].minute << ':'
    << theTime[i].second << endl;
  }

}

//Step 5
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

int main()
{
  //decleare and initilize the time to noon
  tod theTime [] = {{12, 0, 0, "Noon"},
    {0, 0, 0, "Midnight"},
    {13, 30, 0, "Lunch time"},
    {18, 35, 0, "Supper time"},
    {23, 0, 0, "Bed time"}};
  
  for ( int i = 0; i < 5 ; i++ )
  {
    cout<< theTime[i].descr << " is " << theTime[i].hour << ':';
    coutTod (theTime[i]);
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
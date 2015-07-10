// Aysin Oruz
// Lab 4 - Part B
// Compiler XCode
//
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

#include <cstdlib>

int passedSeconds(int, int, int);


int main()
{
  int hour;
  int minute;
  int second;
  string buf;
    
  // input the hour-min-sec and read from buf 
  while (true){
   cout<<" Aysin Oruz - Lab 4 / Part B \n";
   cout<<"(Press Q to exit:)\nPlease enter the hour >> \n";
   cin>>buf; hour = atoi ( buf.c_str());
    if( buf[0] == 'q' || buf[0] == 'Q')
     break;
   cout<<"(Press Q to exit:)\nPlease enter the minute >> \n";
   cin>>buf; minute = atoi ( buf.c_str());
    if( buf[0] == 'q' || buf[0] == 'Q')
     break;
   cout<<"(Press Q to exit:)\nPlease enter the second >> \n";
   cin>>buf; second = atoi ( buf.c_str());
    if( buf[0] == 'q' || buf[0] == 'Q')
     break;
        
  //Call the funstion passedSecond
  cout<<"Second Passed:::: "<< passedSeconds(hour, minute, second)<<endl;
  }
    
}

int passedSeconds(int hour1, int minute1, int second1)
{
  if(hour1 >= 12)
   hour1 -= 12;
  return hour1 * 60 * 60 + minute1 * 60 + second1;
}
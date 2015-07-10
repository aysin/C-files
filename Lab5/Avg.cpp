//Aysin ORuz
//Lab 5
//Xcode as editor n compiler


#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <cstdlib>

#include <string>
using std::string;

int avg (int, int);
int avg (double, double);

int main()
{
  int num1;
  int num2;
  string buf;
  
  cout<<"please enter 2 different number to find the average of it: \n";
  cin>>buf; num1 = atoi (buf.c_str());
  cin>>buf; num2 = atoi (buf.c_str());
  avg (num1, num2);

}

int avg (int a, int b)
{
  return (a + b) / 2;
} 


int avg (double a, double b)
{
  return (a + b) / 2.0;
} 
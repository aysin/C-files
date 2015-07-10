//Aysin Oruz
// Lab 5
// Xcode : compiler n editor



#include <iostream>
using std::cout;
using std::endl;

#include <cstdarg>

//Prototypes of the functions 
int avg (int, ...);
double davg ( int , ... );
int avgx(int&, int&, int, ...);
double avgx(double&, double&, int, ...);


int main()
{
  // Print out the name and lab
  cout<<" Aysin Oruz - 1331735 \n";
  cout<<" Lab 5, \n";
  cout<<" Computer Science 165 \n\n";
    
  //integer numbers - average
  cout << "The average of 7 test scores is: " << avg(7, 81, 92, 73, 84, 95, 99, 98 ) <<endl<<endl;
    
  //floating numbers- average
  cout<< "The average of 6 test scores is: " <<davg ( 6, 90.0, 98.0, 100.0, 55.0, 89.0, 99.9 ) <<endl<<endl;
    
  //intiger numbers
  int a, aMax, aMin;
  a = avgx(aMax, aMin, 10, 84, 99 , 85, 80, 98, 90, 70, 60, 50, 88);
  cout<< "Between 10 number\nThe Maximum number is: "<<aMax<<"\nMinimum number is: "<<aMin<<"\nAverage number is: "<<a<<endl<<endl;
    
  //floating point numbers
  double b, bMax, bMin;
  b = avgx(bMax, bMin, 8, 55.5, 99.8, 88.0, 98.5, 97.5, 77.7, 87.9, 68.9);
  cout<< "Between 8 number\nThe maximum number is: "<<bMax<<"\nMinimum number is: "<<bMin<<"\nAverage number is: "<<b<<endl<<endl;
  
}

int avg (int n, ...) //"n" is the number of the number list;"..." is the list
{
  va_list list; // assign the name list to the variable length list of integer
  va_start(list, n); // tell C++ that the list begins AFTER the argument 'n'
  
  int num;
  int total = 0;
  for ( int i=0; i< n; i++)
   {
    num = va_arg ( list, int);
    total = total + num;
   }
  va_end(list); //close the list - REQUIRE
    
  return total / n;
}


double davg ( int num, ... )
{
  va_list list;  //assign the name list to the variable length list of double
  va_start (list, num); //tell C++ the list begins After the argument "num"

  double total = 0;
  for ( int x = 0; x < num; x++ )        // Loop until all numbers are added
    total += va_arg ( list, double );    // adds the numbers to total

  va_end ( list );                      // Close the list
  return total / num;                 //compute and return the value
}


int avgx ( int& mx, int& mn, int n, ...)
{
  va_list list;
  va_start (list, n);
  
  int num;

  //create the total of "n" numer in the list
  int total = 0;
  for (int i=0; i< n; i++)
   {
    num = va_arg (list, int);
    if ((i == 0) || ( mn > num))  // update min value
      mn = num;
    if ((i == 0) || ( mx < num))  // update max value
      mx = num;
      total +=num;  //increment the total
    }
  va_end ( list );  // close the list

  return total / n; //compute and return the value
    
}


double avgx(double&max, double&min, int n, ...)
{
  va_list list;
  va_start (list, n);
 
  double num;

  // create the total of "n" numer in the list
  double total = 0;
  for (int i=0; i< n; i++)
   {
    num = va_arg (list, double);
    if ((i == 0) || ( min > num))  //update the min
      min = num;
    if ((i == 0) || ( max < num)) //update the max
      max = num;
      total +=num;   //increment the total
   }
  va_end ( list );   // close the list

  return total / n;  //compute and return the value
}



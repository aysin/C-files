//
//  Name: Aysin Oruz
//  Lab 1
//  Editor and Compiler : XCode
//
//

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ios;

#include <string>
using std::string;
using std::getline;

#include <cstdlib>

#include <iomanip>
using std::setprecision;


int main()
{
  string buf, name, city;
  int age, age2;
  float ftemp, ctemp;
    
  // Ask user to enter age, name, temprerature, and city  
  cout << "What is your age? \n";
  cin >> buf; age = atoi(buf.c_str());
  cin.ignore(1000, 10);
  cout << "What is your name? \n";
  getline( cin, name );
  cout<< "What is the outside temprature in F: \n";
  cin>>buf; ftemp = atof (buf.c_str());
  cin.ignore(1000, 10);
  cout<<"Enter the city you are in: \n";
  getline ( cin, city );
    
  //converts F to C
  ctemp=(ftemp-32)*5.0/9.0;
    
  //calculate age for next year
  age2 = age + 1;

  cout<<name<<" is "<<age<<" now, and will be " <<age2<<" a year from now.\n"<<"Its "<<ftemp<<" in "<<city<<endl;
  cout.setf(ios::fixed|ios::showpoint);
  cout<<"That's "<<setprecision(1)<<ctemp<<" degrees C\n";
    

}
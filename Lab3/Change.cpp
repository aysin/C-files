// Aysin ORuz
// Lab 3
// Editor: JNotePad
// Compiler: Xcode
//


#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios;

#include <iomanip>
using std::setprecision;

#include <cstdlib>

#include <string>
using std::string;


int main()
{
  int dollar50 = 0;
  int dollar20;
  int dollar10;
  int dollar5;
  int dollar;
  int change1;
  int half;
  int quarter;
  int dime;
  int cent5;
  int penny;
  double purchase = 0.0;
  double tendered = 0.0;
  double change = 0.0;
  string buf;
  char sign='$';
    
  // Print out the name and lab
  cout<<" Aysin Oruz - 1331735 \n";
  cout<<" Lab 3, \n";
  cout<<" Computer Science 165 \n\n";
    
  //ask use to enter money owened and money paid
  cout<<" Please enter the amount of the purchase, and the amount tendered \n";
  cin>>buf; purchase = atof (buf.c_str()); 
  cin>>buf; tendered = atof (buf.c_str());
    
  //Print out either wrong amount tendered or calculation
  if (purchase > tendered)
   {
    cout<<"The amount that was given is not enough, please pay the full amount.";
    cout<<endl;
    cout<<endl;
   }
  else
  {
   cout.setf(ios::fixed | ios::showpoint);
   cout<<setprecision(2)<<endl;
   change = tendered - purchase;
   change1 = (int) (change * 100 + 0.5);
   dollar50 = change1 % 5000 / 5000;
   dollar20 = change1 % 2000 / 2000;
   dollar10 = change1 % 1000 / 1000;
   dollar5 = change1 % 500 / 500;
   dollar = change1 % 100 / 100;
   half = change1 % 50 / 50;
   quarter = change1 % 25 / 25;
   dime = change1 % 10 / 10;
   cent5 = change1 % 100 % 25% 10 / 5;
   penny = change1 % 100 % 25 % 10 % 5 / 1;
   
   //Print the Due
   cout<<"Change Due:\n"<<change<<endl;
        
   //Calculation part
   while(true)
    {
     if(change < 50 ) break;
     dollar50++;
     change-=50;
    }
     if (dollar50 != 0 && dollar50 <= 1)
      cout<<dollar50<<"  "<<sign<<"50 Dollar Bill\n";
     if (dollar50 != 0 && dollar50 >= 2)
      cout<<dollar50<<"  "<<sign<<"50 Dollar Bills\n";
        
   while(true)
    {
     if(change < 19.99 ) break;
     dollar20++;
     change-=20;
    }
    if (dollar20 != 0 && dollar20 <= 1)
      cout<<dollar20<<"  "<<sign<<"20 Dollar Bill\n";
    if (dollar20 != 0 && dollar20 >= 2)
       cout<<dollar20<<"  "<<sign<<"50 Dollar Bills\n";
   while(true)
    {
     if(change < 9.99 ) break;
     dollar10++;
     change-=10;
    }
     if (dollar10 != 0 && dollar10 <= 1)
      cout<<dollar10<<"  "<<sign<<"10 Dollar Bill\n";
     if (dollar10 != 0 && dollar10 >= 2)
      cout<<dollar10<<"  "<<sign<<"10 Dollar Bills\n";
   while(true)
    {
     if(change < 5 ) break;
     dollar5++;
     change-=5;
    }
    if (dollar5 != 0 && dollar5<= 1)
     cout<<dollar5<<"  "<<sign<<"5 Dollar Bill\n";
    if (dollar5 != 0 && dollar5 >= 2)
     cout<<dollar5<<"  "<<sign<<"5 Dollar Bills\n";
   while(true)
    {
     if(change < 1 ) break;
     dollar++;
     change-=1;
    }
    if (dollar != 0 && dollar <= 1 )
     cout<<dollar<<"  "<<sign<<"1 Dollar Bill\n";
    if (dollar != 0 && dollar >= 2)
     cout<<dollar<<"  "<<sign<<"1 Dollar Bills\n";
    while(true)
     {
      if(change < .50 ) break;
      half++;
      change-=.50;
     }
     if (half != 0 && half <= 1)
      cout<<half<<"  "<<sign<<"50 cent coin\n";
     if (half != 0 && half >= 2)
      cout<<half<<"  "<<sign<<"50 cent coins\n";
    while(true)
     {
      if(change < .25 ) break;
      quarter++;
      change-=.25;
     }
     if (quarter != 0 && quarter <= 1)
      cout<<quarter<<"  "<<sign<<"25 cent coin\n";
     if (quarter!= 0 && quarter >= 2)
      cout<<quarter<<"  "<<sign<<"25 cent coins\n";
    while(true)
     {
      if(change < .10 ) break;
      dime++;
      change-=.10;
     }
     if (dime != 0 && dime <= 1)
      cout<<dime<<"  "<<sign<<"10 cent coin\n";
     if (dime != 0 && dime >= 2)
      cout<<dime<<"  "<<sign<<"10 cent coins\n";
    while(true)
     {
      if(change < .5 ) break;
      cent5++;
      change-=.5;
     }
     if (cent5 != 0 && cent5 <= 1)
      cout<<cent5<<"  "<<sign<<"5 cent coin\n";
     if (cent5!= 0 && cent5 >= 2)
      cout<<cent5<<"  "<<sign<<"5 cent coins\n";
    while(true)
     {
      if(change < .1 ) break;
      penny++;
      change-=.1;
     }
     if (penny != 0 && penny <= 1)
      cout<<penny<<"  "<<sign<<"1 cent coin\n";
     if (penny!= 0 && penny >= 2)
      cout<<penny<<"  "<<sign<<"1 cent coins\n";
        
        
   }
}
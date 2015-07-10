
// Aysin ORuz
// Lab 2
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
using std::setw;


int main()
{
  float population = 7107000000.0; // Census.gov
  double growthrate = 0.012;    // Census.gov
  float increase = 0;
    
  // Print out the name and lab
  cout << " Aysin Oruz - 1331735 \n";
  cout << " Lab 2, Part C \n";
  cout << " Computer Science 165 \n\n\n";
    ,mn m,/.,,/,
  cout << "Year      Population       Increase" << endl;
    
  // countting 75 years and outputting 
  for( int y = 2013; y <= 2088; y++ )
  {
   cout.setf(ios::fixed|ios::showpoint);
   cout.setf(ios::right, ios::adjustifield);
   cout << y << setw(12) << population << setw(24) << increase << endl;
   increase = population * growthrate;
   population += increase;
  }
}
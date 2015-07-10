//Aysin Oruz
//Com Sci 165
//Xcode

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios;

#include <string>
using std::string;


#include <iomanip>
using std::setw;

//struct definition
struct course
{
  char courseDes [11];    //Course designation
  char term [7];
  double unit ;
  char grade  ;
  course* next;
};

void courseList( course* ); //print course list function

int main ()
{
  // Print out the name and lab
  cout<<"Aysin Oruz - 1331735 \n";
  cout<<"Lab 12 \n";
  cout<<"Computer Science 165 \n\n";
 
  course* head = 0;      // declare an empty simple linked list
  string buf;
  
  // start a loop
  while (true)
  {
    // print the list
    courseList ( head );
    char n ; // Ask to contunie
    
    // prompt user to ADD a node or QUIT
    cout << "\n\nTo add new node press 'N'. To Quit press 'Q' please: \n";
    cin >> n;
    cin.ignore(1000,10);
    
    
    if ( n == 'Q' || n == 'q' )
    {
      cout << endl;
      courseList ( head );
      break;
    }
    
    // STEP 1: create new node
    course* t = new course;
    
    // STEP 2: fill node with data from user (cin)
    cout << "\nEnter another course you are taking or took before. Example ( COMSC-200 ): \n";
    cin >> t -> courseDes;
    cin.ignore(1000,10);
    
    cout << endl << "Enter semester's term (FA2011): \n";
    cin >> t->term;
    cin.ignore(1000,10);
    
    cout << endl << "Enter course's units: \n";
    cin >> buf; t->unit = atoi(buf.c_str());
    
    cout << endl << "Enter course's grade (A,B, C, D, F or X for if u havent taken it yet): \n";
    cin >>t->grade;
    cin.ignore(1000,10);
    
    // STEP 3+4: insert at head of list (stack method)
    t -> next = head;
    head = t;
    
  } // end of loop
  
  
  // deallocate list memory
  while (head) // zero if already empty list
  {
    course* next = head->next; // remember before killing off the head
    delete head; // deallocate the head
    head = next; // a new head
  }
}

//print course list function
void courseList ( course* headOne)
{
  cout.setf(ios::right, ios::adjustfield);
  cout << setw(4) << " COURSE " << setw(13) << "  TERM " << setw (11) << " UNITS " << setw (10) << " GRADE " << endl;
  cout << setw(4) << "___________" << setw(10) << "______" << setw (10) << "_____" << setw (10) << "_____" << endl;
  
  for ( const course* p = headOne; p; p = p -> next)
  {
    cout.setf(ios::left, ios::adjustfield);
    cout << setw(15) << p -> courseDes ;
    cout << setw(13) << p -> term ;
    cout << setw (10) <<  p -> unit;
    cout <<  p -> grade  << endl;
  }
}


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

#include <cstring>
#include <cstdlib>

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
int myStricmp(const char* , const char* );
int myStrnicmp(const char* , const char* , int );
int courseCmp ( const course* , const course* );


int main ()
{
  // Print out the name and lab
  cout<<"Aysin Oruz - 1331735 \n";
  cout<<"Lab 13 \n";
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
    
    // find insertion point in new list
    course* p, *prev;
    for (p = head, prev = 0; p; prev = p, p = p->next)
      if (courseCmp(t, p) < 0) // if "t" comes before "p"...
        break; // "t" goes between "prev" and "p"
    
    // insert "t" between "prev" and "p"
    t->next = p; // "t" inserted before "p"
    if (prev) // "t" inserted after "prev"
      prev->next = t;
    else // "t" added to front of list
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

int courseCmp ( const course* a, const course* b)
{
  //validate the lenfth of the strings
  if ((strlen (a->term) !=6) || (strlen (b->term) !=6))
    return myStricmp (a->courseDes, b->courseDes);
  
  //handle ties here
  if ( myStricmp(a->term, b->term ) == 0)
    return myStricmp (a->courseDes, b->courseDes);
  
  //compare the years
  int yearA = atoi ( a-> term + 2);
  int yearB = atoi ( b-> term + 2);
  
  if ( yearA < yearB)
    return -1; // terA comes first
  
  if (yearA > yearB)
    return 1; //termB comes first
  
  //compare semsters in case of same year
  if ( myStrnicmp(a->term, "SP", 2) == 0)
    return -1;
  
  if ( myStrnicmp(a->term, "SU", 2 ) == 0)
    return myStrnicmp(b->term, "SP", 2) ? -1 : 1;
  return 1;
  
}


int myStricmp(const char* dst, const char* src)
{
  int f, l;
  do
  {
    if (((f = (unsigned char)(*(dst++))) >= 'A') && (f <= 'Z')) f -= 'A' - 'a';
    if (((l = (unsigned char)(*(src++))) >= 'A') && (l <= 'Z')) l -= 'A' - 'a';
  } while (f && (f == l));
  return(f - l);
}


int myStrnicmp(const char* dst, const char* src, int count)
{
  int f, l;
  do
  {
    if (((f = (unsigned char)(*(dst++))) >= 'A') && (f <= 'Z')) f -= 'A' - 'a';
    if (((l = (unsigned char)(*(src++))) >= 'A') && (l <= 'Z')) l -= 'A' - 'a';
  } while (--count && f && (f == l));
  return (f - l);
}

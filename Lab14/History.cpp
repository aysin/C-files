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

#include <fstream>
using std::fstream;
using std::ofstream;
using std::ifstream;

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
course* restoreList(course* );
void saveList(course* );
course* sortByUnit(course* );
course* sortByGrade(course* );
course* sortByTerm(course* );
course* sortByDesc(course* );


int main ()
{
  // Print out the name and lab
  cout<<"Aysin Oruz - 1331735 \n";
  cout<<"Lab 13 \n";
  cout<<"Computer Science 165 \n\n";
  
  course* head = 0;      // declare an empty simple linked list
  string buf;
  char y; // Calling the history record
  
  cout << "\n\nWould you like to recall the history folder that had been saved? Press Y to confirm.\n";
  cin >> y;
  
  if ( y == 'Y' || y == 'y')
  {
    head = restoreList(head);
    cout << endl;
  }
  
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
      saveList(head);
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
    for (p = head, prev = 0; p; prev = p, p = p->next);
     
    
    // insert "t" between "prev" and "p"
    t->next = p; // "t" inserted before "p"
    if (prev) // "t" inserted after "prev"
      prev->next = t;
    else // "t" added to front of list
      head = t;
    
  } // end of loop
  saveList(head);
  
  cout << "\nPress ENTER to view class history sorted by Unit: " << endl;
	cin.get();
  
  cout << endl;
	cout << "          Class History Sorted by Unit \n";
	cout << "          ---------------------------- \n";
	head = sortByUnit(head);
	courseList(head);
	cout << endl;
  
  cout << "\nPress ENTER to view class history sorted by grade: " << endl;
	cin.get();
  
	cout << endl;
	cout << "          Class History Sorted by Grade \n";
	cout << "          ----------------------------- \n";
	head = sortByGrade(head);
	courseList(head);
	cout << endl;
  
  cout << "\nPress ENTER to view class history sorted by term: " << endl;
	cin.get();
  
	cout << endl;
	cout << "          Class History Sorted by Term \n";
	cout << "          ---------------------------- \n";
	head = sortByTerm(head);
	courseList(head);
	cout << endl;
  
	cout << "\nPress ENTER to view class history sorted by description: " << endl;
	cin.get();
  
	cout << endl;
	cout << "          Class History Sorted by Description \n";
	cout << "          -----------------------------------`\n";
 	head = sortByDesc(head);
	courseList(head);
	cout << endl;
  
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

//Adding  t to its proper spot. Tail
course* pushToTail(course* head, course* x)
{
  course* t = head;
  if (t == 0)
  {
    x->next = 0;
    return x;
    
  }
  else
  {
    course* a = t;
		
    while(a->next)
    {
      a = a->next;
    }
    a->next = x;
    return t;
  }
}

//restoring the entered data
course* restoreList(course* head)
{
  ifstream fin;
  fin.open("course.dat", ios::binary|ios::in);
  
  if (!fin)
		return head;
  
  // read the number of objects fromthe disk file
  int nRecs;
  fin.read((char*)&nRecs, sizeof(int));
  course* newHead = head;
  
  for (int i = 0; i < nRecs; i++)
  {
    course* x = new course;
    fin.read((char*)x, sizeof(course));
    x->next = 0;
    newHead = pushToTail(newHead, x);
  }
  fin.close();
  return newHead;
}

//saving the list
void saveList(course* head)
{
  int counter = 0;
  ofstream fout;
  fout.open("course.dat", ios::binary|ios::out|ios::trunc);
  if(!fout) cout << "Could not find and save file..." << endl;
  
  course* x = head;
  
  for(;x; ++counter, x = x->next);
  x = head;
  fout.write((char*)&counter, sizeof(int));
  
  for (; x; x = x->next)
  {
    fout.write((char*)x, sizeof(course));
  }
  fout.close();
}

course* sortByUnit(course* head)
{
  course* newHead = 0; // a new empty list
  course* oldHead = head; // the original list
  while (oldHead)
  {
    course* t = oldHead; // get node from old list
    oldHead = oldHead ->next; // remove node from old list
    
    // find insertion point in new list
    
    // insert "t" between "prev" and "p"
    course* p, *prev;
    for (p = newHead, prev = 0; p; prev = p, p = p->next)
    {
      if ( t -> unit < p -> unit)
        break;
    }
    
    t -> next = p;
    if (prev)
      prev -> next = t;
    else
      newHead = t;
  }
  return newHead;
}

course* sortByGrade(course* head)
{
  course* newHead = 0;
  course* oldHead = head;
  
  while (oldHead)
  {
    course* t = oldHead;
    oldHead = oldHead->next;
    course* x, *prev;
    
    for (x = newHead, prev = 0; x; prev = x, x = x->next)
    {
      if (tolower(t->grade) < tolower(x->grade))
				break;
    }
    
    t->next = x;
    
    if (prev)
      prev->next = t;
    
    else
      newHead = t;
  }
  return newHead;
}


course* sortByDesc(course* head)
{
  course* newHead = 0;
  course* oldHead = head;
  
  while (oldHead)
  {
    course* t = oldHead;
    oldHead = oldHead->next;
    course* x, *prev;
    
    for (x = newHead, prev = 0; x; prev = x, x = x->next)
    {
      if (strcmp(t->courseDes, x->courseDes) < 0)
				break;
    }
    
    t->next = x;
    if (prev)
      prev->next = t;
    else
      newHead = t;
  }
  
  return newHead;
}

course* sortByTerm(course* head)
{
  course* newHead = 0;
  course* oldHead = head;
  
  while (oldHead)
  {
    course* t = oldHead;
    oldHead = oldHead->next;
    course* x, *prev;
    
    for (x = newHead, prev = 0; x; prev = x, x = x->next)
    {
      if (courseCmp(t, x) < 0)
				break;
    }
    
    t->next = x;
    if (prev)
      prev->next = t;
    else
      newHead = t;
  }
  return newHead;
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

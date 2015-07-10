//Aysin Oruz
// Com Sci 165
// Xcode

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
  tod* next; // link
};

//utility function prototype
void coutTod (const tod&);
void coutTod (int, const tod[]);


int main()
{
  // Print out the name and lab
  cout<<"Aysin Oruz - 1331735 \n";
  cout<<"Lab 11 \n";
  cout<<"Computer Science 165 \n\n";
  
  //decleare and initilize the time to noon
  tod noon = {12, 0, 0, "Noon"};
  tod lunch =  {13, 30, 0, "Lunch time"};
  tod midnight =  {0, 0, 0, "Midnight"};
  tod bedTime = {23, 0, 0, "Bed time"};
  tod supperTime =   {18, 35, 0, "Supper time"};
  
  tod* head = 0;
  head = &midnight;
  midnight.next = &noon;
  noon.next = &lunch;
  lunch.next = &supperTime;
  supperTime.next = &bedTime;
  bedTime.next = 0;
  
  tod* p;
  for (p=head; p; p=p->next)
  {
    cout << "Chronological Order " << p->descr<< " is : " << p->hour << ':' ;
    coutTod(*p);
  }
  cout << endl ;
  
  tod breakfast ={07, 20,0, "Breakfast"};
  breakfast.next = &noon;
  midnight.next = &breakfast;
  cout << "Breakfast has been added to list." << endl;
  tod* a;
  for (a=head; a; a=a->next)
  {
    cout << "Chronological Order " << a->descr<< " is : " << a->hour << ':' ;
    coutTod(*a);
  }
  cout << endl;
  
  tod classStarts = {9, 30, 0, "CS 165 Starts"};
  classStarts.next = &noon;
  breakfast.next = &classStarts;
  cout << "Class Starts has been added to list." << endl;
  tod* b;
  for (b=head; b; b=b->next)
  {
    cout << "Chronological Order " << b->descr<< " is : " << b->hour << ':' ;
    coutTod(*b);
  }
  cout << endl;
  
  tod classEnds = {12, 20, 0, "CS 165 Ends"};
  classEnds.next = &lunch;
  noon.next = &classEnds;
  cout << "Class Ending time has been added to list." << endl;
  tod* c;
  for (c=head; c; c=c->next)
  {
    cout << "Chronological Order " << c->descr<< " is : " << c->hour << ':' ;
    coutTod(*c);
  }
  cout << endl;
  
  // Delete mealtimes
  midnight.next = &classStarts; // Delete breakfast
  classStarts.next = &noon;
  noon.next = &classEnds; // delete lunch
  classEnds.next = &bedTime; // delete supper
  bedTime.next = 0;
  cout << "Mealtimes had been removed!" << endl;
  tod* d;
  for (d=head; d; d=d->next)
  {
    cout << "Chronological Order " << d->descr<< " is : " << d->hour << ':' ;
    coutTod(*d);
  }
  cout << endl;
  
  // Re-insert mealtimes
  midnight.next = &breakfast;
  breakfast.next = &classStarts;
  classStarts.next = &noon;
  noon.next = &classEnds;
  classEnds.next = &lunch;
  lunch.next = &supperTime;
  supperTime.next = &bedTime;
  cout << "Mealtimes had been re-inserted!" << endl;
  tod* e;
  for (e=head; e; e=e->next)
  {
    cout << "Chronological Order " << e->descr<< " is : " << e->hour << ':' ;
    coutTod(*e);
  }
  cout << endl;
  
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
//overloads the existing function by the same name
void coutTod (int, const tod theTime[])
{
  for ( int i = 0; i < 5 ; i++ )    // go to loop 5 times and print out the description
  {
    cout<< theTime[i].descr << " is " << theTime[i].hour << ':';
    coutTod (theTime[i]);
  }
}



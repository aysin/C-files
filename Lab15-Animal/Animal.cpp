// program and programmer identification
// Aysin Oruz
// XCode
// Lab 15
        
// includes
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ios;

#include <cstring>


// class definition
class animal
{
  public:
  char text[128];   //a yes and no question or an animal name
  animal* yes;      // pointer to next node if question is answered yes
  animal* no;      // pointer to next node if question is answered no
}; // if yes and no are 0, then text is an animal name

// function prototype
void deallocateTree(animal*); // write this!

  
int main()
{
  cout << "LAB 15 - Animal.cpp \nProgrammer: Aysin Oruz\nXCode\n\n";
  // initialize a "top" pointer named "animal* top"
  animal* top;
  
  // set "top" to a newly created node; set its text to "elephant", pointers to 0
  top = new animal;
  strcpy (top->text, "Elephant");
  
  //pointers to 0
  top->yes = 0;
  top->no = 0;

  
  // start a "while" loop that runs each cycle of the program
  while (true)
  {
    // invite the user to think of an animal which it will try to guess
    char play;
    cout << "Hey my friend!\nLets play a game. You think of an animal and I will guess what it is. Are you in? [Y/N]: \n";
    cin >> play ;
    cin.ignore (1000,10);
    
    // await the user's response, and break out of the loop if he declines
    if (play == 'N' || play == 'n')
      break;
    
    if (play == 'y' || play == 'Y')
    {
      // declare a pointer "p" to traverse the tree, and initialize it to "top"
      animal* p;
      p = top;
      
      // start a loop to traverse the binary tree
      while (true)
      {
        // if p->yes is 0...
        if ( p->yes == 0 )
        {
          //...print p->text as the guessed animal
          cout << p->text;
          
          // ask user if this is correct
          cout << "\nDid I guess it right? [Y/N]: \n";
          cin >> play ;
          cin.ignore (1000,10);
          
          // if correct, brag and break from loop
          if (play == 'y' || play == 'Y')
          {
            cout << "Damn! Im very smart :)\n\n";
            break;
          }
          
          // ask user what animal he was thinking of...
          if (play == 'N' || play == 'n')
          {
            char yesNo; //yes or no question
            
            cout << "No? Well, what is it then?: \n"; //ask user what animal he was thinking of  ANSWER
            char a[128]; //...store in "char a[128]
            cin.getline ( a,128);
            
            cout << "What question should I ask to tell the difference ?: \n"; //ask what yes/no question differentiates "p->text" from "a"
            char q[128]; //question in char q[128]  (question differentiates)
            cin.getline(q, 128);
            
            cout << "Which answer is correct for " <<  a <<" [Y/N]: \n"; //ask which response is correct for "a" -- yes or no
            cin >> yesNo;
            cin.ignore(1000, 10);
            
            // create two new nodes, names "y" and "n"
            animal* y = new animal;
            animal* n = new animal;
            
            // if the correct response for "a" is yes...
            if (yesNo == 'Y' || yesNo == 'y')
            {
              // copy "a" into y->text
              strcpy(y -> text, a);
              
              // copy p->text into n->text
              strcpy(n -> text, p -> text);
            }
            
            // else if the correct response is no...
            if (yesNo == 'N' || yesNo == 'n')
            {
              // copy "a" into n->text
              strcpy(n -> text, a);
              
              // copy p->text into y->text
              strcpy(y -> text, p -> text);
            }
            // copy "q" into p->text
            strcpy(p -> text, q);
            
            // set y->yes, n->yes, y->no, and n->no to 0
            y -> yes = 0;
            n -> yes = 0;
            y -> no = 0;
            n -> no = 0;
            
            // set p->yes to y and p->no to n
            p -> yes = y;
            p -> no = n;
            
            // break from loop
            break;
            
          }
        }
        
        // else if p->yes is not 0
        else if ( p -> yes != 0 )
        {
          char yesNo;
          cout << p->text << "? [Y/N]: "; //print p->text as a question ask for a yes/no reply
          cin >> yesNo; //store in char yesNo
          cin.ignore(1000, 10);
          
          //if yes set p to p->yes
          if(yesNo == 'Y' || yesNo == 'y')
          {
            p = p->yes;
          }
          
          //else if set p to p->no
          else if (yesNo =='N'|| yesNo=='n')
          {
            p = p->no;
          }
        } // end of else if
      } // end of while
      
      // reclaim memory
      deallocateTree(top);
      
    } // end of if
  } // end of outer while
} //end of main


// function definition
void deallocateTree(animal* a)
{
  if (a != 0) return;
  deallocateTree(a->yes);
  deallocateTree(a->no);
  delete a;
  
}




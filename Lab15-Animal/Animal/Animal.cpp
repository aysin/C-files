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

#include <fstream>
using std::fstream;
using std::ofstream;
using std::ifstream;


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
// utility function prototypes
void saveTree(animal*, fstream&);
void restoreTree(animal*, fstream&);
void editQ(animal* p);
void deleteNode(animal* p);

int main()
{
  cout << "Lab 16:  Animal.cpp\n";
  cout << "Programmer: Aysin Oruz\n\n";
  
  // initialize a "top" pointer named "animal* top"
  animal* top;
  
  // set "top" to a newly created node; set its text to "elephant", pointers to 0
  top = new animal;
  strcpy (top->text, "Elephant");
  
  // restore tree from a disk file
  fstream fin;
  fin.open("Animal.dat", ios::in|ios::binary);
  if(!fin)
  {
    strcpy (top->text, "Elephant");
    
    //pointers to 0
    top->yes = 0;
    top->no = 0;
  }
  else
  {
    restoreTree(top, fin); //restore tree
  }
  fin.close();
  
  // start a "while" loop that runs each cycle of the program
  while (true)
  {
    // invite the user to think of an animal which it will try to guess
    char play;
    cout << "\nHey my friend!\nLets play a game. You think of an animal and I will guess what it is. Are you in? [Y/N]: \n";
    cin >> play ;
    cin.ignore (1000,10);
    cout << endl;
    
    // await the user's response, and break out of the loop if he declines
    if (play == 'N' || play == 'n')
    {
      cout << ":( !!!!" << endl;
      
      // save tree
      fstream fout;
      fout.open("Animal.dat", ios::out|ios::binary);
      saveTree(top, fout);
      fout.close();
      break;
    }
    //If user enters Delete or Edit right at the begining of the game
    if(play =='d' || play == 'D' || play =='e' || play == 'E')
    {
      cout << "\nThis is a new game so you should choose [Y/N]: \n!" << endl;
    }
    
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
          cout << endl << p->text;
          
          // ask user if this is correct
          cout << "\nDid I guess it right? [Y/N]: \n";
          cin >> play ;
          cin.ignore (1000,10);
          
          // if correct, brag and break from loop
          if (play == 'y' || play == 'Y')
          {
            cout << "\nDamn! Im very smart :)\n\n";
            break;
          }
          //Edit a node
          if(play == 'e' || play == 'E')
          {
            cout << "\nEnabling edit mode for the animal: ";
            editQ(p);
            continue;
          }
          
          //Delete a node
          if(play == 'd' || play == 'D')
          {
            continue;
          }
          
          // ask user what animal he was thinking of...
          if (play == 'N' || play == 'n')
          {
            char yesNo; //yes or no question
            
            cout << "\nNo? Well, what is it then?: \n"; //ask user what animal he was thinking of  ANSWER
            char a[128]; //...store in "char a[128]
            cin.getline ( a,128);
            
            cout << "\nWhat question should I ask to tell the difference between ?: \n"; //ask what yes/no question differentiates "p->text" from "a"
            
            char q[128]; //question in char q[128]  (question differentiates)
            cin.getline(q, 128);
            
            cout << "\nWhich answer is correct for " <<  a <<" [Y/N]: \n"; //ask which response is correct for "a" -- yes or no
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
          if (yesNo =='N'|| yesNo=='n')
          {
            p = p->no;
          }
          if(yesNo=='e' || yesNo=='E')
          {
            
            cout << "\nEnabling edit mode for the question: ";
            editQ(p);
          }
          if(yesNo=='d' || yesNo=='D')
          {
            deleteNode(p);
            continue;
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

// function definitions -- save and restore
void saveTree(animal* a, fstream& fout) // saves tree to disk file
{
  if (a)
  {
    fout.write((char*)a, sizeof(animal));
    saveTree(a->yes, fout);
    saveTree(a->no, fout);
  }
}

void restoreTree(animal* a, fstream& in) // loads tree from disk file
{
  in.read((char*)a, sizeof(animal));
  if(a->yes)
  {
    restoreTree(a->yes = new animal, in);
    restoreTree(a->no = new animal, in);
  }
}

//edit the question
void editQ(animal* p)
{
  cout << "\nWhat should this be?\n";// ask user what new question should be
  char a[128];//...store in "char a[128]"
  cin.getline(a,128);
  strcpy(p->text,a); // copy "a" into p->text
}

//delete node
void deleteNode(animal* p)
{
  char answer ;
  cout << "\nDeleting question. What go you want to replace this question with,Elephant [y]"
  << " or another Animal [n]? " << endl;
  while (true)
  {
    cin >> answer ;
    cin.ignore(1000,10);
    
    if(answer!='n'&& answer!='y'&& answer!='d'&& answer!='e') cout << "\nYes or No [y/n]?\n";
    else break;
  }
  if(answer=='y')
  {
    char ele[128] = "\nElephant";
    strcpy(p->text,ele);
  }
  else if(answer=='n')
  {
    char a[128];
    cout << "\nNew animal name: ";
    cin.getline(a, 128);
    strcpy(p->text,a);
  }
  p->yes=0;
  p->no=0;
}


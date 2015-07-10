//Aysin Oruz
// Lab 10
// Compiler and Editor = Xcode

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::ios;

#include <string>
using std::string;

#include <fstream>
using std::ofstream;
using std::ifstream;

#include <ctime>
#include <cstdlib>
// Function prototypes
void printGrid(const char[]);//  displays the grid
void goX(char[]); // Prompts user for turn
void printInstructions(); // Display list of valid entries

void goO1(char[]);
void goO2(char[]);
void goO3(char[]);
char check4Xwinner(char[]);
char check4Owinner(char[]);
char check4Tie(char[]);
bool f_ValidEntry(char);
bool f_IsOccupied(char[]);
void s_ReadScores(int[]);
void scores(int[]);

int main()
{
  // Print out the name and lab
  cout<<" Aysin Oruz - 1331735 \n";
  cout<<" Lab 10 \n";
  cout<<" Computer Science 165 \n\n";
  
  srand((unsigned)time(NULL)); rand(); //Set srand for number generator
  
  //  Array of chars initialized to one space each element
  char grid[] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
  char replay = 'Y'; // Play again?
  int player ; // Select player
  int intScores[3]; // Create an array to hold file's contents
  string buf;
  
  // Call function to open scores file and read lines of input
  s_ReadScores(intScores);
  
  int xwins = intScores[0];
  int owins = intScores[1];
  int ties =  intScores[2];
  // Displays scores
  cout << "Scores" << endl;
  cout << "======" << endl;
  cout << "X wins: " << xwins << endl;
  cout << "O wins: " << owins << endl;
  cout << "  Ties: " << ties << endl <<endl;
  
  
  // Prompt user to select an opponent
  cout << "Please choose a number below to whom you want to play against to."<< endl;
  cout << "[1] = A person." << endl;
  cout << "[2] = Dumb computer." << endl;
  cout << "[3] = Smart computer." << endl;
  while(true){
    cout << "Your selection: ";
    cin >> buf; player = atoi (buf.c_str());
    cin.ignore(1000,10);
    if( player == 1 || player == 2 || player == 3)
    {
      break;
    }
    else
      cout << "Try a valid number!\n";
  }
  
  printGrid(grid); // Print grid
  
  // Displays scores
  cout << "Scores" << endl;
  cout << "======" << endl;
  cout << "X wins: " << xwins << endl;
  cout << "O wins: " << owins << endl;
  cout << "  Ties: " << ties << endl <<endl;
  
  while ((replay == 'Y') || (replay == 'y'))
  {
    char grid[] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};  // Called here to clear the grid on next game!
    while(1)
    {
      cout << endl;
      printGrid(grid); // Print grid
      goX(grid); // X moves
      
      // Checks if X is winner
      if (check4Xwinner(grid) == 'Y')
      {
        printGrid(grid);
        cout << "X wins!" << endl;
        xwins++;
        break;
      }
      
      // Checks if tie
      if (check4Tie(grid) == 'Y')
      {
        printGrid(grid);
        cout << "It's a tie!" << endl;
        ties++;
        break;
      } // end if
      
      // O moves. Specific player that moves is selected by user
      switch(player)
      {
        case 1: // Human
          goO1(grid);
          break;
          
        case 2: // Dumb computer
          goO2(grid);
          break;
          
        case 3: // Smart computer
          goO3(grid);
          break;
          
        default:
          break;
      } // end switch
      
      // Checks if O is winner
      if (check4Owinner(grid) == 'Y')
      {
        printGrid(grid);
        cout << "O wins! " << endl;
        owins++;
        break;
      } // end if
      
      
    } // end while
    
    cout << "Would you like to play again [y/n]?" << endl;
    cin >> replay;
    
    if ((replay == 'n') || (replay == 'N'))
      break;
  }
  
  cout << "Scores" << endl;
  cout << "======" << endl;
  cout << "X wins: " << xwins << endl;
  cout << "O wins: " << owins << endl;
  cout << "  Ties: " << ties << endl;
  intScores[0] = xwins;
  intScores[1]= owins;
  intScores[2]= ties;
  // Call function to save scores
  scores(intScores);
  
}

// Display the tic-tac-toe grid
void printGrid(const char theGrid[])
{
  cout << endl;
  cout << ' ' << theGrid[0] << " |" << ' ' << theGrid[1] << " |" << ' ' << theGrid[2] << endl;
  cout << "---+---+---" << endl;
  cout << ' ' <<  theGrid[3] << " |" << ' ' << theGrid[4] << " |" << ' ' << theGrid[5] << endl;
  cout << "---+---+---" << endl;
  cout << ' ' << theGrid[6] << " |" << ' ' << theGrid[7] << " |" << ' ' << theGrid[8] << endl;
}

void printInstructions()
{
  cout << "\nValid entries are as follows:\n\n";
  cout << " Q | W | E" << endl;
  cout << "---+---+---" << endl;
  cout << " A | S | D" << endl;
  cout << "---+---+---" << endl;
  cout << " Z | X | C \n" << endl << endl;
}

void goX(char theGrid[])
{
  char chrInput = 'g'; // Dummy value
  bool blnValid;
  bool blnTryAgain;
  
  printInstructions();
  blnTryAgain = true;
  
  while (blnTryAgain) // Continue looping until an empty cell is found
  {
    // call function to display valid options
    cout << "X Player - Its your Turn. Move: \n";
    
    // Prompt for input
    cin >> chrInput;
    
    blnValid = false;
    
    // Call function to validate input
    blnValid = f_ValidEntry(chrInput);
    
    // Check if array element is occupied
    if (blnValid == true)
    {
      if ((chrInput == 'q') || (chrInput == 'Q'))
      {
        if (theGrid[0] == ' ')
        {
          theGrid[0] = 'X';
          blnTryAgain = false;
        }
        else
        {
          cout << "  Position already taken! Try again!" << endl;
        }
      }
      if ((chrInput == 'w') || (chrInput == 'W'))
      {
        if (theGrid[1] == ' ')
        {
          theGrid[1] = 'X';
          blnTryAgain = false;
        }
        else
        {
          cout << "  Position already taken! Try again!" << endl;
        }
      }
      if ((chrInput == 'e') || (chrInput == 'E'))
      {
        if (theGrid[2] == ' ')
        {
          theGrid[2] = 'X';
          blnTryAgain = false;
        }
        else
        {
          cout << "  Position already taken! Try again!" << endl;
        }
      }
      if ((chrInput == 'a') || (chrInput == 'A'))
      {
        if (theGrid[3] == ' ')
        {
          theGrid[3] = 'X';
          blnTryAgain = false;
        }
        else
        {
          cout << "  Position already taken! Try again!" << endl;
        }
      }
      if ((chrInput == 's') || (chrInput == 'S'))
      {
        if (theGrid[4] == ' ')
        {
          theGrid[4] = 'X';
          blnTryAgain = false;
        }
        else
        {
          cout << "  Position already taken! Try again!" << endl;
        }
      }
      if ((chrInput == 'd') || (chrInput == 'D'))
      {
        if (theGrid[5] == ' ')
        {
          theGrid[5] = 'X';
          blnTryAgain = false;
        }
        else
        {
          cout << "  Position already taken! Try again!" << endl;
        }
      }
      if (chrInput == 'z' || chrInput == 'Z')
      {
        if (theGrid[6] == ' ')
        {
          theGrid[6] = 'X';
          blnTryAgain = false;
        }
        else
        {
          cout << "  Position already taken! Try again!" << endl;
        }
      }
      if (chrInput == 'x' || chrInput == 'X')
      {
        if (theGrid[7] == ' ')
        {
          theGrid[7] = 'X';
          blnTryAgain = false;
        }
        else
        {
          cout << "  Position already taken! Try again!" << endl;
        }
      }
      if (chrInput == 'c' || chrInput == 'C')
      {
        if (theGrid[8] == ' ')
        {
          theGrid[8] = 'X';
          blnTryAgain = false;
        }
        else
        {
          cout << "  Position already taken! Try again!" << endl;
        }
      }
    } // Valid input
    else // (blnValid == false)
    {
      cout << "You've entered: " << chrInput << endl;
      cout << "This is an invalid entry. Try again!" << endl << endl;
      printInstructions(); // display valid options
    } // Checking input
  } // while blnTryAgain
}

void goO1(char theGrid[])
{
  char chrInput = 'g'; // Dummy value
  bool blnValid;
  bool blnTryAgain;
  
  printInstructions();
  blnTryAgain = true;
  
  while (blnTryAgain) // Continue looping until an empty cell is found
  {
    // call function to display valid options
    cout << "O Player - Its your Turn. Move: \n";
    
    // Prompt for input
    cin >> chrInput;
    
    blnValid = false;
    
    // Call function to validate input
    blnValid = f_ValidEntry(chrInput);
    
    // Check if array element is occupied
    if (blnValid == true)
    {
      if ((chrInput == 'q') || (chrInput == 'Q'))
      {
        if (theGrid[0] == ' ')
        {
          theGrid[0] = 'O';
          blnTryAgain = false;
        }
        else
        {
          cout << "  Position already taken! Try again!" << endl;
        }
      }
      if ((chrInput == 'w') || (chrInput == 'W'))
      {
        if (theGrid[1] == ' ')
        {
          theGrid[1] = 'O';
          blnTryAgain = false;
        }
        else
        {
          cout << "  Position already taken! Try again!" << endl;
        }
      }
      if ((chrInput == 'e') || (chrInput == 'E'))
      {
        if (theGrid[2] == ' ')
        {
          theGrid[2] = 'O';
          blnTryAgain = false;
        }
        else
        {
          cout << "  Position already taken! Try again!" << endl;
        }
      }
      if ((chrInput == 'a') || (chrInput == 'A'))
      {
        if (theGrid[3] == ' ')
        {
          theGrid[3] = 'O';
          blnTryAgain = false;
        }
        else
        {
          cout << "  Position already taken! Try again!" << endl;
        }
      }
      if ((chrInput == 's') || (chrInput == 'S'))
      {
        if (theGrid[4] == ' ')
        {
          theGrid[4] = 'O';
          blnTryAgain = false;
        }
        else
        {
          cout << "  Position already taken! Try again!" << endl;
        }
      }
      if ((chrInput == 'd') || (chrInput == 'D'))
      {
        if (theGrid[5] == ' ')
        {
          theGrid[5] = 'O';
          blnTryAgain = false;
        }
        else
        {
          cout << "  Position already taken! Try again!" << endl;
        }
      }
      if (chrInput == 'z' || chrInput == 'Z')
      {
        if (theGrid[6] == ' ')
        {
          theGrid[6] = 'O';
          blnTryAgain = false;
        }
        else
        {
          cout << "  Position already taken! Try again!" << endl;
        }
      }
      if (chrInput == 'x' || chrInput == 'X')
      {
        if (theGrid[7] == ' ')
        {
          theGrid[7] = 'O';
          blnTryAgain = false;
        }
        else
        {
          cout << "  Position already taken! Try again!" << endl;
        }
      }
      if (chrInput == 'c' || chrInput == 'C')
      {
        if (theGrid[8] == ' ')
        {
          theGrid[8] = 'O';
          blnTryAgain = false;
        }
        else
        {
          cout << "  Position already taken! Try again!" << endl;
        }
      }
    } // Valid input
    else // (blnValid == false)
    {
      cout << "You've entered: " << chrInput << endl;
      cout << "This is an invalid entry. Try again!" << endl << endl;
      printInstructions(); // display valid options
    } // Checking input
  } // while blnTryAgain
}

void goO2(char theGrid[])
{
  bool blnValid;
  srand( (unsigned)time(NULL)); rand();
  int choice = 0;
  
  blnValid = (f_ValidEntry(choice));
  do
  {
    choice = rand()%9;
    if(theGrid[choice]=='O' || theGrid[choice]=='X') continue;
    else
    {
      theGrid[choice]='O';
      f_ValidEntry(choice);
      break;
    }
  }while(true);
}

void goO3(char square[])
{
  
  //Try to win part
  if ((square[0] == 'O') && (square[1] == 'O') && (square[2] == ' '))
  {
    square[2] = 'O'; // O wins. 3 in a row
    cout << " O wins! 3 in a row! \n";
    return;
  }
  else if ((square[0] == 'O') && (square[1] == ' ') && (square[2] == 'O'))
  {
    square[1] = 'O'; // O wins. 3 in a row
    return;
  }
  else if ((square[0] == ' ') && (square[1] == 'O') && (square[2] == 'O'))
  {
    square[0] = 'O'; // O wins. 3 in a row
    return;
  }
  else if ((square[3] == 'O') && (square[4] == 'O') && (square[5] == ' '))
  {
    square[5] = 'O'; // O wins. 3 in a row
    return;
  }
  else if ((square[3] == 'O') && (square[4] == ' ') && (square[5] == 'O'))
  {
    square[4] = 'O'; // O wins. 3 in a row
    return;
  }
  else if ((square[3] == ' ') && (square[4] == 'O') && (square[5] == 'O'))
  {
    square[3] = 'O'; // O wins. 3 in a row
    return;
  }
  else if ((square[6] == 'O') && (square[7] == 'O') && (square[8] == ' '))
  {
    square[8] = 'O'; // O wins. 3 in a row
    return;
  }
  else if ((square[6] == 'O') && (square[7] == ' ') && (square[8] == 'O'))
  {
    square[7] = 'O'; // O wins. 3 in a row
    return;
  }
  else if ((square[6] == ' ') && (square[7] == '0') && (square[8] == 'O'))
  {
    square[6] = 'O'; // O wins. 3 in a
    return;
  }
  else if ((square[0] == 'O') && (square[3] == 'O') && (square[6] == ' '))
  {
    square[6] = 'O'; // O wins. 3 in a row
    return;
  }
  else if ((square[0] == 'O') && (square[3] == ' ') && (square[6] == 'O'))
  {
    square[3] = 'O'; // O wins. 3 in a row
    return;
  }
  else if ((square[0] == ' ') && (square[3] == 'O') && (square[6] == 'O'))
  {
    square[0] = 'O'; // O wins. 3 in a row
    return;
  }
  else if ((square[1] == 'O') && (square[4] == 'O') && (square[7] == ' '))
  {
    square[7] = 'O'; // O wins. 3 in
    return;
  }
  else if ((square[1] == 'O') && (square[4] == ' ') && (square[7] == 'O'))
  {
    square[4] = 'O'; // O wins. 3 in
    return;
  }
  else if ((square[1] == ' ') && (square[4] == 'O') && (square[7] == 'O'))
  {
    square[1] = 'O'; // O wins. 3 in
    return;
  }
  else if ((square[2] == 'O') && (square[5] == 'O') && (square[8] == ' '))
  {
    square[8] = 'O'; // O wins. 3 in a row
    return;
  }
  else if ((square[2] == 'O') && (square[5] == ' ') && (square[8] == 'O'))
  {
    square[5] = 'O'; // O wins. 3 in a row
    return;
  }
  else if ((square[2] == ' ') && (square[5] == 'O') && (square[8] == 'O'))
  {
    square[2] = 'O'; // O wins. 3 in a row
    return;
  }
  else if ((square[0] == 'O') && (square[4] == 'O') && (square[8] == ' '))
  {
    square[8] = 'O'; // O wins. 3 in a row
    return;
  }
  else if ((square[0] == 'O') && (square[4] == ' ') && (square[8] == 'O'))
  {
    square[4] = 'O'; // O wins. 3 in a row
    return;
  }
  else if ((square[0] == ' ') && (square[4] == 'O') && (square[8] == 'O'))
  {
    square[0] = 'O'; // O wins. 3 in a row
    return;
  }
  else if ((square[2] == 'O') && (square[4] == 'O') && (square[6] == ' '))
  {
    square[6] = 'O'; // O wins. 3 in a row
    return;
  }
  else if ((square[2] == 'O') && (square[4] == ' ') && (square[6] == 'O'))
  {
    square[4] = 'O'; // O wins. 3 in a row
    return;
  }
  else if ((square[2] == ' ') && (square[4] == 'O') && (square[6] == 'O'))
  {
    square[2] = 'O'; // O wins. 3 in a row
    return;
  }
  
  //Try to block
  else
  {
    if ((square[0] == 'X') && (square[1] == 'X') && (square[2] == ' '))
    {
      square[2] = 'O'; // O wins. 3 in a row
      return;
    }
    else if ((square[0] == 'X') && (square[1] == ' ') && (square[2] == 'X'))
    {
      square[1] = 'O'; // O wins. 3 in a row
      return;
    }
    else if ((square[0] == ' ') && (square[1] == 'X') && (square[2] == 'X'))
    {
      square[0] = 'O'; // O wins. 3 in a row
      return;
    }
    else if ((square[3] == 'X') && (square[4] == 'X') && (square[5] == ' '))
    {
      square[5] = 'O'; // O wins. 3 in a row
      return;
    }
    else if ((square[3] == 'X') && (square[4] == ' ') && (square[5] == 'X'))
    {
      square[4] = 'O'; // O wins. 3 in a row
      return;
    }
    else if ((square[3] == ' ') && (square[4] == 'X') && (square[5] == 'X'))
    {
      square[3] = 'O'; // O wins. 3 in a row
      return;
    }
    else if ((square[6] == 'X') && (square[7] == 'X') && (square[8] == ' '))
    {
      square[8] = 'O'; // O wins. 3 in a row
      return;
    }
    else if ((square[6] == 'X') && (square[7] == ' ') && (square[8] == 'X'))
    {
      square[7] = 'O'; // O wins. 3 in a row
      return;
    }
    else if ((square[6] == ' ') && (square[7] == 'X') && (square[8] == 'X'))
    {
      square[6] = 'O'; // O wins. 3 in a
      return;
    }
    else if ((square[0] == 'X') && (square[3] == 'X') && (square[6] == ' '))
    {
      square[6] = 'O'; // O wins. 3 in a row
      return;
    }
    else if ((square[0] == 'X') && (square[3] == ' ') && (square[6] == 'X'))
    {
      square[3] = 'O'; // O wins. 3 in a row
      return;
    }
    else if ((square[0] == ' ') && (square[3] == 'X') && (square[6] == 'X'))
    {
      square[0] = 'O'; // O wins. 3 in a row
      return;
    }
    else if ((square[1] == 'X') && (square[4] == 'X') && (square[7] == ' '))
    {
      square[7] = 'O'; // O wins. 3 in
      return;
    }
    else if ((square[1] == 'X') && (square[4] == ' ') && (square[7] == 'X'))
    {
      square[4] = 'O'; // O wins. 3 in
      return;
    }
    else if ((square[1] == ' ') && (square[4] == 'X') && (square[7] == 'X'))
    {
      square[1] = 'O'; // O wins. 3 in
      return;
    }
    else if ((square[2] == 'X') && (square[5] == 'X') && (square[8] == ' '))
    {
      square[8] = 'O'; // O wins. 3 in a row
      return;
    }
    else if ((square[2] == 'X') && (square[5] == ' ') && (square[8] == 'X'))
    {
      square[5] = 'O'; // O wins. 3 in a row
      return;
    }
    else if ((square[2] == ' ') && (square[5] == 'X') && (square[8] == 'X'))
    {
      square[2] = 'O'; // O wins. 3 in a row
      return;
    }
    else if ((square[0] == 'X') && (square[4] == 'X') && (square[8] == ' '))
    {
      square[8] = 'O'; // O wins. 3 in a row
      return;
    }
    else if ((square[0] == 'X') && (square[4] == ' ') && (square[8] == 'X'))
    {
      square[4] = 'O'; // O wins. 3 in a row
      return;
    }
    else if ((square[0] == ' ') && (square[4] == 'X') && (square[8] == 'X'))
    {
      square[0] = 'O'; // O wins. 3 in a row
      return;
    }
    else if ((square[2] == 'X') && (square[4] == 'X') && (square[6] == ' '))
    {
      square[6] = 'O'; // O wins. 3 in a row
      return;
    }
    else if ((square[2] == 'X') && (square[4] == ' ') && (square[6] == 'X'))
    {
      square[4] = 'O'; // O wins. 3 in a row
      return;
    }
    else if ((square[2] == ' ') && (square[4] == 'X') && (square[6] == 'X'))
    {
      square[2] = 'O'; // O wins. 3 in a row
      return;
    }
  }
  for (int i = 0; i < 9; i++)
  {
    i = rand()%9;
    if (square[i] == ' ')
    {
      square[i] = 'O';
      return;
    }
  }
}


//Check the winner function for O
char check4Owinner(char theGrid[])
{
  char chrOwins;
  if ((theGrid[0] == 'O') && (theGrid[1] == 'O') && (theGrid[2] == 'O'))
  {
    chrOwins = 'Y'; // 3 in a row, top row
    
  }
  else if ((theGrid[3] == 'O') && (theGrid[4] == 'O') && (theGrid[5] == 'O'))
  {
    chrOwins = 'Y';  // 3 in row, middle
  }
  else if ((theGrid[6] == 'O') && (theGrid[7] == 'O') && (theGrid[8] == 'O'))
  {
    chrOwins = 'Y'; // 3 in row bottom part
  }
  else if ((theGrid[0] == 'O') && (theGrid[4] == 'O') && (theGrid[8] == 'O'))
  {
    chrOwins = 'Y';    // Diagonal
  }
  else if ((theGrid[6] == 'O') && (theGrid[4] == 'O') && (theGrid[2] == 'O'))
  {
    chrOwins = 'Y';
  }
  else if ((theGrid[0] == 'O') && (theGrid[3] == 'O') && (theGrid[6] == 'O'))
  {
    chrOwins = 'Y';
  }
  else if ((theGrid[1] == 'O') && (theGrid[4] == 'O') && (theGrid[7] == 'O'))
  {
    chrOwins = 'Y';
  }
  else if ((theGrid[2] == 'O') && (theGrid[5] == 'O') && (theGrid[8] == 'O'))
  {
    chrOwins = 'Y';
  }
  else
  {
    chrOwins = 'N';
  }
  return chrOwins;
}

//Check the winner for X
char check4Xwinner(char theGrid[])
{
  char chrWins;
  if ((theGrid[0] == 'X') && (theGrid[1] == 'X') && (theGrid[2] == 'X'))
  {
    chrWins = 'Y'; // 3 in a row, top row
  }
  else if ((theGrid[3] == 'X') && (theGrid[4] == 'X') && (theGrid[5] == 'X'))
  {
    chrWins = 'Y';
  }
  else if ((theGrid[6] == 'X') && (theGrid[7] == 'X') && (theGrid[8] == 'X'))
  {
    chrWins = 'Y';
  }
  else if ((theGrid[0] == 'X') && (theGrid[4] == 'X') && (theGrid[8] == 'X'))
  {
    chrWins = 'Y';
  }
  else if ((theGrid[6] == 'X') && (theGrid[4] == 'X') && (theGrid[2] == 'X'))
  {
    chrWins = 'Y';
  }
  
  else if ((theGrid[0] == 'X') && (theGrid[3] == 'X') && (theGrid[6] == 'X'))
  {
    chrWins = 'Y';
  }
  else if ((theGrid[1] == 'X') && (theGrid[4] == 'X') && (theGrid[7] == 'X'))
  {
    chrWins = 'Y';
  }
  
  else if ((theGrid[2] == 'X') && (theGrid[5] == 'X') && (theGrid[8] == 'X'))
  {
    chrWins = 'Y';
  }
  else
  {
    chrWins = 'N';
  }
  return chrWins;
}

char check4Tie(char theGrid[])   //Check if the game is tie function
{
  char chrTie;
  if (theGrid[0] == ' ')
  {
    chrTie = 'N';
  }
  else if (theGrid[1] == ' ')
  {
    chrTie = 'N';
  }
  else if (theGrid[2] == ' ')
  {
    chrTie = 'N';
  }
  else if (theGrid[3] == ' ')
  {
    chrTie = 'N';
  }
  else if (theGrid[4] == ' ')
  {
    chrTie = 'N';
  }
  else if (theGrid[5] == ' ')
  {
    chrTie = 'N';
  }
  else if (theGrid[6] == ' ')
  {
    chrTie = 'N';
  }
  else if (theGrid[7] == ' ')
  {
    chrTie = 'N';
  }
  else if (theGrid[8] == ' ')
  {
    chrTie = 'N';
  }
  else
  {
    chrTie = 'Y';
  }
  return chrTie;
}


// Compares input against array of valid characters
bool f_ValidEntry(char chrInput)
{
  char chrValidCharacters[]={"qweasdzxcQWEASDZXC"}; // array against which validation is performed
  
  bool blnValid = false;
  // Traverse array comparing input to array of valid entries
  for (int i=0; i < 19; i++)
  {
    if (chrValidCharacters[i] == chrInput) // Valid input
    {
      blnValid = true;
    }
  }
  return  blnValid;
}


void s_ReadScores(int theScores[])  //File Record Function
{
  int i = 0;
  ifstream fin; // Create stream adaptor
  fin.open("t3.ini"); // Using adaptor, open specified file
  
  if (!fin) // Some sort of reading error, or file does not exist
  {
    // Set all scores to zero
    theScores[0] = 0; // Xs
    theScores[1] = 0; // Os
    theScores[2] = 0; // Ties
  }
  else
  {
    // Read each line into array
    while (!fin.eof())
    {
      fin >> theScores[i];
      i = (i+1);
    }
  }
  // Close file
  fin.close();
}

void scores(int theScores[])  //Keep scores function
{
  ofstream fout; // Create stream adaptor
  fout.open("t3.ini"); // Using adaptor, open source file
  if (!fout)
  {
    cout << "Can't open file to save scores!" << endl;
  }
  else
  {
    for (int i =0; i<3; i++)
    {
      fout << theScores[i] << endl;
    }
  }
  // Close file
  fout.close();
  
}
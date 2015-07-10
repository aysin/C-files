//Aysin Oruz
// Lab 6
// Xcode : compiler n editor

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

//Functions Prototypes
int readArray ( int, int []);
int stat (int, const int[], int&,int&, int&);
int histogram ( int, const int[], int[]);

int main()
{
  const int MAX_SCORE = 50;   // The max # of scores a user can enter
  int score [MAX_SCORE];  // Storege for up to 50 scores enter by user

  // Print out the name and lab
  cout<<" Aysin Oruz - 1331735 \n";
  cout<<" Lab 6 \n";
  cout<<" Computer Science 165 \n\n\n";

  //Promt user to enter the array of number to calcuate the scores
  cout<<"(Enter a '-1' after last score is entered)\nPlease enter up to 50 scores between 0 - 100 : \n\n";
  int nScores = readArray(MAX_SCORE, score);

  //calculate the Avg. Max and Min. of numbers
  int avgScore, minScore, maxScore;
  if(stat(nScores, score, avgScore, minScore, maxScore) == 0)
  {
    cout<<"\nAverage= "<<avgScore<<endl
    <<"Max= "<<maxScore<<endl
    <<"Min= "<<minScore<<endl;
    
    // find how many Grades were earned
    int grade [5] = {};
    histogram(nScores, score, grade);
    cout << "A's: " << grade[0]<<endl;
    cout << "B's: " << grade[1]<<endl;
    cout << "C's: " << grade[2]<<endl;
    cout << "D's: " << grade[3]<<endl;
    cout << "F's: " << grade[4]<<endl;
  }
  else
    cout<<"-- NO DATA --";  // if the function doesnt return the value of 0
}




int readArray ( int sizeArray, int goal[])
{
  string buf;               // if user enters non-numeric input;
  int nGoal =0;

  // loop to count how many numberes is entered
  for (int i = 0; i < sizeArray; i++)
  {
    cin>> buf; goal [i] = atoi(buf.c_str());
    
    if (goal [i] < 0)
        break;   //no more scores after the 1st negative is found
    else
        nGoal++;  //count the score if its non-negative
  }
  return nGoal;
}

//Function to calculate the Average, Max and min
int stat( int numberCount, const int setOfNumber[],int& avg, int& max, int& min)
{
  int total = 0;  //initilize total

  //average numbers in array
  for ( int i = 0; i < numberCount; i++)
   { 
    if ( setOfNumber[i] < 0)  // if number is below 0 break
        break;
    else
        total += setOfNumber[i];
   }
  if ( numberCount == 0)  //
    return 1;
  else
    avg = total / numberCount;

  //MAximum number in array
  int mx = setOfNumber [0];
  for ( int i=0; i < numberCount; i++)
    if ( mx > setOfNumber[i])
    {
        mx = setOfNumber [i];
    }
  max = mx;

  //minimum number in array
  int mn = setOfNumber [0];
  for ( int i=0; i < numberCount; i++)
    if ( mn < setOfNumber[i])
    {
        mn = setOfNumber [i];
    }
  min = mn;

  return 0;
}


int histogram ( int mScore, const int arraySize[], int grade[])
{
  for( int i=0 ;i < mScore ;i++)
   {

    //if the numbers entered between 100-90 add to grade count
    if ( arraySize[i] <= 100 && arraySize[i] >= 90)
        grade[0] ++;
    
    //if the numbers entered between 90-80 add to grade count
    if ( arraySize[i] < 90 && arraySize[i] >= 80)
        grade[1] ++;
    
    //if the numbers entered between 80-70 add to grade count
    if ( arraySize[i] < 80 && arraySize[i] >= 70)
        grade[2] ++;
    
    //if the numbers entered between 70-60 add to grade count
    if ( arraySize[i] < 70 && arraySize[i] >= 60)
        grade[3] ++;
    
    //if the numbers entered between 60-0 add to grade count
    if ( arraySize[i] < 60 && arraySize[i] >= 0)
        grade[4] ++;
   }

  //return 0 if its true
  return 0;
}
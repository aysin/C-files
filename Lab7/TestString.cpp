// Aysin Oruz
// Lab 7 - 1331735
// Compiler & Editor : XCode
// Com. Sci. 165  - Prof. Burns

#include <iostream>
using std::cout;
using std::cin;
using std::endl;


#include <cstring>


//Prototype for finding the size of array
int myStrLen ( const char[]);
int myStrCpy(char[], const char[]);
int myStrCmp(const char[], const char[]);



int main()
{
    
    char source[128];
    char copyTo[]="ABC";
    cout<<"Enter a string please: "<<endl;
    cin.getline(source, 128);
    
    
    cout<<"Enter another string to compare: "<<endl;
    cin.getline(copyTo, 128);
    
    //print the string and compare it
    cout<<"\nEntered string: "<<source<<endl;
    cout<<"The length of the string: "<<myStrLen(source)<<endl;
    if (myStrCmp(source, copyTo) == 0)
        cout << "The changed string is equals ABC" << endl;
    else
        cout << "The changed string does not equal to ABC" << endl;
    
    //Change the string, print it and compare it
    myStrCpy( copyTo , source);
    cout<< "\nCopied String: "<< source << endl;
    cout<< "Copied String Length: "<< myStrLen(source) << endl;
    if (myStrCpy (source, copyTo) == 0)
        cout << "The changed string is equals ABC" << endl << endl;
    else
        cout << "The changed string is NOT equals ABC" << endl;
    
    
}


int myStrLen ( const char s[])
{
    
    int length = 0 ;
    for( int i = 0; i < length || !'\0'; i++)
    {
        if (s[i] == '\0')
            break;
        else
            length ++;
    }
    return length;
    
}

int myStrCpy ( char *copyAgain, const char *copy)
{
    while ( *copyAgain != '\0' )
    {
        *copyAgain = *copy ;
        copy++ ;
        copyAgain++ ;
    }
    *copyAgain = '\0' ;
    return 0;
    
}

int myStrCmp(const char compareA[], const char compareB[])
{
    int c = 0;
    
    while( compareA[c] == compareB[c] )
    {
        if( compareA[c] == '\0' != compareB[c] == '\0' )
            return -1;
        c++;
    }
    if( compareA[c] == '\0' && compareB[c] == '\0' )
        return 0;
    else
        return -1;
    
}
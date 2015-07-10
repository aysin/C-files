


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
void myStrCpy(char[], const char[]);
int myStrCmp(const char[], const char[]);



int main()
{
    
    char source[128];
    char copyTo[128]={};
    cout<<"Enter a string please: "<<endl;
    cin.getline(source, 128);
    
    
    //print the string and compare it
    cout<<"\n1.String: "<<source<<endl;
    cout<<"The length of the string: "<<myStrLen(source)<<endl;
    if (myStrCmp(source, copyTo) == 0)
        cout << "The changed string is equals " << endl;
    else
        cout << "The changed string does not equal" << endl;
    
    //Change the string, print it and compare it
    myStrCpy( source , copyTo);
    cout<< "\nCopied String: "<< source << endl;
    cout<< "Copied String Length: "<< myStrLen(source) << endl;
    if (myStrCmp (source, copyTo) == '\0')
        cout << "The changed string is equals ABC" << endl << endl;
    else
        cout << "The changed string is NOT equals ABC\n" << endl;
    {
        char source[128];
        char copyTo[128]={};
        cout<<"Enter a string please: "<<endl;
        cin.getline(source, 128);
        
        
        //print the string and compare it
        cout<<"\n1.String: "<<source<<endl;
        cout<<"The length of the string: "<<strlen(source)<<endl;
        if (strcmp(source, copyTo) == 0)
            cout << "The changed string is equals " << endl;
        else
            cout << "The changed string does not equal" << endl;
        
        //Change the string, print it and compare it
        strcpy( source , copyTo);
        cout<< "\nCopied String: "<< source << endl;
        cout<< "Copied String Length: "<< strlen(source) << endl;
        if (strcmp (source, copyTo) == '\0')
            cout << "The changed string is equals ABC" << endl << endl;
        else
            cout << "The changed string is NOT equals ABC\n" << endl;
    }
    
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

void myStrCpy ( char copyAgain[], const char copy[])
{
   //delete the first string
    for (int i = 0; ;i++)
    {
        if (copyAgain[i] == '\0')
            break;
        else
            copyAgain[i] = 0;
    }
    
    //copying copy array into new one
    for ( int j = 0; ;j++)
    {
        if (copy[j] == '\0')
            break;
        else
            copyAgain[j] = copy[j];
    }
}

int myStrCmp(const char compareA[], const char compareB[])
{
    int c = 0;
    int flag = 0;
    
    while( compareA[c] != '\0' && compareB[c] != '\0')
    {
        if( compareA[c] == '\0' || compareB[c] == '\0' ){
            flag=1;
            break;}
        c++;
    }
    if( flag == 0 && compareA[c] == '\0' && compareB[c] == '\0' )
        return 0;
    else
        return 1;
}
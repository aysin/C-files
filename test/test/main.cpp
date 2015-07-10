//
//
//Lab 2b, Rectangle.h RectangleDriver.cpp Program
//Programmer: Aysin Oruz
//Compiler(s) used: Xcode and Terminal

#include <iostream>
using namespace std;

#include <cassert>
#include "Rectangle.h"
#include "Rectangle.h" //ifndef test

#include "Fraction.h"

ostream& operator<<(ostream& os, const Fraction& f)
{
  return os << f.numerator << "/" << f.denominator ;
}

int main()
{
  cout << "\n\nLab 2b,Rectangle.h RectangleDriver.cpp \n";
  cout << "Programmer: Aysin Oruz \n";
  cout << "Editor(s) used: JNotePad and Xcode \n";
  cout << "Compiler(s) used: Xcode and Terminal \n";
  cout << "Description: The purpose of this lab is for you to learn how to create and apply a templated class. It also demonstrates the concept of data abstraction, as the Rectangle class you write is to know or care nothing about the Fraction class!.";
  cout << "File: " <<  __FILE__ << endl;
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << endl;
  
  
  Rectangle<float> box; //setLength ; setWidth
  box.setLength (15);  //Testing with new Numbers
  box.setWidth (36.7);  //Testing with new Numbers
  
  //Testing first elements LENGHT-WIDTH-AREA-PERIMETER
  cout << "\n\nTESTING 1. SET OF NUMBERS\n";
  cout << "Value at lenght is " << box.getLength() << endl;
  cout << "I expected 15\n";
  assert ( box.getLength() == 15);
  
  cout << "\nValue at width is " << box.getWidth() << endl;
  cout << "I expected 36.7\n";
  assert ( box.getWidth() > 36.6 && box.getWidth() < 36.8 );
  
  cout << "\nValue for area is " << box.getArea() << endl;
  cout << "Expected value for area is 550.5\n";
  assert ( box.getArea() > 550.4 &&  box.getArea() < 550.6);
  
  cout << "\nValue for perimeter is " << box.getPerimeter() << endl;
  cout << "Expected value for perimeter is 103.4\n";
  assert ( box.getPerimeter() > 103.3 && box.getPerimeter() < 103.5 );
  
  cout << "\nTesting the length and width comparison\n";
  cout << "Expected result 36.7 width is greater than 15 length\n";
  if(box.lenOrWid ())
  {
    cout << box.getLength() << " Length is greater than width " << box.getWidth() << endl;
  }
  else
  {
    cout << box.getWidth() << " Width is greater than length " << box.getLength() << endl;
  }
  
  // object copy testing, with assignment Upon decleration
  {
    Rectangle<float> copy = box;
    box.setLength (15);  //Testing with new Numbers
    box.setWidth (36.7);  //Testing with new Numbers
    
    //Testing first elements LENGHT-WIDTH-AREA-PERIMETER
    cout << "\nObject copy testing, with assignment UPON declaration\n" << endl;
    cout << "Value at lenght is " << copy.getLength() << endl;
    cout << "I expected 15\n";
    assert ( copy.getLength() == 15);
    
    cout << "\nValue at width is " << copy.getWidth() << endl;
    cout << "I expected 36.7\n";
    assert ( copy.getWidth() > 36.6 && copy.getWidth() < 36.8 );
    
    cout << "\nValue for area is " << copy.getArea() << endl;
    cout << "Expected value for area is 550.5\n";
    assert ( copy.getArea() > 550.4 &&  copy.getArea() < 550.6);
    
    cout << "\nValue for perimeter is " << copy.getPerimeter() << endl;
    cout << "Expected value for perimeter is 103.4\n";
    assert ( copy.getPerimeter() > 103.3 && copy.getPerimeter() < 103.5 );
    
    cout << "\nTesting the length and width comparison\n";
    cout << "Expected result 36.7 width is greater than 15 length\n";
    if(copy.lenOrWid ())
    {
      cout << copy.getLength() << " Length is greater than width " << copy.getWidth() << endl;
    }
    else
    {
      cout << copy.getWidth() << " Width is greater than length " << copy.getLength() << endl;
    }
  }
  
  // object copy testing, with assignment AFTER decleration
  {
    Rectangle<float> copy; copy = box;
    box.setLength (15);  //Testing with new Numbers
    box.setWidth (36.7);  //Testing with new Numbers
    
    //Testing first elements LENGHT-WIDTH-AREA-PERIMETER
    cout << "\nObject copy testing, with assignment AFTER declaration\n" << endl;
    cout << "Value at lenght is " << copy.getLength() << endl;
    cout << "I expected 15\n";
    assert ( copy.getLength() == 15);
    
    cout << "\nValue at width is " << copy.getWidth() << endl;
    cout << "I expected 36.7\n";
    assert ( copy.getWidth() > 36.6 && copy.getWidth() < 36.8 );
    
    cout << "\nValue for area is " << copy.getArea() << endl;
    cout << "Expected value for area is 550.5\n";
    assert ( copy.getArea() > 550.4 &&  copy.getArea() < 550.6);
    
    cout << "\nValue for perimeter is " << copy.getPerimeter() << endl;
    cout << "Expected value for perimeter is 103.4\n";
    assert ( copy.getPerimeter() > 103.3 && copy.getPerimeter() < 103.5 );
    
    cout << "\nTesting the length and width comparison\n";
    cout << "Expected result 36.7 width is greater than 15 length\n";
    if(copy.lenOrWid ())
    {
      cout << copy.getLength() << " Length is greater than width " << copy.getWidth() << endl;
    }
    else
    {
      cout << copy.getWidth() << " Width is greater than length " << copy.getLength() << endl;
    }
  }
  
  //Testing with FRACTION as a DataType
  Fraction a, b ,perimeter, area;
  a.numerator = 1;
  a.denominator = 4;
  b.numerator = 2;
  b.denominator = 3;
  
  Rectangle<Fraction> f;
  f.setLength(a);
  f.setWidth(b);
  
  cout << "\nTESTING FRACTION DATATYPE\n";
  cout << "Actual Lenght: " << f.getLength()<< endl;
  cout << "Expected Length: 1/4\n\n";
  
  cout << "Actual Width: " << f.getWidth() << endl;
  cout << "Expected Width: 2/3\n\n";
  
  cout << "Actual Area is: " << f.getArea() << endl;
  cout << "Expected Area is: 2/12\n\n";
  
  cout << "Perimeter is: " << f.getPerimeter() << endl;
  cout << "Expected Perimeter is 22/12\n";
  
  cout << "\nTesting the length and width comparison\n";
  cout << "Expected result 2/3 width is greater than 1/4 length\n";
  if(box.lenOrWid ())
  {
    cout << box.getLength() << " Length is greater than width " << box.getWidth() << endl;
  }
  else
  {
    cout << box.getWidth() << " Width is greater than length " << box.getLength() << endl << endl;
  }
  
  //Object Copy Testing with UPON Declaration
  {
    Rectangle<Fraction> copy = f;
    Fraction a, b ,perimeter, area;
    a.numerator = 1;
    a.denominator = 4;
    b.numerator = 2;
    b.denominator = 3;
    
    cout << "\nObject copy testing, with assignment UPON declaration\n" << endl;
    cout << "Actual Area is: " << copy.getArea() << endl;
    cout << "Expected Area is: 2/12\n\n";
    
    cout << "Perimeter is: " << copy.getPerimeter() << endl;
    cout << "Expected Perimeter is 22/12\n";
    
  }
  
  //Object Copy Testing with After Declaration
  {
    Rectangle<Fraction> copy; copy = f;
    Fraction a, b ,perimeter, area;
    a.numerator = 1;
    a.denominator = 4;
    b.numerator = 2;
    b.denominator = 3;
    
    cout << "\nObject copy testing, with assignment UPON declaration\n" << endl;
    cout << "Actual Area is: " << copy.getArea() << endl;
    cout << "Expected Area is: 2/12\n\n";
    
    cout << "Perimeter is: " << copy.getPerimeter() << endl;
    cout << "Expected Perimeter is 22/12\n\n";
    
  }
}
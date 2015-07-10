//
//
//Lab 2b, Rectangle.h RectangleDriver.cpp Program
//Programmer: Aysin Oruz
//Compiler(s) used: Xcode and Terminal

#ifndef RECTANGLE_H
#define RECTANGLE_H


template  <class DataType>
class Rectangle
{ 
  private:
  DataType length;
  DataType width;
  
  public:
  void setLength (DataType l);
  void setWidth (DataType w);
  DataType& getLength ();
  DataType& getWidth ();
  DataType getArea ();
  DataType getPerimeter ();
  bool lenOrWid ();
};

template <class DataType>
bool Rectangle<DataType>::lenOrWid ()  //compare length vs width
{
  bool result;
  if (width < length)
    result = true;
  
  if (width > length)
    return false;
  
  return result;
}

template <class DataType>
void Rectangle<DataType>::setLength (DataType l)
{
  length = l;
}

template <class DataType>
void Rectangle<DataType>::setWidth (DataType w)
{
  width = w;
}

template <class DataType>
DataType& Rectangle<DataType>::getLength ()
{ 
  return length; 
} 

template <class DataType>
DataType& Rectangle<DataType>::getWidth ()
{ 
  return width; 
} 

template <class DataType>
DataType Rectangle<DataType>::getArea ()
{
return (length*width);
} 

template <class DataType>
DataType Rectangle<DataType>::getPerimeter ()
{ 
  return ((2 * length) + (2 * width));
} 

#endif


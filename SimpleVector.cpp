// Program Information ////////////////////////////////////////////////////////
/*
    File Name:    SimpleVector.cpp

    Description:  Implementation of SimpleVector.h
*/

// Version/Revision Information ///////////////////////////////////////////////
/*
    1.00 (09/09/2015) - Jackson Buck
        First complete version of my Simple Vector.
        I believe testing is sufficient considering the assignment's specs.
*/

// Program description/support ////////////////////////////////////////////////
/*
    This is a simple vector which works in conjunction with driver file
    PA02.cpp which was used to test the class and its functions.
*/

// Precompiler directives /////////////////////////////////////////////////////

#ifndef SIMPLE_VECTOR_CLASS_CPP
#define SIMPLE_VECTOR_CLASS_CPP

// Header files ///////////////////////////////////////////////////////////////

#include "SimpleVector.h"
#include <stdexcept>
#include <iostream>

using namespace std;

// Class function implementation //////////////////////////////////////////////

    // constructors

/******************************************************************************
Function Specifications: SimpleVector
===============================================================================
Preconditions:
- none ~ simnply creating new class instance with no arguments
Postconditions:
- new class instance is created with an array of default size;
Algorithm:
- none - just assign the values.
Exceptional/Error Conditions:
- none
*/
template <class DataType>
SimpleVector<DataType>::SimpleVector()
{
    vectorCapacity = DEFAULT_CAPACITY;
    vectorSize = 0;
    vectorData = new DataType[DEFAULT_CAPACITY];
}

/******************************************************************************
Function Specifications: SimpleVector
===============================================================================
Preconditions:
- needs a positive int to set the vector's capacity
Postconditions:
- a new, blank vector is created with a capacity set by int argument
Algorithm:
- assign values.
Exceptional/Error Conditions:
- negative int argument would cause problems.
*/
template <class DataType>
SimpleVector<DataType>::SimpleVector(int newCapacity)
{
    if (newCapacity <= 0)
    {
        throw logic_error("Capacity must be > 0");
    }

    vectorCapacity = newCapacity;
    vectorData = new DataType[vectorCapacity];
    vectorSize = 0;
}

/******************************************************************************
Function Specifications: SimpleVector
===============================================================================
Preconditions:
- Expects positive int value for capacity and some kind of data to store
Postconditions:
- instance of class of int argument size, filling each element with data arg.
Algorithm:
- check for positive int argument
- create new array of type DataType
- loop through to capacity assigning fillValue to each array element.
Exceptional/Error Conditions:
- negative int argument (capacity)
*/
template <class DataType>
SimpleVector<DataType>::SimpleVector(int newCapacity, const DataType &fillValue)
{
    int index = 0;

    if (newCapacity <= 0)
    {
        throw logic_error("capacity must be > 0");
    }

    vectorCapacity = newCapacity;
    vectorSize = newCapacity;
    vectorData = new DataType[vectorCapacity];
    for (index = 0; index < vectorCapacity; index++)
    {
        vectorData[index] = fillValue;
    }
}

/******************************************************************************
Function Specifications: SimpleVector COPY CONSTRUCTOR
===============================================================================
Preconditions:
- receives a source SimpleVector class instance from which to copy
Postconditions:
- this destination SimpleVector instance is a clone of the source
Algorithm:
- copy size & capacity
- create new array of same capacityh
- have copyVector function perform a deep-copy of the array elements.
Exceptional/Error Conditions:
- none
*/
template <class DataType>
SimpleVector<DataType>::SimpleVector(const SimpleVector &copiedVector)
{
    vectorCapacity = copiedVector.vectorCapacity;
    vectorSize = copiedVector.vectorSize;
    vectorData = new DataType[vectorCapacity];
    
    copyVector(vectorData, copiedVector.vectorData);
}

    // destructor

/******************************************************************************
Function Specifications: ~SimpleVector
===============================================================================
Preconditions:
- none
Postconditions:
- array has been cleared
Algorithm:
- delete the array
Exceptional/Error Conditions:
- none
*/
template <class DataType>
SimpleVector<DataType>::~SimpleVector()
{
    if (vectorSize > 0)
    {
        delete[] vectorData;
    }
}

    // assignment

/******************************************************************************
Function Specifications: SimpleVector   OPERATOR= overloading
===============================================================================
Preconditions:
- Receives an instance of SimpleVector which has an existing array
Postconditions:
- This destination has is a clone of the source. Old data is gone.
Algorithm:
- Set size/capacity
- delete old array
- clone new array with copyVector()
Exceptional/Error Conditions:
- none
*/
template <class DataType>
const SimpleVector<DataType>& SimpleVector<DataType>::operator=(const SimpleVector &rhVector)
{    
    vectorCapacity = rhVector.vectorCapacity;
    vectorSize = rhVector.vectorSize;
    delete[] vectorData;    
    vectorData = new DataType[vectorCapacity];

    copyVector(vectorData, rhVector.vectorData);
    
    return *this;
}

    // accessors

/******************************************************************************
Function Specifications: getCapacity
===============================================================================
Preconditions:
- none
Postconditions:
- just returns vectorCapacity
Algorithm:
- just return vectorCapacity
Exceptional/Error Conditions:
- none
*/
template <class DataType>
int SimpleVector<DataType>::getCapacity() const
{
    // cout << "in getCapacity() " << vectorCapacity << endl;
    return vectorCapacity;
}

/******************************************************************************
Function Specifications: getSize
===============================================================================
Preconditions:
- none
Postconditions:
- just returns vectorSize
Algorithm:
- just return vectorSize
Exceptional/Error Conditions:
- none
*/
template <class DataType>
int SimpleVector<DataType>::getSize() const
{
    return vectorSize;
}

// index access
/******************************************************************************
Function Specifications: operator[] overloading
===============================================================================
Preconditions:
- expects an int index for altering a particular point in the array
Postconditions:
- returns the altered data inserted into the point at the array.
Algorithm:
- check for valid index
- return array element data at index
Exceptional/Error Conditions:
- out-of-bounds array index
*/
template <class DataType>
DataType& SimpleVector<DataType>::operator[](int index) throw (logic_error)
{
    if (index < 0 || index >(vectorCapacity - 1))
    {
        throw logic_error("ERROR from not-const operator[] overload");
    }

    return vectorData[index];
}

/******************************************************************************
Function Specifications: const operator[] overloading
===============================================================================
Preconditions:
- expects an int index for altering a particular point in the array
Postconditions:
- returns the altered data inserted into the point at the array.
Algorithm:
- check for valid index
- return array element data at index
Exceptional/Error Conditions:
- out-of-bounds array index
*/
template <class DataType>
const DataType& SimpleVector<DataType>::operator[](int index) const throw (logic_error)
{
    if (index < 0 || index >(vectorCapacity - 1))
    {
        throw logic_error("ERROR from CONST operator[] overload");
    }

    return vectorData[index];
}

    // modifiers
    // allows vector to grow by given quantity
/******************************************************************************
Function Specifications: growBy
===============================================================================
Preconditions:
- Receives positive int for number of elements to add to the vector's capacity
Postconditions:
- New vector with the same data
Algorithm:
- create new array of original+growBy size
- have copyVector duplicate contents
- delete old vector
- have array pointer point to new array
Exceptional/Error Conditions:
- as per in-class instructions, we assume programmer will send a positive int
*/
template <class DataType>
void SimpleVector<DataType>::grow(int growBy)
{
    DataType * newArray;
    int newCapacity, index;

    newCapacity = vectorCapacity + growBy;

    newArray = new DataType[newCapacity];

    copyVector(newArray, vectorData);

    vectorCapacity = newCapacity;

    delete[] vectorData;
    
    vectorData = newArray;
}

    // allows vector to shrink by given quantity
    // allows vector to be shrunk to zero,
    //   but throws logic_error if attempt to shrink to less than zero
    //void shrink(int shrinkBy) throw (logic_error);
/******************************************************************************
Function Specifications: shrink
===============================================================================
Preconditions:
- receives int by which vector array should be shrunk
Postconditions:
- new shrunken array has replaced original array
Algorithm:
- check for valid shrink request
- update vectorCapacity to reflect shortened array lengh
- update size if it is larger than the capacity
- create a new vector array of new, shortened length
- copy the new vector array in copyVector
- delete old array
Exceptional/Error Conditions:
- array must have at least 1 element.  error if shrink to < 1
*/
template <class DataType>
void SimpleVector<DataType>::shrink(int shrinkBy) throw (logic_error)
{
    DataType *shrunkenVector; 

    if (shrinkBy >= vectorCapacity)
    {
        throw logic_error("Cannot shrink into negatives");
    }
    
    vectorCapacity -= shrinkBy;

    if (vectorCapacity < vectorSize)
    {
        vectorSize = vectorCapacity;    
    }

    shrunkenVector = new DataType[vectorCapacity];
    
    copyVector(shrunkenVector, vectorData);

    delete[] vectorData;
    
    vectorData = shrunkenVector;
}

    // increment/decrement don't affect class
    //    but allow programmer to keep track of size inside vector
/******************************************************************************
Function Specifications: incrementSize
===============================================================================
Preconditions:
- int vectorSize has been initialized
Postconditions:
- vectorSize has been increased by 1
Algorithm:
- add 1
Exceptional/Error Conditions:
- none
*/
template <class DataType>
void SimpleVector<DataType>::incrementSize()
{
    vectorSize++;   // As instructed in class, this member only does this.
}

/******************************************************************************
Function Specifications: decrementSize
===============================================================================
Preconditions:
- int vectorSize has been initialized
Postconditions:
- vectorSize has been decreased by 1
Algorithm:
- subtract 1
Exceptional/Error Conditions:
- none
*/
template <class DataType>
void SimpleVector<DataType>::decrementSize()
{
    vectorSize--;   // As instructed in class, this member only does this.
}

    // Private

/******************************************************************************
Function Specifications: copyVector
===============================================================================
Preconditions:
- receives two pointers to already-identically-sized arrays
Postconditions:
- both arrays contain identical data
Algorithm:
- copy array elements one by one until vectorSize has been reached.
Exceptional/Error Conditions:
- none
*/
template <class DataType>
void SimpleVector<DataType>::copyVector(DataType *dest, DataType *src)
{
    int index = 0;

    for (index = 0; index < vectorCapacity; index++)
    {
        dest[index] = src[index];
    }
}

#endif

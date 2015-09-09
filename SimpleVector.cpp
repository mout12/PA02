#include "SimpleVector.h"
#include <stdexcept>
#include <iostream>

using namespace std;

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

///// COPY CONSTRUCTOR
/******************************************************************************
Function Specifications: SimpleVector COPY CONSTRUCTOR
===============================================================================
Preconditions:
-
Postconditions:
-
Algorithm:
-
Exceptional/Error Conditions:
-
*/
template <class DataType>
SimpleVector<DataType>::SimpleVector(const SimpleVector &copiedVector)
{
    int index = 0;

    vectorCapacity = copiedVector.vectorCapacity;
    vectorSize = copiedVector.vectorSize;
    vectorData = new DataType[vectorCapacity];

    for (index = 0; index < vectorSize; index++)
    {
        vectorData[index] = copiedVector.vectorData[index];
    }     
}

// destructor
/******************************************************************************
Function Specifications: SimpleVector
===============================================================================
Preconditions:
-
Postconditions:
-
Algorithm:
-
Exceptional/Error Conditions:
-
*/
template <class DataType>
SimpleVector<DataType>::~SimpleVector()
{
    if (vectorSize > 0)
    {
        delete[] vectorData;
    }
}


// OPERATOR OVERLOADING
// assignment
/******************************************************************************
Function Specifications: SimpleVector
===============================================================================
Preconditions:
-
Postconditions:
-
Algorithm:
-
Exceptional/Error Conditions:
-
*/
template <class DataType>
const SimpleVector<DataType>& SimpleVector<DataType>::operator=(const SimpleVector &rhVector)
{
    int index = 0;

    vectorCapacity = rhVector.vectorCapacity;
    vectorSize = rhVector.vectorSize;
    vectorData = new DataType[vectorCapacity];

    for (index = 0; index < vectorSize; index++)
    {
        vectorData[index] = rhVector.vectorData[index];
    }  

    return *this;
}

// accessors
/******************************************************************************
Function Specifications: SimpleVector
===============================================================================
Preconditions:
-
Postconditions:
-
Algorithm:
-
Exceptional/Error Conditions:
-
*/
template <class DataType>
int SimpleVector<DataType>::getCapacity() const
{
    // cout << "in getCapacity() " << vectorCapacity << endl;
    return vectorCapacity;
}

/******************************************************************************
Function Specifications: SimpleVector
===============================================================================
Preconditions:
-
Postconditions:
-
Algorithm:
-
Exceptional/Error Conditions:
-
*/
template <class DataType>
int SimpleVector<DataType>::getSize() const
{
    return vectorSize;
}

// index access
/******************************************************************************
Function Specifications: operator[]
===============================================================================
Preconditions:
- expects an int index for altering a particular point in the array
Postconditions:
- returns the altered data inserted into the point at the array.
Algorithm:
-
Exceptional/Error Conditions:
-
*/
template <class DataType>
DataType& SimpleVector<DataType>::operator[](int index) throw (logic_error)
{
    //cout << " THE COOL INDEX IS: " << index << endl;
#if 1
    if (index < 0 || index > (vectorCapacity-1))
    {

        //throw logic_error(vectorData[index]);
        throw logic_error("ERROR from not-const operator[] overload");
    }
#endif
//    cout << "operator[" << index << "] (not const) " << vectorData[index] << endl;
    
    return vectorData[index];
}

/******************************************************************************
Function Specifications: SimpleVector
===============================================================================
Preconditions:
-
Postconditions:
-
Algorithm:
-
Exceptional/Error Conditions:
-
*/
template <class DataType>
const DataType& SimpleVector<DataType>::operator[](int index) const throw (logic_error)
{
    //cout << " THE INDEX IS: " << index << endl;
    //cout << " CAPACITY IS : " << vectorCapacity << endl;
 #if 1
    if (index < 0 || index > (vectorCapacity-1))
    {
        //throw logic_error(vectorData[index]);
        throw logic_error("ERROR from CONST operator[] overload");
    }
#endif
//    cout << "operator[" << index << "] (not const) " << vectorData[index] << endl;
    //cout << " THE END" << endl;
    
    return vectorData[index];

}

// modifiers
// allows vector to grow by given quantity
/******************************************************************************
Function Specifications: grow
===============================================================================
Preconditions:
- Receives positive int for number of elements to add to the vector's length
Postconditions:
-
Algorithm:
-
Exceptional/Error Conditions:
-
*/
template <class DataType>
void SimpleVector<DataType>::grow(int growBy)
{
    DataType * tempArray;
    int index;
    int newCapacity, newSize;

    if ((vectorSize + growBy) > vectorCapacity)
    {
        newCapacity = vectorSize + growBy;
    }
    
    newSize = vectorSize + growBy;

    tempArray = new DataType[newCapacity];
    
    for (index = 0; index < vectorSize; index++) // Size not capacity only copy written datay
    {
        tempArray[index] = vectorData[index];
    }

    vectorSize += growBy;

    delete[] vectorData;
    vectorData = tempArray;
}


// allows vector to shrink by given quantity
// allows vector to be shrunk to zero,
//   but throws logic_error if attempt to shrink to less than zero
//void shrink(int shrinkBy) throw (logic_error);
/******************************************************************************
Function Specifications: shrink
===============================================================================
Preconditions:
-
Postconditions:
-
Algorithm:
-
Exceptional/Error Conditions:
-
*/
template <class DataType>
void SimpleVector<DataType>::shrink(int shrinkBy) throw (logic_error)
{
    DataType *shrunkenVector;
    vectorCapacity -= shrinkBy;
    int index = 0;    

    if (shrinkBy > vectorCapacity)
    {
        throw logic_error("Cannot shrink into negatives");
    }
    else if (vectorSize > vectorCapacity)
    {
        vectorSize = vectorCapacity;
    }
   
    shrunkenVector = new DataType[vectorCapacity];

    for (index = 0; index < vectorCapacity; index++)
    {
        shrunkenVector[index] = vectorData[index];   
    }

    delete[] vectorData;
    vectorData = shrunkenVector;    
}

// increment/decrement don't affect class
//    but allow programmer to keep track of size inside vector
/******************************************************************************
Function Specifications: SimpleVector
===============================================================================
Preconditions:
-
Postconditions:
-
Algorithm:
-
Exceptional/Error Conditions:
-
*/
template <class DataType>
void SimpleVector<DataType>::incrementSize()
{
    if (vectorSize < vectorCapacity)
    {
        vectorSize++;
    }
}

/******************************************************************************
Function Specifications: SimpleVector
===============================================================================
Preconditions:
-
Postconditions:
-
Algorithm:
-
Exceptional/Error Conditions:
-
*/
template <class DataType>
void SimpleVector<DataType>::decrementSize()
{
    if (vectorSize < 0)
    {
        vectorSize--;
    }
}

// Private
//void copyVector(DataType *dest, DataType *src);
/******************************************************************************
Function Specifications: SimpleVector
===============================================================================
Preconditions:
-
Postconditions:
-
Algorithm:
-
Exceptional/Error Conditions:
-
*/
template <class DataType>
void SimpleVector<DataType>::copyVector(DataType *dest, DataType *src)
{
    
}

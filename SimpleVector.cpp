#include "SimpleVector.h"
#include <stdexcept>
#include <iostream>

using namespace std;

// constructors

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
SimpleVector<DataType>::SimpleVector()
{
    vectorCapacity = 0;
    vectorSize = 0;
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
SimpleVector<DataType>::SimpleVector(int newCapacity)
{
    // make sure > 0;
    vectorCapacity = newCapacity;
    vectorData = new DataType[vectorCapacity];
    vectorSize = 0;
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
SimpleVector<DataType>::SimpleVector(int newCapacity, const DataType &fillValue)
{
    vectorCapacity = newCapacity;
    vectorSize = newCapacity;
    vectorData = new DataType[vectorCapacity];
    for (int i = 0; i < vectorCapacity; i++)
    {
        vectorData[i] = fillValue;
        //cout << "@vectorData[" << i << "] = " << vectorData[i] << endl;
    }
}

///// COPY CONSTRUCTOR
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
SimpleVector<DataType>::SimpleVector(const SimpleVector &copiedVector)
{

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
    cout << "in getSize() " << vectorSize << endl;
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
#if 0
    if (index < 0 || index > (vectorSize-1))
    {
        //throw logic_error(vectorData[index]);
        throw logic_error("ERROR DUDE");
    }
#endif
    cout << "operator[" << index << "] (not const) " << vectorData[index] << endl;

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
    cout << "hello world CONST" << endl;
    if (index < 0 || index >(vectorSize - 1))
    {
        throw logic_error("Error!! out of bounds");
    }

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

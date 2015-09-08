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
    vectorCapacity = 10;
    vectorSize = 0;
    vectorData = new DataType[DEFAULT_CAPACITY];
    //cout << " Default constructor "  << endl;
    //cout << " The capacity isXXX: " << vectorCapacity << endl;
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
    //cout << " new capacity constructor " << endl;
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
    //cout << " new capacity and fill with data constructyor " << endl;
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

    if (vectorSize > vectorCapacity)
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

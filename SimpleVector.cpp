#include "SimpleVector.h"


// constructors
template <class DataType>
SimpleVector<DataType>::SimpleVector()
{
}

template <class DataType>
SimpleVector<DataType>::SimpleVector(int newCapacity)
{
}

template <class DataType>
SimpleVector<DataType>::SimpleVector(int newCapacity, const DataType &fillValue)
{
}

template <class DataType>
SimpleVector<DataType>::SimpleVector(const SimpleVector &copiedVector)
{
}

// destructor
template <class DataType>
SimpleVector<DataType>::~SimpleVector()
{
}



// assignment
template <class DataType>
const SimpleVector<DataType>& SimpleVector<DataType>::operator=(const SimpleVector &rhVector)
{
}


// accessors
template <class DataType>
int SimpleVector<class DataType>::getCapacity() const
{

}

template <class DataType>
int SimpleVector<class DataType>::getSize() const
{

}




// index access
template <class DataType>
DataType& SimpleVector<DataType>::operator[](int index) throw (logic_error)
{

}

template <class DataType>
const DataType& SimpleVector<DataType>::operator[](int index) const throw (logic_error)
{

}



// modifiers
// allows vector to grow by given quantity
template <class DataType>
void SimpleVector<DataType>::grow(int growBy)
{

}


// allows vector to shrink by given quantity
// allows vector to be shrunk to zero,
//   but throws logic_error if attempt to shrink to less than zero
//void shrink(int shrinkBy) throw (logic_error);
template <class DataType>
void SimpleVector<DataType>::shrink(int shrinkBy) throw (logic_error)
{

}



// increment/decrement don't affect class
//    but allow programmer to keep track of size inside vector
template <class DataType>
void SimpleVector<DataType>::incrementSize()
{

}

template <class DataType>
void SimpleVector<DataType>::decrementSize()
{

}




// Private
//void copyVector(DataType *dest, DataType *src);
template <class DataType>
void SimpleVector::copyVector(DataType *dest, DataType *src)
{

}


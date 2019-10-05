//********************************************************************************
// Pointers.h
//
// (C) 2019 TerseWorks. All rights reserved.
// TerseWorks Public Code License (https://www.terseworks.com/licensing).
//
// Written by: John Meschke
// Description: Smart pointer implementation.
//********************************************************************************

#ifndef INCLUDE_POINTERS
#define INCLUDE_POINTERS

#include <cstdlib>

//********************************************************************************
// ScopedPointer
//********************************************************************************

template<typename typeA>
class ScopedPointer
{
	public:
		ScopedPointer();
		ScopedPointer(typeA *newMemory);
		~ScopedPointer();
		typeA &operator*() const;
		typeA *operator->() const;
		typeA *get() const;
		typeA *release();
		void reset(typeA *newMemory);
		void swap(ScopedPointer<typeA> &scopedPointer);

	private:
		typeA *memory;

		ScopedPointer(const ScopedPointer &scopedPointer);
		ScopedPointer &operator=(const ScopedPointer &rhs);
};

/*
ScopedPointer constructor.
*/
template<typename typeA>
ScopedPointer<typeA>::ScopedPointer() : memory(0)
{
}

/*
ScopedPointer constructor.
*/
template<typename typeA>
ScopedPointer<typeA>::ScopedPointer(typeA *newMemory) : memory(newMemory)
{
}

/*
ScopedPointer destructor.
*/
template<typename typeA>
ScopedPointer<typeA>::~ScopedPointer()
{
	delete memory;
}

/*
ScopedPointer * operator.
*/
template<typename typeA>
typeA &ScopedPointer<typeA>::operator*() const
{
	return *memory;
}

/*
ScopedPointer -> operator.
*/
template<typename typeA>
typeA *ScopedPointer<typeA>::operator->() const
{
	return memory;
}

/*
Return a raw pointer to the memory.
*/
template<typename typeA>
typeA *ScopedPointer<typeA>::get() const
{
	return memory;
}

/*
Releases ownership of the memory to a raw pointer.
Object no longer is responsible for memory deletion.
*/
template<typename typeA>
typeA *ScopedPointer<typeA>::release()
{
	typeA *temp = memory;
	memory = 0;

	return temp;
}

/*
Clear the existing memory and reassign to new memory.
Can also be used to nullify a pointer.
*/
template<typename typeA>
void ScopedPointer<typeA>::reset(typeA *newMemory)
{
	if (memory != newMemory)
	{
		delete memory;
		memory = newMemory;
	}
}

/*
Swap the contents and ownership of the memory.
*/
template<typename typeA>
void ScopedPointer<typeA>::swap(ScopedPointer<typeA> &scopedPointer)
{
	typeA *temp = memory;
	memory = scopedPointer.memory;
	scopedPointer.memory = temp;
}

//********************************************************************************
// ScopedArray
//********************************************************************************

template<typename typeA>
class ScopedArray
{
	public:
		ScopedArray();
		ScopedArray(typeA *newMemory);
		~ScopedArray();
		typeA &operator[](size_t index) const;
		typeA *get() const;
		typeA *release();
		void reset(typeA *newMemory);
		void swap(ScopedArray<typeA> &scopedArray);

	private:
		typeA *memory;

		ScopedArray(const ScopedArray &scopedArray);
		ScopedArray &operator=(const ScopedArray &rhs);
};

/*
ScopedArray constructor.
*/
template<typename typeA>
ScopedArray<typeA>::ScopedArray() : memory(0)
{
}

/*
ScopedArray constructor.
*/
template<typename typeA>
ScopedArray<typeA>::ScopedArray(typeA *newMemory) : memory(newMemory)
{
}

/*
ScopedArray destructor.
*/
template<typename typeA>
ScopedArray<typeA>::~ScopedArray()
{
	delete[] memory;
}

/*
ScopedArray [] operator.
*/
template<typename typeA>
typeA &ScopedArray<typeA>::operator[](size_t index) const
{
	return memory[index];
}

/*
Return a raw pointer to the memory.
*/
template<typename typeA>
typeA *ScopedArray<typeA>::get() const
{
	return memory;
}

/*
Releases ownership of the memory to a raw pointer.
Object no longer is responsible for memory deletion.
*/
template<typename typeA>
typeA *ScopedArray<typeA>::release()
{
	typeA *temp = memory;
	memory = 0;

	return temp;
}

/*
Clear the existing memory and reassign to new memory.
Can also be used to nullify a pointer.
*/
template<typename typeA>
void ScopedArray<typeA>::reset(typeA *newMemory)
{
	if (memory != newMemory)
	{
		delete[] memory;
		memory = newMemory;
	}
}

/*
Swap the contents and ownership of the memory.
*/
template<typename typeA>
void ScopedArray<typeA>::swap(ScopedArray<typeA> &scopedArray)
{
	typeA *temp = memory;
	memory = scopedArray.memory;
	scopedArray.memory = temp;
}

#endif
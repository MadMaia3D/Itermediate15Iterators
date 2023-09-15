#include "MySexyVector.h"
#include <assert.h>
#include <iostream>

MySexyVector::~MySexyVector()
{
	delete[] container;
	container = nullptr;
}

// operators

int MySexyVector::operator[](int pos) const
{
	assert(pos < currentSize);
	return container[pos];
}

// capacity

bool MySexyVector::empty() const
{
	return currentSize == 0;
}

int MySexyVector::size() const
{
	return currentSize;
}

void MySexyVector::reserve(int new_cap)
{
	std::cout << "\nTrying to reallocate" << std::endl;
	if (new_cap <= currentCapacity) {
		std::cout << "Reallocation not completed" << std::endl;
		return;
	}
	reallocate(new_cap);
}

int MySexyVector::capacity() const
{
	return currentCapacity;
}

void MySexyVector::shrink_to_fit()
{
	reallocate(currentSize);
}

void MySexyVector::clear()
{
	currentSize = 0;
}

void MySexyVector::push_back(int value)
{
	if (currentCapacity == 0) {
		reallocate(1);
	}
	else if (currentSize == currentCapacity) {
		reallocate(currentCapacity * 2);
	}
	std::cout << "Pushing back " << value << std::endl;
	container[currentSize] = value;
	currentSize++;
}

void MySexyVector::pop_back()
{
	assert(currentSize > 0);
	currentSize -= 1;
}

void MySexyVector::reallocate(int new_cap)
{
	std::cout << "Reallocation Started" << std::endl;
	assert(new_cap >= 0);
	int* newContainer = new int[new_cap];
	for (int i = 0; (i < currentCapacity) && (i < new_cap); i++) {
		newContainer[i] = container[i];
	}
	delete[] container;
	container = newContainer;
	currentCapacity = new_cap;

	std::cout << "Reallocation Complete" << std::endl;
	std::cout << "New Size: " << size() << "\tNew Capacity: " << capacity() << "\n" << std::endl;
}

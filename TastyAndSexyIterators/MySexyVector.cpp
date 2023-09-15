#include "MySexyVector.h"
#include <assert.h>

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

int MySexyVector::capacity() const
{
	return currentCapacity;
}

void MySexyVector::push_back(int value)
{
	if (currentCapacity == 0) {
		delete[] container;
		container = new int[1];
		currentCapacity = 1;
	}
	else if (currentSize == currentCapacity) {
		const int newCapacity = currentCapacity * 2;
		int* newContainer = new int[newCapacity];
		for (int i = 0; i < currentCapacity; i++) {
			newContainer[i] = container[i];
		}
		delete[] container;
		container = newContainer;
		currentCapacity = newCapacity;
	}

	container[currentSize] = value;
	currentSize++;
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

#include <iostream>
#include "MySexyVector.h"
#include <vector>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

template <typename IterableContainer>
int SumMyNumbers(IterableContainer container) {
	IterableContainer::value_type sum = 0;
	for (IterableContainer::iterator iterator = container.begin(), end = container.end(); iterator != end; ++iterator) {
		sum += *iterator;
	}
	return sum;
}

int main()
{
	{
		MySexyVector my_vec;
		std::vector<int> standardVec;

		for (int i = 0; i < 100; i++) {
			my_vec.push_back(i+1);
			standardVec.push_back(i + 1);
		}
		
		std::cout << SumMyNumbers(my_vec) << std::endl;
		std::cout << SumMyNumbers(standardVec) << std::endl;

	}
	std::cin.get();

	_CrtDumpMemoryLeaks();
	return 0;
}
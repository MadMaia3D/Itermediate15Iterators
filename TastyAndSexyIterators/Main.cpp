#include <iostream>
#include "MySexyVector.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
	{
		MySexyVector vec;

		std::cout << "Capacity: " << vec.capacity() << "\t Size: " << vec.size() << std::endl;
		for (int i = 0; i < 100; i++) {
			vec.push_back(i);
			std::cout << "Capacity: " << vec.capacity() << "\t Size: " << vec.size() << std::endl;
		}

		for (int i = 0; i < 100; i++) {
			std::cout << vec[i]<< " - ";
		}

	}
	std::cin.get();

	_CrtDumpMemoryLeaks();
	return 0;
}
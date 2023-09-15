#include <iostream>
#include "MySexyVector.h"

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
	MySexyVector vec;
	
	std::cout << "Capacity: " << vec.capacity() << "\t Size: " << vec.size() << std::endl;
	vec.push_back(1);
	//for (int i = 0; i < 100; i++) {
	//	vec.push_back(i);
	//	std::cout << "Capacity: " << vec.capacity() << "\t Size: " << vec.size() << std::endl;
	//}

	std::cin.get();

	_CrtDumpMemoryLeaks();
	return 0;
}
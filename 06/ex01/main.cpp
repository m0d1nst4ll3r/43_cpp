#include "Serialize.hpp"
#include "Data.hpp"
#include <iostream>
#include <string>
#include <stdint.h>

int	main()
{
	Data		*data = new Data();
	Data		*copy;
	uintptr_t	addr;

	data->str = "Mrglrglrglgl";
	std::cout << "Addr of data as ptr:  " << data << "\n";
	addr = Serialize::serialize(data);
	std::cout << "Addr of data as uint: " << addr << "\n";
	copy = Serialize::deserialize(addr);
	std::cout << "Back to ptr:          " << copy << "\n";
	std::cout << "Data contents:        " << copy->str << "\n";

	delete data;
	return 0;
}

#include "Serialize.hpp"
#include "Data.hpp"
#include <iostream>
#include <string>
#include <stdint.h>

int	main()
{
	Data		*data = new Data();
	uintptr_t	addr;

	data->str = "Mrgrblrglrbglr";
	std::cout << "Addr of data as ptr:  " << data << "\n";
	addr = Serialize::serialize(data);
	std::cout << "Addr of data as uint: " << addr << "\n";
	std::cout << "Back to ptr:          " << Serialize::deserialize(addr) << "\n";
	delete data;
	return 0;
}
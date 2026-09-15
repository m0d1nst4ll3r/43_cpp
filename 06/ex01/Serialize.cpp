#include "Serialize.hpp"
#include "Data.hpp"
#include <stdint.h>

uintptr_t Serialize::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serialize::deserialize(uintptr_t ptr)
{
	return reinterpret_cast<Data*>(ptr);
}
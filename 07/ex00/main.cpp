#include "whatever.hpp"
#include <iostream>

int	main()
{
	int	a = 2, b = 5;
	double da = 2, db = 5;
	std::cout << "Before, a[" << a << "], b[" << b << "], da[" << da << "], db[" << db << "]\n";
	swap(a, b);
	swap(da, db);
	std::cout << "After, a[" << a << "], b[" << b << "], da[" << da << "], db[" << db << "]\n";
	std::cout << "Min a/b: " << min(a,b) << " - Min da/db: " << min(da,db) << "\n";
	std::cout << "Max a/b: " << max(a,b) << " - Max da/db: " << max(da,db) << "\n";
	return 0;
}
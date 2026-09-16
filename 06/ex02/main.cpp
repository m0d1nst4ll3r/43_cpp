#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#include <ctime>

namespace
{
	Base *generate()
	{
		Base *newBase;
		static bool	seeded = false;
		if (!seeded)
		{ // Combining tv_usec and std::clock for more randomness (this is overkill)
			struct timeval	tv;
			gettimeofday(&tv, NULL);
			srand(static_cast<unsigned int>(tv.tv_usec) ^ static_cast<unsigned int>(std::clock()));
			seeded = true;
		}
		int rng = rand();
		if (rng % 3 == 0)
			newBase = new A;
		else if (rng % 3 == 1)
			newBase = new B;
		else
			newBase = new C;
		return newBase;
	}

	void identify(Base *p)
	{
		if (dynamic_cast<A*>(p))
			std::cout << "Object is of type A.\n";
		if (dynamic_cast<B*>(p))
			std::cout << "Object is of type B.\n";
		if (dynamic_cast<C*>(p))
			std::cout << "Object is of type C.\n";
	}

	void identify(Base &p)
	{
		if (dynamic_cast<A*>(&p))
			std::cout << "Object is of type A.\n";
		if (dynamic_cast<B*>(&p))
			std::cout << "Object is of type B.\n";
		if (dynamic_cast<C*>(&p))
			std::cout << "Object is of type C.\n";
		(void)p;
	}
}

int	main()
{
	Base *unknown;

	unknown = generate();
	identify(unknown);
	identify(*unknown);
	return 0;
}

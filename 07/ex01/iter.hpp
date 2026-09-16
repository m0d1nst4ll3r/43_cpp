#ifndef ITER_HPP
#define ITER_HPP

template<typename T, typename F> void iter(T *arr, const int len, F func)
{
	for (int i = 0; i < len; ++i)
	{
		func(arr[i]);
	}
}

#endif /* ITER_HPP */
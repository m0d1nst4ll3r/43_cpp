#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template<typename T>class Array
{
	public:

	Array(unsigned int size = 0) : _size(size)
	{
		_arr = 0;
		if (_size)
			_arr = new T[_size]();
	}

	~Array()
	{
		if (_arr)
			delete[] _arr;
	}

	Array(const Array& toCopy) : _size(toCopy._size)
	{
		_arr = 0;
		if (_size)
			_arr = new T[_size]();
		for (unsigned int i = 0; i < _size; ++i)
			_arr[i] = toCopy._arr[i];
	}

	Array& operator=( const Array& op )
	{
		if (this != &op)
		{
			if (_arr)
				delete[] _arr;
			_size = op._size;
			if (_size)
				_arr = new T[_size]();
			for (unsigned int i = 0; i < _size; ++i)
				_arr[i] = op._arr[i];
		}
		return *this;
	}

	unsigned int size() const
	{
		return _size;
	}

	T operator[](unsigned int i) const
	{
		if (i >= _size)
			throw std::runtime_error("invalid index");
		return _arr[i];
	}

    T& operator[](unsigned int i)
	{
		if (i >= _size)
			throw std::runtime_error("invalid index");
		return _arr[i];
	}

	private:
	T*				_arr;
	unsigned int	_size;
};

#endif /* ARRAY_HPP */
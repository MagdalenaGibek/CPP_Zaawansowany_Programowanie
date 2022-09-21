#pragma once
#include <memory>
template <typename T>
class CircularBuffer
{
public:
	CircularBuffer(int size)
		: buffer(std::unique_ptr<T[]>(new T[_capacity])),
		_capacity(size)
	{
	}
	int capacity()
	{
		return _capacity;
	}
	int size()
	{
		return _size;
	}
	void push_back(T value)
	{
		buffer[tail] = value;
		tail = (tail + 1) % _capacity;
		if (_size < _capacity)
		{
			++_size;
		}
	}
	T pop_back()
	{
		T element = buffer[tail - 1];
		if (_size == 0)
		{
			std::cout << "Bufor jest pusty." << std::endl;
			return -1;
		}
		else if (tail == 0)
		{
			tail = _capacity;
		}
		else
		{
			tail = (tail - 1) % _capacity;
		}
		--_size;
		return element;
	}
	T pop_front()
	{
		if (_size == 0)
		{
			std::cout << "Bufor jest pusty." << std::endl;
			return -1;
		}
		T element = buffer[head];
		head = (head + 1) % _capacity;

		--_size;
		return element;
	}

	T& operator[](int index)
	{
		return buffer[index];
	}

	T front()
	{
		return buffer[head];
	}

	T back()
	{
		return buffer[tail - 1];
	}

	T resize(int newCapacity)
	{
		std::unique_ptr<T[]> increasedBuffer(new T[newCapacity]);

		for (size_t i = 0; i < _size; ++i)
		{
			increasedBuffer[i] = buffer[i];
		}
		_capacity = newCapacity;
		return _capacity;
	}

	void insert(int pos, T value)
	{
		if (size() == capacity())
		{
			resize(_capacity * 2);
		}
		if (head < tail)
		{
			for (size_t i = tail; i > (head + pos); --i)
			{
				buffer[i] = buffer[i - 1];
			}
			buffer[head + pos] = value;
		}
		else if (head > tail)
		{
			int counter = _size - pos;
			int tmp = tail;
			for (size_t i = 0; i < counter; ++i)
			{
				if (tmp == 0)
				{
					buffer[tmp] = buffer[_capacity];
					tmp = _capacity;
				}
				else
				{
					buffer[tmp] = buffer[tmp - 1];
					--tmp;
				}
			}

			/*++tail;
			if (tail >= _capacity)
			{
				tail = 0;
			}*/
			tail = (tail + 1) % _capacity;

			buffer[head + pos] = value;
		}

		_size++;
	}


private:
	int _capacity;
	std::unique_ptr<T[]> buffer;
	int head = 0;
	int tail = 0;
	int _size = 0;
};
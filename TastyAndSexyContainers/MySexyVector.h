#pragma once

class MySexyVector {

public:
	class my_sexy_iterator {
	public:
		my_sexy_iterator(int* ptr)
			:
			ptr(ptr)
		{ }

		my_sexy_iterator& operator++()
		{
			ptr++;
			return *this;
		}
		my_sexy_iterator operator++(int)
		{
			my_sexy_iterator copy = *this;
			ptr++;
			return copy;
		}

		my_sexy_iterator& operator--()
		{
			ptr--;
			return *this;
		}
		my_sexy_iterator operator--(int)
		{
			my_sexy_iterator copy = *this;
			ptr--;
			return copy;
		}

		my_sexy_iterator& operator+=(int value) {
			for (int i = 0; i < value; i++) {
				ptr++;
			}
			return *this;
		}

		my_sexy_iterator& operator-=(int value)
		{
			for (int i = 0; i < value; i++) {
				ptr--;
			}
			return *this;
		}

		int operator*() const
		{
			return *ptr;
		}
		bool operator==(const my_sexy_iterator& other) const
		{
			return ptr == other.ptr;
		}
		bool operator!=(const my_sexy_iterator& other) const
		{
			return !(*this == other);
		}
	private:
		int* ptr = nullptr;
	};
public:
	typedef int value_type;
	typedef my_sexy_iterator iterator;
public:
	MySexyVector() = default;
	MySexyVector(const MySexyVector& source);
	MySexyVector& operator=(const MySexyVector& source);
	~MySexyVector();
	// operators
	int& operator[](int pos);
	const int operator[](int pos) const;
	// capacity
	bool empty() const;
	int size() const;
	void reserve(int new_cap);
	int capacity() const;
	void shrink_to_fit();
	//modifiers
	void clear();
	void push_back(int value);
	void pop_back();
	//void resize(int count);
	// iterators functions
	my_sexy_iterator begin() const
	{
		return my_sexy_iterator(container);
	}
	my_sexy_iterator end() const
	{
		return my_sexy_iterator(container + currentSize);
	}

private:
	void reallocate(int new_cap);
private:
	int* container = nullptr;
	int currentSize = 0;
	int currentCapacity = 0;
};
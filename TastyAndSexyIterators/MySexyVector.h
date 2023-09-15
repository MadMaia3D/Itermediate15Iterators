#pragma once

class MySexyVector {
public:
	~MySexyVector();
	// operators
	int operator[](int pos) const;
	// capacity
	bool empty() const;
	int size() const;
	void reserve(int new_cap);
	int capacity() const;
	void shrink_to_fit();
	//modifiers
	void clear();
	void push_back(int value);
	int pop_back();
	void resize(int count);

private:
	void reallocate(int new_cap);
private:
	int* container = nullptr;
	int currentSize = 0;
	int currentCapacity = 0;
};
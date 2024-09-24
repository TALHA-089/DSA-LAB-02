#pragma once
template<class Type>

class Stack
{
private:

	int top;
	int maxSize;
	Type* stack;

public:

	Stack(int max);
	~Stack();
	bool isFull();
	bool isEmpty();
	void Push(Type item);
	void Pop(Type& item);
};
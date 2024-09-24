#include "Stack.h"
#include<iostream>

using namespace std;

template<class Type>
Stack<Type>::Stack(int max) {
	this->maxSize = max;
	top = -1;
	stack = new Type[maxSize];
}

template<class Type>
Stack<Type>::~Stack() {
	delete[] stack;
}

template<class Type>
bool Stack<Type>::isEmpty() {
	return (top == -1);
}

template<class Type>
bool Stack<Type>::isFull() {
	return (top == maxSize - 1);
}

template<class Type>
void Stack<Type>::Push(Type item) {
	if (isFull()) {
		cout << "\nStack Overflow!\n";
	}
	else {
		top++;
		stack[top] = item;
	}
}

template<class Type>
void Stack<Type>::Pop(Type& item) {
	if (isEmpty()) {
		cout << "\nStack Underflow!\n";
	}
	else {
		item = stack[top];
		top--;
	}
}
/* Generic Stack Class */


#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

template <class T>
class GenStack {
	public:
		GenStack();
		GenStack(int maxSize);
		~GenStack();

		void push(T data);
		T pop();
		T peek();

		bool isFull();
		bool isEmpty();
		void printStack();

		int top;
		int max;
		T* stack;
};

template <class T>
GenStack<T>::GenStack() {

};

template <class T>
GenStack<T>::GenStack(int maxSize) {
	stack = new T[maxSize];
	max = maxSize;
	top = -1;
}

template <class T>
GenStack<T>::~GenStack() {
	delete stack;
}

template <class T>
void GenStack<T>::push(T data) {
	//if the stakc is full, double size and copy old values
	if (top == max - 1) {
		T *tempStack = new T[max];

		for (int i = 0; i < max; ++i) {
			tempStack[i] = stack[i];
		}

		delete[] stack;
		stack = new T[max * 2];

		for (int i = 0; i < max; ++i) {
			stack[i] = tempStack[i];
		}

		delete[] tempStack;
		max *= 2;
	}

	//add new data to stack
	stack[++top] = data;
}

template <class T>
T GenStack<T>::pop() {
	if (top != -1) {
		return stack[top--];
	} else {
		return 0;
	}
}

template <class T>
T GenStack<T>::peek() {
	return stack[top];
}

//this should return bools??
template <class T>
bool GenStack<T>::isFull() {
	return (top == max-1);
}

//this should return bools??
template <class T>
bool GenStack<T>::isEmpty() {
	return (top == -1);
}

//needs to be tested more
template <class T>
void GenStack<T>::printStack() {
	for(int i = 0; i < max; ++i) {
		cout << stack[i] << endl;
	}
}

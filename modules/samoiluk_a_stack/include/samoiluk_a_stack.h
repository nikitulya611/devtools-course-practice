// Copyright 2022 Samoiluk Anastasiya

#ifndef MODULES_SAMOILUK_A_STACK_INCLUDE_SAMOILUK_A_STACK_H_
#define MODULES_SAMOILUK_A_STACK_INCLUDE_SAMOILUK_A_STACK_H_

#include <string>

template <class T>
class Stack {
    T* mem;
    int size;
    int index;
 public:
    explicit Stack(int _size = 100);
    Stack(const Stack& s);
    ~Stack();

    void push(T value);
    T pop();

    T getLast();
    T getSize();

    bool isEmpty();
    bool isFull();

    Stack& operator=(const Stack& s);
};

template <class T>
Stack<T>::Stack(int _size) : size(_size) {
    if (size < 0) throw "Negative stack size";
    index = -1;
    mem = new T[size];
}

template <class T>
Stack<T>::Stack(const Stack& s) {
    size = s.size;
    index = s.index;
    mem = new T[size];
    for (int j = 0; j < index + 1; j++)
        mem[j] = s.mem[j];
}

template <class T>
Stack<T>::~Stack() {
    if (mem != NULL)
        delete[] mem;
}

template <class T>
void Stack<T>::push(T value) {
    if (isFull()) throw "isFull";
    index++;
    mem[index] = value;
}

template <class T>
T Stack<T>::pop() {
    if (isEmpty()) throw "isEmpty";
    T value = mem[index];
    index--;
    return value;
}

template <class T>
T Stack<T>::getLast() { return mem[index]; }

template <class T>
T Stack<T>::getSize() { return size; }

template <class T>
bool Stack<T>::isEmpty() { return index < 0; }

template <class T>
bool Stack<T>::isFull() { return index >= size - 1; }

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& s) {
    if (&s == this) return *this;
    size = s.size;
    index = s.index;
    delete mem;
    mem = new T[size];
    for (int j = 0; j < index + 1; j++)
        mem[j] = s.mem[j];
    return *this;
}

#endif  // MODULES_SAMOILUK_A_STACK_INCLUDE_SAMOILUK_A_STACK_H_

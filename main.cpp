#include <iostream>
#include "dynamicArray.h"
#include "stack.h"
#include "array_stack.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Stack<int> *stack = new ArratStack<int>();
    stack->push(10);
    stack->push(11);
    stack->push(12);
    std::cout << stack->getSize() << std::endl;
    std::cout << *stack->pop()<< std::endl;;
    std::cout << stack->getSize() << std::endl;
    std::cout << *stack->pop()<< std::endl;;
    std::cout << stack->getSize() << std::endl;
    std::cout << *stack->pop()<< std::endl;;
    return 0;
}
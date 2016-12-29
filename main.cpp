#include <iostream>
#include "dynamicArray.h"
#include "stack.h"
#include "array_stack.h"
#include "ListBaseStack.h"

using namespace std;

class TestClas {
public:
    TestClas(int v) {
        this->value = v;
    }

    int value;
};

void testWithPrimiriveType(Stack<int> *stack) {
    cout << "size of empty stack :: " << stack->getSize() << endl;
    stack->push(1);
    cout << "size of stack after adding item " << stack->getSize() << endl;
    stack->push(1 + 1);
    cout << "size of stack after adding item " << stack->getSize() << endl;
    cout << "poped item :: " << *stack->pop() << endl;
    cout << "size stack after pop :: " << stack->getSize() << endl;
    cout << "poped item :: " << *stack->pop() << endl;
    cout << "size stack after pop :: " << stack->getSize() << endl;
}

void testWithClassType(Stack<TestClas> *stack) {
    cout << "size of empty stack :: " << stack->getSize() << endl;
    stack->push(TestClas(1));
    cout << "size of stack after adding item " << stack->getSize() << endl;
    stack->push(TestClas(1 + 1));
    cout << "size of stack after adding item " << stack->getSize() << endl;
    cout << "size of stack after adding item " << stack->getSize() << endl;
    cout << "poped item :: " << stack->pop()->value << endl;
    cout << "size stack after pop :: " << stack->getSize() << endl;
    cout << "poped item :: " << stack->pop()->value << endl;
    cout << "size stack after pop :: " << stack->getSize() << endl;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    cout << "_______________________________________________________________________" << endl;
    cout << "testing list base stack with primitive type " << endl;
    cout << "_______________________________________________________________________" << endl;
    ListBaseStack<int> *stackIntList = new ListBaseStack<int>();
    testWithPrimiriveType(stackIntList);
    delete stackIntList;
    cout << "_______________________________________________________________________" << endl;
    cout << "testing array base stack with primitive type " << endl;
    cout << "_______________________________________________________________________" << endl;
    ArrayStack<int> *stackIntArray = new ArrayStack<int>();
    testWithPrimiriveType(stackIntArray);
    delete stackIntArray;


    cout << "_______________________________________________________________________" << endl;
    cout << "testing list base stack with class type " << endl;
    cout << "_______________________________________________________________________" << endl;
    ListBaseStack<TestClas> *stackObjectList = new ListBaseStack<TestClas>();
    testWithClassType(stackObjectList);
    delete stackObjectList;
    cout << "_______________________________________________________________________" << endl;
    cout << "testing array base stack with class type " << endl;
    cout << "_______________________________________________________________________" << endl;
    ArrayStack<TestClas> *stackObjectArray = new ArrayStack<TestClas>();
    testWithClassType(stackObjectArray);
    delete stackObjectArray;
    return 0;
}
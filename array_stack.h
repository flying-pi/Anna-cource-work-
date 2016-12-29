//
// Created by Yura Braiko on 29.12.16.
//

#ifndef ANNCURSACH_ARRAY_STACK_H
#define ANNCURSACH_ARRAY_STACK_H

#include "stack.h"
#include "dynamicArray.h"

template<class T>
class ArrayStack :  protected DynamicArray<T> ,public Stack<T>{
public:
    ArrayStack() : DynamicArray<T>() {

    }

    virtual void push(T &item) override {
        this->addItem(item);
    }

    virtual void push(T &&item) override {
        this->addItem(item);
    }

    virtual T *pop() override {
        if (this->length == 0)
            return nullptr;
        T *result = this->getItem(this->length - 1);
        this->earse(this->length - 1);
        return result;
    }

    virtual int getSize() override {
        return this->getLength();
    }
};

#endif //ANNCURSACH_ARRAY_STACK_H

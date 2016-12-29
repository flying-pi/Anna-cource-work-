//
// Created by Yura Braiko on 29.12.16.
//

#ifndef ANNCURSACH_STACK_H
#define ANNCURSACH_STACK_H

template<class T>
class Stack {
public:
    virtual void push(T &item) = 0;
    virtual void push(T &&item) = 0;
    virtual T* pop() =0;
    virtual int getSize() = 0;
};

#endif //ANNCURSACH_STACK_H

//
// Created by Yura Braiko on 29.12.16.
//

#ifndef ANNCURSACH_LISTBASESTACK_H
#define ANNCURSACH_LISTBASESTACK_H


#include "stack.h"

template<class T>
class ListBaseStack : public Stack<T> {
public:
    ListBaseStack() {
        last = nullptr;
        size = 0;
    }

    ~ListBaseStack() {
        if (last != nullptr)
            delete last;
    }

    virtual void push(T &item) override {
        size++;
        if (last == nullptr) {
            last = new stackItem(&item);
            return;
        }
        stackItem *newItem = new stackItem(&item);
        newItem->next = last;
        last = newItem;
    }

    virtual void push(T &&item) override {
        size++;
        if (last == nullptr) {
            last = new stackItem(&item);
            return;
        }
        stackItem *newItem = new stackItem(&item);
        newItem->next = last;
        last = newItem;
    }

    virtual T *pop() override {
        if (last == nullptr)
            return nullptr;
        T *result = last->value;
        last = last->next;
        size--;
        return result;
    }

    virtual int getSize() override {
        return size ;
    }

private:
    struct stackItem {
        stackItem *next;
        T *value;

        stackItem(T *v) {
            value = v;
            next = nullptr;
        }

        ~stackItem() {
            if (value != nullptr)
                delete value;
        }
    };

    stackItem *last;
    int size;
};

#endif //ANNCURSACH_LISTBASESTACK_H

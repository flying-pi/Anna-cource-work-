//
// Created by Yura Braiko on 29.12.16.
//

#ifndef ANNCURSACH_DYNAMICARRAY_H
#define ANNCURSACH_DYNAMICARRAY_H

template<class T>
class DynamicArray {
public:
    DynamicArray() {
        freePosition = 10;
        length = 0;
        items = new T *[length];
        for (int i = 0; i < freePosition; i++)
            items[i] = nullptr;
    }

    virtual ~DynamicArray() {
        delete[]items;
    }

    /**
     * adding new item in array in free position
     * @param item  lvalue ref of item for adding
     * @return position of adding item
     */
    int addItem(T &item) {
        if (freePosition < length) smartIncrease();
        items[length] = &item;
        length++;
        return length - 1;
    }

    /**
     * adding new item in array in free position
     * @param item  rvalue ref of item for adding
     * @return position of adding item
     */
    int addItem(T &&item) {
        if (freePosition < length) smartIncrease();
        items[length] = &item;
        length++;
        return length - 1;
    }

    /**
     * insert new item in random position
     * @param pos position for inserting. If it negative function do nothing.
     * When it in range [0,length) replase item on given position
     * When it bigger than lenth size of array increace and element between old length and position of
     * new item will be zero.
     * @param item item  lvalue ref of item for adding
     */
    void insertItem(int pos, T &item) {
        if (pos >= freePosition) increase(pos + 1);
        items[pos] = &item;
        if (pos >= length)
            length = pos + 1;
    }

    /**
     * insert new item in random position
     * @param pos position for inserting. If it negative function do nothing.
     * When it in range [0,length) replase item on given position
     * When it bigger than lenth size of array increace and element between old length and position of
     * new item will be zero.
     * @item item item  evalue ref of item for adding
     */
    void insertItem(int pos, T &&item) {
        if (pos >= freePosition) increase(pos + 1);
        items[pos] = &item;
        if (pos >= length)
            length = pos + 1;
    }

    /**
     * remove all items
     */
    void clear() {
        for (int i = 0; i < length; i++)
            items[i] = nullptr;
        length = 0;
    }

    /**
     * getting item by position
     * @param position position
     * @return retun pointer for item of nullptr for empty item
     */
    T *getItem(int position) {
        return position >= length ? nullptr : items[position];

    }

    /**
     * remove item on given position. If position out of range no exception will not throw
     * all item above given position move for one position down
     * @param position
     */
    void removeItem(int position) {
        if (position >= length)
            return;
        for (int i = position; i < length - 1; i++) {
            items[i] = items[i + 1];
        }
        freePosition++;
        length--;
    }

    /**
     * replase item with given position with nullptr
     * @param position
     */
    void earse(int position){
        if (position >= length)
            return;
        items[position] = nullptr;
        if(position == length-1)
            length--;
    }

    /**
     *
     * @return count of nonull items
     */
    int getLength() {
        return length;
    }

protected:
    T **items;
    int freePosition;
    int length;

    void smartIncrease() {
        if (freePosition < 50) {
            increase(freePosition * 2);
            return;
        }
        if (freePosition < 100) {
            increase((int) (freePosition * 1.5f));
            return;
        }

        if (freePosition < 1000) {
            increase((int) (freePosition * 1.25f));
            return;
        }

        increase(freePosition + 500);
    }

    void increase(int newSize) {
        T **newArr = new T *[newSize];
        for (int i = 0; i < length; i++)
            newArr[i] = items[i];
        for (int i = length; i < newSize; i++)
            newArr[i] = nullptr;
        delete[] items;
        items = nullptr;
        items = newArr;
    }
};

#endif //ANNCURSACH_DYNAMICARRAY_H

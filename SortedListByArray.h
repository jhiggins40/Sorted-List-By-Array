#ifndef SORTEDLISTBYARRAY_H
#define SORTEDLISTBYARRAY_H

#include "ItemType.h"

const int MAX_ITEMS = 100;

class SortedList
{
private:
    ItemType items[MAX_ITEMS];
    int length;

public:
    SortedList();
    bool IsFull() const;
    int GetLength() const;
    void InsertItem(ItemType item);
    void GetItem(int index, ItemType& item) const;
    void MergeList(SortedList& listOne, SortedList& listTwo);
    void PrintList() const;
};

#endif

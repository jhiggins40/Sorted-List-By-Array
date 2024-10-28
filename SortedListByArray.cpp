#include "SortedListByArray.h"
#include <iostream>

SortedList::SortedList()
{
    length = 0;
}

bool SortedList::IsFull() const
{
    return length == MAX_ITEMS;
}

int SortedList::GetLength() const
{
    return length;
}

void SortedList::InsertItem(ItemType item)
{
    if (!IsFull()) {
        int i = 0;
        while (i < length && items[i].ComparedTo(item) == LESS) {
            i++;
        }

        for (int j = length; j > i; j--) {
            items[j] = items[j - 1];
        }

        items[i] = item;
        length++;
    }
}

void SortedList::GetItem(int index, ItemType& item) const
{
    if (index >= 0 && index < length) {
        item = items[index];
    }
}

void SortedList::MergeList(SortedList& listOne, SortedList& listTwo)
{
    length = 0;  // Reset the current list

    int i = 0, j = 0;

    // Merge the two lists while both have elements
    while (i < listOne.GetLength() && j < listTwo.GetLength()) {
        ItemType itemOne, itemTwo;
        listOne.GetItem(i, itemOne);
        listTwo.GetItem(j, itemTwo);

        if (itemOne.ComparedTo(itemTwo) != GREATER) {
            // Directly insert into the array at the current length
            items[length] = itemOne;
            i++;
        } else {
            items[length] = itemTwo;
            j++;
        }
        length++;
    }

    // Add the remaining items from listOne if any
    while (i < listOne.GetLength()) {
        ItemType itemOne;
        listOne.GetItem(i, itemOne);
        items[length] = itemOne;
        length++;
        i++;
    }

    // Add the remaining items from listTwo if any
    while (j < listTwo.GetLength()) {
        ItemType itemTwo;
        listTwo.GetItem(j, itemTwo);
        items[length] = itemTwo;
        length++;
        j++;
    }
}

void SortedList::PrintList() const
{
    for (int i = 0; i < length; i++) {
        items[i].Print();
    }
    std::cout << std::endl;
}

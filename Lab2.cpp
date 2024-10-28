#include <iostream>
#include "SortedListByArray.h"

void printList(const SortedList& list) {
    list.PrintList();
}

int main() {
    SortedList listOne;
    SortedList listTwo;

    ItemType item;
    
    item.Initialize('A');
    listOne.InsertItem(item);
    
    item.Initialize('B');
    listOne.InsertItem(item);
    
    item.Initialize('D');
    listOne.InsertItem(item);

    item.Initialize('C');
    listTwo.InsertItem(item);
    
    item.Initialize('E');
    listTwo.InsertItem(item);

    std::cout << "List One: ";
    printList(listOne);

    std::cout << "List Two: ";
    printList(listTwo);

    SortedList mergedList;
    mergedList.MergeList(listOne, listTwo);

    std::cout << "Merged List: ";
    printList(mergedList);

    return 0;
}

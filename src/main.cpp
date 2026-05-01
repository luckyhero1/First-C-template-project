#include <iostream>
#include "DoublyLinkedList.h"

int main()
{
    DL_List<int> l1;
    for(int i = 5; i > 0; i -= 1)
    {
        l1.push_front(i);
    }
    l1.print();

    for (int i = 5; i > 0; i -= 1)
    {
        l1.pop_front();
    }
    l1.print();

    DL_List<int> l2;
    for (int i = 0; i < 5; i += 1)
    {
        l2.push_back(i);
    }
    l2.print();

    for (int i = 0; i < 5; i += 1)
    {
        l2.pop_back();
    }
    l2.print();

    DL_List<int> l3;
    for (int i = 0; i < 5; i += 1)
    {
        l3.push_at_position(i, i);
    }
    l3.print();

    for (int i = 0; i < 5; i += 1)
    {
        l3.pop_at_position(0);
    }
    l3.print();
}
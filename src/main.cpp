#include <iostream>
#include <fstream>
#include <cstdlib>

#include "DoublyLinkedList.hpp"
#include "BubbleSort.hpp"
#include "LatexDocument.hpp"

/*
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

    DL_List<int> l4;
    for (int i = 0; i < 5; i += 1)
    {
        l4.push_at_position(i, rand() % 10);
    }
    l4.print();

    bubble_sort(l4);
    l4.print();

    for (int i = 0; i < 5; i += 1)
    {
        l4.pop_at_position(0);
    }
    l4.print();
}*/

int main() {
    std::ofstream file("output.tex");

    LatexDocument doc(file);
    
    DL_List<int> l4;
    for (int i = 0; i < 5; i += 1)
    {
        l4.push_at_position(i, rand() % 10);
    }

    bubble_sort(l4, file);

    for (int i = 0; i < 5; i += 1)
    {
        l4.pop_at_position(0);
    }

    std::ofstream file2("output_jamie.tex");

    LatexDocument doc2(file2);

    DL_List<int> l5;
    for (int i = 0; i < 15; i += 1)
    {
        l5.push_at_position(i, rand() % 10);
    }

    bubble_sort(l5, file2);
}
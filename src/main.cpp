#include <iostream>
#include <fstream>
#include <cstdlib>

#include "DoublyLinkedList.hpp"
#include "BubbleSort.hpp"
#include "LatexDocument.hpp"

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
    for (int i = 0; i < 20; i += 1)
    {
        l5.push_at_position(i, rand() % 10);
    }

    bubble_sort(l5, file2);
}
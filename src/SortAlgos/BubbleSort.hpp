#pragma once

#include <iostream>
#include <fstream>
#include <string>

/**
 * @brief
 * @param obj              : Object you want to sort (it needs a 'int size()'-function)
 * @param out              : Output stream you want to write the visualization into
 * @param pivot_element    : Number of the current element to sort
 * @param value            : Counter of function calls
 * @param was_sorted_flag  : This flag is 1, if the current compare results in a swap
 */
template<typename T>
void show_obj(T& obj, std::ostream& out, int pivot_element = 0, int value = 0, int was_sorted_flag = 0) {
    out << "\\begin{tikzpicture}[x=1cm, y=1cm]\n"
           "\\node[anchor = west] at (-0.6, 0.8) {Schritt: " << value + 1 << "};\n"
           "\n";

    int row = 0;
    for (int i = 0; i < obj.size(); i++)
    {
        if((i != 0) && (i % 17 == 0))   // For more than 16 elements in a row -> create new line
        {
            row -= 1;
        }

        std::string color;
        if (i == pivot_element) // Draws the current "bubble-element"/iterator
        {
            color = "red!60";
        }
        else if (i - 1 == pivot_element && was_sorted_flag == 0 && value != 0)  // Next element, that will be compared to current
        {
            color = "orange!60";
        }
        else if (i + 1 == pivot_element && was_sorted_flag == 1 && value != 0)  // Element, that was swapped
        {
            color = "green!60";
        }
        else
        {
            color = "{rgb,255:red,191; green,209; blue,255}";   // Default color for every other node
        }

        out << "\\node[draw, minimum width=0.8cm, minimum height=0.8cm, fill=" << color
            << "] at (" << i % 17 << "," << row << ") {" << obj[i]->value << "};\n";
    }

    out <<  "\n"
            "\\end{tikzpicture}\n"
            "\n";
}

/**
 * @brief
 * @param obj              : Object you want to sort (it needs a 'int size()'-function)
 * @param out              : Output stream you want to write the visualization into
 */
template<typename T>
void bubble_sort(T& obj, std::ofstream& out)
{
    show_obj<T>(obj, out);  // Default list visualization with the 0. element as pivot element
    
    int length = obj.size();
    int pivot_element = 0;
    int count = 0;

    // 
    for(int i = 1; i < length + 1; i += 1)
    {
        for(int j = 0; j < length - 1; j += 1)
        {
            pivot_element = j;
            count += 1;
            show_obj<T>(obj, out, pivot_element, count);    // Shows the compare

            if(obj[j]->value > obj[j + 1]->value)
            {
                pivot_element = j + 1;
                auto c = obj[j + 1]->value;
                obj[j + 1]->value = obj[j]->value;
                obj[j]->value = c;
                count += 1;
                show_obj<T>(obj, out, pivot_element, count, 1); // Shows the switch
            }
        }
    }
}
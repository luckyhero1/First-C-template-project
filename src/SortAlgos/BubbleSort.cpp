#include <iostream>
#include <fstream>
#include <cmath>

template<typename T>
void show_obj(T& obj, std::ostream& out, int pivot_element = 0, int value = 0, int was_sorted_flag = 0) {
    out << "\\begin{tikzpicture}\n"
            "\n";

    //int color = 127 * sin(0.15 * value - M_PI / 2) + 128;
    //int color = 40 * (M_PI / 2.0) * asin(sin((2 * value) - (0.5 * M_PI))) + 1;
    int color = ((sin(0.25 * value - 1.5) + 1) / 2.0) * 50.0;

    for (int i = 0; i < obj.size(); i++)
    {
        if(i == pivot_element)
        {
            out << "\\node at (" << i << ",0) [behind path, fill=red!40] {" << obj[i]->value << "};\n";
        }
        else if ((i - 1 == pivot_element) && (i != obj.size()) && (value != 0))
        {
            out << "\\node at (" << i << ",0) [behind path, fill=orange!60] {" << obj[i]->value << "};\n";
        }
        else if ((i + 1 == pivot_element) && (was_sorted_flag == 1) && (value != 0))
        {
            out << "\\node at (" << i << ",0) [behind path, fill=green!60] {" << obj[i]->value << "};\n";
        }
        else
        {
            out << "\\node at (" << i << ",0) [behind path, fill=blue!" << color << "] {" << obj[i]->value << "};\n";
        }
    }

    out <<  "\n"
            "\\end{tikzpicture}\n"
            "\n";
}

template<typename T>
void bubble_sort(T& obj, std::ofstream& out)
{
    show_obj<T>(obj, out);
    int length = obj.size();
    int pivot_element;
    int count = 0;

    for(int i = 1; i < length + 1; i += 1)
    {
        for(int j = 0; j < length - 1; j += 1)
        {
            pivot_element = j;
            count += 1;
            show_obj<T>(obj, out, pivot_element, count);

            if(obj[j]->value > obj[j + 1]->value)
            {
                pivot_element = j + 1;
                auto c = obj[j + 1]->value;
                obj[j + 1]->value = obj[j]->value;
                obj[j]->value = c;
                count += 1;
                show_obj<T>(obj, out, pivot_element, count, 1);
            }
        }
    }
}
#include <iostream>
#include <fstream>
#include <cmath>

int give_rgb(int value, int c0, int c1)
{
    // Diese Funktion soll zwischen den Werten im Spektrum pendeln.
    // c(x) = (1−t(x))*c0​ + t(x)*c1​ mit t(x) = (1−cos(((2*pi)/P) * x)​)/2 und c0 Startwert RGB und c1 Endwert

    double tx = (1 - cos(((2 * M_PI) / 20) * value)) / 2.0;
    return c0 * (1 - tx) + c1 * tx;
}

template<typename T>
void show_obj(T& obj, std::ostream& out, int pivot_element = 0, int value = 0, int was_sorted_flag = 0) {
    out << "\\begin{tikzpicture}\n"
            "\\node[anchor = west] at (0, 0.5) {Schritt: " << value + 1 << "};\n"
            "\\draw[step = 1, gray!10](0, -1) grid(" << obj.size() - 0.5 << ", 1);\n";

    // int color = ((sin(0.25 * value - 1.5) + 1) / 2.0) * 50.0;
    int rgb_red = give_rgb(value, 240, 100);
    int rgb_green = give_rgb(value, 245, 141);

    for (int i = 0; i < obj.size(); i++)
    {
        int column = i; // sollte +2 sein
        if(i == pivot_element)
        {
            out << "\\node at (" << column << ",0) [behind path, fill=red!40] {" << obj[i]->value << "};\n";
        }
        else if ((i - 1 == pivot_element) && (i != obj.size()) && (value != 0))
        {
            out << "\\node at (" << column << ",0) [behind path, fill=orange!60] {" << obj[i]->value << "};\n";
        }
        else if ((i + 1 == pivot_element) && (was_sorted_flag == 1) && (value != 0))
        {
            out << "\\node at (" << column << ",0) [behind path, fill=green!60] {" << obj[i]->value << "};\n";
        }
        else
        {
            out << "\\node at (" << column << ",0) [behind path, fill={rgb,255:red," << rgb_red << "; green," << rgb_green << "; blue,255}] {" << obj[i]->value << "};\n";
        }
    }

    out << "\n"
           "\\draw[gray!30] (1.5,-0.5) rectangle (" << 1.5 + obj.size() << ",0.5);\n"
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
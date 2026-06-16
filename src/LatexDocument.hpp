#pragma once

#include <iostream>

struct LatexDocument {
    std::ostream& out;

    LatexDocument(std::ostream& out)
        : out(out)
    {
        out << "\\documentclass{article}\n"
               "\\usepackage{tikz}\n"
               "\\usepackage{xcolor}"
               "\\usepackage[left=1.5cm, right=1.5cm, top=2.5cm, bottom=2.5cm]{geometry}\n"
               "\\begin{document}\n"
               "\n"
               "\\title{Visualisierung des BubbleSort-Algos}\n"
               "\\author{Michael Tomilin}\n"
               "\\maketitle\n"
               "\n";
    }

    ~LatexDocument() {
        out << "\\end{document}";
    }
};
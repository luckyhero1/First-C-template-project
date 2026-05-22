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
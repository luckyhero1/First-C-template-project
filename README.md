# Visualization of the sorting of a data structure using LaTeX

This application instantiates doubly-linked lists, stores random values ​​in them and sorts them using Bubble-Sort.
The steps of the sorting algorithm are then written to a TeX-file for each list.
The TeX-files are converted into PDF files.

## How to use:

### Prerequisites

You need CMake (version >= 3.20) and Latexmk (install a perl-environment if your TeX-distribution does not already have one).

### Using Visual Studio Code

Press F7 and let CMake select the correct compiler.

### Using Terminal

Use the following commands at the root of the directory.

```
cmake -B build -S .
cmake --build build
```

## How it's made:

**Resources:** C++ (Standardlibs), CMake, LaTeX

**Sources/Aids:** ...

Hier könnte Ihr Text stehen!

### DoublyLinkedList.hpp

Hier könnte Ihr Text stehen!

### BubbleSort.hpp

Hier könnte Ihr Text stehen!

### LatexDocument.hpp

The struct LatexDocument defines the format of the TeX-File. It saves an output stream, which will be written into the TeX-File. The sorting steps will be written into this LatexDocument. 

### main.cpp

This file serves as an interface. Here you can create lists und LatexDocuments and call the Bubble-Sort function.

## What did I learn:

Hier könnte Ihr Text stehen!
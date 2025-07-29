# Guide to Compiling and Running C++ Programs

This document explains how to compile and run C++ programs on Windows using the Command Prompt (CMD).

## Prerequisites

Before you can compile and run C++ programs, you need to have a C++ compiler installed. The most common options are:

1. **MinGW-w64**: A free and open-source compiler for Windows
2. **MSVC (Microsoft Visual C++)**: Part of Visual Studio
3. **Clang**: Another popular C++ compiler

In this guide, we'll focus on using g++ from MinGW-w64, which is already installed on your system (version 13.2.0).

## Compiling a C++ Program

To compile a C++ program using g++, follow these steps:

1. Open Command Prompt (CMD)
2. Navigate to the directory containing your .cpp file using the `cd` command:
   ```
   cd path\to\your\directory
   ```
3. Compile the program using g++:
   ```
   g++ -o ProgramName FileName.cpp
   ```
   - `-o ProgramName` specifies the name of the output executable
   - `FileName.cpp` is the name of your C++ source file

For example, to compile `DS_Program_1.cpp`:
```
g++ -o DS_Program_1 DS_Program_1.cpp
```

## Running a C++ Program

After compilation, you can run the program by typing its name in the command prompt:

```
.\ProgramName
```

For example, to run the compiled `DS_Program_1` program:
```
.\DS_Program_1
```

## Example: Linear Search Program

The `DS_Program_1.cpp` file contains a C++ program that demonstrates the linear search algorithm:

1. It asks the user to input the size of an array
2. It prompts the user to enter the elements of the array
3. It asks for an element to search for
4. It performs a linear search and displays whether the element was found and at which index

## Debugging and Error Handling

If your program doesn't compile, check for:
- Syntax errors
- Missing libraries
- Incorrect function calls

Common compilation flags:
- `-Wall`: Enable all warnings
- `-g`: Include debugging information
- `-std=c++11` (or newer): Specify the C++ standard to use

Example with debugging flags:
```
g++ -Wall -g -std=c++17 -o ProgramName FileName.cpp
```

## Additional Resources

- [C++ Reference](https://en.cppreference.com/w/)
- [MinGW-w64 Official Website](https://www.mingw-w64.org/)
- [Learn C++](https://www.learncpp.com/)

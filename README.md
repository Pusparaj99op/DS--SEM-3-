# 🚀 Guide to Compiling and Running C++ Programs

<div align="center">
  
  ![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
  ![MinGW](https://img.shields.io/badge/MinGW-4B32C3?style=for-the-badge&logo=windows&logoColor=white)
  ![CMD](https://img.shields.io/badge/Command_Prompt-4D4D4D?style=for-the-badge&logo=windows-terminal&logoColor=white)
  
  <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/cplusplus/cplusplus-original.svg" alt="C++" width="100" height="100"/>
  
  <p><i>A comprehensive guide to compiling and running C++ programs on Windows</i></p>
</div>

This document explains how to compile and run C++ programs on Windows using the Command Prompt (CMD). Follow the animated steps below for a smooth experience!

## 📋 Prerequisites

Before you can compile and run C++ programs, you need to have a C++ compiler installed. The most common options are:

1. **MinGW-w64**: A free and open-source compiler for Windows
2. **MSVC (Microsoft Visual C++)**: Part of Visual Studio
3. **Clang**: Another popular C++ compiler

In this guide, we'll focus on using g++ from MinGW-w64, which is already installed on your system (version 13.2.0).

<details>
<summary>🔽 How to install MinGW-w64 if you don't have it</summary>

1. Download the MinGW-w64 installer from the [official website](https://www.mingw-w64.org/downloads/).
2. Run the installer and follow the on-screen instructions.
3. Add the MinGW-w64 bin directory to your system PATH.
4. Verify installation by running `g++ --version` in Command Prompt.

</details>

## 💻 Compiling a C++ Program

<div align="center">
  <img src="https://media.giphy.com/media/13HgwGsXF0aiGY/giphy.gif" alt="Compiling" width="300"/>
</div>

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
```bash
g++ -o DS_Program_1 DS_Program_1.cpp
```

<div align="center">
  <img src="https://media.giphy.com/media/eCqFYAVjjDksg/giphy.gif" alt="Code" width="300"/>
</div>

## ▶️ Running a C++ Program

After compilation, you can run the program by typing its name in the command prompt:

```
.\ProgramName
```

For example, to run the compiled `DS_Program_1` program:
```bash
.\DS_Program_1
```

## 🔍 Example: Linear Search Program 

<div align="center">
  <img src="https://media.giphy.com/media/3o7buiv5wHoOjX29gY/giphy.gif" alt="Search" width="300"/>
</div>

The `DS_Program_1.cpp` file contains a C++ program that demonstrates the linear search algorithm:

1. It asks the user to input the size of an array
2. It prompts the user to enter the elements of the array
3. It asks for an element to search for
4. It performs a linear search and displays whether the element was found and at which index

<details>
<summary>👀 View Linear Search Algorithm Code Example</summary>

```cpp
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index if the element is found
        }
    }
    return -1; // Return -1 if the element is not found
}
```
</details>

## 🐞 Debugging and Error Handling

<div align="center">
  <img src="https://media.giphy.com/media/l0HlN5Y28D9MzzcRy/giphy.gif" alt="Debugging" width="300"/>
</div>

If your program doesn't compile, check for:
- Syntax errors
- Missing libraries
- Incorrect function calls

Common compilation flags:
- `-Wall`: Enable all warnings
- `-g`: Include debugging information
- `-std=c++11` (or newer): Specify the C++ standard to use

Example with debugging flags:
```bash
g++ -Wall -g -std=c++17 -o ProgramName FileName.cpp
```

## 📚 Additional Resources

<div align="center">

| Resource | Description |
|----------|-------------|
| [C++ Reference](https://en.cppreference.com/w/) | Comprehensive C++ documentation |
| [MinGW-w64](https://www.mingw-w64.org/) | Official MinGW-w64 website |
| [Learn C++](https://www.learncpp.com/) | Great tutorials for beginners and advanced users |

</div>

## 🌟 Contributing

Feel free to contribute to this guide by creating pull requests or opening issues!

<div align="center">
  <img src="https://media.giphy.com/media/kH0ohbodETc8JXlaob/giphy.gif" alt="Thanks" width="200"/>
  
  Made with ❤️ by [Pusparaj99op](https://github.com/Pusparaj99op)
</div>

---

<div align="center">
  <p>If you found this helpful, please give it a ⭐</p>
  <p>Happy Coding! 👨‍💻</p>
</div>

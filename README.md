# Introduction

In this optional assignment you should develop a C++ function that solves the following problem:

> Code a C++ function that receives an array of integers with `n` elements, examine the **first**, **last**, and  **middle** elements, find the median of these 3 elements and, if necessary, swap them so that the median value becomes the last element of the array. The order of the other two elements in the array is irrelevant BUT it is desirable that the highest of the remaining two elements comes before the smallest element.
> The function should not create a new array, rather it should only swap the three elements mentioned above.

In this repository you'll find the support code to test your solution.

## Examples

Here are a few examples to help you understand the problem you need to solve.

```
Input: [ 3 0 0 2 0 0 1]  --> Output: [ 1 0 0 3 0 0 2]
Input: [ 2 0 0 3 0 0 1]  --> Output: [ 1 0 0 3 0 0 2]
Input: [ 1 0 0 2 0 0 3]  --> Output: [ 1 0 0 3 0 0 2] 
```
Another acceptable output for these examples above is `[3 0 0 1 0 0 2]`, although the solution above is preferable.

Other examples with an **even** number of elements
```
Input: [ 3 0 0 2 0 1]  --> Output: [ 1 0 0 3 0 2]
Input: [ 2 0 0 3 0 1]  --> Output: [ 1 0 0 3 0 2]
Input: [ 1 0 0 2 0 3]  --> Output: [ 1 0 0 3 0 2] 
```

When `n` (length of the array) is an even number the _middle_ element is obtained by dividing the number of elements by two and adding the result to the first index (in these cases, zero). That is why in the examples above the middle element is located in `V[3]`.

# Organization

The folders and files of this project are the following:

- `src/median.cpp`: the source file where you should **code** your solution. This is the **only** file you need to run the tests.
- `src/median.h`: a header with the declaration of the median function.
- `src/CMakeLists.txt`: the `cmake` file of this folder (it only sets the C++ standard).
- `src/tests/`: This is the folder that contains the tests and the `TestManager` library. _You do not need to edit any file in this folder_.
- `CMakeLists.txt`: The main `cmake` script that builds the tests.
- `README.md`: This file.

# Compiling

This project may be compiled with [CMake](https://cmake.org). CMake is an open-source, cross-platform family of tools designed to build, test and package software. Basically, cmake reads a script (`CMakeLists.txt`) with meta-information on the project and **creates a Makefile automatically**, tailored to your system configuration.
After that, you may run the `make` command, as usual.
Alternatively, the same script might be used to create Xcode projects, Ninja, or Microsoft Visual Studio projects, for instance.

CMake supports **out-of-source** build. This means the _source code_ is stored in **one** folder and the _generated executable files_ should be stored in **another** folder: project should never mix-up the source tree with the build tree.
But don't worry, they are already set up in the `CMakeLists.txt` script.

In particular, this project creates two **targets**: the first is the `TextManager` library, and the second one it the executable file called `run_tests`. Note that only the second target is relevant for the testing process.


To compile this project with [cmake](https://cmake.org) follow these steps (from the root folder of the project):

1. `cmake -S . -B build`: this command asks `cmake` to create the build directory and generate an Unix Makefile based on the script found on the current level.
2. `cmake --build build`: triggers the compiling process that creates the targets (executable) inside `build`. As stated above, one target is the test library, the other is the test itself.

For further details, please refer to the [cmake documentation website](https://cmake.org/cmake/help/v3.14/manual/cmake.1.html).

## Compiling without cmake

If you wish to compile this project without the `cmake`, create the `build` folder manually (`mkdir build`), then try to run the command below from the source folder:

```
g++ -Wall -std=c++17 -I src/ -I tests/tm/ src/median.cpp tests/main.cpp tests/tm/tm.cpp -o build/run_tests
```

# Running

From the project's root folder, run as usual (assuming `$` is the terminal prompt):

```
$ ./build/run_tests
```

If everything went fine, the result of the command above might be:

```
[===========] Running 13 from the "Median of 3 Tests" test suite.
[ RUN       ] Median(1) -> Vetor com tamanho inferior a 3.
[        OK ]
[ RUN       ] Median(2) -> Odd -> Lo-Md-Hi
[      FAIL ] at line 34.
[ RUN       ] Median(3) -> Even -> Lo-Md-Hi
[        OK ]
[ RUN       ] Median(4) -> Odd -> Lo-Hi-Md
[        OK ]
[ RUN       ] Median(5) -> Even -> Lo-Hi-Md
[        OK ]
[ RUN       ] Median(6) -> Odd -> Md-Lo-Hi
[      FAIL ] at line 98.
[ RUN       ] Median(7) -> Even -> Md-Lo-Hi
[      FAIL ] at line 114.
[ RUN       ] Median(8) -> Odd -> Md-Hi-Lo
[      FAIL ] at line 130.
[ RUN       ] Median(9) -> Even -> Md-Hi-Lo
[      FAIL ] at line 146.
[ RUN       ] Median(10) -> Odd -> Hi-Md-Lo
[      FAIL ] at line 162.
[ RUN       ] Median(11) -> Even -> Hi-Md-Lo
[      FAIL ] at line 178.
[ RUN       ] Median(12) -> Odd -> Hi-Lo-Md
[        OK ]
[ RUN       ] Median(13) -> Even -> Hi-Lo-Md
[        OK ]
[===========] 13 tests from the "Median of 3 Tests" test suite ran.
[ PASSED    ] 6 tests.
[ FAILED    ] 7 tests.
```

Because the function `median_of_3()` has not been coded just yet, it fails most of the tests.
If you code the function correctly, all the tests should yield status OK.

# Authorship

Project created by Selan (<selan.santos@ufrn.br>), 2023.1

&copy; DIMAp/UFRN 2023.

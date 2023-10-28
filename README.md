# Sudoku
 Sudoku with CPP

There are two parts in this repo
1. Sudoku Map Transformation
2. Sudoku Map Solver

## Execute code
transformation: make run  
solve: make solve

## 1. Sudoku Map Transformation
Source: sudoku.cpp sudoku.h transform.cpp  

Aim: Generate an **equivalent** Sudoku Map with user key-in function  

Input: A 9x9 Sudoku Map  
![image](https://github.com/Study-boy-dot/Sudoku/assets/80616480/d9c82e1e-8f8f-4ee3-a157-cc3b83ffd4bf)  
There are 5 methods to transform a Sudoku Map in this code
1. Exchange two number in whole Sudoku Map

![image](https://github.com/Study-boy-dot/Sudoku/assets/80616480/a51ea227-d540-4819-b026-06d7284b9749)

2. Exchange two rows

![image](https://github.com/Study-boy-dot/Sudoku/assets/80616480/5c3834fc-59c2-4c63-b82b-6421feacf8f7)

3. Exchange two cols

![image](https://github.com/Study-boy-dot/Sudoku/assets/80616480/49878ff1-d017-402e-9dc6-ee10f9021a19)

4. Clockwise Rotate Sudoku Map 90 degree

![image](https://github.com/Study-boy-dot/Sudoku/assets/80616480/255965dd-e5e0-443f-831c-f2e0cef47799)

5. Mirror Inversion Sudoku Map(Horizontal, Vertical)

![image](https://github.com/Study-boy-dot/Sudoku/assets/80616480/20382d63-4074-4a00-9fdd-6dd2f56afbe1)

## 2. Sudoku Map Solver
There has a default grid inside code
Input: A 9x9 Sudoku Map, blank space fills with 0
![image](https://github.com/Study-boy-dot/Sudoku/assets/80616480/ac696118-5d97-4e89-9291-c2dadd5d9e45)

Method: Using recursive method to find the solution of given input.

Output: If there is a solution, output solution matrix else output `No solution exists.`
## Caveat
There is not any error handling mechanism. Input must in range

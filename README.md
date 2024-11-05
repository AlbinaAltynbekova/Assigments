# FillArrayTask
Lab01. FillArray Function 
#ifndef STD2DARRAYS_H
#define STD2DARRAYS_H

#include <array>
#include <stdexcept>

const int MAXNUMBEROFROWS = 100;
const int MAXNUMBEROFCOLUMNS = 100;

void fillArray(std::array<std::array<int, MAXNUMBEROFCOLUMNS>, MAXNUMBEROFROWS>& arr, int rows, int columns);
void printArray(const std::array<std::array<int, MAXNUMBEROFCOLUMNS>, MAXNUMBEROFROWS>& arr, int rows, int columns);

#endif
#include "Std2DArrays.h"
#include <stdexcept>

void fillArray(std::array<std::array<int, MAXNUMBEROFCOLUMNS>, MAXNUMBEROFROWS>& arr, int rows, int columns) {
    if (rows > MAXNUMBEROFROWS || columns > MAXNUMBEROFCOLUMNS) {
        throw std::invalid_argument("Incorrect number of rows or columns");
    }

    int value = 1;
    for (int startCol = columns - 1; startCol >= 0; --startCol) {
        int col = startCol;
        int row = 0;
        while (col < columns && row < rows) {
            arr[row][col] = value++;
            ++row;
            ++col;
        }
    }
    for (int startRow = 1; startRow < rows; ++startRow) {
        int col = 0;
        int row = startRow;
        while (col < columns && row < rows) {
            arr[row][col] = value++;
            ++row;
            ++col;
        }
    }
}

void printArray(const std::array<std::array<int, MAXNUMBEROFCOLUMNS>, MAXNUMBEROFROWS>& arr, int rows, int columns) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
#include "Std2DArrays.h"
#include <iostream>

int main() {
    std::array<std::array<int, MAXNUMBEROFCOLUMNS>, MAXNUMBEROFROWS> arr;
    int numberOfRows, numberOfColumns;

    std::cout << "Enter the number of rows: ";
    std::cin >> numberOfRows;
    std::cout << "Enter the number of columns: ";
    std::cin >> numberOfColumns;

    try {
        fillArray(arr, numberOfRows, numberOfColumns);
        printArray(arr, numberOfRows, numberOfColumns);
    } catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

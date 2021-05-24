#ifndef SORTING_H
#define SORTING_H

#include <iostream>
#include <chrono>
#include <fstream>
#include <random>
#include <ctime>
#include <stdlib.h>

using namespace std;
using namespace std::chrono;

class Sorting
{
  public:
    Sorting();
    ~Sorting();
    void BubbleSort(double* numbers, int numbersSize);
    void SelectionSort(double* numbers, int numbersSize);
    void InsertionSort(double* numbers, int numbersSize);
    void QuickSort(double* numbers, int low, int high);
    void MergeSort(double* numbers, int lo, int hi);
    void ShellSort(double* numbers, int numbersSize);
    void PrintArray(double* numbers, int numbersSize);

    void GenerateFile(int numbersSize, string fileName);
    void ReadFromFile(string fileName);

    void Swap(double* a, double* b);
    void Merge(double* numbers, int lo, int hi);
    int Partition(double* numbers, int low, int high);
    double generate(double min, double max);

  private:
    ifstream inFS;
    ofstream outFS;

    double* bubbleSortArray;
    double* insertionSortArray;
    double* selectionSortArray;
    double* shellSortArray;
    double* mergeSortArray;
    double* quickSortArray;

    string fileSentence;
};

#endif

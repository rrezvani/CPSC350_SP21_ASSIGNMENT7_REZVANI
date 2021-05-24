#include "Sorting.h"

Sorting::Sorting() {

}

Sorting::~Sorting() {

}

void Sorting::BubbleSort(double* numbers, int numbersSize) {
  for (int i = 0; i < numbersSize - 1; i++) {
    for (int j = 0; j < numbersSize - i - 1; j++) {
      if (numbers[j] > numbers[j+1]) {
        double temp = numbers[j];
        numbers[j] = numbers[j + 1];
        numbers[j+1] = temp;
      }
    }
  }
}

void Sorting::SelectionSort(double* numbers, int numbersSize) {
  for (int i = 0; i < numbersSize - 1; ++i) {
    int indexSmallest = i;
    for (int j = i + 1; j < numbersSize; ++j) {
      if (numbers[j] < numbers[indexSmallest]) {
        indexSmallest = j;
      }
    }

    double temp = numbers[i];
    numbers[i] = numbers[indexSmallest];
    numbers[indexSmallest] = temp;
  }
}


void Sorting::InsertionSort(double* numbers, int numbersSize) {
  for (int i = 0; i < numbersSize; ++i) {
    double temp = numbers[i];
    int j = i;
    while (j > 0 && numbers[j - 1] >= temp) {
      numbers[j] = numbers[j - 1];
      --j;
    }
    numbers[j] = temp;
  }
}

void Sorting::PrintArray(double* numbers, int numbersSize) {
  for (int i = 0; i < numbersSize; ++i) {
    cout << numbers[i] << " " << endl;
  }
}

int Sorting::Partition(double* numbers, int low, int high)
{
    double pivot = numbers[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (numbers[j] < pivot)
        {
            i++; // increment index of smaller element
            Swap(&numbers[i], &numbers[j]);
        }
    }
    Swap(&numbers[i + 1], &numbers[high]);
    return (i + 1);
}

void Sorting::Swap(double* a, double* b)
{
    double t = *a;
    *a = *b;
    *b = t;
}

void Sorting::QuickSort(double* numbers, int low, int high)
{
    if (low < high)
    {

        int pi = Partition(numbers, low, high);
        QuickSort(numbers, low, pi - 1);
        QuickSort(numbers, pi + 1, high);
    }
}

void Sorting::MergeSort(double* numbers, int lo, int hi) {
  if (lo < hi) {
    int middle = (lo + hi) / 2;
    MergeSort(numbers, lo, middle);
    MergeSort(numbers, middle+1, hi);
    Merge(numbers, lo, hi);
  }
}

void Sorting::Merge(double* numbers, int lo, int hi) {
  double* newArr = new double[hi - lo + 1];
  int middle  = (hi + lo)/2;
  int k = 0;
  int i;
  int j;
  for (i = lo; i <= middle; ++i) {
    newArr[k++] = numbers[i];
  }
  for (j = hi; j >= middle+1; --j) {
    newArr[k++] = numbers[j];
  }
  i = 0;
  k = lo;
  j = (hi - lo); //number of elements -1
  while (i <= j) {
    if (newArr[i] < newArr[j]) {
      numbers[k++] = newArr[i++];
    }
    else {
      numbers[k++] = newArr[j--];
    }
  }
}

void Sorting::ShellSort(double* numbers, int numbersSize) {
    for (int gap = numbersSize / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < numbersSize; i += 1)
        {
            double temp = numbers[i];
            int j;
            for (j = i; j >= gap && numbers[j - gap] > temp; j -= gap) {
              numbers[j] = numbers[j - gap];
            }
            numbers[j] = temp;
        }
    }
}

double Sorting::generate(double min, double max)
{
    static default_random_engine generator(unsigned(time(nullptr)));
    uniform_real_distribution<double> distribution(min, max);

    return distribution(generator);
}

void Sorting::GenerateFile(int numbersSize, string fileName)
{
  outFS.open(fileName);
  outFS << numbersSize << endl;
  for (int i = 0; i < numbersSize; ++i) {
    outFS << generate(0, 500000) << endl;
  }
  outFS.close();
}

void Sorting::ReadFromFile(string fileName) {
  inFS.open(fileName);

  getline(inFS, fileSentence);
  int size = stoi(fileSentence);

  bubbleSortArray = new double[size];
  insertionSortArray = new double[size];
  selectionSortArray = new double[size];
  shellSortArray = new double[size];
  quickSortArray = new double[size];
  mergeSortArray = new double[size];

  for (int i = 0; i < size; ++i) {
    getline(inFS, fileSentence);
    double temp = stod(fileSentence);
    bubbleSortArray[i] = temp;
    insertionSortArray[i] = temp;
    selectionSortArray[i] = temp;
    shellSortArray[i] = temp;
    quickSortArray[i] = temp;
    mergeSortArray[i] = temp;
  }

  auto start = high_resolution_clock::now();
  BubbleSort(bubbleSortArray, size);
  for (int i = 0; i < 5000000; ++i) {}
  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<microseconds>(stop - start);
  cout << "Bubble sort: " << duration.count() * 1e-6 << " seconds" << endl;

  start = high_resolution_clock::now();
  SelectionSort(selectionSortArray, size);
  for (int i = 0; i < 5000000; ++i) {}
  stop = chrono::high_resolution_clock::now();
  duration = chrono::duration_cast<microseconds>(stop - start);
  cout << "Selection sort: " << duration.count() * 1e-6 << " seconds" << endl;

  start = high_resolution_clock::now();
  InsertionSort(insertionSortArray, size);
  for (int i = 0; i < 5000000; ++i) {}
  stop = chrono::high_resolution_clock::now();
  duration = chrono::duration_cast<microseconds>(stop - start);
  cout << "Insertion sort: " << duration.count() * 1e-6 << " seconds" << endl;

  start = high_resolution_clock::now();
  ShellSort(shellSortArray, size);
  for (int i = 0; i < 5000000; ++i) {}
  stop = chrono::high_resolution_clock::now();
  duration = chrono::duration_cast<microseconds>(stop - start);
  cout << "Shell sort: " << duration.count() * 1e-6 << " seconds" << endl;

  start = high_resolution_clock::now();
  QuickSort(quickSortArray, 0, size - 1);
  for (int i = 0; i < 5000000; ++i) {}
  stop = chrono::high_resolution_clock::now();
  duration = chrono::duration_cast<microseconds>(stop - start);
  cout << "Quick sort: " << duration.count() * 1e-6 << " seconds" << endl;

  start = high_resolution_clock::now();
  MergeSort(mergeSortArray, 0, size - 1);
  for (int i = 0; i < 5000000; ++i) {}
  stop = chrono::high_resolution_clock::now();
  duration = chrono::duration_cast<microseconds>(stop - start);
  cout << "Merge sort: " << duration.count() * 1e-6 << " seconds" << endl;
}
  /*
  double* foo = new double[1000];
  double j = 1000.1;
  for (int i = 0; i < 1000; ++i) {
    foo[i] = j;
    j -= 1;
  }
  auto start = high_resolution_clock::now();
  ShellSort(foo, 1000);
  for (int i = 0; i < 500000000; ++i) {

  }
  auto stop = chrono::high_resolution_clock::now();
  PrintArray(foo, 1000);

  auto duration = chrono::duration_cast<microseconds>(stop - start);
  cout << "foobar: " << duration.count() * 1e-6 << " seconds" << endl; //g++ --std=c+11 Sorting.cpp
  */

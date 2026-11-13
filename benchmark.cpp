#include <iostream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include "Sorting.h"

using namespace std;
using namespace std::chrono;

bool compareIntegers(int a, int b)
{
    return a < b;
}
int main()
{

    srand(time(0));

    int sizes[] = {1000, 2000, 4000, 8000,
                   16000, 32000, 64000};

    cout << "SIZE\tINSERTION(ms)\tQUICK SORT(ms)\n";

    for (int n : sizes)
    {

        double insertionTotal = 0;
        double quickTotal = 0;

        int *original = new int[n];
        int *working = new int[n];

        for (int i = 0; i < n; i++)
        {
            original[i] = rand() % 100000;
        }

        // Three repetitions
        for (int repeat = 0; repeat < 3; repeat++)
        {

            for (int i = 0; i < n; i++)
                working[i] = original[i];

            auto start = high_resolution_clock::now();

            insertionSort(working, n, compareIntegers);

            auto stop = high_resolution_clock::now();

            insertionTotal += duration<double, milli>(
                                  stop - start)
                                  .count();

            for (int i = 0; i < n; i++)
                working[i] = original[i];

            start = high_resolution_clock::now();

            quickSort(working, 0, n - 1, compareIntegers);

            stop = high_resolution_clock::now();

            quickTotal += duration<double, milli>(
                              stop - start)
                              .count();
        }

        cout << n << "\t"
             << insertionTotal / 3 << "\t\t"
             << quickTotal / 3 << endl;

        delete[] original;
        delete[] working;
    }

    return 0;
}

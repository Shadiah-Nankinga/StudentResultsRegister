#ifndef SORTING_H
#define SORTING_H

#include <cstdlib>
#include <utility>

template <typename T, typename Comparator>
void insertionSort(T arr[], int n, Comparator comp)
{
    for (int i = 1; i < n; i++)
    {
        T key = arr[i];
        int j = i - 1;

        while (j >= 0 && comp(key, arr[j]))
        {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

template <typename T, typename Comparator>
int partition(T arr[], int low, int high, Comparator comp)
{

    int randomIndex = low + rand() % (high - low + 1);

    std::swap(arr[randomIndex], arr[high]);

    T pivot = arr[high];

    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (comp(arr[j], pivot))
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);

    return i + 1;
}

template <typename T, typename Comparator>
void quickSort(T arr[], int low, int high, Comparator comp)
{

    if (low < high)
    {
        int pivotIndex = partition(arr, low, high, comp);

        quickSort(arr, low, pivotIndex - 1, comp);
        quickSort(arr, pivotIndex + 1, high, comp);
    }
}
template <typename T, typename Comparator>
int binarySearch(T arr[], int n, const T &target, Comparator comp)
{

    int low = 0;
    int high = n - 1;

    while (low <= high)
    {

        int mid = low + (high - low) / 2;

        if (!comp(arr[mid], target) && !comp(target, arr[mid]))
        {
            return mid;
        }
        else if (comp(arr[mid], target))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}
#endif

#ifndef SORTER_H
#define SORTER_H


#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include "dinamicArray.h"

using namespace std;
template <typename T>
class ISorter {
public:
    virtual ~ISorter() = default;
    virtual DinamicArray<T>* Sort(DinamicArray<T>*, int (*cmp)(const T&, const T&)) = 0;
};

template <typename T>
class BubbleSorter : public ISorter<T> {
public:
    DinamicArray<T>* Sort(DinamicArray<T>* arr, int (*cmp)(const T&, const T&)) override {
        size_t n = arr->get_size();
        for (size_t i = 0; i < n - 1; ++i) {
            for (size_t j = 0; j < n - i - 1; ++j) {
                if (cmp(arr->GetData()[j], arr->GetData()[j + 1]) > 0) {
                    std::swap(arr->GetData()[j], arr->GetData()[j + 1]);
                }
            }
        }
        return arr;
    }
};


template <typename T>
class BinaryInsertionSorter : public ISorter<T> {
public:
    DinamicArray<T>* Sort(DinamicArray<T>* arr, int (*cmp)(const T&, const T&)) override {
        for (size_t i = 1; i < arr->get_size(); ++i) {
            T key = arr->GetData()[i];
            size_t low = 0;
            size_t high = i;

            // Найти позицию вставки ключа с помощью бинарного поиска
            while (low < high) {
                size_t mid = (low + high) / 2;
                if (cmp(arr->GetData()[mid], key) > 0) {
                    high = mid;
                } else {
                    low = mid + 1;
                }
            }

            // Сдвинуть элементы вправо для вставки ключа
            for (size_t j = i; j > low; --j) {
                arr->GetData()[j] = arr->GetData()[j - 1];
            }

            arr->GetData()[low] = key;
        }

        return arr;
    }
};


template <typename T>
class QuickSorter : public ISorter<T> {
public:
    DinamicArray<T>* Sort(DinamicArray<T>* arr, int (*cmp)(const T&, const T&)) override {
        quickSort(arr->GetData(), 0, arr->get_size() - 1, cmp);
        return arr;
    }

private:
    void quickSort(T* data, int low, int high, int (*cmp)(const T&, const T&)) {
        if (low < high) {
            int pi = partition(data, low, high, cmp);
            quickSort(data, low, pi - 1, cmp);
            quickSort(data, pi + 1, high, cmp);
        }
    }

    int partition(T* data, int low, int high, int (*cmp)(const T&, const T&)) {
        T pivot = data[high];
        int i = low - 1;
        for (int j = low; j <= high - 1; j++) {
            if (cmp(data[j], pivot) < 0) {
                i++;
                std::swap(data[i], data[j]);
            }
        }
        std::swap(data[i + 1], data[high]);
        return i + 1;
    }
};

#endif // SORTER_H

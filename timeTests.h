#ifndef TIMETESTS_H
#define TIMETESTS_H
#include <ctime>
#include "dinamicArray.h"
#include "sorter.h"
#include <bits/stdc++.h>
#include <exception>


void garbage(){
    // DinamicArray<int> arr;
    // arr.push_back(10);
    // arr.push_back(5);
    // arr.push_back(20);
    // arr.push_back(15);
    // arr.push_back(3);
    // arr.push_back(2);
    // for (size_t i = 0; i < arr.get_size(); ++i) {
    //     std::cout << arr[i] << " ";
    // }
    // std::cout << std::endl;
    // // Сортировка подсчетом
    // CountingSorter<int> sorter1;
    // sorter1.Sort(&arr, [](int a, int b) { return a - b; });
    // for (size_t i = 0; i < arr.get_size(); ++i) {
    //     std::cout << arr[i] << " ";
    // }
    // std::cout << std::endl;
    // arr.push_back(6);
    // arr.push_back(7);
    // arr.push_back(299);
    // arr.push_back(45);
    // arr.push_back(66);
    // arr.push_back(2);
    // // Метод двоичного поиска
    // BinaryInsertionSorter<int> sorter2;
    // sorter2.Sort(&arr, [](int a, int b) { return a - b; });
    // for (size_t i = 0; i < arr.get_size(); ++i) {
    //     std::cout << arr[i] << " ";
    // }
    // std::cout << std::endl;
    // arr.push_back(10);
    // arr.push_back(5);
    // arr.push_back(20);
    // arr.push_back(15);
    // arr.push_back(3);
    // arr.push_back(2);
    // // Быстрая сортировка
    // QuickSorter<int> sorter3;
    // sorter3.Sort(&arr, [](int a, int b) { if (a < b) return -1;
    // if (a > b) return 1;
    // return 0; });
    // for (size_t i = 0; i < arr.get_size(); ++i) {
    //     std::cout << arr[i] << " ";
    // }
    // std::cout << std::endl;
}

struct Person {
    std::string first_name;
    std::string last_name;
    int birth_year;
    float height;
    float weight;

    bool operator==(const Person& other) const {
        return first_name == other.first_name && last_name == other.last_name &&
               birth_year == other.birth_year && height == other.height && weight == other.weight;
    }
};

// Comparator function
int CompareByBirthYear(const Person& a, const Person& b) {
    if (a.birth_year < b.birth_year) return -1;
    if (a.birth_year > b.birth_year) return 1;
    return 0;
}

int CompareByHeight(const Person& a, const Person& b) {
    if (a.height < b.height) return -1;
    if (a.height > b.height) return 1;
    return 0;
}
int CompareStrings(const std::string& a, const std::string& b) {
    return a.compare(b);
}

void testBubbleSorter() {
    DinamicArray<Person> arr;
    arr.push_back({"John", "Doe", 1980, 180.5, 75.0});
    arr.push_back({"Jane", "Smith", 1990, 165.0, 60.0});
    arr.push_back({"Alice", "Johnson", 1985, 170.0, 65.0});
    arr.push_back({"Bob", "Brown", 1975, 175.0, 70.0});
    arr.push_back({"Charlie", "Davis", 2000, 160.0, 55.0});

    // Print the original array
    std::cout << "Original array:" << std::endl;
    for (size_t i = 0; i < arr.get_size(); ++i) {
        std::cout << arr[i].first_name << " " << arr[i].last_name << " " << arr[i].birth_year << " "
                  << arr[i].height << " " << arr[i].weight << std::endl;
    }

    // Sort by birth year
    BubbleSorter<Person> sorter;
    sorter.Sort(&arr, CompareByBirthYear);

    // Print the sorted array
    std::cout << "Sorted by birth year:" << std::endl;
    for (size_t i = 0; i < arr.get_size(); ++i) {
        std::cout << arr[i].first_name << " " << arr[i].last_name << " " << arr[i].birth_year << " "
                  << arr[i].height << " " << arr[i].weight << std::endl;
    }

    // Sort by height
    sorter.Sort(&arr, CompareByHeight);

    // Print the sorted array
    std::cout << "Sorted by height:" << std::endl;
    for (size_t i = 0; i < arr.get_size(); ++i) {
        std::cout << arr[i].first_name << " " << arr[i].last_name << " " << arr[i].birth_year << " "
                  << arr[i].height << " " << arr[i].weight << std::endl;
    }
}

#endif // TIMETESTS_H

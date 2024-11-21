#ifndef DINAMICARRAY_H
#define DINAMICARRAY_H
#include <bits/stdc++.h>
#include <iostream>
#include <exception>

template <typename T>
class DinamicArray {
protected:
    T* data;
    size_t size;
    size_t capacity;

    void resize_internal(size_t new_capacity) {
        if (new_capacity == 0) {
            delete[] data;
            data = nullptr;
            size = 0;
            capacity = 0;
            return;
        }

        T* new_data = new T[new_capacity];
        if (new_data == nullptr) {
            throw std::bad_alloc();
        }

        size_t copy_size = std::min(size, new_capacity);
        for (size_t i = 0; i < copy_size; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
    DinamicArray() : data(nullptr), size(0), capacity(0) {}
    virtual ~DinamicArray() { delete[] data; }

    void resize(size_t new_size) {
        if (new_size > capacity) {
            resize_internal(std::max(new_size, capacity * 2));
        }
        size = new_size;
    }

    size_t get_size() const { return size; }
    size_t get_capacity() const { return capacity; }
    bool isEmpty() const { return size == 0; }

    T& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    void push_back(const T& value) {
        if (size == capacity) {
            resize_internal(capacity == 0 ? 1 : capacity * 2);
        }
        data[size++] = value;
    }

    void insert(size_t index, const T& value) {
        if (index > size) {
            throw std::out_of_range("Index out of range");
        }
        if (size == capacity) {
            resize_internal(capacity == 0 ? 1 : capacity * 2);
        }
        for (size_t i = size; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        size++;
    }


    void erase(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        for (size_t i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        size--;
    }
    T* GetData() {
        return data;
    }
    size_t GetSize() const { return size; }
};


#endif // DINAMICARRAY_H

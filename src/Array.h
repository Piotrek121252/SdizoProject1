#pragma once
#include <iostream>
#include <vector>

class Array {
    size_t array_size = 0;
    int* array = nullptr;

public:
    Array(size_t initialSize);
    ~Array();
    //metody, dla których badałem czas
    void add_to_beginning(const int &value);
    void add_to_back(const int &value);
    void add(const int &value, int index);

    void delete_from_beginning();
    void delete_from_back();
    void delete_element(int index);

    int search(int value); //Zwraca index pierwszej napotkanej wartości w tablicy albo -1 gdy nie ma takiej wartości

    //metody pomocnicze
    void print();
    void fill_array(std::vector<int> data);
    void swap(int index_1, int index_2);
    int &get_value(int index);
    int get_size(); //const w tym miejscu oznacza, że metoda nie może modyfikować pól obiektu
    bool validate_index(int index);
};


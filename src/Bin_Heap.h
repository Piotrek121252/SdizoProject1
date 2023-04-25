#pragma once
#include <iostream>
#include "Array.h"

class Bin_Heap {
    Array* array; //wykorzystujemy naszą tablicę dynamiczną

public:
    Bin_Heap();
    ~Bin_Heap();
    //metody dla których mierzę czas
    int search(int value);
    void delete_from_top();
    void add(int value);
    //metody pomocnicze
    void print();
private:
    void fix_from_top(int index, int array_size); //naprawa kopca w dół
    void fix_from_bottom(int index); //naprawa kopca do góry


};



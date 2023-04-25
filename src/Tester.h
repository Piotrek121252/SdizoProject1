#pragma once
#include <chrono>
#include <random>
#include <vector>
#include <fstream>
#include "Array.h"
#include "List.h"
#include "Bin_Heap.h"
#include "BSTree.h"


class Tester {
public:
    Tester();
    ~Tester();

    void array_test(int n, std::string out_file_name);
    void list_test(int n, std::string out_file_name);
    void Bin_heap_test(int n, std::string out_file_name);
    void BSTree_test(int n, std::string out_file_name);
};


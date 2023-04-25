#include "Tester.h"

Tester::Tester() = default;

Tester::~Tester() = default;

void Tester::array_test(int n, std::string out_file_name) {
    int size = n;

    std::ofstream fout;

    Array* array = new Array(0);
    std::vector<long long int> results;

    std::vector<int> generated_data;

    results.clear();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist1(0, INT_MAX);

    for(int i=0; i<size; i++) { //generujemy losowe wartości
        generated_data.push_back(dist1(gen));
    }

    array->fill_array(generated_data); //wypełniamy tablicę


    std::uniform_int_distribution<> dist2(0, array->get_size() - 1);

    int random_index = dist2(gen);
    int value = array->get_value(random_index);


    auto end = std::chrono::high_resolution_clock::now();

    auto start = std::chrono::high_resolution_clock::now();
    array->search(value);
    end = std::chrono::high_resolution_clock::now();

    results.push_back(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());

    value = dist1(gen);

    start = std::chrono::high_resolution_clock::now();
    array->add_to_beginning(value);
    end = std::chrono::high_resolution_clock::now();

    results.push_back(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
    array->delete_from_beginning();

    value = dist1(gen);

    start = std::chrono::high_resolution_clock::now();
    array->add_to_back(value);
    end = std::chrono::high_resolution_clock::now();

    results.push_back(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
    array->delete_from_back();

    value = dist1(gen);
    random_index = dist2(gen);

    start = std::chrono::high_resolution_clock::now();
    array->add(value, random_index);
    end = std::chrono::high_resolution_clock::now();

    results.push_back(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
    array->delete_element(random_index);

    value = array->get_value(0);

    start = std::chrono::high_resolution_clock::now();
    array->delete_from_beginning();
    end = std::chrono::high_resolution_clock::now();

    results.push_back(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
    array->add_to_beginning(value);

    value = array->get_value(array->get_size() - 1);

    start = std::chrono::high_resolution_clock::now();
    array->delete_from_back();
    end = std::chrono::high_resolution_clock::now();

    results.push_back(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
    array->add_to_back(value);

    random_index = dist2(gen);

    start = std::chrono::high_resolution_clock::now();
    array->delete_element(random_index);
    end = std::chrono::high_resolution_clock::now();

    results.push_back(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());

    fout.open(out_file_name, std::ofstream::app);
    for(int i = 0; i < results.size(); i++) {
        fout << results[i];
        if(i != results.size() - 1)
            fout << ",";
    }
    fout << std::endl;
    fout.close();
}

void Tester::list_test(int n, std::string out_file_name) {
    int size = n;

    std::ofstream fout;

    List* list = new List();
    std::vector<long long int> results;


    std::vector<int> generated_data;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist1(0, INT_MAX);

    for(int i=0; i<size; i++) { //generujemy losowe wartości
        generated_data.push_back(dist1(gen));
    }

    for(int i=0; i<size; i++) {
        list->add_to_beginning(generated_data[i]);
    }

    std::uniform_int_distribution<> dist2(0, list->get_Size() - 1);

    int random_index = dist2(gen);
    int value = generated_data[random_index];

    auto end = std::chrono::high_resolution_clock::now();

    auto start = std::chrono::high_resolution_clock::now();
    list->search(value);
    end = std::chrono::high_resolution_clock::now();

    results.push_back(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());

    value = dist1(gen);

    start = std::chrono::high_resolution_clock::now();
    list->add_to_beginning(value);
    end = std::chrono::high_resolution_clock::now();

    results.push_back(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
    list->delete_from_beginning();

    value = dist1(gen);

    start = std::chrono::high_resolution_clock::now();
    list->add_to_end(value);
    end = std::chrono::high_resolution_clock::now();

    results.push_back(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
    list->delete_from_end();

    value = dist1(gen);
    random_index = dist2(gen);

    start = std::chrono::high_resolution_clock::now();
    list->add_at_index(value, random_index);
    end = std::chrono::high_resolution_clock::now();

    results.push_back(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
    list->delete_at_index(random_index);

    value = dist1(gen);

    start = std::chrono::high_resolution_clock::now();
    list->delete_from_beginning();
    end = std::chrono::high_resolution_clock::now();

    results.push_back(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
    list->add_to_beginning(value);

    value = dist1(gen);

    start = std::chrono::high_resolution_clock::now();
    list->delete_from_end();
    end = std::chrono::high_resolution_clock::now();

    results.push_back(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
    list->add_to_end(value);

    random_index = dist2(gen);

    start = std::chrono::high_resolution_clock::now();
    list->delete_at_index(random_index);
    end = std::chrono::high_resolution_clock::now();

    results.push_back(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());

    fout.open(out_file_name, std::ofstream::app);
    for(int i = 0; i < results.size(); i++) {
        fout << results[i];
        if(i != results.size() - 1)
            fout << ",";
    }
    fout << std::endl;
    fout.close();
}

void Tester::Bin_heap_test(int n, std::string out_file_name) {
    int size = n;
    std::ofstream fout;

    Bin_Heap* heap = new Bin_Heap();

    std::vector<long long int> results;
    std::vector<int> generated_data;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist1(0, INT_MAX);

    for(int i=0; i<size; i++) { //generujemy losowe wartości
        generated_data.push_back(dist1(gen));
    }

    for(int i=0; i<size; i++) {
        heap->add(generated_data[i]);

    }
    std::cout << "Utworzono kopiec!" << std::endl;


    std::uniform_int_distribution<> dist2(0, size - 1);

    int random_index = dist2(gen);
    int value = generated_data[random_index];

    auto end = std::chrono::high_resolution_clock::now();

    auto start = std::chrono::high_resolution_clock::now();
    heap->search(value);
    end = std::chrono::high_resolution_clock::now();

    results.push_back(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());

    value = dist1(gen);

    start = std::chrono::high_resolution_clock::now();
    heap->add(value);
    end = std::chrono::high_resolution_clock::now();

    results.push_back(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());

    start = std::chrono::high_resolution_clock::now();
    heap->delete_from_top();
    end = std::chrono::high_resolution_clock::now();

    results.push_back(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());

    fout.open(out_file_name, std::ofstream::app);
    for(int i = 0; i < results.size(); i++) {
        fout << results[i];
        if(i != results.size() - 1)
            fout << ",";
    }
    fout << std::endl;
    fout.close();

}

void Tester::BSTree_test(int n, std::string out_file_name) {

    int size = n;
    std::ofstream fout;

    BSTree* tree = new BSTree();

    std::vector<long long int> results;
    std::vector<int> generated_data;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist1(0, INT_MAX);

    for(int i=0; i<size; i++) { //generujemy losowe wartości
        generated_data.push_back(dist1(gen));
    }

    for(int i=0; i<size; i++) {
        tree->add_node(generated_data[i]);

    }
    std::cout << "Utworzono drzewo." << std::endl;

    std::uniform_int_distribution<> dist2(0, size - 1);

    int random_index = dist2(gen);
    int value = generated_data[random_index];

    auto end = std::chrono::high_resolution_clock::now();

    auto start = std::chrono::high_resolution_clock::now();
    tree->search(value);
    end = std::chrono::high_resolution_clock::now();

    results.push_back(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());

    value = dist1(gen);

    start = std::chrono::high_resolution_clock::now();
    tree->add_node(value);
    end = std::chrono::high_resolution_clock::now();

    results.push_back(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());

    random_index = dist2(gen);
    value = generated_data[random_index];

    start = std::chrono::high_resolution_clock::now();
    tree->erase_node(tree->search(value));
    end = std::chrono::high_resolution_clock::now();

    results.push_back(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());

    fout.open(out_file_name, std::ofstream::app);
    for(int i = 0; i < results.size(); i++) {
        fout << results[i];
        if(i != results.size() - 1)
            fout << ",";
    }
    fout << std::endl;
    fout.close();


}

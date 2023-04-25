#include "Bin_Heap.h"


Bin_Heap::Bin_Heap() {
    array = new Array(0);
}

Bin_Heap::~Bin_Heap() {
    if(array)
        delete array;
}
//Jeśli kopiec ma więcej niż 2 elementy to wpisujemy ostatni element z tablicy w miejsce korzenia
//i następnie usuwamy ostatnią wartość z tablicy i naprawiamy kopiec w dół zaczynając w korzeniu
void Bin_Heap::delete_from_top() {
    int size = array->get_size();
    if(size == 0)
        return;
    if (size <= 2) {
        array->delete_from_beginning();
        return;
    }

    array->swap(0,size - 1);
    array->delete_from_back();

    fix_from_top(0, size - 1); //naprawiamy od góry zaczynając w korzeniu
}

//Dodajemy nową wartość na koniec tablicy i naprawiamy w górę zaczynając od dodanej wartości
void Bin_Heap::add(int value) {
    array->add_to_back(value);

    fix_from_bottom(array->get_size() - 1);
}

//Naprawa kopca w dół
void Bin_Heap::fix_from_top(int index, int array_size) {

    int max_index = index; //zmienna przechowująca index z największą wartością pomiędzy rodzicem i jego dziećmi
    int left_child_index = index * 2 + 1; //korzystamy z własności kopca do wyznaczenia indeksów dzieci
    int right_child_index = index * 2 + 2;

    //sprawdzamy pod którym z powyższych indeksów jest największa wartość
    if(left_child_index < array_size && array->get_value(left_child_index) > array->get_value(max_index)) {
        max_index = left_child_index;
    }
    if(right_child_index < array_size && array->get_value(right_child_index) > array->get_value(max_index)) {
        max_index = right_child_index;
    }

    //Jeśli największa wartość nie znajduje się pod indeksem rodzica to zamieniamy ją z rodzicem
    //i naprawiamy kopiec w dół zaczynając od indeksu gdzie była największa wartość (jedno z dzieci)
    if(index != max_index) {
        array->swap(index,  max_index);
        fix_from_top(max_index, array_size);
    }
}
//Naprawa kopca w górę
void Bin_Heap::fix_from_bottom(int index) {

    int parent_index = (index - 1)/2; //korzystając z własności kopca obliczamy index rodzica

    //zamieniamy wartość rodzica z wartością dziecka dopóki nie dojedziemy do korzenia albo wartość rodzica będzie większa
    while(index > 0 && array->get_value(index) > array->get_value(parent_index)) {
        array->swap(index, parent_index);
        index = parent_index;
        parent_index = (index - 1)/2;
    }
}

void Bin_Heap::print() {
    int size = array->get_size();
    if(size == 0) {
        std::cout << "Kopiec jest pusty." << std::endl;
        return;
    }

    int max_on_level = 1, printed_on_level;
    int i = 0;

    std::cout << "Obecny stan kopca:" << std::endl;
    while(i < size) {
        printed_on_level = 0;
        while(i < size && printed_on_level <  max_on_level) {
            std::cout << array->get_value(i) << " ";
            printed_on_level++;
            i++;
        }
        std::cout << std::endl;
        max_on_level *= 2;
    }
}

int Bin_Heap::search(int value) {
    return array->search(value);
}











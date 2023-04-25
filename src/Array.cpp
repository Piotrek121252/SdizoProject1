#include "Array.h"


Array::Array(size_t initialSize) {
    if(initialSize == 0) //Jesli podana wartosc to 0 to nie tworzymy tablicy
        return;
    array_size = initialSize;
    array = new int[initialSize];
}
//Zwalniamy zasoby przy usuwaniu tablicy
Array::~Array() {
    if(array_size > 0)
        delete[] array;
}

int &Array::get_value(int index) {
    return array[index];
}

int Array::get_size(){
    return array_size;
}

void Array::print() {

    std::cout << "\nObecny stan tablicy: ";

    if(array_size == 0)
    {
        std::cout << "Tablica jest pusta." << std::endl;
        return;
    }

    for(int i = 0; i < array_size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}


void Array::add_to_beginning(const int &value) {

    size_t new_size = array_size + 1;
    int* temp_array = new int[new_size];

    //kopiujemy tylko gdy tablica nie jest pusta
    if(array) {
        for(int i = 1; i < new_size; i++) {
            temp_array[i] = array[i - 1];
        }
    }
    temp_array[0] = value;

    delete[] array;

    array = temp_array;
    array_size = new_size;
}

void Array::add_to_back(const int &value) {

    size_t new_size = array_size + 1;
    int* temp_array = new int [new_size];

    if(array) {
        for(int i = 0; i < array_size; i++) {
            temp_array[i] = array[i];
        }
    }
    temp_array[new_size - 1] = value;

    delete[] array;

    array_size = new_size;
    array = temp_array;
}
//ponieważ validate_index sprawdza czy index jest aktualnie dostępny
// musimy jeszczę sprawdzić czy użytkownik nie chce dodać na koniec tablicy
void Array::add(const int &value, int index) {
    if(!validate_index(index) && index != array_size) {
        return;
    }

    size_t newSize = array_size + 1;
    int* temp_array = new int[newSize];

    for(int i=0; i < index; i++) {
        temp_array[i] = array[i];
    }

    temp_array[index] = value;

    for(int i = index; i < array_size; i++) {
        temp_array[i + 1] = array[i];
    }

    delete[] array;

    array_size = newSize;
    array = temp_array;
}

bool Array::validate_index(int index) {
    if(index < 0 || index >= array_size)
        return false;
    else
        return true;
}


void Array::delete_from_beginning() {
    if(array_size == 0)
        return;
    if(array_size == 1) {
        delete[] array;
        array_size = 0;
        array = nullptr;
        return;
    }

    size_t new_size = array_size - 1;
    int* temp_array = new int[new_size];

    for(int i=0; i < new_size; i++) {
        temp_array[i] = array[i+1];
    }

    delete[] array;

    array = temp_array;
    array_size = new_size;
}

void Array::delete_from_back() {
    if(array_size == 0)
        return;
    if(array_size == 1) {
        delete[] array;
        array_size = 0;
        array = nullptr;
        return;
    }

    size_t new_size = array_size - 1;
    int* temp_array = new int[new_size];

    for(int i=0; i < new_size; i++) {
        temp_array[i] = array[i];
    }

    delete[] array;

    array = temp_array;
    array_size = new_size;
}

void Array::delete_element(int index) {
    if(array_size == 0 || !validate_index(index)) {
        return;
    }
    if(array_size == 1) {
        delete[] array;
        array_size = 0;
        array = nullptr;
        return;
    }

    size_t new_size = array_size - 1;
    int* temp_array = new int[new_size];

    for(int i=0; i < index; i++) {
        temp_array[i] = array[i];
    }

    for(int i=index; i < new_size; i++) {
        temp_array[i] = array[i+1];
    }

    delete[] array;

    array = temp_array;
    array_size = new_size;
}

//Zwraca index pierwszej napotkanej wartości w tablicy albo -1 gdy nie ma takiej wartości.
int Array::search(int value) {
    for(int i=0; i<array_size; i++) {
        if(array[i] == value)
            return i;
    }
    return -1;
}

void Array::swap(int index_1, int index_2) {
    if(array_size < 2)
        return;

    if((validate_index(index_1)) && (validate_index(index_2))) {
        int temp = array[index_1];
        array[index_1] = array[index_2];
        array[index_2] = temp;
    }
}

void Array::fill_array(std::vector<int> data) {

    int size = data.size();
    if(array_size == 0)
        array = new int[size];
    else {
        delete[] array;
        array = new int[size];
    }

    for(int i = 0; i < size; i++) {
        array[i] = data[i];
    }

    array_size = size;
}



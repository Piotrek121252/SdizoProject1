#include "List.h"

List::List() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

// Musimy zwolnić pamięć zajmowaną przez Elementy listy
List::~List() {
    List_element* current_element = head;
    List_element* next_element;

    //Iterujemy po wszystkich elementach i zwalniamy pamięć
    while(current_element != nullptr) {
        next_element = current_element -> next;
        delete current_element;
        current_element = next_element;
    }
}

void List::add_to_beginning(int value) {

    List_element* new_element = new List_element(value);
    size++;
    if(head == nullptr) { //sprawdzamy czy lista jest pusta czy już mamy jakąś wartość
        head = new_element;
        tail = new_element;
    } else {
        new_element->next = head;
        head->previous = new_element;
        head = new_element;
    }

}

void List::add_to_end(int value) {

    List_element* new_element = new List_element(value);
    size++;
    if(tail == nullptr) { //sprawdzamy czy lista jest pusta czy już mamy jakąś wartość
        head = new_element;
        tail = new_element;
    } else {
        new_element->previous = tail;
        tail->next = new_element;
        tail = new_element;
    }

}

void List::add_at_index(int value, int index) {
    if(index > size || index < 0)
        return;
    else if(index == size) { //index jest równy size wiec dodajemy na koniec listy
        add_to_end(value);
        return;
    } else if(index == 0) { //index jest równy 0 dodajemy na początek listy
        add_to_beginning(value);
        return;
    }

    List_element* current_element;
    //jeśli index znajduje się w pierwszej połowie elementów i iterujemy od head
    if(index <= (size/2)) {
        current_element = head;
        for(int i = 0; i < index; i++)
            current_element = current_element->next;

    } else { // index znajduje się w drugiej połowie elementów zatem iterujemy od tail
        current_element = tail;
        for(int i = size - 1; i > index; i--)
            current_element = current_element->previous;
    }

    List_element* new_element = new List_element(value);

    //wstawiamy pomiędzy dwa elementy nowy element przez modyfikowanie wskaźników elementu poprzedniego i następnego
    List_element* previous_element = current_element->previous;
    List_element* next_element = current_element;

    next_element->previous = new_element;
    previous_element->next = new_element;
    new_element->previous = previous_element;
    new_element->next = next_element;

    size++;
}

void List::delete_from_beginning() {

    if(!head) {
        return;
    }

    List_element* next_element = head->next;
    size--;

    if(!next_element) { //Gdy lista ma tylko jeden element
        delete head;
        head = nullptr;
        tail = nullptr;
    } else {
        delete head;
        next_element->previous = nullptr;
        head = next_element;
    }
}

void List::delete_from_end() {

    if(!tail) {
        return;
    }

    List_element* previous_element = tail->previous;
    size--;

    if(!previous_element) { //Gdy lista ma tylko jeden element
        delete tail;
        head = nullptr;
        tail = nullptr;
    } else {
        delete tail;
        previous_element->next = nullptr;
        tail = previous_element;
    }
}

void List::delete_at_index(int index) {
    if(index >= size || index < 0)
        return;
    if(index == 0) { //usuwamy z początku
        delete_from_beginning();
        return;
    }
    if(index == size) { //usuwamy z końca listy
        delete_from_end();
        return;
    }

    List_element* current_element;

    if(index <= (size/2)) { //jeśli index znajduje się w pierwszej połowie elementów to iterujemy od head
        current_element = head;
        for(int i = 0; i < index; i++)
            current_element = current_element->next;

    } else { // index znajduje się w drugiej połowie elementów zatem iterujemy od tail
        current_element = tail;
        for(int i = size - 1; i > index; i--)
            current_element = current_element->previous;
    }
    //łączymy element wcześniejszy i następny ze sobą
    current_element->previous->next = current_element->next;
    current_element->next->previous = current_element->previous;

    //usuwamy znaleziony element
    delete current_element;
    size--;
}

//zwraca pozycje pierwszej napotkanej wartości albo -1 gdy nie damy rady jej znaleźć
int List::search(int value) {
    int index = 0;
    List_element* current_element = head;

    while(current_element) {
        if(current_element->value == value) {
            return index;
        }
        current_element = current_element->next;
        index++;
    }
    return -1;
}

void List::print_from_start() {

    if(!head) {
        std::cout << "Lista jest pusta!" << std::endl;
        return;
    } else
        std::cout << "Elementy listy od poczatku do konca:" << std::endl;

    List_element* current_element = head;
    while(current_element) {
        std::cout << current_element->value << " ";
        current_element = current_element->next;
    }
    std::cout << std::endl;
}

void List::print_from_end() {

    if(!tail) {
        std::cout << "Lista jest pusta!" << std::endl;
        return;
    } else
        std::cout << "Elementy listy od konca do poczatku:" << std::endl;

    List_element* current_element = tail;
    while(current_element) {
        std::cout << current_element->value << " ";
        current_element = current_element->previous;
    }
    std::cout << std::endl;
}

void List::print() {
    if(!head) {
        std::cout << "\nLista jest pusta!" << std::endl;
    } else {
        std::cout << "\nIlosc elementow w liscie: " << size << std::endl;
        print_from_start();
        std::cout << std::endl;
        print_from_end();
    }
}

int List::get_Size() {
    return size;
}






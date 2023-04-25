#pragma once
#include <iostream>
#include "List_element.h"

class List {
List_element* head;
List_element* tail;
int size;

public:
List();
~List();

//metody, dla których dokonano testów czasowych
void add_to_beginning(int value);
void add_to_end(int value);
void add_at_index(int value, int index);

void delete_from_beginning();
void delete_from_end();
void delete_at_index(int index);

int search(int value); //zwraca index pierwszej wartości, którą znajdzie w liście

//dodatkowe metody pomocnicze
void print();
void print_from_start();
void print_from_end();

int get_Size();
};




/*
 Projekt: Sdizo_1
 Autor: Piotr Komarnicki
*/
#include <iostream>
#include "Array.h"
#include "List.h"
#include "Bin_Heap.h"
#include "BSTree.h"
#include "Tester.h"

int get_input_from_user(std::string type) {
    int value;
    std::cout << "Podaj " << type << ":";
    std::cin >> value;

    std::cin.clear();
    std::cin.ignore(10000, '\n');

    return value;
}

std::vector<int> load_data_from_file() {

    std::string filepath;

    std::cout << "Podaj sciezke pliku: ";
    std::cin >> filepath;

    std::fstream file;

    file.open(filepath, std::ios::in);
    if (file.good()) {
        std::cout << "File loaded successfully" << std::endl;
    } else {
        std::cout << "File not found" << std::endl;
    }

    int size;

    if (file.is_open()) {
        file >> size;

        if (file.fail()) {
            std::cout << "File error - READ SIZE" << std::endl;
            return {};
        } else {
            int value;
            std::vector<int> tab(size);

            for (int i = 0; i < size; i++) {
                file >> value;

                if (file.fail()) {
                    std::cout << "File error - READ DATA" << std::endl;
                    return {};
                } else {
                    tab[i] = value;
                }
            }
            file.close();
            return tab;
        }
    } else {
        std::cout << "File error - OPEN" << std::endl;
    }
    return {};
}


void dynamic_array_menu() {
    Array* array = new Array(0);

    char choice;
    int index;


    do {
        std::cout << "\nTablica dynamiczna:" << std::endl;
        std::cout << "1. Zaladuj dane z pliku.\n"
                  << "0. Pozostaw tablice pusta.\n"
                  << "Wybierz opcje: ";

        std::cin >> choice;
        std::cin.clear();
        std::cin.ignore(10000, '\n');

        switch(choice) {
            case '1': {
                    std::vector<int> data = load_data_from_file();
                    array->fill_array(data);
                    array->print();
                    }
            case '0': break;
            default: std::cout << "\nPodany symbol jest bledny, sprobuj jeszcze raz.\n";
        }
    } while(!(choice == '1' || choice == '0'));


    do {
    std::cout << "\nTablica dynamiczna:" << std::endl;

    std::cout << "1. Dodaj element na poczatek\n"
              << "2. Dodaj element na koniec\n"
              << "3. Dodaj element na podane miejsce\n"
              << "4. Usun element z poczatku\n"
              << "5. Usun element z konca\n"
              << "6. Usun element na podanym miejscu\n"
              << "7. Wyszukaj podana wartosc\n"
              << "8. Wyswietl tablice\n"
              << "0. Wyjdz z menu tablicy\n\n"
              << "Wybierz opcje:";

    std::cin >> choice;
    std::cin.clear();
    std::cin.ignore(10000, '\n');

    switch (choice) {
        case '1': array->add_to_beginning(get_input_from_user("wartosc"));
                  array->print();
                  break;
        case '2': array->add_to_back(get_input_from_user("wartosc"));
                  array->print();
                  break;

        case '3': index = get_input_from_user("numer indeksu");
                  if(array->validate_index(index) || index == array->get_size()) {
                  array->add(get_input_from_user("wartosc"), index);
                  array->print();
                  } else
                      std::cout << "\nPodany numer indeksu jest niepoprawny." << std::endl;
                  break;
        case '4': array->delete_from_beginning();
                  array->print();
                  break;
        case '5': array->delete_from_back();
                  array->print();
                  break;
        case '6': index = get_input_from_user("numer indeksu");
                  if(array->validate_index(index)) {
                      array->delete_element(index);
                      array->print();
                  }  else
                      std::cout << "\nPodany numer indeksu jest niepoprawny." << std::endl;
                  break;
        case '7': index = array->search(get_input_from_user("poszukiwana wartosc"));
                  if(index == -1)
                      std::cout << "\nPoszukiwanej wartosci nie ma w tablicy." << std::endl;
                  else {
                      std::cout << "\nPierwsze wystapienie wartosci znajduje sie pod ineksem: " << index <<std::endl;
                      array->print();
                  }
                  break;
        case '8': array->print();
                  break;
        case '0': delete array;
                  std::cout << "\nPowrot do menu glownego." << std::endl;
                  break;
        default: std::cout << "\nPodany symbol jest bledny, sprobuj jeszcze raz.\n";
        }
    } while (choice != '0');
}

void list_menu() {
    int value, index;
    char choice;

    List* list = new List();

    do {
        std::cout << "\nLista dwukierunkowa:" << std::endl;
        std::cout << "1. Zaladuj dane z pliku.\n"
                  << "0. Pozostaw liste pusta.\n"
                  << "Wybierz opcje: ";

        std::cin >> choice;
        std::cin.clear();
        std::cin.ignore(10000, '\n');

        switch(choice) {
            case '1': {std::vector<int> data = load_data_from_file();
                        for(int i = 0; i < data.size(); i++) {
                            list->add_to_end(data[i]);
                        }
                        list->print();
                        }
            case '0': break;
            default: std::cout << "\nPodany symbol jest bledny, sprobuj jeszcze raz.\n";
        }
    } while(!(choice == '1' || choice == '0'));


    do {
        std::cout << "\nLista dwukierunkowa:" << std::endl;

        std::cout << "1. Dodaj element na poczatek\n"
                  << "2. Dodaj element na koniec\n"
                  << "3. Dodaj element na podany indeks\n"
                  << "4. Usun element z poczatku\n"
                  << "5. Usun element z konca\n"
                  << "6. Usun element na podanym indeksie\n"
                  << "7. Wyszukaj podana wartosc\n"
                  << "8. Wyswietl tablice\n"
                  << "0. Wyjdz z menu tablicy\n\n"
                  << "Wybierz opcje:";

        std::cin >> choice;
        std::cin.clear();
        std::cin.ignore(10000, '\n');

        switch (choice) {
            case '1': list->add_to_beginning(get_input_from_user("wartosc"));
                      list->print();
                      break;
            case '2':
                list->add_to_end(get_input_from_user("wartosc"));
                      list->print();
                      break;
            case '3': value = get_input_from_user("wartosc");
                      index = get_input_from_user("indeks");
                      if (index < 0 || index > list->get_Size()) {
                          std::cout << "\nPodany numer indeksu jest niepoprawny." << std::endl;
                      } else {
                          list->add_at_index(value, index);
                          list->print();
                      }
                      break;
            case '4': list->delete_from_beginning();
                      list->print();
                      break;
            case '5': list->delete_from_end();
                      list->print();
                      break;
            case '6': if(list->get_Size() != 0) {
                        index = get_input_from_user("indeks");
                        if (index < 0 || index >= list->get_Size()) {
                            std::cout << "\nPodany numer indeksu jest niepoprawny." << std::endl;
                        } else {
                            list->delete_at_index(index);
                            list->print();
                        }
                      } else
                            list->print();
                      break;
            case '7': index = list->search(get_input_from_user("wartosc"));
                      if(index != -1)
                          std::cout << "\nPodana wartosc znajduje sie pod indeksem:" << index << std::endl;
                      else
                          std::cout << "\nW liscie nie ma takiej wartosc." << std::endl;
                      break;
            case '8': list->print();
                      break;
            case '0': delete list;
                      std::cout << "\nPowrot do menu glownego." << std::endl;
                      break;
            default: std::cout << "\nPodany symbol jest bledny, sprobuj jeszcze raz.\n";
        }
    } while (choice != '0');

}

void binary_heap_menu() {
    Bin_Heap* heap = new Bin_Heap();

    char choice;
    int index;

    do {
        std::cout << "\nKopiec Binarny:" << std::endl;
        std::cout << "1. Zaladuj dane z pliku.\n"
                  << "0. Pozostaw kopiec pusty.\n"
                  << "Wybierz opcje: ";

        std::cin >> choice;
        std::cin.clear();
        std::cin.ignore(10000, '\n');

        switch(choice) {
            case '1': {
                        std::vector<int> data = load_data_from_file();
                        for(int i = 0; i < data.size(); i++) {
                            heap->add(data[i]);
                        }
                        heap->print();
                      }
            case '0': break;
            default: std::cout << "\nPodany symbol jest bledny, sprobuj jeszcze raz.\n";
        }
    } while(!(choice == '1' || choice == '0'));


    do {
        std::cout << "\nKopiec binarny:" << std::endl;

        std::cout << "1. Dodaj element\n"
                  << "2. Usun element w korzeniu\n"
                  << "3. Wyszukaj podana wartosc\n"
                  << "4. Wyswietl kopiec\n"
                  << "0. Wyjdz z menu kopca\n\n"
                  << "Wybierz opcje:";

        std::cin >> choice;
        std::cin.clear();
        std::cin.ignore(10000, '\n');

        switch (choice) {
            case '1': heap->add(get_input_from_user("wartosc"));
                      heap->print();
                      break;
            case '2': heap->delete_from_top();
                      heap->print();
                      break;
            case '3': index = heap->search(get_input_from_user("wartosc"));
                      if (index == -1) {
                          std::cout << "\nPoszukiwanej wartosci nie ma w kopcu." << std::endl;
                      } else {
                        if (index == 0) {
                            std::cout << "Poszukiwana wartosc znajduje sie w korzeniu." << std::endl;
                        } else
                            std::cout << "\nPierwsze wystapienie wartosci znajduje sie pod ineksem: " << index << std::endl;
                        heap->print();
                      }
                      break;
            case '4': heap->print();
                      break;
            case '0': delete heap;
                      std::cout << "\nPowrot do menu glownego." << std::endl;
                      break;
            default:  std::cout << "\nPodany symbol jest bledny, sprobuj jeszcze raz.\n";
        }
    } while (choice != '0');
}

void binary_search_tree_menu() {

    BSTree* tree = new BSTree();

    BST_Node* node;
    char choice;
    int value;


    do {
        std::cout << "\nDrzewo poszukiwan binarnych:" << std::endl;
        std::cout << "1. Zaladuj dane z pliku.\n"
                  << "0. Pozostaw drzewo puste.\n"
                  << "Wybierz opcje: ";

        std::cin >> choice;
        std::cin.clear();
        std::cin.ignore(10000, '\n');

        switch(choice) {
            case '1':   {
                        std::vector<int> data = load_data_from_file();
                        for(int i = 0; i < data.size(); i++) {
                            tree->add_node(data[i]);
                        }
                        tree->print();
                        }
            case '0': break;
            default: std::cout << "\nPodany symbol jest bledny, sprobuj jeszcze raz.\n";
        }
    } while(!(choice == '1' || choice == '0'));


    do {
        std::cout << "\nDrzewo poszukiwan binarnych (BST):" << std::endl;

        std::cout << "1. Dodaj wezel\n"
                  << "2. Usun wezel\n"
                  << "3. Sprawdz czy istnieje dana wartosc\n"
                  << "4. Wyswietl drzewo binarne\n"
                  << "0. Wyjdz z menu BST\n"
                  << "\nWybierz opcje:";

        std::cin >> choice;
        std::cin.clear();
        std::cin.ignore(10000, '\n');

        switch (choice) {
            case '1': tree->add_node(get_input_from_user("klucz wezla"));
                      tree->print();
                      break;
            case '2': node = tree->search(get_input_from_user("klucz wezla"));
                      if(node != nullptr) {
                          tree->erase_node(node);
                          tree->print();
                      }
                      else
                          std::cout << "Nie znaleziono podanej wartosci w drzewie binarnym." << std::endl;
                      break;
            case '3': value = get_input_from_user("wartosc");
                      node = tree->search(value);
                      if(node != nullptr && node->key == value)
                          std::cout << "Podana wartosc znajduje sie w drzewie binarnym." << std::endl;
                      else
                          std::cout << "W drzewie binarnym nie ma podanej wartosci." << std::endl;
                      break;
            case '4': tree->print();
                      break;
            case '0': delete tree;
                      std::cout << "\nPowrot do menu glownego." << std::endl;
                      break;
            default:  std::cout << "\nPodany symbol jest bledny, sprobuj jeszcze raz.\n";
        }
    } while (choice != '0');
}

int main(int argc, char *argv[]) {

    if(argc == 2) {
        Tester* tester = new Tester();
        std::string mode = argv[1];
        if(mode == "test1") {
            std::cout << "\nWybrano test tablicy dynamicznej." << std::endl;
            for(int i=0; i < 10; i++)
                tester->array_test(10000000, "Wyniki_Tablica_10000000.csv");
            std::cout << "\nKoniec testu." << std::endl;
            std::cin.get();
        } else if(mode == "test2") {
            std::cout << "\nWybrano test listy dwukierunkowej." << std::endl;
            for(int i=0; i < 10; i++)
                tester->list_test(10000000, "Wyniki_Lista_10000000.csv");
            std::cout << "\nKoniec testu." << std::endl;
            std::cin.get();
        } else if(mode == "test3") {
            std::cout << "\nWybrano test kopca binarnego." << std::endl;
            for(int i=0; i < 10; i++)
                tester->Bin_heap_test(100000, "Wyniki_Kopiec_100000.csv");
            std::cout << "\nKoniec testu." << std::endl;
            std::cin.get();
        } else if(mode == "test4") {
            std::cout << "\nWybrano test drzewa BST." << std::endl;
            for(int i=0; i < 10; i++)
                tester->BSTree_test(20000000, "Wyniki_BST_20000000.csv");
            std::cout << "\nKoniec testu." << std::endl;
            std::cin.get();
        }
        delete tester;
        return 0;
    }


    std::cout << "Testy manualne struktur." << std::endl;

    char choice;
    do {
        std::cout << "\nWybierz strukture:\n"
                  << "1. Tablica dynamiczna\n"
                  << "2. Lista dwukierunkowa\n"
                  << "3. Kopiec binarny (max)\n"
                  << "4. Drzewo wyszukiwan binarnych\n"
                  << "0. Wyjscie z programu\n"
                  << std::endl
                  << "Podaj nr opcji:";

        std::cin >> choice;
        std::cin.clear();
        std::cin.ignore(10000, '\n');

        switch (choice) {
            case '1': dynamic_array_menu();
                      break;
            case '2': list_menu();
                      break;
            case '3': binary_heap_menu();
                      break;
            case '4': binary_search_tree_menu();
                      break;
            case '0': std::cout << "\nKonczenie dzialania programu..." << std::endl;
                      break;
            default: std::cout << "\nPodany symbol jest bledny, sprobuj jeszcze raz.\n";
        }
    } while (choice != '0');

    return 0;
}



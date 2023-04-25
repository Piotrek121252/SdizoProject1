#include <iomanip>
#include "BSTree.h"

BSTree::BSTree() {
root = nullptr;
}

BSTree::~BSTree() {
    deleteTree(root);
}

//Metoda rekurencyjna, która pozwala odwiedzić wszystkie wierzchołki
//usuwamy dany wierzchołek dopiero gdy odwiedzimy wszystkie jego dzieci (postorder)
void BSTree::deleteTree(BST_Node *parent) {

    if(!parent) return;
    deleteTree(parent->child_left);
    deleteTree(parent->child_right);

    delete parent;
}

//Wyszukiwanie binarne, gdy nie znajdzie odpowiedniego wezla to wskaznik bedzie mial wartosc nullptr
BST_Node *BSTree::search(int key) {

    BST_Node* temp_node = root;

    while(temp_node && temp_node->key != key) {
        if(key > temp_node->key) {
            temp_node = temp_node->child_right;
        } else
            temp_node = temp_node->child_left;
    }
    return temp_node;
}

BST_Node *BSTree::search_max() {
    BST_Node* temp_node = root;
    while(temp_node->child_right)
        temp_node = temp_node->child_right;
    return temp_node;
}

BST_Node *BSTree::search_min() {
    BST_Node* temp_node = root;
    while(temp_node->child_left)
        temp_node = temp_node->child_left;
    return temp_node;
}

void BSTree::add_node(int key) {

    if(!root) { //gdy drzewo jest puste
      BST_Node* new_node = new BST_Node(key);
      root = new_node;
      return;
    }

    BST_Node* parent_of_node = nullptr;
    BST_Node* current_node = root;
    while(current_node) { //current_node to miejsce dla nowego węzła, szukamy dopóki nie będzie równe nullptr
                          // jednocześnie zapisując kto jest rodzicem dla danego miejsca
        parent_of_node = current_node;
        if(current_node->key < key) //Jeśli klucz nowego węzła jest taki sam to zostanie wstawiony po lewej stronie
            current_node = current_node->child_right;
        else
            current_node = current_node->child_left;
    }

    BST_Node* new_node = new BST_Node(key);
    new_node->parent = parent_of_node;

    if(parent_of_node->key < new_node->key)
        parent_of_node->child_right = new_node;
    else
        parent_of_node->child_left = new_node;
}


void BSTree::erase_node(BST_Node *node_to_erase) {

    BST_Node* replacement; //zmienna przechowująca wezel zamiennika lub usuwany węzeł jeśli ma mniej niż 2 potomków
    if(node_to_erase->child_left && node_to_erase->child_right) { //węzeł ma 2 potomków dlatego szukamy poprzednika jako zamiennik na jego miejsce
            replacement = node_to_erase->child_left;              //poprzednik zawsze jest poniżej bo mamy dwóch potomków
            while(replacement->child_right) {
                replacement = replacement->child_right;
            }
        } else
            replacement = node_to_erase;


    //zamiennik może mieć maksymalnie 1 potomka
    BST_Node* child_of_replacement;
    if(replacement->child_right)
        child_of_replacement = replacement->child_right;
    else
        child_of_replacement = replacement->child_left;

    //Jesli węzeł ma 1 potomka to powiązujemy go z rodzicem usuwanego węzła
    if(child_of_replacement) {
        child_of_replacement->parent = replacement->parent;
    }
    //Jeśli usuwany węzeł był korzeniem
    if (!replacement->parent)
        root = child_of_replacement;
    else
        if(replacement == replacement->parent->child_right) //wiążemy rodzica z nowym dzieckiem
            replacement->parent->child_right = child_of_replacement;
        else
            replacement->parent->child_left = child_of_replacement;

        //Jeśli musieliśmy znaleźć poprzednika dla usuwanego węzła
        // to należy przepisać jego dane w miejsce usuniętego węzła.
    if(replacement != node_to_erase)
        node_to_erase->key = replacement->key;

    delete replacement;
}

void BSTree::print() {
    if(root == nullptr)
        std::cout << "Drzewo jest puste." << std::endl;
    else {
        std::cout << "Obecny stan drzewa:";
        std::cout << std::endl;
        print_structure(root, 0);
        std::cout << std::endl;
    }

}

//Wykonujemy operacje inorder (wartości od największej do najmniejszej) przy każdym wywołaniu funkcji zwiększamy
//zmienną depth aby wiedzieć na jakiej głębokości znajduje się obecny węzeł
void BSTree::print_structure(BST_Node* node, int depth) {

    if(!node)
        return;

    depth += 1;

    print_structure(node->child_right, depth);

    std::cout << std::endl;
    if(node->parent == nullptr) { //korzeń zaznaczony jest strzałką
        std::cout << "->";
    } else {
        std::cout << "      ";
        for(int i = 2; i < depth; i++)
            std::cout << "       ";

        BST_Node* parent = node->parent;

        if(parent != nullptr) {
            if(node == parent->child_right)
                std::cout << "/~~";
            else
                std::cout << "\\~~";
        }
    }
    std::cout << std::right << std::setfill ('~') << std::setw(5) << node->key;

    print_structure(node->child_left, depth);
}




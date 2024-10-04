#include "CharList.hpp"

int main() {
    CharList ist;

    ist.insertNode('a');
    ist.appendNode('h');
    ist.appendNode('o');
    ist.appendNode('k');
    ist.addNode('f');

    ist.displayList();

    ist.deleteNode('l');

    ist.displayList();
    ist.displayReverse();

    CharList l(ist);

    ist.~CharList();

    l.displayList();
}
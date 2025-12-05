#include "LinkedList.h"
#include <iostream>

int main(){

    LinkedList<int> l1;

    l1.pushBack(10);
    l1.pushFront(20);
    l1.pushFront(40);
    l1.pushFront(110);
    l1.pushFront(30);

    std::cout << l1.size() << std::endl;


    l1.toString();

    return 0;

}
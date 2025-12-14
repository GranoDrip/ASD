#include <iostream>
#include <cassert>
#include <vector>

#include "PriorityQueue.h"
#include "../LinkedList/LinkedList.h"


int main() {
    PriorityQueue<int> pq(10);


    pq.inserisci(30);
    pq.inserisci(10);
    pq.inserisci(20);
    pq.inserisci(40);
    pq.inserisci(1);
    pq.inserisci(50);


    pq.toString();

    std::cout << "Minimo: " << pq.min() << std::endl;

    pq.cancellaMin();

    pq.toString();

    // Provo ad usare una PQ per ordinare n liste

    std::cout << "\n\n\n\n\n\nMERGE DI N LISTE CON PQ" << std::endl;


    PriorityQueue<int> cool(20);
    std::vector<int> merged;


    LinkedList<int> l1;
    l1.pushFront(9);
    l1.pushFront(7);
    l1.pushFront(5);
    l1.pushFront(3);
    l1.pushFront(1);

    LinkedList<int> l2;
    l2.pushFront(2);
    l2.pushFront(4);
    l2.pushFront(6);
    l2.pushFront(8);
    l2.pushFront(10);

    LinkedList<int> l3;
    l3.pushFront(6);
    l3.pushFront(11);
    l3.pushFront(31);
    l3.pushFront(90);
    l3.pushFront(17);

    l1.selectionSort();
    l2.selectionSort();
    l3.selectionSort();

    for (int i = 0; i < l1.size(); i++)
    {
        cool.inserisci(l1.getAt(i));
    }

    
    for (int i = 0; i < l2.size(); i++)
    {
        cool.inserisci(l2.getAt(i));
    }
    
    for (int i = 0; i < l3.size(); i++)
    {
        cool.inserisci(l3.getAt(i));
    }
    
    while (!cool.isEmpty())
    {
        merged.push_back(cool.min());
        cool.cancellaMin();
    }

    for (int x : merged) {
        std::cout << x << " ";
    }    


    return 0;
}
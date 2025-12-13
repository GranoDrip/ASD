#include <iostream>
#include <cassert>
#include "PriorityQueue.h"

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

    return 0;
}
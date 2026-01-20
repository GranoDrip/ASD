#include "GrafoMatrix.h"
#include "../LinkedList/LinkedList.h"
#include <iostream>

int main() {

    GrafoMatrix<char, int> grafo(5);
    int cost = 0;
    
    NodoGrafo a(0), b(1), c(2), d(3);

    // 3. Inseriamo i nodi con etichette
    grafo.insertNode(a, 'A');
    grafo.insertNode(b, 'B');
    grafo.insertNode(c, 'C');
    grafo.insertNode(d, 'D');

    grafo.insertEdge(a,b,5);
    grafo.insertEdge(b,c,5);
    grafo.insertEdge(c,d,5);


    std::cout << "--- Matrice di Adiacenza ---" << std::endl;
    grafo.toString();

    // 5. Preparazione per la DFS
    LinkedList<NodoGrafo> v1;
    LinkedList<NodoGrafo> v2;



    grafo.DFS(a,v1);


    grafo.findPath(a,d,v2,cost);

    std::cout << "\n" << cost;

    return 0;
}
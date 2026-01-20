#include "GrafoMatrix.h"
#include "../LinkedList/LinkedList.h"
#include <iostream>

int main() {

    GrafoMatrix<char, int> grafo(10);
    int cost = 0;

    // Nodi
    NodoGrafo a(0), b(1), c(2), d(3), e(4),
              f(5), g(6), h(7), i(8);

    // Inserimento nodi
    grafo.insertNode(a, 'A');
    grafo.insertNode(b, 'B');
    grafo.insertNode(c, 'C');
    grafo.insertNode(d, 'D');
    grafo.insertNode(e, 'E');
    grafo.insertNode(f, 'F');
    grafo.insertNode(g, 'G');
    grafo.insertNode(h, 'H');
    grafo.insertNode(i, 'I');

    // Archi (grafo direzionato)
    grafo.insertEdge(a, b, 2);
    grafo.insertEdge(a, c, 3);

    grafo.insertEdge(b, d, 4);
    grafo.insertEdge(b, e, 1);

    grafo.insertEdge(c, f, 2);

    grafo.insertEdge(d, g, 3);
    grafo.insertEdge(d, h, 5);

    grafo.insertEdge(e, h, 2);

    grafo.insertEdge(f, g, 4);
    grafo.insertEdge(f, i, 6);

    // Stampa grafo
    std::cout << "--- GRAFO ---" << std::endl;
    grafo.toString();

    // Liste visitati
    LinkedList<NodoGrafo> visitedDFS;
    LinkedList<NodoGrafo> visitedBFS;
    LinkedList<NodoGrafo> visitedPath;

    // DFS
    std::cout << "\nDFS:" << std::endl;
    grafo.DFS(a, visitedDFS);

    // Ricerca path A -> D
    std::cout << "\n\nPATH da A a D:" << std::endl;
    cost = 0;
    if (grafo.findPath(a, d, visitedPath, cost)) {
        std::cout << "\nCosto totale: " << cost << std::endl;
    } else {
        std::cout << "Percorso non trovato" << std::endl;
    }

    // BFS
    std::cout << "\nBFS:" << std::endl;
    grafo.BFS(a, visitedBFS);

    return 0;
}

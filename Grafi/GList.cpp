#include "GrafoList.h"
#include <iostream>

int main() {
    // Creazione del grafo con massimo 10 nodi
    GraphList<int, int> g(10);

    GraphNode g1, g2, g3, g4;

    // --- INSERIMENTO DEI NODI ED ARCHI ---
    g.insertNode(g1, 5);  // ID: 0
    g.insertNode(g2, 10); // ID: 1
    g.insertNode(g3, 15); // ID: 2
    g.insertNode(g4, 20); // ID: 3

    g.insertEdge(g1, g2, 1); // 0 -> 1
    g.insertEdge(g1, g3, 1); // 0 -> 2
    g.insertEdge(g3, g4, 2); // 2 -> 3
    g.insertEdge(g2, g3, 3); // 1 -> 2

    std::cout << "--- Struttura Iniziale ---" << std::endl;
    g.toString();

    // --- TEST UTILITY DI ESISTENZA ---
    std::cout << "\n--- Verifica Esistenza ---" << std::endl;
    if (g.existsNode(g4)) {
        std::cout << "Il nodo g4 esiste correttamente." << std::endl;
    }
    if (g.existsEdge(g1, g2)) {
        std::cout << "L'arco g1 -> g2 esiste correttamente." << std::endl;
    }

    // --- TEST RIMOZIONE ARCO ---
    std::cout << "\n--- Rimozione Arco g1 -> g3 ---" << std::endl;
    g.removeEdge(g1, g3); // Rimuove il collegamento tra 0 e 2
    
    std::cout << "Archi totali dopo rimozione arco: " << g.getNumEdges() << " (Atteso: 3)" << std::endl;
    if (!g.existsEdge(g1, g3)) {
        std::cout << "Confermato: l'arco g1 -> g3 non esiste piu'." << std::endl;
    }

    // --- TEST RIMOZIONE NODO ---
    // Ricorda: rimuovere g2 deve cancellare:
    // 1. L'arco uscente g2 -> g3
    // 2. L'arco entrante g1 -> g2
    std::cout << "\n--- Rimozione Nodo g2 (ID 1) ---" << std::endl;
    g.removeNode(g2);

    std::cout << "Nodi totali: " << g.getNumNodes() << " (Atteso: 3)" << std::endl;
    std::cout << "Archi totali: " << g.getNumEdges() << " (Atteso: 1, rimasti solo g3 -> g4)" << std::endl;

    // --- STAMPA FINALE PER VERIFICA ---
    std::cout << "\n--- Struttura Finale ---" << std::endl;
    g.toString();

    // Verifica manuale della lista nodi rimasti
    std::cout << "\nNodi ancora presenti (ID): ";
    LinkedList<GraphNode> rimasti = g.getNodes();
    for (int i = 0; i < rimasti.size(); i++) {
        std::cout << rimasti.getAt(i).getGraphNodeId() << " "; 
    }
    std::cout << std::endl;

    return 0;
}
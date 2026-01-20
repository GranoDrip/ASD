/*
    Implementazione del grafo con matrice di adiacenza
    Grafo PESATO e DIREZIONATO
*/

#include "Grafo.h"
#include "../LinkedList/LinkedList.h"
#include <iostream>

#ifndef GRAFOMATRIX_H
#define GRAFOMATRIX_H

// Classe che rappresenta le informazioni di un arco (collegamento tra nodi).
// Template P: tipo del peso dell'arco.
template <class P>
class InfoArco{
    public:
        P peso; // Peso associato all'arco ( costo del cammino ).
        bool vuoto; // Flag che indica se l'arco è presente (true se non esiste).

        // Costruttore: inizializza l'arco come vuoto.
        InfoArco(){
            vuoto = true;
        }
};

// Classe che rappresenta le informazioni di un nodo del grafo.
// Template E: tipo dell'etichetta (contenuto informativo del nodo).
// Template P: tipo del peso degli archi (usato per la matrice di adiacenza).
template <class E, class P>
class InfoNodo{
public:
    E etichetta; // Etichetta del nodo (es. nome o valore informativo).
    bool vuoto; // Flag che indica se il nodo è presente (true se non esiste).
    void* info; // Puntatore a informazioni aggiuntive (opzionale, attualmente non usato).
    InfoArco<P>* archi; // Array di InfoArco<P> che rappresenta la matrice di adiacenza per questo nodo (uno per ogni possibile nodo destinazione).

    // Costruttore: inizializza il nodo come vuoto e info a nullptr.
    InfoNodo(){
        info = nullptr;  // Corretto da 0 a nullptr per modernità.
        vuoto = true;
    }

    // Distruttore: libera la memoria dell'array di archi se il nodo non è vuoto.
    ~InfoNodo(){
        if (!vuoto)
        {
            delete [] archi;  // Dealloca l'array dinamico di archi.
        }
    }
};

// Classe che rappresenta un identificatore di nodo nel grafo.
// Utile per gestire ID numerici dei nodi.
class NodoGrafo{
    private:
        int nodoId;  // ID univoco del nodo (intero positivo).

    public:

        NodoGrafo(){};

        // Costruttore: inizializza l'ID del nodo.
        NodoGrafo(int id){
            nodoId = id;
        }

        // Getter: restituisce l'ID del nodo.
        int getId() const {
            return nodoId;
        }

        // Setter: imposta un nuovo ID per il nodo.
        void setId(int id){
            nodoId = id;
        }

        // Operatore == (Necessario per searchElement della LinkedList)
        bool operator==(const NodoGrafo& other) const {
            return this->nodoId == other.nodoId;
        }

        // Operatore << (Necessario per toString della LinkedList)
        friend std::ostream& operator<<(std::ostream& os, const NodoGrafo& n) {
            os << n.nodoId;
            return os;
        }
};

template <class E, class P>
class GrafoMatrix : public Grafo<E,P,NodoGrafo>{

    private:
        InfoNodo<E,P>* matrice; // Matrice di adiacenza
        int dimensione; // Dimensione della matrice ( Numero MAX di nodi che può ospitare )
        int nodi; // Numero di nodi
        int archi; // Numero di archi
    public:

        GrafoMatrix(int d){
            dimensione = d;
            nodi = 0;
            archi = 0;
            matrice = new InfoNodo<E,P>[dimensione];
            
            for (int i = 0; i < dimensione; i++){
                matrice[i].archi = new InfoArco<P>[dimensione];
            }
        }

        
        ~GrafoMatrix(){
            delete [] matrice;
        }

        /* ======== GETTERS ========== */

        bool isEmpty() const override{
            return (nodi == 0);
        }

        int getNumEdges() const override{
            return archi;
        }

        int getNumNodes() const override{
            return nodi;
        }

        LinkedList<NodoGrafo*> getAdjacentNodes(NodoGrafo n) const override {
            LinkedList<NodoGrafo*> list;
        
            for (int i = 0; i < dimensione; i++) {
                // Se l'arco esiste nella matrice di adiacenza
                if (!matrice[n.getId()].archi[i].vuoto) {
                    // Creiamo un nuovo puntatore a NodoGrafo
                    list.pushBack(new NodoGrafo(i));
                    }           
                }

            return list;
        }

        LinkedList<NodoGrafo> getNodes() const override{
            LinkedList<NodoGrafo> list; // Lista di nodi

            for (int i = 0; i < dimensione; i++)
            {
                if (!matrice[i].vuoto) // Se il nodo esiste
                {
                    list.pushBack(NodoGrafo(i)); // Allora aggiungo alla lista
                }           
            }

            return list; 
        }

        E getNodeLabel(NodoGrafo n) const override{
            return matrice[n.getId()].etichetta;
        }

        P getEdgeWeight(NodoGrafo n1, NodoGrafo n2) const override{
            return matrice[n1.getId()].archi[n2.getId()].peso;
        }


        /* ======= INSERIMENTO ===========*/

        void insertNode(NodoGrafo& newnode, E label) override{
            int n = 0;
            if (nodi < dimensione)
            {
                while (matrice[n].vuoto == false)
                {
                    n++;
                }
                nodi++;
                
            }
            newnode.setId(n);
            matrice[n].etichetta = label;
            matrice[n].vuoto = false;
        }

        void insertEdge(NodoGrafo from, NodoGrafo to, P peso) override{
	        matrice[from.getId()].archi[to.getId()].peso = peso;
	        matrice[from.getId()].archi[to.getId()].vuoto = false;
            archi++;
        }

        /* ====== CANCELLAZIONE ========= */

        void removeNode(NodoGrafo n) override {

            bool canc = true;
            int i;
            for (i = 0; i < dimensione && canc; i++)
            {
                if (!matrice[n.getId()].archi[i].vuoto)
                {
                    canc = false;
                }
            }

            for (i=0; i < dimensione && canc; i++) 
            {
                if (!matrice[i].vuoto && !matrice[i].archi[n.getId()].vuoto)
                {
                    canc = false;
                }
            }

            if (canc)
            {
                delete[] matrice[n.getId()].archi;
                matrice[n.getId()].vuoto = true;
                nodi--;
            }   
        }

        void removeEdge(NodoGrafo n1, NodoGrafo n2) override{
            matrice[n1.getId()].archi[n2.getId()].vuoto = true;
            archi--;
        }
        
        /* ======= SETTERS ========== */
        
        void setNodeLabel(NodoGrafo n, E label) override{
            matrice[n.getId()].etichetta = label;
        }

        void setEdgeWeight(NodoGrafo n1, NodoGrafo n2, P weight) override{
            matrice[n1.getId()].archi[n2.getId()].peso = weight;
        }

        /* ====== ALGORITMI DI VISITA ======= */

        void DFS(NodoGrafo start, LinkedList<NodoGrafo>& visited) {

            std::cout << matrice[start.getId()].etichetta << "\n"; // Stampo il nodo che sto visitando
            visited.pushBack(start); // Lo visito

            // Aquisico i suoi adiacenti e me li salvo
            LinkedList<NodoGrafo*> adjList = getAdjacentNodes(start); 
        
            // Per ogni adiacente verifico se è già stato visitato, in alternativa lo visito ricorsivamente
            for (int i = 0; i < adjList.size(); i++) {

                NodoGrafo adjNode = *(adjList.getAt(i)); // "Primo" nodo adiacente
            
                // SE NON è STATO VISITATO ALLORA VISITO
                if (!visited.existsNode(adjNode)) { 
                    DFS(adjNode, visited);
                }
            } 
        }

        /*  Usando la DFS Ricorsiva calcolo il percorso
            da un nodo verso un altro, calcolando anche il costo 
            del cammino
         */
        bool findPath(NodoGrafo start, NodoGrafo target, LinkedList<NodoGrafo>& visited, int& cost){

            // Visito start
            visited.pushBack(start);

            // Caso Base
            // La destinazione è raggiunta
            if (start.getId() == target.getId()){
                std::cout << matrice[start.getId()].etichetta;
                return true;
            }

            // Caso ricorsivo
            LinkedList<NodoGrafo*> adjList = getAdjacentNodes(start); 
        
            // Per ogni adiacente verifico se è già stato visitato, in alternativa lo visito ricorsivamente
            for (int i = 0; i < adjList.size(); i++) {

                NodoGrafo adjNode = *(adjList.getAt(i)); // "Primo" nodo adiacente
            
                // SE NON è STATO VISITATO ALLORA VISITO
                if (!visited.existsNode(adjNode)) { 
                    if (findPath(adjNode,target,visited,cost))
                    {
                        cost += matrice[start.getId()].archi[adjNode.getId()].peso;
                        std::cout << " <- " << matrice[start.getId()].etichetta;
                        return true;
                    }
                }
            } 

            return false;

        }

        void BFS(NodoGrafo start, LinkedList<NodoGrafo>& visited) {
            LinkedList<NodoGrafo> queue; // Coda per i nodi da visitare
            queue.pushBack(start);

            while (!queue.isEmpty()) {
                NodoGrafo currentNode = queue.getAt(0); // Prendi il primo nodo dalla coda
                queue.removeAt(0); // Rimuovi il nodo dalla coda

                // Aggiungi il nodo corrente alla lista dei visitati
                if (visited.searchElement(currentNode) == -1) {
                    visited.pushBack(currentNode);
                }

                // Esplora i nodi adiacenti
                for (int i = 0; i < dimensione; i++) {
                    if (!matrice[currentNode.getId()].archi[i].vuoto) { // Se esiste un arco verso il nodo i
                        NodoGrafo adjacentNode(i);
                        // Controlla se il nodo adiacente è già stato visitato
                        if (visited.searchElement(adjacentNode) == -1) {
                            queue.pushBack(adjacentNode); // Aggiungi alla coda per la visita futura
                        }
                    }
                }
            }
        }


        /* ======== toString ============ */
        void toString() const {
            for (int i = 0; i < dimensione; i++) {
                // Controllo se il nodo sorgente esiste
                if (!matrice[i].vuoto) {
                    std::cout << "[" << matrice[i].etichetta << "] : "; // Stampa l'etichetta del nodo
                    
                    for (int j = 0; j < dimensione; j++) {
                        // Se esiste un arco verso il nodo j
                        if (!matrice[i].archi[j].vuoto) {
                            // Stampa il peso dell'arco e l'etichetta del nodo di destinazione
                            std::cout << " --(" << matrice[i].archi[j].peso << ")--> " << matrice[j].etichetta << "  ";
                        }
                    }
                    std::cout << std::endl;
                }
            }
        }

};

#endif
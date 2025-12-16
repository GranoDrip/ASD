/**
 * GrafoList.h
 * Implementazione concreta di un grafo tramite lista di adiacenza.
 *
 * Nodo: tipo del nodo
 * Peso: tipo del peso sugli archi
 * Etichetta: tipo dell'informazione associata a ciascun nodo
 *
 * La classe implementa tutte le funzioni dell'interfaccia Grafo,
 * sfruttando LinkedList per memorizzare i nodi adiacenti.
 */


#ifndef GRAFO_LIST_H
#define GRAFO_LIST_H

#include "Grafo.h"

/** GraphNode
 * 
 * Rappresenta l'identità di un nodo nel grafo tramite un ID.
 * Contiene costruttori, getter e setter per accedere o modificare l'ID.
 */
class GraphNode{
    private:
        int nodoId;
    
    public:
    // Costruttori
        GraphNode(int i){
            nodoId = i;
        };

        GraphNode(){

        };
    // Getter e setter

        int getGraphNodeId(){
            return nodoId;
        };

        void setGraphNodeId(int val){
            nodoId = val;
        };

};


/** InfoArco
 * 
 * Rappresenta un arco uscente da un nodo del grafo.
 * Contiene il peso dell'arco e il nodo di destinazione (to).
 */
template <class P>
class InfoArco{
    public:
    P peso;
    GraphNode to; // Nodo di destinazione
};


/** InfoNodo
 * 
 * Contiene le informazioni associate a un nodo del grafo.
 * Include l'etichetta del nodo, un flag per indicare se è utilizzato,
 * e una lista degli archi uscenti verso altri nodi.
 */
template<class E, class P> 
class InfoNodo{
    public:
        E etichetta; // Contenuto informativo associato al nodo
        bool vuoto; // Indica se il nodo è occupato o libero
        LinkedList<InfoArco<P>> archi; // Lista degli archi uscenti dal nodo

        InfoNodo(){ 
            vuoto = true; 
        }
};


/** GraphList
 * 
 * Implementazione concreta di un grafo tramite lista di adiacenza.
 * 
 * E: tipo dell'etichetta associata ai nodi
 * P: tipo del peso degli archi
 * Utilizza GraphNode per identificare i nodi e LinkedList<InfoArco<P>> per memorizzare gli archi uscenti.
 */
template<class E, class P>
class GraphList: public Grafo<E,P,GraphNode>{
    private:
        int nNodi; // Numero di nodi
        int nArchi; // Numero di archi
        int maxNodi; // Numero totale di nodi
        InfoNodo<E,P>* nodi; // Nodi

    public:

        // === Costruttore e distruttore ===

        // Costruttore 
        GraphList(int max) {
            nNodi = 0;
            nArchi = 0;
            maxNodi = max;
            nodi = new InfoNodo<E,P>[maxNodi];
        
            // Inizializzazione lista di nodi
            for (int i = 0; i < maxNodi; i++) {
                nodi[i].vuoto = true; // nodo libero
                nodi[i].archi = LinkedList<InfoArco<P>>(); // lista di archi vuota
            }
        }

        // Distruttore
        ~GraphList() {
            delete[] nodi;
        }

        // Getters e controlli base
        bool isEmpty() const override{
            return nodi == nullptr;
        }

        // Numero di nodi
        int getNumNodes() const override{
            return nNodi;
        }

        // Numero di archi
        int getNumEdges() const override{
            return nArchi;
        }

        // Inserisce un nuovo nodo
        void insertNode(GraphNode& node) override{
            // Scorro l'array di nodi fin quando non trovo una posto libero
            for (int i = 0; i < maxNodi; i++)
            {
                // Se il nodo è vuoto
                if (nodi[i].vuoto)
                {
                    // Allora posso inserire
                    nodi[i].vuoto = false; // Imposto a false in modo da evitare la sovrascrittura
                    nodi[i].etichetta = E(); // Etichetta
                    nodi[i].archi = LinkedList<InfoArco<P>>(); // Lista di nodi adiacenti
                    nNodi++; // Incremento il numero di nodi
                    return; // Ho inserito allora esco
                }   
            }            
        }

        void insertEdge(GraphNode from, GraphNode to, P weight) override{

            // Scorro per trovare il nodo di partenza ( n1 )
            for (int i = 0; i < maxNodi; i++)
            {
                if (!nodi[i].valido && nodi[i].etichetta == from.getGraphNodeId());
                {
                    /* code */
                }
                
            }
            

        }


        void toString() const {
            for (int i = 0; i < maxNodi; i++) {
                if (!nodi[i].vuoto) {
                    std::cout << "Nodo " << nodi[i].etichetta << ": ";
                
                    // Scorri la lista di archi
                    LinkedList<InfoArco<P>>& archi = nodi[i].archi;
                    ListNode<InfoArco<P>>* curr = archi.head; // assuming head è pubblico
                    while (curr != nullptr) {
                        std::cout << "(to: " << curr->val.to.getGraphNodeId()
                                  << ", peso: " << curr->val.peso << ") ";
                        curr = curr->next;
                    }
                    std::cout << "\n";
                }
            }
}


    };


#endif

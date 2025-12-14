/*
 * Implementazione di una Priority Queue tramite un heap.
 * Una coda con priorità è una struttura dati che mantiene gli elementi
 * ordinati in base a una relazione di priorità.
 *
 * Nello specifico in questa implementazione la relazione che seguo è
 * heap[padre(i)] <= heap[i]
 * Il padre di i è sempre minore uguale ad i.
 * 
 */

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>

template <class T>
class PriorityQueue{

    private:
        int MAXLEN; // Lunghezza dell'array
        T* heap; // Array di nodi
        int ultimo; // Conta il numero di elementi nell'array heap, serve a capire dove inserire il prossimo nodo

        /** FIXUP()
        * Risale l'elemento appena inserito nell'heap per ripristinare la proprietà di min-heap
        * 
        * Come è stato fatto in BinaryTreeArray.h, gli indici sono rappresentati in base 1 quindi:
        *   - Il padre di un nodo lo si ottiene con i/2
        *   - Figlio sx: 2i
        *   - Figlio dx: 2i + 1
        * 
        * La funzione confronta il nodo con il suo genitore e li scambia
        * finché (heap[padre(i)] <= heap[i]) non è rispettata.
        */
        void fixUp(){
            int i = ultimo; // posizione dell'elemento appena inserito (base 1)
            T tmp = heap[i - 1]; // salva l'elemento da inserire

            int p = i / 2; // indice del genitore (base 1)

            while (i > 1 && tmp < heap[p - 1]) {
                heap[i - 1] = heap[p - 1]; // sposta il genitore giù
                i = p;
                p = i / 2;
            }
            heap[i - 1] = tmp; // inserisci nella posizione corretta
        }
    
        /** fixDown(k, N):
        *
        * - k: indice (base 1) del nodo da far scendere
        * - N: indice (base 1) dell'ultimo elemento valido dell'heap
        *
        * Funzionamento:
        * 1. Confronta il nodo con i suoi figli.
        * 2. Se uno dei figli è più piccolo, scambia con il figlio più piccolo.
        * 3. Ripeti finché arrivi a una foglia o il nodo è più piccolo di entrambi i figli.
        */
        void fixDown(int k, int N){
            int scambio = 1; 

            // Continua finché k non è una foglia (k <= N / 2) e l'elemento è fuori posto.
            while (k <= N / 2 && scambio) {
                int j = 2 * k; // Figlio sinistro
            
                // Trova il figlio minore (j)
                if (j < N && heap[j] < heap[j - 1])
                    j++; 
            
                // Scambio: verifica se il figlio minore è < del genitore, e assegna il risultato a 'scambio'
                if (scambio = (heap[j - 1] < heap[k - 1])) {
                    T tmp = heap[k - 1];
                    heap[k - 1] = heap[j - 1];
                    heap[j - 1] = tmp;
                    // Continua la discesa dal figlio minore
                    k = j;
                }
            }
        }

    public:

        PriorityQueue(int len){
            MAXLEN = len;
            heap = new T[MAXLEN];
            ultimo = 0;
        };

        void inserisci(T element){
            assert(ultimo < MAXLEN);
            ultimo++;
            heap[ultimo - 1] = element; // inserisci in heap[ultimo-1] (base 0)
            fixUp();
        };

        T min(){
            assert(ultimo != 0);
            return heap[0]; // il minimo è sempre in heap[0] (base 0)
        }

        void cancellaMin (){
            assert(ultimo != 0);
            heap[0] = heap[ultimo - 1]; // sposta l'ultimo in cima
            ultimo--;
            fixDown(1, ultimo); // fixDown parte da 1 (base 1)
        }
        
        void toString(){
            if (ultimo == 0) {
                std::cout << "La Priority Queue e' vuota." << std::endl;
                return;
            }

            std::cout << "Priority Queue (Min-Heap, " << ultimo << " elementi):" << std::endl;
            std::cout << "[";
            for (int i = 0; i < ultimo; i++) { // stampa da 0 a ultimo-1
                std::cout << heap[i];
                if (i < ultimo - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << "]" << std::endl;
        }
    
        bool isEmpty(){
            return ultimo == 0;
        }

};

#endif
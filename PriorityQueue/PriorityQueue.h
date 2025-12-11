/*
 * Implementazione di una Priority Queue tramite un heap.
 * Una coda con priorità è una struttura dati che mantiene gli elementi
 * ordinati in base a una relazione di priorità (tipicamente <=).
 *
 * Anche se concettualmente è legata a un albero binario, l’heap viene
 * rappresentato usando strutture sequenziali, come un array o un vector.
 *
 * L’heap è un albero binario quasi completamente bilanciato: ogni nuovo
 * elemento viene inserito nella prima posizione libera in basso e poi
 * “risale” finché la proprietà di ordinamento non è rispettata.
 *
 * La radice dell’heap contiene sempre l’elemento con priorità minima
 * (nel caso di un min-heap), permettendo di recuperarlo in tempo O(1)
 * e di inserirne altri o rimuovere il minimo in tempo O(log n).
 */

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

template <class T>
class PriorityQueue{

    private:
        int MAXLEN;
        T* heap;
        int ultimo;

    public:
        void inserisci(T element);
        void min();
        void cancellaMin ();
            

};

#endif
// Classe List ( Astrazione per la Linked List )

#ifndef LIST_H
#define LIST_H

template <class T>
class List {
public:

    // Distruttore 
    virtual ~List() {}

    // Verifica se la lista è vuota
    virtual bool isEmpty() const = 0;
    
    // Restituisce la dimensione della lista
    virtual int size() const = 0;

    // Inserisce un elemento all'inizio
    virtual void pushFront(T e) = 0;
    // Inserisce un elemento alla fine
    virtual void pushBack(T e) = 0;
    // Inserisce un elemento in una posizione specifica
    virtual void insertAt(int index, T e) = 0;
    // Inserisce seguendo un ordinamento
    virtual void insListaOrdinata(T element) = 0;

    // Rimuove il primo elemento
    virtual void removeFront() = 0;
    // Rimuove l'ultimo elemento
    virtual void removeBack() = 0;
    // Rimuove l'elemento a un indice specifico
    virtual void removeAt(int index) = 0;
    // Svuota la lista
    virtual void erase() = 0;

    // Legge il valore a un determinato indice
    virtual T getAt(int index) const = 0;
    // Cambia il valore a un determinato indice
    virtual void changeAt(T e, int index) = 0;
    // Cerca un elemento e ne restituisce la posizione
    virtual int searchElement(T e) const = 0;

    // Rappresentazione testuale della lista
    virtual void toString() const = 0;
    // Verifica se un elemento esiste
    virtual bool existsNode(T e) const = 0;
};

#endif // LIST_H
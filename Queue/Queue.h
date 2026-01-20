/*
    Implementazione della classe Queue ( Coda ) FIFO con i seguenti metodi usando l'implementazione con Puntatori
    - enqueue() inserisce un elemento in cima alla coda
    - dequeue() estrae l'ultimo elemento in cima alla coda
    - isEmpty() Verifica che sia vuota
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

template<class T> class Queue;

template<class T>
class QNode{
   T val;
   QNode<T> * next = nullptr;
   
   friend class Queue<T>;
};



template<class T>
class Queue{
private:

    QNode<T> * first = nullptr;
    QNode<T> * last = nullptr;
    int size = 0;

public:
    Queue(){
        first = last = nullptr;
        size = 0;
    }

    ~Queue(){
        while (!isEmpty())
        {
            dequeue();
        }
        
    }

    // Inserisce un elemento in fondo alla coda
    void enqueue(T e){
        QNode<T> * node = new QNode<T>();
        node->val = e;
        node->next = nullptr;

        if (isEmpty()) {
            first = last = node;
        } else {
            last->next = node;
            last = node;
        }

        size++;
    }

    // Rimuove l'elemento in testa alla coda
    T dequeue(){
        if (isEmpty()) {
            return T(); // Non fa nulla se vuota, restituisce valore di default
        }
        QNode<T> * temp = first;

        T dato = temp->val;

        first = first->next;

        if (first == nullptr) {
            last = nullptr;
        }
        
        size--;

        delete temp;
        return dato;
    }

    T getFirst(){
        if (isEmpty()){
            return T();
        }else{

            return first->val;   

        } 
    }

    // Ritorna il numero di elementi nella coda
    int getSize(){
        return size;
    }

    // Controlla se è vuota
    bool isEmpty(){
        return first == nullptr;
    }


    void toString(){
         QNode<T> * curr = first;

        while (curr != nullptr)
        {
            std::cout << curr->val << " -> ";
            curr = curr->next;
        }

        std::cout << "END" << std::endl;
    }
    };


#endif


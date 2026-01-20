/* IMPLEMENTAZIONE LINKED LIST (SINGOLARMENTE COLLEGATA)
    
    
    == FUNZIONI INSERIMENTO ==
    - pushFront(T e): Inserisce un elemento all'inizio della lista.
    - pushBack(T e): Inserisce un elemento alla fine della lista.
    - insertAt(int index, T e): Inserisce un elemento in una posizione i.
    - insListaOrdinata(T e): Inserisce un elemento mantenendo l'ordine crescente/decrescente.

    == FUNZIONI CANCELLAZIONE ==
    - removeFront(): Elimina il primo elemento della lista.
    - removeBack(): Elimina l'ultimo elemento della lista.
    - removeAt(int index): Elimina l'elemento alla posizione specificata.
    - clear(): Svuota la lista deallocando la memoria di ogni nodo.

    == FUNZIONI ACCESSO ==
    - getAt(int index): Restituisce il valore memorizzato a un determinato indice.
    - changeAt(T e, int index): Sovrascrive all'indice .
    - searchElement(T e): Cerca un elemento e ne restituisce l'indice (-1 se non trovato).
    - existsNode(T e): Verifica se un valore è presente nella lista (restituisce bool).
    - exchange(p1, p2): Scambia i valori tra le posizioni p1 e p2 senza muovere i nodi.
    - selectionSort(): Ordina gli elementi della lista utilizzando l'algoritmo Selection Sort.

    == ALTRO  ==
    - size(): numero totale di
    - isEmpty() Verifica se ci sono nodi
    - toString(): Stampa la lista
    - reverse(): Inverte l'ordine dei nodi 
    - divide(left, right): Divide la lista a metà 
    - merge(list): Unisce la lista corrente con un'altra lista, mantenendo l'ordine
    - operator!=(list): Confronta due liste 

    =============================================================================
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include "List.h"

template<class T> class LinkedList;

template<class T> 
class ListNode{
    private:
        T val;
        ListNode<T> * next = nullptr;
    
    friend class LinkedList<T>; // Classe Amica
};

template <class T> 
class LinkedList : public List<T>{

    private:
        ListNode <T>* head = nullptr;

    public:

        // Costruttore 
        LinkedList(){
            head = nullptr;
        }
        
        // Distruttore
        ~LinkedList(){
            ListNode<T> *curr = head; // Inizializzo alla testa
            ListNode<T> *nxt; // Uso questo puntatore per il prossimo nodo 
        
            // Ciclo finché ci sono nodi da eliminare
            while (curr != nullptr) {
                nxt = curr->next; // Salvo il puntatore al nodo successivo
                delete curr; // Elimino il nodo corrente per liberare memoria
                curr = nxt; // passo al nodo successivo
            }

            // Alla fine, tutti i nodi sono stati deallocati; posso anche fare:
            head = nullptr;
        }


        // Inserisce e all'inizio della lista
        void pushFront(T e) override{
            
            ListNode<T> * newNode = new ListNode<T>();
            newNode->val = e; // Assegno il valore al nodo

            // Il nuovo nodo punta all'attuale head
            newNode->next = head; 
            
            // Aggiorno head per puntare al nuovo nodo
            head = newNode;

        }

        // Inserisco alla fine della lista
        void pushBack(T e) override {
            
            ListNode<T>  * curr = head; 
            ListNode<T>  * prec = curr; 
            ListNode<T> * newNode = new ListNode<T>(); // Nuovo nodo da inserire
            
            newNode->val = e; 

            if (isEmpty()){ 
                head = newNode;
            }else{
                while (curr != nullptr)
                {
                    prec = curr;
                    curr = curr->next;
                }

                prec->next = newNode;
                newNode->next = nullptr;
            }

        }

        // Inserisce l'elemento in una posizione specifica
        void insertAt(int index,T e) override{
            ListNode<T> * curr = head;
            ListNode<T> * tmp;

            int i = 0;

            if (!isEmpty()){

                if (index==0){
                    pushFront(e);
                }else{
                    while (curr != nullptr && i < index-1)
                    {
                        curr = curr->next;
                        i++;
                    }

                    if (curr != nullptr){
                        ListNode<T>* newNode = new ListNode<T>();
                        newNode->val = e;

                        tmp = curr->next;
                        curr->next = newNode;
                        newNode->next = tmp;
                    } 
                }       
                
            }else{
                pushFront(e);
            }
       }
        

        // Rimuove il nodo all'inizio
        void removeFront() override{

            ListNode<T> * toDelete;

            if (!isEmpty()){
                toDelete = head;
                head = head->next;
                delete toDelete;            
            }

        }

        // Rimuove il nodo alla fine della lista
        void removeBack() override {

            ListNode<T> * curr = head;
            ListNode<T> * prec = head;

            if (!isEmpty())
            {

                if(head->next == nullptr){
                    delete head;
                    head = nullptr;
                }
                else{
                    while (curr->next != nullptr) {
                        prec = curr;
                        curr = curr->next;
                    }

                    prec->next = nullptr;
                    delete curr;  
                }

            }
            
        }

        // Rimuove il nodo ad un determinato indice 
        void removeAt(int index) override {
            ListNode<T> * curr = head;
            ListNode<T> * prec = head;
            int i = 0;

            if (!isEmpty()){
                if (index == 0){
                    removeFront();
                }else{

                    while (curr != nullptr && i < index)
                    {
                        i++;
                        prec = curr;
                        curr = curr->next;
                    }

                    prec->next = curr->next;
                    delete curr;
                    
                }
            }
        }

        // Ricerca lineare di un elemento
        int searchElement(T e) const override{

            ListNode<T> * curr = head;
            int index = -1;
            bool trovato = false;

            if (!isEmpty()){
                while (curr != nullptr)
                {
                    if(curr->val == e){
                        trovato = true;
                    }
                    index++;
                    curr = curr->next;
                }

            }
            
            
            return index;

        }

        // Selection Sort
        void selectionSort() {

            ListNode<T> * i = head;
            ListNode<T> * j = head;
            T tmp;

            while (i != nullptr)
            {
                while (j != nullptr)
                {
                    if (i->val > j->val)
                        tmp = i->val;
                        i->val = j->val;
                        j->val = tmp;

                    j = j->next;
                }

                i = i->next;                
            }
            
        }
        
        // Modifica il valore in un determinato indice
        void changeAt(T e,int index) override{
            ListNode<T> * curr = head;
            int i = 0;

            if (!isEmpty()){
                while (curr->next != nullptr && i < index)
                {
                    curr = curr->next;
                    i++;
                }

                    curr->val = e;                    
            }            
        }

        // Ritorna il valore ad un indice
        T getAt(int index) const override{
            ListNode<T> * curr = head;
            int i = 0;

            if (!isEmpty()){
                while (curr->next != nullptr && i < index)
                {
                    curr = curr->next;
                    i++;
                }                
            }

            return curr->val;
        }

        // Svuota la lista
        void erase() override {
            ListNode<T>* curr = head;
            ListNode<T>* nextNode;
        
            while (curr != nullptr) {
                nextNode = curr->next;
                delete curr;
                curr = nextNode;
            }
            head = nullptr;
        }

        // Stampa la lista
        void toString() const override{
            ListNode<T> * curr = head;

            while (curr != nullptr)
            {
                std::cout << curr->val << " -> ";
                curr = curr->next;
            }

            std::cout << "FINE" << std::endl;
        }

        // Inverte una LL
        void reverse(){

            ListNode<T> * curr = head;
            ListNode<T> * next;
            ListNode<T> * prev = nullptr;

            if (!isEmpty()){
                while (curr != nullptr)
                {
                    next = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = next;
                }
                
            }

            head = prev;
        }

        // Inserisce l'elemento seguendo un ordinamento
        void insListaOrdinata(T element) override{
            ListNode<T> * curr = head;
            ListNode<T> * prev = nullptr;
            ListNode<T>* newNode = new ListNode<T>();
            newNode->val = element;

            // Cambia qui per ordinamento crescente (<) o decrescente (>) 
            
            // Ordinamento crescente:
            
            // Qui vado avanti fin quando non trovo elemento più grande
            while (curr != nullptr && curr->val < element) {
                prev = curr;
                curr = curr->next;
            }

            // Questo è l'inserimento in testa
            if (prev == nullptr) {
                newNode->next = head;
                head = newNode;
            // Questo è l'inserimento in mezzo 
            } else {
                newNode->next = curr;
                prev->next = newNode;
            }
        }


        // Verifica se esiste un nodo
        bool existsNode(T e) const{
            ListNode<T>* curr = head;
        
            // Scorro la lista finche non finisce
            while (curr != nullptr) {
                // SE il valore del nodo corrente è uguale a quello cercato
                if (curr->val == e) {
                    return true; // ALLORA Elemento trovato
                }
                curr = curr->next; // Passa al nodo successivo
            }
        
            // Se il ciclo finisce senza aver ritornato true, l'elemento non c'è
            return false;
        }

        // Controllo se la lista è vuota
        bool isEmpty() const override{
            return head==nullptr;
        }

        // Merge di questa e un altra lista
        LinkedList merge(LinkedList<T> * list){ 
            LinkedList<T> result = LinkedList<T>(); // Creiamo la lista 

            ListNode<T> * curr1 = head; // Nodo che scorre la lista 1
            ListNode<T> * curr2 = list->head; // Nodo che scorre la lista 2

            // Finche uno dei due non finisce
            while (curr1 && curr2)
            {
                // Se curr1 è > curr2 allora lo inserisce alla fine della lista
                if (curr1->val < curr2->val){
                    result.pushBack(curr1->val);
                    curr1 = curr1->next; // Mando avanti c1 perche è stato inserito
                }else{
                    result.pushBack(curr2->val);
                    curr2 = curr2->next; // Mando avanti c2 perche è stato inserito
                }
            }

            // Adesso una delle due liste sarà sicuramente vuota quindi inserisco
            // i nodi rimanenti all'interno della lista risultato.
            while (curr1 != nullptr)
            {
                result.pushBack(curr1->val);
                curr1 = curr1->next;
            }
            
            while (curr2 != nullptr)
            {
                result.pushBack(curr2->val);
                curr2 = curr2->next;
            }
            
            return result; // Ritorno risultato 

        }
    
        // Divide 
        void divide(LinkedList<T> * left, LinkedList<T> * right ){

            if (head == nullptr || head->next == nullptr) {
                left->head = head;
                right->head = nullptr;
                return;
            }

            ListNode<T> * slow = head;
            ListNode<T> * fast = head;
            ListNode<T>* prec = nullptr;

            while (fast != nullptr && fast->next != nullptr)
            {
                prec = slow;
                slow = slow->next;
                fast = fast->next->next;
            }

            if (prec != nullptr)
                prec->next = nullptr;

            left->head = head;
            right->head = slow;

        }

        // Ritorno la lunghezza della lista
        int size() const override{

            ListNode<T> * curr = head;
            int c = 0;

            while (curr != nullptr)
            {
                curr = curr->next;
                c++;
            }

            return c;            
        }

        // Override dell'operatore 
        bool operator!=(const LinkedList& l) const {
            
            // Se la lunghezza è diversa sono diverse => return vero
            if(this->size() != l.size()){
                return true;
            }

            // INIZIALIZZA QUI
            ListNode<T> * curr1 = this->head;
            ListNode<T> * curr2 = l.head;

            while(curr1 != nullptr){

                if(curr1->val != curr2->val){
                    
                    return true; // Ritorna vero quando sono diverse

                }else{

                    curr1 = curr1->next; 
                    curr2 = curr2->next; 
                }

            }
            return false;
            
        } 

        // exchange(p1, p2): scambia l'elemento in posizione p1 con quello in posizione p2
        void exchange(int p1, int p2){

            if (isEmpty() || p1 == p2) {
                return;
            }

            ListNode<T> * curr = head;
            ListNode<T> * nodeP1 = nullptr;
            ListNode<T> * nodeP2 = nullptr;
            int index = 0;

            while (curr != nullptr && (nodeP1 == nullptr || nodeP2 == nullptr)) {
                if (index == p1) {
                    nodeP1 = curr;
                }
                if (index == p2) {
                    nodeP2 = curr;
                }
                index++;
                curr = curr->next;
            }

            // Se non sono vuoti
            if (nodeP1 != nullptr && nodeP2 != nullptr) {
                T tmp = nodeP1->val;
                nodeP1->val = nodeP2->val;
                nodeP2->val = tmp;
            }
        }


};

#endif
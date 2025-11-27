/* ============================================================
 *  ALBERO BINARIO (Binary Tree) Implementazione sequenziale con ARRAY
 *  
 *  Implementazione di un albero binario con array utilizzando
 *  la classe astratta BinaryTree.h
 * 
 * ============================================================ */


#ifndef BT_ARRAY_H
#define BT_ARRAY_H

#include <iostream>
#include "BinaryTree.h"

// Trattandosi di una implementazione sequenziale definisco il massimo di elementi
#define MAX 32

template <class T>
class BinaryTreeArray : public BinaryTree<T,int>{
    
    private:
        // Nodi dell'albero
        T nodes[MAX];

        // Array parallelo di booleani, ci dice se sono disponibili
        bool valid[MAX];

        // Numero di nodi
        int size;

        void printSubTree(int nodeIndex) const override {

            std::cout << "[" << nodes[nodeIndex] << ", ";

            int left = 2*nodeIndex + 1;
            int right = 2*nodeIndex + 2;

            // Figlio sinistro
            if (left < size)
                printSubTree(left);
            else
                std::cout << "NIL";

            std::cout << ", ";

            // Figlio destro
            if (right < size)
                printSubTree(right);
            else
                std::cout << "NIL";

            std::cout << "]";
}


    public:

        // Costruttore
        BinaryTreeArray(){
            int i = 0;
            
            for (i = 0; i < MAX; i++){
                valid[i] = false;
            }

            size = 0;         
        }

        // Ritorna l'indice della radice
        int getRoot() const override{

            if (!isEmpty()){
                int i;
                for (i=0; i < MAX && valid[i]; i++); // Al primo valido trovato si ferma => radice trovata
                return i;
            }else{
                return -1;
            }

        }

        // Ritorna l'indice di nodo a SINISTRA di un NODO dato
        int getSx(int nodeIndex) const override{
            if (nodeIndex >= 0 && nodeIndex < MAX && valid[nodeIndex]){
                if (!sxEmpty(nodeIndex))
                {
                    return nodeIndex*2+1;   
                }
            }

            return -1;
        }

        // Ritorna l'indice di nodo a DESTRA di un NODO dato
        int getDx(int nodeIndex) const override{
            
            if (nodeIndex >= 0 && nodeIndex < MAX && valid[nodeIndex]){
                if (!dxEmpty(nodeIndex))
                {
                    return nodeIndex*2+2;   
                }
            }

            return -1;
        }            


        // Inserisce la Radice
        void insRoot(T val) override{
            if (isEmpty())
            {
                nodes[0] = val;
                valid[0] = true;
                size++;
            }
        }

        // Inserisce il nodo a SX dato un indice
        void insSx(int index, T val) override{

            int child = 2 * index + 1;

            if (sxEmpty(index) && child < MAX)
            {
                nodes[child] = val;
                valid[child] = true;
                size++;
            }   
        }

        // Inserisce il nodo a DX dato un indice
        void insDx(int index, T val) override{

            int child = 2 * index + 2;

            if (dxEmpty(index) && child < MAX)
            {
                nodes[child] = val;
                valid[child] = true;
                size++;
            }   
        }

        // Ritorna il VALORE di un nodo
        T read(int index) const override{
            if (valid[index] && index < MAX && index >= 0)
            {
                return nodes[index];
            }
            
            return T{}; // Valore default vuoto 
        }

        // Sovrascrive il valore di un nodo
        void write(int index, T val ){
            if (valid[index] && index < MAX && index >= 0)
            {
                nodes[index] = val;
            }
        }

        /* Verifica che il BT sia vuoto
        *
        *   Ritorna VERO quando è vuoto
        *   Ritorna FALSO quando ha almeno la radice
        */ 
        bool isEmpty() const override{
            int i = 0;

            for (i=0;i<MAX;i++){

                if(valid[i]){ // Se c'è almeno un nodo TRUE allora esiste almeno la radice quindi NON è vuoto
                    return false;
                }

            }

            return true; // Altrimenti è vuoto;
        }

        // Verifica se un nodo ha figli a destra o a sinistra
        // Funzione per i nodi di dx: 2*i + 1
        // Funzione per i nodi di sx: 2*1 + 2
        bool sxEmpty(int nodeIndex) const override{

            if (nodeIndex >= 0 && nodeIndex < MAX && valid[nodeIndex])
            {
                int child = 2 * nodeIndex + 1; // Indice del nodo figlio

                if (child < MAX && valid[child])
                {
                    return false;
                }
                
            }
            
            return true;
        }

        bool dxEmpty(int nodeIndex) const override{

            if (nodeIndex >= 0 && nodeIndex < MAX && valid[nodeIndex])
            {
                int child = 2 * nodeIndex + 2; // Indice del nodo figlio DESTRO

                if (child < MAX && valid[child])
                {
                    return false;
                }
                
            }
            
            return true;
        }

        void toString() const override{

            if (size == 0) {
                std::cout << "[]" << std::endl;
            } else {
                printSubTree(0); // radice indice 0
                std::cout << std::endl;
            }

        } 

    };   



#endif // BT_ARRAY_H
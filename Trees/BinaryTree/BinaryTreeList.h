/* 

    ALBERI BINARI IMPLEMENTATI CON LISTA LINKATA

*/

#ifndef BINARY_TREE_LIST_H
#define BINARY_TREE_LIST_H

#include <iostream>
#include "TreeNode.h"
#include "BinaryTree.h"

#include "../../Stack/Stack.h"
#include "../../Queue/Queue.h"

template <class T>
class BinaryTreeList: public BinaryTree<T , TreeNode<T>*>{
    protected:
        TreeNode<T> * root;

        void printSubTree(TreeNode<T>* tn) const {
            if (tn == nullptr) {
                std::cout << "NIL";
                return;
            }
        
            std::cout << "[" << tn->val << ", ";
        
            // Figlio sinistro
            printSubTree(tn->sx);
            std::cout << ", ";
        
            // Figlio destro
            printSubTree(tn->dx);
            std::cout << "]";

        }

        // CANCELLAMI 
        // privateRemoveEvenLeaf: Cancella le foglie pari, con visita postOrder (S,D,R)
        void privateRemoveEvenLeaf(TreeNode<T>* &root){

            // Passo Base
            if (root == nullptr)
            {
                return;
            }

            // Passo Ricorsivo
            privateRemoveEvenLeaf(root->sx);
            privateRemoveEvenLeaf(root->dx);

            if (isLeaf(root))
            {
                if (root->val % 2 == 0) // LA FOGLIA HA VALORE PARI
                {                   
                    delete root;
                    root = nullptr;
                }
            }

        }

    public:
        
        // Costruttore
        BinaryTreeList(){
            root = nullptr;
        }

        
        ~BinaryTreeList(){
            // Per la cancellazione dell'albero uso il POST ORDER ricorsivo 
            
            postOrderDistruttore(root);

            root = nullptr;
        
        }

        // Cancellazione di un sotto-albero
        void erase(TreeNode<T>* &root){
            // Passo Base
            if (root == nullptr) {
                return;
            }

            // Passo Induttivo
            erase(root->sx); // Passo a sinistra
            erase(root->dx); // Destra
            delete root;
            root = nullptr; 
        }

        //  == Inserimento ==

        void insRoot(T e) override {
            if (isEmpty())
            {
                root = new TreeNode<T>(e);
            }
            
        }

        void insDx(TreeNode<T>* tn, T e) override{
            
            TreeNode<T> * node = new TreeNode<T>();

            if (dxEmpty(tn))
            {
                node->parent = tn;
                node->val = e;
                tn->dx = node;
            }
            
        }

        void insSx(TreeNode<T>* tn, T e) override {
            
            TreeNode<T>* node = new TreeNode<T>();

            if (sxEmpty(tn)) 
            {
                node->parent = tn;
                node->val = e;
                tn->sx = node;
            }

        }

        // == Getters ==

        TreeNode<T>* getRoot() const override{
            if (!isEmpty())
            {
                return root;
            }else{
                return nullptr;
            }
            
        }

        TreeNode<T>* getSx(TreeNode<T>* tn) const override{
            if (!sxEmpty(tn))
            {
                return tn->sx;
            }
            
            return nullptr;
        }

        TreeNode<T>* getDx(TreeNode<T>* tn) const override{
            if (!dxEmpty(tn))
            {
                return tn->dx;
            }
            
            return nullptr;
        }

        TreeNode<T>* getParent(TreeNode<T>* tn) const override{
            if (tn != root)
            {
                return tn->parent;
            }
            
            return nullptr;
        }
        
        // Lettura e Modifica
        T read(TreeNode<T>* tn) const override{
            if (tn != nullptr)
            {
                return tn->val;
            }
            return T { }; // Possiamo anche creare un Exeption
        }

        void write(TreeNode<T>* tn, T e) override{
            if (tn != nullptr)
            {
                tn->val = e;
            }
            
        }

        // Controlli su nodi vuoti
        bool isEmpty() const override{
            return root == nullptr;
        }

        bool sxEmpty(TreeNode<T>* tn) const override{
            return tn->sx == nullptr;
        }

        bool dxEmpty(TreeNode<T>* tn) const override{
            return tn->dx == nullptr;
        }


        // Stampa
        void toString() const override {
            
            if (isEmpty())
            {
                std::cout << "[]" << std::endl;
            }else{
                printSubTree(root);
                std::cout << std::endl;
            }

        }

        
        // Algoritmi di visita 
        // Algoritmo di visita PRE-ORDER ( In profondità ) versione iterativa
        // Con uso di uno STACK -- ROOT , SINISTRA , DESTRA
        void preOrder(TreeNode<T>* root) const override{

            Stack<TreeNode<T>*> stack; 

            // L'albero è vuoto
            if (root == nullptr)
            {
                return;
            }

            stack.push(root);

            while (!stack.isEmpty())
            {
                root = stack.pop(); // Radice del sottoalbero
                // std::cout << root->val << "-"; // Visita
                if (!dxEmpty(root))
                {
                    stack.push(root->dx);
                }

                if (!sxEmpty(root))
                {
                    stack.push(root->sx);
                }
                   
            } 

        }

        // In Order RICORSIVO
        void inOrder(TreeNode<T>* root) const override{
            if (root == nullptr)
            {
                return;
            }

            inOrder(root->sx);
            std::cout << root->val << "-";
            inOrder(root->dx);
            
        }

        // PostOrder ricorsivo
        void postOrder(TreeNode<T>* root) const override{
            if (root == nullptr)
            {
                return;
            }

            postOrder(root->sx);
            postOrder(root->dx);
            std::cout << root->val << "-"; // Visita
     
        }

        // PostOrder usato come distruttore
        void postOrderDistruttore(TreeNode<T>* root){
            if (root == nullptr)
            {
                return;
            }

            postOrderDistruttore(root->sx);
            postOrderDistruttore(root->dx);
            
            delete root;
        }
        
        
        // Breath First Search
        /* 
           Serve a trovare la profondità minima per cercare qualcosa
           Generare la vista dell'albero livello per livello
        */
        void BFS(TreeNode<T>* root) const{
            
            /* La BFS ha bisogno di una CODA perchè c'è bisogno di tenere
               traccia dei nodi al livello sottostante che verranno visitati
               al termine del livello corrente
            */ 
            Queue<TreeNode<T>*> coda;
            TreeNode<T>* current;

            // Se l'albero è vuoto, non c'è nulla da visitar            
            if (!root)
            {
                return;
            }

            // Inizio dalla radice
            coda.enqueue(root);

            // Finchè ci saranno nodi nella coda, l'albero non sarà finito
            while (!coda.isEmpty())
            {

                current = coda.dequeue(); // Estraggo il primo dalla coda 

                std::cout << current->val << " "; // Visito il nodo PER LA PRIMA VOLTA

                // Inserisco in coda i nodi figli che dovrà visitare al prossimo livello (se esistono)
                // Metto prima il sinistro perche la BFS vuole la lettura da SX verso DX
                if (!sxEmpty(current))
                {
                    coda.enqueue(current->sx);
                }
                
                if (!dxEmpty(current))
                {
                    coda.enqueue(current->dx);
                }

            }           
        }

        // isLeaf: Verifica che il nodo passato sia una foglia
        bool isLeaf(TreeNode<T>* node) const{
            if (node->dx == nullptr && node->sx == nullptr)
            {
                return true;
            }

            return false;
            
        }

        // Cancellami
        void removeEvenLeaf(){
            privateRemoveEvenLeaf(this->root);
        }

        //Cancellami
        // Calcola e restituisce n di foglie verdi (Esercizio)
        // Uso il PostOrder S D R
        int greenLeafs(TreeNode<T>* r){

            // Passo Base
            if (r == nullptr)
            {
                return 0;
            }
            
            // Passo Induttivo
            int fs = greenLeafs(r->sx); // Foglie a sinistra
            int fd = greenLeafs(r->dx); // Foglie a destra

            int i = 0;

            if (isLeaf(r) && r->val == "Green")
            {
                i = 1;  
            }

            return i+fs+fd;

        }


        // Cancellami
        // Calcola e restituisce il numero di nodi di livello pari il cui valore è "rosso" e
        // che hanno almeno un figlio il cui valore è "bianco"
        int levelRed(TreeNode<T> * r){
            
            Queue<TreeNode<T>*> coda;
            coda.enqueue(r);

            int l = 0; // Livello Corrente
            int c = 0; // Numero di nodi che rispettano la condizione

            while (!coda.isEmpty())
            {
                int nodiLiv = coda.getSize();

                for (int i = 0; i < nodiLiv; i++)
                {
                    TreeNode<T> * curr = coda.dequeue();

                    if (l % 2 == 0 && curr->val == "Red")
                    {
                        if ((!sxEmpty(curr) && getSx(curr)->val == "White") || (!dxEmpty(curr) && getDx(curr)->val == "White"))
                        {
                            c++;
                        }
                        
                    }
                    
                    if (!sxEmpty(curr))
                    {
                        coda.enqueue(curr->sx);
                    }
                    if (!dxEmpty(curr))
                    {
                        coda.enqueue(curr->dx);
                    }
                    
                }
                
                l++;
            }

            return c;

        }

    };

#endif
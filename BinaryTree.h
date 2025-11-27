/*  ALBERO BINARIO ( Binary Tree )
    Implementazione delle funzioni principali di un albero binario
    e dei principali algoritmi di visita (ricorsivi e non),

    + Costruttore e Distruttore
    
    + Funzioni di accesso
        - root()
        - sx(Nodo) Figlio sinistro di un Nodo
        - dx(Nodo) Figlio destro di un Nodo
        - isEmpty() per il nodo destro e sinistro
    
    + Funzioni di lettura e scrittura
        - read(Nodo)
        - write(Nodo)
    
    + Inserimento
        - insRoot(Nodo)
        - insSx(Nodo)
        - insDx(Nodo)
    
    + Eliminazione
        - eraseSubTree(N): Cancella un sottoalbero o un nodo
    
    + Funzioni di visita
        - preOrdine()
        - postOrdine()
        - simmetrica()

    + Funzioni di stampa dell'albero

*/

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

template <class T> 
class Nodo{

    private:
        T val;
        Nodo dx = nullptr;
        Nodo sx = nullptr;

    public:
        Nodo(T v){
            val = v;
            dx = nullptr;
            sx = nullptr;
        }
    

}





#endif // BINARY_TREE
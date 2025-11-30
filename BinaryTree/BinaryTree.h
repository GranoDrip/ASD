/* ============================================================
 *  ALBERO BINARIO (Binary Tree)
 *
 *  Interfaccia astratta per la realizzazione di un albero binario,
 *  sia con array sequenziale che con puntatori.
 *  Definizione delle operazioni fondamentali
 * ============================================================ */

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

// T: tipo di dato da inserire (char, int, string)
// NodeType: Tipo di nodo dell'albero (int per array, ListNode per liste)

template <class T, class NodeType>
class BinaryTree {
private:
    // Stampa ricorsiva di un sottoalbero
    virtual void printSubTree(NodeType) const = 0;

public:


    //==== ATTENZIONE QUI >>>> virtual void erase() { };
    // Quando scrivo = 0, dico alle classi che ereditano che devono avere per forza quella funzione
    // TODO: METTI = 0

    /* === FUNZIONI DI ACCESSO === */
    // Restituisce la root dell'albero
    virtual NodeType getRoot() const = 0;
    // Restituisce il genitore del nodo

    //virtual NodeType getParent(NodeType) const { }; // TODO: metti = 0
    
    // Restituisce il nodo a sinistra
    virtual NodeType getSx(NodeType) const = 0;
    // Restituisce il nodo a destro
    virtual NodeType getDx(NodeType) const = 0;

    /* === FUNZIONI DI CONTROLLO === */
    // Verifica se l'albero è vuoto
    virtual bool isEmpty() const = 0;
    // Controlla se il nodo a sinistra è vuoto
    virtual bool sxEmpty(NodeType) const = 0;
    // Controlla se il nodo a destra è vuoto
    virtual bool dxEmpty(NodeType) const = 0;

    /* === FUNZIONI DI LETTURA E SCRITTURA === */
    // Legge il valore di un nodo
    virtual T read(NodeType) const = 0;
    // Scrive un valore in un nodo
    virtual void write(NodeType, T) = 0;

    /* === FUNZIONI DI INSERIMENTO === */
    // Inserisce la radice
    virtual void insRoot(T val) = 0;
    // Inserisce figlio sinistro
    virtual void insSx(NodeType, T val) = 0;
    // Inserisce figlio destro
    virtual void insDx(NodeType, T val) = 0;

    /* === FUNZIONI DI STAMPA === */
    // Stampa l'albero
    virtual void toString() const = 0;

    /* === ALGORITMI DI VISITA */
    virtual void preOrder(NodeType) = 0; // R S D
    virtual void inOrder(NodeType) = 0; // D R S
    virtual void postOrder(NodeType) = 0; // S D R
};

#endif // BINARY_TREE_H
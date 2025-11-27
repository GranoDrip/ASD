/* ============================================================
 *  ALBERO BINARIO (Binary Tree)
 *
 *  Interfaccia astratta per la realizzazione di un albero binario,
 *  sia con array sequenziale che con puntatori.
 *  Definizione delle operazioni fondamentali
 * ============================================================ */

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

template <class T, class NodeType>
class BinaryTree {
private:
    // Stampa ricorsiva di un sottoalbero
    virtual void printSubTree(const NodeType) const;

public:

    /* === COSTRUTTORE E DISTRUTTORE === */
    // Costruttore 
    virtual void create() = 0; // Quando scrivo = 0, dico alle classi che ereditano che devono avere per forza quella funzione

    /* === FUNZIONI DI ACCESSO === */
    // Restituisce la root dell'albero
    virtual NodeType getRoot() const = 0 ;
    // Restituisce il genitore del nodo
    virtual NodeType getParent(NodeType) const = 0 ;
    // Restituisce il nodo a sinistra
    virtual NodeType getSx(NodeType) const = 0 ;
    // Restituisce il nodo a destra
    virtual NodeType getDx(NodeType) const = 0 ;

    /* === FUNZIONI DI CONTROLLO === */
    // Verifica se l'albero è vuoto
    virtual bool isEmpty() const = 0 ;
    // Controlla se il nodo a sinistra è vuoto
    virtual bool sxEmpty(NodeType) const = 0 ;
    // Controlla se il nodo a destra è vuoto
    virtual bool dxEmpty(NodeType) const = 0 ;

    /* === FUNZIONI DI LETTURA E SCRITTURA === */
    // Legge il valore di un nodo
    virtual T read() const = 0;
    // Scrive un valore in un nodo
    virtual void write(NodeType, T) = 0;

    /* === FUNZIONI DI INSERIMENTO === */
    // Inserisce la radice
    virtual void insRoot(NodeType) = 0;
    // Inserisce figlio sinistro
    virtual void insSx(NodeType) = 0;
    // Inserisce figlio destro
    virtual void insDx(NodeType) = 0;

    /* === FUNZIONI DI STAMPA === */
    // Stampa l'albero
    virtual void print() const;

    /* === ALGORITMI DI VISITA */
    virtual void previsita(NodeType);
    virtual void invisita(NodeType);
    virtual void postvisit(NodeType);
};

#endif // BINARY_TREE_H
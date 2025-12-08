/**
 * Implementazione dell'albero N-ario con rappresentazione FCNS (First Child Next Sibling).
 * 
 * Ogni nodo contiene:
 * - firstChild: puntatore al primo figlio
 * - nextSibling: puntatore al fratello successivo
 * - parent: puntatore al genitore (opzionale)
 * 
 * Questa rappresentazione trasforma un albero n-ario in una struttura binaria,
 * permettendo un numero illimitato di figli per nodo.
 */

#ifndef NT_FCNS_H
#define NT_FCNS_H

#include "N_aryTree.h"

// Classe Nodo per l'albero n-ario

template <class NodeType> class NaryTree_FCNS;

template <class DataType>
class TreeNode {
    DataType data;
    TreeNode* firstChild;
    TreeNode* nextSibling;
    TreeNode* parent;
    
    friend class NaryTree_FCNS<DataType,TreeNode<DataType>*>;

};



#endif // NT_FCNS_H
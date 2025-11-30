#include <iostream>
#include "BinaryTreeArray.h"

/* IN QUESTO FILE TESTIAMO L'INSERIMENTO E LA STAMPA DEL SEGUENTE ALBERO

                                    1
                                   / \
                                  2   3
                                 /\   /\
                                4  5 6  7

La stampa usa la versione [valore, sinistro, destro]
Il risultato che ci aspettiamo ( dalla stampa ) è [1, [2, [4, NIL, NIL], [5, NIL, NIL]], [3, [6, NIL, NIL], [7, NIL, NIL]]]

*/

int main() {
    BinaryTreeArray<char> tree;

tree.insRoot('h');

    tree.insSx(1, 'a'); 
    tree.insDx(1, 'c'); 
    
    tree.insSx(2, 'd'); 
    tree.insDx(2, 'l'); 

    tree.insSx(3, 'p'); 
    tree.insDx(3, 's'); 

    tree.insSx(5, 'o'); 
    tree.insDx(5, 'q'); 


    std::cout << "Albero binario completo:" << std::endl;
    tree.toString(); // stampa ricorsiva

    std::cout << "Preorder:" << std::endl;
    tree.preOrder(1);
    std::cout << "\n\n" << std::endl;
    
    std::cout << "InOrder (Simmetrica):" << std::endl;
    tree.inOrder(1);

    std::cout << "\n\n" << std::endl;
    std::cout << "postOrder:" << std::endl;
    tree.postOrder(1);

    return 0;
}

#include <iostream>
#include "NT_FCNS.h"

int main(){

    NaryTree_FCNS<int> nTree;

    // Impostazione radice
    nTree.setRoot(10);
    
    // Figli della radice
    nTree.insertChild(nTree.getRoot(), 5);
    nTree.insertChild(nTree.getRoot(), 8);
    nTree.insertChild(nTree.getRoot(), 12);
    
    // Figli di 5
    TreeNode<int>* node5 = nTree.getFirstChild(nTree.getRoot());
    nTree.insertChild(node5, 2);
    nTree.insertChild(node5, 6);
    
    // Figlio di 6
    TreeNode<int>* node6 = node5->firstChild->nextSibling; // 6
    nTree.insertChild(node6, 7);
    
    // Figli di 8
    TreeNode<int>* node8 = node5->nextSibling; // 8
    nTree.insertChild(node8, 9);
    nTree.insertChild(node8, 11);
    
    // Figlio di 12
    TreeNode<int>* node12 = node8->nextSibling; // 12
    nTree.insertChild(node12, 15);
    
    // Figli di 15
    TreeNode<int>* node15 = nTree.getFirstChild(node12); // 15
    nTree.insertChild(node15, 13);
    nTree.insertChild(node15, 16);
    nTree.insertChild(node15, 18);



    nTree.bfs(nTree.getRoot());

    std::cout << "\n\n";

    std::cout << nTree.getWidth() << std::endl;

    std::cout << nTree.getDepth(nTree.getRoot());


    return 0;

}
#include <iostream>
#include "NT_FCNS.h"

int main(){

    NaryTree_FCNS<char> nTree;

    nTree.setRoot('A');
    nTree.insertChild(nTree.getRoot(),'B');
    nTree.insertChild(nTree.getRoot(),'C');
    nTree.insertChild(nTree.getRoot(),'D');
    nTree.insertChild(nTree.getFirstChild(nTree.getRoot()),'E');
    nTree.insertChild(nTree.getFirstChild(nTree.getRoot()),'F');


    nTree.bfs(nTree.getRoot());

    return 0;

}
#include <iostream>
#include "BinaryTreeList.h"

enum Colors{
    GREEN,
    RED,
    WHITE
};

int main(){

    /*
    BinaryTreeList<int> bt;
    
    bt.insRoot(40);
    auto root = bt.getRoot();

    bt.insSx(root,20);
    bt.insDx(root,60);

    auto n = bt.getSx(root);
    bt.insSx(n,30);
    bt.insDx(n,10);

    n = bt.getDx(n);
    bt.insSx(n,100);
    bt.insDx(n,67);

    n = bt.getDx(root);
    bt.insSx(n,25);
    bt.insDx(n,55);

    n = bt.getDx(n);
    bt.insSx(n,50);

    // bt.toString();

    bt.removeEvenLeaf();

    // bt.toString();

    */
   
    BinaryTreeList<std::string> colorTree;

    colorTree.insRoot("Red");
    auto rt = colorTree.getRoot();

    colorTree.insSx(rt,"Green");
    colorTree.insDx(rt,"White");

    auto m = colorTree.getSx(rt);
    colorTree.insSx(m,"Green");
    colorTree.insDx(m,"Red");

    m = colorTree.getDx(m);
    colorTree.insSx(m,"White");
    colorTree.insDx(m,"Green");

    colorTree.toString();

    std::cout << colorTree.greenLeafs(rt) << std::endl;

    std::cout << colorTree.levelRed(rt) << std::endl;

    return 0;
}
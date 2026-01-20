#include <iostream>
#include "BinaryTreeList.h"

int main(){

    BinaryTreeList<int> bt;

    bt.insRoot(0);
    auto rt = bt.getRoot();

    bt.insSx(rt,-6);
    bt.insDx(rt,2);

    auto msei = bt.getSx(rt);
    auto due = bt.getDx(rt);

    bt.insDx(msei,11);
    bt.insSx(due,-4);
    bt.insDx(due,7);

    bt.toString();

    std::cout << bt.contaSottoAlberi(10,bt.getRoot());

    return 0;
}
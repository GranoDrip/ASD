#include "Stack.h"

int main(){
    Stack<int> godo;
    Stack<int> temp;
    Stack<int> finale;
    int k = 5;
    int n;

    godo.push(5);
    godo.push(1);
    godo.push(4);
    godo.push(8);
    godo.push(9);
    godo.push(2);
    godo.push(6);
    godo.push(6);

    godo.sort().toString();

}
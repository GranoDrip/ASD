// File di test per la hashtable

#include <iostream>
#include "HashTable.h"

int main(){

    HashTable<std::string,int> ht(10);
    Pair<std::string,int> p1("Ciao",1);
    Pair<std::string,int> p2("Prova",2);


    ht.insert(p1);
    ht.insert(p2);
 
    ht.toString();


    ht.toString();


    return 0;


}


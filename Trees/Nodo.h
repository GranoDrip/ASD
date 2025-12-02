#ifndef NODO_H
#define NODO_H

template <class T> 
class Nodo{

    private:
        T val;
        Nodo<T>* dx = nullptr;
        Nodo<T>* sx = nullptr;

    public:
        Nodo(T v){
            val = v;
        }
    

};

#endif
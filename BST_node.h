#include <iostream>

template<class T>
class BST;

template<class T>
class BST_node{
    public:
        BST_node(){
            left = right = 0;
        };

        BST_node(const T& n_data, BST_node<T> * l = 0, BST_node<T> * r = 0){
            data = n_data;
            left = l;
            right = r;
        };
        BST_node& operator=(const BST_node& other);

    private:
        T data;
        BST_node<T> * left;
        BST_node<T> * right;
        friend class BST<T>;
};
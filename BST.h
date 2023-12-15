#include "BST_node.h"
#include <initializer_list>
#include <vector>

template<class T>
class BST{
    public:
        BST(){root = 0;};
        BST(const BST& other);
        BST<T>& operator=(const BST<T>& B){
            BST_node<T>* p = B.root;
            BST<T>* aux_tree;
            preorder_to_copy_tree(this,p);
            return *this;
        };

        BST(std::initializer_list<T>);

        void inorder() {
            inorder(root);
        }

        void preorder() {
            preorder(root);
        }

        void postorder() {
            postorder(root);
        }

        void insert(const T&);
        //search by id
        T* search(int);

        void delete_node(BST_node<T>*& node);

        void preorder_to_copy_tree(BST<T> * tree,BST_node<T> *p);

        void balance(T data[], int first, int last);
        void inorder(BST_node<T> * p);
        void preorder(BST_node<T> * p);
        void postorder(BST_node<T> * p);
        virtual void visit(BST_node<T>* p) {
            std::cout << p->data;
        }
    private:
        BST_node<T> * root;
};

template<class T> 
BST<T>::BST(std::initializer_list<T> lst){
    root = nullptr;

    for (auto& x: lst){
        insert(x);
    }

};


//Return a copy of the node
template <class T> 
T* BST<T> :: search(int key){
    BST_node<T>* aux = root;
    while(!(aux == nullptr)){                        //The ID must be part of your structure
        if (aux->data.id == key){
            return &aux->data;
        }                               //Here, the tree is not responsible for holding ID information
        else if (aux->data.id > key){
            aux = aux->left;
        }
        else {
            aux = aux->right;
        }
    }
    return 0;
}


//
template<class T>
void BST<T>::insert(const T& data) {
    BST_node<T> *aux = root;
    BST_node<T> *previous = 0;
    while (aux != 0) { /*Travelling throughout the nodes till find an empty node*/
        previous = aux;

        if (data < aux->data) {aux = aux->left;}
            
        else {aux = aux->right;}          
    }
    if (root == 0) {root = new BST_node<T>(data);}
        
    else if (data < previous->data) {previous->left = new BST_node<T>(data);}
        
    else {previous->right = new BST_node<T>(data);}
        
}

template <class T>
void BST<T> :: delete_node(BST_node<T>*& node){
    BST_node<T> *prev = node;
    BST_node<T> *tmp = node;
    if(node->right == 0){node = node->left;}
    else if(node->left == 0){node = node->right;}
    else{
        tmp = node->left;
        prev = node;
        while(tmp->right != 0){
            prev = tmp;
            tmp = tmp->right;
        }
        node->data = tmp->data;
        if(prev == node){prev->left = tmp->left;}
        else{prev->right = tmp->left;}
    }
    delete tmp;
}


//
template<class T>
void BST<T>::balance(T data[], int first, int last) {
    if (first <= last) {
        int middle = (first + last)/2;
        insert(data[middle]);
        balance (data,first,middle-1);
        balance (data,middle+1,last);
}
}
//
template<class T>
void BST<T>::inorder(BST_node<T> *p) {
    if (p != 0) {
        inorder(p->left);
        visit(p);
        inorder(p->right);
    }
}

template<class T>
void BST<T>::preorder(BST_node<T> *p) {
    if (p != 0) {
        visit(p);
        preorder(p->left);
        preorder(p->right);
    }
}
template<class T>
void BST<T>::postorder(BST_node<T> *p) {
    if (p != 0) {
        postorder(p->left);
        postorder(p->right);
        visit(p);
    }
}

template<class T>
void BST<T>::preorder_to_copy_tree(BST<T> * tree, BST_node<T> *p) {
    if (p != 0) {
        tree->insert(p->data);
        preorder_to_copy_tree(tree, p->left);
        preorder_to_copy_tree(tree, p->right);
    }
}

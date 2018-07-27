#include <cstddef>
#include<iostream>
using namespace std;
template <typename T>
struct Node{
  Node* left;
  Node* right;
  T elem;
};
template <typename T>
class Abb {
  private:
     Node<T>* root;
     void insertarEnNodo(Node<T>* root, T const& elem);
     void show(Node<T>* root);

  public:
    Abb();
    void insert(T const& elem);
    void erase(T const& elem);
    void get(T const& elem);
    void show();

};

template <typename T>
Abb<T>::Abb(void){
  this -> root = NULL;
}
template <typename T>
void Abb<T>::insert(T const& elem){
  if(this -> root == NULL){
    this -> root = new Node<T>();
    this -> root -> elem = elem;
    this -> root -> right = NULL;
    this -> root -> left = NULL;
  }else{
    insertarEnNodo(root, elem);
  }
}

template <typename T>
void Abb<T>::insertarEnNodo(Node<T>* nodo, T const& elem){
  Node<T>* node = new Node<T>();
  node -> elem = elem;
  node-> right = NULL;
  node -> left = NULL;
    if(elem <= nodo -> elem){
      if(nodo -> left == NULL){
        nodo -> left = node;
      }else{
        insertarEnNodo(nodo-> left, elem);
      }
    }else{
        if(nodo -> right == NULL){
          nodo -> right = node;
        }else{
          insertarEnNodo(nodo -> right, elem);
        }
      }
}

template <typename T>
void Abb<T>::show(){
  show(root);
}

template <typename T>
void Abb<T>::show(Node<T>* root){
  if(root != NULL){
    show(root->left);
    cout << (root->elem);
    cout << " ";
    show(root->right);
  }
}

int main(){
  int a = 5;
  Abb<int>* arbol = new Abb<int>();
  arbol -> insert(0);
  arbol -> insert(15);
  arbol -> insert(3);
  arbol -> insert(10);
  arbol -> insert(1);
  arbol -> insert(a);
  arbol -> insert(a);
  arbol -> show();
  cout << endl;
  return 0;
}

#include <cstddef>
#include<iostream>
using namespace std;
template <typename T>
struct Node{
  Node* siguiente;
  T elem;
};
template <typename T>
class Lista {
  private:
     Node<T>* root;
     void insert(Node<T>* root, T const& elem);
     void show(Node<T>* root);

  public:
    Lista();
    void insert(T const& elem);
    void erase(T const& elem);
    void get(T const& elem);
    void show();

};

template <typename T>
Lista<T>::Lista(void){
  this -> root = NULL;
}

template <typename T>
void Lista<T>::insert(T const& elem){
  Node<T>* node = new Node<T>();
  node -> elem = elem;
  node -> siguiente = NULL;
  if(this->root == NULL){
    this->root = node;
  }else{
    Node<T>* aux = root;
    while(aux -> siguiente != NULL){
      aux = aux -> siguiente;
    }
    aux -> siguiente = node;
  }
}

template <typename T>
void Lista<T>::show(){
  Node<T>* aux = root;
  while(aux != NULL){
    cout << aux -> elem;
    cout << " ";
    aux = aux -> siguiente;
  }
  cout << endl;
}

int main(){
  Lista<int>* lista = new Lista<int>();
  lista -> insert(5);
  lista -> insert(6);
  lista -> insert(7);
  lista -> insert(8);
  lista -> insert(9);
  lista -> insert(10);
  lista -> insert(11);
  lista -> insert(12);
  lista -> insert(13);
  lista -> show();
  return 0;
}

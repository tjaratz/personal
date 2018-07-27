#include <cstddef>
#include<iostream>
#include "sorting.cpp"

using namespace std;


template <typename T>
class MaxHeap {
  private:
     std::vector<T> values;

  public:
    MaxHeap();
    void encolar(T const& elem);
    T const desencolar();
    T const tope();
    void show();

};

template <typename T>
MaxHeap<T>::MaxHeap(void){
}

template <typename T>
void MaxHeap<T>::encolar(T const& elem){
  values.insert(values.begin(), elem);
  maxHeapify(values, 0, values.size());
}

template <typename T>
T const MaxHeap<T>::desencolar(){
  if(values.size() > 0){
    T elem = values[0];
    values.erase(values.begin());
    maxHeapify(values, 0, values.size());
    return elem;
  }
  cout << "Cola vacia" << endl;
  return NULL;
}

template <typename T>
T const MaxHeap<T>::tope(){
  if(values.size() > 0){
    T elem = values[0];
    return elem;
  }
  cout << "Cola vacia" << endl;
  return NULL;
}

template <typename T>
void MaxHeap<T>::show(){
  mostrar(values);
}

int main(){
  MaxHeap<int> cola = MaxHeap<int>();
  while(true){
    cout << "Presione: " << endl << "- 'e' para encolar"
    << endl << "- 'd' para desencolar"
    << endl << "- 't' para obtener el tope"<< endl;
    char option;
    cin >> option;
    if(option == 'e'){
      cout << "Ingrese un numero a encolar: " << endl;
      int number;
      cin >> number;
      cola.encolar(number);
    }
    if(option == 'd'){
      int val = cola.desencolar();
      cout << "desencolado el elemento: " << val << endl;
    }
    if(option == 't'){
      cout << "El tope de la pila es: " << cola.tope() << endl;
    }
  }
  cola.show();
  cout << endl;
  return 0;
}

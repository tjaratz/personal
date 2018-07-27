#include <vector>
#include<iostream>
using namespace std;

void mostrar(std::vector<int> const& v){
  for(auto x : v){
    cout << x << " ";
  }
  cout << endl;
}

void swapp(std::vector<int>& v, int i, int j){
  int aux = v[i];
  v[i] = v[j];
  v[j] = aux;
}

//invariante: [n-i..n] esta ordenado
void bubbleSort(std::vector<int>& v){
  for(int i = 0; i < v.size()-1; i++){
    int j = i;
    for(j = 0; j < v.size()-1; j++){
      if(v[j] > v[j+1]){
          swapp(v, j, j+1);
      }
    }
  }
}

//invariante:[0..i] esta ordenado
void insertionSort(std::vector<int>& v){
  for(int i = 1; i < v.size(); i++){
    int elem = v[i];
    int j = i-1;
    while(j >= 0 && v[j] > elem){
      swapp(v, j, j+1);
      j--;
    }
  }
}

void maxHeapify(std::vector<int>& v, int i, int size){
  int max = i;
  int left = 2*i+1;
  int right = 2*i+2;
  if(left < size && v[i] < v[left]){
    max = left;
  }
  if(right < size && v[right] > v[max]){
    max = right;
  }
  if(i != max){
    swapp(v, i, max);
    maxHeapify(v, max, size);
  }
}

void buildMaxHeap(std::vector<int>& v){
  for(int i = v.size()/2+1; i >=0; i--){
    maxHeapify(v,i, v.size());
  }
}

void heapSort(std::vector<int>& v){
  buildMaxHeap(v);
  int size = v.size();
  for(int i = v.size()-1; i > 0; i--){
    swapp(v,0, i);
    size--;
    maxHeapify(v, 0, size);

  }
}

std::vector<int> subarray(std::vector<int> v, int j, int i){
  std::vector<int> result;
  while(j <= i){
    result.push_back(v[j]);
    j++;

  }
  return result;
}

vector<int> merge(std::vector<int>& a, std::vector<int> b){
  std::vector<int> result;
  int i = 0;
  int j = 0;
  int count = a.size()+b.size();
  int cant = 1;
  while(cant <= count){
    while(i < a.size() && (a[i] < b[j] || j == b.size()) ){
      result.push_back(a[i]);
      i++;
      cant++;
    }
    while(j < b.size() && (b[j] <= a[i] || i == a.size()) ){
      result.push_back(b[j]);
      j++;
      cant++;
    }
  }
  return result;
}

std::vector<int> mergeSort(std::vector<int> v){
  if(v.size() == 1) return v;
  int half = v.size()/2;

  std::vector<int> first = subarray(v, 0, half-1);
  std::vector<int> second = subarray(v, half, v.size()-1);

  std::vector<int> firstOrdered = mergeSort(first);
  std::vector<int> secondOrdered = mergeSort(second);

  return(merge(firstOrdered, secondOrdered));
}
/*
int main(){
  vector<int> v = {8,7,6,5,4,3,2,1,23,14,26,1,0,2,35,78,96,54,12,33,65};
  vector<int> z = {2,4,6,8,10,12};
  //mostrar(v);
  //mostrar(v);
  std::vector<int> res = mergeSort(v);
  mostrar(res);
  return 0;
}*/

#ifndef SORTS_H_
#define SORTS_H_


#include <vector>
#include <iostream>
#include <list>
using namespace std; 
template <class T>
class Sorts{
    public:
        void ordenaSeleccion(vector<T> &vector);
        void ordenaBurbuja(vector<T> &vector);
        void ordenaMerge(vector<T> &vector);
        int busqSecuencial(vector<T> &vector, int val);
        int busqBinaria(vector<T> &vector, int val);
    private:
        void copyArray(std::vector<T> &A, std::vector<T> &B, int low, int high);
        void mergeArray(std::vector<T> &A, std::vector<T> &B, int low, int mid, int high);
        void mergeSplit(std::vector<T> &A, std::vector<T> &B, int low, int high);
        void swap(std::vector<T> &v, int i, int j);
};

template <class T>
void Sorts<T>::swap(vector<T> &v, int i, int j) {
    T aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

template <class T>
void Sorts<T>::ordenaSeleccion(vector<T> &vector){
    int min;
    for(int i = 0; i < vector.size()-1; i++){
        min = i;
        for(int j = i + 1; j < vector.size(); j++) {
            if (vector[j] < vector[min]) {
                min = j;
            }
        }
        if(min != i){
            swap(vector, i, min);
        }
    }
}

template <class T>
void Sorts<T>::ordenaBurbuja(vector<T> &vector){
  for(int i = 1; i<vector.size(); i++){
    for(int j = 0; j<vector.size()-1; j++){
      if (vector[j]>vector[j+1]){
        swap(vector, j, j+1);
      }
    }
  }

}

template <class T>
void Sorts<T>::copyArray(std::vector<T> &A, std::vector<T> &B, int low, int high){
    for(int i = low; i <= high; i++){
        A[i] = B[i];
    }
}

template <class T>
void Sorts<T>::mergeArray(std::vector<T> &A, std::vector<T> &B, int low, int mid, int high){
    int i = low, j = mid + 1, k = low;

    while(i <= mid && j <= high){
        if(A[i] < A[j]){
            B[k] = A[i];
            i++;
        } else {
            B[k] = A[j];
            j++;
        }
        k++;
    }
    if(i > mid){
        for (; j<= high; j++){
            B[k++] = A[j];
        }
    } else {
        for(; i <= mid; i++){
            B[k++] = A[i];
        }
    }
}

template <class T>
void Sorts<T>::mergeSplit(std::vector<T> &A, std::vector<T> &B, int low, int high){
    int mid;
    
    if( (high - low) < 1 ){
        return;
    }
    mid = (high + low) / 2;
    mergeSplit(A, B, low, mid);
    mergeSplit(A, B, mid + 1, high);
    mergeArray(A, B, low, mid, high);
    copyArray(A, B, low, high);
}

template <class T>
void Sorts<T>::ordenaMerge(std::vector<T> &vector){
    std::vector<T> tmp(vector.size());
    mergeSplit(vector, tmp, 0, vector.size() - 1);
}

template <class T> 
int Sorts<T>::busqSecuencial(vector<T> &vector, int val){
  int n = vector.size();
    for(int i = 0; i < n; i++){
        if(vector[i] == val){
            return i;
        } 
    }
    return -1;
}

template <class T> 
int Sorts<T>::busqBinaria(vector<T> &vector, int val){
  
  int n = vector.size();
  int min = 0; 
  int max = n; 
  int mitad; 
  int data;
  int flag; 

  while(min <= max){
    mitad = (min + max)/2; 
    if (vector[mitad] == data){
      flag = 'T'; 
      break;


    }

  }

}


#endif 


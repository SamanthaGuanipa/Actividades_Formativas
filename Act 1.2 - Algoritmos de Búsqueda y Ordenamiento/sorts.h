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
        void swap(vector<T> &v, int i, int j);
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
int Sorts<T>::busqSecuencial(vector<T> &vector, int val){
  int n = vector.size();
    for(int i = 0; i < n; i++){
        if(vector[i] == val){
            return i;
        } 
    }
    return -1;
}

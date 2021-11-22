#ifndef HEAP_H_
#define HEAP_H_

#include <string>
#include <sstream>
#include <iostream>

template <class T>
class Heap {
  private:

	  T *data;

	  unsigned int sizeT;

	  unsigned int count;

	  unsigned int parent(unsigned int) const;

	  unsigned int left(unsigned int) const;
	  unsigned int right(unsigned int) const;

    void swap(unsigned int, unsigned int);
	  void heapify(unsigned int);

  public:
	  
    Heap(unsigned int);

	  ~Heap();

	  bool empty() const;
	  void push(T);
  	T pop();
    int top(); 
    int size();
    std::string toString() const;
	
};

template <class T>
Heap<T>::Heap(unsigned int sz) {

	sizeT = sz;
	data = new T[sizeT];
	count = 0;

}

template <class T>
Heap<T>::~Heap() {
	delete [] data;
	data = 0;
	sizeT = 0;
	count = 0;
}

template <class T>
bool Heap<T>::empty() const {

  return (count == 0);

}

template <class T>
unsigned int Heap<T>::parent(unsigned int pos) const {

	return (pos - 1) / 2;

}

template <class T>
unsigned int Heap<T>::left(unsigned int pos) const {

	return ((2 * pos) + 1);

}

template <class T>
unsigned int Heap<T>::right(unsigned int pos) const {

	return ((2 * pos) + 2);

}

template <class T>
void Heap<T>::swap(unsigned int h, unsigned int i) {
	T aux = data[h];
	data[h] = data[i];
	data[i] = aux;
}

template <class T>
void Heap<T>::heapify(unsigned int pos) {

	unsigned int leftt = left(pos);
	unsigned int rightt = right(pos);
	unsigned int min = pos;

	if (leftt <= count && data[leftt] < data[min]) {
		min = leftt;
	}

	if (rightt <= count && data[rightt] < data[min]) {
		min = rightt;
	}

	if (min != pos) {

		swap(pos, min);
		heapify(min);

	}

}

template <class T>
void Heap<T>::push(T val) {

	unsigned int pos;

	pos = count;
	count++;
  
	while (pos > 0 && val < data[parent(pos)]) {
		
    data[pos] = data[parent(pos)];
		pos = parent(pos);

	}

	data[pos] = val;

}

template <class T>
T Heap<T>::pop() {

	if (empty()) {
		return -1; 

	}

	T aux = data[0];
	data[0] = data[--count];
	heapify(0);
	return aux;
}

template <class T>
int Heap<T>::top(){

   return data[0];

}

template <class T>
int Heap<T>::size(){
   return count;
}

template <class T>
std::string Heap<T>::toString() const {
	std::stringstream aux;
	aux << "[";	for (unsigned int i = 0; i < count; i++) {
		if (i != 0) {
			aux << " ";
		} aux << data[i];
	} aux << "]";
	return aux.str();
}

#endif

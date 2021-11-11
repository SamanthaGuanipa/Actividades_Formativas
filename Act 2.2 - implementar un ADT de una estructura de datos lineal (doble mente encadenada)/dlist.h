#ifndef DLIST_H_
#define DLIST_H_

#include <string>
#include <sstream>

template <class T> class DList;

template <class T>
class DLink {
private:
	DLink(T);
	DLink(T, DLink<T>*, DLink<T>*);
	DLink(const DLink<T>&);

	T	    value;
	DLink<T> *previous;
	DLink<T> *next;

	friend class DList<T>;

};

template <class T>
DLink<T>::DLink(T val) : value(val), previous(0), next(0) {}

template <class T>
DLink<T>::DLink(T val, DLink *prev, DLink* nxt) : value(val), previous(prev), next(nxt) {}

template <class T>
DLink<T>::DLink(const DLink<T> &source) : value(source.value), previous(source.previous), next(source.next) {}


template <class T>
class DList {

public:

	DList(); 
  DList(const DList<T>&); 
  void insertion(T); 
  int search(T) const;
  void update(int, T);
  T deleteAt(int);

  std::string toStringForward() const;
  std::string toStringBackward() const;

private:

	DLink<T> *head;
	DLink<T> *tail;
	int 	 size;

};


template <class T>
DList<T>::DList() : head(0), tail(0), size(0) {}

	template <class T>
	std::string DList<T>::toStringForward() const {
		std::stringstream aux;
		DLink<T> *p;
		p = head;
		aux << "[";
		while (p != 0) {
			aux << p->value;
			if (p->next != 0) {
				aux << ", ";
			}
			p = p->next;
		}
		aux << "]";
		return aux.str();
	}
	template <class T>
	std::string DList<T>::toStringBackward() const {
		std::stringstream aux;
		DLink<T> *p;
		p = tail;
		aux << "[";
		while (p != 0) {
			aux << p->value;
			if (p->previous != 0) {
				aux << ", ";
			}
			p = p->previous;
		}
		aux << "]";
		return aux.str();
	}

template <class T>
void DList<T>::insertion(T val) {
	  DLink<T> *newLink;

	  newLink = new DLink<T>(val);

	  if (size == 0) {
      tail = newLink;
      head = newLink;
	}
  
  else {
		tail->next = newLink;
		newLink->previous = tail;
		tail = newLink;
	}

	size++;
}

template <class T>
int DList<T>::search(T val) const {
	
  DLink<T> *p;
	p = head;
  int i = 0; 

	while (p != 0) {
		if (p->value == val) {
			return i;
		}
    i++; 
		p = p->next;
	}
	return -1;
} 

template <class T> 
void DList<T>::update(int i, T val) {
    int pos = 0;
    DLink<T> *p;
  
    p = head;

    while (p != 0) {
        if (i != pos) {
            p = p->next;
            pos++;
        }
        p -> value = val;
    }
}

template <class T>
T DList<T>::deleteAt(int i){
	int pos;
	T val;
	DLink<T> *p;

	if (i == 0) {

		p = head;
		val = p->value;

		if(head == tail){
			head = 0;
			tail = 0;
		} 
    
    else{

			head = p->next;
			p->next->previous = 0;
		}
		delete p;
		size--;

		return val;		
	}

	p = head;
	pos = 0;
	while (i != pos) {
		p = p->next;
		pos++;
	}

	val = p->value;
	p->previous->next = p->next;
	if (p->next != 0) {
		p->next->previous = p->previous;
	}
	size--;
	delete p;
	return val;
}

#endif

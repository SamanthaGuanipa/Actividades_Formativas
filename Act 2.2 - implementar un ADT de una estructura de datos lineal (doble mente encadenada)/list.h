#ifndef LIST_H
#define LIST_H

#include <string>
#include <sstream>

template <class T> class List;
template <class T> class ListIterator;

template <class T>
class Link {

    private:

        Link(T);
        Link(T, Link<T>*);
        Link(const Link<T>&);

        T       valor;
        Link<T> *next;

        friend class List<T>;
        friend class ListIterator<T>;
};

template <class T>
Link<T>::Link(T val) : valor(val), next(0) {}

template <class T>
Link<T>::Link(T val, Link* nxt) : valor(val), next(nxt) {}

template <class T>
Link<T>::Link(const Link<T> &source) : valor(source.valor), next(source.next) {}

template <class T>
class List {
  
    public:
        List();
        List(const List<T>&);

        std::string toString() const;

        void insertion(T);
        T search(T) const;
        void update(int, T);
        T deleteAt(int);

    private:

        Link<T> *head;
        int size;

        friend class ListIterator<T>;

};

template <class T>
List<T>::List() : head(0), size(0) {}

template <class T>
std::string List<T>::toString() const {

	std::stringstream aux;
	Link<T> *p;

	p = head;

	aux << "[";

	while (p != 0) {
		aux << p->valor;
		if (p->next != 0) {
			aux << ", ";

		}

		p = p->next;
	}

	aux << "]";

	return aux.str();

}

template <class T>
void List<T>::insertion(T val){

    Link<T> *newLink, *p;
    newLink = new Link<T>(val);
    
    if (size == 0) {

        newLink -> next = head;
        head = newLink;
        size++;

    }
    
     else {

        p = head;

        while (p -> next != 0) {

            p = p-> next;
        }
        
        newLink -> next = 0;
        p -> next = newLink;

        size ++;

    }
}



template <class T>
T List<T>::search(T val) const {
    
    Link<T> *p;
    int contador = 0;

    p = head;

    while (p != 0) {

        if (p -> valor == val) {
            return contador;
        }

        p = p -> next;
        contador++;

    }

    return -1;
}

template <class T>
void List<T>::update(int x, T val){

    Link<T> *p;
    int contador = 0;

    p = head;

    while (p != 0) {

        if (contador == x) {
            p -> valor = val;
            return;
        }
       
        p = p -> next;
        contador++;
    }
}

template <class T>
T List<T>::deleteAt(int position){

    if (position == 0){

        T m;
        Link<T> *p;

        p = head; 
        head = p->next;
        m = p -> valor;

        delete p; size --;

        return m;

    } 
    
    else {

        T m;
        int i = 1;

        Link<T> *previo = head;
        Link<T> *actual = head -> next;

        while (i < position){
          
            previo = actual;
            actual = actual -> next;
        }

        m = actual -> valor;
        previo -> next = actual -> next;

        delete actual;

        size++;

        return m;
    }
}

#endif
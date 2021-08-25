/*
 * funciones.h
 *
 *  Created on: 24/08/2021
 *      Author: SamanthaGuanipa
 */
#define FUNCIONES_H_

#include<iostream>
#include <string> 
#include <sstream>

using namespace std; 

class Funciones {
    public: 
    Funciones(); 
    int sumaIterativa (int n);
    int sumaRecursiva (int n);
    int sumaDirecta (int n);

}; 

Funciones::Funciones(){

}

int Funciones::sumaIterativa (int n){
    
    int i=1; 
    int suma = 0;
    for (int i=0; i<=n; i++){
        suma = suma + i;
    }
    
    return suma;

}

int Funciones::sumaRecursiva (int n){ 
    if (n==0){
        return 0; 
    }
    else{
        n = n + sumaRecursiva(n-1);
    }
    return n;
}

int Funciones::sumaDirecta (int n){
    n = (n*(n+1))/2; 
    return n;


}


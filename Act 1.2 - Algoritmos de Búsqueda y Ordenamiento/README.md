*ordenaSeleccion*

**Análisis de complejidad temporal**

Se compone de dos ciclos for (anidados), que irán recorriendo el arreglo para seleccionar el valor menor, irá revisando el arreglo un cierto número de veces. La complejidad del algoritmo es de O(n^2) para el peor de los casos.   

*ordenaBurbuja*

**Análisis de complejidad temporal**

Se compone de dos ciclos for (anidados) que recorren el arreglo para seleccionar el valor mayor, llevándolo al final cada vez Realizará un proceso de revisión diversas veces, dependiendo del arreglo.  La complejidad del algoritmo es de O(n^2) para el peor de los casos.  


*ordenaMerge*

**Análisis de complejidad temporal**

Es recursivo, consiste en dividir el arreglo a la mitad (por medio de la recursividad) y lo va uniendo en orden. Como es una función recursiva en la que se divide varias veces el vector, y se unen posteriormente dependiendo del tamaño del vector, el algoritmo tiene una complejidad temporal de O(n * log n) en el peor de los casos. 

*busqSecuencial*

**Análisis de complejidad temporal**

Va comparando los valores del que se quiere encontrar con cada valor dado por el arreglo.  El número de pasos depende del tamaño del arreglo. La complejidad del algoritmo es O(n)  para el peor de los casos. 

*busquedaBinaria*

**Análisis de complejidad temporal**

Divide a la mitad los arreglos e irá disminuyendo el número de pasos a realizar. La complejidad del algoritmo es O(log n)  para el peor de los casos.

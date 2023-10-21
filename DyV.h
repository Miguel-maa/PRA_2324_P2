#include <iostream>
#include <vector>

using namespace std;

// Busqueda Binaria es una funvión que permite encontrar un valor determinado en un vector ordenado (de manera ascendente) de valores.
template <typename T>
T BusquedaBinaria(T X, std::vector<T>& V, int ini, int fin){
	T valor;
	
	if(ini>fin){
	    cout << endl << "(Busqueda Binaria ascendente)El valor no se ha encontrado"	<< endl;
		valor = -1;
	} else {

    	int media = (ini+fin)/2;	
	    if(V[media]==X){
		    valor = media;
	    } else if (V[media] > X){
		    valor = BusquedaBinaria(X, V, ini, media -1);
	    } else {
		    valor = BusquedaBinaria(X, V, media +1, fin);
	    }
	}

	return valor;
}

// Busqueda Binaria es una funvión que permite encontrar un valor determinado en un vector ordenado (de manera descendente) de valores.
template <typename T>
T BusquedaBinaria_INV(T X, std::vector<T>& V, int ini, int fin){
	T valor;

	if(ini>fin){

	    cout << endl << "(Busqueda Binaria descendente)El valor no se ha encontrado" << endl;
		valor = -1;
	} else {

    	int media = (ini+fin)/2;	
	    if(V[media]==X){
		    valor = media;
	    } else if (V[media] < X){
			valor = BusquedaBinaria_INV(X, V, ini, media - 1);
	    } else {
			valor = BusquedaBinaria_INV(X, V, media + 1, fin);
	    }
	}

	return valor;
}



// QuickSort es un método de ordenamiento de los elementos de un vector. 
// Último elemento del vector utilizado como pivote
// División (Partition): reordena el vector de manera que todos los elementos menores que el pivote estén delante del pivote y los que sean mayores estén detrás
template <typename T>
int Partition(std::vector<T>& V, int ini, int fin){

	T x = V[fin];	// El pivote es el último elemento
	int i = ini;
	for(int j = ini; j <= fin - 1; j++){
		if(V[j] < x){
			T aux = V[i];
			V[i] = V[j];
			V[j] = aux;

			i++;
		} 
	}

	T aux = V[i];
	V[i] = V[fin];
	V[fin] = aux;

	return i;
}
 
template <typename T>
void QuickSort(std::vector<T>& V, int ini, int fin){

	if(ini < fin){
		int pivot = Partition(V, ini, fin);
		QuickSort(V, ini, pivot - 1);
        QuickSort(V, pivot + 1, fin);
	}
}



// Primer elemento del vector utilizado como pivote
template <typename T>
int Partition_ini(std::vector<T>& V, int ini, int fin){

	T x = V[ini];	// El pivote es el primer elemento
	int i = ini;
	for(int j = ini + 1; j <= fin; j++){
		if(V[j] < x){
			T aux = V[i];
			V[i] = V[j];
			V[j] = aux;

			i++;
		} 
	}

	return i;
}
 
template <typename T>
void QuickSort_ini(std::vector<T>& V, int ini, int fin){

	if(ini < fin){
		int pivot = Partition_ini(V, ini, fin);
		QuickSort_ini(V, ini, pivot - 1);
        QuickSort_ini(V, pivot + 1, fin);
	}
}



// Elemento central del vector utilizado como pivote
template <typename T>
int Partition_medio(std::vector<T>& V, int ini, int fin){

	int medio = (ini + fin) / 2;  // Calcula la posición media
    T x = V[medio];  // El pivote es el elemento en la posición media
    int i = ini;
    int j = fin;

	while (true) {
        while (V[i] < x) {
            i++;
        }

        while (V[j] > x) {
            j--;
        }

        if (i >= j) {
            return j;
        }

        T aux = V[i];
        V[i] = V[j];
        V[j] = aux;

        i++;
        j--;
    }
}
 
template <typename T>
void QuickSort_medio(std::vector<T>& V, int ini, int fin){

	if(ini < fin){
		int pivot = Partition_medio(V, ini, fin);
		QuickSort_medio(V, ini, pivot);
        QuickSort_medio(V, pivot + 1, fin);
	}
}
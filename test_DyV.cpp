#include <iostream>
#include <chrono>
#include "DyV.h"

using namespace std;

// Comprovación de tiempo de ejecución 
template <typename T>
float VisualizarTiempos(int modo, std::vector<T>& V, int ini, int fin){

	auto start = std::chrono::system_clock::now();

	if(modo == 0){
		QuickSort_ini(V, ini, fin);	// QuickSort con primer elemento del vector utilizado como pivote
	} else if(modo == 1){
		QuickSort_medio(V, ini, fin);	// QuickSort con el elemento central del vector utilizado como pivote
	} else if(modo == 2){
		QuickSort(V, ini, fin);	// QuickSort con el último elemento central del vector utilizado como pivote
	}


	auto end = std::chrono::system_clock::now();
	std::chrono::duration<float, std::milli> duration = end - start;
	float Tiempo = duration.count();

	return Tiempo;
}



// Imprimir el vector por pantalla
template <typename T>
void ImprimirVector(std::vector<T>& V, int tam){
	
	for(int i = 0; i < tam; i++){
		cout << V[i];
		if(i != tam - 1)
			cout << ", ";
	}	
	
	cout << "]" << endl;
}




int main(){

	int aux;
	cout << "Desea realizar una busqueda (0 para  Búsqueda binaria) o la ordenación de un vector (1 para QuickSort): ";
	cin >> aux;

	if(aux == 0){

		// Prueba con números enteros Búsqueda binaria ascendente
		int tam_int=10;
 		vector<int> vector_int{3,8,15,23,56,60,72,75,81,92};
		int valor_int;

		cout << endl << "(Búsqueda binaria ascendente) Introduzca el valor a buscar (El valor debe ser un número natural): ";
		cin >> valor_int;	

		cout << "El valor a buscar (número natural) se encuentra en la posición: ";	
		int posicion_int = BusquedaBinaria(valor_int, vector_int, 0, tam_int - 1);

		if(posicion_int > -1)
			cout << posicion_int << endl;

		cout << endl;


		// Prueba con números enteros Búsqueda binaria descendente
 		vector<int> vector_int_des{92,81,75,72,60,56,23,15,8,3};

		cout << "(Búsqueda binaria descendente) Introduzca el valor a buscar (El valor debe ser un número natural): ";
		cin >> valor_int;	

		cout << "El valor a buscar (número natural) se encuentra en la posición: ";	
		posicion_int = BusquedaBinaria_INV(valor_int, vector_int_des, 0, tam_int - 1);

		if(posicion_int > -1)
			cout << posicion_int << endl;

		cout << endl;



		// Prueba con cadenas Búsqueda binaria ascendente
		int tam_char=10;
	 	vector<char> vector_char{'a','b','c','d','e','f','g','h','i','j'};
		char valor_char;

		cout << "(Búsqueda binaria ascendente) Introduzca el valor a buscar (El valor debe ser una caracter): ";
		cin >> valor_char;	

		cout << "El valor a buscar (caracter) se encuentra en la posición: ";	
		int posicion_char = BusquedaBinaria(valor_char, vector_char, 0, tam_char - 1);

		if(posicion_char > -1)
			cout << posicion_char << endl;

		cout << endl;


		// Prueba con cadenas Búsqueda binaria descendente
 		vector<char> vector_char_des{'j','i','h','g','f','e','d','c','b','a'};

		cout << "(Búsqueda binaria descendente) Introduzca el valor a buscar (El valor debe ser una caracter): ";
		cin >> valor_char;	

		cout << "El valor a buscar (caracter) se encuentra en la posición: ";	
		posicion_char = BusquedaBinaria_INV(valor_char, vector_char_des, 0, tam_char - 1);

		if(posicion_char > -1)
			cout << posicion_char << endl;

		return 0;


	} else if (aux == 1){

		float Tiempo;

		// Prueba de ordenación de un vertor de números enteros
		int tam_int=10;
 		vector<int> vector_int{72,23,75,15,8,81,3,92,56,60};

		cout << endl << endl << "Primer elemento del vector utilizado como Pivote";
		cout << endl << "Vector a ordenar [";
		ImprimirVector(vector_int, tam_int);

		Tiempo = VisualizarTiempos(0, vector_int, 0, tam_int - 1);	// QuickSort con primer elemento del vector utilizado como pivote

		cout << endl << "Vector ordenado [";
		ImprimirVector(vector_int, tam_int);
		cout << "Tiempo de ejecución: " << Tiempo << "s" << endl;

		
		// Prueba de ordenación de un vertor de caracteres
		int tam_char=10;
 		vector<char> vector_char{'h','e','g','i','c','d','a','b','f','j'};

		cout << endl << endl << "Elemento central del vector utilizado como Pivote";
		cout << endl << "Vector a ordenar [";
		ImprimirVector(vector_char, tam_char);

		Tiempo = VisualizarTiempos(1, vector_char, 0, tam_char - 1);	// QuickSort con el elemento central del vector utilizado como pivote

		cout << endl << "Vector ordenado [";
		ImprimirVector(vector_char, tam_char);
		cout << "Tiempo de ejecución: " << Tiempo << "s" << endl;



		// Prueba de ordenación de un vertor de numeros racionales
		int tam_float=10;
 		vector<float> vector_float{3.14, 5.67, -0.98, 2.25, -4.76, 1.33, 6.42, 0.72, 8.15, 7.91};
		cout << endl << endl << "Último elemento del vector utilizado como Pivote.";
		cout << endl << "Vector a ordenar [";
		ImprimirVector(vector_float, tam_float);

		Tiempo = VisualizarTiempos(2, vector_float, 0, tam_float - 1);	// QuickSort con el último elemento central del vector utilizado como pivote

		cout << endl << "Vector ordenado [";
		ImprimirVector(vector_float, tam_float);
		cout << "Tiempo de ejecución: " << Tiempo << "s" << endl;
	} 	
	

	return 0;
}

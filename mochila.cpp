#include <iostream>
#include <vector>

using namespace std;


int mochila(int N, vector<int>& P, vector<int>& B, int M, vector<int>& Sol){
  int tabla[N][M+1];  // Creación la tabla
  int i, j;
  
  // Inicialización de la tabla
  for(i=0; i<N; i++){
    for(j=0; j<=M; j++){
      tabla[i][j]=0;
    }
  }


  // Rellenamos la tabla
  tabla[0][0] = 0;
  for(i=1; i<N; i++){
    for(j=1; j<=M; j++){

        if (j >= P[i - 1]){

        if (tabla[i - 1][j] == 0){  
          tabla[i][j] = B[i - 1];
        }

        tabla[i][j] = max(tabla[i - 1][j], B[i - 1] + tabla[i - 1][j - P[i - 1]]);

      } else { 
	  		tabla[i][j] = tabla[i - 1][j];
		  }                
    }
  }

  
  // Impreso de la tabla
  cout << "Tabla de ganancias:" << endl;

  for(i=0; i<=N; i++){	
    if (i==0){  // Impresión de la numeración
      cout << "   ";

      for(j=0; j<=M; j++){
        cout << j;
        if(j < 10){
          cout << "  ";
        } else {
          cout << " ";
        } 
      }

    } else {    // Impresión de los valores
      cout << i-1 << "  ";

      for(j=0; j<=M; j++){
        if(tabla[i-1][j] < 10){
            cout << tabla[i-1][j] << "  ";
        } else {
            cout << tabla[i-1][j] << " ";
        }  
      }
    } 

    cout << endl;
  }


  // Devolver los elemento que cabrían en la mochila reportando el máximo beneficio.
  i = N - 1; 
  j = M;
  int num_elementos=0; 

	while( i > 0 && j > 0){ 

		if ( tabla[i][j] != tabla[i - 1][j] ){ //se incluye el objeto actual

			Sol[i - 1] = 1;
			j = j - P[i - 1]; //se elimina el peso del objeto incluido

      num_elementos++;
		}

		i--;
	}

  return num_elementos; // Devuelve la cantidad de elementos que cabrían en la mochila reportando el máximo beneficio.
}




int main(){
  int tam_vector = 4, peso_max_mochila = 5;
  vector<int> vector_peso = {1, 3, 2, 4}, vector_valor = {10, 20, 15, 20}, Sol_vector(tam_vector);
  int Sol_nun_elementos, valor_total;

  // Imprimir por pantalla los valores
  for(int j=0; j<tam_vector; j++){
    
    cout << j + 1 << "º elemento de " << vector_valor[j] << " u.v." << " con un peso de " << vector_peso[j] << " u.p." << endl;
  }
  cout << endl;


  // La función devolverá la cantidad de elementos que la mochila puede llevar reportando el máximo beneficio.
  Sol_nun_elementos = mochila(tam_vector + 1, vector_peso, vector_valor, peso_max_mochila, Sol_vector);
  

  // Obtenemos el valor total que lleva la mochila
  for(int z=0; z<tam_vector; z++){
    if(Sol_vector[z] != 0){
        valor_total = valor_total + vector_valor[z];
    }
  }

  // Imprimimos la solución por pantalla
  cout << endl << "El número de elementos que puede llevar una mochila de " << peso_max_mochila << " u.p. reportando el máximo beneficio son:" << endl;
  cout << Sol_nun_elementos << " elementos con un beneficio de " << valor_total << " u.v." << endl;

  for(int i=0; i<tam_vector; i++){
    if(Sol_vector[i] != 0){
        cout << " " << i + 1 << "º elemento de " << vector_valor[i] << " u.v." << " con un peso de " << vector_peso[i] << " u.p." << endl;
    }
  }

  return 0;
}

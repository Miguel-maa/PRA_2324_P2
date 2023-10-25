#include <iostream>
#include <vector>

using namespace std;


int Cambio(vector<int>& V, int N, int M, vector<int>& Sol){
  int tabla[N][M+1];  // Creación la tabla
  int i, j;
  
  // Inicialización de la tabla
  for(i=0; i<N; i++){	
    for(j=0; j<=M; j++){
      tabla[i][j]=-1;
    }
  }
  
  // Rellenado de la tabla
  tabla[0][0] = 0;	
  for(i=0; i<N; i++){     
    for(j=0; j<=M; j++){
      if(i==0){   // Rellenado de la primera fila
	      if(j >= V[0] && tabla[0][j - V[0]] != -1){
	        tabla[0][j]= 1 + tabla[0][j - V[0]];
	      }
	
      } else {    // Rellenado de las siguientes filas
        tabla[i][0] = 0;

	      if(j < V[i] || tabla[i][j - V[i]] == -1){
	        tabla[i][j]= tabla[i - 1][j];
			
	      } else if(tabla[i - 1][j] != -1){
	        tabla[i][j] = min(tabla[i - 1][j], 1 + tabla[i][j - V[i]]);
	  
	      } else { 
	        tabla[i][j] = 1 + tabla[i][j - V[i]];
	      }
      }
    }
  }


  // Impreso de la tabla
  cout << "Tabla de ganancias:" << endl;

  for(i=0; i<=N; i++){	
    if (i==0){  // Impresión de la numeración
      cout << "     ";

      for(j=0; j<=M; j++){
        cout << j;
        if(j < 10){
          cout << "  ";
        } else {
          cout << " ";
        } 
      }

    } else {    // Impresión de los valores
      cout << i-1 << "{" << V[i-1] << "}" << " ";

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


  // Devolver la cantidad de monedas de cada tipo
  if(tabla[N-1][M] != -1){
    i = N-1;
    j = M; 

    while(i>=0 && j!=0){
      if(i == 0 || tabla[i][j] != tabla[i - 1][j]){
        Sol[i] = Sol[i] + 1;
        j = j - V[i];

      } else {
        i = i - 1;
      } 
    }
  } 

  return tabla[N-1][M]; // Devuelve la cantidad mínima de monedas a devolver
}




int main(){
  int tam_vector = 3, moneda = 8;
  vector<int> vector = {1, 4, 6}, Sol_vector(tam_vector);
  int Sol_nun_moneda;

  // Imprimir por pantalla los valores
  cout << "Tenemos monedas de los siguientes valores:" << endl;

  for(int j=0; j<tam_vector; j++){
    cout << " Monedas de " << vector[j] << " u.v." << endl;
  }
  cout << endl;

  // La función devolverá la cantidad mínima de monedas a devolver o -1 si no hay solución.
  Sol_nun_moneda = Cambio(vector, tam_vector, moneda, Sol_vector);
  

  // Imprimimos la solución por pantalla
  if(Sol_nun_moneda != -1){
    cout << endl << "La cantidad mínima de monedas para devolver " << moneda << " u.v. son: " << Sol_nun_moneda << " monedas" << endl;
    
    for(int i=0; i<tam_vector; i++){
      if(Sol_vector[i] != 0){
        cout << " " << Sol_vector[i] << " monedas de " << vector[i] << " u.v." << endl;
      }
    }

  } else {
    cout << endl << "No hay solución" << endl;
  } 

  return 0;
}

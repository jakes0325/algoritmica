/*
4) Crear y cargar una matriz dinámica y con el siguiente menú de selección, desarrolla las rutinas para cada uno:
- cargarMatriz: se encargará de agregar elementos a la matriz dinámica.
- mostrarMatriz: se encargará de mostrar los elementos cargados en la matriz dinámica.
- sumaDP: se encargará de hallar la sumatoria de los elementos de la diagonal principal. 
*/
#include <iostream>
#include <windows.h>
#include <stdlib.h>
using namespace std;

void cargarMatriz();
void mostrarMatriz(int **, int, int);
void sumaDP(int **, int, int);

int **puntero_matriz, nfilas, ncol;

int main(){
	cargarMatriz();
	mostrarMatriz(puntero_matriz, nfilas, ncol);
	sumaDP(puntero_matriz, nfilas, ncol);
	
	for(int f=0;f<nfilas;f++){
		delete [] puntero_matriz[f];
	}
	delete [] puntero_matriz;
	
	cout<<endl;
	return 0;
	system("pause");
}

void cargarMatriz(){
	cout<<"Ingrese numero de filas: ";
	cin>>nfilas;
	cout<<"Ingrese numero de columnas: ";
	cin>>ncol;
	
	puntero_matriz = new int *[nfilas];
	
	for(int c=0;c<nfilas;c++){
		puntero_matriz[c] = new int[ncol];
	}
	
	for(int f=0;f<nfilas;f++){
		for(int c=0;c<ncol;c++){
			cout<<"Poscicion -> ("<<f<<")("<<c<<") ";
			cin>> *(*(puntero_matriz+f)+c);
		}
	}
}

void mostrarMatriz(int **puntero_matriz, int nfilas, int ncol){
	cout<<"\nMatriz cargada: "<<endl;
	for(int f=0;f<nfilas;f++){
		for(int c=0;c<ncol;c++){
			cout<< *(*(puntero_matriz+f)+c)<<" ";
		}
		cout<<endl;
	}
}

void sumaDP(int **puntero_matriz, int nfilas, int ncol){
	
	int sp=0;
	
	for(int f=0;f<nfilas;f++){
		for(int c=0;c<ncol;c++){
			if(f==c){
				sp = sp + *(*(puntero_matriz+f)+c);
			}
		}
	}
	cout<<"La sumatoria de la diagonal principal es: "<<sp<<endl;
}








































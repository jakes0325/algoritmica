/*
		Crear y cargar una matriz din�mica y con el siguiente men� de selecci�n, desarrolla las rutinas para cada uno:
	- cargarMatriz: se encargar� de agregar elementos a la matriz din�mica.
	- mostrarMatriz: se encargar� de mostrar los elementos cargados en la matriz din�mica.
	- sumaDP: se encargar� de hallar la sumatoria de los elementos de la diagonal principal. 
*/
#include<iostream>
#include<windows.h>
using namespace std;

int ntamao();
void cargarmatriz(int**,int);
void imprimirmatriz(int**,int);
void sumaDP(int**,int);
main(){
	int **matriz;
	int l=ntamao();
	matriz = new int *[l];
	for(int c=0;c<l;c++){
		matriz[c] = new int [l];
	}
	cargarmatriz(matriz,l);
	imprimirmatriz(matriz, l);
	sumaDP(matriz, l);
	system("pause");
	system("cls");
	
}
int ntamao(){
	int l;
	do{
		cout<<"ingrese tama�o de la matriz: ";cin>>l;
		while(!cin.good()){
			cin.clear();
			fflush(stdin);
			cout<<"solo se pueden ingresar nros: ";cin>>l;
		}
	}while(l<=0);
	return l;
}

void cargarmatriz(int** matriz,int limite){
	for(int f=0;f<limite;f++){
		for(int c=0;c<limite;c++){
			cout<<"ingrese nro ["<<f+1<<"] ["<<c+1<<"] ->";cin>>*(*(matriz+f)+c);
			while(!cin.good()){
				cin.clear();
				fflush(stdin);
				cout<<"solo se pueden ingresar nros \n intente de nuevo["<<f<<"] ["<<c<<"] ->";cin>>*(*(matriz+f)+c);
			}
		}
	}
}

void imprimirmatriz(int** matriz,int limite){
	for(int f=0;f<limite;f++){
		for(int c=0;c<limite;c++){
			cout<<*(*(matriz+f)+c)<<"  ";
		}
		cout<<endl;
	}
	
}

void sumaDP(int** matriz,int limite){
	int suma=0;
	for(int f=0;f<limite;f++){
		for(int c=0;c<limite;c++){
			if(f==c){
				suma=suma+ *(*(matriz+f)+c);
			}
		}
	}
	cout<<"LA SUMA DE LA DP ES :"<<suma<<endl;
}
	


/*
		Crear y cargar una matriz dinámica y con el siguiente menú de selección, desarrolla las rutinas para cada uno:
	- cargarMatriz: se encargará de agregar elementos a la matriz dinámica.
	- mostrarMatriz: se encargará de mostrar los elementos cargados en la matriz dinámica.
	- sumaDP: se encargará de hallar la sumatoria de los elementos de la diagonal principal.
*/
#include<iostream>
#include<windows.h>
using namespace std;

int limite();
void cargarMatriz(int **,int);
void mostrarMatriz(int **,int);
void sumaDP(int **,int);
main(){
	int l=limite();
	int M[l][l];
	int**vector=new int*[l];
	for(int f=0;f<l;f++){
		*vector[f]=&M[f][0];
	}
	cargarMatriz(vector,l);
	mostrarMatriz(vector,l);
	sumaDP(vector,l);
	
	
	
	
	
	
	
	
	
	system("pause");
	system("cls");
	
}
int limite(){
	int n;
	do{
		cout<<"ingrese limite para matriz: ";cin>>n;
		while(!cin.good()){
			cin.clear();
			fflush(stdin);
			cout<<"solo se aceptan numeros ";
			cin>>n;
		}
	}while(n<=0);
	return n;
}
void cargarMatriz(int **vector,int n){
	for(int f=0;f<n;f++){
		for(int c=0;c<n;c++){
			cout<<"ingrese nro pos->("<<f+1<<","<<c+1<<"):";cin**(vector+f+c);
		}
	}
}
void mostrarMatriz(int **vector,int n){
	for(int f=0;f<n;f++){
		for(int c=0;c<n;c++){
			cout<<**(vector+f+c)<<" - ";
		}
		cout<<endl;
	}
}
void sumaDP(int **vecor,int n){
	int suma=0;
	for(int f=0;f<n;f++){
		for(int c=0;c<n;c++){
			if(f==c){
				suma= suma + **(vector+f+c);	
			}
		}
	}
	cout<<"LA SUMA DE LA DP ES: "<<suma<<endl;
}

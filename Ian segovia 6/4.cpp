/*
	 Crear y cargar una matriz B de orden 6x5. Llenar cada fila impar con el teclado
	y las filas pares con los elementos invertidos de la fila anterior utilizando pilas.
	Imprimir la matriz
*/
#include<iostream>
#include<windows.h>
using namespace std;
struct nodo{
	int dato;
	nodo* siguiente;	
};
void cargar_pila(int,nodo*&);
void imprimir_pila(int&,nodo*&);
main(){
	int B[6][5]={NULL};
	nodo* pila=NULL;
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<"----------------------CARGAR MATRIZ------------------------------"<<endl;
	cout<<"-----------------------------------------------------------------"<<endl;
	for(int f=0;f<6;f++){
		for(int c=0;c<5;c++){
			if((f+1)%2!=0){
				cout<<"ingrese nro("<<f+1<<")("<<c+1<<")-> ";cin>>B[f][c];
				while(!cin.good()){
					cin.clear();
					fflush(stdin);
					cout<<"ERROR. solo se pueden ingresar nros. \nintente de nuevo("<<f+1<<")("<<c+1<<")-> ";cin>>B[f][c];
				}
				cargar_pila(B[f][c],pila);
			}else{
				imprimir_pila(B[f][c],pila);		
			}
		}
	}
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<"----------------------MATRIZ CARGADA-----------------------------"<<endl;
	cout<<"-----------------------------------------------------------------"<<endl;
	for(int f=0;f<6;f++){
		for(int c=0;c<5;c++){
			cout<<B[f][c]<<" - ";
		}
		cout<<endl;
	}
	cout<<"-----------------------------------------------------------------"<<endl;
	
	
	
	
	
	
	
	
	
	
	system("pause");
	system("cls");
}
void cargar_pila(int n,nodo*& pila){
	nodo* n_nuevo=new nodo();
	n_nuevo->dato=n;
	n_nuevo->siguiente=pila;
	pila=n_nuevo;
}
void imprimir_pila(int&n,nodo*&pila){
	nodo* aux=pila;
	n=aux->dato;
	pila=aux->siguiente;
	delete aux;
}

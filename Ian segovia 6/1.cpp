/*
	Hacer un programa para agregar n�meros enteros a una pila, hasta que el
	usuario lo decida, despu�s mostrar todos os n�meros introducidos en la pila. 
*/
#include<iostream>
#include<windows.h>
#include<string.h>
using namespace std;

struct nodo{
	int dato;
	nodo *siguiente;		
};
void cargar_pila(int,nodo*&);
void imprimir_pila(int&,nodo*&);

main(void){
	int n;
	nodo* pila=NULL;
	for(int c=0;c<5;c++){
			cout<<"ingrese nro: ";cin>>n;
		while(!cin.good()){
			cin.clear();
			fflush(stdin);
			cout<<"solo se permiten nros ingrese de nuevo: ";cin>>n;
		}
		cargar_pila(n,pila);
	}
	for(int c=0;c<5;c++){
		imprimir_pila(n,pila);
		cout<<n<<" - ";
	}
	cout<<endl;

	system("pause");
	system("cls");
}
void cargar_pila(int dato,nodo*& pila){
	nodo* n_nodo = new nodo();
	n_nodo->dato = dato;
	n_nodo->siguiente = pila;
	pila = n_nodo;
}
void imprimir_pila(int& dato,nodo*& pila){
	nodo* aux= pila;
	dato = aux->dato;
	pila = aux->siguiente;
	delete aux;
}

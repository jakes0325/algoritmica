/*
	Crear un programa que permita hacer un sorteo entre 200 boletas vendidas
	con los siguientes premios en el orden indicado:
	- Primer Premio: un iphone X
	- Segundo Premio: un PlayStation 4
	- Tercer premio: Pendrive de 1TB
	- Cuarto premio: Pulsera Mi Band3
	Mostrar los premios del cuarto al primero utilizando pilas. 
*/
#include<iostream>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>


using namespace std;
struct nodo{
	string dato;
	nodo* siguiente;	
};
void cargar_pila(string,nodo*&);
void imprimir_pila(string&,nodo*&);

main(){
	nodo* pila = NULL;
	srand (time(NULL));
	cargar_pila("un iphone x",pila);
	cargar_pila("un playstation 4",pila);
	cargar_pila("pendrive de 1TB",pila);
	cargar_pila("Pulsera Mi Band3",pila);
	int random=NULL;
	string premio;
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<"-------------------------SORTEO----------------------------------"<<endl;
	cout<<"-----------------------------------------------------------------"<<endl;
	for(int c=0;c<4;c++){
		random=rand() % 200 +1;
		imprimir_pila(premio,pila);
		cout<<"\tEl nro ganador de "<<premio<<" es : "<<random<<endl;
		
	}
	cout<<"-----------------------------------------------------------------"<<endl;
	
	
	
	
	
	
	system("pause");
	system("cls");
	
}
void cargar_pila(string n,nodo*& pila){
	nodo* n_nuevo = new nodo();
	n_nuevo->dato=n;
	n_nuevo->siguiente=pila;
	pila=n_nuevo;
}
void imprimir_pila(string&n,nodo*& pila){
	nodo* aux=pila;
	n=aux->dato;
	pila=aux->siguiente;
	delete aux;
}











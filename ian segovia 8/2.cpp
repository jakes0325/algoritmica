/*
	Cargar un vector N con la ayuda de una pila. Imprimir el vector cargado. 
*/
#include<iostream>
#include<windows.h>

using namespace std;

struct nodo{
	int dato;
	nodo *siguiente;	
};
void cargar_pila(nodo*&,int);
int imprimir_pila(nodo*&);
int nlimite(void);
main(){
	nodo*pila=NULL;
	int dato;
	int l=nlimite();
	int N[l];
	for(int c=0;c<l;c++){
		cout<<"ingrese nro: ";cin>>dato;
		while(!cin.good()){
			cin.clear();
			fflush(stdin);
			cout<<"ERROR. solo se permiten nros \nintente de nuevo: ";cin>>dato;
		}
		cargar_pila(pila,dato);
	}
	int f=0;
	while(pila!=NULL){
		N[f]=imprimir_pila(pila);
		f++;
	}
	for(int c=0;c<l;c++){
		if(c==(l-1)){
			cout<<N[c]<<endl;
		}else{
			cout<<N[c]<<" - ";	
		}		
	}	
	system("pause");
	system("cls");
}
void cargar_pila(nodo*& pila,int n){
	nodo *n_nuevo=new nodo;
	n_nuevo->dato=n;
	n_nuevo->siguiente=pila;
	pila=n_nuevo;
}
int imprimir_pila(nodo*& pila){
	int n;
	nodo *aux= pila;
	n=aux->dato;
	pila=aux->siguiente;
	delete aux;
	return n;
}
int nlimite(void){
	int n;
	do{
		cout<<"ingrese limite para su vector: ";cin>>n;
		while(!cin.good()){
			cin.clear();
			fflush(stdin);
			cout<<"ERROR. solo se pueden ingresar numeros\n intente de nuevo: ";cin>>n;
		}
	}while(n<=0);
	return n;
	
}





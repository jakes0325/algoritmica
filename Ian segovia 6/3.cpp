/*
	Crear y cargar un vector A. Invertir los valores del vector utilizando pilas. 
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
int nlimite(void);
main(){
	int n=nlimite();
	nodo* pila=NULL;
	int A[n];
	for(int c=0;c<n;c++){
		cout<<"ingrese nro ("<<c+1<<") ->";cin>>A[c];
		while(!cin.good()){
			cin.clear();
			fflush(stdin);
			cout<<"ERROR. solo se permiten nros.\ningrese de nuevo nro ("<<c+1<<") ->";cin>>A[c];
		}
	}
	for(int c=0;c<n;c++){cargar_pila(A[c],pila);
	}
	for(int c=0;c<n;c++){imprimir_pila(A[c],pila);}
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<"\t-EL VECTO INVERTIDO -"<<endl<<"\t";
	for(int c=0;c<n;c++){
		cout<<A[c]<<" - ";
	}
	cout<<endl<<"-----------------------------------------------------------------"<<endl;
	
	
	
	
	
	
	
	
	
	
	
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
int nlimite(void){
	int l;
	do{
		cout<<"ingrese un nro para el limite de su vector: ";cin>>l;
		while(!cin.good()){
			cin.clear();
			fflush(stdin);
			cout<<"ERROR. solo se pueden ingresar nros\n ingrese de nuevo: ";cin>>l;
		}
	}while(l<=0);
	return l;
}



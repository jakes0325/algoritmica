/*
	Crear y cargar 4 vectores A, B, C y D. Con ellos cargar una cola de datos el
	cual, luego se descargara en el vector D que contendrán los valores de A, B
	y C.
*/
#include<iostream>
#include<windows.h>
using namespace std;

struct nodo{
	int dato;
	nodo* siguiente;	
};
void cargar_cola(nodo*&,nodo*&,int);
void imprimir_cola(nodo*&,nodo*&,int&);
bool cola_vacia(nodo*);
int nlimite(void);
void cargar_vectores(int*&,int);
main(){
	int n;
	int l;
	l=nlimite();
	nodo*frente=NULL,*fin=NULL;
	int *A=new int [l];
	int *B=new int [l];
	int *C=new int [l];
	int *D=new int [l];
	cout<<"CARGAR VECTORES"<<endl;
	cout<<"VECTOR A"<<endl;
	cargar_vectores(A,l);
	cout<<"VECTOR B"<<endl;
	cargar_vectores(B,l);
	cout<<"VECTOR C"<<endl;
	cargar_vectores(C,l);
	cout<<"VECTOR D"<<endl;
	cargar_vectores(D,l);
	for(int c=0;c<l;c++){
		cargar_cola(frente,fin,A[c]);	
	}
	for(int c=0;c<l;c++){
		cargar_cola(frente,fin,B[c]);	
	}
	for(int c=0;c<l;c++){
		cargar_cola(frente,fin,C[c]);	
	}
	for(int c=0;c<l;c++){
		cargar_cola(frente,fin,D[c]);	
	}
	cout<<"LA COLA CARGADA"<<endl;
	while(frente!=NULL){
		imprimir_cola(frente,fin,n);
		cout<<n<<" - ";
	}
	cout<<endl;	
	system("pause");
	system("cls");
}
void cargar_cola(nodo*& frente,nodo*& fin,int n){
	nodo *n_nuevo= new nodo;
	n_nuevo->dato=n;
	n_nuevo->siguiente=NULL;
	if(cola_vacia(frente)){
		frente=n_nuevo;
	}else{
		fin->siguiente=n_nuevo;
	}
	fin=n_nuevo;
}
bool cola_vacia(nodo*frente){
	if(frente==NULL){
		return true;
	}else{
		return false;
	}
}
void imprimir_cola(nodo*& frente,nodo*& fin,int&n){
	nodo *aux=frente;
	n=frente->dato;
	if(frente==fin){
		frente=NULL;
		fin=NULL;
	}else{
		frente=frente->siguiente;
	}
	delete aux;
}
int nlimite(void){
	int n;
	do{
		cout<<"ingrese limite para los vectores: ";cin>>n;
		while(!cin.good()){
			cin.clear();
			fflush(stdin);
			cout<<"ERROR. solo se permiten numeros\n intente de nuevo: ";cin>>n;
		}
	}while(n<=0);
	return n;
	
}
void cargar_vectores(int*&v,int l){
	for(int c=0;c<l;c++){
		cout<<"ingrese nro("<<c+1<<") ->";cin>>*(v+c);
	}
}

/*
	– Hacer un programa para agregar números enteros a una cola, hasta que el
	usuario lo decida, después mostrar todos os números introducidos en la cola.
*/
#include<iostream>
#include<windows.h>
#include<string.h>
#include<locale>
using namespace std;

struct nodo{
	int dato;
	nodo *siguiente;
};
void cargar_cola(nodo*&,nodo*&,int);
void imprimir_cola(nodo*&,nodo*&,int&);
bool cola_vacia(nodo*);

int main(void){
	int n,sw;
	string op;
	nodo*frente=NULL,*fin=NULL;
	do{
		cout<<"ingrese nro: ";cin>>n;
		while(!cin.good()){
			cin.clear();
			fflush(stdin);
			cout<<"ERROR.solo se permiten numeros\n ingrese de nuevo: ";cin>>n;
		}
		
		cout<<"desea ingresar otro nro?(Si - No): ";
		do{
			fflush(stdin);
			getline(cin,op);
			for(int c=0;c<op.length();c++){
				op[c]=toupper(op[c]);
			}
			sw=0;
			for(int c=0;(c<op.length())&&(sw==0);c++){
				if(isdigit(op[c])==true){
					cout<<"usted ingreso un nro, por favor ingrese lo indicado";
					cin.clear();
					fflush(stdin);
					cout<<endl<<" ingrese de nuevo: ";
					sw=1;
				}else if(((op.compare("SI"))!=0)&&((op.compare("NO")) != 0)){
					cout<<"ERROR ingrese (si o no):";
					sw=1;
				}
			}	
		}while(sw==1);
		cargar_cola(frente,fin,n);
	}while(op=="SI");
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
	cout<<"el nro se ingreso correctamente"<<endl;
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







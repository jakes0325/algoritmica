/*
	Crear y cargar una lista simplemente enlazada en orden decreciente. Mostrar
	los elementos de la lista.
*/
#include<iostream>
#include<windows.h>
#include<string.h>
using namespace std;

struct nodo{
	int dato;
	nodo* siguiente;
};

void cargarlista(nodo*&,int);
void imprimirlista(nodo*);
bool verificacion(nodo*);
string leer_op(void);

main(){
	nodo* lista=NULL;
	int dato;
	string op;
	do{
		cout<<"ingrese nro: ";cin>>dato;
		while(!cin.good()){
			cin.clear();
			fflush(stdin);
			cout<<"ERROR, solo se pueden ingresar nros\nintente de nuevo: ";cin>>dato;
		}
		cargarlista(lista,dato);
		cout<<"desea seguir ingresando? (si/no) : ";
		op=leer_op();
	}while(op.compare("SI")==0);
	cout<<"LISTA CARGADA\n";
	imprimirlista(lista);
	system("pause");
}
void cargarlista(nodo*& lista,int dato){
	nodo* nuevo_nodo= new nodo();
	nuevo_nodo->dato=dato;
	nodo *aux1=lista;
	nodo *aux2;
	while((aux1!=NULL)&&(aux1->dato>dato)){
		aux2=aux1;
		aux1=aux1->siguiente;
	}
	if(lista==aux1){
		lista=nuevo_nodo;
	}else{
		aux2->siguiente=nuevo_nodo;
	}
	nuevo_nodo->siguiente = aux1; 
}
bool verificacion(nodo*lista){
	if(lista==NULL){
		return true;
	}else{
		return false;
	}
}
void imprimirlista(nodo* lista){
	while(lista!=NULL){
		cout<<lista->dato<<"\n";
		lista=lista->siguiente;
	}
}
string leer_op(void){
	string a;
	int sw=0;
	 do{ 
			fflush(stdin);
			getline(cin,a);
			for(int c=0;c<a.length();c++){
				a[c]=toupper(a[c]);
			}
			sw=0;
			for(int c=0;(c<a.length())&&(sw==0);c++){
				if(isdigit(a[c])==true){
					cout<<"usted ingreso un nro, por favor ingrese lo indicado";
					cin.clear();
					fflush(stdin);
					cout<<endl<<" ingrese de nuevo: ";
					sw=1;
				}else if(((a.compare("SI"))!=0)&&((a.compare("NO")) != 0)){
					cout<<"ERROR ingrese (si o no):";
					sw=1;
				}
			}
		}while(sw==1);
		return a;
}




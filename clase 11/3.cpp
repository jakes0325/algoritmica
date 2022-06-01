/*
	Cargar una lista hasta que el usuario lo decida. Luego, ingresar un numero,
	buscar en la lista y decir cuantas veces se encuentra repetido o si el mismo no
	se encuentra en la lista .
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
int leer_entero(void);
string leer_op(void);
bool buscarlista(nodo*,int,int&);

main(){
	int c=0;
	nodo*lista=NULL;
	int dato,men,may;
	string op;
	cout<<"-CARGAR LISTA-\n";
	do{
		cout<<"ingrese nro: ";
		dato=leer_entero();
		cargarlista(lista,dato);
		cout<<"desea continuar? (si - no): ";
		op=leer_op();
	}while(op.compare("SI")==0);
	cout<<"-BUSCAR UN NRO-\n";
	cout<<"ingrese el nro que desea buscar:";
	dato=leer_entero();
	if(buscarlista(lista,dato,c)){
		cout<<"el nro "<<dato<<" se encontro una cantidad de: "<<c<<" veces\n";
	}else{
		cout<<"el nro "<<dato<<" no se ha encontrado\n";
	}
	
	cout<<"-IMPRIMIR LISTA-\n";
	imprimirlista(lista);
		
	
	
	system("pause");	
	system("cls");	
}
void cargarlista(nodo*& lista,int n){
	nodo* nuevo_nodo=new nodo();
	nuevo_nodo->dato=n;
	nodo* aux1=lista;
	nodo* aux2=NULL;
	while(aux1!=NULL){
		aux2=aux1;
		aux1=aux1->siguiente;
	}
	if(lista==aux1){
		lista=nuevo_nodo;
	}else{
		aux2->siguiente=nuevo_nodo;
	}
	nuevo_nodo->siguiente=aux1;
}
void imprimirlista(nodo* lista){
	nodo* actual=lista;
	while(actual!=NULL){
		cout<<actual->dato<<" - ";
		actual=actual->siguiente;
	}
	cout<<endl;
}
int leer_entero(void){
	int n;
	cin>>n;
	while(!cin.good()){
		cin.clear();
		fflush(stdin);
		cout<<"ERROR.solo se permiten nros.\nvuelva a intentar:";
		cin>>n;
	}
	return n;
}
string leer_op(void){
	string a;
	int sw=0;	
	do{
		sw=0;
		fflush(stdin);
		getline(cin,a);
		for(int c=0;c<a.length();c++){
			a[c]=toupper(a[c]);
		}
		for(int c=0;(c<a.length())&&(sw==0);c++){
			if(isdigit(a[c])){
				cout<<"usted a ingresado un nro, por favor vuelva a intentarlo:";
				sw=1;
			}else if((a.compare("SI")!=0)&&(a.compare("NO")!=0)){
				cout<<"ingrese una opcion correcta(si/no):";
				sw=1;
			}
		}
	}while(sw==1);
	return a;
}
bool buscarlista(nodo* lista,int n,int&c){
	bool sw=false;
	nodo* aux=lista;
	while(aux!=NULL){
		if(aux->dato==n){
			sw = true;
			c++;
			aux=aux->siguiente;
		}else{
			aux=aux->siguiente;
		}
	}
	return sw;
}










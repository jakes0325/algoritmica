/*
	Crear una lista de pedidos para un local de comida rápida, donde, cada cliente solo
	podrá realizar un pedido por vez. Para ello, se debe anotar: nombre, comida, precio.
	Imprimir la lista de pedidos
*/
#include<iostream>
#include<windows.h>
#include<string.h>

using namespace std;

struct nodo{
	string nombre;
	string comida;
	int precio;
	nodo* siguiente;	
};
void cargar_cola(nodo*&,nodo*&,int,string,string);
void imprimir_cola(nodo*&,nodo*&,int&,string&,string&);
bool verificacion_frente(nodo*);
string leer_caracteres(void);
string leer_op(void);

main(){
	nodo* frente=NULL,*fin=NULL;
	int precio;
	string nombre,comida,op;
	cout<<"-----------------------------------------------------------------"<<endl;
	do{
		cout<<"ingrese nombre del cliente: ";
		nombre=leer_caracteres();
		cout<<"ingrese comida del cliente: ";
		comida=leer_caracteres();
		cout<<"ingrese precio de la comida: ";cin>>precio;
		while(!cin.good()){
			cin.clear();
			fflush(stdin);
			cout<<"Erro ingrese nros en este espacio\nintente de nuevo: ";cin>>precio;
		}
		cargar_cola(frente,fin,precio,nombre,comida);
		cout<<"desea continuar (si // no): ";
		op=leer_op();
	}while(op.compare("SI")==0);
	system("cls");
	cout<<"-----------------------------------------------------------------"<<endl;
	while(frente!=NULL){
		cout<<"-----------------------------------------------------------------"<<endl;
		imprimir_cola(frente,fin,precio,nombre,comida);
		cout<<"-CLIENTE-"<<endl;
		cout<<"Nombre: "<<nombre<<endl;
		cout<<"Comida: "<<comida<<endl;
		cout<<"Precio: "<<precio<<endl;
		cout<<"-----------------------------------------------------------------"<<endl;
	}
	
	cout<<"-----------------------------------------------------------------"<<endl;
	
	
	
	
	
	
	
	
	
	
	system("pause");
	system("cls");
}
void cargar_cola(nodo*& frente,nodo*& fin,int precio,string nombre,string comida){
	nodo* n_nuevo= new nodo;
	n_nuevo->comida=comida;
	n_nuevo->nombre=nombre;
	n_nuevo->precio=precio;
	n_nuevo->siguiente=NULL;
	if(verificacion_frente(frente)){
		frente=n_nuevo;
	}else{
		fin->siguiente=n_nuevo;
	}
	fin=n_nuevo;
}
bool verificacion_frente(nodo*frente){
	if(frente==NULL){
		return true;
	}else{
		
		return false;
	}
}
void imprimir_cola(nodo*& frente,nodo*& fin,int& precio,string& nombre,string& comida){
	nodo *aux=frente;
	comida=frente->comida;
	nombre=frente->nombre;
	precio=frente->precio;
	if(frente==fin){
		frente=NULL;
		fin=NULL;
	}else{
		frente=frente->siguiente;	
	}	
	delete aux;
}
string leer_caracteres(){
	string a;
	int sw=0;
	 do{
			fflush(stdin);
			getline(cin,a);
			sw=0;
			for(int c=0;(c<a.length())&&(sw==0);c++){
				if(isdigit(a[c])==true){
					cout<<"usted ingreso un nro, por favor ingrese lo indicado";
					cin.clear();
					fflush(stdin);
					cout<<endl<<" ingrese de nuevo: ";
					sw=1;
				}
			}
		}while(sw==1);
		return a;
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

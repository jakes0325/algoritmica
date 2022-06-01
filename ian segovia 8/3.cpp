/*
	Crear una lista que permita ingresar los datos de un conjunto de personas, teniendo en
	cuenta los siguientes campos: nombre, edad. Imprimir la lista de las personas que
	tengan la mayoría de edad y decir cuántas de las personas son menores de edad.
*/
#include<iostream>
#include<windows.h>
#include<string.h>

using namespace std;

struct nodo{
	string nombre;
	int edad;
	nodo* siguiente;
};
void cargar_cola(nodo*&,nodo*&,int,string);
void imprimir_cola(nodo*&,nodo*&,int&,string&);
bool cola_vacia(nodo*);
string leer_caracteres(void);
string leer_op(void);
main(){
	nodo *frente=NULL,*fin=NULL;
	string op,nombre;
	int edad;
	do{
		cout<<"ingrese nombre: ";
		nombre = leer_caracteres();
		do{
			cout<<"ingrese edad: ";cin>>edad;
			while(!cin.good()){
			cin.clear();
			fflush(stdin);
			cout<<"ERROR. solo se pueden ingresar nros\nvuelva a intentar: ";cin>>edad;
			}
		}while((edad<=0)||(edad>110));
		cout<<"desea seguir ingresando? (si // no) ";
		op = leer_op();
		cargar_cola(frente,fin,edad,nombre);
	}while(op.compare("SI")==0);
	int cm=0;
	while(frente!=NULL){
		imprimir_cola(frente,fin,edad,nombre);
		if(edad<17){
			cm++;
		}else{
			cout<<"Nombre: "<<nombre<<endl;
			cout<<"Edad: "<<edad<<endl;
		}
	}
	cout<<"la cantidad de menores es: "<<cm<<endl;
	
	system("pause");
	system("cls");
}
void cargar_cola(nodo*& frente,nodo*& fin,int n,string a){
	nodo *n_nuevo = new nodo;
	n_nuevo->edad=n;
	n_nuevo->nombre=a;
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
void imprimir_cola(nodo*& frente,nodo*& fin,int& n,string& a){
	nodo *aux=frente;
	n=frente->edad;
	a=frente->nombre;
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









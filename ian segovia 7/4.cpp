/*
	– Crear una lista de recepción para un consultorio medico registrando el
	nombre de los pacientes. Imprimir la lista de los pacientes y el nro que le
	corresponde en la consulta
*/
#include<iostream>
#include<windows.h>
#include<string.h>


using namespace std;
struct nodo{
	string nombre;
	int dato;
	nodo* siguiente;
};
void cargar_cola(nodo*&,nodo*&,int,string);
void imprimir_cola(nodo*&,nodo*&,int&,string&);
bool cola_vacia(nodo*);
string leer_caracteres(void);
string leer_op(void);
main(){
	string nombre,op;
	int nro=0;
	nodo *frente=NULL,*fin=NULL;
	do{
		cout<<"ingrese nombre del paciente: ";
		nombre=leer_caracteres();
		nro++;
		cout<<"desea continuar ingresando? (si // no): ";
		op=leer_op();
		cargar_cola(frente,fin,nro,nombre);
	}while(((op.compare("SI"))==0)||((op.compare("S"))==0));
	system("cls");
	cout<<"-----------------------------------------------------------------------------"<<endl;
	while(frente!=NULL){
		imprimir_cola(frente,fin,nro,nombre);
		cout<<"Numero de la consulta: ("<<nro<<") // Nombre: "<<nombre<<endl;
	}
	cout<<"-----------------------------------------------------------------------------"<<endl;


	system("pause");
	system("cls");

}
void cargar_cola(nodo*& frente,nodo*& fin,int n,string a){
	nodo *n_nuevo = new nodo;
	n_nuevo->dato=n;
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
	n=frente->dato;
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

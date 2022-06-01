/*
	Crear una lista de puntajes de un curso para varias puntajes donde los datos a registrar
	son los siguientes: nombre, materia, puntaje. Mostrar la lista y el promedio de puntaje
	de las materias, como también el promedio general entre todas las .
*/
#include<iostream>
#include<windows.h>
#include<string.h>


using namespace std;

struct nodo{
	string nombre;
	puntajes materia;
	string materias;
	nodo* siguiente;	
};
struct puntajes{
	int matematica;
	int ciencias;
	int historia;
	int quimica;
	int fisica;
};
void cargar_cola(nodo*&,nodo*&,int,string,puntajes);
void imprimir_cola(nodo*&,nodo*&,int,string,puntajes);
string leer_caracteres(void);
string leer_op(void);
int leer_entero(void);
main(){
	nodo *frente=NULL,*fin=NULL;	
	string nombre,op;
	puntajes materia;
	string materias;
	float promedio_puntajesomedio_general;
	cout<<"-----------------------------------------------------------------"<<endl;
	do{
		cout<<"ingrese nombre del alumno: ";
		nombre=leer_caracteres();
		cout<<"ingrese puntaje de matematicas: ";
		puntajes->matematica=leer_entero();
		cout<<"ingrese puntaje de ciencias: ";
		puntajes->ciencias=leer_entero();
		cout<<"ingrese puntaje de historia: ";
		puntajes->historia=leer_entero();
		cout<<"ingrese puntaje de quimica: ";
		puntajes->quimica=leer_entero();
		cout<<"ingrese puntaje de fisica: ";
		puntajes->fisica=leer_entero();
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
void cargar_cola(nodo*& frente,nodo*& fin,int puntaje,string nombre,string materia){
	nodo *n_nuevo=new nodo;
	n_nuevo->nombre=nombre;
	n_nuevo->materia=materia;
	n_nuevo->puntaje=puntaje;
	n_nuevo->siguiente=NULL;
	if(frente==NULL){
		frente=n_nuevo
	}else{
		fin->siguiente=n_nuevo;
	}
	fin=n_nuevo;
}
void imprimir_cola(nodo*& frente,nodo*& fin,int puntaje,string nombre,string materia){
	nodo *aux=frente;
	puntaje = frente->puntaje;
	nombre = frente->nombre;
	materia = frente->materia;
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
int leer_entero(void){
	int a;
	do{
		cin>>a;
		while(!cin.good()){
			cin.clear();
			fflush(stdin);
			cout<<"ERROR solo se pueden ingresar nros!\n intente de nuevo: ";cin>>a;
		}
	}while(a<0);
	return a;
}

/*
	Cargar una lista de 20 alumnos con sus calificaciones finales en una materia
	cualquiera. Imprimir la lista de reprobados en el orden que se ha cargado.
	Utiliza una cola para representar los datos.
*/
#include<iostream>
#include<windows.h>
#include<string.h>

using namespace std;
struct nodo{
	string alumno;
	int dato;
	nodo* siguiente;
};
void cargar_cola(nodo*&,nodo*&,int,string);
void imprimir_cola(nodo*&,nodo*&,int&,string&);
bool cola_vacia(nodo*);

main(){
	nodo *frente=NULL,*fin=NULL;
	int A,sw;
	string B;
	cout<<"LISTA DE ALUMNOS (20)"<<endl;
	for(int c=0;c<20;c++){
		fflush(stdin);
		cout<<"ingrese nombre del alumno("<<c+1<<"): ";
		do{
			fflush(stdin);
			getline(cin,B);
			sw=0;
			for(int c=0;(c<B.length())&&(sw==0);c++){
				if(isdigit(B[c])==true){
					cout<<"usted ingreso un nro, por favor ingrese lo indicado";
					cin.clear();
					fflush(stdin);
					cout<<endl<<" ingrese de nuevo: ";
					sw=1;
				}	
			}	
		}while(sw==1);
		do{
			cout<<"ingrese calificacion del alumno("<<c+1<<"): ";cin>>A;
			while(!cin.good()){
				cin.clear();
				fflush(stdin);
				cout<<"solo se permiten ingresar numeros\n vuelva a intentar:("<<c+1<<") ";cin>>A;
			}
		}while((A<0)||(A>5));
		if(A<2){
			cargar_cola(frente,fin,A,B);
		}
	}
	string aux1;
	int aux;
	cout<<"-----------------------------------------------------------------------------"<<endl;
	while(frente!=NULL){
		imprimir_cola(frente,fin,aux,aux1);
		cout<<"Alumno: "<<aux1<<" nota-> "<<aux<<endl;
	}
	cout<<endl<<cout<<"-----------------------------------------------------------------------------"<<endl;
	
	
	
	
	
	
	
	system("pause");
	system("cls");
}
void cargar_cola(nodo*& frente,nodo*& fin,int n,string a){
	nodo *n_nuevo = new nodo;
	n_nuevo->dato=n;
	n_nuevo->alumno=a;
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
	a=frente->alumno;
	if(frente==fin){
		frente=NULL;
		fin=NULL;
	}else{
		frente=frente->siguiente;	
	}	
	delete aux;
}







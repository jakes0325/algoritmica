/*
	Crear un registro de datos cuyos campos serán: nombre, curso, edad. Los cuáles serán
	almacenados en una pila. Imprimir la Pila cargada, en formato de tabla.
*/
#include<iostream>
#include<windows.h>
#include<string.h>
using namespace std;
struct nodo{
	string nombre;
	string curso;
	int edad;
	nodo *siguiente;	
};
void gotoxy(int x,int y){  
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
 }
void cargar_pila(nodo*&,string,string,int);
void imprimir_pila(nodo*&,string&,string&,int&);
string leer_caracteres(void);
string leer_op(void);
main(){
	nodo*pila=NULL;
	string op,nombre,curso;
	int edad;
	do{
		cout<<"ingrese nombre del alumno: ";
		nombre = leer_caracteres();
		cout<<"ingrese curso del alumno: ";
		curso = leer_caracteres();
		cout<<"ingrese edad: ";cin>>edad;
		while((!cin.good())||(edad<0)||(edad>110)){
			cin.clear();
			fflush(stdin);
			if((edad<0)||(edad>110)){
				cout<<"solo se permiten edad reales!\ningrese de nuevo: ";cin>>edad;
			}else{
				cout<<"ERROR. solo se permiten nros\n vuelva a ingresar: ";cin>>edad;
			}	
		}
		cargar_pila(pila,nombre,curso,edad);
		cout<<"desea continuar ingresando? (si // no): ";
		op=leer_op();
	}while((op.compare("SI")==0));
	system("cls");
	cout<<"----------------------------------------------------------"<<endl;
	cout<<"---NOMBRE-------------CURSO-----------------EDAD----------"<<endl;
	cout<<"----------------------------------------------------------"<<endl;
	int gotf=4;
	while(pila!=NULL){
		imprimir_pila(pila,nombre,curso,edad);
		gotoxy(3,gotf);cout<<nombre;gotoxy(21,gotf);cout<<curso;gotoxy(45,gotf);cout<<edad;
		gotf++;
	}
	cout<<endl;
	
	
	
	
	
	
	
	
	
	
	
	
	
	system("pause");
	system("cls");
}
void cargar_pila(nodo*& pila,string nombre,string curso,int edad){
	nodo *n_nuevo= new nodo;
	n_nuevo->nombre=nombre;
	n_nuevo->curso=curso;
	n_nuevo->edad=edad;
	n_nuevo->siguiente=pila;
	pila=n_nuevo;
}
void imprimir_pila(nodo*& pila,string& nombre,string& curso,int& edad){
	nodo *aux=pila;
	nombre = aux->nombre;
	curso = aux->curso;
	edad= aux->edad;
	pila=aux->siguiente;
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










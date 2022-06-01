/*
	Crear una lista de puntajes de un curso para varias puntajes donde los datos a registrar
	son los siguientes: nombre, materia, puntaje. Mostrar la lista y el promedio de puntaje
	de las materias, como también el promedio general entre todas las materias.
*/
#include<iostream>
#include<windows.h>
#include<string.h>


using namespace std;

struct nodo{
	string nombre;
	string materia;
	int puntaje;
	nodo* siguiente;	
};
//struct puntajes{
//	int matematica;
//	int ciencias;
//	int historia;
//	int quimica;
//	int fisica;
//};
void cargar_cola(nodo*&,nodo*&,int,string,string);
void imprimir_cola(nodo*&,nodo*&,int,string,string);
bool verificacion_frente(nodo*);
string leer_caracteres(void);
string leer_op(void);
int leer_entero(void);
main(){
	nodo *frente=NULL,*fin=NULL;	
	string nombre,op;
	string materia;
	int puntaje;
	float promedio_puntajes[5]={},promedio_general=0;
	cout<<"-----------------------------------------------------------------"<<endl;
	do{
		cout<<"ingrese nombre del alumno: ";
		nombre=leer_caracteres();
		do{
			cout<<"ingrese una de las 5 materias (matematica/ciencias/historia/quimica/fisica): ";
			materia=leer_caracteres();
			for(int c=0;c<materia.length();c++){
				materia[c]=toupper(materia[c]);
			}
		}while((materia.compare("MATEMATICA")!=0)&&(materia.compare("CIENCIAS")!=0)&&(materia.compare("HISTORIA")!=0)&&(materia.compare("QUIMICA")!=0)&&(materia.compare("FISICA")!=0));
		do{
			cout<<"ingrese puntaje de la materia: ";
			puntaje=leer_entero();	
		}while((puntaje<0)||(puntaje>5));
		
		cargar_cola(frente,fin,puntaje,nombre,materia);
		cout<<"desea continuar (si // no): ";
		op=leer_op();
	}while(op.compare("SI")==0);
	system("cls");
	cout<<"-----------------------------------------------------------------"<<endl;
	int c=1;
	while(frente!=NULL){
		cout<<"-----------------------------------------------------------------"<<endl;
		imprimir_cola(frente,fin,puntaje,nombre,materia);
		cout<<"-ALUMNO-"<<endl;
		cout<<"Nombre: "<<nombre<<endl;
		cout<<"Materia: "<<materia<<endl;
		cout<<"Puntaje: "<<puntaje<<endl;
		cout<<"-----------------------------------------------------------------"<<endl;
		//matematica = 1
		//ciencias = 2
		//historia =3
		//quimica = 4 
		//fisica = 5
		promedio_general=promedio_general+puntaje;
		c++;
		if(materia.compare("MATEMATICA")==0){
			promedio_puntajes[1]=promedio_puntajes[1]=+puntaje;
		}else if(materia.compare("CIENCIAS")==0){
			promedio_puntajes[2]=promedio_puntajes[2]=+puntaje;
		}else if(materia.compare("HISTORIA")==0){
			promedio_puntajes[3]=promedio_puntajes[3]=+puntaje;
		}else if(materia.compare("QUIMICA")==0){
			promedio_puntajes[4]=promedio_puntajes[4]=+puntaje;
		}else if(materia.compare("FISICA")==0){
			promedio_puntajes[5]=promedio_puntajes[5]=+puntaje;
		}
	}
	
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<"-PROMEDIO GENERAL-"<<endl;
	cout<<"Promedio -> "<<promedio_general/c<<endl;
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<"-PROMEDIO POR MATERIA-"<<endl;
	cout<<"promedio de Matematica -> "<<promedio_puntajes[1]<<endl;
	cout<<"promedio de Ciencias -> "<<promedio_puntajes[2]<<endl;
	cout<<"promedio de Historia -> "<<promedio_puntajes[3]<<endl;
	cout<<"promedio de Quimica -> "<<promedio_puntajes[4]<<endl;
	cout<<"promedio de Fisica -> "<<promedio_puntajes[5]<<endl;
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
	if(verificacion_frente(frente)){
		frente=n_nuevo;
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
bool verificacion_frente(nodo*frente){
	if(frente==NULL){
		return true;
	}else{
		
		return false;
	}
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

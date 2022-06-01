/*
	Crear una aplicación que permita realizar todas las operaciones vistas hasta
	el momento en listas enlazadas (insertar, mostrar, buscar, eliminar nodo,
	eliminar todo). Utiliza un menú para poder interactuar con el usuario

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
bool buscarlista(nodo*,int);
void eliminarnodo(nodo*&,int);
void eliminarlista(nodo*&,int&);
int leer_entero(void);
string leer_op(void);
main(){
	nodo* lista=NULL;
	string op;
	int dato,menu;
	
	do{
		cout<<"-MENU-\n";
		cout<<"1-cargar lista\n2-imprimir lista\n3-buscar algun elemento de la lista\n4-eliminar algun elemento\n5-borrar toda la lista\n6-salir\nseleccionar opcion: ";
		do{
			menu=leer_entero();	
		}while((menu<0)||(menu>6));
			switch(menu){
				case 1:
					system("pause");
					system("cls");
					cout<<"-CARGAR LISTA-\n";
					do{
						
						cout<<"ingrese nro: ";
						dato=leer_entero();
						cargarlista(lista,dato);
						cout<<"desea continuar? (si - no): ";
						op=leer_op();
					}while(op.compare("SI")==0);
					break;
				case 2:
					system("pause");
					system("cls");
					cout<<"-IMPRIMIR LISTA-\n";
					imprimirlista(lista);
					break;
				case 3:
					system("pause");
					system("cls");
					cout<<"-BUSCAR UN DATO-\n";
					cout<<"ingrese el dato el cual quiere buscar:";
					dato=leer_entero();
					if(buscarlista(lista,dato)){
						cout<<"El elemento "<<dato<<" fue encontrado.\n";
					}else{
						cout<<"El elemento "<<dato<<" no fue encontrado.\n";
					}
					break;
				case 4:
					system("pause");
					system("cls");
					cout<<"-ELIMINAR UN ELEMENTO-\n";
					cout<<"ingrese el dato que quiera eliminar: ";
					dato=leer_entero();
					eliminarnodo(lista,dato);
					break;
				case 5:
					system("pause");
					system("cls");
					cout<<"-ELIMINAR TODA-\n";
					while(lista!=NULL){
						eliminarlista(lista,dato);
						cout<<"El elemento "<<dato<<" se a eliminado\n";	
					}
					
					
					break;
				case 6:
					system("pause");
					system("cls");
					cout<<"GRACIAS POR USAR EL PROGRAMA!!\n";
					break;
			}
				
					
				
	}while(menu!=6);
	system("pause");
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
bool buscarlista(nodo* lista,int n){
	nodo* aux=lista;
	while(aux!=NULL){
		if(aux->dato==n){
			return true;
		}else{
			aux=aux->siguiente;
		}
	}
	return false;
}
void eliminarnodo(nodo*&lista,int n){
	nodo* aux_borrar=lista;
	nodo* anterior=NULL;
	while((aux_borrar!=NULL)&&(aux_borrar->dato!=n)){
		anterior=aux_borrar;
		aux_borrar->siguiente;
	}
	if(aux_borrar==NULL){
		cout<<"no se ha encontrado el elemento buscado\n";
	}else if(anterior==NULL){
		lista=lista->siguiente;
		delete aux_borrar;
		cout<<"El elemento "<<n<<" fue eliminado correctamente\n";
	}else{
		anterior->siguiente= aux_borrar->siguiente;
		delete aux_borrar;
		cout<<"El elemento "<<n<<" fue eliminado correctamente\n";
	}
	
}
void eliminarlista(nodo*&lista,int&n){
	nodo* aux=lista;
	n=aux->dato;
	lista=aux->siguiente;
	delete aux;
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





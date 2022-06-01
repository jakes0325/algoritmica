/*
		Crear una lista doblemente enlazada, en donde se pueda, agregar, 
	modificar, eliminar elementos numéricos enteros; atendiendo que ninguno 
	sea un valor repetido. Luego, ingresar un número cualquiera y decir 
	si el número se encuentra primero en el recorrido de primero a ultimo o de
	ultimo a primer elemento de la lista. En caso de no encontrarse el valor, 
	indicar con un mensaje.
*/
#include<iostream>
#include<windows.h>
#include<string.h>
using namespace std;

struct nodo{
	int dato;
	nodo *siguiente;
	nodo *anterior;
};

void cargarlista(nodo*&,nodo*&,int);
void mostrarlistaPU(nodo*);
void mostrarlistaUP(nodo*);
void modificarlista(nodo*&,int);
void eliminarnro(nodo*&,nodo*&,int);
bool valor_repetido(nodo*,int);
string leer_op();
int recorrido(nodo*,nodo*,int);
main(void){
	nodo* primero = NULL;
	nodo* ultimo = NULL;
	int dato;
	string op;
	int menu;
	do{
		cout<<"-MENU-\n";
		cout<<"1-cargar lista\n2-imprimir lista\n3-modificar valor\n4-eliminar algun valor\n5-recorrido\n6-salir\n--->";
		do{
			cin>>menu;
			while(!cin.good()){
				cin.clear();
				fflush(stdin);
				cout<<"ERROR, solo se permiten nros\ningrese de nuevo";cin>>menu;
			}
		}while((menu<0)||(menu>6));
		system("pause");
		system("cls");
		switch(menu){
			case 1:
				cout<<"-CARGAR LISTA-\n";
				do{
					cout<<"ingrese nro: ";cin>>dato;
					while(valor_repetido(primero,dato)){
						cout<<"no se pueden ingresar nros repetidos!\nintente de nuevo:";cin>>dato;
					}
					while(!cin.good()){
						cin.clear();
						fflush(stdin);
						cout<<"ERROR. solo se permiten nros\nintente de nuevo: ";cin>>dato;
					}
					cargarlista(primero,ultimo,dato);
					cout<<"desea seguir ingresando? ";
					op=leer_op();
				}while(op.compare("SI")==0);
				break;
			case 2:
				cout<<"-MOSTRAR LISTA-\n";
				cout<<"-DE PRIMERO A ULTIMO-\n";
				mostrarlistaPU(primero);
				cout<<"\n-DE ULTIMO A PRIMERO-\n";
				mostrarlistaUP(ultimo);
				break;
			case 3:
				cout<<"-MODIFICAR VALOR-\n";
				cout<<"ingrese el nro que deseè modificar: ";cin>>dato;
				while(!cin.good()){
					cin.clear();
					fflush(stdin);
					cout<<"ERROR. solo se permiten nros\nintente de nuevo: ";cin>>dato;
				}
				modificarlista(primero,dato);
				break;
			case 4:
				cout<<"-ELIMINAR VALOR-\n";
				cout<<"ingrese el nro que deseè eliminar: ";cin>>dato;
				while(!cin.good()){
					cin.clear();
					fflush(stdin);
					cout<<"ERROR. solo se permiten nros\nintente de nuevo: ";cin>>dato;
				}
				eliminarnro(primero,ultimo,dato);
				break;
			case 5:
				cout<<"-RECORRIDO-\n";
				cout<<"ingrese el nro que deseè recorrer: ";cin>>dato;
				while(!cin.good()){
					cin.clear();
					fflush(stdin);
					cout<<"ERROR. solo se permiten nros\nintente de nuevo: ";cin>>dato;
				}
				int opR;
				opR=recorrido(primero,ultimo,dato);
				switch(opR){
					case 1:
						cout<<"tienen el mismo recorrido\n";
						break;
					case 2:
						cout<<"se llega primero desde el ultimo elemento\n";
						break;
					case 3:
						cout<<"se llega primero desde el primer elemento\n";
						break;
				}
				break;
			case 6:
				cout<<"gracias por usar el programa\n";
				break;
		}
		system("pause");
		system("cls");
	}while(menu!=6);	
	
	
	system("pause");
}
void cargarlista(nodo*& primero,nodo*& ultimo,int n){
	nodo* nuevo_nodo=new nodo();
	nuevo_nodo->dato=n;
	if(primero==NULL){
		primero=nuevo_nodo;
		nuevo_nodo->siguiente=NULL;
		nuevo_nodo->anterior=NULL;
		ultimo=nuevo_nodo;
	}else{
		ultimo->siguiente=nuevo_nodo;
		nuevo_nodo->anterior=ultimo;
		nuevo_nodo->siguiente=NULL;
		ultimo=nuevo_nodo;
	}
	cout<<"El valor "<<n<<" se ha ingresado correctamente\n";
}
void mostrarlistaPU(nodo*primero){
	nodo* aux=primero;
	if(primero!=NULL){
		while(aux!=NULL){
			cout<<aux->dato<<" - ";
			aux=aux->siguiente;
		}
	}else{
		cout<<"la lista esta vacia(ingrese elementos primero)\n";
	}
}
void mostrarlistaUP(nodo* ultimo){
	nodo* aux=ultimo;
	if(ultimo!=NULL){
		while(aux!=NULL){
			cout<<aux->dato<<" - ";
			aux=aux->anterior;
		}
	}else{
		cout<<"la lista esta vacia(ingrese elementos primero)\n";
	}
}
void modificarlista(nodo*& primero,int n){
	nodo* aux=primero;
	int sw=0;
	int valor;
	if(primero!=NULL){
		while((aux!=NULL)&&(sw==0)){
			if(aux->dato==n){
				sw=1;
			}else{
				aux=aux->siguiente;	
			}
		}
		if(sw==0){
			cout<<"El elemento "<<n<<" no se ha encontrado\n";
		}else{
			cout<<"El elemento "<<n<<" se ha encontrado\n";
			cout<<"ingrese el valor por el cual desea reemplazar: ";
			cin>>valor;
			while(valor_repetido(primero,valor)){
				cout<<"no se pueden ingresar nros repetidos!\nintente de nuevo:";cin>>valor;
			}
			aux->dato=valor;
		}
		
	}else{
		cout<<"la lista esta vacia(ingrese elementos primero)\n";
	}
}
void eliminarnro(nodo*& primero,nodo*& ultimo,int n){
	nodo* actual=primero;
	nodo* anterior=NULL;
	nodo* aux=new nodo();
	bool sw=false;
	if(primero!=NULL){
		while((actual!=NULL)&&(sw==false)){
			if(actual->dato==n){
				if(primero==actual){
					aux=primero;
					primero=primero->siguiente;
					primero->anterior=NULL;	
				}else if(actual==ultimo){
					aux=ultimo;
					anterior->siguiente=NULL;
					ultimo=anterior;
				}else{
					aux=actual;
					anterior->siguiente=actual->siguiente;
					actual->siguiente->anterior=anterior;
				}
				delete aux;
				cout<<"El elemento "<<n<<"se ha eliminado\n";
				sw=true;
			}else{
				anterior=actual;
				actual=actual->siguiente;
			}
		}
		if(sw==false){
			cout<<"no se encontro el elemento para eliminar\n";
		}
	}else{
		cout<<"la lista esta vacia(ingrese elementos primero)\n";
	}
}
bool valor_repetido(nodo*primero,int n){
	nodo* aux=primero;
	while(aux!=NULL){
		if(aux->dato==n){
			return true;
		}else{
			aux=aux->siguiente;
		}
	}
	return false;
}
string leer_op(){
	int sw=0;
	string a;
	do{
		sw=0;
		fflush(stdin);
		getline(cin,a);
		for(int c=0;c<a.length();c++){
			a[c]=toupper(a[c]);
		}
		for(int c=0;(c<a.length())&&(sw==0);c++){
			if(isdigit(a[c])==1){
				cout<<"ERROR. solo se pèrmiten caracteres\ningrese de nuevo: ";
				sw=1;
			}
			if((a.compare("SI")!=0)&&(a.compare("NO")!=0)){
				cout<<"ingrese una opcion valida(si/no): ";
				sw=1;
			}
		}
	}while(sw==1);
	return a;
}
int recorrido(nodo*primero,nodo*ultimo,int n){
	nodo* auxP=primero;
	nodo* auxU=ultimo;
	int cP=0,cU=0;
	
	if(primero!=NULL){
		while((auxP!=NULL)&&(auxP->dato!=n)){
			cP++;
			auxP=auxP->siguiente;
		}
		while((auxU!=NULL)&&(auxU->dato!=n)){
			cU++;
			auxU=auxU->anterior;
		}
		if((auxP==NULL)&&(auxU==NULL)){
			cout<<"el valor no se ha encontrado\n";
		}else{
			if(cP==cU){
				return 1;
			}else if(cU<cP){
				return 2;
			}else{
				return 3;
			}
		}
	}else{
		cout<<"la lista esta vacia(ingrese elementos primero)\n";
	}
}

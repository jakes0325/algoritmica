/*
		Crear un programa que permita registrar las temperaturas en °C durante el día, de 4 ciudades,
	en donde los datos a registrar son los siguientes:
	- Temperatura
	- Ciudad (1 = Ciudad del este, 2 = Hernandarias, 3 = Pte Franco, 4 = Minga Guasu)
	- Hora (Horario 24hs)
	Permitir el ingreso de datos en una lista doblemente enlazada y la consulta de los mismos a
	través del siguiente menú:
	1) Registrar Temperatura
	2) Consulta de temperaturas por hora en forma ascendente
	3) Consulta de temperaturas por hora en forma descendente
	4) Consulta de temperaturas registradas por ciudad
	5) La ciudad que registro mayor temperatura en el día 
		Observación:
	- Realiza las validaciones para el horario de 24hs y el código de las ciudades (1,2,3,4)
	- en las consultas mostrar el nombre de la ciudad teniendo en cuenta su código (1,2,3,4) 
*/
#include<iostream>
#include<windows.h>
#include<string.h>
using namespace std;

struct nodo{
	int temperatura;
	float hora;
	int ciudad;
	nodo* siguiente;
	nodo* anterior;	
};
struct nodo2{
	int temperatura;
	float hora;
	int ciudad;
	nodo2* siguiente;
};

void cargarlista(nodo*&,nodo*&,int,float,int);
void consulta_de_temperatura_por_hora_as(nodo*);
void consulta_de_temperatura_por_hora_de(nodo*);
string leer_op();
int leer_entero();
void listaascendenteAS(nodo2*&,int,float,int);
void listaascendenteDE(nodo2*&,int,float,int);
void mostrarlistaPU(nodo*,int);
void mayortemperatura(nodo*);
main(){
	nodo* primero=NULL;
	nodo* ultimo=NULL;
	int temperatura;
	float hora=0.00;
	int city;
	string op;
	int menu;
	do{
		
		cout<<"\t-MENU DE OPCIONES-\n";
		cout<<"1)Registrar Temperatura  \n2) Consulta de temperaturas por hora en forma ascendente	\n3) Consulta de temperaturas por hora en forma descendente	\n4) Consulta de temperaturas registradas por ciudad	\n5) La ciudad que registro mayor temperatura en el día \n6) salir\n->";
		do{
			menu=leer_entero();	
		}while((menu<1)||(menu>6));
		switch(menu){
			case 1:
				cout<<"-REGISTRAR TEMPERATURA-\n";
				do{
					cout<<"ingrese temperatura: ";
					temperatura=leer_entero();
					do{
						cout<<"ingrese hora de dicha temperatura:(24/horas) ";
						hora=leer_entero();
					}while((hora<0)||(hora>24));
					cout<<"-Ingrese ciudad de la temperatura obtenida-\n\t1-ciudad del este\n\t2-hernandarias\n\t3-pte franco\n\t4-minga guasu)\n->";
					city=leer_entero();
					while((city<1)||(city>4)){
						cout<<"ingrese una opcion valida (ej:1,2,3,4): ";
						city=leer_entero();
					}
					cargarlista(primero,ultimo,temperatura,hora,city);
					cout<<"desea seguir ingresando? ";
					op=leer_op();
				}while(op.compare("SI")==0);
				break;
			case 2:
					cout<<"-temperaturas por hora en forma ascendente-\n";
					consulta_de_temperatura_por_hora_as(primero);
				break;
			case 3:
					cout<<"-temperaturas por hora en forma descendente-\n";
					consulta_de_temperatura_por_hora_de(primero);
				break;
			case 4:
					cout<<"-Consulta de temperaturas registradas por ciudad-\n";
					cout<<"ingrese la ciudad que desea ver: ";
					do{
						cin>>city;
						while(!cin.good()){
							cin.clear();
							fflush(stdin);
							cout<<"solo se permiten valores numericos:";cin>>city;
						}
					}while((city<1)||(city>4));
					
					mostrarlistaPU(primero,city);
				break;
			case 5:
					cout<<"- La ciudad que registro mayor temperatura en el día -\n";
					mayortemperatura(primero);
					
					
				break;
			case 6:
				cout<<"-GRACIAS POR USAR EL PROGRAMA-\n";
				break;
		}
		system("pause");
		system("cls");
	}while(menu!=6);
	
	
	
	
	
	
	
	
	
	
	system("pause");
	system("cls");
}
void cargarlista(nodo*&primero,nodo*&ultimo,int temperatura,float hora,int ciudad){
	nodo* n_nodo=new nodo();
	n_nodo->temperatura=temperatura;
	n_nodo->hora=hora;
	n_nodo->ciudad=ciudad;
	if(primero==NULL){
		primero=n_nodo;
		n_nodo->anterior=NULL;
		n_nodo->siguiente=NULL;
		ultimo=n_nodo;
	}else{
		ultimo->siguiente=n_nodo;
		n_nodo->anterior=ultimo;
		n_nodo->siguiente=NULL;
		ultimo=n_nodo;
	}
	cout<<"los valores se ha ingresado correctamente\n";
}
void consulta_de_temperatura_por_hora_as(nodo*primero){
	nodo* aux=primero;
	nodo2* primer=NULL;
	while(aux!=NULL){
		listaascendenteAS(primer,aux->temperatura,aux->hora,aux->ciudad);
		aux=aux->siguiente;	
	}
	nodo2* ayudin=primer;
	while(ayudin!=NULL){
		cout<<"-------------------------------\n";
		cout<<"temperatura: "<<ayudin->temperatura<<endl;
		cout<<"hora: "<<ayudin->hora<<endl;
		switch(ayudin->ciudad){
			case 1:
				cout<<"ciudad: Ciudad del este"<<endl;
				break;
			case 2:
				cout<<"ciudad:  Hernandarias"<<endl;
				break;
			case 3:
				cout<<"ciudad:  Pte.Franco"<<endl;
				break;
			case 4:
				cout<<"ciudad:  Minga guasu"<<endl;
				break;
		}
		cout<<"-------------------------------\n";
		ayudin=ayudin->siguiente;
	}
	
}
void listaascendenteAS(nodo2*&primer,int temperatura,float hora,int ciudad){
	nodo2* nuevo_nodo= new nodo2();
	nuevo_nodo->temperatura=temperatura;
	nuevo_nodo->hora=hora;
	nuevo_nodo->ciudad=ciudad;
	nodo2 *aux1=primer;
	nodo2 *aux2;
	while((aux1!=NULL)&&(aux1->hora<hora)){
		aux2=aux1;
		aux1=aux1->siguiente;
	}
	if(primer==aux1){
		primer=nuevo_nodo;
	}else{
		aux2->siguiente=nuevo_nodo;
	}
	nuevo_nodo->siguiente = aux1; 	
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
int leer_entero(){
	int a;
	cin>>a;
	while(!cin.good()){
		cin.clear();
		fflush(stdin);
		cout<<"solo se permiten valores enteros\nvuelva a intentar: ";cin>>a;
	}
	return a;
}
void consulta_de_temperatura_por_hora_de(nodo*primero){
	nodo* aux=primero;
	nodo2* primer=NULL;
	while(aux!=NULL){
		listaascendenteDE(primer,aux->temperatura,aux->hora,aux->ciudad);
		aux=aux->siguiente;	
	}
	nodo2* ayudin=primer;
	while(ayudin!=NULL){
		cout<<"-------------------------------\n";
		cout<<"temperatura: "<<ayudin->temperatura<<endl;
		cout<<"hora: "<<ayudin->hora<<endl;
		switch(ayudin->ciudad){
			case 1:
				cout<<"ciudad:  Ciudad del este"<<endl;
				break;
			case 2:
				cout<<"ciudad:  Hernandarias"<<endl;
				break;
			case 3:
				cout<<"ciudad:  Pte.Franco"<<endl;
				break;
			case 4:
				cout<<"ciudad:  Minga guasu"<<endl;
				break;
		}
		
		cout<<"-------------------------------\n";
		ayudin=ayudin->siguiente;
	}
	
}
void listaascendenteDE(nodo2*&primer,int temperatura,float hora,int ciudad){
	nodo2* nuevo_nodo= new nodo2();
	nuevo_nodo->temperatura=temperatura;
	nuevo_nodo->hora=hora;
	nuevo_nodo->ciudad=ciudad;
	nodo2 *aux1=primer;
	nodo2 *aux2;
	while((aux1!=NULL)&&(aux1->hora>hora)){
		aux2=aux1;
		aux1=aux1->siguiente;
	}
	if(primer==aux1){
		primer=nuevo_nodo;
	}else{
		aux2->siguiente=nuevo_nodo;
	}
	nuevo_nodo->siguiente = aux1; 	
}
void mostrarlistaPU(nodo*primero,int city){
	nodo* aux=primero;
	if(primero!=NULL){
		while(aux!=NULL){
			if(city==aux->ciudad){
				cout<<"-------------------------------\n";
				cout<<"temperatura: "<<aux->temperatura<<endl;
				cout<<"hora: "<<aux->hora<<endl;
				switch(aux->ciudad){
					case 1:
						cout<<"ciudad:  Ciudad del este"<<endl;
						break;
					case 2:
						cout<<"ciudad:  Hernandarias"<<endl;
						break;
					case 3:
						cout<<"ciudad:  Pte.Franco"<<endl;
						break;
					case 4:
						cout<<"ciudad:  Minga guasu"<<endl;
						break;
				}
					cout<<"-------------------------------\n";
				aux=aux->siguiente;	
			}			
			aux=aux->siguiente;
		}
	}else{
		cout<<"la lista esta vacia(ingrese elementos primero)\n";
	}
}

void mayortemperatura(nodo* primero){
	int mayor;
	int c=0;
	nodo* aux=primero;
	while(aux!=NULL){
		c++;
		if(c==1){
			mayor=aux->temperatura;
		}else if(mayor<aux->temperatura){
			mayor=aux->temperatura;
		}
		aux=aux->siguiente;
	}
	aux=primero;
	while(aux!=NULL){
		if(mayor==aux->temperatura){
			while(aux!=NULL){
				cout<<"-------------------------------\n";
				cout<<"temperatura: "<<aux->temperatura<<endl;
				cout<<"hora: "<<aux->hora<<endl;
				switch(aux->ciudad){
					case 1:
						cout<<"ciudad:  Ciudad del este"<<endl;
						break;
					case 2:
						cout<<"ciudad:  Hernandarias"<<endl;
						break;
					case 3:
						cout<<"ciudad:  Pte.Franco"<<endl;
						break;
					case 4:
						cout<<"ciudad:  Minga guasu"<<endl;
						break;
				}
				
				cout<<"-------------------------------\n";
				aux=aux->siguiente;
			}
		}
		aux=aux->siguiente;
	}
}
















/*
		Los empleados de una fábrica trabajan en dos turnos, Diurno y Nocturno. Crear un programa que
	permita registrar el código, nombre del funcionario, horas trabajadas, el turno y el día (“Festivo”,
	“Laborable”) y a su vez calcular el jornal diario a cobrar donde se tienen en cuenta los siguientes
	puntos:
	? La tarifa de las horas diurnas es de 100.000 Gs
	? La tarifa de las horas nocturnas es de 135.000 Gs
	? En caso de ser festivo, la tarifa se incrementa en un 10% en caso de turno diurno y en un
	15% para el nocturno.
	Además, realizar el proceso de arreglo, que consistirá en filtrar todos los jornales pendientes de
	cualquier empleado seleccionado, mostrando el resumen y total a cobrar.
	Realizar la implementación de la aplicación en una lista doblemente enlazada que contendrá todos
	los datos mencionados anteriormente y utiliza el siguiente menú para la navegación e
	implementación:
	
			MENU
	1) Registrar Jornal.
	2) Modificar Jornal.
	3) Eliminar Jornal.
	4) Consultar Jornal por código de Funcionario.
	5) Mostrar Lista de Primero al Último con un resumen totalizado.
	6) Mostrar Lista de Ultimo al Primero con un resumen totalizado.
	7) Mostrar el funcionario con mayor y menor jornal.
	8) Realizar Arreglo (Cobrar Jornales).
	9) Consultar Jornal Cobrado, por Funcionario.
	10) Consultar Jornal Cobrado, en forma totalizada.
	11) Consultar Jornal pendiente, por Funcionario.
	12) Consultar Jornal pendiente, en forma totalizada.
	13) Cancelar Jornal Cobrado.
	14) Salir o Regresar.
										OBSERVACIONES:
	? Se recomienda crear una estructura exclusiva para los empleados, donde cada uno debe ser
	identificado con un código ID
	? Un funcionario solo puornal eede recibir un Jn un turno determinado, en caso de repetir un
	dato, el programa debe mostrar un error, especificando el inconveniente.
	? Para consultar, modificar y eliminar se tendrá en cuenta el campo “Código de Funcionario”
	para la búsqueda, donde, el código de funcionario debe ser un campo único e irrepetible.
	? El arreglo de jornal consiste en el pago de los jornales obtenidos por los empleados, es decir,
	los alumnos con jornales pendientes.
	? Se recomienda un campo que permita identificar a los registros de jornal como pendiente o
	cobrado.
	? El resumen totalizado es la sumatoria de todos los jornales calculados
	? Considerar como días festivos: sábados, domingos y feriados 
*/
#include<iostream>
#include<windows.h>
#include<string.h>

using namespace std;

struct nodo{
	int id;
	int codigo;
	string nombre;
	int horas;
	string turno;	// diurno o nocturno
	string dia;		// festivo(sabado,domingo,feriados) o laboral(lunes,martes,miercoles,jueves,viernes)
	string jornal;	// pendiente o cobrado
	
	nodo* siguiente;
	nodo* anterior;
};

void gotoxy(int x,int y){  
	HANDLE hcon;  
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
	COORD dwPos;  
	dwPos.X = x;  
	dwPos.Y= y;  
	SetConsoleCursorPosition(hcon,dwPos);  
}  

void cargarlista(nodo*&,nodo*&,int,int,string,int,string,string,string);
void mostrarlista(nodo*);
void mostrarlistaUP(nodo*);
void modificarjornal(nodo*&,int);
void eliminarjornal(nodo*&,nodo*&,int);
void consultarjornalXid(nodo*,int);
void func_con_mayor_y_menor_jornal(nodo*);
void arreglo_de_jornales(nodo*&);
void jornal_cobrado_X_func(nodo*,int);
void jornal_cobrado_totalizado(nodo*);
void jornal_pendiente_X_func(nodo*,int);
void jornal_pendiente_totalizado(nodo*);
void cancelar_jornal_Cobrado(nodo*,int);


bool validar_ingreso(nodo*,int,string,string);
void encabezado();
void MostrarMenu();
int leer_entero();
string leer_caracter();

main(){
	nodo* primero=NULL;
	nodo* ultimo=NULL;
	int id,horas,menu,codigo;
	string nombre,turno,dia,jornal;
	int op=1,op2=0;
	do{
		
		MostrarMenu();
		menu=leer_entero();
		while((menu<1)||(menu>14)){
			cout<<"Ingrese una opcion valida\n";
			system("pause");
			system("cls");
			MostrarMenu();
			menu=leer_entero();
		}
		switch(menu){
			case 1:
				system("pause");
				system("cls");
				cout<<"-REGISTRAR JORNAL-\n";
				do{
					cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
					//codigo
					cout<<"ingrese codigo de funcionario: ";
					do{
						codigo=leer_entero();
					}while(codigo<0);	
					//nombre
					cout<<"ingrese nombre: ";
					nombre=leer_caracter();
					//horas
					cout<<"ingrese horas: ";
					do{
						horas=leer_entero();
					}while((horas<0)||(horas>16));
					//turno
					cout<<"ingrese turno (diurno o nocturno) :";	// diurnas o nocturnas
					do{
						turno=leer_caracter();
					}while((turno.compare("DIURNO")!=0)&&(turno.compare("NOCTURNO")!=0));
					//dia
					cout<<"ingrese el dia (Ej:lunes,martes,miercoles,sabado,domingo y feriados) :"; //festivo o laboral
					do{
						dia=leer_caracter();	
					}while((dia.compare("FERIADO")!=0)
					&&(dia.compare("LUNES")!=0)
					&&(dia.compare("MARTES")!=0)
					&&(dia.compare("MIERCOLES")!=0)
					&&(dia.compare("JUEVES")!=0)
					&&(dia.compare("VIERNES")!=0)
					&&(dia.compare("SABADO")!=0)
					&&(dia.compare("DOMINGO")!=0));
					//jornal
					cout<<"El jornal ya fue pagado o sigue pendiente?\ningrese pagado si ya se pago o pendiente si todavia no se pago\n----->";
					do{													//pendiente o pagado
						jornal=leer_caracter();	
					}while((jornal.compare("PAGADO")!=0)&&(jornal.compare("PENDIENTE")!=0));
					
					if(validar_ingreso(primero,codigo,turno,nombre)){
						//id
						if(ultimo==NULL){
						id=1;
						}else{
							id=ultimo->id;
							id++;	
						}
						cout<<"desea continuar ingresando? (1=si / 0=no)";
						do{
							op=leer_entero();	
						}while((op<0)||(op>1));
						cargarlista(primero,ultimo,id,codigo,nombre,horas,turno,dia,jornal);
					}else{
						cout<<"ERROR. los valores ingresados ya estan cargados\nvuelva a intentar\n";
					}		
				}while(op==1);	
			break;				
			case 2:
				system("pause");
				system("cls");
				cout<<"- MODIFIICAR JORNAL -\n";
				encabezado();
				mostrarlista(primero);
				system("pause");
				system("cls");
				cout<<"\ningrese el ID del usuario que desea modificar:";
				op=leer_entero();   //uso esta variable para no crear otra
				while(op<0){
					cout<<"ingrese un nro mayor que 0\n";
					op=leer_entero();
				}
				modificarjornal(primero,op);
				system("pause");
			break;				
			case 3:
				system("pause");
				system("cls");
				cout<<"- ELIMINAR JORNAL -\n";
				encabezado();
				mostrarlista(primero);
				system("pause");
				system("cls");
				cout<<"\ningrese el ID del usuario que desea eliminar:";
				op=leer_entero();   //uso esta variable para no crear otra
				while(op<0){
					cout<<"ingrese un nro mayor que 0\n";
					op=leer_entero();
				}
				eliminarjornal(primero,ultimo,op);
				system("pause");
			break;				
			case 4:
				system("pause");
				system("cls");
				cout<<"-CONSULTAR JORNAL POR CODIGO DE USUARIO-\n";
				encabezado();
				mostrarlista(primero);
				cout<<"\ningrese el codigo del usuario que desea consultar:";
				op=leer_entero();   //uso esta variable para no crear otra
				while(op<0){
					cout<<"ingrese un nro mayor que 0\n";
					op=leer_entero();
				}
				consultarjornalXid(primero,op);
				system("pause");
			break;				
			case 5:
				system("pause");
				system("cls");
				cout<<"-LISTA DE PRIMERO A ULTIMO-\n";
				encabezado();
				mostrarlista(primero);
				system("pause");
				system("cls");
				
			break;				
			case 6:
				system("pause");
				system("cls");
				cout<<"-LISTA DE ULTIMO A PRIMERO-\n";
				encabezado();
				mostrarlistaUP(ultimo);
				system("pause");
				system("cls");
			break;				
			case 7:
				system("pause");
				system("cls");
				cout<<"-El funcionario con mayor y menor jornal-\n";
				func_con_mayor_y_menor_jornal(primero);
				system("pause");
			break;				
			case 8:
				system("pause");
				system("cls");
				cout<<"-Realizar Arreglo (Cobrar Jornales)-\n";
				encabezado();
				arreglo_de_jornales(primero);
				system("pause");
			break;				
			case 9:
				system("pause");
				system("cls");
				cout<<"- Jornal Cobrado por Funcionario -\n";
				encabezado();
				mostrarlista(primero);
				system("pause");
				system("cls");
				cout<<"ingrese codigo del usuario para consultar: ";
				do{
					codigo=leer_entero();
				}while(codigo<0);
				jornal_cobrado_X_func(primero,codigo);
				system("pause");
			break;				
			case 10:
				system("pause");
				system("cls");
				cout<<"- Jornales Cobrados en forma totalizada -\n";
				jornal_cobrado_totalizado(primero);
				system("pause");
			break;				
			case 11:
				system("pause");
				system("cls");
				cout<<"- Jornal pendiente por Funcionario -\n";
				encabezado();
				mostrarlista(primero);
				system("pause");
				system("cls");
				cout<<"ingrese codigo del usuario para consultar: ";
				do{
					codigo=leer_entero();
				}while(codigo<0);
				jornal_pendiente_X_func(primero,codigo);
				system("pause");
			break;				
			case 12:
				system("pause");
				system("cls");
				cout<<"- Jornales Pendientes en forma totalizada -\n";
				jornal_pendiente_totalizado(primero);
				system("pause");
			break;				
			case 13:
				system("pause");
				system("cls");
				cout<<"- Cancelar Jornal Cobrado -\n";
				encabezado();
				mostrarlista(primero);
				cout<<"ingrese el ID del funcionario que desea cancelar: ";
				do{
					id=leer_entero();	
				}while(id<0);
				
				cancelar_jornal_Cobrado(primero,id);
				system("pause");
			break;				
			case 14:
				cout<<"desea 1-salir o 0-regresar?(ingrese los valores numericos de las opciones)\n------> ";
				do{
					op2=leer_entero();
				}while((op2<0)||(op2>1));
				
			break;				
		}
		system("cls");
	}while(op2==0);
	
	
	
	
	
	
	
	
	
	system("pause");
	system("cls");
}
void encabezado(){
	cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
	cout<<"|  ID  |  CODIGO	 |	NOMBRE	|  HORAS	|	TURNO	|	DIA		|	JORNAL		|\n";
	cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
}
void MostrarMenu(){
	cout<<"		-MENU-			\n";
	cout<<"1) Registrar Jornal.			\n";
	cout<<"2) Modificar Jornal.		\n";
	cout<<"3) Eliminar Jornal.			\n";
	cout<<"4) Consultar Jornal por codigo de Funcionario.	\n";
	cout<<"5) Mostrar Lista de Primero al Ultimo con un resumen totalizado.\n";
	cout<<"6) Mostrar Lista de Ultimo al Primero con un resumen totalizado.\n";
	cout<<"7) Mostrar el funcionario con mayor y menor jornal.\n";
	cout<<"8) Realizar Arreglo (Cobrar Jornales).\n";
	cout<<"9) Consultar Jornal Cobrado, por Funcionario.\n";
	cout<<"10) Consultar Jornal Cobrado, en forma totalizada.\n";
	cout<<"11) Consultar Jornal pendiente, por Funcionario.\n";
	cout<<"12) Consultar Jornal pendiente, en forma totalizada.\n";
	cout<<"13) Cancelar Jornal Cobrado.\n";
	cout<<"14) Salir o Regresar.\n";
	cout<<"ingrese opcion	---> ";
}

bool validar_ingreso(nodo*primero,int codigo,string turno,string nombre){
	nodo *aux=primero;
	while(aux!=NULL){
		if((aux->codigo==codigo)&&(aux->nombre.compare(nombre)!=0)){
			return false;
		}
		if((aux->codigo==codigo)&&(aux->turno.compare(turno)!=0)){
			return false;
		}
		aux=aux->siguiente;
	}
	return true;
}

void cargarlista(nodo*&primero,nodo*&ultimo,int id,int codigo,string nombre,int horas,string turno,string dia,string jornal){
	nodo *n_nuevo = new nodo();
	n_nuevo->id=id;
	n_nuevo->codigo=codigo;
	n_nuevo->nombre=nombre;
	n_nuevo->horas=horas;
	n_nuevo->turno=turno;
	n_nuevo->dia=dia;
	n_nuevo->jornal=jornal;
	if(primero==NULL){
		primero=n_nuevo;
		primero->anterior=NULL;
		primero->siguiente=NULL;
		ultimo=n_nuevo;
	}else{
		ultimo->siguiente=n_nuevo;
		n_nuevo->anterior=ultimo;
		n_nuevo->siguiente=NULL;
		ultimo=n_nuevo;
	}
	cout<<"los datos se han cargado correctamente!\n";
}
void mostrarlista(nodo*primero){
	if(primero!=NULL){
		nodo *aux=primero;
		int f=5;
		while(aux!=NULL){
			gotoxy(2,f);cout<<aux->id;
			gotoxy(12,f);cout<<aux->codigo;
			gotoxy(29,f);cout<<aux->nombre;
			gotoxy(44,f);cout<<aux->horas;
			gotoxy(63,f);cout<<aux->turno;
			gotoxy(85,f);cout<<aux->dia;
			gotoxy(100,f);cout<<aux->jornal;
			aux=aux->siguiente;
			f++;
		}
		cout<<endl;
	}else{
		cout<<"rellene unos jornales primero antes de acceder a esta opcion\n ";
	}
	
} 
void mostrarlistaUP(nodo*ultimo){
	if(ultimo!=NULL){
		nodo *aux=ultimo;
		int f=5;
		while(aux!=NULL){
			gotoxy(2,f);cout<<aux->id;
			gotoxy(12,f);cout<<aux->codigo;
			gotoxy(29,f);cout<<aux->nombre;
			gotoxy(44,f);cout<<aux->horas;
			gotoxy(63,f);cout<<aux->turno;
			gotoxy(85,f);cout<<aux->dia;
			gotoxy(100,f);cout<<aux->jornal;
			aux=aux->anterior;
			f++;
		}
		cout<<endl;
	}else{
		cout<<"rellene unos jornales primero antes de acceder a esta opcion\n ";
	}
}

void modificarjornal(nodo*&primero,int id){
	if(primero!=NULL){
		int sw=0,menu;
		nodo *aux=primero;	
		while((aux!=NULL)&&(sw==0)){
			if(aux->id==id){
				sw=1;
			}else{
				aux=aux->siguiente;	
			}
		}
		if(sw==1){
			cout<<"			- MENU PARA MODIFICAR -\n";
			cout<<"1-Modificar el nombre\n";
			cout<<"2-Modificar las horas\n";
			cout<<"3-Modificar turno\n";
			cout<<"4-Modificar el dia\n";
			cout<<"5-Modificar el estado del jornal\n";
			cout<<"6-Modificar codigo de funcionario\n";
			cout<<"7-Modificar todo\n";
			cout<<"------->";
			do{
				menu=leer_entero();	
			}while((menu<0)||(menu>6));
			switch(menu){
				case 1:
					cout<<"ingrese el nuevo nombre: ";
					aux->nombre=leer_caracter();
				break;
				case 2:
					cout<<"ingrese la nueva cantidad de horas: ";
					do{
						aux->horas=leer_entero();
					}while((aux->horas<0)||(aux->horas>16));
					
				break;
				case 3: 
					cout<<"ingrese el nuevo turno: ";
					do{
						aux->turno=leer_caracter();	
					}while((aux->turno.compare("DIURNO")!=0)&&(aux->turno.compare("NOCTURNO")!=0));
				break;
				case 4: 
					cout<<"ingrese el nuevo dia: (Ej:lunes,martes,miercoles,sabado,domingo y feriados) ";
					do{
						aux->dia=leer_caracter();	
					}while((aux->dia.compare("FERIADO")!=0)
					&&(aux->dia.compare("LUNES")!=0)
					&&(aux->dia.compare("MARTES")!=0)
					&&(aux->dia.compare("MIERCOLES")!=0)
					&&(aux->dia.compare("JUEVES")!=0)
					&&(aux->dia.compare("VIERNES")!=0)
					&&(aux->dia.compare("SABADO")!=0)
					&&(aux->dia.compare("DOMINGO")!=0));
				break;
				case 5: 
					cout<<"ingrese el nuevo jornal: ";
					do{													
						aux->jornal=leer_caracter();	
					}while((aux->jornal.compare("PAGADO")!=0)&&(aux->jornal.compare("PENDIENTE")!=0));
				break;
				case 6:
					cout<<"ingrese codigo de funcionario: ";
					do{
						aux->codigo=leer_entero();
					}while(aux->codigo<0);
				break;
				case 7: 
					cout<<"ingrese codigo de funcionario: ";
					do{
						aux->codigo=leer_entero();
					}while(aux->codigo<0);
					cout<<"ingrese el nuevo nombre: ";
					aux->nombre=leer_caracter();
					cout<<"ingrese la nueva cantidad de horas: ";
					do{
						aux->horas=leer_entero();
					}while((aux->horas<0)||(aux->horas>16));
					cout<<"ingrese el nuevo turno: ";
					do{
						aux->turno=leer_caracter();	
					}while((aux->turno.compare("DIURNO")!=0)&&(aux->turno.compare("NOCTURNO")!=0));
					cout<<"ingrese el nuevo dia: ";
					do{
						aux->dia=leer_caracter();	
					}while((aux->dia.compare("FERIADO")!=0)
					&&(aux->dia.compare("LUNES")!=0)
					&&(aux->dia.compare("MARTES")!=0)
					&&(aux->dia.compare("MIERCOLES")!=0)
					&&(aux->dia.compare("JUEVES")!=0)
					&&(aux->dia.compare("VIERNES")!=0)
					&&(aux->dia.compare("SABADO")!=0)
					&&(aux->dia.compare("DOMINGO")!=0));
					cout<<"ingrese el nuevo jornal: ";
					do{													
						aux->jornal=leer_caracter();	
					}while((aux->jornal.compare("PAGADO")!=0)&&(aux->jornal.compare("PENDIENTE")!=0));
				break;
				
			}
			cout<<"se ha modificado perfectamente!\n";
		}else{
			cout<<"el usuario que buscas no ha sido encontrado\n";
		}
	}else{
		cout<<"rellene unos jornales primero antes de acceder a esta opcion\n ";
	}
	
	
	
}

void eliminarjornal(nodo*&primero,nodo*&ultimo,int id){
	if(primero!=NULL){
		int sw=0;
		nodo *aux=primero;
		nodo *aux2=NULL;	
		while((aux!=NULL)&&(sw==0)){
			if(aux->id==id){
				sw=1;
			}else{
				aux2=aux;
				aux=aux->siguiente;
			}
		}
		if(sw==1){
			if(aux==primero){
				primero=primero->siguiente;
				primero->anterior=NULL;
				delete aux;
			}else if(aux==ultimo){
				ultimo=ultimo->anterior;
				ultimo->siguiente=NULL;
				delete aux;
			}else{
				aux2->siguiente=aux->siguiente;
				aux->siguiente->anterior=aux2;
				delete aux;
			}
		}else{
			cout<<"el usuario que buscas no ha sido encontrado\n";
		}
		cout<<"se ha eliminado perfectamente!\n";
	}else{
		cout<<"rellene unos jornales primero antes de acceder a esta opcion\n ";
	}
	
}

void consultarjornalXid(nodo*primero,int codigo){
	/*? La tarifa de las horas diurnas es de 100.000 Gs
	? La tarifa de las horas nocturnas es de 135.000 Gs
	? En caso de ser festivo, la tarifa se incrementa en un 10% en caso de turno diurno y en un
	15% para el nocturno.*/
	if(primero!=NULL){
		int sw=0,total=0;
		nodo *aux=primero;
		while(aux!=NULL){
			if(aux->codigo==codigo){
				if(aux->turno.compare("DIURNO")==0){
					if((aux->dia.compare("FERIADO")==0)&&(aux->dia.compare("SABADO")==0)&&(aux->dia.compare("DOMINGO")==0)){
						total=(aux->horas*100000)*1.1;
					}else{
						total=aux->horas*100000;
					}
				}else{
					if((aux->dia.compare("FERIADO")==0)&&(aux->dia.compare("SABADO")==0)&&(aux->dia.compare("DOMINGO")==0)){
						total=(aux->horas*135000)*1.15;
					}else{
						total=aux->horas*135000;
					}
				}
				cout<<"turno: "<<aux->turno<<endl;
				cout<<"dia: "<<aux->dia<<endl;
				cout<<"horas: "<<aux->horas<<endl;
				cout<<"Total a pagar: "<<total<<endl;
				sw=1;
			}
			aux=aux->siguiente;	
		}
		
		if(sw==1){
			system("pause");
		}else{
			cout<<"el usuario que buscas no ha sido encontrado\n";	
		}
	}else{
		cout<<"rellene unos jornales primero antes de acceder a esta opcion\n ";
	}
}



void func_con_mayor_y_menor_jornal(nodo*primero){
	if(primero!=NULL){
		int c=0,total=0,men,may;
		string may2,men2;
		nodo *aux=primero;
		while(aux!=NULL){
			if(aux->turno.compare("DIURNO")==0){
				if((aux->dia.compare("FERIADO")==0)&&(aux->dia.compare("SABADO")==0)&&(aux->dia.compare("DOMINGO")==0)){
					total=(aux->horas*100000)*1.1;
				}else{
					total=aux->horas*100000;
				}
			}else{
				if((aux->dia.compare("FERIADO")==0)&&(aux->dia.compare("SABADO")==0)&&(aux->dia.compare("DOMINGO")==0)){
					total=(aux->horas*135000)*1.15;
				}else{
					total=aux->horas*135000;
				}
			}
			if(c==0){
				men=total;men2=aux->nombre;
				may=total;may2=aux->nombre;
			}else if(total<men){
				men=total;men2=aux->nombre;
			}else if(total>may){
				may=total;may2=aux->nombre;
			}
			aux=aux->siguiente;	
			c++;
		}
		cout<<"El mayor jornal es: "<<may<<" y es de "<<may2<<endl;
		cout<<"El menor jornal es: "<<men<<" y es de "<<men2<<endl;
	}else{
		cout<<"rellene unos jornales primero antes de acceder a esta opcion\n ";
	}
}

void arreglo_de_jornales(nodo*&primero){
	if(primero!=NULL){
		int f=5,id;
		nodo *aux=primero;
		while(aux!=NULL){
			if(aux->jornal.compare("PENDIENTE")==0){
				gotoxy(2,f);cout<<aux->id;
				gotoxy(12,f);cout<<aux->codigo;
				gotoxy(29,f);cout<<aux->nombre;
				gotoxy(44,f);cout<<aux->horas;
				gotoxy(63,f);cout<<aux->turno;
				gotoxy(85,f);cout<<aux->dia;
				gotoxy(100,f);cout<<aux->jornal;
				f++;
			}
			aux=aux->siguiente;
		}
		cout<<endl;
		int sw=0;
		cout<<"ingrese id del que desea pagar :\n";
		do{
			id=leer_entero();	
		}while(id<0);
		aux=primero;
		while((aux!=NULL)&&(sw==0)){
			if(aux->id==id){
				sw=1;
			}else{
				aux=aux->siguiente;
			}
		}
		if(sw==1){	
												
			aux->jornal="PAGADO";	
			cout<<"se ha pagado correctamente";
		}else{
			cout<<"el usuario que buscas no ha sido encontrado\n";
		}
	}else{
		cout<<"rellene unos jornales primero antes de acceder a esta opcion\n ";
	}
}

void jornal_cobrado_X_func(nodo *primero,int codigo){
	if(primero!=NULL){
		int sw=0,total=0;
		nodo *aux=primero;
		while(aux!=NULL){
			if((aux->codigo==codigo)&&(aux->jornal.compare("PAGADO")==0)){
				
				if(aux->turno.compare("DIURNO")==0){
					if((aux->dia.compare("FERIADO")==0)&&(aux->dia.compare("SABADO")==0)&&(aux->dia.compare("DOMINGO")==0)){
						total=total+((aux->horas*100000)*1.1);
					}else{
						total=total+(aux->horas*100000);
					}
				}else{
					if((aux->dia.compare("FERIADO")==0)&&(aux->dia.compare("SABADO")==0)&&(aux->dia.compare("DOMINGO")==0)){
						total=total+((aux->horas*135000)*1.15);
					}else{
						total=total+(aux->horas*135000);
					}
				}
				sw=1;
			}
			aux=aux->siguiente;
		}
		if(sw==1){
			cout<<"El total cobrado por el codigo: "<<codigo<<" es: "<<total<<" Gs"<<endl;
		}else{
			cout<<"el usuario que buscas no ha sido encontrado\n";
		}
	}else{
		cout<<"rellene unos jornales primero antes de acceder a esta opcion\n ";
	}
}

void jornal_cobrado_totalizado(nodo*primero){
	if(primero!=NULL){
		int total,suma=0;
		nodo *aux=primero;
		while(aux!=NULL){
			if(aux->jornal.compare("PAGADO")==0){
				if(aux->turno.compare("DIURNO")==0){
					if((aux->dia.compare("FERIADO")==0)&&(aux->dia.compare("SABADO")==0)&&(aux->dia.compare("DOMINGO")==0)){
						total=(aux->horas*100000)*1.1;
					}else{
						total=aux->horas*100000;
					}
				}else{
					if((aux->dia.compare("FERIADO")==0)&&(aux->dia.compare("SABADO")==0)&&(aux->dia.compare("DOMINGO")==0)){
						total=(aux->horas*135000)*1.15;
					}else{
						total=aux->horas*135000;
					}
				}
				suma=suma+total;
			}
			aux=aux->siguiente;
		} 
		 cout<<"El monto total de jornales pagados es:"<<suma<<" Gs"<<endl;
	}else{
		cout<<"rellene unos jornales primero antes de acceder a esta opcion\n ";
	}
}
void jornal_pendiente_X_func(nodo*primero,int codigo){
	if(primero!=NULL){
		int sw=0,total=0;
		nodo *aux=primero;
		while(aux!=NULL){
			if((aux->codigo==codigo)&&(aux->jornal.compare("PENDIENTE")==0)){
				if(aux->turno.compare("DIURNO")==0){
					if((aux->dia.compare("FERIADO")==0)&&(aux->dia.compare("SABADO")==0)&&(aux->dia.compare("DOMINGO")==0)){
						total=total+((aux->horas*100000)*1.1);
					}else{
						total=total+(aux->horas*100000);
					}
				}else{
					if((aux->dia.compare("FERIADO")==0)&&(aux->dia.compare("SABADO")==0)&&(aux->dia.compare("DOMINGO")==0)){
						total=total+((aux->horas*135000)*1.15);
					}else{
						total=total+(aux->horas*135000);
					}
				}
				sw=1;
			}
			aux=aux->siguiente;
			
		}
		if(sw==1){
			cout<<"El total pendiente por el codigo: "<<codigo<<" es: "<<total<<" Gs"<<endl;
		}else{
			cout<<"el usuario que buscas no ha sido encontrado\n";
		}
	}else{
		cout<<"rellene unos jornales primero antes de acceder a esta opcion\n ";
	}
	
}

void jornal_pendiente_totalizado(nodo*primero){
	if(primero!=NULL){
		int total,suma=0;
		nodo *aux=primero;
		while(aux!=NULL){
			if(aux->jornal.compare("PENDIENTE")==0){
				if(aux->turno.compare("DIURNO")==0){
					if((aux->dia.compare("FERIADO")==0)&&(aux->dia.compare("SABADO")==0)&&(aux->dia.compare("DOMINGO")==0)){
						total=(aux->horas*100000)*1.1;
					}else{
						total=aux->horas*100000;
					}
				}else{
					if((aux->dia.compare("FERIADO")==0)&&(aux->dia.compare("SABADO")==0)&&(aux->dia.compare("DOMINGO")==0)){
						total=(aux->horas*135000)*1.15;
					}else{
						total=aux->horas*135000;
					}
				}
				suma=suma+total;
			}
			aux=aux->siguiente;
		} 
		 cout<<"El monto total de jornales pendientes es:"<<suma<<" Gs"<<endl;
	}else{
		cout<<"rellene unos jornales primero antes de acceder a esta opcion\n ";
	}
}

void cancelar_jornal_Cobrado(nodo*primero,int id){
	if(primero!=NULL){
		nodo *aux=primero;
		int sw=0;
		while((aux!=NULL)&&(sw==0)){
			if(aux->id==id){
				sw=1;
				aux->jornal="PENDIENTE";
			}
			aux=aux->siguiente;
		}
		if(sw==1){
			cout<<"se ha cancelado correctamente! \n";
		}else{
			cout<<"el usuario que buscas no ha sido encontrado\n";
		}
		
	}else{
		cout<<"rellene unos jornales primero antes de acceder a esta opcion\n ";
	}
}


int leer_entero(){
	int a;
	cin>>a;
	while(!cin.good()){
		cin.clear();
		fflush(stdin);
		cout<<"ERROR. solo se permiten nros\nvuelva a ingresar: ";cin>>a;
	}
	return a;
}

string leer_caracter(){
	string a;
	int sw=0;
	do{
		sw=0;
		fflush(stdin);
		getline(cin,a);
		for(int c=0;(c<a.length())&&(sw==0);c++){
			a[c]=toupper(a[c]);
			if(isdigit(a[c])==1){
				cout<<"ERROR. solo se permiten caracteres\n vuelva a ingresar: ";
				sw=1;
			}
		}
	}while(sw==1);
	
	return a;
}




/* EJERCICIO 3 - C13
Crear un proceso que permita ingresar las calificaciones de la carrera de ing. En informática para
el periodo lectivo 2022. Donde, cada registro de calificación debe contar con los siguientes datos:
- Cedula del Alumno, Nombre, Apellido, Curso, Materia, Calificación
La aplicación debe permitir realizar las operaciones básicas: Insertar, Modificar, Eliminar
registros y realizar las siguientes consultas:
	- Mostrar los registros cargados
	- Mostrar los registros cargados por curso
	- Mostrar los registros cargados por materia  
	- Buscar los registros relacionados con un alumno	
	- Consultar la cantidad de alumnos con calificaciones (1, 2, 3, 4, 5)
	- Consultar el promedio de las calificaciones por materia	
	- Consultar el promedio de calificaciones en forma global	
	- Consultar la lista de calificaciones por curso	
	- Consultar la lista de calificaciones por materia	
	- Decir cuántos aprobados y no aprobados existen por materia	<---- X
Observación:
- Ningún registro puede estar repetido en la estructura (realizar validación)
- Utilizar la función gotoxy para presentar los datos en forma de tablas

*/
#include <iostream>
#include <windows.h>
#include <string.h>
using namespace std;
struct Nodo{
	int id;
	int cedula;
	string nombre;
	string apellido;
	int curso;
	string materia;
	int calificacion;
	Nodo *siguiente;	
};

struct Materias{
	int c;
	string materia1;
	Materias* siguiente;
};

void gotoxy(int x,int y){  
	HANDLE hcon;  
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
	COORD dwPos;  
	dwPos.X = x;  
	dwPos.Y= y;  
	SetConsoleCursorPosition(hcon,dwPos);  
}  

void cargarLista(Nodo *&, int, int, string, string, int, string, int);
void mostrarLista(Nodo *);
void modificarLista(Nodo *, int);
void cargarmateria(Materias*&,string);

void eliminarNodo(Nodo*&,int);
void registrosXcurso(Nodo*);
void registrosXmateria(Nodo*,Materias*&);
void registrosXalumno(Nodo*,string);
void mostrarCantidades(Nodo *);
void buscarPromMateria(Nodo *, string);
void promCalificacionesG(Nodo*);
void calificacionesXcurso(Nodo*);
void calificacionesXmateria(Nodo*,Materias*&);
void aprobadosXmateria(Nodo*,Materias*&);


bool validarmateria(Materias*,string);
bool validarIngreso(Nodo *, int, string);  
int buscarId(Nodo *);
void encabezado();
void mostrarMenu();
void mensajeSalir();
int leer_entero();
string leer_caracteres();
main(){
	char op;
	int sw=1, id, cedula, curso, cal, menu, ops;
	string nombre, apellido, materia;
	Materias* Lmaterias = NULL;
	Nodo *lista = NULL;
	do{
		system("cls");
		mostrarMenu();
		cin>>menu;
		while((menu<1)||(menu>14)){
			system("cls");
			cout<<" ERROR: el numero ingresado no se encuentra en el rango"<<endl;
			cout<<" Vuelva a Intentar"<<endl;
			system("pause");
			system("cls");
			mostrarMenu();
			cin>>menu;
		}
		switch(menu){
			case 1:
				do{ 
					system("cls");
					cout<<" MENU 1 -> Cargar Registros"<<endl;
					cout<<"--------------------------------------------"<<endl;
					cout<<"Cedula: ";
					cedula=leer_entero();
					cout<<"Nombre: ";
					nombre=leer_caracteres();
					cout<<"Apellido: ";
					apellido=leer_caracteres();
					cout<<"Curso: ";
					curso=leer_entero();
					while((curso<1)||(curso>5)){
						cout<<"ERROR de curso, solo del 1 al 5"<<endl;
						cout<<"Intente de nuevo: ";
						curso=leer_entero();
					}
					cout<<"Materia: ";
					materia=leer_caracteres();
					cout<<"Calificacion: ";
					cal=leer_entero();
					while((cal<1)||(cal>5)){
						cout<<"ERROR de calificacion, solo del 1 al 5"<<endl;
						cout<<"Intente de nuevo: ";
						cal=leer_entero();
					}
					if(validarIngreso(lista,cedula,materia)==false){
						id = buscarId(lista);
						id++;
						cargarLista(lista, id, cedula, nombre, apellido, curso, materia, cal);
						cout<<"Desea ingresar mas registros S/N: ";
						cin>>op;									
					}else{
						cout<<"ERROR: no se puede repetir registros ";
						cout<<"Vuelva a Intentar"<<endl;	
					}										
					system("pause");
					system("cls");
					fflush(stdin);
				}while((op == 'S')||(op == 's'));
				break;
			case 2: 
				system("cls");
				cout<<" MENU 2 -> Modificar Registro"<<endl;
				cout<<"--------------------------------------------"<<endl;
				mostrarLista(lista);
				cout<<" Ingrese ID de registro: ";
				cin>>id;
				modificarLista(lista, id);
				cout<<endl;
				system("pause");
				break;
			case 3: 
				system("cls");
				cout<<" MENU 3 -> Mostrar Registros"<<endl;
				encabezado();
				mostrarLista(lista);
				system("pause");
				break;
			case 4: 
				system("cls");
				cout<<"MENU 4 -> Eliminar Registro"<<endl;
				cout<<"--------------------------------------------"<<endl;
				encabezado();
				mostrarLista(lista);
				system("pause");
				cout<<"ingrese el id del usuario que desea eliminar: ";
				id=leer_entero();
				eliminarNodo(lista,id);
				system("pause");
				break;
			case 5: 
				system("cls");
				cout<<"MENU 5 -> Mostrar Registros por Curso"<<endl;
				cout<<"--------------------------------------------"<<endl;
				registrosXcurso(lista);
				system("pause");
				break;
			case 6: 
				system("cls");
				cout<<"MENU 6 -> Mostrar Registros por Materia"<<endl;
				cout<<"--------------------------------------------"<<endl;
				registrosXmateria(lista,Lmaterias);
				break;
			case 7: 
				
				system("cls");
				cout<<"MENU 7 -> Mostrar Registros por Alumno"<<endl;
				cout<<"--------------------------------------------"<<endl;
				cout<<"ingrese nombre del alumno: ";
				nombre=leer_caracteres();
				cout<<"ingrese nombre del apellido: ";
				apellido=leer_caracteres();
				encabezado();
				registrosXalumno(lista,nombre+apellido);
				system("pause");
				break;
			case 8: 
				system("cls");
				cout<<"MENU 8 -> Mostrar Registros con calificaciones (1, 2, 3, 4, 5)"<<endl;
				cout<<"--------------------------------------------"<<endl;
				mostrarCantidades(lista);
				system("pause");
				break;
			case 9:
				system("cls");
				cout<<"MENU 9 -> Promedio de calificaciones por materia"<<endl;
				cout<<"--------------------------------------------"<<endl; 
				cout<<"Ingrese la materia a consultar: ";
				materia=leer_caracteres();
				buscarPromMateria(lista, materia);
				system("pause");
				break;
			case 10: 
				system("cls");
				cout<<"MENU 10 -> Promedio de calificaciones en forma global"<<endl;
				cout<<"--------------------------------------------"<<endl;
				promCalificacionesG(lista);
				system("pause");
				break;
			case 11: 
				system("cls");
				cout<<"MENU 11 -> Lista de Calificaciones por Curso"<<endl;
				cout<<"--------------------------------------------"<<endl;
				calificacionesXcurso(lista);
				system("pause");
				break;
			case 12: 
				system("cls");
				cout<<"MENU 12 -> Lista de Calificaciones por Materia"<<endl;
				cout<<"--------------------------------------------"<<endl;
				calificacionesXmateria(lista,Lmaterias);
				
				system("pause");				
				break;
			case 13: 
				system("cls");
				cout<<"MENU 13 -> Cantidad de aprobados y no aprobados por materia"<<endl;
				cout<<"--------------------------------------------"<<endl;
				aprobadosXmateria(lista,Lmaterias);
				system("pause");
				break;
			case 14: 
				system("cls");
				mensajeSalir();
				cin>>ops;
				while((ops<1)||(ops>2)){
					system("cls");
					cout<<" ERROR: el numero ingresado solo debe ser 1 o 2"<<endl;
					cout<<" Vuelva a Intentar"<<endl;
					system("pause");
					system("cls");
					mensajeSalir();
					cin>>ops;
				}
				if(ops==1){
					sw=0;
					system("cls");
					cout<<" GRACIAS POR UTILIZAR ESTE PROGRAMA"<<endl;
					cout<<" VUELVA PRONTO"<<endl;
					
				}
				system("pause");
				break;
		}
	}while(sw==1);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	system("pause");
	system("cls");
}
void encabezado(){
	cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
	cout<<" Id	Cedula		Nombre		Apellido		Curso	Materia		Calificacion"<<endl;
	cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
}

void mostrarMenu(){
	cout<<" MENU DE OPCIONES"<<endl;
	cout<<"--------------------------------------------"<<endl;
	cout<<"  1. Insertar Registros"<<endl;
	cout<<"  2. Modificar Registros"<<endl;
	cout<<"  3. Mostrar Registros"<<endl;
	cout<<"  4. Eliminar Registro"<<endl;
	cout<<"  5. Mostrar Registros por Curso"<<endl;
	cout<<"  6. Mostrar Registros por Materia"<<endl;
	cout<<"  7. Mostrar Registros por Alumno"<<endl;
	cout<<"  8. Cantidad de alumnos con calificaciones (1,2,3,4,5)"<<endl;
	cout<<"  9. Promeio de calificaciones por materia"<<endl;
	cout<<"  10. Promedio de calificaciones en forma global"<<endl;
	cout<<"  11. Lista de Calificaciones por Curso"<<endl;
	cout<<"  12. Lista de Calificaciones por Materia"<<endl;
	cout<<"  13. Cantidad de aprobados y no aprobados por materia"<<endl;
	cout<<"  14. Salir o Regresar"<<endl;
	cout<<"--------------------------------------------"<<endl;
	cout<<"\n  Seleccionar una opcion: ";
}
void mensajeSalir(){
	cout<<" Desea salir de la aplicacion"<<endl;
	cout<<" 1. Si"<<endl;
	cout<<" 2. No"<<endl;
	cout<<" Opcion seleccionada: ";
}
int buscarId(Nodo *lista){
	int id=0;
	Nodo *actual = lista;
	if(actual != NULL){
		while(actual != NULL){
			id = actual->id;			
			actual = actual->siguiente;
		}
	}
	return id;	
}
int leer_entero(){
	int a;
	cin>>a;
	while(!cin.good()){
		cin.clear();
		fflush(stdin);
		cout<<"error. solo se permiten valores numericos\ningrese de nuevo: ";
		cin>>a;
	}
	return a;
}
string leer_caracteres(){
	string a;
	int sw=0;
	do{
		sw=0;
		fflush(stdin);
		getline(cin,a);
		for(int c=0;c<a.length();c++){
			a[c]=toupper(a[c]);
			if(isdigit(a[c]==1)){
				sw=1;
			}
		}
	}while(sw==1);
	return a;
}
void cargarLista(Nodo *&lista, int id, int cedula, string nombre, string apellido, int curso, string materia, int cal){
	Nodo *n_nodo = new Nodo();
	//guardar registro
	n_nodo->id=id;
	n_nodo->cedula=cedula;
	n_nodo->nombre=nombre;
	n_nodo->apellido=apellido;
	n_nodo->curso=curso;
	n_nodo->materia=materia;
	n_nodo->calificacion=cal;
	//fin guardar registro
	Nodo *aux1 = lista;
	Nodo *aux2;
	while (aux1 != NULL){
		aux2= aux1;
		aux1 = aux1->siguiente;
	}
	if(lista == aux1){
		lista = n_nodo;
	}else{
		aux2->siguiente= n_nodo;
	}
	n_nodo->siguiente = aux1;
	cout<<"EL registro fue cargado correctamente en la lista. "<<endl;
	cout<<"\n";
}

void mostrarLista(Nodo *lista){
	int f=4;
	Nodo *actual = lista;
	if(actual != NULL){
		while(actual != NULL){
			f++;
			gotoxy(2,f);cout<<actual->id;
			gotoxy(8,f);cout<<actual->cedula;
			gotoxy(24,f);cout<<actual->nombre;
			gotoxy(40,f);cout<<actual->apellido;
			gotoxy(64,f);cout<<actual->curso;
			gotoxy(72,f);cout<<actual->materia;
			gotoxy(88,f);cout<<actual->calificacion;			
			actual = actual->siguiente;
		}
		cout<<endl;
	}else{
		cout<<"Nno existe registros guardados"<<endl;
	}	
}
bool validarIngreso(Nodo *lista, int cedula, string materia){
	bool correcto = false;
	int sw=0;
	Nodo *actual = lista;
	if(actual != NULL){
		while((actual != NULL) && (sw==0)){
			if((actual->cedula == cedula) && (materia.compare(actual->materia) == 0)){
				sw=1;	
			}
			actual = actual->siguiente;
		}
		if(sw==1){
			correcto = true;
		}
	}else{
		correcto = false;
	}
	return correcto;
}
void eliminarNodo(Nodo *&lista, int n){
	if(lista != NULL){
		Nodo *aux_b = lista;
		Nodo *anterior = NULL;				
		while((aux_b != NULL) && (aux_b->id != n)){
			anterior = aux_b;
			aux_b = aux_b->siguiente;
		}		
		if(aux_b == NULL){
			cout<<"\nEl elemento no ha sido encontrado\n ";			
		}else if(anterior == NULL){
			lista = lista->siguiente;
			delete aux_b;				
		}else{
			anterior->siguiente = aux_b->siguiente;
			delete aux_b;
			cout<<"\nEL registro "<<n<<" fue eliminado correctamente de la lista. "<<endl;
			cout<<"\n";
		}		
	}else{
		cout<<"La lista está vacía"<<endl;
	}
}
void registrosXcurso(Nodo* lista){
	Nodo *actual = lista;
	if(actual != NULL){
		int f=4;
		for(int c=1;c<=5;c++){
			actual=lista;
			encabezado();
			while(actual != NULL){
				if(actual->curso==c){		
					f++;
					gotoxy(2,f);cout<<actual->id;
					gotoxy(8,f);cout<<actual->cedula;
					gotoxy(24,f);cout<<actual->nombre;
					gotoxy(40,f);cout<<actual->apellido;
					gotoxy(64,f);cout<<actual->curso;
					gotoxy(72,f);cout<<actual->materia;
					gotoxy(88,f);cout<<actual->calificacion;
					cout<<endl;
				}			
				actual = actual->siguiente;
			}
			system("pause");
			system("cls");
			actual=lista;
			f=4;
		}
	
		system("pause");
	}else{
		cout<<"Nno existe registros guardados"<<endl;
	}
}
void registrosXmateria(Nodo* lista,Materias*& Lmaterias){
	Nodo *actual = lista;
	if(actual != NULL){
		if(Lmaterias == NULL){
			while(actual != NULL){
				if(Lmaterias==NULL){
					cargarmateria(Lmaterias,actual->materia);
				}else{
					while(validarmateria(Lmaterias,actual->materia)){
						actual=actual->siguiente;
					}
					cargarmateria(Lmaterias,actual->materia);
				}
				actual = actual->siguiente;
			}
		}
		Materias* aux=Lmaterias;
		actual=lista;
		while(aux!=NULL){
			actual=lista;
			while(actual!=NULL){
				if(aux->materia1.compare(actual->materia)==0){
					aux->c=aux->c+1;
				}
				actual=actual->siguiente;
			}	
			aux=aux->siguiente;
		}
		aux=Lmaterias;
		while(aux!=NULL){
			cout<<"la cantidad de registros en la materia "<<aux->materia1<<" es: "<<aux->c<<endl;
			aux->c=0;
			aux=aux->siguiente;
		}
		system("pause");
		
		
	}else{
		cout<<"Nno existe registros guardados"<<endl;
	}
}
void cargarmateria(Materias*& Lista,string materia){
	Materias* n_nuevo=new Materias();
	n_nuevo->materia1=materia;
	
	Materias* aux1=Lista;
	Materias* aux2=NULL;
	while(aux1!=NULL){
		aux2=aux1;
		aux1=aux1->siguiente;
	}	
	if(Lista==NULL){
		Lista=n_nuevo;
	}else{
		aux2->siguiente=n_nuevo;	
	}
	n_nuevo->siguiente=aux1;	
}
bool validarmateria(Materias* lista, string materia){
	Materias* aux=lista;
	int sw=0;
	while((aux!=NULL)&&(sw==0)){
		if(aux->materia1.compare(materia)==0){
			sw=1;
		}
		aux=aux->siguiente;
	}
	if(sw==1){
		return true;
	}else{
		return false;
	}
	
}
void registrosXalumno(Nodo*lista, string nombreapellido){
	if(lista!=NULL){
		int f=7;
		Nodo* actual=lista;
		while(actual!=NULL){
			if(nombreapellido.compare(actual->nombre+actual->apellido)==0){
				f++;
				gotoxy(2,f);cout<<actual->id;
				gotoxy(8,f);cout<<actual->cedula;
				gotoxy(24,f);cout<<actual->nombre;
				gotoxy(40,f);cout<<actual->apellido;
				gotoxy(64,f);cout<<actual->curso;
				gotoxy(72,f);cout<<actual->materia;
				gotoxy(88,f);cout<<actual->calificacion;			
				actual = actual->siguiente;
			}
		}
	}else{
		cout<<"la lista esta vacia\n";
	}
}
void mostrarCantidades(Nodo *lista){
	int c1=0, c2=0, c3=0, c4=0, c5=0;
	Nodo *actual = lista;
	if(actual != NULL){
		while(actual != NULL){
			switch(actual->calificacion){
				case 1: c1++; break;
				case 2: c2++; break;
				case 3: c3++; break;
				case 4: c4++; break;
				case 5: c5++; break;
			}			
			actual = actual->siguiente;
		}
		cout<<"Cantidad de 1: "<<c1<<endl;
		cout<<"Cantidad de 2: "<<c2<<endl;
		cout<<"Cantidad de 3: "<<c3<<endl;
		cout<<"Cantidad de 4: "<<c4<<endl;
		cout<<"Cantidad de 5: "<<c5<<endl;
		cout<<endl;
		system("pause");
	}else{
		cout<<"Nno existe registros guardados"<<endl;
	}	
}
void buscarPromMateria(Nodo *lista, string materia){
	int can=0;
	float sum=0, pro;
	Nodo *actual = lista;
	if(actual != NULL){
		while(actual != NULL){
			if(materia.compare(actual->materia) == 0){
				sum = sum + actual->calificacion;
				can++;	
			}
			actual = actual->siguiente;
		}
		pro = sum/can;
		cout<<"El promedio es: "<<pro<<endl;
	}else{
		cout<<"No existe registros para buscar"<<endl;
	}
	system("pause");
}
void promCalificacionesG(Nodo* lista){
	if(lista!=NULL){
		Nodo* actual=lista;
		int c=0;
		float suma=0,prom;
		while(actual!=NULL){
			c++;
			suma=suma+actual->calificacion;
			actual=actual->siguiente;
		}
		prom=suma/c;
		cout<<"El Promedio global es: "<<prom<<endl;
	}else{
		cout<<"la lista esta vacia\n";
	}
}
void calificacionesXcurso(Nodo* lista){
	Nodo *actual = lista;
	if(actual != NULL){
		int f=4;
		for(int c=1;c<=5;c++){
			cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
			cout<<"| Id	|	Curso	|	Materia		|	Calificacion"<<endl;
			cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
			while(actual != NULL){
				if(actual->curso==c){
					f++;
					gotoxy(2,f);cout<<actual->id;
					gotoxy(8,f);cout<<actual->curso;
					gotoxy(20,f);cout<<actual->materia;
					gotoxy(30,f);cout<<actual->calificacion;
				}
				actual = actual->siguiente;
			}
			system("pause");
		}
		cout<<endl;
		system("pause");
	}else{
		cout<<"No existe registros guardados"<<endl;
	}
}
void calificacionesXmateria(Nodo*lista ,Materias*& Lmaterias){
	Nodo *actual = lista;
	if(actual != NULL){
		if(Lmaterias == NULL){
			while(actual != NULL){
				if(Lmaterias==NULL){
					cargarmateria(Lmaterias,actual->materia);
				}else{
					while(validarmateria(Lmaterias,actual->materia)){
						actual=actual->siguiente;
					}
					cargarmateria(Lmaterias,actual->materia);
				}
				actual = actual->siguiente;
			}
		}
		
			Materias* aux=Lmaterias;
			int f=4;
			while(aux!=NULL){
				cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
				cout<<"| Id	|	Curso	|	Materia		|	Calificacion"<<endl;
				cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
				while(actual!=NULL){
					if(aux->materia1.compare(actual->materia)==0){
						f++;
						gotoxy(2,f);cout<<actual->id;
						gotoxy(14,f);cout<<actual->curso;
						gotoxy(26,f);cout<<actual->materia;
						gotoxy(45,f);cout<<actual->calificacion;
						cout<<endl;
					}
					actual=actual->siguiente;
				}	
				aux=aux->siguiente;
				f=4;
				actual=lista;
				system("pause");
				system("cls");
			}
			
	}else{
		cout<<"Nno existe registros guardados"<<endl;
	}
}
void aprobadosXmateria(Nodo* lista,Materias*& Lmaterias){
	
	Nodo *actual = lista;
	if(actual != NULL){
		if(Lmaterias==NULL){
			while(actual != NULL){
				if(Lmaterias==NULL){
					cargarmateria(Lmaterias,actual->materia);
				}else{
					while(validarmateria(Lmaterias,actual->materia)){
						actual=actual->siguiente;
					}
					cargarmateria(Lmaterias,actual->materia);
				}
				//actual = actual->siguiente;
			}
		}else{
			Materias* aux=Lmaterias;
			int aprobados=0;
			while(aux!=NULL){	
				while(actual!=NULL){
					if((aux->materia1.compare(actual->materia)==0)&&(actual->calificacion>1)){
						aprobados++;
					}
					actual=actual->siguiente;
				}	
				cout<<"la cantidad de aprobados en "<<aux->materia1<<" es: "<<aprobados<<endl;
				aprobados=0;
				actual=lista;
				aux=aux->siguiente;
			}
			system("pause");
		}
		
	}else{
		cout<<"Nno existe registros guardados"<<endl;
	}
}
void modificarLista(Nodo *lista, int id){
	int swb=0, cedula, curso, cal;
	string nombre, apellido, materia;
	Nodo *actual = lista;
	if(actual != NULL){
		while((actual != NULL) && (swb == 0)){
			if(actual->id == id){
				swb = 1;
			}else{
				actual = actual->siguiente;	
			}			
		}
		if(swb == 0){
			cout<<"El Codigo ingresado, no existe"<<endl;		
		}else{
			cout<<"Ingrese los datos para modificar el registro"<<endl;
			cout<<"Cedula: ";
			cedula=leer_entero();
			cout<<"Nombre: ";
			nombre=leer_caracteres();
			cout<<"Apellido: ";
			apellido=leer_caracteres();
			cout<<"Curso: ";
			curso=leer_entero();
			while((curso<1)||(curso>5)){
				cout<<"ERROR de curso, solo del 1 al 5"<<endl;
				cout<<"Intente de nuevo: ";
				curso=leer_entero();
			}
			cout<<"Materia: ";
			materia=leer_caracteres();
			cout<<"Calificacion: ";
			cal=leer_entero();
			while((cal<1)||(cal>5)){
				cout<<"ERROR de calificacion, solo del 1 al 5"<<endl;
				cout<<"Intente de nuevo: ";
				cal=leer_entero();
			}
			
			actual->cedula=cedula;
			actual->nombre=nombre;
			actual->apellido=apellido;
			actual->curso=curso;
			actual->materia=materia;
			actual->calificacion=cal;
			cout<<"Registro Modificado Satisfactoriamente"<<endl;		
		}		
	}else{
		cout<<"La lista se encuentra vacia"<<endl;
	}	
}

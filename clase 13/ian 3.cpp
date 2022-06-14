/* EJERCICIO 3 - C13
Crear un proceso que permita ingresar las calificaciones de la carrera de ing. En inform�tica para
el periodo lectivo 2022. Donde, cada registro de calificaci�n debe contar con los siguientes datos:
- Cedula del Alumno, Nombre, Apellido, Curso, Materia, Calificaci�n
La aplicaci�n debe permitir realizar las operaciones b�sicas: Insertar, Modificar, Eliminar
registros y realizar las siguientes consultas:
	- Mostrar los registros cargados
	- Mostrar los registros cargados por curso
	- Mostrar los registros cargados por materia  <---- X
	- Buscar los registros relacionados con un alumno	<---- X
	- Consultar la cantidad de alumnos con calificaciones (1, 2, 3, 4, 5)	<---- X
	- Consultar el promedio de las calificaciones por materia	<---- X
	- Consultar el promedio de calificaciones en forma global	<---- X
	- Consultar la lista de calificaciones por curso	<---- X
	- Consultar la lista de calificaciones por materia	<---- X
	- Decir cu�ntos aprobados y no aprobados existen por materia	<---- X
Observaci�n:
- Ning�n registro puede estar repetido en la estructura (realizar validaci�n)
- Utilizar la funci�n gotoxy para presentar los datos en forma de tablas

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
void eliminarNodo(Nodo*&,int);
void registrosXcurso(nodo*);
void registrosXmateria(nodo*);



bool validarIngreso(Nodo *, int, string);  
int buscarId(Nodo *);
void mostrarMenu();
void mensajeSalir();
int leer_entero();
int leer_caracteres();
main(){
	string op;
	int sw=0, id, cedula, curso, cal, menu, ops;
	string nombre, apellido, materia;
	Nodo *lista = NULL;
	do{
		system("cls");
		mostrarMenu();
		cin>>menu;
		while((menu<1)||(menu>13)){
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
				cout<<" Ingrese Codigo de Registro: ";
				cin>>id;
				modificarLista(lista, id);
				cout<<endl;
				break;
			case 3: 
				system("cls");
				cout<<" MENU 3 -> Mostrar Registros"<<endl;
				cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
				cout<<" Id	Cedula		Nombre		Apellido		Curso	Materia		Calificacion"<<endl;
				cout<<"--------------------------------------------------------------------------------------------------------"<<endl;
				mostrarLista(lista);
				system("pause");
				break;
			case 4: 
				system("cls");
				cout<<"MENU 4 -> Eliminar Registro"<<endl;
				cout<<"--------------------------------------------"<<endl;
				mostrarLista(lista);
				system("pause");
				cout<<"ingrese el id del usuario que desea eliminar: ";
				id=leer_entero();
				eliminarNodo(lista,id);
				system("pause");
				break;
			case 5: 
				system("cls");
				cout<<"MENU 4 -> Mostrar Registros por Curso"<<endl;
				cout<<"--------------------------------------------"<<endl;
				registrosXcurso(lista);
				break;
			case 6: 
				system("cls");
				cout<<"MENU 5 -> Mostrar Registros por Materia"<<endl;
				cout<<"--------------------------------------------"<<endl;
				registrosXmateria(lista);
				
				
				break;
			case 7: 
				system("cls");
				cout<<"MENU 6 -> Mostrar Registros por Alumno"<<endl;
				cout<<"--------------------------------------------"<<endl;
				break;
			case 8: 
				system("cls");
				cout<<"MENU 7 -> Mostrar Registros con calificaciones (1, 2, 3, 4, 5)"<<endl;
				cout<<"--------------------------------------------"<<endl;
				mostrarCantidades(lista);
				break;
			case 9:
				system("cls");
				cout<<"MENU 8 -> Promedio de calificaciones por materia"<<endl;
				cout<<"--------------------------------------------"<<endl; 
				cout<<"Ingrese la materia a consultar: ";
				getline(cin,materia); fflush(stdin);
				buscarPromMateria(lista, materia);
				break;
			case 10: 
				system("cls");
				cout<<"MENU 9 -> Promedio de calificaciones en forma global"<<endl;
				cout<<"--------------------------------------------"<<endl;
				break;
			case 11: 
				system("cls");
				cout<<"MENU 10 -> Lista de Calificaciones por Curso"<<endl;
				cout<<"--------------------------------------------"<<endl;
				break;
			case 12: 
				system("cls");
				cout<<"MENU 11 -> Lista de Calificaciones por Materia"<<endl;
				cout<<"--------------------------------------------"<<endl;
				system("pause");				
				break;
			case 13: 
				system("cls");
				cout<<"MENU 12 -> Cantidad de aprobados y no aprobados por materia"<<endl;
				cout<<"--------------------------------------------"<<endl;
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
					sw=1;
					system("cls");
					cout<<" GRACIAS POR UTILIZAR ESTE PROGRAMA"<<endl;
					cout<<" VUELVA PRONTO"<<endl;
				}
				break;
		}
	}while(sw==1);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	system("pause");
	system("cls");
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
		cout<<"error. solo se permiten valores numericos\n";
		cin>>a;
	}
}
int leer_caracteres(){
	string a;
	int sw=0;
	do{
		sw=0;
		fflush(stdin);
		getline(cin,a);
		for(int c=0;c<a.length();c++{
			a[c]=toupper(a[c]);
			if(isdigit(a[c]==1)){
				sw=1;
			}
		}
	}while(sw==1;);
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
			cout<<"Encontro"<<endl;
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
		while((aux_b != NULL) && (aux_b->dato != n)){
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
			cout<<"\nEL numero "<<n<<" fue eliminado correctamente de la lista. "<<endl;
			cout<<"\n";
		}		
	}else{
		cout<<"La lista est� vac�a"<<endl;
	}
}
void registrosXcurso(nodo* lista){
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
		cout<<"La Cantidad de Alumnos del 1�: "<<c1<<endl;
		cout<<"La Cantidad de Alumnos del 2�: "<<c2<<endl;
		cout<<"LA Cantidad de Alumnos del 3�: "<<c3<<endl;
		cout<<"La Cantidad de Alumnos del 4�: "<<c4<<endl;
		cout<<"La Cantidad de Alumnos del 5�: "<<c5<<endl;
		cout<<endl;
		system("pause");
	}else{
		cout<<"Nno existe registros guardados"<<endl;
	}
}
void registrosXmateria(nodo* lista){
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
		cout<<"La Cantidad de Alumnos del 1�: "<<c1<<endl;
		cout<<"La Cantidad de Alumnos del 2�: "<<c2<<endl;
		cout<<"LA Cantidad de Alumnos del 3�: "<<c3<<endl;
		cout<<"La Cantidad de Alumnos del 4�: "<<c4<<endl;
		cout<<"La Cantidad de Alumnos del 5�: "<<c5<<endl;
		cout<<endl;
		system("pause");
	}else{
		cout<<"Nno existe registros guardados"<<endl;
	}
}
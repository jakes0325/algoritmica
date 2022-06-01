/*
	 Crear una estructura que permita cargar los siguientes registros para la materia de Algorítmica: cedula, nombre
	y apellido, curso, parcial 1, parcial 2, trabajo practico, donde se debe prestar atención a los siguientes detalles:
	- Los datos ingresados deben ser validados, es decir, en campos numéricos no deben ser permitidos datos
	alfanuméricos y viceversa.
	- Las parciales deben tener valores en los rangos de 0 a 15 puntos.
	- El trabajo practico debe tener un rango de 0 a 10 puntos.
	- La calificación dependerá del total de puntos el cual es la sumatoria entre las parciales y el trabajo
	practico. A su vez, la calificación deberá ser calculado teniendo en cuenta la siguiente escala. 
		A partir de los datos ingresados, mostrar los siguientes resultados
	- Opción 1: Mostrar los datos ingresados en forma de tabla
	- Opción 2: Ingresar un curso y filtrar la lista por el curso ingresado
	- Opción 3: Ingresar la cedula de identidad de un alumno, y filtrar los datos del mismo
	- Opción 4: Salir del Programa 
*/
#include<iostream>
#include<windows.h>
#include<string.h>

using namespace std;

struct registros{
	int cedula;
	string nombre;
	string apellido;
	string curso;
	int parcial1;
	int parcial2;
	int trabajo_practico;
};
int limite();
void cargarstructura(registros*,int);
void imprimirstructura(registros*,int);
void validarstring(string);
void cursoingresado(registros*,int);
void cedulaingresada(registros*,int);
main(){
	int l=limite();
	registros alu[l];
	registros *alumnos= &alu[0];
	int op;
	cargarstructura(alumnos,l);
	do{
		cout<<"-----------------------------------------------------------------"<<endl;
		cout<<"----------------------MENU---------------------------------------"<<endl;
		cout<<"-----------------------------------------------------------------"<<endl;
		cout<<"opcion 1 = Mostrar los datos ingresados"<<endl;
		cout<<"Opción 2 = Ingrese un curso para filtrar la lista por el curso ingresado"<<endl;
		cout<<"Opción 3 = Ingrese la cedula de identidad de un alumno para filtrar los datos del mismo"<<endl;
		cout<<"Opción 4 = salir del programa"<<endl;
		cout<<"-----------------------------------------------------------------"<<endl;
		do{
			cout<<"ingrese una opcion:";cin>>op;
			while(!cin.good()){
			cin.clear();
			fflush(stdin);
			cout<<"solo se permiten nros: ";cin>>op;
			}
		}while((op<=0)||(op>4));
		switch(op){
			case 1:
				imprimirstructura(alumnos,l);
				system("pause");
				system("cls");
				break;
			case 2:
				cursoingresado(alumnos,l);
				system("pause");
				system("cls");
				break;
			case 3:
				cedulaingresada(alumnos,l);
				system("pause");
				system("cls");
				break;
			case 4:
				cout<<"!gracias por usar el programa!"<<endl;
				break;
		}
	}while(op!=4);
	system("pause");
	system("cls");
}
int limite(){
	int l;
	do{
		cout<<"ingrese cantidad de alumnos: ";cin>>l;
		while(!cin.good()){
			cin.clear();
			fflush(stdin);
			cout<<"solo se permiten nros: ";cin>>l;
		}
	}while(l<=0);
	return l;
}
void cargarstructura(registros* alumnos,int l){
	for(int c=0;c<l;c++){
		do{
			cout<<"ingrese nro de cedula: ";cin>>alumnos[c].cedula;
			while(!cin.good()){
			cin.clear();
			fflush(stdin);
			cout<<"solo se permiten nros: ";cin>>alumnos[c].cedula;
			}
		}while(alumnos[c].cedula<=0);
		fflush(stdin);
		cout<<"ingrese nombre: ";getline(cin,alumnos[c].nombre);
		validarstring(alumnos[c].nombre);
		fflush(stdin);
		cout<<"ingrese apellido: ";getline(cin,alumnos[c].apellido);
		validarstring(alumnos[c].apellido);
		fflush(stdin);
		cout<<"ingrese curso: ";getline(cin,alumnos[c].curso);
		validarstring(alumnos[c].curso);
		do{
			cout<<"ingrese puntaje de parcial 1(0 - 15) : ";cin>>alumnos[c].parcial1;
			while(!cin.good()){
			cin.clear();
			fflush(stdin);
			cout<<"solo se permiten nros: ";cin>>alumnos[c].parcial1;
			}
		}while((alumnos[c].parcial1<0)||(alumnos[c].parcial1>15));
		do{
			cout<<"ingrese puntaje de parcial 2(0 - 15) : ";cin>>alumnos[c].parcial2;
			while(!cin.good()){
			cin.clear();
			fflush(stdin);
			cout<<"solo se permiten nros: ";cin>>alumnos[c].parcial2;
			}
		}while((alumnos[c].parcial2<0)||(alumnos[c].parcial2>15));
		do{
			cout<<"ingrese cantidad de puntaje hecho en el trabajo practico (0 - 10): ";cin>>alumnos[c].trabajo_practico;
			while(!cin.good()){
			cin.clear();
			fflush(stdin);
			cout<<"solo se permiten nros: ";cin>>alumnos[c].trabajo_practico;
			}
		}while((alumnos[c].trabajo_practico<0)||(alumnos[c].trabajo_practico>10));
	}
}
void imprimirstructura(registros* alumnos,int l){
	int suma=0;
	for(int c=0;c<l;c++){
		cout<<"-----------------------------------------------------------------"<<endl;
		cout<<"----------------------------ALUMNO "<<c+1<<"---------------------"<<endl;
		cout<<"-----------------------------------------------------------------"<<endl;
		cout<<" nro de cedula: "<<alumnos[c].cedula<<endl;
		cout<<"-----------------------------------------------------------------"<<endl;	
		cout<<" nombre: "<<alumnos[c].nombre<<endl;
		cout<<"-----------------------------------------------------------------"<<endl;
		cout<<" apellido: "<<alumnos[c].apellido<<endl;
		cout<<"-----------------------------------------------------------------"<<endl;
		cout<<" curso: "<<alumnos[c].curso<<endl;
		cout<<"-----------------------------------------------------------------"<<endl;
		cout<<" puntaje de parcial 1(0 - 15) : "<<alumnos[c].parcial1<<endl;
		cout<<"-----------------------------------------------------------------"<<endl;
		cout<<" puntaje de parcial 2(0 - 15) : "<<alumnos[c].parcial2<<endl;
		cout<<"-----------------------------------------------------------------"<<endl;
		cout<<" trabajo practico (0 - 10): "<<alumnos[c].trabajo_practico<<endl;
		cout<<"-----------------------------------------------------------------"<<endl;
		suma = alumnos[c].parcial1 + alumnos[c].parcial2 + alumnos[c].trabajo_practico;
		if(suma<=27){
			cout<<"su calificacion es 1"<<endl;
		}else if((suma>27)&&(suma<=30)){
			cout<<"su calificacion es 2"<<endl;
		}else if((suma>30)&&(suma<=34)){
			cout<<"su calificacion es 3"<<endl;
		}else if((suma>34)&&(suma<=37)){
			cout<<"su calificacion es 4"<<endl;
		}else if((suma>37)&&(suma<=40)){
			cout<<"su calificacion es 5"<<endl;
		}
		cout<<"-----------------------------------------------------------------"<<endl;
	}
}
void validarstring(string a){
	int sw=0;
	for(int c=0;(c<a.length())&&(sw==0);c++){
		if(isdigit(a[c])==true){
			cout<<"usted ingreso un nro, por favor ingrese lo indicado";
			cin.clear();
			fflush(stdin);
			cout<<endl<<" ingrese de nuevo: ";
			getline(cin,a);
			validarstring(a);
			sw=1;
		}
	}
}

void cursoingresado(registros* alumnos,int l){
	string a;
	int suma;
	fflush(stdin);
	cout<<"-filtrado por curso-"<<endl;
	cout<<"ingrese curso:";getline(cin,a);
	validarstring(a);
	for(int c=0;c<a.length();c++){
		a[c]=toupper(a[c]);
	}
	fflush(stdin);
	for(int c=0;c<l;c++){	
		string aux = alumnos[c].curso;
		for(int c=0;c<aux.length();c++){
			aux[c]=toupper(aux[c]);
		}	
		if((a.compare(aux)==0)||(aux.compare(a)==0)){
			cout<<"-----------------------------------------------------------------"<<endl;
			cout<<"----------------------------ALUMNO "<<c+1<<"---------------------"<<endl;
			cout<<"-----------------------------------------------------------------"<<endl;
			cout<<" nro de cedula: "<<alumnos[c].cedula<<endl;
			cout<<"-----------------------------------------------------------------"<<endl;	
			cout<<" nombre: "<<alumnos[c].nombre<<endl;
			cout<<"-----------------------------------------------------------------"<<endl;
			cout<<" apellido: "<<alumnos[c].apellido<<endl;
			cout<<"-----------------------------------------------------------------"<<endl;
			cout<<" curso: "<<alumnos[c].curso<<endl;
			cout<<"-----------------------------------------------------------------"<<endl;
			cout<<" puntaje de parcial 1(0 - 15) : "<<alumnos[c].parcial1<<endl;
			cout<<"-----------------------------------------------------------------"<<endl;
			cout<<" puntaje de parcial 2(0 - 15) : "<<alumnos[c].parcial2<<endl;
			cout<<"-----------------------------------------------------------------"<<endl;
			cout<<" trabajo practico (0 - 10): "<<alumnos[c].trabajo_practico<<endl;
			cout<<"-----------------------------------------------------------------"<<endl;
			suma = alumnos[c].parcial1 + alumnos[c].parcial2 + alumnos[c].trabajo_practico;
			if(suma<=27){
				cout<<"su calificacion es 1"<<endl;
			}else if((suma>27)&&(suma<=30)){
				cout<<"su calificacion es 2"<<endl;
			}else if((suma>30)&&(suma<=34)){
				cout<<"su calificacion es 3"<<endl;
			}else if((suma>34)&&(suma<=37)){
				cout<<"su calificacion es 4"<<endl;
			}else if((suma>37)&&(suma<=40)){
				cout<<"su calificacion es 5"<<endl;
			}
			cout<<"-----------------------------------------------------------------"<<endl;
		}
	}
}
void cedulaingresada(registros* alumnos,int l){
	int a;
	int suma;
	cout<<"-filtrado por cedula-"<<endl;
	do{
		cout<<"ingrese nro de cedula: ";cin>>a;
		while(!cin.good()){
			cin.clear();
			fflush(stdin);
			cout<<"solo se permiten nros: ";cin>>a;
		}
	}while(a<=0);
	for(int c=0;c<l;c++){
		if(a==alumnos[c].cedula){
			cout<<"-----------------------------------------------------------------"<<endl;
			cout<<"----------------------------ALUMNO "<<c+1<<"---------------------"<<endl;
			cout<<"-----------------------------------------------------------------"<<endl;
			cout<<" nro de cedula: "<<alumnos[c].cedula<<endl;
			cout<<"-----------------------------------------------------------------"<<endl;	
			cout<<" nombre: "<<alumnos[c].nombre<<endl;
			cout<<"-----------------------------------------------------------------"<<endl;
			cout<<" apellido: "<<alumnos[c].apellido<<endl;
			cout<<"-----------------------------------------------------------------"<<endl;
			cout<<" curso: "<<alumnos[c].curso<<endl;
			cout<<"-----------------------------------------------------------------"<<endl;
			cout<<" puntaje de parcial 1(0 - 15) : "<<alumnos[c].parcial1<<endl;
			cout<<"-----------------------------------------------------------------"<<endl;
			cout<<" puntaje de parcial 2(0 - 15) : "<<alumnos[c].parcial2<<endl;
			cout<<"-----------------------------------------------------------------"<<endl;
			cout<<" trabajo practico (0 - 10): "<<alumnos[c].trabajo_practico<<endl;
			cout<<"-----------------------------------------------------------------"<<endl;
			suma = alumnos[c].parcial1 + alumnos[c].parcial2 + alumnos[c].trabajo_practico;
			if(suma<=27){
				cout<<"su calificacion es 1"<<endl;
			}else if((suma>27)&&(suma<=30)){
				cout<<"su calificacion es 2"<<endl;
			}else if((suma>30)&&(suma<=34)){
				cout<<"su calificacion es 3"<<endl;
			}else if((suma>34)&&(suma<=37)){
				cout<<"su calificacion es 4"<<endl;
			}else if((suma>37)&&(suma<=40)){
				cout<<"su calificacion es 5"<<endl;
			}
			cout<<"-----------------------------------------------------------------"<<endl;
		}
	}
}




/*
	Comprobar si un número es par o impar, y señalar la posición de memoria donde se está guardando el numero
	utilizando punteros.
*/
#include<iostream>
#include<windows.h>
using namespace std;


main(){
	int n;
	cout<<"ingrese nros: ";cin>>n;
	if(n%2==0){
		cout<<"el nro es par"<<endl;
	}else{
		cout<<"el nro es impar"<<endl;
	}
	cout<<"la posicion de memoria es: "<<&n<<endl;
	
	
	
	
	
	
	
	
	
	
	system("pause");
	system("cls");
}

/*
	Comprobar si un n�mero es par o impar, y se�alar la posici�n de memoria donde se est� guardando el numero
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

/*
1) Comprobar si un n�mero es par o impar, y se�alar la posici�n de memoria
donde se est� guardando el numero utilizando punteros. 
*/

#include <iostream>
#include <ctype.h>
#include <windows.h>

using namespace std;

main(){
	int *var, a;
	
	cout<<"Ingrese un numero: "; 
	cin>>a;
	
	var= &a;
	
	if(*var%2==0){
		cout<<"El numero es par - posicion: "<<var;
	}else{
		cout<<"El numero es impar - posicion: "<<var;
	}
	
	cout<<endl;
	system("pause");
}

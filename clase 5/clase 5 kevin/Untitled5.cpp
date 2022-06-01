/*
5) Ingresar un Numero y calcular su factorial en forma recursiva. 
*/
#include <iostream>
#include <windows.h>
using namespace std;

int factorial(int);

main(){
	int n;
	cout<<"Ingrese numero: ";
	cin>>n;
	while(n<=0){
		cout<<"Error. solo numeros positivos -> ";
		cin>>n;
	}
	cout<<"\nLa factorial de "<<n<<" es: "<<factorial(n)<<endl;
}

int factorial(int numero){
	if(numero<=1){
		return 1;
	}else{
		return numero * factorial(numero-1);
	}
}

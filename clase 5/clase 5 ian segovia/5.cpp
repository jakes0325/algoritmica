/*
	Ingresar un Numero y calcular su factorial en forma recursiva. 
*/
#include<iostream>
#include<windows.h>

using namespace std;
int factorial(int);
main(){
	int n;
	cout<<"ingrese nro: ";cin>>n;
	while(!cin.good()){
		cin.clear();
		fflush(stdin);
		cout<<"solo se puede ingresar nros: ";cin>>n;
	}
	cout<<"la factorial de "<<n<<" es:  "<<factorial(n)<<endl;
	system("pause");
	system("cls");
	
}
int factorial(int n){
	if(n<=1){
		return 1;
	}else{
		return n * factorial(n-1); 
	}
}







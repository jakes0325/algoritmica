/*
	Rellenar un arreglo con “n” números, posteriormente utilizando punteros determinar el menor elemento del
	arreglo.
*/
#include<iostream>
#include<windows.h>
#include<ctype.h>

using namespace std;

void menor(int*,int);
main(){
	int n;
	do{
		cout<<"ingrese tamaño del arreglo: ";cin>>n;
		while(!cin.good()){
			cin.clear();
			fflush(stdin);
			cout<<"solo se aceptan numeros: ";cin>>n;
		}
	}while(n<=0);
	int B[n];
	int *puntero;
	puntero=&B[0];
	for(int c=0;c<n;c++){
		cout<<"ingrese un nro: ";cin>>B[c];
		while(!cin.good()){
			cin.clear();
			fflush(stdin);
			cout<<"solo se aceptan nros: ";cin>>B[c];
		}
	}
	for(int c=0;c<n;c++){		
		if(c==n-1){
			cout<<B[c];
		}else{
			cout<<B[c]<<" - ";
		}
	}
	cout<<endl;
	menor(puntero, n);
	
	system("pause");
	system("cls");
}
void menor(int* puntero,int l){
	int menor;
	for(int c=0;c<l;c++){
		if(c==0){
			menor=*(puntero+c);
		}else if(menor>*(puntero+c)){
			menor=*(puntero+c);
		}
	}
	cout<<"El menor elemento es: "<<menor<<endl;
	
}

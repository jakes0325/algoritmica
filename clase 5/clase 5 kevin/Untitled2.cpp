/*2) Rellenar un arreglo con “n” números, posteriormente utilizando
punteros determinar el menor elemento del arreglo.*/

#include <iostream>
#include <windows.h>

using namespace std;

 int elementos ();
 
 void cargar_matriz(int *, int);
 
 void imprimir(int *, int);
 
 void menornum(int *, int);
 
main(){
	int *puntero;
    int numero; 
    numero = elementos();
    puntero= new int [numero];
    cargar_matriz(puntero,numero);
    imprimir(puntero, numero); cout<<endl;
    menornum(puntero, numero);
   }
   
int elementos (){
 	int number;
  
 	cout<<"Ingrese limite del vector: "; 
  	cin>>number;
  	
  	return number;
  
  }
   
void cargar_matriz(int *puntero, int n){
	
  	cout<<"Cargar vector: "<<endl;
  	for(int i=0; i<n; i++){
  		cout<<"Ingrese numero: "; 
		cin>>*puntero++;
	}
  	
  }
  
void imprimir(int *puntero, int n){
	
  	cout<<"El vector cargado es: "<<endl;
  	
  	for(int i=0; i<n; i++){
  		cout<<*puntero++<<", ";
	}
  	
  	
  }
  
void menornum(int *puntero, int n){
	
  	int menor=0;
  	
  	for(int i=0; i<n; i++){
  		if(i==0){
  			menor=*puntero;
		  }else if(*puntero<menor){
		  	menor=*puntero;
		  }
		  *puntero++;
	  }
	  cout<<endl<<menor<<" es el menor elemento del vector"<<endl;
  }
  
  
  
  
  
  

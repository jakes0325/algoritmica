/*
3) Crear un Array dinámico N (unidimensional) utilizando una función para obtener la cantidad de elementos en el
array, teniendo en cuenta que el número de elementos debe estar entre 10 y 50.
 Utilizar las siguientes rutinas para encontrar los siguientes valores.
	mayorElemento( ) Se encargará de hallar el mayor elemento ingresado en el array
	menorElemento() Se encargará de hallar el menor elemento ingresado en el array
	valorPromedio() Encontrará el promedio de valores ingresados en el array
	CantidadPar_Impar( ) Encontrará la cantidad de pares e impres ingresados en el array
	imprimeArray( ) Se encargará de imprimir el array creado	
*/
#include <iostream>
#include <windows.h>

using namespace std;

int elementos ();
 
void cargar_matriz(int *, int);
 
void imprimir(int *, int);
 
void mayorElemento(int *, int);
 
void menorElemento(int *, int);

void valorPromedio(int *, int);

void CantidadPar_Impar(int *, int);

main(){
	int *N;
	int numero;
	
	numero = elementos();
	N = new int [numero];
	cargar_matriz(N,numero);
    imprimir(N, numero);
	menorElemento(N, numero); 
	mayorElemento(N, numero);
	valorPromedio(N, numero);
	CantidadPar_Impar(N, numero);
	delete [] N;
	
	cout<<endl;
	system("pause");
}

int elementos(){
	int n;
  
 	cout<<"Ingrese limite del vector: "; 
  	cin>>n;
  	
  	while((n<10)||(n>50)){
  		cout<<"ERROR:solo nros entre 10 y 50 -> ";
  		cin>>n;
	}
  	
  	return n;
	
}

void cargar_matriz(int *N, int n){
	
	int c=0; 
	
  	cout<<"Cargar vector: "<<endl;
  	for(int i=0; i<n; i++){
  		cout<<"Ingrese numero: "; 
		cin>>*N++;
		c++;
	}
  	cout<<"Fueron ingresados ("<<c<<") elementos en el vector "<<endl;
}

void imprimir(int *N, int n){
	
  	cout<<"El vector cargado es: "<<endl;
  	
  	for(int i=0; i<n; i++){
  		cout<<*N++<<", ";
	}
  	
}

void mayorElemento(int *N, int n){
	
  	int may=0;
  	
  	for(int i=0; i<n; i++){
  		if(i==0){
  			may=*N;
		  }else if(*N>may){
		  	may=*N;
		  }
		  *N++;
	  }
	  cout<<endl<<may<<" es el mayor elemento del vector"<<endl;
}

void menorElemento(int *N, int n){
	
  	int menor=0;
  	
  	for(int i=0; i<n; i++){
  		if(i==0){
  			menor=*N;
		  }else if(*N<menor){
		  	menor=*N;
		  }
		  *N++;
	  }
	  cout<<endl<<menor<<" es el menor elemento del vector"<<endl;
}

void valorPromedio(int *N, int n){
	int s=0, promedio=0;
	
	for(int c=0;c<n;c++){
		s= s+*(N+c);
		*N++;
	}
	promedio = s%n;
	
	cout<<"El valor promedio es: "<<promedio<<endl;
}

void CantidadPar_Impar(int *N, int n){
	
	int cpar=0, cimpar=0;
	
	for(int i=0;i<n;i++){
		if(*(N+i)%2==0){
			cpar++;
		}else{
			cimpar++;
		}
	}
	cout<<"Cantidad de elementos pares: "<<cpar<<endl;
	cout<<"Cantidad de elementos impares: "<<cimpar<<endl;
}




























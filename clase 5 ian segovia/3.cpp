/*
	Crear un Array dinámico N (unidimensional) utilizando una función para obtener la cantidad de elementos en el
	array, teniendo en cuenta que el número de elementos debe estar entre 10 y 50.
 	Utilizar las siguientes rutinas para encontrar los siguientes valores
*/
#include<iostream>
#include<windows.h>
#include<string.h>
using namespace std;
int limite();
void mayorElemento(int *,int);
void menorElemento(int *,int);
void valorPromedio(int *,int);
void CantidadPar_Impar(int *,int);
void imprimeArray(int *,int);
main(){
	int l=limite();
	int N[l];
	int*vector=&N[0];
	int menu=0;
	for(int c=0;c<l;c++){
		cout<<"ingrese nro: ";cin>>N[c];
		while(!cin.good()){
			cin.clear();
			fflush(stdin);
			cout<<"solo se aceptan numeros ";
			cin>>N[c];
		}
	}
	while(menu!=6){
		cout<<"-----------------------------------------------------------------"<<endl;
		cout<<"----------------------MENU---------------------------------------"<<endl;
		cout<<"-----------------------------------------------------------------"<<endl;
		cout<<"1 - mayor elemento"<<endl;
		cout<<"2 - menor elemento"<<endl;
		cout<<"3 - Promedio"<<endl;
		cout<<"4 - cantidad de nros par e impar"<<endl;
		cout<<"5 - imprimir array"<<endl;
		cout<<"6 - salir del menu"<<endl;
		cin>>menu;
		while(!cin.good()){
			cin.clear();
			fflush(stdin);
			cout<<"solo se aceptan numeros ";
			cin>>menu;
		}
		switch(menu){
			case 1:
				mayorElemento(vector,l);
				break;
			case 2:
				menorElemento(vector,l);
				break;
			case 3:
				valorPromedio(vector,l);
				break;
			case 4:
				CantidadPar_Impar(vector,l);
				break;
			case 5:
				imprimeArray(vector,l);
				break;
			case 6:
				cout<<"gracias por utilizar el programa!!!"<<endl;
				break;
				
		}
		
		
		system("pause");
		system("cls");
		
	}
	
	
	
	
	
	system("pause");
	system("cls");
}
int limite(){
	int n;
	do{
		cout<<"ingrese limite:(10 -- 50) ";cin>>n;
		while(!cin.good()){
			cin.clear();
			fflush(stdin);
			cout<<"solo se aceptan numeros ";
			cin>>n;
		}
	}while((n<10)||(n>50));
	
	
	
	return n;
}
void mayorElemento(int *vector,int n){
	int may;
	for(int c=0;c<n;c++){
		if(c==0){
			may=*(vector+c);
		}else if(may<*(vector+c)){
			may=*(vector+c);
		}
	}
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<"EL MAYOR ELEMENTO ES: "<<may<<endl;
	cout<<"-----------------------------------------------------------------"<<endl;
	
}
void menorElemento(int *vector,int n){
	int men;
	for(int c=0;c<n;c++){
		if(c==0){
			men=*(vector+c);
		}else if(men>*(vector+c)){
			men=*(vector+c);
		}
	}
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<"EL MENOR ELEMENTO ES: "<<men<<endl;
	cout<<"-----------------------------------------------------------------"<<endl;
}
void valorPromedio(int *vector,int n){
	float suma=0;
	for(int c=0;c<n;c++){
		suma=suma + *(vector+c);
	}
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<"EL PROMEDIO ES: "<<suma/n<<endl;
	cout<<"-----------------------------------------------------------------"<<endl;
}
void CantidadPar_Impar(int *vector,int n){
	int cp=0,ci=0;
	for(int c=0;c<n;c++){
		if(*(vector+c)%2==0){
			cp++;
		}else{
			ci++;
		}
	}
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<"LA CANTIDAD DE PARES ES: "<<cp<<endl;
	cout<<"-----------------------------------------------------------------"<<endl;
	cout<<"LA CANTIDAD DE IMPARES ES: "<<ci<<endl;
	cout<<"-----------------------------------------------------------------"<<endl;
	
}
void imprimeArray(int *vector,int n){
	for(int c=0;c<n;c++){
		if(c==n-1){
			cout<<*(vector+c);
		}else{
			cout<<*(vector+c)<<" - ";
		}
	}
	cout<<endl;
}

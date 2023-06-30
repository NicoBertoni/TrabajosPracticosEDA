//Ejercicio 1.- Hacer un programa que ingrese dos cadenas y: 
//
//Determine cuál de ellas es mayor en orden alfabético.
//Concatene ambas cadenas.
//Determine cuál es más larga.
//Invierta la primera ingresada. 
// Cadena mayor (Alfabetico)

//El programa deberá mostrar todas las salidas con carteles aclaratorios
//
//1º Cadena: ...........
//2º Cadena: ...........
//La cadena mayor es: ............................. 
//Las cadenas concatenadas quedan así............. 
//La cadena más larga es: ................ 
//La cadena invertida se lee.............


#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	char cadena1[100];
	char cadena2[100];
	bool condicion;
	int i=0;
	cout<<"A continuacion, ingrese la primer cadena\n";
	cin.getline(cadena1, 100);
	cout<<"Ahora ingrese la segunda cadena\n";
	cin.getline(cadena2, 100);
	cout<<"1º Cadena: "<<cadena1<<".\n";
	cout<<"2º Cadena: "<<cadena2<<".\n";
	do{
		if(cadena1[i]==cadena2[i]){
			i++;
			condicion=false;
		}else{
		if (cadena1[i]>cadena2[i]){
			cout<<"La cadena mayor es: "<<cadena1<<".\n";
			condicion=true;
		} else{
			cout<<"La cadena mayor es: "<<cadena2<<".\n";
			condicion=true;
		}
		}
		
	}while(condicion==false);
	
	cout<<"Las cadenas concatenadas quedan asi: ";
	cout<<cadena1;
	cout<<cadena2<<"\n";
	int longitud1= 0;
	int longitud2= 0;
	
	    while(cadena1[longitud1] !='\0') {
        longitud1++;
    }
        while(cadena2[longitud2] !='\0') {
    	longitud2++;
    }
    
	if(longitud1>longitud2) {
    	cout <<"La cadena mas larga es: " <<cadena1<< ".\n";
	} else if(longitud1<longitud2) {
    	cout <<"La cadena mas larga es: " <<cadena2<< ".\n";
	} else {
    	cout <<"Las 2 cadenas tienen la misma longitud.\n";
	}
	int j=longitud1-1;
	char cadenaInv[j];
	for(i=0;i<longitud1;i++){
		cadenaInv[j]=cadena1[i];
		j--;
	}
	cout<<"La cadena invertida se lee: "<<cadenaInv<<".\n";
	char salida;
	cout<<"Ingrese cualquier letra/numero y presione enter para salir ";
	cin>>salida;
	return 0;
}



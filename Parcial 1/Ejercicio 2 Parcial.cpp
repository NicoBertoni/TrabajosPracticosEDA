// Escribir un programa que solicite el ingreso de un texto (máximo 500 palabras). 
// El programa deberá mostrar: el texto ingresado, las palabras del texto que se repiten y cuantas veces se 
// repite cada una, con el siguiente formato: 

//En el texto "aquí va el texto" las palabras que se repiten son: 

// nnnnnnn xx veces 
// nnnnnnn xx veces 
// nnnnnnn xx veces 


#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main() {
    string texto[500];
    int contPalabras = 0;
    int repeticion[500] = { 0 }; 
    string palabra;
    int longitudFinal;
	cout << "Ahora ingrese el texto con un max 500 palabras. Para finalizar el ingreso, escriba 'finalizamiento':\n";
    while (cin >>palabra && contPalabras < 500) {
        if (palabra == "finalizamiento") { 
            break;
        }
        texto[contPalabras] = palabra;
		longitudFinal++; 
        bool encontrada = false;
        for (int i = 0; i < contPalabras; i++) {
            if (texto[i] == palabra) {
                repeticion[i]++;
                encontrada = true;
                break;
            }
        }
        if (!encontrada) { 
            repeticion[contPalabras] = 1;
            contPalabras++; 
        }
    }
  	 cout << "En el texto ingresado '";
	for (int i=0;i<longitudFinal;i++){
	cout<<texto[i]<<" ";
	}
	cout<<" 'las palabras que se repiten son: \n";
    for (int i = 0; i < contPalabras; i++) {
        if (repeticion[i] > 1) {
            cout << texto[i] <<" "<< repeticion[i]<<" veces\n";
        }
    }
    cout<<"Ingrese cualquier caracter y presione enter para salir ";
    char terminar;
    cin>>terminar;
    return 0;
}


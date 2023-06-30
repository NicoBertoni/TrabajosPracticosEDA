//Ejercicio 1.- Escribir una función que use la estructura pila de caracteres (capacidad 100 chars) para
//comprobar si una determinada palabra o frase es un palíndromo.
//Un palíndromo es una palabra o expresión que es igual si se lee de izquierda a derecha que de derecha a
//izquierda.
//Deben considerarse palíndromos las cadenas que involucren espacios como así también considerar válida la
//letra independientemente si esta en mayúscula o minúscula.
//Ejemplos de palíndromos sería: 
//“Anita lava la tina”
//“anilina”
//No consideramos palíndromos si la cadena tiene signos de puntuación o acentos. Por ej. “Isaac no ronca así”
//o “Yo dono rosas, oro no doy”
//-La cadena debe ser ingresada por el usuario.
//- La comprobación del palíndromo debe hacerse por medio de una función que tome como parámetro
//la cadena a comprobar.
//- El programa principal debe solicitar la cadena y luego indicar si es palíndromo o no. 

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;
const int limite = 100;

struct Pila {
    char letras[limite];
    int cantidad = 0;
    int p = 0;
    int u = 0;

    bool esVacia() {
        return cantidad == 0;
    }

    bool esLlena() {
        return cantidad == limite;
    }

    void push(char elemento) {
        if (!esLlena()) {
            letras[u] = elemento;
            u++;
            cantidad++;
        }
    }

    void pop() {
        if (!esVacia()) {
            u--;
            cantidad--;
        }
    }

    char verTope() {
        return letras[u - 1];
    }
};

bool esPalindromo(const string& palabra) {
    Pila pila;
    int longitud = palabra.length();

    for (int i = 0; i < longitud; i++) {
        char caracter = tolower(palabra[i]);
        if (isalpha(caracter)) {
            pila.push(caracter);
        }
    }

    for (int i = 0; i < longitud; i++) {
        char caracter = tolower(palabra[i]);
        if (isalpha(caracter)) {
            if (caracter != pila.verTope()) {
                return false;
            }
            pila.pop();
        }
    }

    return true;
}

int main() {
    string palabra;
    cout << "Ingrese una palabra o frase para verificar si es un palíndromo: ";
    getline(cin, palabra);
    if (esPalindromo(palabra)) {
        cout << "La palabra o frase es un palíndromo.\n";
    } else {
        cout << "La palabra o frase no es un palíndromo.\n";
    }
    system("pause");
    return 0;
}


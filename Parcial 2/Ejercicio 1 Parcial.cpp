//Ejercicio 1.- Escribir una funci�n que use la estructura pila de caracteres (capacidad 100 chars) para
//comprobar si una determinada palabra o frase es un pal�ndromo.
//Un pal�ndromo es una palabra o expresi�n que es igual si se lee de izquierda a derecha que de derecha a
//izquierda.
//Deben considerarse pal�ndromos las cadenas que involucren espacios como as� tambi�n considerar v�lida la
//letra independientemente si esta en may�scula o min�scula.
//Ejemplos de pal�ndromos ser�a: 
//�Anita lava la tina�
//�anilina�
//No consideramos pal�ndromos si la cadena tiene signos de puntuaci�n o acentos. Por ej. �Isaac no ronca as�
//o �Yo dono rosas, oro no doy�
//-La cadena debe ser ingresada por el usuario.
//- La comprobaci�n del pal�ndromo debe hacerse por medio de una funci�n que tome como par�metro
//la cadena a comprobar.
//- El programa principal debe solicitar la cadena y luego indicar si es pal�ndromo o no. 

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
    cout << "Ingrese una palabra o frase para verificar si es un pal�ndromo: ";
    getline(cin, palabra);
    if (esPalindromo(palabra)) {
        cout << "La palabra o frase es un pal�ndromo.\n";
    } else {
        cout << "La palabra o frase no es un pal�ndromo.\n";
    }
    system("pause");
    return 0;
}


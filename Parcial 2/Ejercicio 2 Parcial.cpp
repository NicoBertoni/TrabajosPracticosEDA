//Ejercicio 2. Escribir un programa que use la estructura cola de enteros (Máx 20). El programa debe
//implementar una función que tome una cola de enteros y retorne en la misma cola los elementos ordenados
//bajo la siguiente condición:
//Primero debe tener los números que terminan en 0, luego los números que terminan en 1, luego los números
//que terminan en 2 y así hasta que en las últimas posiciones estén los números que terminan en 9. 
//- Los números deben ser generados aleatoriamente del 0 al 100.
//- El programa principal debe mostrar los números generados y la salida de la función. 

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int MAX = 20;

struct Cola {
    private:
        int datos[MAX];
        int cantidad = 0;
        int p = 0;
        int u = 0;

    public:
        bool esVacia() {
            return cantidad == 0;
        }

        bool esLlena() {
            return cantidad == MAX;
        }

        void encolar(int elemento) {
            if (!esLlena()) {
                datos[u] = elemento;
                u = (u + 1) % MAX;
                cantidad++;
            }
        }

        void desencolar() {
            if (cantidad != 0) {
                p = (p + 1) % MAX;
                cantidad--;
            }
        }

        int verPrimero() {
            return datos[p];
        }

        int verUltimo() {
            int ultimo = (u - 1 + MAX) % MAX;
            return datos[ultimo];
        }
};

void ordenarCola(Cola& cola) {
    Cola colasDigitos[10];
    while (!cola.esVacia()) {
        int num = cola.verPrimero();
        cola.desencolar();
        int ultimoDigito = num % 10;
        colasDigitos[ultimoDigito].encolar(num);
    }
    for (int i = 0; i <= 9; i++) {
        while (!colasDigitos[i].esVacia()) {
            int num = colasDigitos[i].verPrimero();
            colasDigitos[i].desencolar();
            cola.encolar(num);
        }
    }
}

int main() {
    Cola cola;
    int n, num;
    bool validar = true;
    cout << "Ingrese la cantidad de numeros a generar (maximo 20 numeros): ";
    do {
        cin >> n;
        if (n < 1 || n > 20) {
            cout << "La cantidad ingresada es menor a 1 o mayor a 20, ingrese de nuevo: ";
            validar = false;
        }
    } while (!validar);
    srand(time(0));
	cout << "Los numeros generados en la cola son: \n";
    for (int i = 0; i < n; i++) {
        num = rand() % 101;
        cout << num << " ";
        cola.encolar(num);
    }
    cout << "\nLos numeros ordenados en la cola segun el criterio quedan asi: \n";
    ordenarCola(cola);
    while (!cola.esVacia()) {
        cout << cola.verPrimero() << " ";
        cola.desencolar();
    }
    cout << endl;
    system("pause");
	return 0;
}












#include <iostream>
using namespace std;

bool esPrimo(int n) {
    bool control = true;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            control = false;
            break;
        }
    }
    return control;
}

void primosAnteriores(int n) {
    cout << "Los siguientes numeros son los primos anteriores a " << n << ":\n";
    for (int i = n - 1; i >= 1; i--) {
        if (esPrimo(i)) {
            cout << i << "\n";
        }
    }
}

int main() {
    int n, op;
    cout << "Seleccione la operacion que desea realizar:\n";
    cout << "1) Verificar si un numero es primo.\n";
    cout << "2) Listar los numeros primos anteriores a un numero.\n";
    cin >> op;
    switch (op) {
        case 1:
            cout << "Ingrese un numero: ";
            cin >> n;
            if (esPrimo(n)) {
                cout << "El numero es primo.\n";
            } else {
                cout << "El numero no es primo.\n";
            }
            break;
        case 2:
            cout << "Ingrese un numero: ";
            cin >> n;
            primosAnteriores(n);
            break;
        default:
            cout << "Opcion invalida.\n";
            break;
    }
    return 0;
}


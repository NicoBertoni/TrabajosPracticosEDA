//Defina una estructura que sirva para representar a una persona. La estructura debe contener 
//dos campos: el nombre de la persona y un valor de tipo lógico que indica si la persona tiene 
//algún tipo de discapacidad. Realice un programa que dado un vector de personas rellene dos 
//nuevos vectores: uno que contenga las personas que no tienen ninguna discapacidad y otro que 
//contenga las personas con discapacidad.

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

struct persona {
	string nombre;
	bool discapacidad;
};

int main () {
    persona registro[5];
    bool validar;
    char op;
    int contK=0;
    int contL=0;
    int k = 0;
    int l = 0;

    // Carga del registro de personas
    for(int i=0; i<5; i++){
        cout<<"Registro de personas ("<<i+1<<"/5)\n";
        cout<<"Ingrese el nombre de la persona\n";
        cin>>registro[i].nombre;
        cout<<"¿Es la persona discapacitada?  S/N\n";
        do{
            cin>>op;
            switch(op){
                case 'S':
                case 's':
                    registro[i].discapacidad=true;
                    contK++;
                    validar=true;
                    break;
                case 'N':
                case 'n':
                    registro[i].discapacidad=false;
                    contL++;
                    validar=true;
                    break;
                default:
                    validar=false;
                    cout<<"Opcion no valida, ingrese una nueva\n";
                    break;
            }
        } while (!validar);
    }

    // Separacion por discapacidad
    persona discapacitados[contK];
    persona noDiscapacitados[contL];
    for (int j=0;j<5;j++){
        if(registro[j].discapacidad){
            discapacitados[k] = registro[j];
            k++;
        }else{
            noDiscapacitados[l] = registro[j];
            l++;
        }
    }
    cout<<"Separacion de discapacitados completada\n";
    
    //Muestra por pantalla del registro
    cout<<"Personas registradas\n";
    for(int i=0;i<5;i++){
    	cout<<registro[i].nombre<<"\n";
	}
	
	
	cout<<"Personas con discapacidad\n";
	if(k==0){
		cout<<"---No se ha registrado ninguna persona---\n";
	}else{
		for(int i=0;i<contK;i++){
    		cout<<discapacitados[i].nombre<<"\n";
		}
	}
	
	
	cout<<"Personas sin discapacidad\n";
	if(l==0){
		cout<<"---No se ha registrado ninguna persona---\n";
	}else{
		for(int i=0;i<contL;i++){
    		cout<<noDiscapacitados[i].nombre<<"\n";
		}
	}
	
	system("pause");
	return 0;
}



//Haga un programa en donde se ingresará una cantidad X de segundos, para luego
//convertir a horas, minutos y segundos. 
#include <iostream>
using namespace std;

int main (){
	int segundos, minutos, horas;
	cout <<"Ingrese la cantidad de segundos a convertir\n>";
	cin>>segundos;
	minutos=segundos/60;
	horas=minutos/60;
	cout <<segundos<<" segundos equivalen a "<<horas<<" hora/s, "<<(minutos % 60)<<" minuto/s, y "<<(segundos%60)<<" segundo/s.\n";
	return 0;
}

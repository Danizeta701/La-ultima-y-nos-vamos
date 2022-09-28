#include <iostream>
#include<string>
#include<sstream>

using namespace std;

class Fecha {//Name's class
private:
	int dia;
	int mes;
	int anio;
	string fechaInstring;
public:
	Fecha(int _dia, int _mes, int _anio)
		: mes(_mes), dia(_dia), anio(_anio) {};

	void leer();
	void biciesto();
	int mesesMix();
	Fecha& operator++();
};

Fecha& Fecha::operator++() {
		

		++dia;
		if ( mes== 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) {
			if (dia > 31) {
				dia = 1;
				mes++;
				if (anio > 12) {
					mes = 1;
					anio++;
				}
			}
		}
		else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
			if (dia > 30) {
				dia = 1;
				mes++;
				if (mes > 12) {
					mes = 1;
					anio++;
				}
			}
		}
		else if (mes == 2) {
			if (anio % 4 == 0 && anio % 100 != 0 || anio % 400 == 0) {
				if (dia > 29) {
					dia = 1;
					mes++;
					if (mes > 12) {
						mes = 1;
						anio++;
					}
				}
			}
			else if (dia > 28) {
				dia = 1;
				mes++;
				if (mes > 12) {
					mes = 1;
					anio++;
				}
			}
		}
	
	cout << endl; 
	cout << "Fecha: " << dia<< "/" << mes << "/" << anio << endl;
	return *this;
	
}



void Fecha::leer() {
	cout << "Digite la fecha" << endl << endl;
	cout << "Digite el dia: ";
	cin >> dia;
	cout << "Digite el mes: ";
	cin >> mes;
	cout << "Digite el anio: ";
	cin >> anio;
	if ((dia >= 1 && dia <= mesesMix()) && (mes >= 1 && mes <= 12) && (anio >= 1));
	else {
		cout << "Fecha ingresada incorrectamente " << dia << "/" << mes << "/" << anio << endl;
	}
}


void Fecha::biciesto() {

	if (anio % 4 == 0 && anio % 100 != 0 || anio % 400 == 0)
		cout << "\nEste anio es biciesto" << endl;

}
int Fecha::mesesMix() {
	int limit = 31;//Meses que tenga 31 días

	switch (mes) {
	case 2:
		if (anio % 4 == 0) limit = 29;//Es bisiesto
		else limit = 28;//No es bisiesto
		break;
		//Meses que tengan máximo 30 días
	case 4:
	case 6:
	case 9:
	case 11:
		limit = 30;
		break;
	}

	return limit;
}


int main() {
	int dia = 0, mes = 0, anio = 0;
	Fecha press(dia, mes, anio);
	
	press.leer();
	press.biciesto();
	press.mesesMix();
	press.operator++();

	return 0;
}
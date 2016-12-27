#ifndef _TPORO_H_
#define _TPORO_H_

#include <iostream>
using namespace std;

class TPoro{

	//Sobrecarga del operador SALIDA
	friend ostream & operator<<(ostream &os, const TPoro &p);

private:
	//Coordenada x de la posicion
	int x;
	//Coordenada y de la posicion
	int y;
	//Volumen
	double volumen;
	//Color
	char* color;

public:
	//Contructor por defecto
	TPoro();
	//Constructor a partir de una posicion y un volumen
	TPoro(int x, int y, double volumen);
	//Constructor a partir de una posicion, un volumen y un color
	TPoro(int x, int y, double volumen, char* color);
	//Constructor copia
	TPoro(const TPoro &p);
	//Destructor
	~TPoro();
	//Sobrecarga del operador asignacion
	TPoro & operator=(const TPoro &p);
	//Sobrecarga del operador igualdad
	bool operator==(const TPoro &p);
	//Sobrecarga del operador desigualdad
	bool operator!=(const TPoro &p);
	//Modifica al posicion
	void Posicion(const int x, const int y){ this->x=x; this->y=y;};
	//Modifica el volumen
	void Volumen(const double volumen){ this->volumen=volumen;};
	//Modifica el color
	void Color(const char *color);
	//Devuelve la coordenada x de la posicion
	int PosicionX()const{ return x;};
	//Devuelve la coordenada y de la posicion
	int PosicionY()const{ return y;};
	//Devuelve el volumen
	double Volumen()const { return volumen;};
	//Devuelve el color
	char * Color() const{ return color;};
	//Devuelve cierto si el poro esta vacio
	bool EsVacio()const;
};

#endif

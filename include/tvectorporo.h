#ifndef _TVECTORPORO_H_
#define _TVECTORPORO_H_

#include <iostream>
#include "tporo.h"
using namespace std;

class TVectorPoro{

	//Sobrecarga del operador salida
	friend ostream & operator<<(ostream &os, TVectorPoro &tv);

private:
	//Dimension del vecto
	int dimension;
	//Datos del vector
	TPoro *datos;
	//Para cuando haya error en el operator[]
	TPoro error;

public:
	//Constructor por defecto
	TVectorPoro();
	//Constructor a partir de una dimnension
	TVectorPoro(int dimension);
	//Constructor de copia
	TVectorPoro(const TVectorPoro &vp);
	//Destructor
	~TVectorPoro();
	//Sobrecarga del operador asignacion
	TVectorPoro & operator=(const TVectorPoro &vp);
	//Sobrecarga del operador igualdad
	bool operator==(const TVectorPoro &vp);
	//Sobrecarga del operador desigualdad
	bool operator!=(const TVectorPoro &vp);
	//Sobrecarga del operador corchete ESCRITURA (parte IZQUIERDA)
	TPoro & operator[](const int k);
	//Sobrecarga del operador corchete LECTURA (parte DERECHA)
	TPoro operator[](const int k)const;
	//Devuelve la longitud (dimension) del vector
	int Longitud()const{ return dimension;};
	//Devuelve la cantidad de posiciones ocupadas (no vacias) en el vector
	int Cantidad()const;
	//REDIMENSIONAR el vector de TPoro
	bool Redimensionar (const int tam);

};

#endif

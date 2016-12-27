#ifndef _TLISTAPORO_H_
#define _TLISTAPORO_H_

#include <iostream>
#include "tporo.h"
using namespace std;


/*
**************************************************
**************************************************
					TListaNodo
**************************************************
*/

class TListaNodo{
	
	friend class TListaPosicion;
	friend class TListaPoro;

private:
	//El elemento del nodo
	TPoro e;
	//El nodo anterior
	TListaNodo *anterior;
	//El nodo siguiente
	TListaNodo *siguiente;

public:
	//Constructor por defecto
	TListaNodo();
	//Constructor de copia
	TListaNodo (TListaNodo &ln);
	//Destructor
	~TListaNodo();

};

/*
**************************************************
**************************************************
					TListaPosicion
**************************************************
*/
class TListaPosicion{

	friend class TListaPoro;

private:
	//Para implementar la POSICION  a NODO de la LISTA de TPoro
	TListaNodo *pos;

public:
	//Constructor por defecto
	TListaPosicion();
	//Constructor de copia
	TListaPosicion (const TListaPosicion &lp);
	//Destructor
	~TListaPosicion();


};

/*
**************************************************
**************************************************
					TListaPoro
**************************************************
*/

class TListaPoro{

	//Sobrecarga del operador salida
	friend ostream & operator<<(ostream &os, const TListaPoro &lp);

private:
	//Primer elemento de la lista
	TListaNodo *primero;
	//Ultimo elemento de la lista
	TListaNodo *ultimo;


public:
	//Constructor por defecto
	TListaPoro();
	//Constructor de copia
	TListaPoro (const TListaPoro &lp);
	//Destructor
	~TListaPoro();



};

#endif

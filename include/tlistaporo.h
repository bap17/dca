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
	//Sobrecarga del operador asignacion
	TListaNodo & operator=(const TListaNodo &ln);

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
	//Sobrecarga del operador asignacion
	TListaPosicion& operator=(const TListaPosicion &lp);
	//Sobrecarga del operador igualdad
	bool operator==(const TListaPosicion &lp);
	bool operator!=(const TListaPosicion &lp);
	//Devuelve la posicion anterior
	TListaPosicion Anterior();
	//Devuelve la posicion siguiente
	TListaPosicion Siguiente();
	//Devuelve TRUE si la posicion no apunta a un lista, FALSE en caso contrario
	bool EsVacia();



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
	//Sobrecarga del operador asignacion
	TListaPoro & operator=(const TListaPoro &lp);
	//Sobrecarga del operador igualdad
	bool operator==(const TListaPoro &lp);
	//Sobrecarga del operador suma
	TListaPoro operator+(const TListaPoro &lp);
	//Sobrecarga operador resta
	TListaPoro operator-(const TListaPoro &lp);
	//Devuelve true si la lista está vacía, false en caso contrario
	bool EsVacia()const;
	//Inserta el elemento en el lista
	bool Insertar(const TPoro &p);
	//Busca y borra el elemento
	bool Borrar(const TPoro &p);
	//Borra el elemento que ocupa la posicion indicada
	bool Borrar(const TListaPosicion &lp);
	//Obtiene el elemento que ocupa la posicion indicada
	TPoro Obtener(const TListaPosicion &lp)const;
	//Devuelve true si el elemento esta en la lista, false en caso contrario
	bool Buscar(const TPoro &p)const;
	//Devuelve la longitud de la lista
	int Longitud()const;
	//Devuelve la primera posicion en la lista
	TListaPosicion Primera()const;
	//Devuelve la ultima posicion en la lista
	TListaPosicion Ultima()const;
	//Extraer un rango de nodos de la lista
	TListaPoro ExtraerRango(const int n1, const int n2);	




};

#endif

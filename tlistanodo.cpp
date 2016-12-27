#include <iostream>
#include "tlistanodo.h"



//Constructor por defecto
TListaNodo::TListaNodo():e() { //Con ':e' llamamos al constructor del objeto

	anterior=siguiente=NULL;
}

//Constructor de copia
TListaNodo::TListaNodo(TListaNodo &ln):e(ln.e){

	anterior=siguiente=NULL;
}

//Destructor 
TListaNodo::~TListaNodo(){
	e.~TPoro();
	anterior=siguiente=NULL;
}



//Sobrecarga del operador asignacion
TListaNodo & TListaNodo::operator=(const TListaNodo &ln){
	if(this!=&ln){
		(*this).~TListaNodo();
		e=ln.e;

	}
	return *this;
}
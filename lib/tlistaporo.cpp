
#include "tlistaporo.h"

/*
**************************************************
**************************************************
					TListaNodo
**************************************************
*/

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




/*
**************************************************
**************************************************
					TListaPosicion
**************************************************
*/

//Constructor por defecto
TListaPosicion::TListaPosicion(){

	pos=NULL;
}

//TLista de copia
TListaPosicion::TListaPosicion(const TListaPosicion &lp){

	pos=lp.pos;
}

//Destructor
TListaPosicion::~TListaPosicion(){
	pos=NULL;
}



//Devuelve la posicion anterior
TListaPosicion TListaPosicion::Anterior(){

	TListaPosicion p;
	if(this->pos==NULL){

	}else{
		p.pos=pos->anterior;
	}
	return p;	
}

//Devuelve la posicion siguiente
TListaPosicion TListaPosicion::Siguiente(){
	
	TListaPosicion p;
	if(this->pos==NULL){
		
	}else{
		p.pos=pos->siguiente;
	}
	return p;
}

//Devuelve TRUE si la posicion no apunta a una lista, FALSE en caso contrario
bool TListaPosicion::EsVacia(){
	bool vacia=true;
	if(pos!=NULL){
		vacia=false;
	}
	return vacia;
}




/*
**************************************************
**************************************************
					TListaPoro
**************************************************
*/

//Constructor por defecto
TListaPoro::TListaPoro(){
	primero=NULL;
	ultimo=NULL;
}

//Constructor de copia
TListaPoro::TListaPoro(const TListaPoro &lp){
	
	if(!lp.EsVacia()){
		TListaPosicion lista, pos1, pos2;
		lista = lp.Primera();
		primero = new TListaNodo(*lista.pos);
		pos2 = this->Primera();
		lista = lista.Siguiente();
		while(!lista.EsVacia()){
			pos1 = pos2;
			pos2 = pos2.Siguiente();
			pos2.pos = new TListaNodo(*lista.pos);
			pos2.pos->anterior = pos1.pos;
			pos1.pos->siguiente = pos2.pos;
			lista = lista.Siguiente();
		}
		ultimo = pos2.pos;

	}
}

//Destructor
TListaPoro::~TListaPoro(){
	TListaPosicion pos1, pos2;
	pos2 = Primera();
	while(!pos2.EsVacia()){
		pos1 = pos2;
		pos2 = pos2.Siguiente();
		delete pos1.pos;
	}
	primero = NULL;
	ultimo = NULL;
}

//Devuelve true si la lista esta vacia, false en caso contrario
bool TListaPoro::EsVacia()const{
	bool vacia=false;
	if(primero==NULL && ultimo==NULL){
		vacia=true;
	}
	return vacia;
}



//Devuelve la primera posicion en la lista
TListaPosicion TListaPoro::Primera()const{
	TListaPosicion pos;
	if(!this->EsVacia()){
		pos.pos=primero;
	}
	return pos;
}



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



//Sobrecarga del operador asignacion
TListaNodo & TListaNodo::operator=(const TListaNodo &ln){
	if(this!=&ln){
		(*this).~TListaNodo();
		e=ln.e;

	}
	return *this;
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

//Sobrecarga del operador asignacion
TListaPosicion & TListaPosicion::operator=(const TListaPosicion &lp){
	if(this!=&lp){
		if(lp.pos!=NULL){
			(*this).~TListaPosicion();
		}
		pos=lp.pos;
		
	}
	return *this;
}

//Sobrecarga del operador igualdad
bool TListaPosicion::operator==(const TListaPosicion &lp){
	bool iguales=false;
	if(pos==lp.pos){
		iguales=true;
	}
	return iguales;
}
bool TListaPosicion::operator!=(const TListaPosicion &lp){
	return !(*this==lp);
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

//Sobrecarga del operador asignacion
TListaPoro & TListaPoro::operator=(const TListaPoro & lp){
	if(this!=&lp){
		(*this).~TListaPoro();
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
	return *this;
}

//Sobrecarga del operador igualdad
bool TListaPoro::operator==(const TListaPoro & lp){
	bool iguales= true;
	if(this->Longitud()!=lp.Longitud()){
		iguales=false;
	}
	TListaPosicion pos1, posi1;
	pos1=Primera();
	posi1= lp.Primera();

	while(!pos1.EsVacia()  && iguales){
		if(pos1.pos==posi1.pos){
			pos1 = pos1.Siguiente();
			posi1 = posi1.Siguiente();
		}else{
			iguales=false;
		}

	}
	return iguales;
}

//Sobrecarga del operador suma
TListaPoro TListaPoro::operator+(const TListaPoro & lp){
	 
	TListaPoro lista; 
	TListaPosicion pos1;
	lista=*this;
	pos1=lp.Primera();
	while(!pos1.EsVacia()){
		lista.Insertar(pos1.pos->e);
		pos1=pos1.Siguiente();
	}
	return lista;

}

//Sobrecarga operador resta
TListaPoro TListaPoro::operator-(const TListaPoro &lp){

	TListaPoro lista;
	TListaPosicion pos1, pos2;
	pos1=Primera();//Lista de la izquierda
	while(!pos1.EsVacia()){
		if(!lp.Buscar(pos1.pos->e)){//Busco si el elemento esta en la lista lp
			lista.Insertar(pos1.pos->e);
		}
		pos1=pos1.Siguiente();
	}
	return lista;
	
}

//Devuelve true si la lista esta vacia, false en caso contrario
bool TListaPoro::EsVacia()const{
	bool vacia=false;
	if(primero==NULL && ultimo==NULL){
		vacia=true;
	}
	return vacia;
}


//Insertar el elemento en la lista
bool TListaPoro::Insertar(const TPoro &p){
	bool insert=false;
	TListaPosicion pos1, pos2, posNueva;
	TListaNodo *nodoNuevo;
	if(this->EsVacia()){ //Si esta vacia la lista
		nodoNuevo = new TListaNodo();
		nodoNuevo->e=p;
		primero=nodoNuevo;
		ultimo=nodoNuevo;
		insert=true;
	}
	if(Buscar(p)){
			insert=false;
	}else{
		if(primero->e.Volumen()>p.Volumen()){//Quiero insertarlo antes
			nodoNuevo = new TListaNodo();
			nodoNuevo->e=p;
			nodoNuevo->siguiente=primero;
			primero->anterior=nodoNuevo;
			primero=nodoNuevo;
			insert=true;
		}else if(ultimo->e.Volumen()<=p.Volumen()){//Quiero insertarlo en la ultima posicion
			nodoNuevo= new TListaNodo();
			nodoNuevo->e=p;
			nodoNuevo->siguiente=NULL;
			nodoNuevo->anterior=ultimo;
			ultimo->siguiente=nodoNuevo;   
			ultimo=nodoNuevo;
			insert=true;
		}
		pos1=Primera();//El puentero de la primera posicion
		while(!pos1.EsVacia() && !insert){
			pos2=pos1.Siguiente();
			if(Obtener(pos1).Volumen()<=p.Volumen() && Obtener(pos1).Volumen()>p.Volumen()){//Quiero meterno en el medio
					nodoNuevo = new TListaNodo();
					nodoNuevo->e=p;
					nodoNuevo->anterior=pos1.pos;
					nodoNuevo->siguiente=pos2.pos;
					pos1.pos->siguiente=nodoNuevo;
					pos2.pos->anterior=nodoNuevo;
					insert=true;
			}//Si hay varios iguales, se volvera a meter en el while
		}
	}
	return insert;
}
	

//Buscar y borrar el elemento
bool TListaPoro::Borrar(const TPoro  &p){     
	bool borrar=false;
	if(!this->EsVacia()){
		if(Buscar(p)){
			TListaPosicion pos1, pos2;
			TListaNodo *aux;
			if(primero->e==p){
				aux=primero;
				//primero->siguiente->anterior=NULL;
				//delete primero;
				primero=aux->siguiente;
				//delete aux;
				borrar=true;
			}else if(ultimo->e==p){
				aux=ultimo;
				ultimo->anterior->siguiente=NULL;
				//delete ultimo;
				ultimo=aux->anterior;
				//delete aux;
				borrar=true;
			}
			pos1=Primera();
			while(!pos1.EsVacia() && !borrar){
				if(pos1.pos->e==p){
					pos1.pos->anterior->siguiente=pos1.pos->siguiente; 
					pos1.pos->siguiente->anterior=pos1.pos->anterior; 
					//delete pos1.pos;
					borrar=true;
				}
				pos1=pos1.Siguiente();
			}
		}
	}
	return borrar;
}

//Borra el elemento que ocupa la posicion indicada
bool TListaPoro::Borrar(const TListaPosicion &lp){
	TPoro p;
	bool borrar=false;
	if(!this->EsVacia()){//Si la lista no es vacia
		p=this->Obtener(lp);
		if(!p.EsVacio()){
			borrar=Borrar(p);
		}
			
	}
	return borrar;
}

//Obtiene el elemento que ocupa la posicion indicada
TPoro TListaPoro::Obtener(const TListaPosicion &pos)const{
	TPoro p;
	TListaPosicion pos1;
	if(this->EsVacia()){
		//Poro vaciio
	}else{
		pos1=Primera();
		while(!pos1.EsVacia()){
			if(pos1==pos){
				p=pos1.pos->e;
			}
			pos1=pos1.Siguiente();
		}
	}
	return p;

}

//Devuelve true si el elemento esta en la lista, FALSE en caso contrario
bool TListaPoro::Buscar(const TPoro &p)const{
	bool encontrada=false;
	if(this->EsVacia()){
		encontrada=false;
	}else{
		TListaPosicion pos1;
		pos1=Primera();
		while(!pos1.EsVacia() && !encontrada){
			if(pos1.pos->e==p){
				encontrada=true;
			}
			pos1=pos1.Siguiente();
		}
	}
	return encontrada;
}

//Devuelve la longitud de la lista
int TListaPoro::Longitud()const{
	TListaPosicion pos1;
	int i=0;
	pos1=Primera();
	while(!pos1.EsVacia()){
		pos1=pos1.Siguiente();
		i++;
	}
	return i;
}

//Devuelve la primera posicion en la lista
TListaPosicion TListaPoro::Primera()const{
	TListaPosicion pos;
	if(!this->EsVacia()){
		pos.pos=primero;
	}
	return pos;
}

//Devuelve la ultima posicion en la lista
TListaPosicion TListaPoro::Ultima()const{
	TListaPosicion pos;
	if(!this->EsVacia()){
		pos.pos=ultimo;
	}
	return pos;
}

//Extraer un rango de nodos de la lista
TListaPoro TListaPoro::ExtraerRango(const int n1, const int n2){
	TListaPoro lista; //Lista que devolveremos
	if(!(*this).EsVacia()){
		TListaPosicion pos;
		if(n2>(*this).Longitud() && n1<Longitud()){
			int i=1;
			pos=Primera();
			while(!pos.EsVacia()){
				if(i==n1 && i<=(*this).Longitud()){
					lista.Insertar(pos.pos->e); //Insertamos en la nueva lista
					(*this).Borrar(pos.pos->e); //Borramos de la lista principal
				}
				i++;
				pos=pos.Siguiente();
			}
		}
		if(n1<=0 && n2<=Longitud()){
			int j=1;
			pos=Primera();
			while(!pos.EsVacia()){
				if(j<=n2){
					lista.Insertar(pos.pos->e);
					(*this).Borrar(pos.pos->e);
				}
				j++;
				pos=pos.Siguiente();
			}

		}
		if(n1==n2 && n1<Longitud()){
			int k=1;
			pos=Primera();
			while(!pos.EsVacia()){
				if(k==n1){
					lista.Insertar(pos.pos->e);
					(*this).Borrar(pos.pos->e);
				}
				k++;
				pos=pos.Siguiente();
			}
		}
		if(n1<n2 && n1<Longitud() && n2<=Longitud()){
			int m=1;
			pos=Primera();
			while(!pos.EsVacia()){
				if(m>=n1 && m<=n2){
					lista.Insertar(pos.pos->e);
					(*this).Borrar(pos.pos->e);
				}
				m++;
				pos=pos.Siguiente();
			}
		}
	}
	return lista;

}

//Sobrecarga del operador salida
ostream & operator<<(ostream &os, const TListaPoro &lp){
	if(lp.EsVacia()){
		os<<"()";
	}else{
		TListaPosicion pos1;
		pos1=lp.Primera();
		os<<"(";		
		while(!pos1.EsVacia()){
			os<<lp.Obtener(pos1);
			if(pos1!=lp.Ultima()){
				os<<" ";
			}
			
			
			pos1=pos1.Siguiente();

		}
		os<<")";
	}
	return os;

}

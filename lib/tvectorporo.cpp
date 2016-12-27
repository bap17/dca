#include <iostream>
#include "tvectorporo.h"

using namespace std;


//Constructor por defecto
TVectorPoro::TVectorPoro(){
	//Dimension del vector
	this->dimension=0;
	this->datos=NULL;
	//Para cuando haya un error en el operador
	//this->error.TPoro()
}


//Constructor a partir de una dimnension
TVectorPoro::TVectorPoro(int dimension){
	if(dimension>0){
		this->dimension = dimension;
		this->datos = new TPoro[this->dimension];
	}else{
		this->dimension = 0;
		this->datos = NULL;
	}
	
	
}

//Constructor de copia
TVectorPoro::TVectorPoro(const TVectorPoro &vp){
	
	if(this!=&vp){
		this->dimension=vp.dimension;
		this->datos = new TPoro[vp.dimension];
		for(int i=0; i<=vp.dimension; i++){
			this->datos[i]=vp.datos[i];
		}
	}

}

//Destructor
TVectorPoro::~TVectorPoro(){
	if(datos!=NULL){
		this->dimension=0;
		delete [] this->datos;
		this->datos=NULL;
	}
}
	
//Sobrecarga del operador asignacion
TVectorPoro & TVectorPoro::operator=(const TVectorPoro &vp){
	
	if(this!=&vp){
		(*this).~TVectorPoro();
		this->dimension=vp.dimension;
		this->datos=new TPoro[vp.dimension];
		for(int i=0; i<vp.dimension; i++){
			this->datos[i]=vp.datos[i];
		}
	}
	return *this;
}

//Sobrecarga del operador igualdad
bool TVectorPoro::operator==(const TVectorPoro &vp){
	bool iguales=true;
	if(this->dimension==vp.dimension){
		for(int i=0; i<dimension;i++){
			if(this->datos[i]!=vp.datos[i]){
				iguales=false;
			}
		}
	}else{
		iguales=false;
	}
	return iguales;
}

//Sobrecarga del operador desigualdad
bool TVectorPoro::operator!=(const TVectorPoro &vp){
	return !(*this==vp);
}

//Sobrecarga del operador corchete (parte IZQUIERDA)
TPoro & TVectorPoro::operator[](const int k){
	if(k<=this->dimension && k>0){
		//datos empieza en 0
		return this->datos[k-1];
	}

	return this->error;
}

//Sobrecarga del operador corchete LECTURA (parte DERECHA)
TPoro TVectorPoro::operator[](const int k)const{
	if(k<=this->dimension && k>0){
		return this->datos[k-1];
	}

	return this->error;
}

//Devuelve la cantidad de posiciones ocupadas (no vacias) en el vector
int TVectorPoro::Cantidad()const{
	int ocupadas=0;
	for(int i=0; i<this->dimension; i++){
		if(!this->datos[i].EsVacio()){
			ocupadas++;
		}
	}
	return ocupadas;
}
//REDIMENSIONAR el vector de TPoro
bool TVectorPoro::Redimensionar (const int tam){

	bool redimen=false;
	if(tam>0 && this->dimension!=tam){
		TPoro *datoAux = new TPoro[tam];

		for(int i=0; i<tam && i<this->dimension; i++){

			datoAux[i]=this->datos[i];
		}

		delete [] this->datos;
		this->dimension=tam;
		datos=NULL;
		datos = new TPoro[this->dimension];
		for(int i=0; i<this->dimension; i++){

			this->datos[i]=datoAux[i];

		}
		delete [] datoAux;
		datoAux=NULL;
		redimen=true;

	}
	return redimen;
}

//Funcion amiga
ostream& operator<<(ostream &os, TVectorPoro &tv){

	if(tv.datos!=NULL){
		os<<"[";
		for(int i=0; i<tv.dimension; i++){
			os<<i+1<<" "<<tv.datos[i];
			if(i!=tv.dimension-1){
				cout<<" ";
			}
		}
		os<<"]";

	}else{
		os<<"[]";
	}
	return os;

}

#include <iostream>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "tporo.h"
using namespace std;

//Contructor por defecto
TPoro::TPoro(){
	x=0;
	y=0;
	volumen=0;
	color=NULL;
}


//Constructor a partir de una posicion y un volumen
TPoro::TPoro(int x, int y, double volumen){
	this->x=x;
	this->y=y;
	this->volumen=volumen;
	this->color=NULL;
}
//Constructor a partir de una posicion, un volumen y un color
TPoro::TPoro(int x, int y, double volumen, char* color){
	this->x=x;
	this->y=y;
	this->volumen=volumen;
	Color(color);
}

TPoro::~TPoro(){
	this->x=this->y=this->volumen=0;
	if(!this->color)
		delete color;
		color=NULL;
}

//Constructor copia
TPoro::TPoro(const TPoro &p){
	if(this!=&p){
		this->x=p.x;
		this->y=p.y;
		this->volumen=p.volumen;
		Color(p.color);
	}
	
}

//Sobrecarga del operador asignacion
TPoro& TPoro::operator=(const TPoro &p){

	if(this!=&p){
		(*this).~TPoro();
		x=p.x;
		y=p.y;
		volumen=p.volumen;
		Color(p.color);

	}

	return *this;
}

//Sobrecarga del operador igualdad
bool TPoro::operator==(const TPoro &p){
	bool iguales=false;
	if(this->x==p.x && this->y==p.y && this->volumen==p.volumen){
		if(this->color==NULL && p.color==NULL){
			iguales=true;
		}else if(this->color!=NULL){
			if(p.color!=NULL){
				if((strcmp(this->color,p.color))==0){
					iguales=true;
				}
			}

		}
	}
	return iguales;
}

//Sobrecarga del operador desigualdad
bool TPoro::operator!=(const TPoro &p){

	return !(*this==p);
}


//Modificador Color
void TPoro::Color(const char *color){
	
	if(color!=NULL){
		char *minus = new char(strlen(color)+1);
		int i;
		for(i=0;i<strlen(color);i++){
			minus[i]=tolower(color[i]);
		}
		minus[i]='\0';
		this->color=new char(strlen(color)+1);
		strcpy(this->color, minus);
	}else{
		this->color=NULL;
	}

}

//Devuelve cierto si el poro esta vacio
bool TPoro::EsVacio() const{
	if(x==0 && y==0 && volumen==0 && color==NULL){
		return true;
	}
	return false;
}

//Funcio amiga
ostream& operator<<(ostream &os, const TPoro &p){

	if(!p.EsVacio()){
		os.setf(ios::fixed);
		os.precision( 2 );
		os<<"("<<p.x<<", "<<p.y<<") "<<p.volumen<<" ";
		if(p.color!=NULL){
			os<<p.color;
		}else{
			os<<"-";
		}
	}else{
		os<<"()";
	}
	
	return os;
}

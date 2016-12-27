#include <iostream>
using namespace std;
#include "tporo.h"



void tad1(){
	TPoro a, b, c;
	cout << "No hace nada" << endl;
}

void tad2(){
	TPoro a;
	cout<<a<<endl;	
}

void tad3(){
	TPoro a(1,2,3,"rojo");
	cout<<a<<endl;
}

void tad4(){
	TPoro a;
	a.Posicion(10, 20);
	cout<<a<<endl;
}
void tad5(){
	TPoro a(1,2,3, "rojo");
	TPoro b;
	b=a;
	cout<<a<<endl;
	cout<<b<<endl;
}

void tad6(){
	TPoro a(1, 2, 3, "rojo");

	 cout << "PosicionX: " << a.PosicionX() << endl;
	 cout << "PosicionY: " << a.PosicionY() << endl;
	 cout << "Volumen: " << a.Volumen() << endl;
}

void tad7(){
	 TPoro a(1, 2, 3, "rojo");

  if(a.PosicionX() == 1)
    cout << "SI" << endl;
  else
    cout << "NO" << endl;

  if(a.PosicionY() == 2)
    cout << "SI" << endl;
  else
    cout << "NO" << endl;
}

void tad8(){
	TPoro a;

  if(a.EsVacio())
    cout << "VACIO" << endl;
  else
    cout << "NO VACIO" << endl;

  a.Color("rojo");

  if(a.EsVacio())
    cout << "VACIO" << endl;
  else
    cout << "NO VACIO" << endl;

}

void tad9(){
	  TPoro a;

  if(a.EsVacio())
    cout << "VACIO" << endl;
  else
    cout << "NO VACIO" << endl;

  a.Color("rojo");

  if(a.EsVacio())
    cout << "VACIO" << endl;
  else
    cout << "NO VACIO" << endl;

  a.~TPoro();

  if(a.EsVacio())
    cout << "VACIO" << endl;
  else
    cout << "NO VACIO" << endl;
}

void tad10(){
	  TPoro a, b(0, 0, 0, NULL);
  TPoro c(a), d(b);

  if(a.EsVacio())
    cout << "VACIO" << endl;
  else
    cout << "NO VACIO" << endl;

  if(b.EsVacio())
    cout << "VACIO" << endl;
  else
    cout << "NO VACIO" << endl;

  if(c.EsVacio())
    cout << "VACIO" << endl;
  else
    cout << "NO VACIO" << endl;

  if(d.EsVacio())
    cout << "VACIO" << endl;
  else
    cout << "NO VACIO" << endl;
}

int main(void){

	cout<<"Comprobamos tad1: "<<endl; tad1();
	cout<<"Comprobamos tad2: "<<endl; tad2();
	cout<<"Comprobamos tad3: "<<endl; tad3();
	cout<<"Comprobamos tad4: "<<endl; tad4();
	cout<<"Comprobamos tad5: "<<endl; tad5();
	cout<<"Comprobamos tad6: "<<endl; tad6();
	cout<<"Comprobamos tad7: "<<endl; tad7();
	cout<<"Comprobamos tad8: "<<endl; tad8();
	cout<<"Comprobamos tad9: "<<endl; tad9();
	cout<<"Comprobamos tad10: "<<endl; tad10();
}

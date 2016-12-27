#include <iostream>
using namespace std;


#include "tlistaporo.h"

void tad1(){
	TPoro a, b, c;
  TListaPoro d,  e, f;

  cout << "No hace nada" << endl;
}

void tad2(){
	  TPoro p(1, 1, 1), q(2, 2, 2), r(3, 3, 3);
  TListaPoro a, b, c;

  cout << a.Longitud() << endl;
  cout << b.Longitud() << endl;
  cout << c.Longitud() << endl;

  a.Insertar(p);
  b.Insertar(p); b.Insertar(q);
  c.Insertar(p); c.Insertar(q); c.Insertar(r);

  cout << a.Longitud() << endl;
  cout << b.Longitud() << endl;
  cout << c.Longitud() << endl;
}

void tad3(){
	  TListaPoro a;

  cout << a << endl;
}

void tad4(){
	  TPoro p(1, 2, 3);
  TListaPoro a, b;

  if(a == b)
    cout << "SI"  << endl;
  else
    cout << "NO" << endl;

  a.Insertar(p);

  if(a == b)
    cout << "SI"  << endl;
  else
    cout << "NO" << endl;
}

void tad5(){
	  TPoro p(1, 1, 1), q(2, 2, 2), r(3, 3, 3);
  TListaPoro a;

  a.Insertar(p); a.Insertar(q); a.Insertar(r);

  cout << a << endl;
}

void tad6(){
	  TPoro p(1, 2, 3, (char*)"rojo");
  TListaPoro a, b;

  a.Insertar(p);
  b = a;

  cout << a << endl;
  cout << b << endl;
}

void tad7(){
  TPoro p(1, 2, 3, (char*)"rojo");
  TListaPoro a;

  cout << "Longitud: " << a.Longitud() << endl;

  a.Insertar(p);
  cout << "Longitud: " << a.Longitud() << endl;

  a.Insertar(p);
  cout << "Longitud: " << a.Longitud() << endl;

  a.~TListaPoro();
  cout << "Longitud: " << a.Longitud() << endl;
}

void tad8(){
	  TPoro p(1, 2, 3, (char*)"rojo");
  TListaPoro a, b;

  cout << "Longitud: " << a.Longitud() << endl;
  cout << "Longitud: " << b.Longitud() << endl;

  a.Insertar(p);
  b = a;

  cout << "Longitud: " << a.Longitud() << endl;
  cout << "Longitud: " << b.Longitud() << endl;
}

void tad9(){
	  TPoro p(1, 1, 1, (char*)"rojo"), q(2, 2, 2, (char*)"verde");
  TListaPoro a;

  a.Insertar(p);
  a.Insertar(q);
  cout << a << endl;

  a.Borrar(p);
  cout << a << endl;

  a.Borrar(q);
  cout << a << endl;
}

void tad10(){
	  TPoro p(1, 1, 1, (char*)"rojo"), q(2, 2, 2, (char*)"verde"), r(3, 3, 3, (char*)"amarillo");
  TListaPoro a;

  a.Insertar(p); a.Insertar(q);

  if(a.Buscar(p))
    cout << "SI" << endl;
  else
    cout << "NO" << endl;

  if(a.Buscar(q))
    cout << "SI" << endl;
  else
    cout << "NO" << endl;

  if(a.Buscar(r))
    cout << "SI" << endl;
  else
    cout << "NO" << endl;
}

void tad11(){
	  TPoro p(1, 1, 1, (char*)"rojo"), q(2, 2, 2, (char*)"verde"), r(3, 3, 3, (char*)"amarillo");
  TListaPoro a;
  TListaPosicion pos;

  a.Insertar(p); a.Insertar(q); a.Insertar(r);

  pos = a.Primera();

  while(!pos.EsVacia())
  {
    cout << a.Obtener(pos) << endl;
    pos = pos.Siguiente();
  }
}

void tad12(){
	  TPoro p(1, 1, 1, (char*)"rojo"), q(2, 2, 2, (char*)"verde"), r(3, 3, 3, (char*)"amarillo");
  TListaPoro a;
  TListaPosicion pos;

  a.Insertar(p); a.Insertar(q); a.Insertar(r);

  pos = a.Ultima();

  while(!pos.EsVacia())
  {
    cout << a.Obtener(pos) << endl;
    pos = pos.Anterior();
  }
}

int main(void){

	cout<<"Salida tad1: "<<endl; tad1();
	cout<<"Salida tad2: "<<endl; tad2();
	cout<<"Salida tad3: "<<endl; tad3();
	cout<<"Salida tad4: "<<endl; tad4();
	cout<<"Salida tad5: "<<endl; tad5();
	cout<<"Salida tad6: "<<endl; tad6();
	cout<<"Salida tad7: "<<endl; tad7();
	cout<<"Salida tad8: "<<endl; tad8();
	cout<<"Salida tad9: "<<endl; tad9();
	cout<<"Salida tad10: "<<endl; tad10();
	cout<<"Salida tad11: "<<endl; tad11();	
	cout<<"Salida tad12: "<<endl; tad12();
}







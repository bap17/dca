#include <iostream>
using namespace std;

#include "tporo.h"
#include "tvectorporo.h"

void tad1(){
	  TPoro a, b, c;
  TVectorPoro d, e, f;

  cout << "No hace nada" << endl;

}

void tad2(){
	TPoro auxOK;
  TVectorPoro a, b(5), c(10);

  cout << a.Longitud() << endl;
  cout << b.Longitud() << endl;
  cout << c.Longitud() << endl;

}

void tad3(){
	TVectorPoro a;

  cout << a << endl;
}

void tad4(){
	  TVectorPoro a(5);
  TVectorPoro b;

  if(a == b)
    cout << "SI"  << endl;
  else
    cout << "NO" << endl;

}

void tad5(){
	  TPoro a(1, 2, 3, "rojo");
  TVectorPoro v(5);

  v[1] = a;
  v[2] = a;
  v[3] = a;
  v[4] = a;
  v[5] = a;

  cout << v << endl;
}

void tad6(){
	 TPoro a(1, 2, 3, "rojo");
  TVectorPoro v(5), w;

  v[1] = a;
  v[2] = a;
  v[3] = a;
  v[4] = a;
  v[5] = a;

  w = v;

  cout << v << endl;
  cout << w << endl;

}

void tad7(){
	TPoro a(1, 2, 3, "rojo");
  TVectorPoro v(5);

  cout << "Cantidad: " << v.Cantidad() << endl;

  v[1] = a;
  cout << "Cantidad: " << v.Cantidad() << endl;

  v[2] = a;
  cout << "Cantidad: " << v.Cantidad() << endl;

  v[3] = a;
  cout << "Cantidad: " << v.Cantidad() << endl;

  v[4] = a;
  cout << "Cantidad: " << v.Cantidad() << endl;

  v[5] = a;
  cout << "Cantidad: " << v.Cantidad() << endl;

}

void tad8(){
	TPoro a(1, 2, 3, "rojo");
  TVectorPoro v(5), w;

  cout << "Longitud: " << v.Longitud() << endl;
  cout << "Longitud: " << w.Longitud() << endl;

  w = v;

  cout << "Longitud: " << v.Longitud() << endl;
  cout << "Longitud: " << w.Longitud() << endl;
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
}
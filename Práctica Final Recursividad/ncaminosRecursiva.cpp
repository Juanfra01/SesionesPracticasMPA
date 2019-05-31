
#include <iostream>
#include <stdlib.h>
#include <string>
#include "funciones.h"
using namespace std;

int main()
{

    int *X,*Y,*M;
    int k,xentrada,yentrada,xsalida,ysalida,F,C;
    string valor1  = "X de entrada";
    string valor2  = "Y de entrada";
    string valor3  = "X de salida";
    string valor4  = "Y de salida";
  //  string fila    = " fila N";
  //  string columna = " columna M";


    F = introducirTamanyoFila();
    C = introducirTamanyoColumna();

    X = new int[F*C];
    Y = new int[F*C];
    M = new int[F*C];


    //COORDENADAS DE ENTRADA
    xentrada = introducirValor(valor1);
    while(xentrada<1 || xentrada > F) {
		cout<<"\nEl valor a introducir debe de estar entre 1 y "<<F<<endl;
		xentrada = introducirValor(valor1);
	}

    yentrada = introducirValor(valor2);
    while(yentrada<1 || yentrada > C) {
		cout<<"\nEl valor a introducir debe de estar entre 1 y "<<C<<endl;
		yentrada = introducirValor(valor2);
	}

	//COORDENADAS DE SALIDA
	xsalida = introducirValor(valor3);
	while(xsalida<1 || xsalida>F) {
		cout<<"\nEl valor a introducir debe de estar entre 1 y "<<F<<endl;
		xsalida = introducirValor(valor3);
	}
	ysalida = introducirValor(valor4);
	while(ysalida<1 || xsalida>C) {
		cout<<"\nEl valor a introducir debe de estar entre 1 y "<<C<<endl;
		ysalida = introducirValor(valor4);
	}


    cout<<"Punto de entrada: ("<<xentrada<<","<<yentrada<<")"<<endl;
    cout<<"Punto de salida: ("<<xsalida<<","<<ysalida<<")"<<endl;

	xentrada--;
	yentrada--;
	xsalida--;
	ysalida--;

    k=1;
    X[k] = xentrada;
    Y[k] = yentrada;

     int total = 0;
    //cuentaCaminosRecursivo(X,Y,M,xsalida,ysalida,k,total);

	total = cuentaCaminosIterativo(xentrada, yentrada, xsalida, ysalida, F, C);

    cout<<endl;
    cout<<"El total de caminos encontrados es de: "<<total<<endl;
    cout<<endl;


    //LIBERAR MEMORIA

    delete[] X;
    delete[] Y;
    delete[] M;

    return 0;
}

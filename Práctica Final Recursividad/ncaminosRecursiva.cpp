#include "funciones.h"
#include <iostream>
#include <stdlib.h>
using namespace std;





int main()
{
    int **laberinto;
    int *X,*Y,*M,*sol;
    int k,xentrada,yentrada,xsalida,ysalida,F,C;
    string valor1  = "entrada X";
    string valor2  = "entrada Y";
    string valor3  = "salida X";
    string valor4  = "salida Y";
  //  string fila    = " fila N";
  //  string columna = " columna M";


    F = introducirTamanyoFila();
    C = introducirTamanyoColumna();

    X = new int[F*C];
    Y = new int[F*C];
    M = new int[F*C];
    sol = new int[F*C];

    //COORDENADAS DE ENTRADA
    do{
        cout<<"\nEl valor a introducir debe de estar entre 0 y "<<F<<endl;
        xentrada = introducirValor(valor1);
    }while(xentrada > F);
    do{
        cout<<"\nEl valor a introducir debe de estar entre 0 y "<<C<<endl;
        yentrada = introducirValor(valor2);
    }while(yentrada > C);

    //COORDENADAS DE SALIDA
    do{
        cout<<"\nEl valor a introducir debe de estar entre "<<xentrada<<" y "<<F<<endl;
        xsalida = introducirValor(valor3);
        if(xsalida > F){
            xsalida = 0;
        }
    }while(xentrada >= xsalida);

     do{
        cout<<"\nEl valor a introducir debe de estar entre "<<yentrada<<" y "<<C<<endl;
        ysalida = introducirValor(valor4);
        if(ysalida > C){
            ysalida = 0;
        }
    }while(yentrada >= ysalida);

    cout<<"Punto de entrada: ("<<xentrada<<","<<yentrada<<")"<<endl;
    cout<<"Punto de salida: ("<<xsalida<<","<<ysalida<<")"<<endl;

    k=1;
    X[k] = xentrada;
    Y[k] = yentrada;

    laberinto = crearLaberinto(F,C);
    pintarLaberinto(laberinto,F,C);
  //  imprimirLaberinto(laberinto,F,C);

    for(int r=0;r<F*C;r++){
        sol[r]=0;
    }

    int total = 0;
    funcionLaberinto(laberinto,X,Y,M,xentrada,yentrada,xsalida,ysalida,k,sol,F,C);


    cout<<endl;
    cout<<"El total de caminos encontrados es de: "<<total<<endl;
    cout<<endl;
    imprimirLaberinto(laberinto,F,C);

    //LIBERAR MEMORIA
    for(int i=0;i<F;i++)delete[] laberinto[i];
    delete[] X;
    delete[] Y;
    delete[] M;
    delete[] sol;
    return 0;
}

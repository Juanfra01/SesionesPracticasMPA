/*
Juan Francisco Torres Martínez
Alejandro Gallego López
*/

#include <iostream>
#include <stdlib.h>
#include <locale.h>//para los acentos
using namespace std;

#define MUEVE_DERECHA       1
#define MUEVE_ABAJO         2
#define MUEVE_DERECHA_ABAJO 3

int introducirTamanyo(string);
int introducirTamanyoColumna();
int introducirValor(string);

void cuentaCaminosRecursivo(int*,int*,int*,int,int, int,int&);
int cuentaCaminosIterativo(int, int, int, int, int, int);
void siguienteCandidato(int*, int*, int*, int);
bool factible(int,int,int,int);

// FUNCIÓN PRINCIPAL
int main()
{
    setlocale(LC_ALL,"");

    int *X=NULL,*Y=NULL,*M=NULL;
    int k;
    int xentrada = 0;
    int yentrada = 0;
    int xsalida  = 0;
    int ysalida  = 0;
    int F = 0;
    int C = 0;
    int opcion=0,total = 0;
    string valor1  = "X de entrada";
    string valor2  = "Y de entrada";
    string valor3  = "X de salida";
    string valor4  = "Y de salida";
    string fila    = "filas";
    string columna = "columnas";

    //MENU//
    do
    {
        cout<<"\n --------------"<<endl;
        cout<<" #### MENU ####"<<endl;
        cout<<" --------------"<<endl;

		cout<<" Plano: "<<F<<" x "<<C<<endl;

        cout<<" Origen: ("<<xentrada<<","<<yentrada<<")"<<endl;
        cout<<" Destino: ("<<xsalida<<","<<ysalida<<")"<<endl;

        cout<<"\n 1. Tamaño del plano.";
        cout<<"\n 2. Punto origen y destino.";
        cout<<"\n 3. Algoritmo recursivo.";
        cout<<"\n 4. Algoritmo iterativo.";
        cout<<"\n 5. Salir.";
        cout<<"\n\nIntroduzca una opción de las mencionadas (1 - 5)."<<endl;
        cin>>opcion;

        switch(opcion)
        {
            case 1:

                    F = introducirTamanyo(fila);
                    C = introducirTamanyo(columna);
                    if(F==0 && C==0){
                        cout<<"\n\n¡¡¡¡¡¡ATENCIÓN!!!!!!"<<endl;
                        cout<<"Introduzca una tamaño distinto de 0, por lo menos en uno de  los ejes"<<endl<<endl;
                        break;
                    }

                    X = new int[F*C];
                    Y = new int[F*C];
                    M = new int[F*C];
                break;
            case 2:
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


                break;
            case 3:
                    if(F==0 && C==0){
                        break;
                    }
                    xentrada--;
                    yentrada--;
                    xsalida--;
                    ysalida--;

                    k=1;
                    X[k] = xentrada;
                    Y[k] = yentrada;
                    cuentaCaminosRecursivo(X,Y,M,xsalida,ysalida,k,total);
                    cout<<endl;
                    cout<<"El total de caminos encontrados mediante la función recursiva es de: "<<total<<endl;
                    cout<<endl;
                    total = 0;//contador de caminos
                break;
            case 4:
                    if(F==0 && C==0){
                        break;
                    }
                    total = cuentaCaminosIterativo(xentrada, yentrada, xsalida, ysalida, F, C);
                    cout<<endl;
                    cout<<"El total de caminos encontrados mediante la función iterariva es de: "<<total<<endl;
                    cout<<endl;
                    total = 0;//contador de caminos
                break;
            case 5:

                break;
             default:
				cout<<"Opción incorrecta"<<endl;
        }//FIN SWITCH
    }while(opcion != 5);

    system("cls");//Vacía el contenido de la consola
    cout<<"\nHASTA LA PRÓXIMA"<<endl;

    //LIBERAR MEMORIA
    if (X!=NULL) {
		delete[] X;
		delete[] Y;
		delete[] M;
	}
    return 0;
}

//FUNCIÓN PARA INTRODUCIR EL TAMAÑO DE LA MATRIZ
int introducirTamanyo(string tamanyo){
    int num;
    cout<<"Introduce el numero de "<<tamanyo<<" de la matriz: ";
    cin>>num;

    return num;
}

//INTRODUCIR VALORES DE LAS COORDENADAS
int introducirValor(string valor){
    int num;
    cout<<"Introduce la coordenada "<<valor<<": ";
    cin>>num;

    return num;
}

//FUNCIÓN RECURSIVA
void cuentaCaminosRecursivo(int *X, int *Y,int *M, int xsalida, int ysalida, int k, int& total)
{
    int xsig,ysig;
    M[k]=0;
    while(M[k]<3)
    {
        M[k] = M[k] + 1;
        siguienteCandidato(X,Y,M,k);
        xsig = X[k];
        ysig = Y[k];
        if(factible(xsig,ysig,xsalida,ysalida)){
            X[k+1] = xsig;
            Y[k+1] = ysig;
            if(X[k+1] == xsalida && Y[k+1] == ysalida){
                total++;
            }else{
              cuentaCaminosRecursivo(X,Y,M,xsalida,ysalida,k+1,total);
            }
        }//fin factible
    }//fin while
}

// FUNCION ITERATIVA
int cuentaCaminosIterativo(int xentrada, int yentrada, int xsalida, int ysalida, int F, int C)
{
	int *X,*Y,*M;
	int k,total;
	int xsig,ysig;
    X = new int[F*C];
    Y = new int[F*C];
    M = new int[F*C];
	k = 1;
	total=0;
	X[k] = xentrada;
    Y[k] = yentrada;
    M[k] = 0;
	while (k>0) {
		while(M[k]<3) {
			M[k] = M[k] + 1;
			siguienteCandidato(X,Y,M,k);
			xsig = X[k];
			ysig = Y[k];
			if(factible(xsig,ysig,xsalida,ysalida)) {
				X[k+1] = xsig;
				Y[k+1] = ysig;
				if(X[k+1] == xsalida && Y[k+1] == ysalida){
					total++;
				} else {
					k++;
					M[k]=0;
				}
			}
		}
		k--;
	}
	delete[] X;
	delete[] Y;
	delete[] M;
	return total;
}

//FUNCIÓN SIGUIENTE CANDIDATO
void siguienteCandidato(int *X, int *Y, int *M, int k)
{
    if(M[k]==MUEVE_DERECHA){
        Y[k] = Y[k] + 1;
    }
    if(M[k]==MUEVE_ABAJO){
        Y[k] = Y[k] - 1;
        X[k] = X[k] + 1;
    }
    if(M[k]==MUEVE_DERECHA_ABAJO){
        Y[k] = Y[k] + 1;
    }
}

//FUNCIÓN QUE EVALUA SI LA COORDENADAS SIGUIENTES SON FACTIBLES
bool factible(int xsig, int ysig, int xsalida, int ysalida){
	return xsig<=xsalida && ysig<=ysalida;
}

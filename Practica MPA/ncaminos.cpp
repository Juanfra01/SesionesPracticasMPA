#include <iostream>
#include <stdlib.h>
#include <locale.h>//para los acentos
using namespace std;

#define MUEVE_DERECHA       1
#define MUEVE_ABAJO         2
#define MUEVE_DERECHA_ABAJO 3

//á: 160 é: 130 í: 161 ó: 162 ú: 163 Á: 181 É: 144 Í: 214 Ó: 224 Ú: 23 ñ: 164 Ñ: 165


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

    int *X,*Y,*M;
    int k,xentrada,yentrada,xsalida,ysalida,F,C;
    int opcion=0,total;
    string valor1  = "X de entrada";
    string valor2  = "Y de entrada";
    string valor3  = "X de salida";
    string valor4  = "Y de salida";
    string fila    = "filas";
    string columna = "columnas";





    do
    {
        cout<<"\n 1. Tamaño del plano.";
        cout<<"\n 2. Punto origen y destino.";
        cout<<"\n 3. Algoritmo recursivo.";
        cout<<"\n 4. Algoritmo iterativo.";
        cout<<"\n 5. Salir.";
        cout<<"\n\nIntroduzca una opción."<<endl;
        cin>>opcion;

        switch(opcion)
        {
            case 1:
                    F = introducirTamanyo(fila);
                    C = introducirTamanyo(columna);

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

                    total = 0;//contador de caminos
                break;
            case 3:
                    xentrada--;
                    yentrada--;
                    xsalida--;
                    ysalida--;

                    k=1;
                    X[k] = xentrada;
                    Y[k] = yentrada;
                    cuentaCaminosRecursivo(X,Y,M,xsalida,ysalida,k,total);
                    cout<<endl;
                    cout<<"El total de caminos encontrados es de: "<<total<<endl;
                    cout<<endl;
                break;
            case 4:
                    total = cuentaCaminosIterativo(xentrada, yentrada, xsalida, ysalida, F, C);
                    cout<<endl;
                    cout<<"El total de caminos encontrados es de: "<<total<<endl;
                    cout<<endl;
                break;
            case 5:
                    opcion =5;
                break;
        }//FIN SWITCH



    }while(opcion != 5);

    //LIBERAR MEMORIA
    delete[] X;
    delete[] Y;
    delete[] M;
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
            //cout<<"Nivel k: "<<k<<" ("<<X[k+1]<<","<<Y[k+1]<<")"<<endl;
            if(X[k+1] == xsalida && Y[k+1] == ysalida){
                total++;
                //cout<<"Se ha encontrado la salida numero: "<<total<<endl;
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

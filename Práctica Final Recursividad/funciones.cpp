#include <iostream>
#include <stdlib.h>
using namespace std;


int introducirTamanyoFila(){
    int num;
    cout<<"Introduce el valor de la fila: ";
    cin>>num;

    return num;
}

int introducirTamanyoColumna(){
    int num;
    cout<<"Introduce el valor de la columna: ";
    cin>>num;

    return num;
}

//CREAR LABERINTO y DARLE VALORES
int **crearLaberinto(int f, int c){
    int **maze;
    maze = new int*[f];
    for(int x=0;x<f;x++){
        maze[x] = new int[c];
    }

    return maze;
}

//INTRODUCIR VALORES DE LAS COORDENADAS
int introducirValor(string valor){
    int num;
    cout<<"Introduce el valor de "<<valor<<":";
    cin>>num;

    return num;
}

//DAR VALORES AL LABERINTO
void pintarLaberinto(int **maze, int f, int c){
    for(int i=0;i<f;i++){
        for(int j=0;j<c;j++){
            maze[i][j] = 0;
        }
    }
}


//IMPRIMIR LABERINTO
void imprimirLaberinto(int **maze,int f, int c){
    for(int i=0;i<f;i++){
        for(int j=0;j<c;j++){
            cout<<maze[i][j]<<" ";
        }
        cout<<endl;
    }
}



//FUNCIÓN LABERINTO
void funcionLaberinto(int **maze,int *Y, int *X,int *M, int xentrada, int yentrada, int xsalida, int ysalida, int k, int *sol,int f,int c)
{
    int xsig,ysig,xk,yk;
    M[k]=0;
    while(M[k]<3)
    {
        M[k] = M[k] + 1;
        siguienteCandidato(X,Y,M,k,xsalida,ysalida);
        xsig = X[k];
        ysig = Y[k];
        if(factible(maze,xsig,ysig,xsalida,ysalida,f,c)==true){
            X[k+1] = xsig;
            Y[k+1] = ysig;
            cout<<"Nivel k: "<<k<<" ("<<X[k+1]<<","<<Y[k+1]<<")"<<endl;
            if(X[k+1] == xsalida && Y[k+1] == ysalida){
                sol[k] = k;
                cout<<"Se ha encontrado la salida numero: "<<sol[k]<<endl;
                maze[xsalida][ysalida]=1;

            }else{
                xk = X[k];
                yk = Y[k];
                maze[xk][yk] = 1;
                funcionLaberinto(maze,Y,X,M,xentrada,yentrada,xsalida,ysalida,k+1,sol,c,f);
            }
        }//fin factible
    }//fin while
}

//FUNCIÓN SIGUIENTE CANDIDATO
void siguienteCandidato(int *X, int *Y, int *M, int k, int xsalida, int ysalida)
{
    if(M[k]==1){
        Y[k] = Y[k] + 1;
    }
    if(M[k]==2){
        Y[k] = Y[k] - 1;
        X[k] = X[k] + 1;
    }
    if(M[k]==3){
        Y[k] = Y[k] + 1;
    }
}


//función factible
bool factible(int **maze, int xsig, int ysig, int xsalida, int ysalida, int f, int c){

  if(xsig > f-1 || ysig > c-1){
        return false;

    }else{
        if( xsig > xsalida ) {
            return false;
        }else if(ysig > ysalida ){
            return false;
		}
		else{
            return true;
        }
    }
}

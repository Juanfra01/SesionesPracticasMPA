#include <iostream>

using namespace std;

//#define N 6

int introducirValor(string);
int introducirTamanyo(string);
int **crearLaberinto(int,int);
void pintarLaberinto(int**,int,int);
void imprimirLaberinto(int**,int,int);
void funcionLaberinto(int**,int*,int*,int*,int,int,int,int, int,int*,int,int);
void siguienteCandidato(int*, int*, int*, int, int, int);
bool factible(int**,int,int,int,int,int,int);



int main()
{
    int **laberinto;
    int *X,*Y,*M,*sol;
    int k,xentrada,yentrada,xsalida,ysalida,F,C;
    string valor1  = "entrada X";
    string valor2  = "entrada Y";
    string valor3  = "salida X";
    string valor4  = "salida Y";
    string fila    = " fila N";
    string columna = " columna M";


    F = introducirTamanyo(fila);
    C = introducirTamanyo(columna);

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


    /*
    for(int j=1;j<F*C;j++){
        if(sol[j] <=N && sol[j] != 0){
            ntotal+=1;
        }
        cout<<"valor de sol["<<j<<"] ="<<sol[j]<<endl;
    }*/

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
}//fin main

//CREAR LABERINTO y DARLE VALORES
int **crearLaberinto(int f, int c){
    int **maze;
    maze = new int*[f];
    for(int x=0;x<f;x++){
        maze[x] = new int[c];
    }

    return maze;
}

//DAR VALORES AL LABERINTO
void pintarLaberinto(int **maze, int f, int c){
    for(int i=0;i<f;i++){
        for(int j=0;j<c;j++){
            maze[i][j] = 0;
        }
    }
}

//INTRODUCIR VALORES DE LAS COORDENADAS
int introducirValor(string valor){
    int num;
    cout<<"Introduce el valor de "<<valor<<":";
    cin>>num;

    return num;
}


int introducirTamanyo(string valor){
    int num;
    cout<<"Introduce el valor de "<<valor<<":";
    cin>>num;

    return num;
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












#include <iostream>

using namespace std;

#define N 5

int **crearLaberinto(int);
void pintarLaberinto(int**);
void imprimirLaberinto(int**);
void funcionLaberinto(int**,int*,int*,int*,int,int,int,int, int,int*);
void siguienteCandidato(int*, int*, int*, int, int, int);
bool factible(int**,int,int,int,int);



int main()
{
    int **laberinto;
    int *X,*Y,*M,*sol;
    int k,xentrada,yentrada,xsalida,ysalida;

    X = new int[N*N];
    Y = new int[N*N];
    M = new int[N*N];
    sol = new int[N*N];
    int ntotal = 0;

    xentrada = 1;
    yentrada = 1;
    xsalida  = 3;
    ysalida  = 2;

    k=1;
    X[k] = xentrada;
    Y[k] = yentrada;



    laberinto = crearLaberinto(N);
    pintarLaberinto(laberinto);
    imprimirLaberinto(laberinto);



    funcionLaberinto(laberinto,X,Y,M,xentrada,yentrada,xsalida,ysalida,k,sol);

    for(int j=1;j<N*N;j++){
        if(sol[j]==1){
            cout<<"sol "<<endl;
            ntotal += sol[j];
        }
    }

    cout<<endl;
    cout<<"El total de caminos encontrados es de: "<<ntotal<<endl;
    cout<<endl;
    imprimirLaberinto(laberinto);

    //LIBERAR MEMORIA
    for(int i=0;i<N;i++)delete[] laberinto[i];
    delete[] X;
    delete[] Y;
    delete[] M;
    return 0;
}

//CREAR LABERINTO y DARLE VALORES
int **crearLaberinto(int n){
    int **maze;
    maze = new int*[n];
    for(int x=0;x<n;x++){
        maze[x] = new int[n];
    }

    return maze;
}


void pintarLaberinto(int **maze){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            maze[i][j] = 0;
        }
    }
}

//IMPRIMIR LABERINTO
void imprimirLaberinto(int **maze){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<maze[i][j]<<" ";
        }
        cout<<endl;
    }
}


//FUNCIÓN LABERINTO
void funcionLaberinto(int **maze,int *Y, int *X,int *M, int xentrada, int yentrada, int xsalida, int ysalida, int k, int *sol)
{
    int xsig,ysig,xk,yk;
    M[k]=0;
    maze[xentrada][yentrada]=1;
    maze[xsalida][ysalida]=2;

    while(M[k]<3){

  /*  for(int i=0;i<3;i++){
        M[k] = i;
        cout<<"Vector M:"<<i<<" ";
        for(int c=1;c<=k;c++){
            cout<<" (";
            cout<<"X"<<X[k]<<" Y"<<Y[k];
            cout<<") ";
        }
        cout<<endl;*/


        M[k] = M[k] + 1;
        siguienteCandidato(X,Y,M,k,xsalida,ysalida);
        xsig = X[k];
        ysig = Y[k];
        if(factible(maze,xsig,ysig,xsalida,ysalida)==true){
            X[k+1] = xsig;
            Y[k+1] = ysig;
            if(X[k+1] == xsalida && Y[k+1] == ysalida){
                sol[k] = 1;
                cout<<"Se ha encontrado la salida numero: "<<sol[k]<<endl;
                maze[xsalida][ysalida]=1;

               // X[k-1] = xsig;
               // Y[k-1] = ysig;
              //  imprimirLaberinto(maze);
             //   pintarLaberinto(maze);
            }else{
                xk = X[k];
                yk = Y[k];
                maze[xk][yk] = 1;
                funcionLaberinto(maze,Y,X,M,xentrada,yentrada,xsalida,ysalida,k+1,sol);
            }
        }//fin factible
   // }//for
    }//fin while
}

//FUNCIÓN SIGUIENTE CANDIDATO
void siguienteCandidato(int *X, int *Y, int *M, int k, int xsalida, int ysalida)
{
    if(M[k]==1){
        Y[k] = Y[k] + 1;
        //cout<<"derecha "<<endl;
        //cout<<"Valor de Y[k] "<<Y[k]<<" ||Valor de ysalida]: "<<ysalida<<endl;
    }
    if(M[k]==2){
        Y[k] = Y[k] - 1;
        X[k] = X[k] + 1;
       // cout<<"abajo"<<endl;
    }
    if(M[k]==3){
        Y[k] = Y[k] + 1;
       // cout<<"diagonal"<<endl;
    }
}


//función factible
bool factible(int **maze, int xsig, int ysig, int xsalida, int ysalida){

  if(xsig > N-1 || ysig > N-1){
        return false;

    }else{
        if( xsig > xsalida ) {
            //cout<<"\nEntra en funcion factible  de Xsig devuelve false!!!!! "<<endl;
            return false;
        }else if(ysig > ysalida ){
		//	  cout<<"\nEntra en funcion factible de ysig devuelve false!!!!! "<<endl;
            return false;
		}
		else{
         //   cout<<"\nEntra en funcion factible devuelve true!!!!! "<<endl;
       //     cout<<"Valor de xsig "<<xsig<<" ||Valor de ysig: "<<ysig<<endl;
            return true;
        }
    }
}












#include <iostream>

using namespace std;

#define N 5

int **crearLaberinto(int);
void imprimirLaberinto(int**);
void funcionLaberinto(int**,int,int,int,int);
void siguienteCandidato(int*, int*, int*, int);
bool factible(int**,int,int);



int main()
{
    int **laberinto;
  //  int n=5;

    laberinto = crearLaberinto(N);
    imprimirLaberinto(laberinto);

    funcionLaberinto(laberinto,1,1,4,4);

    cout<<endl;
    imprimirLaberinto(laberinto);



    for(int i=0;i<N;i++)delete[] laberinto[i];
    return 0;
}

//CREAR LABERINTO y DARLE VALORES
int **crearLaberinto(int n)
{
    int **maze;
    maze = new int*[n];
    for(int x=0;x<n;x++){
        maze[x] = new int[n];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            maze[i][j] = 0;
        }
    }
    maze[1][4] = 2;
    maze[2][2] = 2;
    maze[3][2] = 2;
    maze[3][3] = 2;

    return maze;
}

//IMPRIMIR LABERINTO
void imprimirLaberinto(int **maze)
{
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<maze[i][j]<<" ";
        }
        cout<<endl;
    }
}

//FUNCIÓN LABERINTO
void funcionLaberinto(int **maze, int xentrada, int yentrada, int xsalida, int ysalida)
{
    int k,xsig,ysig;
    int *X,*Y,*M;
    bool encontrada = false;
    int xk, yk;


    X = new int[N*N];
    Y = new int[N*N];
    M = new int[N*N];

    k = 1;
    X[k] = xentrada;// 1
    Y[k] = yentrada;// 1
    xk = X[k];
    yk = Y[k];

    maze[xk][xk] = 1; // comprobar su funcionamiento
    //salida por pantalla de prueba
    cout<<"posicion de incio laberinto: "<< maze[xk][xk]<<endl;

    M[k] = 0;

    while(k > 0 && encontrada == false){
        if(M[k] < 4){
            M[k] = M[k] + 1;
            //prueba
           // cout<<"Vamos a ver si entra "<<M[k]<<endl;
            siguienteCandidato(X,Y,M,k);
            xsig = X[k];
            ysig = Y[k];

            cout<<"X: "<<xsig<<", Y: "<<ysig<<", M:"<<M[k]<<endl;
            //si es factible
            if( factible(maze, xsig, ysig) == true){
                X[k+1] = xsig;
                Y[k+1] = ysig;
                if(X[k+1] == xsalida && Y[k+1] == ysalida){
                 //   cout<<imprimirCamino(X,Y,k+1);
                 cout<<"Se ha encontrado la salida"<<endl;
                    encontrada = true;
                }else{
                    k = k + 1;
                    xk = X[k];
                    yk = Y[k];
                    maze[xk][yk] = 1;
                    M[k] = 0;
                    cout<<"esle ultimo"<<endl;
                }//fin
            }//fin factible
        }else{
            xk = X[k];
            yk = Y[k];
            maze[xk][yk] = 0;
            M[k] = 0;
            k = k -1;
        }//fin condicion Mk > 4
    }//fin while

    for(int r = 0; r<N; r++){
        cout<<"El valor de X["<<r<<"]: "<<X[r]<<endl;
        cout<<"El valor de Y["<<r<<"]: "<<Y[r]<<endl;
    }
}

//FUNCIÓN SIGUIENTE CANDIDATO
void siguienteCandidato(int *X, int *Y, int *M, int k)
{

    if(M[k]==1){
        Y[k] = Y[k] + 1;
        cout<<"entra derecha"<<endl;
    }
    if(M[k]==2){
        Y[k] = Y[k] - 1;
        X[k] = X[k] + 1;
        cout<<"entra abajo"<<endl;
    }
    if(M[k]==3){
        Y[k] = Y[k] - 1;
        X[k] = X[k] - 1;
        cout<<"entra izquierda"<<endl;
    }
    if(M[k]==4){
        Y[k] = Y[k] - 1;
        cout<<"entra arriba"<<endl;
    }
}


//función factible
bool factible(int **maze, int xsig, int ysig){

    if(xsig > N-1 || ysig > N-1){
        return false;

    }else{
        if(maze[xsig][ysig] > 1){
            cout<<"\nEntra en funcion factible devuelve false!!!!! "<<endl;
            return false;
        }else{
            cout<<"\nEntra en funcion factible devuelve true!!!!! "<<endl;
            return true;
        }
    }
}


































































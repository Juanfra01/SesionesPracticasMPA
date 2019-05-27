#include <iostream>

using namespace std;

#define N 5

int **crearLaberinto(int);
void imprimirLaberinto(int**);
void funcionLaberinto(int**,int,int,int,int);
void siguienteCandidato(int*, int*, int*, int, int, int);
bool factible(int**,int,int,int,int);



int main()
{
    int **laberinto;
  //  int n=5;

    laberinto = crearLaberinto(N);
    imprimirLaberinto(laberinto);

    funcionLaberinto(laberinto,0,0,2,2);

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

    cout<<"xk: "<<xk<<" yk: "<<yk<<endl;

    maze[xk][yk] = 1;


    if(xentrada > ysalida){
        k=0;
        encontrada = true;
        cout<<"La posicion no se puede Hallar con los movimientos descritos."<<endl;
    }
     if(yentrada > ysalida){
        k=0;
        encontrada = true;
        cout<<"La posicion no se puede Hallar con los movimientos descritos."<<endl;
    }


    //salida por pantalla de prueba
    cout<<"posicion de incio laberinto: "<< maze[xk][xk]<<endl;

    M[k] = 0;
    while(k > 0 && encontrada == false){
        if(M[k] < 3){
            M[k] = M[k] + 1;
            //prueba
           // cout<<"Vamos a ver si entra "<<M[k]<<endl;
            siguienteCandidato(X,Y,M,k,xsalida,ysalida);
            xsig = X[k];
            ysig = Y[k];

            cout<<"X: "<<xsig<<", Y: "<<ysig<<", M:"<<M[k]<<endl;
            //si es factible
            if( factible(maze, xsig, ysig, xsalida, ysalida) == true){
                X[k+1] = xsig;
                Y[k+1] = ysig;
                if(X[k+1] == xsalida && Y[k+1] == ysalida){
                    cout<<"Se ha encontrado la salida"<<endl;
                    maze[xsalida][ysalida] = 1;
                    encontrada = true;
                }else{
                    k = k + 1;//siguente nivel
                    xk = X[k];
                    yk = Y[k];
                    maze[xk][yk] = 1;
                    M[k] = 0;
                    //cout<<"esle ultimo"<<endl;
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

    for(int r = 1; r<N; r++){
        cout<<"El valor de X["<<r<<"]: "<<X[r]<<endl;
        cout<<"El valor de Y["<<r<<"]: "<<Y[r]<<endl;
    }
}

//FUNCIÓN SIGUIENTE CANDIDATO
void siguienteCandidato(int *X, int *Y, int *M, int k, int xsalida, int ysalida)
{
    if(M[k]==1){
        Y[k] = Y[k] + 1;
        cout<<"derecha "<<endl;
        cout<<"Valor de Y[k] "<<Y[k]<<" ||Valor de ysalida]: "<<ysalida<<endl;
    }
    if(M[k]==2){
        Y[k] = Y[k] - 1;
        X[k] = X[k] + 1;
        cout<<"abajo"<<endl;
    }
    if(M[k]==3){
        Y[k] = Y[k] + 1;
        cout<<"diagonal"<<endl;
    }
}


//función factible
bool factible(int **maze, int xsig, int ysig, int xsalida, int ysalida){

  if(xsig > N-1 || ysig > N-1){
        return false;

    }else{
        if( xsig > xsalida ) {
            cout<<"\nEntra en funcion factible  de Xsig devuelve false!!!!! "<<endl;
            return false;
        }else if(ysig > ysalida ){
			  cout<<"\nEntra en funcion factible de ysig devuelve false!!!!! "<<endl;
            return false;
		}
		else{
            cout<<"\nEntra en funcion factible devuelve true!!!!! "<<endl;
            return true;
        }
    }
}












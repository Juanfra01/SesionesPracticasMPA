#include <iostream>
#include <stack>

using namespace std;

#define N 5

int **crearLaberinto(int);
void imprimirLaberinto(int**);
int funcionLaberinto(int**,int,int,int,int);
void siguienteCandidato(int*, int*, int*, int, int, int);
bool factible(int**,int,int,int,int);



int main()
{
    int **laberinto;
  //  int n=5;
    int contador = 0;

    laberinto = crearLaberinto(N);
    imprimirLaberinto(laberinto);

    // funcionLaberinto(laberinto,0,0,2,2);
    contador += funcionLaberinto(laberinto,0,0,2,1);

    cout<<endl;
    cout<<"Total ncaminos: "<<contador<<endl;

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
int funcionLaberinto(int **maze, int xentrada, int yentrada, int xsalida, int ysalida)
{
    int k,xsig,ysig;
    int *X,*Y,*M;
    int total =0;
    int xk, yk;
    stack <int>pilax;//declaramos la pilax
    stack <int>pilay;//declaramos la pilay


    X = new int[N*N];
    Y = new int[N*N];
    M = new int[N*N];

    k = 1;
    X[k] = xentrada;// 1
    Y[k] = yentrada;// 1
    xk = X[k];
    yk = Y[k];

    maze[xk][yk] = 1;
    pilax.push(xentrada);
    pilay.push(yentrada);


    M[k] = 0;
    while(k != 0){
      //  cout<<"\nk: "<<k<<endl;
       // cout<<"M[k]: "<<M[k]<<endl;
        if(M[k] < 3){
            M[k] = M[k] + 1;
            siguienteCandidato(X,Y,M,k,xsalida,ysalida);
            xsig = X[k];
            ysig = Y[k];
            //si es factible
            if( factible(maze, xsig, ysig, xsalida, ysalida) == true){
                X[k+1] = xsig;
                Y[k+1] = ysig;
                if(X[k+1] != xsalida || Y[k+1] != ysalida){//SI NO COINCIDEN LAS COORDENADAS SIGUIENTES CON LAS FINALES ENTRA EN EL IF
                    //APILAMOS LAS COORDENADAS
                    pilax.push(xsig);
                    pilay.push(ysig);
                    cout<<"\n("<<X[k]<<","<<Y[k]<<")"<<endl;
                    k+=1;
                    xk = X[k];
                    yk = Y[k];
                    maze[xk][yk] = 1;
                    M[k] = 0;
                }else{
                    cout<<"\n("<<X[k]<<","<<Y[k]<<") ENCONTRADA"<<endl;
                    maze[xsalida][ysalida] = 1;
                    total +=1;//contador de caminos posibles
                    //SE DESAPILA
                    X[k] = pilax.top();
                    pilax.pop();
                    Y[k] = pilay.top();
                    pilay.pop();
                    cout<<"Valores sacados de la pila "<<X[k]<<", "<<Y[k]<<endl;
                    cout<<"Valor en salida de k: "<<k<<endl<<endl;
                }//fin
            }//fin factible
        }else{
            xk = X[k];
            yk = Y[k];
            M[k] = 0;
            k = k -1;
        }//fin
    }//fin while

    return total;
}

//FUNCIÓN SIGUIENTE CANDIDATO
void siguienteCandidato(int *X, int *Y, int *M, int k, int xsalida, int ysalida)
{
    if(M[k]==1){
        Y[k] = Y[k] + 1;
        cout<<"right  ";
    }
    if(M[k]==2){
        Y[k] = Y[k] - 1;
        X[k] = X[k] + 1;
        cout<<"down ";
    }
    if(M[k]==3){
        X[k] = X[k] + 1;
        Y[k] = Y[k] + 1;
        cout<<"diagonal ";
    }
}


//función factible
bool factible(int **maze, int xsig, int ysig, int xsalida, int ysalida){

  if(xsig > N-1 || ysig > N-1){
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












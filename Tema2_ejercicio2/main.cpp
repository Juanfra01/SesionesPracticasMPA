#include <iostream>

#define N 5

using namespace std;
int **crearLaberinto(int);
void imprimirLaberinto(int**);
int ncaminos(int**,int,int);

int main()
{
    int **laberinto;
    int sol = 0;

    laberinto = crearLaberinto(N);
    imprimirLaberinto(laberinto);
    sol = ncaminos(laberinto,1,3);

    cout<<endl;
    imprimirLaberinto(laberinto);

    cout<<"\nSolucion: "<<sol;

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
            maze[i][j] = 1;
        }
    }

    maze[1][3] = 3;

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

int ncaminos(int **maze,int x, int y)
{
    if(x == 0 || y == 0){
        return 1;
    }else{
        return ncaminos(maze, x - 1, y) + ncaminos(maze,x , y -1 );
    }
}

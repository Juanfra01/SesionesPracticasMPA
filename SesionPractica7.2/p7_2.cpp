//JUAN FRANCISCO TORRES MARTÍNEZ alu80
//ALEJANDRO GALLEGO LÓPEZ alu37
#include <iostream>

using namespace std;

// DEFINICION DE FUNCIONES
double Mochila(int M, int n, int *P, double *V, int *Vobjetos);

int main()
{
    // DECLARAMOS E INICIALIZAMOS LAS VARIABLES
    int i = 0, M = 0, n = 0, *Vobjetos;
    double ValorMaximo = 0;
    int *P;
    double *V;

    // PIDO POR PANTALLA LOS DATOS
     cout << "Peso maximo de la mochila:";
     cin >> M;
     cout << endl;
     cout << "Total de objetos:";
     cin >> n;
     cout << endl;

    // RESERVO MEMORIA PARA LOS VECTORES DE TAMAÑO n
     P = new int[n + 1];
     V = new double[n + 1];

     P[0] = 0;
     for (i = 1; i <= n; i++)
     {
         cout << "Peso del objeto " << i << ":";
         cin >> P[i];
         cout << endl;
     }

     V[0] = 0;
     for (i = 1; i <= n; i++)
     {
         cout << "Valor del objeto " << i << ":";
         cin >> V[i];
         cout << endl;
     }

 /*   M = 15;
    n = 4;*/

    Vobjetos = new int[n + 1];
    for (i = 0; i < n + 1; i++)
    {
        Vobjetos[i] = 0;
    }
/*
    int P[n + 1] = {0, 8, 3, 6, 2};
    double V[n + 1] = {0, 40, 18, 24, 16};*/

    // LLAMAMOS A LA FUNCIÓN MOCHILA
    ValorMaximo = Mochila(M, n, P, V, Vobjetos);

    // MOSTRAMOS EL RESULTADO POR PANTALLA
    cout << "Objetos en la mochila:";
    for (i = 0; i < n + 1; i++)
    {
        if(Vobjetos[i]!=0){
            cout << " " << Vobjetos[i];
        }
    }
    cout << endl;

    cout << "Valor maximo que puede llevar: " << ValorMaximo << endl;


    delete[]P;
    delete[]V;
    delete[]Vobjetos;
    return 0;
}

// FUNCION MOCHILA
double Mochila(int M, int n, int *P, double *V, int *Vobjetos)
{
    // INICIALIZAMOS LAS VARIABLES
    int i = 0, j = 0;

    // RESERVO MEMORIA PARA LA MATRIZ
    double **T = new double *[n + 1];
    for (int i = 0; i < n + 1; ++i)
    {
        T[i] = new double[M + 1];
    }

    for (i = 0; i < M + 1; i++)
    {
        T[0][i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        T[i][0] = 0;
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= M; j++)
        {
            if (P[i] > j)
            {
                T[i][j] = T[i - 1][j];
            }
            else
            {
                T[i][j] = (double)max(T[i - 1][j], V[i] + T[i - 1][j - P[i]]);
            }
           // cout << T[i][j] << " ";
        }
       // cout << endl;
    }


   //  cout<<"----------------------------"<< endl;
    //Asignación del valor
    j =M;
    for (i = n; i >= 1; i--)
    {
       //   cout << T[i][j] << " ";
           if(T[i][j] != T[i-1][j]){

            Vobjetos[i] = i;
            if(Vobjetos[i]==Vobjetos[i-1]){
                Vobjetos[i]-=i;
            }
            j-=P[i];
        }
       // cout << endl;
    }
/*
    for(i=1;i<n;i++){
        cout<<"Vobjeto: "<<Vobjetos[i]<<endl;
    }
*/
    return T[n][M];
}



/*
Juan Francisco Torres Martínez - alu80
Alejandro Gallego López - alu37
Santiago Moltó Martínez - alu55
*/
#include <iostream>

using namespace std;

#define negativeINF -999999

int numeroTotalObjetos();
double *introducirPesos(int);
double *introducirValores(int);
void maleta(int,double,double*,double*,double*,int,double*,double&);
double calcularSuma(double*,double*,int);


int main()
{
    double *pesos,*valores,*x,*xopt;
    int n,k;
    double M = 10.0;
    double vopt;

    vopt = negativeINF;
    k = 1;

    n = numeroTotalObjetos();

    //Reservamos memoria
    x = new double[n + 1];
    xopt = new double[n + 1];

    pesos = introducirPesos(n);
    valores = introducirValores(n);


    maleta(n, M, pesos, valores, x, k, xopt, vopt);
    /*
    for(int i=1;i<=n;i++){
        cout<<"pesos("<<i<<"): "<<valores[i]<<endl;
    }*/

      cout << "\nOBJETOS A INTRODUCIR EN LA MALETA" << endl;
    for (int i = 1; i <= n; i++)
    {
        if (xopt[i] == 1)
        {
            cout << i << ": " << pesos[i] << "kg - Valor: "
                 << valores[i] << endl;
        }
    }

    cout << "\nPeso: " << calcularSuma(xopt, pesos, n);
    cout << "\nValor: " << vopt << endl;

    cout << "\nOBJETOS QUE QUEDAN FUERA:";
    for (int i = 1; i <= n; i++)
    {
        if (xopt[i] == 0)
        {
            cout << " " << i;
        }
    }
    cout << endl;



    delete[]pesos;
    delete[]valores;
    delete[]x;
    delete[]xopt;
    return 0;
}


//Introducimos el total de objetos
int numeroTotalObjetos(){
    int n;
    cout<<"Introduce el total de objetos (n):"<<endl;
    cin>> n;
    while(n<0){
        cout<<"\nIntroduce el total de objetos (n):";
        cin>> n;
    }
    return n;
}

//Introducir Pesos
double *introducirPesos(int n){
    double *pesos;
    pesos = new double[n + 1];
    cout << "PESOS:" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << "Objeto " << i << ":";
        cin >> pesos[i];
        cout << endl;
    }
    return pesos;
}

//Introducir Valores
double *introducirValores(int n){
    double *valores;
    valores = new double[n + 1];
    cout << "VALORES:" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << "Objeto " << i << ":";
        cin >> valores[i];
        cout << endl;
    }
    return valores;
}


void maleta(int n, double m, double *p, double *v, double *x, int k, double *xopt, double &vopt)
{
    double valor = 0;
    int i = 1;
    int j = 1;
    double peso = 0;

    if (k <= n)
    {
        for (i = 0; i <= 1; i++)
        {
            x[k] = i;
            peso = calcularSuma(x, p, k);
            if (peso <= m)
            {
                if (k == n)
                {
                    valor = calcularSuma(x, v, k);
                    if (valor > vopt)
                    {
                        for (j = 1; j <= n; j++)
                        {
                            xopt[j] = x[j];
                        }
                        vopt = valor;
                    }
                }
                else
                {
                    maleta(n, m, p, v, x, k + 1, xopt, vopt);
                }
            }
        }
    }
}

//Función calcular suma
double calcularSuma(double *x, double *v, int k)
{
    double suma = 0;
    int i = 0;

    while (i <= k)
    {
        if (x[i] == 1)
        {
            suma = suma + v[i];
        }
        i++;
    }

    return suma;
}



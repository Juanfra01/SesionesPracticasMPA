#include <iostream>

using namespace std;

#define negativeINF -9999999

double CalcularSuma(double *x, double *v, int k)
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

void Maleta(int n, double m, double *p, double *v, double *x, int k, double *xopt, double &vopt)
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
            peso = CalcularSuma(x, p, k);
            if (peso <= m)
            {
                if (k == n)
                {
                    valor = CalcularSuma(x, v, k);
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
                    Maleta(n, m, p, v, x, k + 1, xopt, vopt);
                }
            }
        }
    }
}

int main()
{
    double *pesos, *valores, *x, *xopt;
    int n;
    int k;
    double M = 10.0;
    double vopt;

    vopt = negativeINF;
    k = 1;

    cout << "Introduce el total de objetos (n):" << endl;
    cin >> n;

    //RESERVA DE MEMORIA
    pesos = new double[n + 1];
    valores = new double[n + 1];
    x = new double[n + 1];
    xopt = new double[n + 1];

    cout << "PESOS:" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << "Objeto " << i << ":";
        cin >> pesos[i];
        cout << endl;
    }

    cout << "VALORES:" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << "Objeto " << i << ":";
        cin >> valores[i];
        cout << endl;
    }

    Maleta(n, M, pesos, valores, x, k, xopt, vopt);

    cout << "\nOBJETOS A INTRODUCIR EN LA MALETA" << endl;
    for (int i = 1; i <= n; i++)
    {
        if (xopt[i] == 1)
        {
            cout << i << ": " << pesos[i] << "kg - Valor: "
                 << valores[i] << endl;
        }
    }

    cout << "\nPeso: " << CalcularSuma(xopt, pesos, n);
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
    return 0;
}



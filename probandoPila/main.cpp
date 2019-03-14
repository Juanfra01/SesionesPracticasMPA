#include <iostream>
#include <stack>
#include <stdlib.h>

using namespace std;

int main()
{
    stack <int> pila;
    int dato,i;

    cout << "Apilando datos" << endl;
    cout << "--------------" << endl;
    for (i=1; i<=5; i++){
    cout << "Introduce dato: ";
    cin >> dato;
    pila.push(dato);
    }
    cout << endl;
    cout << "Num. elementos de la pila: ";
    cout << pila.size() << endl << endl;
    cout << "Desapilando datos" << endl;
    cout << "-----------------" << endl;
    while (! pila.empty() )
    {
    dato = pila.top();
    cout << dato << endl;
    pila.pop();
    }
    cout << endl;
    system("pause");

    return 0;
}

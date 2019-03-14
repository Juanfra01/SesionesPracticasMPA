#include <iostream>
#include <stack>

using namespace std;

int pedirDatos(string);
void imprimir(string,int);
int programa1(int,int);

int main()
{
    stack <int> pila;
    int x = 5;
    int y = 4;
    int dato=0;
    int i=1, j=1;

    cout << "Introduce valores de x:";
    cin >> x;
    cout << "\nIntroduce valores de y:";
    cin >> y;

    while(x > 1){
        pila.push(dato=(-x+y));
         cout<<i<<")Dato "<<dato<<endl;
        x = x - 1;
        y = y + 2;
        cout<<i<<")Valores "<<x<<" "<<y<<endl<<endl;
        i++;
    }

    while(! pila.empty()){
        y = y + pila.top();
        cout<<j<<")Valor de y: "<<y<<endl;
        pila.pop();
        j++;
    }

    cout << "\nResultado: " << y << endl;
}

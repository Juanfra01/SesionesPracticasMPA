#include <iostream>
#include <stack>

using namespace std;

int pedirDatos(string);
void imprimir(string,int);
int programa1(int,int);

int main()
{
    stack <int> pila;
    int a = 0;
    int b = 0;
    int a0,b0;

    int sol = 0;

    cout << "Introduce valores de a:";
    cin >> a;
    cout << "\nIntroduce valores de b:"<<endl;
    cin >> b;
    a0 = a;
    b0 = b;

    while(a0 >= 3){
        pila.push(+a0);
        a0 /= 3;
        b0 -= 2;
    }

    a0 = a0 + b0;

    while(! pila.empty()){
        a0 = a0 + pila.top();
        pila.pop();
    }

    cout << "\nResultado: " << a0 << endl;
}

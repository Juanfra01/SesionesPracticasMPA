#include <iostream>
#include <stack>

using namespace std;


int programa3(int a,int b){
    stack <int> pila;
    int a0,b0;
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

    return a0;
}

int main()
{

    int a = 0;
    int b = 0;

    cout << "Introduce valores de a:";
    cin >> a;
    cout << "\nIntroduce valores de b:";
    cin >> b;


    cout << "\nResultado: " << programa3(a,b) << endl;
}

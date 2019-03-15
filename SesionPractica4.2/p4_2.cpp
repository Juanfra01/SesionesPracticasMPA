#include <iostream>
#include <stack>

using namespace std;


int programa2(int x,int y){
    stack <int> pila;
    int x0,y0;
    int z=0;
    x0 = x;
    y0 = y;

     while(y0 != 0 ){
            pila.push(y0);
            y0 /= 2;
        }
        cout<<endl;
        z = 1;
        while(! pila.empty()){
            y0 = pila.top();
            z *=z;
            if(y0 %2 !=0){
                z *=x0;
            }
            pila.pop();
        }
    return z;
}

int main()
{
    int x = 0;
    int y = 0;
    int x0,y0;

    cout << "Introduce valores de x:";
    cin >> x;
    cout << "\nIntroduce valores de y:";
    cin >> y;

    if(y<0){
        cout<<"\nResultado: Error"<<endl;
    }else{

        cout <<"Resultado: "<<programa2(x,y)<<endl;
    }
}


#include <iostream>

using namespace std;
int introducirValor(string);
int funcionMultiplicacion(int,int);

int main()
{
    int x,y, resultado;

    string valor1 = "primer";
    string valor2 = "segundo";

    cout<<"3. MULTIPLICACION"<<endl;
    cout<<"-----------------"<<endl;
    x = introducirValor(valor1);
    y = introducirValor(valor2);

    cout<<"Traza"<<endl;
    resultado = funcionMultiplicacion(x,y);

 //   cout<<"Valor: "<<valor1<<":"<<x<<endl;
 //   cout<<"Valor: "<<valor2<<":"<<y<<endl;
 //   resultado = x/y;

    cout<<"\nEl resultado es: "<<resultado<<endl;

    return 0;
}

// FUNCION DONDE SE INTRODUCEN LOS VALORES
int introducirValor(string valor){
    int num;
    cout<<"Introduce "<<valor<<" numero:";
    cin>>num;

    return num;
}

//FUNCION MULTIPLICACION RECURSIVA
int funcionMultiplicacion(int x, int y){
    int suma=0,divisor=0,multi=0;
    int r = x;
    multi = y;

    while(r != 0){
        int i = 1;

        cout<<i<<">multiplicacion<"<<r<<","<<multi<<">"<<endl;
        r = r/2;
        multi *= 2;
        if(r%2!=0){
            suma += multi;
        }
      //  suma += multi;
        i++;
    }

    return suma;
}

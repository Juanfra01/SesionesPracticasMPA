#include <iostream>

using namespace std;
int introducirValor(string);
int funcionRecursiva(int,int);



int main()
{
    int x,y, resultado;

    string valor1 = "x";
    string valor2 = "y";

    cout<<"2. FUNCION F"<<endl;
    cout<<"------------"<<endl;

    x = introducirValor(valor1);
    y = introducirValor(valor2);

     // 2. FUNCION RECURSIVA
    resultado = funcionRecursiva(x,y);

    if(x < 0){
        cout<<"Error"<<endl;
    }else{
        cout<<"Traza"<<endl;
        cout<<"F<"<<x<<","<<y<<">"<<endl<<endl;
        cout<<"El resultado es: "<<resultado<<endl;
    }
    return 0;
}

// FUNCION DONDE SE INTRODUCEN LOS VALORES
int introducirValor(string x){
    int num;
    cout<<"Introduce valor "<<x<<":";
    cin>>num;

    return num;
}

//FUNCIÓN RECURSIVA
int funcionRecursiva(int x, int y){
    int result = 0;

     if(x == 0){
        result = 1;
     }else
     if(x == 1){
        result = 2*y;
     }else
     if(x >= 2){
        result = (2*y)*funcionRecursiva(x-1,y) -2*(x-1)*funcionRecursiva(x-2,y);
     }else{
       result = -1;
     }
    return result;
}

#include <iostream>

using namespace std;
int introducirValor(string);
float funcionRecursiva(int,float);



int main()
{
    int x,y;
    float resultado;

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
       // cout<<"F("<<x<<","<<y<<")"<<endl<<endl;
        cout<<"El resultado es: "<<resultado<<endl;
    }
    return 0;
}

// FUNCION DONDE SE INTRODUCEN LOS VALORES
int introducirValor(string x){
    int num;
    cout<<"Introduce valor "<<x<<":";
    cin>>num;
    cout<<endl;

    return num;
}

//FUNCIÓN RECURSIVA
float funcionRecursiva(int x, float y){
    float result = 0;
    cout<<"F("<<x<<","<<y<<")"<<endl;

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

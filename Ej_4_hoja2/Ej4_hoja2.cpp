//Ejercicion 4 de la hoja 2 de ejercicios
//Este es el apartdado b donde implementamos la funcion recursiva en iterativa.
#include <iostream>
using namespace std;

int main(){
    int a, b;
    cout<<"Valor de a: "<<endl;
    cin>>a;
    cout<<"Valor de b: "<<endl;
    cin>>b;

    while(a!=b){
        if(a>b){
            a-=b;
        }else{
            b-=a;
        }
    }
    cout<<"Valor de a: "<<a<<endl;
    cout<<"Valor de b: "<<b<<endl;

    return 0;
}

/*
using namespace std;
int pedirDatos(string);
int euclides(int a, int b);
//FORMA RECURSIVA
int main()
{

    int a,b;
    string valor1 ="a";
    string valor2 = "b";

    a=pedirDatos(valor1);
    b=pedirDatos(valor2);


    cout<<"Valor de "<<valor1<<":"<<a<<endl;
    cout<<"Valor de "<<valor2<<":"<<b<<endl;
   // euclides(a,b);

    cout<<"El valor de a es: "<<euclides(a,b)<<endl;


    return 0;
}

int pedirDatos(string x){
    int valor;
    cout<<"Introduce el valor de "<<x<<": "<<endl;
    cin>>valor;
    return valor;
}

int euclides(int a, int b){

    if(a==b){

        return a;
    }else{
         if(a>b){
            return euclides(a-b,b);
        }else{
            return euclides(a,b-a);
        }
    }
}
*/

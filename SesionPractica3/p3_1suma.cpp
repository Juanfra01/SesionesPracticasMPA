#include <iostream>
#include <stdlib.h>
#include <time.h>


using namespace std;

int pedirDatos();
//void sumarDigitos(int);
int sumarDigitosRecursiva(int);


int main()
{
    int num, resultado=0;
    num = pedirDatos();
    cout<<"Traza"<<endl;
   // sumarDigitos(num);


    if(num<0){
        cout<<"1>sumadigitos<"<<num<<">"<<endl;
        cout<<"\nEl resultado es: -1"<<endl;
    }else{
        resultado = sumarDigitosRecursiva(num);
        cout<<"\nEl resultado es: "<<resultado<<endl;
    }

    return 0;
}


int pedirDatos(){
    int numero;
    cout<<"1. SUMA DIGITOS"<<endl;
    cout<<"---------------"<<endl;
    cout<<"Introuduce numero:";
    cin>>numero;

    return numero;
}

int sumarDigitosRecursiva(int num){
    int i=1;
    if(num == 0){
        return 0;
    }else{
        cout<<i<<">sumadigitos<"<<num<<">"<<endl;
        return  sumarDigitosRecursiva(num/10) + num%10;
    }
}

/*
void sumarDigitos(int num){
    int r,s,i;
    s = 0;
    i = 1;

    if(num<0){
        cout<<"Traza"<<endl;
        cout<<i<<">"<<"sumadigitos<"<<num<<">"<<endl;
        cout<<"El resultado es: -1"<<endl;
    }else{
        cout<<"Traza"<<endl;
        while(num>0){
        r = num %10;
        s = s + r;
      //  cout<<"iteracion:"<<i<<"valor de s:"<<s<<endl;
        cout<<i<<">"<<"sumadigitos<"<<num<<">"<<endl;
        i++;
        num = num / 10;
        }
        cout<<"\nEl resultado es: "<<s<<endl;
    }

}
*/

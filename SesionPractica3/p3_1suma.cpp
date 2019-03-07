#include <iostream>
#include <stdlib.h>
#include <time.h>


using namespace std;

int pedirDatos();
void sumarDigitos(int);
//int *convertirIntToArray(int);

int main()
{
    int num;
    num = pedirDatos();
    sumarDigitos(num);



   //vec = convertirIntToArray();

  //  cout<<"\nEl numero introudcido es:"<<num<<endl;
 //   cout<<"La suma del numero es:"<<s;



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

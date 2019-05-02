/*
Juan Francisco Torres Martínez - alu80
Alejandro Gallego López - alu37
Santiago Moltó Martínez - alu55
*/
//Juan Francisco Torres Martínez - alu80
#include <iostream>
#include<stdio.h>
#include <stdlib.h>


using namespace std;

int pesoMaximoMochila();
int numeroTotalObjetos();
float *inElementos(int,string);
void printVector(float*, int);
float maximo(float,float);
float mochila(int, float*, float*, int);

int main()
{
    int pesoMax;
    int totalObj;
    float *pObj;
    float *vObj;
    float vMax;
    string peso = "Peso";
    string valor = "Valor";

    pesoMax = pesoMaximoMochila();
    totalObj = numeroTotalObjetos();
    pObj = inElementos(totalObj,peso);
    vObj = inElementos(totalObj,valor);

    //salidas de prueba
   /* cout<<"\nPeso Maximo de la mochila: "<<pesoMax<<endl;
    cout<<"El numero total de objetos es: "<<totalObj<<endl;
    printVector(pObj,totalObj);
    printVector(vObj,totalObj);*/


    vMax = mochila(pesoMax,pObj,vObj,totalObj);

    cout<<"\nValor maximo que puede llevar: "<<vMax<<endl;

    delete[]pObj;
    delete[]vObj;
    return 0;
}

//Introducimos el total del peso de la mochila
int pesoMaximoMochila(){
    int pMax;
    cout<<"Peso maximo de la mochila:";
    cin>>pMax;
    while(pMax<0){
        cout<<"Peso maximo de la mochila:";
        cin>>pMax;
    }

    return pMax;
}

//Introducimos el total de objetos
int numeroTotalObjetos(){
    int n;
    cout<<"\nTotal de objetos:";
    cin>> n;
    while(n<0){
        cout<<"\nTotal de objetos:";
        cin>> n;
    }

    return n;
}

//Rellenamos el vector
float *inElementos(int tamanyo,string nombre){
    float *vecPesosObj;
    vecPesosObj = new float[tamanyo+1];
    int j = 1;
    for(int i=0;i<tamanyo;i++){
        cout<<"\n"<<nombre<<" del objeto "<<j<<":";
        cin>>vecPesosObj[i];
        while(vecPesosObj[i]<0){
            cout<<"\n"<<nombre<<" del objeto "<<j<<":";
            cin>>vecPesosObj[i];
        }

        j++;
    }
  //  cout<<endl;
    return vecPesosObj;
 }


//Imprimimos el vector
void printVector(float *vec, int tamanyo){
    cout<<"Vector: ";
    for(int i=0;i<tamanyo;i++){
        cout<<vec[i];
        cout<<" ";
    }
    cout<<endl;
 }

float maximo(float a, float b){
    return (a > b)? a:b;
}

float mochila(int pMax, float *pObjeto, float *vObjeto, int n){
    //Caso Base
    if(n == 0 || pMax == 0){
        return 0;
    }
    if(pObjeto[n-1]> pMax){
        return mochila(pMax, pObjeto, vObjeto, n-1);
    }else{
        return maximo(vObjeto[n-1] + mochila(pMax-pObjeto[n-1], pObjeto, vObjeto, n-1), mochila(pMax, pObjeto, vObjeto, n-1));
    }
}

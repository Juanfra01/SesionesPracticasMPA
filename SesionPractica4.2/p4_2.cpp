#include <iostream>
#include <stack>

using namespace std;

int pedirDatos(string);
void imprimir(string,int);
int programa1(int,int);

int main()
{
    stack <int> pila;
    int x = 0;
    int y = 0;
    int x0,y0;
    int z=0;
  /*  int i=1;
    int j=1;
    int h=1;
*/
    cout << "Introduce valores de x:";
    cin >> x;
    cout << "\nIntroduce valores de y:";
    cin >> y;
    x0 = x;
    y0 = y;


    if(y<0){
        cout<<"Resultado: Error";
    }else{
        while(y0 != 0 ){
            pila.push(y0);
       //     cout<<i<<")Valor de y0--> "<<y0<<endl;
            y0 /= 2;
        //    i++;
        }
        cout<<endl;
        z = 1;
        while(! pila.empty()){
            y0 = pila.top();
            z *=z;
        //    cout<<j<<")Desapilar de z0: "<<z<<endl;
            if(y0 %2 !=0){
                z *=x0;
        //    cout<<h<<")Dento del if. Valor de z: "<<z<<" || Valor de x0: " <<x0<<endl;
       //     h++;
            }
            //cout<<h<<")salida del if: "<<z<<" " <<x0<<endl;
            pila.pop();
         //   j++;

        }
        cout <<"Resultado: "<<z;
    }
}

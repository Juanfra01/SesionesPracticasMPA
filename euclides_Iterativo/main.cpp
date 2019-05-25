#include <iostream>

using namespace std;

int main()
{
    int a = 21;
    int b = 12;

    while(a!=b){
        if(a>b){
            a-=b;
        }else{
            b-=a;
        }
    }


    cout<<"El resultado es: "<<a<<endl;

    return 0;
}

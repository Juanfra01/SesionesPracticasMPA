#include <iostream>

using namespace std;

int main()
{
     int a, b;
     int b0,a0;

    cout<<"Valor de a: "<<endl;
    cin>>a;
    cout<<"Valor de b: "<<endl;
    cin>>b;

    b0 = b;
    a0=1;

    while(b0>0){
        b0=b0-1;
    }

    b0=0;

    while(b0!=b){
        a0*=a;
        b0++;
    }

    cout<<"Valor de a: "<<a<<endl;
    cout<<"Valor de b: "<<b<<endl;

    cout<<"Valor de a0: "<<a0<<endl;
    cout<<"Valor de b0: "<<b0<<endl;

    return 0;
}

#include <iostream>

using namespace std;
int digitos(double,int);

int main()
{
    int contador=0;
    double cantidad;
    cout<<"Ingrese un numero entero: ";
    cin>>cantidad;
    
    cout<<digitos(cantidad,contador);
}

int digitos(double cantidad,int contador)
{
    if(cantidad<10)
    {
        return contador+1;
    }
    else
    {
       cantidad=cantidad/10; //le estamos quitando una cifra a la cantidad
        contador = digitos(cantidad,contador+1);
        return contador;
    }
    
    
}
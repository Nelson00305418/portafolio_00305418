/*Elabore una función recursiva que, dado un número entero que se obtiene desde
teclado, realice un conteo como el siguiente:
Suponiendo que el valor ingresado es 3:
1
2
3
2
1*/

#include <iostream>

using namespace std;
//prototipo
int conteo(int,int);
int main()
{
    int numero,contador=1;
    cout<<"Ingrese el numero positivo que desea efectuar el conteo: ";
    cin>>numero;
    
    conteo(numero,contador);
}

int conteo(int numero,int contador)
{
    if(contador<=numero)
    {
        cout<<contador<<endl;
        conteo(numero,contador+1);
        contador=contador-1;
        if(contador>=1)
        cout<<contador<<endl;
    }

}
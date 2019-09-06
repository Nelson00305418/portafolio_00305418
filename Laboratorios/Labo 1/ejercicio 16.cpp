/*) Solicite diez enteros al usuario, almacénelos en un arreglo y finalmente calcule su suma
y promedio. Utilice el ciclo for para controlar el flujo del programa.
*/

#include <iostream>

using namespace std;

int main()
{
    double arreglo[10],acumulador=0;
    double promedio;
    
    for(int i=0;i<10;i++)
    {
        cout<<"Ingrese el elemento numero: "<<i+1<<": ";
        cin>>arreglo[i];
        acumulador=acumulador+arreglo[i];
    }
    
    cout<<"La suma de todos los elementos del arreglo es: "<<acumulador<<endl;
    promedio=acumulador/10;
    cout<<"El promedio de todos los elementos es: "<<promedio;
}

/*Dados dos números enteros llamados mayor y menor, obtener el máximo común divisor
(mcd) de ambos por el método de Euclides. Para resolver este problema se procede así:
a) se realiza la división entera del mayor entre el menor, b) si el residuo es cero, el mcd
está en la variable llamada menor, despliega el resultado y termina el programa, c)
pero si el residuo no es cero, el valor de menor pasa a mayor y el valor de residuo pasa
a menor, d) repetir el paso a.*/

#include <iostream>

using namespace std;

//prototipo 
void euclides(int, int);

int main()
{
    int mayor,menor,auxiliar;
    cout<<"Ingrese un numero entero mayor que cero: ";
    cin>>mayor;
    
    cout<<"Ingrese otro numero entero mayor que cero: ";
    cin>>menor;
    
    if(mayor<menor)
    {
        auxiliar = mayor;
        mayor = menor;
        menor = auxiliar;
    }

    //llamada a la funcion recursiva
    euclides(mayor,menor);
}

//funcion recursiva 
void euclides(int mayor,int menor)
{
    int residuo=(mayor%menor);
    if(residuo == 0)
    {
        cout<<"El mcd es: "<<menor;
    }
    else 
    {
        residuo = menor;
        menor= mayor;
        euclides(mayor,menor);
    }
}
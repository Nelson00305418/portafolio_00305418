
/*Implemente una estructura para utilizar números complejos en C++, con campos para
almacenar la parte real y la parte imaginaria. Cree una función que acepte un número
complejo, calcule su conjugada (negar la parte imaginaria y dejar la parte real tal
como está) y devuelva el resultado (otro número complejo).*/

#include <iostream>

using namespace std;
//prototipos


struct complejo {
        int real;
        int imaginaria;
    }numeroComplejo;
    
    //prototipos 
    int conjugada(complejo);
    
int main()
{
    cout<<"Ingrese un numero complejo, primero ingrese la parte real: ";
    cin>>numeroComplejo.real;
    cout<<"Ingrese la parte imaginaria: ";
    cin>>numeroComplejo.imaginaria;
    cout<<"El numero complejo es: "<<numeroComplejo.real;
    if(numeroComplejo.imaginaria>=0){
        cout<<"+"<<numeroComplejo.imaginaria<<"i"<<endl;
    }
    else 
    cout<<numeroComplejo.imaginaria<<"i"<<endl;

   cout<<"La conjugada del complejo es: "<<numeroComplejo.real;
   
   if(numeroComplejo.imaginaria<0)
   cout<<"+"<<conjugada(numeroComplejo)<<"i";
   
   else
   cout<<conjugada(numeroComplejo)<<"i";
}

int conjugada(complejo numeroComplejo)
{
    numeroComplejo.imaginaria = -numeroComplejo.imaginaria;
    return numeroComplejo.imaginaria;
}


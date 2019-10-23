/*Elabore una funcion recursiva que calcule la suma de los numeros 
pares y la suma de los numeros impares contenidos en una lista. la
funcion debe recibir como primer argumento el punto de la lista y 
actualizar otros dos argumentos con las sumas realizadas */

#include <iostream>

using namespace std;

struct nodo
{
    int dato;
    nodo *sig;
};


void llenarLista(nodo**pInicio,int numero)
{
    nodo *nuevo;
    nuevo = new nodo;
    nuevo->dato=numero;
    if(pInicio==NULL) //caso especial si la lista esta vacia 
    {
        *pInicio=nuevo;
        (*pInicio)->sig=NULL;
    }
    else
    {
        //el nuevo nodo apunta hacia el siguiente nodo y amarramos nuestra lsita
        nuevo->sig=*pInicio;
        *pInicio=nuevo;
        //el nuevo nodo pasa a ser la nueva cabeza de la lista y pInicio apunta a el
    }
}

void suma(nodo*pInicio,int *sumaImpar,int *sumaPar)
{
    if(pInicio)
    {
        suma(pInicio->sig,sumaImpar,sumaPar);
        if(pInicio->dato%2==0)
        {
            *sumaPar=*sumaPar+pInicio->dato;
        }
        else
        {
            *sumaImpar=*sumaImpar+pInicio->dato;
        }
    
    }
}

int main()
{
   char respuesta;
    int numero,eliminar;
    struct nodo *pInicio=NULL;
    
    cout<<"Desea ingresar un numero a su lista? (s/n) ";
    cin>>respuesta;
    while(respuesta=='s')
    {
        cout<<"Ingrese el numero: ";
        cin>>numero;
        llenarLista(&pInicio,numero);
        cout<<"Desea ingresar otro numero a su lista (s/n): ";
        cin>>respuesta;
    }
    cout<<endl<<"Imprimiendo los elementos de la lista: ";
    
    //par de llaves ambito local 
    {
        struct nodo *saltarin; //declaro mi puntero auxiliar que me ayudara a recorrer la lista
        saltarin=pInicio; //saltarin apunta al inicio de la lista 
        while(saltarin!=NULL)
            {
             cout<<saltarin->dato<<" "; //imprimo el valor del nodo actual
             saltarin=saltarin->sig; //saltarin salta hacia el siguiente nodo
             }
    }
    
    cout<<endl;
    int sumaPar=0,sumaImpar=0;
    suma(pInicio,&sumaImpar,&sumaPar);
    cout<<"la suma de los pares es: "<<sumaPar;
    cout<<endl<<"La suma de los impares es: "<<sumaImpar;
    
}
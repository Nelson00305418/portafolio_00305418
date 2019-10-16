//ejercicio 8 de la guia 
/* elabore un programa que convierta un numero entero en base 10, a su binario 
equivalente. Guarde los digitos binarios en una lista simple y realice el 
despliegue de los digitos en forma correcta */

#include <iostream>

using namespace std;

struct nodo 
{
    int dato;
    nodo *sig;
};

class miLista
{
    private:
    nodo *pInicio;
    
    //prototipos
    public:
    miLista(); //constructor
    void binario(int);
    void desplegarLista();
};

//sentencias del constructor 
miLista::miLista()
{
    pInicio=NULL;
}

//sentencias metodo de llenado de lista 
void miLista::binario(int decimal)
{
    nodo *nuevo;
    nuevo=new nodo;
    int residuo; //aqui guardaremos el residuo del decimal 
    if(pInicio==NULL && decimal<2)//Caso para la lista vacia y que el numero decimal es menor a 2
    {
        residuo=decimal%2;
        nuevo->dato=residuo;
        pInicio=nuevo;
        pInicio->sig=NULL;
        return; 
    }
    else if(pInicio==NULL) //caso para la lista vacia y con numero decimal mayor o igual a 2
           {
             residuo=decimal%2;
             nuevo->dato=residuo;
             pInicio=nuevo;
             pInicio->sig=NULL;
             binario(decimal/2); //recursion que envia el cociente
           }
             else if(decimal>=2)
                  {
                    residuo=decimal%2;
                    nuevo->dato=residuo;
                    nuevo->sig=pInicio;
                    pInicio=nuevo;
                     binario(decimal/2); //lamada recursiva que envia el cociente
                  }
                    else  //caso base cuando se llega que el cociente es menor que 2
                       {
                        nuevo->sig=pInicio;
                        pInicio=nuevo;
                        nuevo->dato=decimal;
                        }
}


//funcion que me va a desplegar la lista  
void miLista::desplegarLista(void)
{
    nodo *s; //puntero axuliar para recorrer la lista 
    s=pInicio; //s apunta al inicio de la lista 
    cout<<endl<<"El numero en binario es: ";
    while(s!=NULL)
    {
        cout<<s->dato;
        s=s->sig;
    }
}
int main()
{
    miLista numero; //creando al objeto
    int decimal;
    
    cout<<"Ingrese un numero entero: ";
    cin>>decimal;
    numero.binario(decimal);
    numero.desplegarLista();
}

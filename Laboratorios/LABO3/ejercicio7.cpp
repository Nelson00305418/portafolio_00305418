#include <iostream>

using namespace std;
struct nodo
{
    int dato;
    struct nodo *sig;
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

void eliminarNodo(nodo**pInicio,int eliminar)
{
    nodo *p = *pInicio, *q = NULL;
    
    while(p != NULL && p->dato != eliminar)
    { //aqui vamos a saltar hasta llegar al nodo buscado
        q = p;
        p = p->sig;
    }
    
    //esta instruccion se va a hacer media vez el elemento buscado este en la lista
    if(p != NULL)
      {
        if(q != NULL){ //el caso generico para el medio y el final
            q->sig = p->sig;
            delete p; //borramos el nodo 
            eliminarNodo(pInicio,eliminar); //volvemos a llamar para ver si el elemento buscado esta en la lista
        }
        else{ //caso particular para el inicio de la lista 
            *pInicio = p->sig;
            delete p; //borramos el nodo'
            eliminarNodo(pInicio,eliminar); //volvemos a llamar para ver si el elemento buscado esta en la lista
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
    
    cout<<endl<<"que elemento desea eliminar?: ";
    cin>>eliminar;
    eliminarNodo(&pInicio,eliminar);
    
    cout<<endl<<"Imprimiendo su lista con el elemento eliminado: ";
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
}
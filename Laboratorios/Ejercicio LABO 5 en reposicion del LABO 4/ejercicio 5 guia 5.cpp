/*Dada una lista lineal simplemente enlazada, construya un árbol binario de búsqueda a
partir de los valores de la lista. Recorra la lista y vaya copiando cada valor de la misma
en un árbol binario de búsqueda que irá construyendo. Al final, se tiene tanto la lista
como el árbol.
*/

/*BAAAAAAAAAAAANCHOOOOOOOOOOOOON soy el alumno que te dijo que te enviaria un ejercicio de la practica 5
en reposicion a los 2 ejercicios de la practica 4 BAAAAAAAAAAAANCHOOOOOOOOOOOOON*/

#include <iostream>
using namespace std;

//tipo de dato del nodo 
struct nodo{
    int dato;
    nodo *hijoIzq;
    nodo *hijoDer;
};

//tipo de dato de la lista 
struct nodoLista
{
    int dato;
    nodoLista *sig;
};

class ABB{
private:
    nodo *pArbol;
    
    //lista enlazada 
    nodoLista *pInicio;
public:
    ABB(void);
    void operaciones(void);
    void mostrarIn(void);
    void mostrarIn(nodo *);
    void insNodo(int);
    void insNodo(nodo **, int);
    
    
    //metodos de la lista 
    void insertarInicioLista(int dato);
    void mostrarLista(void);
};
//lista enlazada 
void ABB::insertarInicioLista(int dato) {
    nodoLista *nuevo;

    nuevo = new nodoLista;
    nuevo->dato = dato;
    nuevo->sig = pInicio;
    pInicio = nuevo;
}

void ABB::mostrarLista(void) {
    nodoLista *s = pInicio;

    cout << "Los elementos de la lista son:" << endl;
    while (s != NULL) {
        cout << s->dato << " ";
        s = s->sig;
    }
}


//arbol 
ABB::ABB(void){
    pArbol = NULL;
    pInicio=NULL;
}

 

void ABB::insNodo(int dato){ //esta es la funcion llamada por operaciones
    insNodo(&pArbol, dato); //esta funcion llama a la que pertenece a la clase 
    /*Se envia el puntero al inicio del arbol y el dato a ingrear*/
}

void ABB::insNodo(nodo **p, int dato)
{
    /*enviamos pArbol por referencia pero no le haremos ningun cambio a el, el unico cambio 
    que le pasaria seria en este primer if, ya que en los otros casos no le hacemos ningun cambio
    simplemente volvemos a llamar pero nos saltamos a la derecha o a la izquierda aplicando 
    la recursion*/
    if(!(*p)){  /*p haria la funcion de pArbol, caso en el que el arbol este vacio (ya que 
    si no esta vacio vale 1 y como se niega es 0 y se pasa a la siguiente parte. 
    Este if tambien ocurre cuando nos encontramos en una hoja (ya que el puntero a una hoja Esta 
    a NULL*/
        *p = new nodo;
        (*p)->dato = dato;
        (*p)->hijoIzq = (*p)->hijoDer = NULL;
    }
    else
        if(dato < (*p)->dato){ /*si el dato a ingresar menor al dato actual*/
            insNodo(&((*p)->hijoIzq), dato); /*saltamos a la izquierda y volvemos a llamar 
            a manera que como ya nos encontramos en una hoja (ya que en esta llamada mandamos 
            la direccion del puntero de la izquierda y esta a null) por lo cual entramos al primer
            if (el que esta antes de esta llamada) y guardamos ahi el dato. Si en dado casohubieran varios nodos
            esta funcion va a ir recorriendo el arbol de manera recursiva osea, ej: 1. dato a ingresar es menor
            al dato actual, recursivo y salto al siguiente en la izquierda 2.dato a ingresar es menor
            al dato actual, recursivo y salto al siguiente en la izquierda 3. dato a ingresar es menor
            al dato actual, recursivo y salto al siguiente en la izquierda... y hago todo esto hasta llegar
            a la hoja del arbol a manera que se guarde el dato en el anterior if y por lo tanto se haya 
            insertado el valor en el arbol*/
        }
        else
            if(dato > (*p)->dato){
                /*la misma logica anterior se aplica para esta funcion pero en este caso el dato a ingresar es 
                mayor al actual y por ellos nos vamos a la derecha. AUNQUE NO NECESARIAMENTE HAY QUE IRSE 
                DIRECTAMENTE SOLO A LA DERECHA O SOLO A LA IZQUIERDA, el dato actual ira recorreidno el arbol
                por la derecha o la izquierda si es necesario hasta llegar a la hoja*/
                insNodo(&((*p)->hijoDer), dato);
            }
            else
                {
                    cout<<endl<<"Este elemento ya se encuentra en el arbol: "<<(*p)->dato<<". Por lo cual ya no se pone";
                }
}


void ABB::mostrarIn(void)
{
    mostrarIn(pArbol);
}

void ABB::mostrarIn(nodo *p)
{
    if(p != NULL){
        mostrarIn(p->hijoIzq);
        cout << p ->dato<<" ";
        mostrarIn(p->hijoDer);
    }
}

void ABB::operaciones(void)
{
    char resp;
    int dato;
    nodoLista *s; //puntero auxiliar a la lista 
    cout << "Desea meter un dato a su lista (s/n)?: ";
    cin>> resp;
    while(resp == 's'){
        cout << "Digite el dato: ";
        cin >> dato;
        insertarInicioLista(dato);
        cout << "Desea meter otro dato (s/n)?: ";
        cin>> resp;
    }    
    
    mostrarLista();
    
    s=pInicio;
    //llenando el arbol con los elementos de la lista enlazada
    while(s!=NULL)
    {
        insNodo(s->dato);
        s=s->sig;
    }
    
    cout <<"\nSe ha llenado el arbol binario con los elementos de la lista";
    cout<<endl<<"Mostrando in-orden (ascendente) su arbol:" << endl;
    mostrarIn();
    
}

int main(void)
{
    ABB miArbol;
    miArbol.operaciones();

    return 0;
}
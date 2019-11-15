/*Dado un árbol binario de búsqueda, guarde la ruta de búsqueda de un nodo, en una lista.
Es decir, guarde en la lista todos los valores de los nodos que visita, hasta encontrar el
número que se está buscando. Si el número buscado se encuentra en el árbol, será el
último valor introducido a la lista. Si no se encentra en el árbol, la lista no contendrá
dicho valor. Si el árbol es vacío, obviamente resultará una lista vacía también.*/


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
    void buscar(int);
    void buscar(nodo *, int);
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

void ABB::buscar(int datoB)
{
    buscar(pArbol, datoB);
}
 /*si ponemos la llamada para llenar la lista antes de la llamada recurisva la lista se va a guardar
 a manera que el dato de referencia seria el primero de la lista y no el ultimo, asi que pondre la llamada a 
 llenar la lista despues de la la llamada recursiva */
void ABB::buscar(nodo *p, int datoB)
{
    if(!p) //caso en que el arbol este vacio o se llegue a la hoja 
        cout << "NO esta" << endl;
    else
        if(p->dato == datoB)
        {
            cout << "SI esta" << endl;
            insertarInicioLista(p->dato);
        }
        else
            if(datoB < p->dato)
            {
                buscar(p->hijoIzq, datoB);
                insertarInicioLista(p->dato);
                
            }
            else
            {
                buscar(p->hijoDer, datoB);
                insertarInicioLista(p->dato);
            }
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
                cout << "El nodo ya existe\n";
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
    int datoReferencia;
    cout << "Desea meter un dato (s/n)?";
    cin>> resp;
    while(resp == 's'){
        cout << "Digite el dato: ";
        cin >> dato;
        insNodo(dato);
        cout << "Desea meter un dato (s/n)?";
        cin>> resp;
    }    
    
    cout << "\nMostrar in-orden (ascendenrte):" << endl;
    mostrarIn();
    
    cout<<endl<<"Ingrese el dato que quiere buscar en su arbol: ";
    cin>>datoReferencia;
    buscar(datoReferencia);
    mostrarLista();
}

int main(void)
{
    ABB miArbol;
    miArbol.operaciones();

    return 0;
}

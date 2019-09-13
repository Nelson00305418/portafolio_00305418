/*El problema de las torres de Hanói. Consiste en mover una torre de discos, de
una aguja hacia otra, nada más con la ayuda de una aguja auxiliar. La torre consiste
de n discos de diferente tamaño, que van colocados uno sobre otro, iniciando en la
base con el más grande y terminando en la parte superior con el más pequeño. Solo
puede moverse un disco a la vez y en ningún momento un disco puede estar sobre
otro más pequeño que él. Un ejemplo de la solución puede verlo en el siguiente
enlace:*/

#include <iostream>

using namespace std;
//prototipo
int hanoi(int,int,int,int);

int main()
{
    int n,origen=1,auxiliar=2,destino=3;
    cout<<"Cuantos discos quiere tener? ";
    cin>>n;

    hanoi(n,origen,auxiliar,destino);
}

int hanoi(int n,int origen,int auxiliar,int destino)
{
    //caso de jugar solo con un disco
    if(n==1)
    {
        cout<<"mover disco "<<n<<" hacia la torre "<<destino<<endl;
    }
    else
    {
        hanoi(n-1,origen,destino,auxiliar);
        cout<<"mover disco "<<n<<" Hacia la torre "<<destino<<endl;
        hanoi(n-1,auxiliar,origen,destino);
    }

}

/*Cree una matriz cuadrada de enteros que contenga cinco filas y cinco columnas e
inicialice todas sus casillas a cero. Solicite al usuario sólo aquellos valores que sean
necesarios para crear una matriz tri-diagonal y muéstrela en consola de forma
ordenada (más información en: http://mathworld.wolfram.com/TridiagonalMatrix.html)*/

#include <iostream>

using namespace std;

int main()
{
    int  matriz[5][5];
    //llenar la matriz con ceros 
    for(int i=0;i<5;i++) //fila 
    {
       for(int j=0;j<5;j++) //columna 
       {
           matriz[i][j]=0;
       }
    }
    
    for(int i=0;i<5;i++) //fila 
    {
       for(int j=0;j<5;j++) //columna 
       {
          if(i==j or i==j-1)
             {
                 cout<<"Ingrese el elemento "<<i<<" "<<j<<": ";
                 cin>>matriz[i][j];
             } 
          
          if(j==i-1)
          {
              cout<<"Ingrese el elemento "<<i<<" "<<j<<": ";
                 cin>>matriz[i][j];
          }
       }
    }
    
    //imprimiendo la matriz 
     for(int i=0;i<5;i++) //fila 
    {
        cout<<endl;
       for(int j=0;j<5;j++) //columna 
       {
           cout<<matriz[i][j]<<" ";
       }
    }
}
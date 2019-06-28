/*
    Implementação do algoritmo de Kruskal
    Para detectar ciclos iremos utilizar o algoritmo Union-Find que detecta
    ciclos em grafos NÃO direcionados.
*/

#include <iostream>
#include <mapa_labirinto.h>
using namespace std;


int main(int argc, char *argv[])
{
    int l=21,c=21;
    int **lab=new int*[l] ();
    for(int i = 0; i < l; i++){
        lab[i]=new int[c] ();
    }

    criar_labrinto(lab,l,c);

    printMatriz(lab,l,c);
    cout<<endl;
    printLabirinto(lab,l,c);

    for(int i = 0; i < l; i++)
        delete lab[i];
    delete lab;

    return 0;
}

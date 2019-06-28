/*
    Implementação do algoritmo de Kruskal
    Para detectar ciclos iremos utilizar o algoritmo Union-Find que detecta
    ciclos em grafos NÃO direcionados.
*/

#include <iostream>
#include <vector>
#include <algorithm> // sort
#include <random>
#include <queue>
#include <string.h> // memset
#include <mapa_labirinto.h>
using namespace std;

class Aresta
{
    int vertice1, vertice2, peso;

public:

    Aresta(){
        vertice1=vertice2=peso=0;
    }
    Aresta(int v1, int v2, int peso)
    {
        vertice1 = v1;
        vertice2 = v2;
        this->peso = peso;
    }

    int obterVertice1()
    {
        return vertice1;
    }

    int obterVertice2()
    {
        return vertice2;
    }

    int obterPeso()
    {
        return peso;
    }

    // sobrescrita do operador "<"
    bool operator < (const Aresta& aresta2) const
    {
        return (peso < aresta2.peso);
    }
};

class Grafo
{
    int V; // número de vértices
    vector<Aresta> arestas; // vetor de arestas

public:

    Grafo(int V)
    {
        this->V = V;
    }

    vector<Aresta> getArestas(){
        return arestas;
    }

    // função que adiciona uma aresta
    void adicionarAresta(int v1, int v2, int peso)
    {
        Aresta aresta(v1, v2, peso);
        arestas.push_back(aresta);
    }

    // função que busca o subconjunto de um elemento "i"
    int buscar(int subset[], int i)
    {
        if(subset[i] == -1)
            return i;
        return buscar(subset, subset[i]);
    }

    // função para unir dois subconjuntos em um único subconjunto
    void unir(int subset[], int v1, int v2)
    {
        int v1_set = buscar(subset, v1);
        int v2_set = buscar(subset, v2);
        subset[v1_set] = v2_set;
    }

    void copy_arestas(vector<Aresta> &result){
        result=arestas;
    }

    void kruskal(vector<Aresta> &arvore)
    {
        int size_arestas = arestas.size();

        // ordena as arestas pelo menor peso
        sort(arestas.begin(), arestas.end());

        // aloca memória para criar "V" subconjuntos
        int * subset = new int[V];

        // inicializa todos os subconjuntos como conjuntos de um único elemento
        memset(subset, -1, sizeof(int) * V);

        for(int i = 0; i < size_arestas; i++)
        {
            int v1 = buscar(subset, arestas[i].obterVertice1());
            int v2 = buscar(subset, arestas[i].obterVertice2());

            if(v1 != v2)
            {
                // se forem diferentes é porque NÃO forma ciclo, insere no vetor
                arvore.push_back(arestas[i]);
                unir(subset, v1, v2); // faz a união
            }
        }
    }
};

void criar_uma_arvore(int x,int y, vector<Aresta> &res){
    srand((unsigned)time(0));
    Grafo g(x*y); // grafo

    int n;

    for(int i=0;i<y;i++)
        for(int j=0;j<x-1;j++){
            n=i*x+j;
            g.adicionarAresta(n, n+1, rand()%3+1);
        }

    for(int i=0;i<y-1;i++)
        for(int j=0;j<x;j++){
            n=i*x+j;
            g.adicionarAresta(n, n+x, rand()%3+1);
        }

    g.kruskal(res);
}

void transformar_arvore_em_labirinto(int **lab,int x, int y, vector<Aresta> &arvore){
    int c=x*2-1,l=y*2-1;
    for(int i = 0; i < l; i++)
        for(int j = 0; j < c; j++)
            lab[i][j]=i%2||j%2;


    int size_arvore = arvore.size();

    for(int i = 0; i < size_arvore; i++){
        // TODO transformar a posição int do vertice em seu linha coluna
        // 0 00  1 02  2 04  3 06
        // 4 20  5 22  6 24  7 26
        int nv1 = arvore[i].obterVertice1();//2
        int lv1=nv1/x*2;//0
        int cv1=nv1%x*2;//4

        int nv2 = arvore[i].obterVertice2();//3
        int lv2=nv2/x*2;//0
        int cv2=nv2%x*2;//6
        cout<<"ok "<<i;
        if(cv1==cv2) {
            cout<<"ok "<<i<<"("<<lv1+1<<","<<cv1<<") |"<<endl;
            lab[lv1+1][cv1]=0;
        } else if(lv1==lv2){
            cout<<"ok "<<i<<" "<<nv1<<" ("<<lv1<<","<<cv1+1<<") - "<<l<<"x"<<c<<endl;
            lab[lv1][cv1+1]=0;//5 0
        }
    }
}

void criar_labrinto(int **lab,int l, int c){

    int x=((c%2)?(c+1):c)/2,y=((l%2)?(l+1):l)/2;
    vector<Aresta> arvore;
    criar_uma_arvore(x, y,arvore); // roda o algoritmo de Kruskal

    int size_arvore = arvore.size();
    cout<<"size: "<<size_arvore<<endl;
    // mostra as arestas selecionadas com seus respectivos pesos
    for(int i = 0; i < size_arvore; i++)
    {
        char v1 = 'A' + arvore[i].obterVertice1();
        char v2 = 'A' + arvore[i].obterVertice2();
        cout << "(" << v1 << ", " << v2 << ") = " << arvore[i].obterPeso() << endl;
    }

    transformar_arvore_em_labirinto(lab,x,y,arvore);
}

void printMatriz(int **mat,int l,int c){
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++)
            cout<<mat[i][j]<<' ';
        cout<<endl;
    }
}

void printLabirinto(int **mat,int l,int c){
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++)
            if(mat[i][j])cout<<"▓"; else cout<<"░";
        cout<<endl;
    }
}

#include <iostream>
#include "grafo.h"
#include <chrono>
#include <vector>

using namespace std;

int main(){
    // Este grafo é direcionado.
    // Como eu quero representar uma rede, adiciono os vértices em ambas as direções
    int n = 4; // Num vertices
    Grafo rede(n);

    rede.addAresta(0, 1, 1);
    rede.addAresta(0, 2, 1);

    rede.addAresta(1, 0, 1);
    rede.addAresta(1, 3, 1);

    rede.addAresta(2, 0, 1);
    rede.addAresta(2, 3, 1);

    rede.addAresta(3, 1, 1);
    rede.addAresta(3, 2, 1);
    

    auto start = chrono::high_resolution_clock::now();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            rede.dijkstra(i, j);
        }
    }

    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    cout << "Djikstra de todos pra todos: " << elapsed.count() << endl;

    start = chrono::high_resolution_clock::now();

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            rede.Bellman_Ford(i, j);
        }
    }

    end = chrono::high_resolution_clock::now();
    elapsed = chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    cout << "Bellman-Ford de todos pra todos: " << elapsed.count() << endl;

    return 0;
}
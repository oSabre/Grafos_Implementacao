#include <iostream>
#include <utility>
#include <list>
#include <queue>
#define INFINITO 10000000

using namespace std;

class Grafo{
    private:
        int nv; //Num vértices
        list<pair<int,int>> *adj; // Lista de adjacência.

    public:
        Grafo(int numver){
            this->nv = numver;
            adj = new list<pair<int,int>>[numver];
        }

        void addAresta(int ver1, int ver2, int custo){
            adj[ver1].push_back(make_pair(ver2, custo));
        }
        
        void getLADJ(int vertice){
            list<pair<int, int> >::iterator it;
            for(it = adj[vertice].begin(); it != adj[vertice].end(); it++){
                cout << "O vertice " << vertice <<" faz par com o vertice " << it->first << " com custo " << it->second << endl;
            }
        }

        int dijkstra(int orig, int dest){
            // Vetor de Distandcias
            int dist[nv];
            // Vetor de visitados 
            int visitados[nv];
            // Vetor de Predecessores
            int prev[nv];
            // fila de prioridades de pair (distancia, vértice)
            priority_queue < pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
            // inicia o vetor de distâncias e visitados
            for(int i = 0; i < nv; i++){
                dist[i] = INFINITO;
                visitados[i] = false;
                prev[i] = -1;
            }
            dist[orig] = 0;
            pq.push(make_pair(dist[orig], orig));
            while(!pq.empty()){
                pair<int, int> p = pq.top();
                int u = p.second;
                pq.pop();
                if(visitados[u] == false){
                    visitados[u] = true;
                    list<pair<int, int> >::iterator it;
                    for(it = adj[u].begin(); it != adj[u].end(); it++){
                        int v = it->first;
                        int custo_aresta = it->second;
                        prev[v] = u;

                        if(dist[v] > (dist[u] + custo_aresta)){
                            dist[v] = dist[u] + custo_aresta;
                            pq.push(make_pair(dist[v], v));
                        }
                    }
                }
            }
            return dist[dest];
        }

        int Bellman_Ford(int orig, int dest){
            // Vetor de Distancias
            int dist[nv]; // Distância do vértice X a origem.
            // Predecessor do vértice 
            int pred[nv];
            // Vetor de visitas
            
            // Todas as distâncias a origem vão pra infinito e sem predecessor
            for(int i = 0; i < nv; i++){
                dist[i] = INFINITO;
                pred[i] = -1;
            }
            // Distância da origem a ela mesma deve ser 0
            dist[orig] = 0;

            for(int count = 0; count < nv-1; count++){
                //Escolhe um vértice.
                for(int u = 0; u < nv; u++){
                    list<pair<int, int> >::iterator it;
                    // Pega todos os vértices adjacentes ao vértice U e testa para o relaxamento.
                    for(it = adj[u].begin(); it != adj[u].end(); it++){
                        int v = it->first;
                        int custo = it->second;

                        if(dist[u] != INFINITO && dist[u]+custo < dist[v]){
                            dist[v] = dist[u] + custo;
                            pred[v] = u;
                        }
                    }
                }
            }
            return dist[dest];
        }
};

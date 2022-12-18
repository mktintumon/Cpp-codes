#include <bits/stdc++.h>
#include<vector>
using namespace std;

class Graph{
    int V;
    vector<int> *g;

    public:
        Graph(int V){
            this->V = V;
            g = new vector<int>[V];
        }

        void addEdge(int u , int v){
            g[u].push_back(v);
            g[v].push_back(u);
        }

        void printGraph(){
            for(int i=0 ; i<V; i++){
                cout << "Vertex " << i << " -> ";
                for(int nbr : g[i]){
                    cout << nbr << "   ";
                }
                cout << endl;
            }
        }
};

int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(1,2);
    g.printGraph();

    return 0;
}
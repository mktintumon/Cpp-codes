#include <bits/stdc++.h>
using namespace std;

class Edge{
    public:
        int u,v,wt;

        Edge(int u,int v,int wt){
            this->u = u;
            this->v = v;
            this->wt = wt;
        }
};

class Graph{
    public:
        int V; // no of vertex
        vector<Edge> *g;

        Graph(int V){
            this->V = V;
            g = new vector<Edge>[V];
        }

        void addEdge(int u , int v , int wt){
            g[u].push_back(Edge(u,v,wt));
            g[v].push_back(Edge(v,u,wt));
        }

        void printGraph(){
            for(int i=0 ; i<V; i++){
                cout << "Vertex " << i << " -> ";
                for(Edge nbr : g[i]){
                    cout << "[" << nbr.u << " - " << nbr.v  << " @ " <<  nbr.wt << "] , " ;
                }
                cout << endl;
            }
        }
};

int main(){
    Graph g(4);
    g.addEdge(0,1,10);
    g.addEdge(0,2,20);
    g.addEdge(2,3,30);
    g.addEdge(1,2,40);
    g.printGraph();

    return 0;
}
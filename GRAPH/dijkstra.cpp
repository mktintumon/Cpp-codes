#include<bits/stdc++.h>
using namespace std;

// ADJACENCY LIST METHOD

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
        vector<Edge> *adj;

        Graph(int V){
            this->V = V;
            adj = new vector<Edge>[V];
        }

        void addEdge(int u , int v , int wt){
            adj[u].push_back(Edge(u,v,wt));
            adj[v].push_back(Edge(v,u,wt));
        }

        void printGraph(){
            for(int i=0 ; i<V; i++){
                cout << "Vertex " << i << " -> [";
                for(Edge nbr : adj[i]){
                    cout << nbr.v << ","; 
                    //cout << "[" << nbr.u << " - " << nbr.v  << " @ " <<  nbr.wt << "] , " ;
                }
                cout << "]"<<endl;
            }
        }

        void DijkstraAlgo();
};

void Graph::DijkstraAlgo(){
    queue<Edge> qu;
    int dist[V];
    for(int i = 0; i < V; i++){
        dist[i] = 1e9;
    }

    qu.push(Edge(0,1,2));
    dist[0] = 0;

    while(qu.size() > 0){
        Edge rem = qu.front();
        qu.pop();

        for(Edge e : adj[rem.u]){
            int u = e.u;
            int v = e.v;
            int wt = e.wt;

            if(dist[u] + wt < dist[v]){
                //relaxation
                dist[v] = dist[u] + wt;
                qu.push(Edge(v,u,wt));
            }
        } 
    }

    cout << "Dijkstra distance: ";
    for(int i = 0; i < V ; i++){
        cout << dist[i] << " ";
    }
}


int main(){
    int n = 4;
    Graph g(n);
    g.addEdge(0,1,2);
    g.addEdge(0,3,3);
    g.addEdge(1,2,6);
    g.addEdge(2,3,1);
    
    cout << "ADJACENCY LIST VIEW OF GRAPH :"<<endl;
    cout << "==============================="<<endl;
    g.printGraph();
    cout << "==============================="<<endl<<endl;

    g.DijkstraAlgo();

    return 0;
}
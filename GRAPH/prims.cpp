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

        void primsAlgo();    
};


void Graph::primsAlgo(){
    // This PQ will give min element from the queue
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>qu;
    int vis[V];
    memset(vis, 0, sizeof(vis));

    qu.push({0,0});
    int minCost = 0;

    while(qu.size() > 0){
        auto p = qu.top();
        qu.pop();
        int wt = p.first, node = p.second;

        if(vis[node] == 1) continue;

        vis[node] = 1;
        minCost += wt;

        for(auto e : adj[node]){
            int v = e.v , eWt = e.wt;
            if(vis[v] == 0){
                qu.push({eWt,v});
            }  
        }
    }

    cout << "MIN COST using PRIMS -> " << minCost;
}


int main(){
    int n = 7;
    Graph g(n);
    g.addEdge(0,1,28);
    g.addEdge(0,5,10);
    g.addEdge(2,6,14);
    g.addEdge(5,4,25);
    g.addEdge(4,3,22);
    g.addEdge(3,2,12);
    g.addEdge(1,3,16);
    g.addEdge(3,6,18);
    g.addEdge(4,6,24);
    

    cout << "ADJACENCY LIST VIEW OF GRAPH :"<<endl;
    cout << "============================="<<endl;
    g.printGraph();
    cout << "=============================="<<endl<<endl;

    g.primsAlgo();

    return 0;
}
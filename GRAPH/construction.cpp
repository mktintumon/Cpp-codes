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

        void dfs_Traversal();
        void bfs_Traversal();
};

void dfs(int src , vector<Edge> adj[] , int vis[] , vector<int> &list){
    vis[src] = 1;
    list.push_back(src);

    for(int i=0; i<adj[src].size() ; i++){
        Edge e = adj[src].at(i);
        int nbr = e.v;

        if(vis[nbr] == 0){
            dfs(nbr, adj, vis, list);
        }
    }
}

void Graph::dfs_Traversal(){
    int vis[V]={0};
    vector<int> list;
    dfs(0,adj,vis,list);

    for(int i = 0; i < list.size(); i++){
        cout << list[i] << " ";
    }
}

void Graph::bfs_Traversal(){
    queue<Edge> qu;
    int vis[V]={0};
    qu.push(Edge(0,1,10));

    while(qu.size() > 0){
        Edge rem = qu.front();
        qu.pop();

        vis[rem.u] = 1;
        cout << rem.u << " ";

        for(Edge e : adj[rem.u]){
            if(vis[e.v] == 0){
                qu.push(Edge(e.v,e.u,e.wt));
            }  
        }
    }
}



int main(){
    int n = 6;
    Graph g(n);
    g.addEdge(0,2,10);
    g.addEdge(0,3,20);
    g.addEdge(0,1,30);
    g.addEdge(2,4,40);
    g.addEdge(4,5,60);
    

    cout << "ADJACENCY LIST VIEW OF GRAPH :"<<endl;
    cout << "================================================"<<endl;
    g.printGraph();
    cout << "================================================"<<endl<<endl;

    cout << "DFS TRAVERSAL -> ";
    g.dfs_Traversal();
    cout<<endl;

    cout << "BFS TRAVERSAL -> ";
    g.bfs_Traversal();
    cout<<endl;

    return 0;
}
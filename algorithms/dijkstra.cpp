#include <vector>
#include <iostream>
#include <limits>
#include <queue>
#include <list>
#include <utility>


using namespace std;


typedef pair<int, int> iPair;

class Graph
{
    int V; // no of vertices

    vector<list<pair<int, int>>> adj;

    vector<int> dijkstra(int from) {
        priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
        pq.push(make_pair(0, from));
        vector<int> dist(V, numeric_limits<int>::max());
        dist[from] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop(); 

            for (auto i : adj[u]) {
                int v = i.first;
                int w = i.second;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        return dist;
    }

public:

    Graph(int V) {
        this->V = V;
        for (auto i = 0; i < V; ++i) {
            adj.push_back(list<pair<int, int>>());
        }
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    void printShortestPaths(int from) {

        auto dist = dijkstra(from);

        // Print shortest distances stored in dist[]
        printf("Vertex   Distance from Source\n");
        for (int i = 0; i < V; ++i)
            printf("%d \t\t %d\n", i, dist[i]);

    }
};


int main(){
    int V = 9;
    Graph g(V);
 
    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
 
    g.printShortestPaths(0);


	return 0;
}

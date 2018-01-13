#include <iostream>
#include <vector>
#include <utility>
#include <stdexcept>

using namespace std;

// O(VE)

vector<int> bellmanFord(vector<vector<pair<int, int>>> adj, int src) {
    int INF = numeric_limits<int>::max();
    vector<int> dist(adj.size(), INF);
    dist[src] = 0;

    for (auto i = 0; i < adj.size(); ++i) {
        for (auto v = 0; v < adj.size(); ++v) {
            for (auto n : adj[v]) {
                int e = n.first;
                int w = n.second;
                // relaxation
                if (dist[v] != INF && (dist[e] > dist[v] + w)) {
                    dist[e] = dist[v] + w;
                }
            }
        } 
    }

    // the above step guarantees shortest paths if there are no negative weight cycles
    // checking for cycles
    for (auto v = 0; v < adj.size(); ++v) {
        for (auto n : adj[v]) {
            int e = n.first;
            int w = n.second;
            // relaxation
            if (dist[v] != INF && (dist[e] > dist[v] + w)) {
                throw(runtime_error("Graph contains a negative weight cycle"));
            }
        }
    } 


    return dist;
}


int main() {
    vector<vector<pair<int, int>>> adj(5);

    adj[0].push_back(make_pair(1, -1));
    adj[0].push_back(make_pair(2, 4));

    adj[1].push_back(make_pair(2, 3));
    adj[1].push_back(make_pair(3, 2));
    adj[1].push_back(make_pair(4, 2));

    adj[3].push_back(make_pair(2, 5));
    adj[3].push_back(make_pair(1, 1));
    
    adj[4].push_back(make_pair(3, -3));

    auto dist = bellmanFord(adj, 0);

    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < adj.size(); ++i)
    printf("%d \t\t %d\n", i, dist[i]);

    adj.clear();
    adj.push_back(vector<pair<int, int>>());
    adj[0].push_back(make_pair(0, -1));

    auto res = bellmanFord(adj, 0);

    return 0;
}

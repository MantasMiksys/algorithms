#include <iostream>
#include <vector>
#include "../data_structures/union_find_set.h"

using namespace std;

struct Edge {
    int from;
    int to;
    int weight;
};

vector<Edge> toEdgeArray(const vector<vector<int>> & adj) {
    vector<Edge> edges;
    for(int i = 0; i < adj.size(); ++i) {
        for(int j = 0; j < adj.size(); ++j) {
            if(adj[i][j]) {
                edges.push_back(Edge{i, j, adj[i][j]});
            }
        }
    }
    return edges;
}

vector<int> kruskal(const vector<vector<int>> & adj) {
    vector<int> parent(adj.size());
    UnionFindSet uf(adj.size());
    // sort edges by increasing cost
    auto edges = toEdgeArray(adj);
    sort(edges.begin(), edges.end(), [](Edge & e1, Edge & e2){ return e1.weight < e2.weight; });

    for(int i = 0; i < edges.size(); ++i) {
        if(!uf.find(edges[i].from, edges[i].to)) {
            uf.makeUnion(edges[i].from, edges[i].to);
            parent[edges[i].to] = edges[i].from;
        }
    }

    return parent;
}

void printMST(const vector<int> & parent, const vector<vector<int>> & adj)
{
   printf("Edge   Weight\n");
   for (int i = 1; i < adj.size(); i++)
      printf("%d - %d    %d \n", parent[i], i, adj[i][parent[i]]);
}

int main() {
    vector<vector<int>> adj = {{0, 2, 0, 6, 0},
                {2, 0, 3, 8, 5},
                {0, 3, 0, 0, 7},
                {6, 8, 0, 0, 9},
                {0, 5, 7, 9, 0},
                };
    auto res = kruskal(adj);
    printMST(res, adj);
}

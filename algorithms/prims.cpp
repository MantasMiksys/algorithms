#include <iostream>
#include <vector>
#include <set>

using namespace std;

int minKey(const vector<int> & keys, const vector<bool> & mstSet) {
    int minVal = numeric_limits<int>::max();
    int minIndex = -1;
    for(int i = 0; i < keys.size(); ++i) {
        if(!mstSet[i] && keys[i] < minVal) {
            minVal = keys[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// assuming the graph is connected
vector<int> primMST(const vector<vector<int>> & adj) {
    vector<bool> mstSet(adj.size(), false);
    vector<int> keys(adj.size(), numeric_limits<int>::max());
    vector<int> parent(adj.size());
    parent[0] = -1;
    keys[0] = 0;
    
    for(int i = 0; i < adj.size()-1; ++i) {
        int m = minKey(keys, mstSet);
        mstSet[m] = true;
        for(int j = 0; j < adj.size(); ++j) {
            if(adj[m][j] && !mstSet[j] && adj[m][j] < keys[j]) {
                parent[j] = m;
                keys[j] = adj[m][j];
            }
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
    auto res = primMST(adj);
    printMST(res, adj);
 
}

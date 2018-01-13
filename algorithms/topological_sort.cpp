#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// time complexity O(V + E)

void topologicalSortUtil(const vector<vector<int>> & adj, vector<bool> & visited, stack<int> & s, int from) {
    visited[from] = true;
    for(int n : adj[from]) {
        if(!visited[n])
            topologicalSortUtil(adj, visited, s, n);
    }
    s.push(from);
}

stack<int> topologicalSort(const vector<vector<int>> & adj) {
    stack<int> s;
    vector<bool> visited(adj.size(), false);
    for(int i = 0; i < visited.size(); ++i) {
        if(!visited[i])
            topologicalSortUtil(adj, visited, s, i);
    }
    return s;
}

int main() {
    vector<vector<int>> adj(6);
    adj[5].insert(adj[5].end(), {0, 2});
    adj[4].insert(adj[4].end(), {0, 1});
    adj[2].push_back(3);
    adj[3].push_back(1);
    stack<int> s = topologicalSort(adj);
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}
